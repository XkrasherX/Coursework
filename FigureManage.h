#pragma once
#include <vector>
#include <string>
#include "Figure.h"

//клас для взаємодією над фігурами
class FigureManage
{
private: 
	std::vector<Figure> figures;

public:
	//додати фігуру до списку всіх фігур
	void addFigureToList(const Figure& figure);
	
	//очистити фігури
	void clearAll();

	int getCount() const;
	Figure getFigure(int index) const;

	//сортує за значенням периметра(метод простої вибірки)
	void sortByPerimeter();

	//знайти фігуру з найбільшою площею з найменшою кількістю відрізків.
	int findLargestAreaWithFewestSegments() const;

	void scaleFigure(int index, double factor);

	//індекс фігури під точкою (x, y) або -1
	int findFigureAt(float x, float y) const;

	//робота з файлом (використовує оператори << і >>)
	void saveToFile(const std::wstring& path) const;
	void loadFromFile(const std::wstring& path);
};

