#include "card.h"
#include "q2_2.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace {
TEST(PlayingCard, Test0) {
  PlayingCard c(1, 1);
  EXPECT_EQ(c.get_val(), 0);
}

TEST(PlayingCard, Test1) {
  PlayingCard c(3, 11);
  EXPECT_EQ(c.get_val(), 42);
}

TEST(PlayingCard, Test2) {
  PlayingCard c(3, 11);
  EXPECT_TRUE(c.IsValid());
}

TEST(PlayingCard, Test3) {
  PlayingCard c(55);
  EXPECT_FALSE(c.IsValid());
}

TEST(PlayingCard, Test4) {
  PlayingCard c(1, 1);
  EXPECT_EQ(c.GetSuit(), 1);
  EXPECT_EQ(c.GetNumber(), 1);
}

TEST(PlayingCard, Test5) {
  PlayingCard c(3, 11);
  EXPECT_EQ(c.GetSuit(), 3);
  EXPECT_EQ(c.GetNumber(), 11);
}

TEST(PlayingCard, Test6) {
  PlayingCard c(51);
  EXPECT_EQ(c.GetSuit(), 4);
  EXPECT_EQ(c.GetNumber(), 13);
}

TEST(PlayingCard, Test7) {
  PlayingCard c(5, 1);
  EXPECT_FALSE(c.IsValid());
  PlayingCard c2(51);
  EXPECT_TRUE(c2.IsValid());
}

TEST(IsValidHand, Test0) {
  FiveCardsHand h{.cards = {PlayingCard{1}, PlayingCard{2}, PlayingCard{3},
                            PlayingCard{4}, PlayingCard{5}}};
  EXPECT_TRUE(IsValid(h));
}

TEST(IsValidHand, Test1) {
  FiveCardsHand h{.cards = {PlayingCard{1}, PlayingCard{2}, PlayingCard{3},
                            PlayingCard{4}, PlayingCard{1}}};
  EXPECT_FALSE(IsValid(h));
}

TEST(IsValidHand, Test2) {
  FiveCardsHand h{.cards = {PlayingCard{1}, PlayingCard{2}, PlayingCard{3},
                            PlayingCard{4}, PlayingCard{56}}};
  EXPECT_FALSE(IsValid(h));
  FiveCardsHand h2{.cards = {PlayingCard{1}, PlayingCard{2}, PlayingCard{3},
                             PlayingCard{4}, PlayingCard{1, 6}}};
  EXPECT_TRUE(IsValid(h2));
}

TEST(IsValidHand, Test3) {
  FiveCardsHand h{.cards = {PlayingCard{1, 3}, PlayingCard{2, 3},
                            PlayingCard{3, 3}, PlayingCard{4, 3},
                            PlayingCard{2, 1}}};
  EXPECT_TRUE(IsValid(h));
}

