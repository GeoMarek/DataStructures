//
// pch.h
// Header for standard system include files.
//

#pragma once
#include "gtest/gtest.h"
#include "E:\Git\DataStructures\structures\Stack.h"
#include "E:\Git\DataStructures\structures\Queue.h"
#include "E:\Git\DataStructures\structures\List.h"
#include "E:\Git\DataStructures\structures\LinkedList.h"
#include "E:\Git\DataStructures\structures\Deque.h"
#include "E:\Git\DataStructures\structures\DoublyLinkedList.h"

struct stackTestFixture : public testing::Test
{
    Stack<int> empty_stack = Stack<int>();
    Stack<int> my_stack = Stack<int>();
    void SetUp()
    {
        int values[] = { 1,2,3,4,5,6,7,8,9,10 };
        for (auto& value : values)
        {
            my_stack.Push(value);
        }
    }
    void TearDown() {}
};

struct QueueTestFixture : public testing::Test
{
    Queue<int> empty_queue = Queue<int>();
    Queue<int> full_queue = Queue<int>();
    void SetUp()
    {
        int values[] = { 1,2,3,4,5,6,7,8,9,10 };
        for (auto& value : values)
        {
            full_queue.Enqueue(value);
        }
    }
    void TearDown() {}
};

struct  ListTestFixture : public testing::Test
{
    List<int> empty_list = List<int>();
    List<int> full_list = List<int>();
    void SetUp()
    {
        int values[] = { 1,2,3,4,5,6,7,8,9,10 };
        for (auto& value : values)
        {
            full_list.Insert(full_list.Count(), value);
        }
    }
    void TearDown(){}
};

struct  LinkedListFixture : public testing::Test
{
    LinkedList<int> empty_linked_list = LinkedList<int>();
    LinkedList<int> full_linked_list = LinkedList<int>();
    void SetUp() 
    {
        int values[] = { 1,2,3,4,5,6,7,8,9,10 };
        for (auto& value : values)
        {
            full_linked_list.InsertTail(value);
        }
    }
    void TearDown() {}
};

struct DequeTestFixture : public testing::Test 
{
    Deque<int> full_deque = Deque<int>();
    Deque<int> empty_deque = Deque<int>();
    void SetUp() 
    {
        int values[] = { 1,2,3,4,5,6,7,8,9,10 };
        for (auto& value : values)
        {
            full_deque.EnqueueBack(value);
        }
    }
    void TearDown() {}
};

struct DoublyLinkedListFixture : public testing::Test 
{
    DoublyLinkedList<int> empty_list = DoublyLinkedList<int>();
    DoublyLinkedList<int> full_list = DoublyLinkedList<int>();
    void SetUp()
    {
        int values[] = { 1,2,3,4,5,6,7,8,9,10 };
        for (auto& value : values)
        {
            full_list.InsertTail(value);
        }
    }
    void TearDown() {}
};