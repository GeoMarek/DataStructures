#pragma once
#include "pch.h"



TEST_F(DequeTestFixture, FrontReturnFirstValue) 
{
	int item = 1;
	while (!full_deque.IsEmpty()) 
	{
		int value = full_deque.Front();
		ASSERT_EQ(value, item);
		full_deque.DequeueFront();
		++item;
	}
}

TEST_F(DequeTestFixture, BackReturnsLastValue)
{
	int item = 10;
	while (!full_deque.IsEmpty()) 
	{
		int value = full_deque.Back();
		ASSERT_EQ(item, value);
		full_deque.DequeueBack();
		--item;
	}
}

TEST_F(DequeTestFixture, EqueueFrontInsertValueAtTheBeginning)
{
	int value = 100;
	full_deque.EnqueueFront(value);
	ASSERT_EQ(value, full_deque.Front());
}
TEST_F(DequeTestFixture, EqueueBackInsertValueAtTheEnd)
{
	int value = 100;
	full_deque.EnqueueBack(value);
	ASSERT_EQ(value, full_deque.Back());
}
TEST_F(DequeTestFixture, IsEmptyReturnIfDequeHasElements)
{
	ASSERT_FALSE(full_deque.IsEmpty());
	ASSERT_TRUE(empty_deque.IsEmpty());
}

