#include "String.h"
#include <cstring>
#include <iostream>

String::String() : size(0), capacity(0), pointer(nullptr) {}
String::String(const char* str)
{
	this->size = strlen(str);
	this->pointer = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->pointer[i] = str[i];
	}
	this->pointer[size] = '\0';
	this->capacity = sizeof(*pointer)*(size);
}
String::String(const String& other_str)
{
	this->size = other_str.size;
	this->capacity = other_str.capacity;
	this->pointer = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->pointer[i] = other_str.pointer[i];
	}
	this->pointer[size] = '\0';
}
String::String(String&& str) noexcept
{
	this->size = str.size;
	this->pointer = str.pointer;
	this->capacity = str.capacity;
	str.pointer = nullptr;
}
String::~String()
{
	delete[] this->pointer;
}


String& String::operator = (const char* str)
{
	if (this->pointer != nullptr)
	{
		delete[] this->pointer;
	}
	this->size = strlen(str);
	this->pointer = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->pointer[i] = str[i];
	}
	this->pointer[size] = '\0';
	this->capacity = sizeof(*pointer) * (size);
	return *this;
}
String& String::operator = (const String& str)
{
	if (this->pointer != nullptr)
	{
		delete[] this->pointer;
	}
	this->size = str.getSize();
	this->pointer = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->pointer[i] = str[i];
	}
	this->pointer[size] = '\0';
	this->capacity = str.getCapa();
	return *this;
}
char& String::operator [] (std::size_t pos)
{
	if (pos > this->size)
	{
		throw std::exception(" pos out of range.");
	}
	return this->pointer[pos];
}
const char& String::operator [] (std::size_t pos) const
{
	if (pos > this->size)
	{
		throw std::exception(" pos out of range.");
	}
	return this->pointer[pos];
}
String& String::operator= (String&& str) noexcept
{
	if (this == &str)
	{
		return *this;
	}
	delete[] this->pointer;
	this->pointer = str.pointer;
	str.pointer = nullptr;
	return *this;
}
String& String::insert(std::size_t pos, const char* str)
{
	size_t size_str = strlen(str);
	if (size_str == 0)
	{
		return *this;
	}
	if (this->pointer == nullptr)
	{
		return *this;
	}
	
	
	if (pos > this->size-1)
	{
		return *this;
	}
	std::size_t newSize = (this->size + size_str);
	char* newStr = new char[newSize];
	if (this->capacity <= size_str + this->size)
	{
		this->capacity = size_str + this->size;
		this->size = this->capacity;
	}
	int j = 0;
	int k = 0;
	for (int i = 0; i < pos; i++, j++)
	{
		newStr[j] = this->pointer[i];
	}
	for (int i = pos; i < size_str + pos; i++, k++)
	{
		newStr[i] = str[k];
	}
	for (size_t i = pos + size_str; i < newSize; i++, j++)
	{
		newStr[i] = this->pointer[j];
	}
	delete this->pointer;
	this->pointer = newStr;
	return *this;
}
int String::compare(const String& str)
{
	size_t count = 0;
	int ans = 0;
	if (this->size > str.size)
	{
		count = str.size;
	}
	else
	{
		count = this->size;
	}
	for (int i = 0; i < count; i++)
	{
		if (this->pointer[i] < str[i])
		{
			return --ans;
		}
		if (this->pointer[i] > str[i])
		{
			return ++ans;
		}
	}
	return ans;
}
char* String::getPtr() const
{
	return this->pointer;
}
size_t String::find(char c, size_t pos) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (c == this->pointer[i])
		{
			pos = i;
		}
		else
		{
			pos = npos;
		}
	}
	return pos;
}
String String::substr(size_t pos, size_t len) const
{
	String SubStr;
	if (pos == this->size)
	{
		return SubStr;
	}
	if (pos > this->size)
	{
		throw std::exception("pos out of range.");
	}
	for (size_t i = 0; i < len; i++)
	{
		SubStr[i] = this->pointer[pos + i];
	}
	return SubStr;
}
std::ostream& operator << (std::ostream& os, const String& str)
{
	for (int i = 0; i < str.getSize(); i++)
	{
		os << str[i];
	}
	return os;
}
std::size_t String::getCapa() const
{
	return this->capacity;
}
std::size_t String::getSize() const
{
	return this->size;
}