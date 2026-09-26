#include "Segment.h"
#include <cmath>

//конструктор за замовчуванням. Початкові координати = 0
Segment::Segment()
{
	start.x = 0;
	start.y = 0;
	end.x = 0;
	end.y = 0;
}

//конструктор з параметрами. x1, y2 - початок відрізку, x2, y2 - кінець відрізку.
Segment::Segment(double x1, double y1, double x2, double y2)
{
	start.x = x1;
	start.y = y1;
	end.x = x2;
	end.y = y2;
}

//конструктор копіювання
Segment::Segment(const Segment& other)
{
	start = other.start;
	end = other.end;
}

//геттер початку відрізку
Point Segment::getStart() const
{
	return start;
}

//геттер кінця відрізку
Point Segment::getEnd() const
{
	return end;
}

double Segment::getLength() const
{
	double x = end.x - start.x;
	double y = end.y - start.y;
	return sqrt((x * x) + (y * y));
}

void Segment::scaling(Point center, double factor)
{
	start.x = center.x + (start.x - center.x) * factor;
	start.y = center.y + (start.y - center.y) * factor;
	end.x = center.x + (end.x - center.x) * factor;
	end.y = center.y + (end.y - center.y) * factor;
}

std::ostream& operator<<(std::ostream& out, const Segment& other)
{
	out << other.start.x << " " << other.start.y << " "
		<< other.end.x << " " << other.end.y;
	return out;
}

std::istream& operator>>(std::istream& in, Segment& other)
{
	in >> other.start.x >> other.start.y >> other.end.x >> other.end.y;
	return in;
}
