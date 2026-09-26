#pragma once
#include <vector>
#include "Figure.h"

//клас для взаємодією над фігурами
class FigureManage
{
private: 
	std::vector<Figure> figures;

public:
	//додати фігуру до списку всіх фігур
	void addFigureToList(const Figure& figure);
	
	
	int getCount() const;
	Figure getFigure(int index) const;

	//сортує за значенням периметра(метод простої вибірки)
	void sortByPerimeter();

	//знайти фігуру з найбільшою площею з найменшою кількістю відрізків.
	Figure findLargestAreaWithFewestSegments() const;

	void scaleFigure(int index, double factor);
};

