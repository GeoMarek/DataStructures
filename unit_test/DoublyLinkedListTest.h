#pragma once
#include "pch.h"

TEST_F(DoublyLinkedListFixture, GetWithBadIndexReturnNullPointer)
{
	DoublyNode<int>* overflow = full_list.Get(100);
	DoublyNode<int>* negative = full_list.Get(-1);
	ASSERT_EQ(overflow, nullptr);
	ASSERT_EQ(negative, nullptr);
}

TEST_F(DoublyLinkedListFixture, GetWithGoodIndexReturnsCorrectValue)
{
	uint32_t i = 0;
	while (i < full_list.Count()) 
	{
		ASSERT_EQ(full_list.Get(i)->value, i+1);
		++i;
	}
	
}

TEST_F(DoublyLinkedListFixture, InsertHeadPutValueAtTheBeginningOfList)
{
	int value = 100;
	full_list.InsertHead(value);
	ASSERT_EQ(full_list.Get(0)->value, value);
}

TEST_F(DoublyLinkedListFixture, InsertTailPutValueAtTheEndOfList)
{
	int value = 100;
	full_list.InsertTail(value);
	ASSERT_EQ(value, full_list.Get(full_list.Count()-1)->value);
}

TEST_F(DoublyLinkedListFixture, InsertAtBadIndexDontChangeCount)
{
	uint32_t count = full_list.Count();
	full_list.Insert(-1, 100);
	full_list.Insert(100, 100);
	ASSERT_EQ(count, full_list.Count());
}

TEST_F(DoublyLinkedListFixture, InsertAtIndexEqualToCountInsertTail)
{
	int value = 100;
	uint32_t count = full_list.Count();
	full_list.Insert(count, value);
	ASSERT_EQ(full_list.Get(count)->value, value);
}

TEST_F(DoublyLinkedListFixture, RemoveHeadDeleteFirstElementAndDecrementCount)
{
	int second = full_list.Get(1)->value;
	int count = full_list.Count();
	full_list.RemoveHead();
	ASSERT_EQ(second, full_list.Get(0)->value);
	ASSERT_EQ(count, full_list.Count() + 1);

}

TEST_F(DoublyLinkedListFixture, RemoveTailDeleteLastElementAndDecrementCount)
{
	uint32_t count = full_list.Count();
	int penultimate_value = full_list.Get(count-2)->value;
	full_list.RemoveTail();
	uint32_t last_index = full_list.Count() - 1;
	ASSERT_EQ(full_list.Get(last_index)->value, penultimate_value);
	ASSERT_EQ(count, full_list.Count() + 1);
}

TEST_F(DoublyLinkedListFixture, RemoveAtBadIndexDontChangeCount)
{
	int count = full_list.Count();
	full_list.Remove(-1);
	ASSERT_EQ(full_list.Count(), count);
	full_list.Remove(100);
	ASSERT_EQ(full_list.Count(), count);
	
}