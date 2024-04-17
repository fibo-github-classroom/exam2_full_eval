#include "q1.h"
#include "q1_objects.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <cmath>
#include <cstdlib>

namespace {
using testing::DoubleNear;

TEST(Q1_1, Test0) { EXPECT_EQ(factorial(0), 1); }

TEST(Q1_1, Test1) { EXPECT_EQ(factorial(1), 1); }

TEST(Q1_1, Test2) { EXPECT_EQ(factorial(2), 2); }
TEST(Q1_1, Test3) { EXPECT_EQ(factorial(3), 6); }

TEST(Q1_1, Test4) { EXPECT_EQ(factorial(5), 120); }

TEST(Q1_1, Test5) { EXPECT_EQ(factorial(10), 3628800); }

TEST(Q1_2, TEST0) {
  PersonInfo info{1.7, 70};
  EXPECT_THAT(GetBMI(info), DoubleNear(24.2215, 1e-3));
}

TEST(Q1_2, TEST1) {
  PersonInfo info{1.99, 59};
  EXPECT_THAT(GetBMI(info), DoubleNear(14.8986, 1e-3));
}

TEST(Q1_2, TEST2) {
  PersonInfo info{1., 20};
  EXPECT_THAT(GetBMI(info), DoubleNear(20, 1e-3));
}

TEST(Q1_2, TEST3) {
  PersonInfo info{2.2, 59};
  EXPECT_THAT(GetBMI(info), DoubleNear(12.19, 1e-3));
}

TEST(Q1_3, TEST0) {
  std::vector<PersonInfo> infos = {{1.7, 70}};
  EXPECT_THAT(GetAverageBMI(infos), DoubleNear(24.2215, 1e-3));
}

TEST(Q1_3, TEST1) {
  std::vector<PersonInfo> infos = {
      {1.7, 70}, {1.99, 59}, {1.8, 120}, {1.5, 40}};
  EXPECT_THAT(GetAverageBMI(infos), DoubleNear(23.4837, 1e-3));
}

TEST(Q1_3, TEST2) {
  std::vector<PersonInfo> infos = {{1.8, 70}, {1.75, 65}, {1.7, 50}, {1.45, 36},
                                   {1.9, 60}, {1.7, 50},  {1.5, 30}, {1.6, 40}};
  EXPECT_THAT(GetAverageBMI(infos), DoubleNear(17.5166, 1e-3));
}

TEST(Q1_3, TEST3) {
  std::vector<PersonInfo> infos = {
      {1.5, 50}, {1.6, 60}, {1.7, 70}, {1.8, 80}, {1.9, 90}};
  EXPECT_THAT(GetAverageBMI(infos), DoubleNear(23.9007, 1e-3));
}

TEST(Q1_3, TEST4) {
  std::vector<PersonInfo> infos = {{1.8, 70}, {1.75, 65}, {1.7, 50}, {1.9, 60},
                                   {1.7, 50}, {1.5, 30},  {1.6, 40}};
  EXPECT_THAT(GetAverageBMI(infos), DoubleNear(17.5729, 1e-3));
}

TEST(Q1_3, TEST5) {
  std::vector<PersonInfo> infos = {};
  EXPECT_EQ(GetAverageBMI(infos), 0.);
}

TEST(Q1_4, TEST0) {
  Node s0{10, nullptr};
  EXPECT_FALSE(HasAnyLoop(&s0));
}

TEST(Q1_4, TEST1) {
  Node s0{10, nullptr};
  s0.next = &s0;
  EXPECT_TRUE(HasAnyLoop(&s0));
}

TEST(Q1_4, TEST2) {
  Node s0{10, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 10; ++i) {
    Node *n = new Node{10 - i, cur};
    cur = n;
  }
  EXPECT_FALSE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST3) {
  Node s0{10, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 10; ++i) {
    Node *n = new Node{10 - i, cur};
    cur = n;
  }
  s0.next = cur;
  EXPECT_TRUE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST4) {
  Node s0{10, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 10; ++i) {
    Node *n = new Node{10 - i, cur};
    cur = n;
    if (i == 1) {
      s0.next = cur;
    }
  }
  EXPECT_TRUE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST5) {
  Node s0{10, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 10; ++i) {
    Node *n = new Node{10 - i, cur};
    cur = n;
    if (i == 6) {
      s0.next = cur;
    }
  }
  EXPECT_TRUE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST6) {
  Node s0{0, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 1000; ++i) {
    Node *n = new Node{i, cur};
    cur = n;
    if (i == 777) {
      s0.next = cur;
    }
  }
  EXPECT_TRUE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST7) {
  Node s0{0, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 1000; ++i) {
    Node *n = new Node{i, cur};
    cur = n;
    if (i == 123) {
      s0.next = cur;
    }
  }
  EXPECT_TRUE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST8) {
  Node s0{0, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 1000; ++i) {
    Node *n = new Node{i, cur};
    cur = n;
    if (i == 890) {
      cur->next = cur;
    }
  }
  EXPECT_TRUE(HasAnyLoop(cur));
}

TEST(Q1_4, TEST9) {
  Node s0{0, nullptr};
  Node *cur = &s0;
  for (int i = 1; i < 1000; ++i) {
    Node *n = new Node{i, cur};
    cur = n;
    if (i == 0) {
      s0.next = cur;
    }
  }
  EXPECT_FALSE(HasAnyLoop(cur));
}

TEST(Q1_5, Test0) {
  Node s0{5, nullptr};
  Node s1{7, nullptr};
  auto out = SortedIntersect(&s0, &s1);
  EXPECT_EQ(out, nullptr);
}

TEST(Q1_5, Test1) {
  Node s0{5, nullptr};
  Node s1{7, nullptr};
  Node *cur0 = &s0;
  Node *cur1 = &s1;
  for (int i = 1; i < 4; ++i) {
    Node *n0 = new Node{5 - i, cur0};
    cur0 = n0;
    Node *n1 = new Node{7 - 2 * i, cur1};
    cur1 = n1;
  }
  auto out = SortedIntersect(cur0, cur1);
  // Expect 3->5
  for (int i = 0; i < 2; ++i) {
    ASSERT_NE(out, nullptr);
    EXPECT_EQ(out->val, 3 + 2 * i);
    out = out->next;
  }
  EXPECT_EQ(out, nullptr);
}

TEST(Q1_5, Test2) {
  Node s0{10, nullptr};
  Node s1{20, nullptr};
  Node *cur0 = &s0;
  Node *cur1 = &s1;
  for (int i = 1; i < 10; ++i) {
    Node *n0 = new Node{10 - i, cur0};
    cur0 = n0;
    Node *n1 = new Node{20 - 2 * i, cur1};
    cur1 = n1;
  }

  auto out = SortedIntersect(cur0, cur1);
  // Expect 2->4->6->8->10
  for (int i = 1; i < 6; ++i) {
    ASSERT_NE(out, nullptr);
    EXPECT_EQ(out->val, 2 * i);
    out = out->next;
  }
  EXPECT_EQ(out, nullptr);
}

TEST(Q1_5, Test3) {
  Node s0{21, nullptr};
  Node s1{20, nullptr};
  Node *cur0 = &s0;
  Node *cur1 = &s1;
  for (int i = 1; i < 10; ++i) {
    Node *n0 = new Node{21 - 2 * i, cur0};
    cur0 = n0;
    Node *n1 = new Node{20 - 2 * i, cur1};
    cur1 = n1;
  }

  auto out = SortedIntersect(cur0, cur1);
  // Expect nullptr
  EXPECT_EQ(out, nullptr);
}

TEST(Q1_5, Test4) {
  auto out = SortedIntersect(nullptr, nullptr);
  EXPECT_EQ(out, nullptr);
}

TEST(Q1_5, Test5) {
  Node s0{10, nullptr};
  Node *cur0 = &s0;
  for (int i = 1; i < 10; ++i) {
    Node *n0 = new Node{10 - i, cur0};
    cur0 = n0;
  }
  auto out = SortedIntersect(cur0, cur0);
  // Expect 1->2->...->9->10
  for (int i = 1; i < 11; ++i) {
    ASSERT_NE(out, nullptr);
    EXPECT_EQ(out->val, i);
    out = out->next;
  }
  EXPECT_EQ(out, nullptr);
}
} // namespace
