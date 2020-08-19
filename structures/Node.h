#pragma once

template<typename T>
class Node
{
public:
	T value;
	Node<T>* next;
	Node(T value);
};

template<typename T>
inline Node<T>::Node(T value) : value(value), next(nullptr)
{
}