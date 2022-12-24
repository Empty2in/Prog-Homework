#include <iostream>
#include <cstddef>
#include <fstream>
#include "String.h"

const int WORDS_ARRAY_SIZE = 4;
const int MAX_STR_LEN = 50;
String CreateString(const String& str);
bool isGood(std::istream& stream, size_t& pos);
void BubleSort(const int& size, String* arr);
void PrintArr(int size, const String* arr);
void FindChar(char c, const String* arr, int size);
String FindMaxSub(const String& sub, const String* arr, int size);

int main()
{
	char* str_test1 = new char[MAX_STR_LEN];
	char* str_test2 = new char[MAX_STR_LEN];
	size_t count = 0;
	std::size_t pos;

	try
	{
		std::cout << "Own Class String. Test start.\n\n";
		String str_empty;
		std::cout << "1. Base Constructor." << "\n";
		std::cout << "\tstring_1: " << str_empty << "\n\tsize: " << str_empty.getSize() << "\n\tcapacity: " << str_empty.getCapa() << "\n\n";

		std::cout << "2. Char Constructor." << "\n";
		std::cout << "Enter your string: ";
		std::cin >> str_test1;
		String str_char_made(str_test1);
		std::cout << "\tstring_2: " << str_char_made << "\n\tsize: " << str_char_made.getSize() << "\n\tcapacity: " << str_char_made.getCapa() << "\n\n";

		std::cout << "3. Copy Constructor." << "\n";
		String str_copy_made = str_char_made;
		std::cout << "\tstring_3: " << str_copy_made << "\n\tsize: " << str_copy_made.getSize() << "\n\tcapacity: " << str_copy_made.getCapa() << "\n\n";

		std::cout << "4. Move Constructor." << "\n";
		String str_move_made = CreateString(str_copy_made);
		std::cout << "\tstring_4: " << str_move_made << "\n\tsize: " << str_move_made.getSize() << "\n\tcapacity: " << str_move_made.getCapa() << "\n\n";

		std::cout << "5. Copy Operator." << "\n";
		str_empty = str_test1;
		std::cout << "\tstring_5: " << str_empty << "\n\tsize: " << str_empty.getSize() << "\n\tcapacity: " << str_empty.getCapa() << "\n\n";

		std::cout << "6. Move Operator." << "\n";
		str_empty = CreateString(str_test1);
		std::cout << "\tstring_6: " << str_empty << "\n\tsize: " << str_empty.getSize() << "\n\tcapacity: " << str_empty.getCapa() << "\n\n";

		std::cout << "7. [] Operator." << "\n";
		std::cout << "Enter pos of element: ";
		if (!isGood(std::cin, pos))
		{
			throw std::exception(" uncorrect pos.");
		}
		std::cout << "\tstring_7: " << str_empty << "\n\telement: " << str_empty[pos] << "\n\n";

		std::cout << "8. Method insert." << "\n";
		std::cout << "Enter your substring: ";
		std::cin >> str_test1;
		std::cout << "Enter pos of element: ";
		if (!isGood(std::cin, pos))
		{
			throw std::exception(" uncorrect pos.");
		}
		std::cout << "\tstring_befor: " << str_char_made << "\n\tsubstr: " << str_test1;
		std::cout << "\n\tstring_after: " << str_char_made.insert(pos, str_test1) << "\n\n";

		std::cout << "9. Method compare." << "\n";
		std::cout << "Enter first string: ";
		std::cin >> str_test1;
		String str_first_compare(str_test1);
		std::cout << "Enter second string: ";
		std::cin >> str_test2;
		String str_second_compare(str_test2);
		std::cout << "\n\tIs first string less then second one? " << str_first_compare.compare(str_second_compare) << "\n\n";

		std::cout << "Individual task. Var 3." << "\n";

		String* words = new String[WORDS_ARRAY_SIZE];
		std::ifstream in;
		std::string name;
		String finall;

		std::cout << "Enter fail name: ";
		std::cin >> name;
		in.open(name);
		if (!in.is_open())
		{
			throw std::exception(" fail couldn't be open.");
		}
		while (!in.eof())
		{
			char tmp[MAX_STR_LEN];
			for (int i = 0; i < WORDS_ARRAY_SIZE; i++) {
				in >> tmp;
				finall = tmp;
				words[i] = finall.getPtr();
			}
		}

		std::cout << "\nTest sort func\n";
		std::cout << "Arr befor sort:\n";
		PrintArr(WORDS_ARRAY_SIZE, words);
		BubleSort(WORDS_ARRAY_SIZE, words);
		std::cout << "Arr arter sort:\n";
		PrintArr(WORDS_ARRAY_SIZE, words);

		std::cout << "\nTest find func\n";
		char c;
		std::cout << "Enter element: ";
		std::cin >> c;
		FindChar(c, words, WORDS_ARRAY_SIZE);

		std::cout << "\nTest substr func\n";
		char* sub = new char[MAX_STR_LEN];
		std::cout << "Enter substr: ";
		std::cin >> sub;
		String new_sub(sub);
		String ans = FindMaxSub(new_sub, words, WORDS_ARRAY_SIZE);
		std::cout << "\tMax str begin of this sub: " << ans << "\n\tSize: " << ans.getSize();

		std::cout << "\n\nThe End of the program.\n";
		delete[] words;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		exit(-1);
	}
	delete[] str_test1;
	delete[] str_test2;
	return 0;
}

void PrintArr(int size, const String* arr)
{
	for (int i = 0; i < WORDS_ARRAY_SIZE; i++)
	{
		std::cout << "\t" << arr[i] << "\n";
	}
}
bool isGood(std::istream& stream, size_t& pos)
{
	stream >> pos;
	if (stream.peek() != '\n' || pos < 0 || stream.fail())
	{
		return false;
	}
	return true;
}
String CreateString(const String&str)
{
	String retBuff(str);
	return retBuff;
}
void BubleSort(const int& size, String* arr)
{
	String temp;
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (arr[j].compare(arr[j+1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void FindChar(char c, const String* arr, int size)
{
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].find(c) > 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}
String FindMaxSub(const String& sub, const String* arr, int size)
{
	String ans;
	size_t maxim = arr[0].getSize();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].substr(0).compare(sub) == 0)
		{
			if (arr[i].getSize() > maxim)
			{
				maxim = arr[i].getSize();
				ans = arr[i];
			}
		}
	}
	return ans;
}