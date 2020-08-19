#pragma once
#include <cstdint>
#include <iostream>
#include "DoublyNode.h"


template<typename T>
class DoublyLinkedList 
{
private:
    uint32_t count;
public:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyNode<T>* Get(uint32_t index);
    void InsertHead(T value);
    void InsertTail(T value);
    void Insert(uint32_t index, T value);
    uint32_t Search(T value);
    void RemoveHead();
    void RemoveTail();
    void Remove(uint32_t index);
    uint32_t Count();
    void PrintListForward();
    void PrintListBackward();
};

template<typename T>
inline void DoublyLinkedList<T>::RemoveHead()
{
    if (count == 0) return;

    DoublyNode<T>* node = head;
    head = head->next;
    delete node;
    if (head != nullptr) {

        head->prev = nullptr;
    }
    --count;
}

template<typename T>
inline void DoublyLinkedList<T>::RemoveTail()
{
    if (count == 0) return;
    if (count == 1) 
    {
        RemoveHead(); 
        return;
    }
    DoublyNode<T>* node = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete node;
    --count;
}

template<typename T>
inline void DoublyLinkedList<T>::Remove(uint32_t index)
{
    if (count == 0) return;
    if (index < 0 or index > count) return;
   
    if (index == 0) {
        RemoveHead();
        return;
    }
    else if (index == count - 1) {
        RemoveTail();
        return;
    }

    DoublyNode<T>* prevNode = head;
    for (uint32_t i = 0; i < index; ++i) 
    {
        prevNode = prevNode->next;
    }

    DoublyNode<T>* node = prevNode->next;
    DoublyNode<T>* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete node;
    --count;
}

template<typename T>
inline uint32_t DoublyLinkedList<T>::Count()
{
    return count;
}

template<typename T>
inline void DoublyLinkedList<T>::PrintListForward()
{
    DoublyNode<T>* node = head;

    while (node != nullptr)
    {
        std::cout << node->value << " -> ";
        node = node->next;
    }

    std::cout << "nullptr\n";
}

template<typename T>
inline void DoublyLinkedList<T>::PrintListBackward()
{
    DoublyNode<T>* node = tail;

    while (node != nullptr)
    {
        std::cout << node->value << " -> ";
        node = node->prev;
    }

    std::cout << "nullptr\n";
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : count(0), head(nullptr), tail(nullptr)
{
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
}

template<typename T>
inline DoublyNode<T>* DoublyLinkedList<T>::Get(uint32_t index)
{
    if (index < 0 or index > count) return nullptr;  
    DoublyNode<T>* node = head;
    for (int i = 0; i < index; ++i)
    {
        node = node->next;
    }
    return node;
}

template<typename T>
inline void DoublyLinkedList<T>::InsertHead(T value)
{
    DoublyNode<T>* node = new DoublyNode<T>(value);
    node->next = head;
    if (head != nullptr) {
        head->prev = node;
    }
    head = node;
    if (count == 0) tail = head;
    ++count;
}

template<typename T>
inline void DoublyLinkedList<T>::InsertTail(T value)
{
    if (count == 0) 
    {
        InsertHead(value);
        return;
    }
    DoublyNode<T>* node = new DoublyNode<T>(value);
    
    tail->next = node;
    node->prev = tail;
    tail = node;
    ++count;
}

template<typename T>
inline void DoublyLinkedList<T>::Insert(uint32_t index, T value)
{
    if (index<0 or index > count) return;
    else if (index == 0) 
    {
        InsertHead(value);
        return;
    }
    else if (index == count)
    {
        InsertTail(value);
        return;
    }
   
    DoublyNode<T>* prevNode = head;

    for (uint32_t i = 0; i < index; ++i) 
    {
        prevNode = prevNode->next;
    }

    DoublyNode<T>* nextNode = prevNode->next;
    DoublyNode<T>* node = new DoublyNode<T>(value);

    node->next = nextNode;
    node->prev = prevNode;
    prevNode->next = node;
    nextNode->prev = node;

    ++count;
}

template<typename T>
inline uint32_t DoublyLinkedList<T>::Search(T value)
{
    if (count == 0) return uint32_t();
    uint32_t index = 0;
    Node<T>* node = head;

    while (node->value != value)
    {
        index++;
        node = node->next;
        if (node == nullptr) return uint32_t();
    }
    return index;
}


