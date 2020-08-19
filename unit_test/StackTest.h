#pragma once
#include "pch.h"
#include "../template/Stack.h"


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

TEST_F(stackTestFixture, TopReturnLastPushedValueAndPopRemoveLastPushedValue)
{
    int thisValueWillBePopped = 10;
    while (thisValueWillBePopped != 1)
    {
        ASSERT_EQ(my_stack.Top(), thisValueWillBePopped--);
        my_stack.Pop();
    }
}

TEST_F(stackTestFixture, IsEmptyReturnFalseWhereStackCountIsGreaterThanZero)
{
    int stack_count = 10;
    while (stack_count > 0)
    {
        ASSERT_NE(my_stack.IsEmpty(), true);
        my_stack.Pop();
        --stack_count;
    }
}

TEST_F(stackTestFixture, IsEmptyReturnTrueWhereStackCountIsEqualToZero)
{
    ASSERT_EQ(empty_stack.IsEmpty(), true);
    empty_stack.Push(0);
    empty_stack.Pop();
    ASSERT_EQ(empty_stack.IsEmpty(), true);
    empty_stack.Push(0);
    ASSERT_EQ(empty_stack.IsEmpty(), false);
}

TEST_F(stackTestFixture, TopReturnLastPushedValue)
{
    for (uint32_t i = 0; i < 10; ++i)
    {
        empty_stack.Push(i);
        ASSERT_EQ(empty_stack.Top(), i);
    }
}