#pragma once
#include <iostream>
#include <string>
#include "Segment.h"

class Figure
{
private:
	std::string name;
	Segment* segments;
	int segments_count;
	double area;
	double perimeter;

public:
    //конструктор за замовчуванням
	Figure();

    //конструктор з параметрами
	Figure(const std::string figure_name, Segment* arr_segment, int count);

    //конструктор копіювання
    Figure(const Figure& other);

    //оператор присвоєння
    Figure& operator=(const Figure& other);
    
    //деструктор
    ~Figure();                                                      

    //геттери
    std::string GetName() const;
    int GetSegmentsCount() const;
    Segment GetSegment(int index) const;
    double GetArea() const;
    double GetPerimeter() const;

    //сеттер
    void SetName(const std::string& figureName);

    //максимум фігур з заданою кількістю відрізків
    int maxFiguresBySegments() const;

    //площа вписаного кола у фігуру
    double areaOfInscribedCircle() const;
    
    //порахувати периметр
    double calculatePerimeter();

    //порахувати площу
    double calculcateArea();

    void scale(double factor);

    //перевантажені оператори вводу і виводу
    friend std::ostream& operator<<(std::ostream& out, const Figure& other);
    friend std::istream& operator>>(std::istream& in, Figure& other);

};

