#pragma once
#include <string>

//клас для обробки винятків

class FigureException {
private:
	std::string message;

public:
	//конструктор з параметрами
	FigureException(const std::string& msg) : message(msg) {}

	//вивід помилки
	std::string GetMessage() const {
		return message;
	}
};