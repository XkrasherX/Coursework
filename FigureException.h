#pragma once
#include <string>

//клас для обробки винятків

class FigureException {
private:
	std::wstring message;

public:
	//конструктор з параметрами
	FigureException(const std::wstring& msg) : message(msg) {}

	//вивід помилки
	std::wstring GetMessage() const {
		return message;
	}
};