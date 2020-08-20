//
// pch.h
// Header for standard system include files.
//

#pragma once
#include "gtest/gtest.h"
#include "E:\Git\DataStructures\structures\Stack.h"
#include "E:\Git\DataStructures\structures\Queue.h"
#include "E:\Git\DataStructures\structures\List.h"

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



