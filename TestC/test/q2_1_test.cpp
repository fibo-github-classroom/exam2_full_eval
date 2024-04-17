#include "q2_1.h"
#include "singly_linked_list.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace {

TEST(PriorityQueue, InsertTest0){
  PriorityQueue q;
  q.Insert('a', 1);
  EXPECT_EQ(q.Size(), 1);
  q.Insert('c', 2);
  EXPECT_EQ(q.Size(), 2);
}

TEST(PriorityQueue, InsertTest1){
  PriorityQueue q;
  for(char c = 'a'; c < 'k'; ++c) {
    int p = (c-'f');
    q.Insert(c, p*p);
    auto n = q.GetNodeAt(0);
    EXPECT_NE(n, nullptr);
    EXPECT_EQ(n->priority, 25);
    EXPECT_EQ(n->val, 'a');
  }
  EXPECT_EQ(q.Size(), 10);
}

TEST(PriorityQueue, InsertTest2){
  PriorityQueue q;
  for(char c = 'a'; c < 'k'; ++c) {
    q.Insert(c, c-'a');
    auto n = q.GetNodeAt(0);
    EXPECT_NE(n, nullptr);
    EXPECT_EQ(n->priority, c-'a');
    EXPECT_EQ(n->val, c);
  }
  EXPECT_EQ(q.Size(), 10);
}


TEST(PriorityQueue, InsertTest3){
  PriorityQueue q;
  for(char c = 'a'; c < 'k'; ++c) {
    int p = (c-'c');
    q.Insert(c, p*p);
    auto n = q.GetNodeAt(0);
    EXPECT_NE(n, nullptr);
    if(p*p > 4) {
      EXPECT_EQ(n->priority, p*p);
      EXPECT_EQ(n->val, c);
    } else if (p*p < 4) {
      EXPECT_EQ(n->priority, 4);
      EXPECT_EQ(n->val, 'a');
    }
  }
  EXPECT_EQ(q.Size(), 10);
}


TEST(PriorityQueue, PeekTest0){
  PriorityQueue q;
  q.Insert('a', 1);
  auto res = q.Peek();
  EXPECT_EQ(res.val, 'a');
  EXPECT_EQ(res.priority, 1);
  q.Insert('c', 2);
  EXPECT_EQ(q.Size(), 2);
  res = q.Peek();
  EXPECT_EQ(res.val, 'c');
  EXPECT_EQ(res.priority, 2);
}

TEST(PriorityQueue, PeekTest1){
  PriorityQueue q;
  Node res;
  for(char c = 'a'; c < 'k'; ++c) {
    int p = (c-'f');
    q.Insert(c, p*p);
    res = q.Peek();
    EXPECT_EQ(res.val, 'a');
    EXPECT_EQ(res.priority, 25);
  }
  EXPECT_EQ(q.Size(), 10);
}

TEST(PriorityQueue, EraseTest0){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  EXPECT_EQ(q.Size(), 4);
  auto res = q.Peek();
  EXPECT_EQ(res.val, 'z');
  EXPECT_EQ(res.priority, 12);
  auto res2 = q.Pop();
  EXPECT_EQ(q.Size(), 3);
  EXPECT_EQ(res.val, res2.val);
  EXPECT_EQ(res.priority, res2.priority);
  res = q.Peek();
  EXPECT_EQ(res.val, 'l');
}

TEST(PriorityQueue, EraseTest1){
  PriorityQueue q;
  for(char c = 'a'; c < 'k'; ++c) {
    int p = (c-'f');
    q.Insert(c, p*p);
  }
  EXPECT_EQ(q.Size(), 10);
  auto res = q.Peek();
  EXPECT_EQ(q.Size(), 10);
  EXPECT_EQ(res.val, 'a');
  EXPECT_EQ(res.priority, 25);
  auto res2 = q.Pop();
  EXPECT_EQ(q.Size(), 9);
  EXPECT_EQ(res.val, res2.val);
  EXPECT_EQ(res.priority, res2.priority);
  // Next two nodes have priority = 16
  res = q.Pop();
  res2 = q.Pop();
  EXPECT_EQ(q.Size(), 7);
  EXPECT_EQ(res.priority, 16);
  EXPECT_EQ(res.priority, res2.priority);
}

TEST(PriorityQueueAdjust, Test0){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  EXPECT_EQ(q.Size(), 4);
  auto res = q.Peek();
  EXPECT_EQ(res.val, 'z');
  EXPECT_EQ(res.priority, 12);
  q.AdjustPriority(0, 150);
  EXPECT_EQ(q.Size(), 4);
  res = q.Peek();
  EXPECT_EQ(res.priority, 150);
  EXPECT_EQ(res.val, 'z');
}

TEST(PriorityQueueAdjust, Test1){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  q.AdjustPriority(2, 30);
  EXPECT_EQ(q.Size(), 4);
  auto res = q.Peek();
  EXPECT_EQ(res.priority, 30);
  EXPECT_EQ(res.val, 'c');
}

TEST(PriorityQueueAdjust, Test2){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  q.AdjustPriority(0, 3);
  EXPECT_EQ(q.Size(), 4);
  auto res = q.Peek();
  EXPECT_EQ(res.priority, 5);
  EXPECT_EQ(res.val, 'l');
}

TEST(PriorityQueueAdjust, Test3){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  q.AdjustPriority(1, 0);
  EXPECT_EQ(q.Size(), 4);
  auto res = q.Pop();
  EXPECT_EQ(res.priority, 12);
  EXPECT_EQ(res.val, 'z');
  res = q.Pop();
  EXPECT_EQ(res.priority, 2);
  EXPECT_EQ(res.val, 'c');
  res = q.Pop();
  EXPECT_EQ(res.priority, 1);
  EXPECT_EQ(res.val, 'a');
  res = q.Pop();
  EXPECT_EQ(res.priority, 0);
  EXPECT_EQ(res.val, 'l');
}

TEST(PriorityQueueAdjust, Test4){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  auto n = q.GetNodeAt(0);
  q.AdjustPriority(0, 0);
  auto n2 = q.GetNodeAt(3);
  EXPECT_EQ(n->val, 'z');
  EXPECT_EQ(n->priority, 0);
  EXPECT_EQ(n, n2);
}

TEST(PriorityQueueAdjust, Test5){
  PriorityQueue q;
  q.Insert('a', 1);
  q.Insert('c', 2);
  q.Insert('z', 12);
  q.Insert('l', 5);
  auto n = q.GetNodeAt(2);
  q.AdjustPriority(2, 30);
  auto n2 = q.GetNodeAt(0);
  EXPECT_EQ(n->val, 'c');
  EXPECT_EQ(n->priority, 30);
  EXPECT_EQ(n, n2);
}
} // namespace
