#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class FlatShapes
{
private: 
	std::vector<std::vector<int>> x_cord;
	std::vector<std::vector<int>> y_cord;
	
	std::string shape_name;

	double shape_area;
	double perimetr;

	FlatShapes();

	int maxNumOfShapes(std::vector<std::vector<int>>& arr);
	double segmentLength(std::vector<std::vector<int>>& arr_x, std::vector<std::vector<int>>& arr_y);

};

