#include "Figure.h"

const double PI = 3.14159265358979;

//конструктор за замовчуванням
Figure::Figure()
{
    name = "";
    segments = nullptr;
    segments_count = 0;
    area = 0;
    perimeter = 0;
}

// конструктор з параметрами, ім'я, відрізки, к-ть відрізків
Figure::Figure(const std::string figure_name, Segment* arr_segment, int count)
{
    name = figure_name;
    segments_count = count;
    segments = new Segment[segments_count];

    for (int i = 0;i < segments_count;i++) {
        segments[i] = arr_segment[i];
    }

    area = 0;
    perimeter = 0;
}

//конструктор копіювання
Figure::Figure(const Figure& other)
{
    name = other.name;
    segments_count = other.segments_count;
    area = other.area;
    perimeter = other.perimeter;

    segments = new Segment[segments_count];
    for (int i = 0; i < segments_count; i++)
    {
        segments[i] = other.segments[i];
    }
}

Figure& Figure::operator=(const Figure& other)
{
    if (this == &other) return *this;

    delete[] segments;

    name = other.name;
    segments_count = other.segments_count;
    area = other.area;
    perimeter = other.perimeter;
    segments = new Segment[segments_count];
    for (int i = 0; i < segments_count;i++) {
        segments[i] = other.segments[i];
    }

    return *this;
}

//деструктор
Figure::~Figure()
{
    name = "";
    segments_count = 0;
    area = 0;
    perimeter = 0;
    delete[] segments;
    segments = nullptr;
}

std::string Figure::GetName() const
{
    return name;
}

int Figure::GetSegmentsCount() const
{
    return segments_count;
}

Segment Figure::GetSegment(int index) const
{
    return segments[index];
}

double Figure::GetArea() const
{
    return area;
}

double Figure::GetPerimeter() const
{
    return perimeter;
}

void Figure::SetName(const std::string& figureName)
{
    name = figureName;
}

int Figure::maxFiguresBySegments() const
{
    return ((segments_count - 1) * (segments_count - 2)) / 2;
}

double Figure::areaOfInscribedCircle() const
{
    double radius = (2.0 * area) / perimeter;
    return radius * radius * PI;
}

double Figure::calculatePerimeter()
{
    double total_sum = 0.0;
    for (int i = 0; i < segments_count;i++) {
        total_sum += segments[i].getLength();
    }
    perimeter = total_sum;
    return perimeter;
}

double Figure::calculcateArea()
{
    double sum = 0.0;
    for (int i = 0; i < segments_count; i++) {
        Point p1 = segments[i].getStart();
        Point p2 = segments[i].getEnd();
        sum += ((p1.x * p2.y) - (p2.x * p1.y));
        area = fabs(sum) / 2.0;
        return area;
    }
}

void Figure::scale(double factor)
{
    // 1) знаходимо центр фігури - середнє арифметичне всіх вершин
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < segments_count; i++)
    {
        Point p = segments[i].getStart();
        sum_x += p.x;
        sum_y += p.y;
    }

    Point center;
    center.x = sum_x / segments_count;
    center.y = sum_y / segments_count;

    // 2) масштабуємо кожен відрізок відносно цього центру
    for (int i = 0; i < segments_count; i++)
    {
        segments[i].scaling(center, factor);
    }

    // 3) периметр і площа змінились разом з координатами - перераховуємо
    calculatePerimeter();
    calculcateArea();
}

std::ostream& operator<<(std::ostream& out, const Figure& other)
{
    out << other.name << " " << other.segments_count << " "
        << other.area << " " << other.perimeter << " " << std::endl;
    for (int i = 0; i < other.segments_count;i++) {
        out << other.segments[i] << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Figure& other)
{
    in >> other.name >> other.segments_count >> other.area >> other.perimeter;
    delete[] other.segments;

    other.segments = new Segment[other.segments_count];
    for (int i = 0; i < other.segments_count;i++) {
        in >> other.segments[i];
     }
    return in;
}
