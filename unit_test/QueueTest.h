#pragma once
#include "pch.h"


TEST_F(QueueTestFixture, IsEmptyReturnTrueIfQueueIsEmpty)
{
    ASSERT_EQ(empty_queue.IsEmpty(), true);
}

TEST_F(QueueTestFixture, IsEmptyReturnFalseIfQueueIsNotEmpty)
{
    ASSERT_EQ(full_queue.IsEmpty(), false);
}

TEST_F(QueueTestFixture, FrontReturnFirstInputedValue) 
{
    empty_queue.Enqueue(0);
    ASSERT_EQ(empty_queue.Front(), 0);
    ASSERT_EQ(full_queue.Front(), 1);
}

TEST_F(QueueTestFixture, DequeueRemoveFirstInputedValue) 
{
    int firstInputedValue = 1;
    while (!full_queue.IsEmpty()) 
    {
        ASSERT_EQ(firstInputedValue++, full_queue.Front());
        full_queue.Dequeue();
    }
}
TEST_F(QueueTestFixture, EnqueueAddElementAtEndOfQueue) 
{
    int inputedValue = 100;
    int expectedValue;
    full_queue.Enqueue(inputedValue);
    while (!full_queue.IsEmpty())
    {
        expectedValue = full_queue.Front();
        full_queue.Dequeue();
    }
    ASSERT_EQ(expectedValue, inputedValue);
}


/*
    bool IsEmpty();
    T Front();
    void Enqueue(T value);
    void Dequeue();
*/
