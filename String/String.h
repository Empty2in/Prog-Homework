#pragma once
#include <cstddef>
#include <iostream>
class String
{
private:
	std::size_t  size;
	std::size_t capacity;
	char* pointer;
	static const size_t npos = -1;
	
public:
	String();
	String(const char* str);
	String(const String& other_str);
	String(String&& str) noexcept;
	~String();

	String& operator = (const char* str);
	char& operator[] (std::size_t pos);
	const char& operator [] (std::size_t pos) const;
	String& operator= (String&& str) noexcept;
	String& operator = (const String& str);
	String& insert(std::size_t pos, const char* str);
	int compare(const String& str);
	size_t find(char c, size_t pos = 0) const;
	String substr(size_t pos = 0, size_t len  = npos) const;

	friend std::ostream& operator << (std::ostream& os, const String& str);
	std::size_t getCapa() const;
	std::size_t getSize() const;
	char* getPtr() const;
};