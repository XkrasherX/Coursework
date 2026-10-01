#pragma once
#include <iostream>

//точка на площині
struct PointSegment {
	float x;
	float y;
};

//клас для створення відрізків
class Segment
{
private:
	PointSegment start;
	PointSegment end;

public:
	//конструктор за замовчуванням
	Segment();

	//конструктор з параметрами координат
	Segment(float x1, float y1, float x2, float y2);

	//конструктор копіювання
	Segment(const Segment& other);

	//геттери на початок і кінець відрізку
	PointSegment getStart() const;
	PointSegment getEnd() const;

	//довжина відрізка
	float getLength() const;

	//відстань від точки до відрізка
	float distanceToPoint(float px, float py) const;

	void scaling(PointSegment center, float factor);
	//перевантажені оператори вводу і виводу
	friend std::ostream& operator<<(std::ostream& out, const Segment& other);
	friend std::istream& operator>>(std::istream& in, Segment& other);
};

