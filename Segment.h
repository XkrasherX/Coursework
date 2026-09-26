#pragma once
#include <iostream>

//точка на площині
struct Point {
	double x;
	double y;
};

//клас для створення відрізків
class Segment
{
private:
	Point start;
	Point end;

public:
	//конструктор за замовчуванням
	Segment();

	//конструктор з параметрами координат
	Segment(double x1, double y1, double x2, double y2);

	//конструктор копіювання
	Segment(const Segment& other);

	//геттери на початок і кінець відрізку
	Point getStart() const;
	Point getEnd() const;

	//довжина відрізка
	double getLength() const;

	void scaling(Point center, double factor);
	//перевантажені оператори вводу і виводу
	friend std::ostream& operator<<(std::ostream& out, const Segment& other);
	friend std::istream& operator>>(std::istream& in, Segment& other);
};

