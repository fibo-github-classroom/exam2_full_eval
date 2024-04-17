#include "node.h"
#include "q2_1.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <cstdlib>

namespace {

TEST(SwapNext, Test0) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  ll.SwapNext(0);
  auto n = ll.GetNodeAt(0);
  EXPECT_EQ(n->val, 1);
  auto n2 = n->next;
  EXPECT_EQ(n2->val, 0);
}

TEST(SwapNext, Test1) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  ll.SwapNext(1);
  auto n = ll.GetNodeAt(1);
  EXPECT_EQ(n->val, 2);
  auto n2 = n->next;
  EXPECT_EQ(n2->val, 1);
}

TEST(SwapNext, Test2) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  ll.SwapNext(7);
  // Do nothing since there are only 9 node.
  EXPECT_NO_THROW(ll.SwapNext(8));
  auto n = ll.GetNodeAt(7);
  auto n2 = ll.GetNodeAt(8);
  EXPECT_EQ(n->val, 8);
  EXPECT_EQ(n->next, n2);
  EXPECT_EQ(n2->val, 7);
  EXPECT_EQ(n2->next, nullptr);
}

TEST(SwapNext, Test3) {
  LinkedList ll;
  for (int i = 0; i <= 1000; ++i) {
    ll.Append(i);
  }
  ll.SwapNext(999);
  auto n = ll.GetNodeAt(999);
  EXPECT_EQ(n->val, 1000);
  auto n2 = n->next;
  EXPECT_EQ(n2->val, 999);
  EXPECT_EQ(n2->next, nullptr);
}

TEST(SwapNext, Test4) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  auto n = ll.GetNodeAt(1);
  auto n2 = ll.GetNodeAt(2);
  // n -> n2
  ll.SwapNext(1);
  // n2 -> n
  EXPECT_EQ(n->val, 1);
  EXPECT_EQ(n2->val, 2);
  EXPECT_EQ(n2->next, n);
}

TEST(SwapNext, Test5) {
  LinkedList ll;
  for (int i = 0; i < 10; ++i) {
    ll.Append(i);
  }
  auto n = ll.GetNodeAt(0);
  auto n2 = ll.GetNodeAt(1);
  // n -> n2
  ll.SwapNext(0);
  // n2 -> n
  EXPECT_EQ(n->val, 0);
  EXPECT_EQ(n2->val, 1);
  EXPECT_EQ(n2->next, n);
  // head_ == n2
  EXPECT_EQ(ll.GetNodeAt(0), n2);
}

TEST(Sort, Test0) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.InsertAt(i, 0);
  }
  ll.Sort();
  auto n = ll.GetNodeAt(0);
  for (int i = 0; i < 9; ++i) {
    EXPECT_EQ(n->val, i);
    n = n->next;
  }
  EXPECT_EQ(n, nullptr);
}
TEST(Sort, Test1) {
  LinkedList ll;
  ll.Append(3);
  ll.Append(1);
  ll.Append(11);
  ll.Append(2);
  ll.Append(9);
  ll.Append(-3);
  ll.Sort();
  auto n = ll.GetNodeAt(0);
  EXPECT_EQ(n->val, -3);
  n = n->next;
  EXPECT_EQ(n->val, 1);
  n = n->next;
  EXPECT_EQ(n->val, 2);
  n = n->next;
  EXPECT_EQ(n->val, 3);
  n = n->next;
  EXPECT_EQ(n->val, 9);
  n = n->next;
  EXPECT_EQ(n->val, 11);
  n = n->next;
  EXPECT_EQ(n, nullptr);
}

TEST(Sort, Test2) {
  std::vector<int> test_set = {19,   23,  -1, -32, 10, 123123,
                               -123, -33, -2, -1,  330};
  LinkedList ll;
  for (auto i : test_set) {
    ll.Append(i);
  }
  ll.Sort();
  std::sort(test_set.begin(), test_set.end());
  auto n = ll.GetNodeAt(0);
  for (auto i : test_set) {
    EXPECT_EQ(n->val, i);
    n = n->next;
  }
}

TEST(Sort, Test3) {
  srand(123);
  std::vector<int> test_set;
  LinkedList ll;
  for (int i = 0; i < 5000; ++i) {
    int val = rand();
    val = (val % 98765);
    if (val % 2 == 1) {
      val *= -1;
    }
    test_set.push_back(val);
    ll.Append(val);
  }
  ll.Sort();
  std::sort(test_set.begin(), test_set.end());

  auto n = ll.GetNodeAt(0);
  for (auto i : test_set) {
    EXPECT_EQ(n->val, i);
    n = n->next;
  }
}

TEST(SwapAny, Test0) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  ll.SwapAny(0, 2);
  auto n = ll.GetNodeAt(0);
  auto n2 = ll.GetNodeAt(2);
  EXPECT_EQ(n->val, 2);
  EXPECT_EQ(n2->val, 0);
  EXPECT_EQ(n->next->next, n2);
  EXPECT_EQ(n2->next->val, 3);
}

TEST(SwapAny, Test1) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  ll.SwapAny(0, 2);
  ll.SwapAny(2, 7);
  auto n = ll.GetNodeAt(0);
  auto n2 = ll.GetNodeAt(2);
  auto n3 = ll.GetNodeAt(7);
  EXPECT_EQ(n->val, 2);
  EXPECT_EQ(n2->val, 7);
  EXPECT_EQ(n3->val, 0);
  EXPECT_EQ(n->next->next, n2);
  EXPECT_EQ(n2->next->val, 3);
  EXPECT_EQ(n3->next->next, nullptr);
}

TEST(SwapAny, Test2) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  auto n = ll.GetNodeAt(5);
  auto n2 = ll.GetNodeAt(8);
  ll.SwapAny(8, 5);
  EXPECT_EQ(n2->val, 8);
  EXPECT_EQ(n->val, 5);
  EXPECT_EQ(n->next, nullptr);
  EXPECT_EQ(ll.GetNodeAt(8), n);
  EXPECT_EQ(ll.GetNodeAt(5), n2);
}

TEST(SwapAny, Test3) {
  LinkedList ll;
  for (int i = 0; i < 9; ++i) {
    ll.Append(i);
  }
  auto n = ll.GetNodeAt(0);
  auto n2 = ll.GetNodeAt(2);
  ll.SwapAny(0, 2);
  EXPECT_EQ(n2->val, 2);
  EXPECT_EQ(n->val, 0);
  EXPECT_EQ(ll.GetNodeAt(0), n2);
  EXPECT_EQ(ll.GetNodeAt(2), n);
}

} // namespace
