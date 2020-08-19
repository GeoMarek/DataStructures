#pragma once
#include "Node.h"

template<typename T>
class Queue {
private:
	uint32_t count;
	Node<T>* front;
	Node<T>* back;
public:
	Queue();
	~Queue();
	bool IsEmpty();
	T Front();
	void Enqueue(T value);
	void Dequeue();
};

template<typename T>
inline Queue<T>::Queue() : count(0), front(nullptr), back(nullptr)
{
}

template<typename T>
inline Queue<T>::~Queue()
{
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	return count <= 0;
}

template<typename T>
inline T Queue<T>::Front()
{
	return front->value;
}

template<typename T>
inline void Queue<T>::Enqueue(T value)
{
	Node<T>* node = new Node<T>(value);
	if (count == 0) 
	{
		node->next = nullptr;
		front = node;
		back = front;
	}
	else 
	{
		back->next = node;
		back = node;
	}
	++count;
}

template<typename T>
inline void Queue<T>::Dequeue()
{
	if (count == 0) return;
	Node<T>* node = front;
	front = node->next;
	delete node;
	--count;
}
