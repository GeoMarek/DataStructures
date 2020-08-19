#pragma once
template <typename T>
class DoublyNode
{
public:
    T value;
    DoublyNode<T>* prev;
    DoublyNode<T>* next;
    DoublyNode(T value);
};

template<typename T>
inline DoublyNode<T>::DoublyNode(T value) : value(value), prev(nullptr), next(nullptr)
{
}