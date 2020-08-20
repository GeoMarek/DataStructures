#pragma once
#include <cstdint>
#include <iostream>
#include "Node.h"

using std::cout;
using std::endl;



template<typename T> 
class LinkedList {
private:
	uint32_t count;
public:
	Node<T>* Head;
	Node<T>* Tail;
	LinkedList();
	~LinkedList();
	Node<T>* Get(uint32_t index);
	void InsertHead(T value);
	void InsertTail(T value);
	void Insert(uint32_t index, T value);
	uint32_t Search(T value);
	void RemoveHead();
	void RemoveTail();
	void Remove(uint32_t index);
	uint32_t Count();
	void PrintList();
};

template<typename T>
inline LinkedList<T>::LinkedList() : count(0), Head(nullptr), Tail(nullptr)
{
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
}

template<typename T>
inline Node<T>* LinkedList<T>::Get(uint32_t index)
{
	if (index<0 || index>count) return nullptr;
	Node<T>* node = Head;
	
	for (uint32_t i = 0; i < index; ++i) 
	{
		node = node->next;
	}

	return node;
}

template<typename T>
inline void LinkedList<T>::InsertHead(T value)
{
	Node<T>* node = new Node<T>(value);
	node->next = Head;
	Head = node;
	if (count == 0) Tail = Head;
	count++;
}

template<typename T>
inline void LinkedList<T>::InsertTail(T value)
{
	if (count == 0) InsertHead(value);
	Node<T>* node = new Node<T>(value);
	Tail->next = node;
	Tail = node;
	++count;
}

template<typename T>
inline void LinkedList<T>::Insert(uint32_t index, T value)
{
	if (index < 0 || index > count) return;
	if (index == 0) InsertHead(value);
	else if (index == count) InsertTail(value);
		
	Node<T>* prevNode = Head;
	for (uint32_t i = 0; i < index; ++i) 
	{
		prevNode = prevNode->next;
	}

	Node<T>* nextNode = prevNode->next;
	Node<T>* node = new Node<T>(value);
	
	node->next = nextNode;
	prevNode->next = node;
	++count;
}

template<typename T>
inline uint32_t LinkedList<T>::Search(T value)
{
	if (count == 0) return uint32_t();
	uint32_t index = 0;
	Node<T>* node = Head;

	while (node->value != value) 
	{
		index++;
		node = node->next;
		if (node == nullptr) return uint32_t();
	}
	return index;
}

template<typename T>
inline void LinkedList<T>::RemoveHead()
{
	if (count == 0) return;
	Node<T>* node = Head;
	Head = Head->next;
	delete node;
	--count;
}

template<typename T>
inline void LinkedList<T>::RemoveTail()
{
	if (count == 0) { return; }
	if (count == 1) { RemoveHead(); return; }

	Node<T>* prevNode = Head;
	Node<T>* node = Head->next;
	
	while (node->next != nullptr) 
	{
		prevNode = prevNode->next;
		node = node->next;
	}
	prevNode->next = nullptr;
	Tail = prevNode;
	delete node;
	--count;
}

template<typename T>
inline void LinkedList<T>::Remove(uint32_t index)
{
	if (count == 0) return;
	if (index < 0 || index >= count) { return; }
	if (index == 0) { RemoveHead(); return; }
	else if (index == count - 1) { RemoveTail(); return; }
	
	Node<T>* prevNode = Head;
	for (uint32_t i = 0; i < index - 1; ++i)
	{
		prevNode = prevNode->next;
	}
	
	Node<T>* node = prevNode->next;
	Node<T>* nextNode = node->next;
	prevNode->next = nextNode;
	delete node;
	--count;
}

template<typename T>
inline uint32_t LinkedList<T>::Count()
{
	return count;
}

template<typename T>
inline void LinkedList<T>::PrintList()
{
	Node<T>* node = Head;
	while (node->next != nullptr) 
	{
		cout << node->value << " -> ";
		node = node->next;
	}
	cout << "nullptr" << endl;
}
