#pragma once
#include "DoublyNode.h"


template<typename T> 
class Deque 
{
private:
	uint32_t count;
	DoublyNode<T>* front;
	DoublyNode<T>* back;
public:
	Deque();
	~Deque();
	T Front();
	T Back();
	void EnqueueFront(T value);
	void EnqueueBack(T value);
	void DequeueFront();
	void DequeueBack();
	bool IsEmpty();
};

template<typename T>
inline Deque<T>::Deque() : count(0), front(nullptr), back(nullptr)
{
}

template<typename T>
inline Deque<T>::~Deque()
{
}

template<typename T>
inline T Deque<T>::Front()
{
	return front->value;
}

template<typename T>
inline T Deque<T>::Back()
{
	return back->value;
}

template<typename T>
inline void Deque<T>::EnqueueFront(T value)
{
	DoublyNode<T>* node = new DoublyNode<T>(value);
	node->next = front;
	if (front != nullptr) front->prev = node;
	front = node;
	if (count == 0) back = front;
	++count;
}

template<typename T>
inline void Deque<T>::EnqueueBack(T value)
{
	if (count == 0) 
	{
		EnqueueFront(value);
		return;
	}
	DoublyNode<T>* node = new DoublyNode<T>(value);
	back->next = node;
	node->prev = back;
	back = node;
	++count;
}

template<typename T>
inline void Deque<T>::DequeueFront()
{
	if (count == 0) return;
	DoublyNode<T>* node = front;
	front = front->next;
	delete node;
	if (front != nullptr) front->prev = nullptr;
	--count;
}

template<typename T>
inline void Deque<T>::DequeueBack()
{
	if (count == 0) return;
	if (count == 1) 
	{
		DequeueFront();
		return;
	}
	
	DoublyNode<T>* node = back;
	back = back->prev;
	back->next = nullptr;
	delete node;
	--count;
}

template<typename T>
inline bool Deque<T>::IsEmpty()
{
	return count <= 0;
}
