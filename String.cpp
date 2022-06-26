#include "String.h"

#pragma region КОНСТРУКТОРЫ:
String::String(){}

String::String(const char* text) 
{
	
	if (strlen(text) < capacity) {

		str = new char[capacity];

		for (int i = 0; i < strlen(text); i++)
			str[i] = text[i];

		str[strlen(text)] = '\0';
		length = strlen(text);
	}

	else {
		while (capacity <= strlen(text)) capacity += 80;
		delete[] str;
		str = new char[capacity];

		for (int i = 0; i < strlen(text); i++)
			str[i] = text[i];

		str[strlen(text)] = '\0';
		length = strlen(text);
	}
}

String::String(unsigned int capacity)
{
	this->capacity = capacity;
	str = new char[capacity];
}

#pragma endregion

#pragma region ДЕСТРУКТОР:
String::~String()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}
#pragma endregion

#pragma region КОНСТРУКТОР КОПИРОВАНИЯ И ПЕРЕНОСА
String::String(const String& origin)
{
	capacity = origin.capacity;
	length = origin.length;
	str = new char[capacity];

	for (int i = 0; i < length; i++)
		str[i] = origin.str[i];
	str[length] = '\0';
}

String::String(String&& origin)
{
	capacity = origin.capacity;
	length = origin.length;
	str = origin.str;
	origin.str = nullptr;
}

#pragma endregion

#pragma region ПЕРЕГРУЗКА ОПЕРАТОРОВ:
bool String::operator==(const String& other)
{
	if (length != other.length) return false;
	else
		for (int i = 0; i < length; i++)
			if (str[i] != other.str[i])
				return false;
	return true;
}

bool String::operator!=(const String& other)
{
	if (length != other.length) return true;
	else
		for (int i = 0; i < length; i++)
			if (str[i] != other.str[i])
				return true;
	return false;
}

bool String::operator==(const char* text)
{
	if (length != strlen(text)) return false;
	else
		for (int i = 0; i < length; i++)
			if (str[i] != text[i])
				return false;
	return true;
}

bool String::operator!=(const char* text)
{
	if (length != strlen(text)) return true;
	else
		for (int i = 0; i < length; i++)
			if (str[i] != text[i])
				return true;
	return false;
}

bool String::operator<(const String& other)
{
	for (int i = 0; i < length; i++) {

		if (str[i] == '\0' || other.str[i] == '\0') break;

		if (str[i] < other.str[i])
			return true;

		else if (str[i] > other.str[i])
			return false;

		else continue;
	}

	if (length < other.length) return true;

	return false;
}

bool String::operator<(const char* text)
{
	for (int i = 0; i < length; i++) {

		if (str[i] == '\0' || text[i] == '\0') break;

		if (str[i] < text[i])
			return true;

		else if (str[i] > text[i])
			return false;

		else continue;
	}

	if (length < strlen(text)) return true;

	return false;
}

bool String::operator>(const String& other)
{
	for (int i = 0; i < length; i++) {

		if (str[i] == '\0' || other.str[i] == '\0') break;

		if (str[i] > other.str[i])
			return true;

		else if (str[i] < other.str[i])
			return false;

		else continue;
	}

	if (length > other.length) return true;

	return false;
}

bool String::operator>(const char* text)
{
	for (int i = 0; i < length; i++) {

		if (str[i] == '\0' || text[i] == '\0') break;

		if (str[i] > text[i])
			return true;

		else if (str[i] < text[i])
			return false;

		else continue;
	}

	if (length > strlen(text)) return true;

	return false;
}

String& String::operator=(const String& other)
{
	if (str == other.str) return *this;
	capacity = other.capacity;
	length = other.length;
	str = new char[capacity];

	for (int i = 0; i < length; i++)
		str[i] = other.str[i];
	str[length] = '\0';

	return *this;
}

String& String::operator=(const char* text)
{
	if (strlen(text) < capacity) {

		for (int i = 0; i < strlen(text); i++)
			str[i] = text[i];

		str[strlen(text)] = '\0';
		length = strlen(text);
	}

	else {
		while (capacity <= strlen(text)) capacity += 80;
		delete[] str;
		str = new char[capacity];

		for (int i = 0; i < strlen(text); i++)
			str[i] = text[i];

		str[strlen(text)] = '\0';
		length = strlen(text);
	}

	return *this;
}

String String::operator+(const String& other)
{
	String copy(length + other.length + 80);
	copy.length = length + other.length;

	int n = 0;

	for (int i = 0; i < length; i++) {
		copy.str[n] = str[i];
		n++;
	}

	for (int i = 0; i < other.length; i++) {
		copy.str[n] = other.str[i];
		n++;
	}

	copy.str[n] = '\0';

	return copy;
}

String& String::operator+=(const String& other)
{
	if (capacity > length + other.length)
	{
		for (int i = 0; i < other.length; i++)
			str[length + i] = other.str[i];
		length += other.length;
		str[length] = '\0';
		return *this;
	}
	else {
		capacity = length + other.length + 80;
		char* text = new char[capacity];
		int n = 0;

		for (int i = 0; i < length; i++) {
			text[n] = str[i];
			n++;
		}

		for (int i = 0; i < other.length; i++) {
			text[n] = other.str[i];
			n++;
		}
		length += other.length;
		text[length] = '\0';
		delete[] str;
		str = text;
		return *this;
	}
}

