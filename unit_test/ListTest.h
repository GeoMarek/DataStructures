#pragma once
#include "pch.h"

TEST_F(ListTestFixture, CountInEmptyListIsEqualToZero)
{
    ASSERT_EQ(empty_list.Count(), 0);
}

TEST_F(ListTestFixture, InsertAtNegaticeIndexDontChangeList)
{
    int count_before = full_list.Count();
    full_list.Insert(-5, 1);
    int count_after = full_list.Count();
    ASSERT_EQ(count_before, count_after);
}

TEST_F(ListTestFixture, InsertBiggerThanCountDontChangeList)
{
    int count_before = full_list.Count();
    full_list.Insert(100, 1);
    int count_after = full_list.Count();
    ASSERT_EQ(count_before, count_after);
}

TEST_F(ListTestFixture, InsertChangeListAtIndexGivenAsParameter)
{
    for (int i = 0; i < 10; i++) full_list.Insert(i, 100+i);
    
    for (int i = 0; i < 10; i++) 
    {
        ASSERT_EQ(full_list.Get(i), 100 + i);
    }
}

TEST_F(ListTestFixture, GetReturnValueIfIndexIsCorrect)
{
    for (int i = 0; i < full_list.Count(); i++) 
    {
        ASSERT_EQ(full_list.Get(i), i + 1);
    }
}
TEST_F(ListTestFixture, GetReturnDefaultInitializerIfIndexIsIncorrect)
{
    int negative = full_list.Get(-5);
    int overflow = full_list.Get(100);
    ASSERT_EQ(negative, int());
    ASSERT_EQ(overflow, int());
}

TEST_F(ListTestFixture, RemoveWithNegativeIndexDontChangeList)
{
    int count_before = full_list.Count();
    full_list.Remove(-5);
    int negative = full_list.Count();
    ASSERT_EQ(count_before, negative);
}

TEST_F(ListTestFixture, RemoveWithToBigIndexDontChangeList)
{
    int count_before = full_list.Count();
    full_list.Remove(100);
    int overflow = full_list.Count();
    ASSERT_EQ(count_before, overflow);
}

TEST_F(ListTestFixture, RemoveWithGoodIndexDecrementCount)
{
    int count_before = full_list.Count();
    while (full_list.Count() != 0) 
    {  
        full_list.Remove(0);
        ASSERT_EQ(--count_before, full_list.Count());
    }
}

TEST_F(ListTestFixture, SearchReturnDefaultInitializerWhenDidNotFound)
{
    int search_result = empty_list.Search(100);
    ASSERT_EQ(search_result, int());
}

TEST_F(ListTestFixture, SearchReturnValidIndexWhenValueWasFound)
{
    for (int i = 0; i < 10; i++) 
    {
        int find = full_list.Search(i + 1);
        ASSERT_EQ(find, i);
    }
}
