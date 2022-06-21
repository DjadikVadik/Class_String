#pragma once
#include <iostream>

class String
{
	char* str = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:

	// конструкторы:
	String();
	String(char* text);
	explicit String(unsigned int capacity);

	//деструктор
	~String();

	//конструктор копирования
	String(const String& origin);

	//перегрузка операторов
	bool operator ==(const String& other);
	bool operator ==(const char* text);
	bool operator<(const String& other);
	bool operator<(const char* text);
	bool operator>(const String& other);
	bool operator>(const char* text);
	String& operator=(const String& other);
	String& operator=(const char* text);
	String& operator+(const String& other);
	String& operator+(const char* text);

	//методы
	char get_char_at(unsigned int num);
};

