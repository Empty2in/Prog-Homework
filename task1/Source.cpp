#include <iostream>
#include <ctime>
#include "DictionaryList.h"


void input(DictionaryList<int>& list, int length);
DictionaryList<int> generate()
{
	DictionaryList<int> M;
	input(M, 7);
	return M;
}


int main()
{
	DictionaryList<int>D; //constructor of move and operator of move
	D = generate();
	DictionaryList<int>L;
	input(L, 5);
	
	std::cout << "\nD: ";
	D.outAll();
	std::cout << "\nL: ";
	L.outAll();
	DictionaryList<int>Inter;
	Inter = getIntersection(D, L);
	std::cout << "\nI: ";
	Inter.outAll();
	std::cout << '\n';

	return 0;
}

void input(DictionaryList<int>& list, int length)
{
	/*srand(time(NULL));*/
	for (int i = 0; i < length; ++i)
	{
		list.insert(rand() % 10);
	}
}
