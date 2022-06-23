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
	String(const char* text);
    String(unsigned int capacity);

	//деструктор
	~String();

	//конструктор копирования и переноса
	String(const String& origin);
	String(String&& origin);

	//перегрузка операторов
	bool operator ==(const String& other);
	bool operator ==(const char* text);
	bool operator<(const String& other);
	bool operator<(const char* text);
	bool operator>(const String& other);
	bool operator>(const char* text);
	String& operator=(const String& other);
	String& operator=(const char* text);
	String operator+(const String& other);
	String& operator+=(const String& other);
	String operator+(const char* text);
	String& operator+=(const char* text);
	friend std::ostream& operator << (std::ostream& ost, const String& st);
	friend std::istream& operator << (std::istream& ist, const String& st);

	//методы
	char get_char_at(unsigned int num);
	unsigned int _length();
	unsigned int _capacity();
};

