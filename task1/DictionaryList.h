#include <iostream>
#ifndef __DICTIONARY_LIST
#define __DICTIONARY_LIST

template<typename T>
class DictionaryList
{
private:
	template<typename T>
	struct Node
	{
		T _data;
		Node* _next;
		Node(T data = T(), Node* next = nullptr)
		{
			this->_data = data;
			this->_next = next;

		}
	};
	
	Node<T>* _head;
	int _size;

	void copy(const DictionaryList<T>& obj)
	{
		clear();
		Node<T>* temp = obj._head;
		for (int i = 0; i < obj._size; ++i)
		{
			push_back(temp->_data);
			temp = temp->_next;
		}
		_size = obj._size;
	}
	void deleted(Node<T>* del)
	{
		Node<T>* temp = _head;
		while (temp->_next != del)
		{
			temp = temp->_next;
		}
		temp->_next = del->_next;
		delete del;
		_size--;
	}

public:

	DictionaryList() : _head(nullptr), _size(0) {}
	~DictionaryList() { clear(); }
	DictionaryList(const DictionaryList<T>& scr);
	DictionaryList(DictionaryList<T>&& scr) noexcept;

	DictionaryList<T>& operator=(const DictionaryList<T>& scr);
	DictionaryList<T>& operator=(DictionaryList<T>&& scr) noexcept;
	T& operator[](const size_t index);


	int getSize() { return _size; }
	bool is_empty() { return this->_head == nullptr; };
	void clear();
	void swap(DictionaryList<T>& other) noexcept;
	void push_back(T data);
	void pop_front();
	void outAll();

	bool search(const T data);
	bool insert(const T& data);
	bool deleted(T data);

	bool merge(DictionaryList<T>& other);
	bool deleted(const DictionaryList<T>& other);

	template<typename T>
	friend DictionaryList<T>& getIntersection(DictionaryList<T>& one, DictionaryList<T>& two)
	{
		DictionaryList<T>Inter;
		Node<T>* temp = one._head;
		while (temp != nullptr)
		{
			if (two.search(temp->_data))
			{
				Inter.insert(temp->_data);
			}
			temp = temp->_next;
		}
		return Inter;
	}

	
};

template<typename T>
inline DictionaryList<T>::DictionaryList(DictionaryList<T>&& scr) noexcept
{
	_head = scr._head;
	_size = scr._size;
	scr._head = nullptr;
	scr._size = 0;
}
template<typename T>
inline DictionaryList<T>::DictionaryList(const DictionaryList<T>& scr)
{
	if (scr._head == nullptr)
	{
		this->_head = nullptr;
		this->_size = 0;
		return;
	}
	this->_head = new Node<T>(scr._head->_data);
	Node<T>* ptrScr = scr._head->_next;
	Node<T>* destScr = this->_head;
	while (ptrScr != nullptr)
	{
		destScr->_next = new Node<T>(ptrScr->_data);
		destScr = destScr->_next;
		ptrScr = ptrScr->_next;
	}
	this->_size = scr._size;
	return;

}

template<typename T>
DictionaryList<T>& DictionaryList<T>::operator=(const DictionaryList<T>& scr)
{
	if (this == &scr)
	{
		return *this;
	}
	copy(scr);
	return *this;
}
template<typename T>
DictionaryList<T>& DictionaryList<T>::operator=(DictionaryList<T>&& scr) noexcept
{
	if (this != &scr)
	{
		swap(scr);
	}
	return *this;
}


template<typename T>
inline void DictionaryList<T>::swap(DictionaryList<T>& other) noexcept
{
	std::swap(_head, other._head);
	std::swap(_size, other._size);
}
template<typename T>
inline void DictionaryList<T>::clear()
{
	while (_size)
	{
		pop_front();
	}
}
template<typename T>
void DictionaryList<T>::push_back(T data)
{
	if (this->is_empty())
	{
		this->_head = new Node<T>(data);

	}
	else
	{
		Node<T>* temp = this->_head;
		while (temp->_next != nullptr)
		{
			temp = temp->_next;
		}
		temp->_next = new Node<T>(data);
	}
	this->_size++;
}
template<typename T>
void DictionaryList<T>::pop_front()
{
	if (!is_empty())
	{
		Node<T>* temp = this->_head;
		_head = _head->_next;
		delete temp;
		this->_size--;
	}

}
template<typename T>
void DictionaryList<T>::outAll()
{
	Node<T>* temp = this->_head;
	while (temp != nullptr)
	{
		std::cout << temp->_data << " ";
		temp = temp->_next;
	}
}
template<typename T>
T& DictionaryList<T>::operator[](const size_t index)
{
	size_t counter = 0;
	Node<T>* temp = this->_head;
	while (temp != nullptr)
	{
		if (counter == index)
		{
			return temp->_data;
		}
		temp = temp->_next;
		counter++;
	}
}

template<typename T>
bool DictionaryList<T>::search(const T data)
{
	Node<T>* temp = this->_head;
	while (temp != nullptr)
	{
		if (data == temp->_data)
		{
			return true;
		}
		temp = temp->_next;
	}
	return false;
}
template<typename T>
bool DictionaryList<T>::insert(const T& data)
{
	if (this->is_empty() || data < _head->_data)
	{
		_head = new Node<T>(data, _head);
		_size++;
		return true;
	}
	else
	{
		Node<T>* prev = this->_head;
		while (prev != nullptr)
		{
			if (data == prev->_data)
			{
				return false;
			}
			else if ((prev->_data < data) && (prev->_next == nullptr) || (prev->_next->_data > data))
			{
				Node<T>* newNode = new Node<T>(data, prev->_next);
				prev->_next = newNode;
				_size++;
				return true;
			}
			prev = prev->_next;
		}
	}
	return false;
}
template<typename T>
bool DictionaryList<T>::deleted(T data)
{
	if (is_empty())
	{
		return false;
	}
	else if (data == this->_head->_data)
	{
		pop_front();
		return true;
	}
	else
	{
		Node<T>* temp = this->_head;
		while (temp != nullptr)
		{
			if (temp->_data == data)
			{
				this->deleted(temp);
				return true;
			}
			temp = temp->_next;
		}
	}
	return false;
	
}

template<typename T>
bool DictionaryList<T>::merge(DictionaryList<T>& other)
{
	Node<T>* temp = other._head;
	while (temp != nullptr)
	{
		insert(temp->_data);
		temp = temp->_next;
	}
	other.clear();
	return true;
}
template<typename T>
bool DictionaryList<T>::deleted(const DictionaryList<T>& other)
{
	Node<T>* temp = other._head;
	while (temp != nullptr)
	{
		deleted(temp->_data);
		temp = temp->_next;
	}
	return true;
}



#endif


/*
проверить, есть ли элемент в словаре (search)
2) проверить узел
добавить элемент (insert);
2) добавить узел

3) Получить пересечение словарей (getIntersection). 
Дружественная функция, формирующая новый словарь, содержащий слова, присутствующие одновременно в двухсловарях. 
Исходные словари остаются без изменения.
*/
