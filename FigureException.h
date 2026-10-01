#pragma once

#include <string>

class FigureException {
private:
	std::wstring message;

public:
	FigureException(const std::wstring& msg) : message(msg) {}

	std::wstring GetMessage() const {
		return message;
	}
};