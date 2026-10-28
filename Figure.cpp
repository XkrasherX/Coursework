#include <cmath>
#include <vector>
#include <string>

#include "Figure.h"
#include "FigureException.h"

const float FIELD_SIZE = 715.0f; //розмір поля
const double PI = 3.14159265358979; //число пі
const float CLOSE_OFFSET = 0.1f; //похибка в утворенні послідовних відрізків

//перевірка чи точка всередині поля
bool pointInField(const PointSegment& p) 
{
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
    //кількість відрізків менша за 3
    if (count < 3) {
        throw FigureException("Фігура повинна складатися принаймі з 3 відрізків!");
    }

    //перевірка чи точка всередині поля для кожного відрізка
    for (int i = 0; i < count; i++) {
        if (!pointInField(arr_segment[i].getStart()) || !pointInField(arr_segment[i].getEnd())) {
            throw FigureException("Координати повині лежати в межах від 0 до 715!");
        }
    }


    for (int i = 0; i < count; i++) {
        PointSegment end = arr_segment[i].getEnd();
        PointSegment next_start = arr_segment[(i + 1) % count].getStart();
        if (fabs(end.x - next_start.x) > CLOSE_OFFSET || fabs(end.y - next_start.y) > CLOSE_OFFSET) {
            throw FigureException("Відрізки не утворюють замкнений контур: кінець відрізка №"
                + std::to_string(i + 1) + " має збігатися з початком відрізка №"
                + std::to_string((i + 1) % count + 1) + "!");
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

//оператор копіювання
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

//геттер ім'я
std::string Figure::GetName() const { return name; }

//геттер кількості відрізків
int Figure::GetSegmentsCount() const { return segments_count; }

//геттер відрізка
Segment Figure::GetSegment(int index) const
{
    if (index < 0 || index >= segments_count) {
        throw FigureException("Відрізка з таким індексом не існує!");
    }
    return segments[index];
}

//геттер площі
double Figure::GetArea() const { return area; }

//геттер периметра
double Figure::GetPerimeter() const { return perimeter; }


//максимум фігур з заданою кількістю відрізків
int Figure::maxFiguresBySegments() const 
{
    return ((segments_count - 1) * (segments_count - 2)) / 2;
}

//площа вписаного кола
double Figure::areaOfInscribedCircle() const
{
    if (perimeter == 0) {
        throw FigureException("Неможливо обчислити площу вписано кола, периметр фігури дорівнює 0!");
    }
    double radius = (2.0 * area) / perimeter;
    return radius * radius * PI;
}

//порахувати периметр фігури
double Figure::calculatePerimeter()
{
    double total_sum = 0.0;
    for (int i = 0; i < segments_count;i++) {
        total_sum += segments[i].getLength();
    }
    perimeter = total_sum;
    return perimeter;
}

//порахувати площу фігури
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

//масштабувати фігуру відносно коефіцієнта factor
void Figure::scale(double factor)
{
    //знаходимо центр фігури - середнє арифметичне всіх вершин
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

    //масштабуємо кожен відрізок відносно цього центру
    for (int i = 0; i < segments_count; i++)
    {
        segments[i].scaling(center, factor);
    }

    //периметр і площа змінились разом з координатами - перераховуємо
    calculatePerimeter();
    calculcateArea();
}

//перевіряємо чи відрізок всередині поля
bool Figure::isInsideField() const
{
    for (int i = 0; i < segments_count; i++) {
        if (!pointInField(segments[i].getStart()) || !pointInField(segments[i].getEnd())) {
            return false;
        }
    }
    return true;
}

//оператор виводу
std::ostream& operator<<(std::ostream& out, const Figure& other)
{
    out << "Назва фігури: " << other.name << std::endl;
    out << "Кількість відрізків: " << other.segments_count << "\n"
        << "Площа фігури: " << other.area << "\n"
        << "Периметр фігури: " << other.perimeter << std::endl;
    out << "Координати відрізків\n X0  Y0  X1  Y1\n";
    for (int i = 0; i < other.segments_count; i++) {
        out << other.segments[i] << std::endl;
    }
    return out;
}

//оператор вводу
std::istream& operator>>(std::istream& in, Figure& other)
{
    std::string name;
    int count;

    in >> std::ws;
    std::getline(in, name);
    in >> count;
    if (!in) return in;

    if (count < 3 || count > 100000)
        throw FigureException("Некоректна кількість відрізків у файлі!");

    std::vector<Segment> segs(count);
    for (int i = 0; i < count; i++)
        in >> segs[i];
    if (!in) return in;

    other = Figure(name, &segs[0], count);   // конструктор сам перевіряє дані
    return in;
}