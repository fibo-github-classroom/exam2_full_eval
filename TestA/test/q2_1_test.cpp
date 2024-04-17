#include "d_node.h"
#include "q2_1.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace {

TEST(DLINKLIST, AppendTest0) {
  LinkedList ll;
  ll.Append('a');
  ll.Append('b');
  // a <-> b
  auto n = ll.GetDNodeAt(0);
  auto n2 = n->right;
  EXPECT_EQ(n->left, nullptr);
  EXPECT_EQ(n->val, 'a');
  EXPECT_NE(n2, nullptr);
  EXPECT_EQ(n2->left, n);
  EXPECT_EQ(n2->right, nullptr);
  EXPECT_EQ(n2->val, 'b');
}

TEST(DLINKLIST, AppendTest1) {
  LinkedList ll;
  // A <-> B <-> ... <-> z
  for (char c = 'A'; c <= 'z'; ++c) {
    ll.Append(c);
  }
  int total_nodes = 'z' - 'A' + 1;
  EXPECT_EQ(ll.Size(), total_nodes);
  const DNode *prev = nullptr;
  for (char c = 'A'; c < 'z'; ++c) {
    int count = c - 'A';
    auto n = ll.GetDNodeAt(count);
    EXPECT_EQ(n->left, prev);
    EXPECT_EQ(n->val, c);
    EXPECT_NE(n->right, nullptr);
    prev = n;
  }
  auto n = ll.GetDNodeAt(total_nodes - 1);
  EXPECT_EQ(n->left, prev);
  EXPECT_EQ(n->val, 'z');
  EXPECT_EQ(n->right, nullptr);
}

TEST(DLINKLIST, InsertTest0) {
  LinkedList ll;
  ll.InsertAt('a', 0);
  ll.InsertAt('b', 0);
  // b <-> a
  auto n = ll.GetDNodeAt(0);
  auto n2 = n->right;
  EXPECT_EQ(n->left, nullptr);
  EXPECT_EQ(n->val, 'b');
  EXPECT_NE(n2, nullptr);
  EXPECT_EQ(n2->left, n);
  EXPECT_EQ(n2->val, 'a');
  EXPECT_EQ(n2->right, nullptr);
}

TEST(DLINKLIST, InsertTest1) {
  LinkedList ll;
  ll.InsertAt('a', 0);
  ll.InsertAt('b', 0);
  ll.InsertAt('c', 1);
  // b <-> c <-> a
  auto n = ll.GetDNodeAt(0);
  auto n2 = n->right;
  EXPECT_EQ(n->left, nullptr);
  EXPECT_EQ(n->val, 'b');
  EXPECT_NE(n2, nullptr);
  EXPECT_EQ(n2->left, n);
  EXPECT_NE(n2->right, nullptr);
  EXPECT_EQ(n2->val, 'c');
  EXPECT_EQ(n2->right->right, nullptr);
  EXPECT_EQ(n2->right->left, n2);
  EXPECT_EQ(n2->right->val, 'a');
}

TEST(DLINKLIST, AppendTest2) {
  LinkedList ll;
  // Y<->Z<->V<->W<->X<->...<->A<->B<->C
  for (char c = 'A'; c <= 'Z'; ++c) {
    int count = c - 'A';
    int pos = count % 3;
    ll.InsertAt(c, pos);
  }
  std::vector<char> expected_out = {'Y', 'Z', 'V', 'W', 'X', 'S', 'T', 'U', 'P',
                                    'Q', 'R', 'M', 'N', 'O', 'J', 'K', 'L', 'G',
                                    'H', 'I', 'D', 'E', 'F', 'A', 'B', 'C'};
  EXPECT_EQ(ll.Size(), 26);
  const DNode *prev = nullptr;
  for (int i = 0; i < 25; ++i) {
    auto n = ll.GetDNodeAt(i);
    EXPECT_EQ(n->left, prev);
    EXPECT_EQ(n->val, expected_out[i]);
    EXPECT_NE(n->right, nullptr);
    prev = n;
  }
  auto n = ll.GetDNodeAt(25);
  EXPECT_EQ(n->left, prev);
  EXPECT_EQ(n->val, expected_out[25]);
  EXPECT_EQ(n->right, nullptr);
}

