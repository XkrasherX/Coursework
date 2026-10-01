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
Segment::Segment(float x1, float y1, float x2, float y2)
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
PointSegment Segment::getStart() const
{
	return start;
}

//геттер кінця відрізку
PointSegment Segment::getEnd() const
{
	return end;
}

float Segment::getLength() const
{
	float x = end.x - start.x;
	float y = end.y - start.y;
	return sqrt((x * x) + (y * y));
}

float Segment::distanceToPoint(float px, float py) const
{
	double dx = end.x - start.x;
	double dy = end.y - start.y;
	double len2 = dx * dx + dy * dy;
	double t = 0.0;
	if (len2 > 0.0) {
		t = ((px - start.x) * dx + (py - start.y) * dy) / len2;
		t = std::max(0.0, std::min(1.0, t));
	}
	double cx = start.x + t * dx;
	double cy = start.y + t * dy;
	return sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));
}

void Segment::scaling(PointSegment center, float factor)
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