String String::operator+(const char* text)
{
	String copy(length + strlen(text) + 80);
	
	copy.length = length + strlen(text);

	int n = 0;

	for (int i = 0; i < length; i++) {
		copy.str[n] = str[i];
		n++;
	}

	for (int i = 0; i < strlen(text); i++) {
		copy.str[n] = text[i];
		n++;
	}

	copy.str[n] = '\0';

	return copy;
}

String& String::operator+=(const char* text)
{
	if (capacity > length + strlen(text))
	{
		for (int i = 0; i < strlen(text); i++)
			str[length + i] = text[i];
		length += strlen(text);
		str[length] = '\0';
		return *this;
	}

	else {
		capacity = length + strlen(text) + 80;
		char* text1 = new char[capacity];
		int n = 0;

		for (int i = 0; i < length; i++) {
			text1[n] = str[i];
			n++;
		}

		for (int i = 0; i < strlen(text); i++) {
			text1[n] = text[i];
			n++;
		}
		length += strlen(text);
		text1[length] = '\0';
		delete[] str;
		str = text1;
		return *this;
	}
}

char& String::operator[](int index)
{
	if (index >= 0 && index < length) return str[index];
	else throw std::exception("out of memory!!!");
}

std::ostream& operator<<(std::ostream& ost, const String& st)
{
	ost << st.str;
	return ost;
}

std::istream& operator>>(std::istream& ist, const String& st)
{
	ist >> st.str;
	return ist;
}

#pragma endregion

#pragma region МЕТОДЫ:
char String::get_char_at(unsigned int num)
{
	if (num < length && num >= 0) return str[num];
	else throw std::exception("символа с таким порядковым номером нет в строке!!!");
}

unsigned int String::_length()
{
	return length;
}

unsigned int String::_capacity()
{
	return capacity;
}

const char* String::GetCharArray() const
{
	return str;
}

int String::IndexOf(char ch)
{
	for (int i = 0; i < length; i++)
		if (str[i] == ch) return i;
	return -1;
}

int String::IndexOf(const String& other)
{
	if (length < other.length) return -1;
	for (int i = 0; i < length - other.length + 1; i++) {
		bool in_serch = true;
		for (int j = 0; j < other.length; j++)
			if (str[i + j] != other.str[j]) {
				in_serch = false;
				break;
			}
		if (in_serch) return i;
	}
	return -1;
}

int String::IndexOf(const char* text)
{
	if (length < strlen(text)) return -1;
	for (int i = 0; i < length - strlen(text) + 1; i++) {
		bool in_serch = true;
		for (int j = 0; j < strlen(text); j++)
			if (str[i + j] != text[j]) {
				in_serch = false;
				break;
			}
		if (in_serch) return i;
	}
	return -1;
}

void String::Replace(char R, char Z)
{
	for (int i = 0; i < length; i++)
		if (str[i] == R) str[i] = Z;
}

void String::Replace(const String& substr, const String& rep)
{
	if (length < substr.length) return;
	if (IndexOf(substr) < 0) return;
	if (capacity <= length + rep.length) capacity = length + rep.length + 80;

	char* str1 = new char[capacity]; // новая строка
	int k = 0; // индекс элемента новой строки

	for (int i = 0; i < length - substr.length + 1; i++) 
	{
		bool in_serch = true;

		str1[k] = str[i];

		for (int j = 0; j < substr.length; j++)
			if (str[i + j] != substr.str[j]) 
			{
				in_serch = false;
				break;
			}
		if (in_serch) 
		{
			for (int j = 0; j < rep.length; j++)
			{
				str1[k] = rep.str[j];
				k++;
			}
			i += substr.length - 1;
		}

		else k++;
	}
	for (int i = length - substr.length + 1; i < length; i++) {
		str1[k] = str[i];
		k++;
	}

	str1[k] = '\0';
	length = k;
	delete[] str;
	str = str1;
	str1 = nullptr;
	
}

void String::Replace(const char* substr, const char* rep)
{
	if (length < strlen(substr)) return;
	if (IndexOf(substr) < 0) return;
	if (capacity <= length + strlen(rep)) capacity = length + strlen(rep) + 80;

	char* str1 = new char[capacity]; // новая строка
	int k = 0;

	for (int i = 0; i < length - strlen(substr) + 1; i++)
	{
		bool in_serch = true;

		str1[k] = str[i];

		for (int j = 0; j < strlen(substr); j++)
			if (str[i + j] != substr[j])
			{
				in_serch = false;
				break;
			}
		if (in_serch)
		{
			for (int j = 0; j < strlen(rep); j++)
			{
				str1[k] = rep[j];
				k++;
			}

			i += strlen(substr) - 1;
		}

		else k++;
	}
	for (int i = length - strlen(substr) + 1; i < length; i++) {
		str1[k] = str[i];
		k++;
	}

	str1[k] = '\0';
	length = k;
	delete[] str;
	str = str1;
	str1 = nullptr;

}

String String::ToLower()
{
	String clone = *this;

	for (int i = 0; i < clone.length; i++)
		if (clone.str[i] >= 'A' && clone.str[i] <= 'Z' || clone.str[i] >= 'А' && clone.str[i] <= 'Я') clone.str[i] += 32;

	return clone;
}

String String::ToUpper()
{
	String clone = *this;

	for (int i = 0; i < clone.length; i++)
		if (clone.str[i] >= 'a' && clone.str[i] <= 'z' || clone.str[i] >= 'а' && clone.str[i] <= 'я') clone.str[i] -= 32;

	return clone;
}

#pragma endregion