TEST(DLINKLIST, EraseTest0) {
  LinkedList ll;
  ll.Append('a');
  ll.InsertAt('b', 0);
  ll.InsertAt('c', 1);
  ll.InsertAt('d', 4);
  // b <-> c <-> a <-> d
  ll.EraseAt(1);
  // b <-> a <-> d
  auto n = ll.GetDNodeAt(0);
  auto n2 = n->right;
  EXPECT_EQ(n->left, nullptr);
  EXPECT_EQ(n->val, 'b');
  EXPECT_NE(n2, nullptr);
  EXPECT_EQ(n2->left, n);
  EXPECT_NE(n2->right, nullptr);
  EXPECT_EQ(n2->val, 'a');
  EXPECT_EQ(n2->right->right, nullptr);
  EXPECT_EQ(n2->right->left, n2);
  EXPECT_EQ(n2->right->val, 'd');
}

TEST(DLINKLIST, EraseTest1) {
  LinkedList ll;
  ll.Append('a');
  ll.InsertAt('b', 0);
  ll.InsertAt('c', 1);
  ll.InsertAt('d', 4);
  // b <-> c <-> a <-> d
  ll.EraseAt(0);
  // c <-> a <-> d
  auto n = ll.GetDNodeAt(0);
  auto n2 = n->right;
  EXPECT_EQ(n->left, nullptr);
  EXPECT_EQ(n->val, 'c');
  EXPECT_NE(n2, nullptr);
  EXPECT_EQ(n2->left, n);
  EXPECT_NE(n2->right, nullptr);
  EXPECT_EQ(n2->val, 'a');
  EXPECT_EQ(n2->right->right, nullptr);
  EXPECT_EQ(n2->right->left, n2);
  EXPECT_EQ(n2->right->val, 'd');
}

TEST(DLINKLIST, EraseTest2) {
  LinkedList ll;
  ll.Append('a');
  ll.InsertAt('b', 0);
  ll.InsertAt('c', 1);
  ll.InsertAt('d', 4);
  // b <-> c <-> a <-> d
  ll.EraseAt(3);
  // b <-> c <-> a
  auto n = ll.GetDNodeAt(3);
  EXPECT_EQ(n, nullptr);
  n = ll.GetDNodeAt(2);
  EXPECT_NE(n->left, nullptr);
  EXPECT_EQ(n->val, 'a');
  EXPECT_EQ(n->right, nullptr);
  EXPECT_EQ(n->left->val, 'c');
}

TEST(IsPalindrome, Test0) {
  LinkedList ll;
  ll.Append('a');
  EXPECT_TRUE(ll.IsPalindrome());
  ll.Append('a');
  EXPECT_TRUE(ll.IsPalindrome());
  ll.Append('b');
  EXPECT_FALSE(ll.IsPalindrome());
}

TEST(IsPalindrome, Test1) {
  LinkedList ll;
  for (char c = 'a'; c < 'j'; ++c) {
    ll.Append(c);
  }
  EXPECT_FALSE(ll.IsPalindrome());
  for (char c = 'i'; c >= 'a'; --c) {
    ll.Append(c);
  }
  EXPECT_TRUE(ll.IsPalindrome());
}

TEST(LongestPalindrome, Test0) {
  LinkedList ll;
  ll.Append('a');
  ll.Append('b');
  ll.Append('a');
  EXPECT_EQ(ll.LongestPalindrome(), 3);
}

TEST(LongestPalindrome, Test1) {
  LinkedList ll;
  ll.Append('a');
  ll.Append('b');
  ll.Append('b');
  EXPECT_EQ(ll.LongestPalindrome(), 2);
}

TEST(LongestPalindrome, Test2) {
  LinkedList ll;
  ll.Append('a');
  ll.Append('b');
  ll.Append('c');
  ll.Append('c');
  ll.Append('b');
  ll.Append('c');
  EXPECT_EQ(ll.LongestPalindrome(), 4);
}

TEST(LongestPalindrome, Test3) {
  LinkedList ll;
  for (char c = 'A'; c <= 'Z'; ++c) {
    ll.Append(c);
    ll.InsertAt(c, 0);
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    ll.Append(c);
    ll.InsertAt(c, 0);
  }
  for (char c = 'z'; c <= 'a'; -c) {
    ll.Append(c);
    ll.InsertAt(c, 0);
  }
  // a-b-...-z-0-z...-a-Z-...-A-A-...Z-a-..-z-z-..-a
  ll.InsertAt('0', 26);
  EXPECT_EQ(ll.LongestPalindrome(), 104);
}
} // namespace
