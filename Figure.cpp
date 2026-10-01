#include <cmath>
#include <vector>
#include <string>

#include "Figure.h"
#include "FigureException.h"

const double PI = 3.14159265358979;
const float CLOSE_OFFSET = 0.1f;

static bool pointInField(const PointSegment& p)
{
    // записано так, щоб NaN теж вважався помилкою
    return p.x >= 0 && p.x <= FIELD_SIZE && p.y >= 0 && p.y <= FIELD_SIZE;
}

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
Figure::Figure(const std::string& figure_name, Segment* arr_segment, int count)
{
    if (count < 3) {
        throw FigureException(L"Фігура повинна складатися принаймі з 3 відрізків!");
    }

    for (int i = 0; i < count; i++) {
        if (!pointInField(arr_segment[i].getStart()) || !pointInField(arr_segment[i].getEnd())) {
            throw FigureException(L"Координати повині лежати в межах від 0 до 715!");
        }
    }

    for (int i = 0; i < count; i++) {
        PointSegment end = arr_segment[i].getEnd();
        PointSegment next_start = arr_segment[(i + 1) % count].getStart();
        if (fabs(end.x - next_start.x) > CLOSE_OFFSET || fabs(end.y - next_start.y) > CLOSE_OFFSET) {
            throw FigureException(L"Відрізки не утворюють замкнений контур: кінець відрізка №"
                + std::to_wstring(i + 1) + L" має збігатися з початком відрізка №"
                + std::to_wstring((i + 1) % count + 1) + L"!");
        }
    }

    name = figure_name;
    segments_count = count;
    segments = new Segment[segments_count];

    for (int i = 0;i < segments_count;i++) {
        segments[i] = arr_segment[i];
    }

    calculatePerimeter();
    calculcateArea();
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
    if (index < 0 || index >= segments_count) {
        throw FigureException(L"Відрізка з таким індексом не існує!");
    }
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
    if (perimeter == 0) {
        throw FigureException(L"Неможливо обчислити площу вписано кола, периметр фігури дорівнює 0!");
    }
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
        PointSegment p1 = segments[i].getStart();
        PointSegment p2 = segments[i].getEnd();
        sum += ((p1.x * p2.y) - (p2.x * p1.y));
    }
        area = fabs(sum) / 2.0;
        return area;
}

void Figure::scale(double factor)
{
    // 1) знаходимо центр фігури - середнє арифметичне всіх вершин
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < segments_count; i++)
    {
        PointSegment p = segments[i].getStart();
        sum_x += p.x;
        sum_y += p.y;
    }

    PointSegment center;
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

bool Figure::isInsideField() const
{
    for (int i = 0; i < segments_count; i++) {
        if (!pointInField(segments[i].getStart()) || !pointInField(segments[i].getEnd())) {
            return false;
        }
    }
    return true;
}

bool Figure::isContainPoints(float px, float py, float offset) const
{
    // 1) клік по самій лінії
    for (int i = 0; i < segments_count; i++) {
        if (segments[i].distanceToPoint(px, py) <= offset) {
            return true;
        }
    }

    // 2) клік всередині контуру (алгоритм променя)
    bool inside = false;
    for (int i = 0; i < segments_count; i++) {
        PointSegment a = segments[i].getStart();
        PointSegment b = segments[i].getEnd();
        if ((a.y > py) != (b.y > py)) {
            double x_cross = a.x + (double)(py - a.y) * (b.x - a.x) / (b.y - a.y);
            if (px < x_cross) {
                inside = !inside;
            }
        }
    }
    return inside;
}

std::ostream& operator<<(std::ostream& out, const Figure& other)
{
    std::streamsize old_precision = out.precision(9);
    out << other.name << std::endl;
    out << other.segments_count << " " << other.area << " " << other.perimeter << std::endl;
    for (int i = 0; i < other.segments_count; i++) {
        out << other.segments[i] << std::endl;
    }
    out.precision(old_precision);
    return out;
}

std::istream& operator>>(std::istream& in, Figure& other)
{
    std::string name;
    int count;
    double file_area, file_perimeter;  // зчитуємо, але не довіряємо - перерахуємо самі

    in >> std::ws;
    if (!std::getline(in, name)) return in;
    if (!(in >> count >> file_area >> file_perimeter)) return in;

    if (count < 3 || count > 100000) {
        in.setstate(std::ios::failbit);
        return in;
    }

    std::vector<Segment> tmp(count);
    for (int i = 0; i < count; i++) {
        if (!(in >> tmp[i])) return in;
    }

    try {
        // конструктор сам перевірить межі й замкненість та порахує площу/периметр
        Figure result(name, tmp.data(), count);
        other = result;
    }
    catch (FigureException&) {
        in.setstate(std::ios::failbit);
    }
    return in;
}
