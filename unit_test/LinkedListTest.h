#pragma once
#include "pch.h"

TEST_F(LinkedListFixture, GetWithIncorrectIndexReturnNullPointer)
{
    ASSERT_EQ(full_linked_list.Get(-5), nullptr);
    ASSERT_EQ(full_linked_list.Get(100), nullptr);
}

TEST_F(LinkedListFixture, GetReturnValidValueWithGoodIndex)
{
    for (uint32_t i = 1; i < 10; ++i) 
    {
        Node<int>* get_node = full_linked_list.Get(i);
        ASSERT_EQ(get_node->value, i);
    }
}

TEST_F(LinkedListFixture, InsertHeadAddNodeAtBeginOfList)
{
    int insert = 100;
    empty_linked_list.InsertHead(insert);
    full_linked_list.InsertHead(insert);

    ASSERT_EQ(empty_linked_list.Get(0)->value, insert);
    ASSERT_EQ(full_linked_list.Get(0)->value, insert);
}

TEST_F(LinkedListFixture, InsertTailAddNodeAtTheEndOfList)
{
    int insert = 100;
    empty_linked_list.InsertTail(insert);
    full_linked_list.InsertTail(insert);

    uint32_t max_index_empty = empty_linked_list.Count() - 1;
    int empty_last = empty_linked_list.Get(max_index_empty)->value;

    uint32_t max_index_full = full_linked_list.Count() - 1;
    int full_last = full_linked_list.Get(max_index_full)->value;

    ASSERT_EQ(empty_last, insert);
    ASSERT_EQ(full_last, insert);
}

TEST_F(LinkedListFixture, InsertWithIncorrectIndexDidNotChangeCount)
{
    empty_linked_list.Insert(-5, 5);
    ASSERT_EQ(empty_linked_list.Count(), 0);
    empty_linked_list.Insert(100, 5);
    ASSERT_EQ(empty_linked_list.Count(), 0);
}

TEST_F(LinkedListFixture, InsertWithIndexEqualToCountIsTailInserting)
{
    int insert = 100;
    uint32_t count_list = full_linked_list.Count();
    full_linked_list.Insert(count_list, insert);
    uint32_t max_index_full = full_linked_list.Count() - 1;
    int last = full_linked_list.Get(max_index_full)->value;
    ASSERT_EQ(last, insert);
}

TEST_F(LinkedListFixture, IfSearchDidNotFoundReturnDefaultInitializer)
{
    auto result = full_linked_list.Search(100);
    ASSERT_EQ(result, uint32_t());

}

TEST_F(LinkedListFixture, RemoveHeadDecrementCountAndPopFirstValue)
{
    uint32_t count_before = full_linked_list.Count();
    int second = full_linked_list.Get(1)->value;
    full_linked_list.RemoveHead();

    ASSERT_EQ(count_before - 1, full_linked_list.Count());
    ASSERT_EQ(second, full_linked_list.Get(0)->value);
}

TEST_F(LinkedListFixture, RemoveTailDecrementCountAndPopLastValue)
{
    uint32_t count_before = full_linked_list.Count();
    uint32_t almost_last_index = count_before - 2;
    int almost_last_value = full_linked_list.Get(almost_last_index)->value;

    full_linked_list.RemoveTail();

    uint32_t count_after = full_linked_list.Count();
    int new_last_value = full_linked_list.Get(count_after - 1)->value;
    
    ASSERT_EQ(almost_last_value, new_last_value);
    ASSERT_EQ(count_after+1, count_before);
}

TEST_F(LinkedListFixture, RemoveWithIncorrectIndexDidNotChangeCount)
{
    uint32_t size = full_linked_list.Count();
    full_linked_list.Remove(-5);
    full_linked_list.Remove(100);
    ASSERT_EQ(full_linked_list.Count(), size);
}

TEST_F(LinkedListFixture, RemoveWithValidIndexDeleteValue)
{
    uint32_t size = full_linked_list.Count();
    int item = 1;
    while (static_cast<uint32_t>(item) <= size)
    {
        uint32_t index = full_linked_list.Search(item);
        full_linked_list.Remove(index);
        ASSERT_EQ(full_linked_list.Search(item), uint32_t());
        item++;
    }
}

TEST_F(LinkedListFixture, CountInEmptyListIsEqualToZero)
{
    ASSERT_EQ(empty_linked_list.Count(), 0);
}

