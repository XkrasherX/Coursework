#pragma once
#include <vector>
#include <string>
#include "Figure.h"

//клас для взаємодії над фігурами
class FigureManage
{
private: 
	std::vector<Figure> figures;

public:
	//додати фігуру до списку всіх фігур
	void addFigureToList(const Figure& figure);
	
	//очистити фігури
	void clearAll();

	//геттери
	int getCount() const;
	Figure getFigure(int index) const;

	//сортує за значенням периметра(метод простої вибірки)
	void sortByPerimeter();

	//знайти фігуру з найбільшою площею з найменшою кількістю відрізків.
	int findLargestAreaWithFewestSegments() const;

	//змінити розмір фігури з індексом index на коеф factor
	void scaleFigure(int index, double factor);

	//зберегти/завантажити з файлу
	void saveToFile(const std::wstring& path) const;
	void loadFromFile(const std::wstring& path);
};

