#include <cmath>
#include <fstream>
#include "FigureManage.h"
#include "FigureException.h"

const double EPS = 1e-9;

//додати фігуру до списку усіх фігур
void FigureManage::addFigureToList(const Figure& figure) { figures.push_back(figure); }

//очистити список усіх фігур
void FigureManage::clearAll() { figures.clear(); }

//геттер кількості фігур у списку
int FigureManage::getCount() const { return (int)figures.size(); }

//геттер фігури за індексом
Figure FigureManage::getFigure(int index) const
{
    if (index < 0 || index >= figures.size()) {
        throw FigureException(L"Фігури з таким індексом не існує!");
    }
	return figures[index];
}

//відсортувати за периметром(метод вибірки)
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

//повертає індекс на найбільшу площу з найменшою кількістю відрізків
int FigureManage::findLargestAreaWithFewestSegments() const
{
    if (figures.empty())
    {
        throw FigureException(L"Список фігур порожній");
    }
    int n = figures.size();

    //знаходимо найбільшу площу серед усіх фігур
    double max_area = figures[0].GetArea();
    for (int i = 1; i < n; i++)
    {
        if (figures[i].GetArea() > max_area)
        {
            max_area = figures[i].GetArea();
        }
    }

    //серед фігур з такою площею обираємо ту, що складається з найменшої кількості відрізків
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

    return best_index;
}

//змінити розмір фігури з індексом index на коефіцієнт factor
void FigureManage::scaleFigure(int index, double factor)
{
    if (index < 0 || index >= figures.size()) {
        throw FigureException(L"Фігури з таким індексом не існує!");
    }

    if (!(factor > 0)) {
        throw FigureException(L"Коефіцієнт масштабування має бути більшим за 0!");
    }
    Figure copy = figures[index];
    copy.scale(factor);

    if (!copy.isInsideField()) {
        throw FigureException(L"Після масштабування фігура вийшла б за межі поля (0..715)!");
    }
    figures[index] = copy;
}

//зберегти у файл
void FigureManage::saveToFile(const std::wstring& path) const
{
    std::ofstream out(path);
	if (!out) {
		throw FigureException(L"Не вдалося відкрити файл для запису!");
	}

	out << figures.size() << std::endl;
	for (size_t i = 0; i < figures.size(); i++) {
		out << figures[i];
	}

	if (!out) {
		throw FigureException(L"Помилка під час запису у файл!");
	}
}

//завантажити з файлу
void FigureManage::loadFromFile(const std::wstring& path)
{
    std::ifstream in(path);
    if (!in) {
        throw FigureException(L"Не вдалося відкрити файл для читання!");
    }

    int n;
    if (!(in >> n) || n < 0) {
        throw FigureException(L"Файл має неправильний формат!");
    }

    std::vector<Figure> loaded;
    for (int i = 0; i < n; i++) {
        Figure f;
        if (!(in >> f)) {
            throw FigureException(L"Файл пошкоджений або містить некоректну фігуру!");
        }
        loaded.push_back(f);
    }

    // підміняємо список лише коли весь файл прочитано успішно
    figures = loaded;
}