TEST(IsBetterThan, Test0) {
  // Straight.
  FiveCardsHand h_a{.cards = {PlayingCard{1,3},PlayingCard{2,4},PlayingCard{3,5},PlayingCard{1,6},PlayingCard{2,7}}};

  // Flush.
  FiveCardsHand h_b{.cards = {PlayingCard{4,1},PlayingCard{4,4},PlayingCard{4,13},PlayingCard{4,9},PlayingCard{4,11}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test1) {
  // High Ace.
  FiveCardsHand h_a{.cards = {PlayingCard{2, 1}, PlayingCard{2, 3},
                              PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}}};

  // A flush.
  FiveCardsHand h_b{.cards = {PlayingCard{3, 4}, PlayingCard{3, 2},
                              PlayingCard{3, 3}, PlayingCard{3, 1},
                              PlayingCard{3, 11}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test2) {
  // High Ace.
  FiveCardsHand h_b{.cards = {PlayingCard{2, 1}, PlayingCard{2, 3},
                              PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}}};

  // High K.
  FiveCardsHand h_a{.cards = {PlayingCard{3, 13}, PlayingCard{4, 4},
                              PlayingCard{1, 3}, PlayingCard{3, 12},
                              PlayingCard{4, 11}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test3) {
  // A flush.
  FiveCardsHand h_a{.cards = {PlayingCard{1, 2}, PlayingCard{1, 7},
                              PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}}};

  // A straight flush.
  FiveCardsHand h_b{.cards = {PlayingCard{4, 2}, PlayingCard{4, 3},
                              PlayingCard{4, 4}, PlayingCard{4, 6},
                              PlayingCard{4, 5}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test4) {
  // Staight up to 9
  FiveCardsHand h_a{.cards = {PlayingCard{1, 9}, PlayingCard{2, 8},
                              PlayingCard{1, 7}, PlayingCard{1, 6},
                              PlayingCard{1, 5}}};

  // Staight up to 10
  FiveCardsHand h_b{.cards = {PlayingCard{3, 9}, PlayingCard{4, 8},
                              PlayingCard{4, 7}, PlayingCard{3, 6},
                              PlayingCard{4, 10}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test5) {
  // Straight Flush
  FiveCardsHand h_a{.cards = {PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}, PlayingCard{1, 12},
                              PlayingCard{1, 13}}};

  // Royal Straight Flush
  FiveCardsHand h_b{.cards = {PlayingCard{2, 1}, PlayingCard{2, 10},
                              PlayingCard{2, 11}, PlayingCard{2, 12},
                              PlayingCard{2, 13}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test6) {
  // Straight A-2-3-4-5 (lowest straight)
  FiveCardsHand h_b{.cards = {PlayingCard{2, 5}, PlayingCard{3, 1},
                              PlayingCard{4, 2}, PlayingCard{4, 3},
                              PlayingCard{4, 4}}};

  // Straight 2-3-4-5-6
  FiveCardsHand h_a{.cards = {PlayingCard{1, 2}, PlayingCard{3, 3},
                              PlayingCard{3, 4}, PlayingCard{3, 5},
                              PlayingCard{3, 6}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test7) {
  // Invalid (duplicated cards)
  FiveCardsHand h_a{.cards = {PlayingCard{1, 1}, PlayingCard{1, 2},
                              PlayingCard{1, 3}, PlayingCard{1, 4},
                              PlayingCard{1, 1}}};

  // High K
  FiveCardsHand h_b{.cards = {PlayingCard{3, 4}, PlayingCard{4, 2},
                              PlayingCard{1, 3}, PlayingCard{1, 8},
                              PlayingCard{2, 13}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsValid2, Test0) {
  TwoCardsHand h{.cards = {PlayingCard{50}, PlayingCard{51}}};
  FiveCardsHand h_center{.cards = {PlayingCard{1}, PlayingCard{2},
                                   PlayingCard{3}, PlayingCard{4},
                                   PlayingCard{5}}};
  EXPECT_TRUE(IsValid(h, h_center));
}

TEST(IsValid2, Test1) {
  TwoCardsHand h{.cards = {PlayingCard{5}, PlayingCard{51}}};
  TwoCardsHand h2{.cards = {PlayingCard{10}, PlayingCard{51}}};
  FiveCardsHand h_center{.cards = {PlayingCard{1}, PlayingCard{2},
                                   PlayingCard{3}, PlayingCard{4},
                                   PlayingCard{5}}};
  EXPECT_FALSE(IsValid(h, h_center));
  EXPECT_TRUE(IsValid(h, h_center));
}

TEST(IsBetterThan2, Test0) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 2}, PlayingCard{2, 3},
                                   PlayingCard{1, 5}, PlayingCard{1, 6},
                                   PlayingCard{1, 8}}};
  // Straight
  TwoCardsHand h_a{.cards = {PlayingCard{2, 4}, PlayingCard{2, 13}}};

  // Flush
  TwoCardsHand h_b{.cards = {PlayingCard{1, 1}, PlayingCard{4, 10}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test1) {
  FiveCardsHand h_center{.cards = {PlayingCard{2, 2}, PlayingCard{1, 3},
                                   PlayingCard{1, 5}, PlayingCard{1, 6},
                                   PlayingCard{1, 8}}};
  // Flush (Ace)
  TwoCardsHand h_a{.cards = {PlayingCard{1, 1}, PlayingCard{2, 7}}};

  // Straight Flush
  TwoCardsHand h_b{.cards = {PlayingCard{1, 4}, PlayingCard{1, 7}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test2) {
  FiveCardsHand h_center{.cards = {PlayingCard{2, 1}, PlayingCard{1, 10},
                                   PlayingCard{1, 11}, PlayingCard{1, 12},
                                   PlayingCard{1, 13}}};
  // Straight Flush
  TwoCardsHand h_a{.cards = {PlayingCard{1, 9}, PlayingCard{3, 2}}};

  // Royal Straight Flush
  TwoCardsHand h_b{.cards = {PlayingCard{1, 1}, PlayingCard{3, 1}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test3) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 12}, PlayingCard{2, 11},
                                   PlayingCard{3, 10}, PlayingCard{4, 8},
                                   PlayingCard{1, 7}}};
  // Straight to K
  TwoCardsHand h_a{.cards = {PlayingCard{1, 9}, PlayingCard{1, 13}}};

  // Straight to K
  TwoCardsHand h_b{.cards = {PlayingCard{2, 9}, PlayingCard{2, 13}}};

  // Straight to Ace
  TwoCardsHand h_c{.cards = {PlayingCard{3, 13}, PlayingCard{3, 1}}};

  // neither a/b is better (tie)
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  // c > a/b
  EXPECT_TRUE(IsBetterThan(h_c, h_b, h_center));
}

TEST(IsBetterThan2, Test4) {
  FiveCardsHand h_center{.cards = {PlayingCard{3, 2}, PlayingCard{1, 1},
                                   PlayingCard{3, 4}, PlayingCard{1, 13},
                                   PlayingCard{3, 5}}};
  // Flush (high Q)
  TwoCardsHand h_a{.cards = {PlayingCard{3, 12}, PlayingCard{3, 6}}};

  // Flush (high K)
  TwoCardsHand h_b{.cards = {PlayingCard{3, 13}, PlayingCard{3, 3}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test5) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 1}, PlayingCard{2, 2},
                                   PlayingCard{1, 7}, PlayingCard{2, 4},
                                   PlayingCard{1, 5}}};
  // High A->K->J.
  TwoCardsHand h_a{.cards = {PlayingCard{2, 13}, PlayingCard{2, 11}}};

  // High A->K->Q
  TwoCardsHand h_b{.cards = {PlayingCard{1, 13}, PlayingCard{2, 12}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

} // namespace
