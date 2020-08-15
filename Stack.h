#pragma once
#include "Node.h"

template<typename T>
class Stack {
private:
	uint32_t count;
	Node<T>* top;
public:
	Stack();
	~Stack();
	bool IsEmpty();
	T Top();
	void Push(T value);
	void Pop();
};

template<typename T>
inline Stack<T>::Stack() : count(0), top(nullptr)
{
}

template<typename T>
inline Stack<T>::~Stack()
{
}

template<typename T>
inline bool Stack<T>::IsEmpty()
{
	return count <= 0;
}

template<typename T>
inline T Stack<T>::Top()
{
	return top->value;
}

template<typename T>
inline void Stack<T>::Push(T value)
{
	Node<T>* node = new Node<T>(value);
	node->next = top;
	top = node;
	++count;
}

template<typename T>
inline void Stack<T>::Pop()
{
	if (IsEmpty()) return;
	
	Node<T>* node = top;
	top = top->next;
	delete node;

	--count;
}
