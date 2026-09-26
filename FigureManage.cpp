#include <cmath>
#include "FigureManage.h"

const double EPS = 1e-9;

void FigureManage::addFigureToList(const Figure& figure)
{
	figures.push_back(figure);

}

int FigureManage::getCount() const
{
	return figures.size();
}

Figure FigureManage::getFigure(int index) const
{
	return figures[index];
}

void FigureManage::sortByPerimeter()
{
    int n = figures.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (figures[j].GetPerimeter() < figures[min_index].GetPerimeter())
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            Figure temp = figures[i];
            figures[i] = figures[min_index];
            figures[min_index] = temp;
        }
    }

}

Figure FigureManage::findLargestAreaWithFewestSegments() const
{
    int n = figures.size();

    // 1) знаходимо найбільшу площу серед усіх фігур
    double max_area = figures[0].GetArea();
    for (int i = 1; i < n; i++)
    {
        if (figures[i].GetArea() > max_area)
        {
            max_area = figures[i].GetArea();
        }
    }

    // 2) серед фігур з такою (чи майже такою - через похибки double) площею
    //    обираємо ту, що складається з найменшої кількості відрізків
    int best_index = 0;
    bool is_found = false;
    for (int i = 0; i < n; i++)
    {
        bool same_area = fabs(figures[i].GetArea() - max_area) < EPS;
        if (same_area && (!is_found || figures[i].GetSegmentsCount() < figures[best_index].GetSegmentsCount()))
        {
            best_index = i;
            is_found = true;
        }
    }

    return figures[best_index];
}

void FigureManage::scaleFigure(int index, double factor)
{
    figures[index].scale(factor);
}
