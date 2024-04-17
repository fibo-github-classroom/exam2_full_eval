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
  EXPECT_EQ(c.get_val(), 36);
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
  PlayingCard c(1, 15);
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
  // A pair.
  FiveCardsHand h_a{.cards = {PlayingCard{1, 3}, PlayingCard{2, 3},
                              PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}}};

  // Two pair.
  FiveCardsHand h_b{.cards = {PlayingCard{3, 4}, PlayingCard{4, 4},
                              PlayingCard{1, 1}, PlayingCard{2, 1},
                              PlayingCard{4, 11}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test1) {
  // High Ace.
  FiveCardsHand h_a{.cards = {PlayingCard{2, 1}, PlayingCard{2, 3},
                              PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}}};

  // A pair.
  FiveCardsHand h_b{.cards = {PlayingCard{3, 4}, PlayingCard{4, 4},
                              PlayingCard{1, 3}, PlayingCard{1, 1},
                              PlayingCard{4, 11}}};

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
  // A pair of two.
  FiveCardsHand h_a{.cards = {PlayingCard{2, 2}, PlayingCard{3, 2},
                              PlayingCard{1, 9}, PlayingCard{1, 10},
                              PlayingCard{1, 11}}};

  // A pair of three.
  FiveCardsHand h_b{.cards = {PlayingCard{3, 3}, PlayingCard{4, 3},
                              PlayingCard{1, 4}, PlayingCard{1, 8},
                              PlayingCard{4, 7}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test4) {
  // A pair of Aces with high 8
  FiveCardsHand h_a{.cards = {PlayingCard{1, 1}, PlayingCard{2, 1},
                              PlayingCard{1, 8}, PlayingCard{1, 6},
                              PlayingCard{1, 4}}};

  // A pair of Aces with high 9
  FiveCardsHand h_b{.cards = {PlayingCard{3, 1}, PlayingCard{4, 1},
                              PlayingCard{2, 9}, PlayingCard{2, 2},
                              PlayingCard{2, 3}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test5) {
  // Triple K.
  FiveCardsHand h_a{.cards = {PlayingCard{2, 13}, PlayingCard{1, 13},
                              PlayingCard{3, 13}, PlayingCard{4, 12},
                              PlayingCard{4, 11}}};

  // Full House 2/3.
  FiveCardsHand h_b{.cards = {PlayingCard{1, 3}, PlayingCard{2, 3},
                              PlayingCard{3, 3}, PlayingCard{4, 4},
                              PlayingCard{3, 4}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test6) {
  // Full House A/K.
  FiveCardsHand h_a{.cards = {PlayingCard{2, 1}, PlayingCard{3, 1},
                              PlayingCard{4, 1}, PlayingCard{4, 13},
                              PlayingCard{1, 13}}};

  // Four of 2.
  FiveCardsHand h_b{.cards = {PlayingCard{1, 2}, PlayingCard{2, 2},
                              PlayingCard{3, 2}, PlayingCard{4, 2},
                              PlayingCard{4, 3}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test7) {
  // Invalid (duplicated Ace)
  FiveCardsHand h_a{.cards = {PlayingCard{1, 1}, PlayingCard{2, 1},
                              PlayingCard{3, 1}, PlayingCard{4, 1},
                              PlayingCard{4, 1}}};

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
  FiveCardsHand h_center{.cards = {PlayingCard{1, 3}, PlayingCard{2, 3},
                                   PlayingCard{1, 9}, PlayingCard{1, 10},
                                   PlayingCard{1, 11}}};
  // One pair.
  TwoCardsHand h_a{.cards = {PlayingCard{2, 1}, PlayingCard{2, 13}}};

  // Two pair.
  TwoCardsHand h_b{.cards = {PlayingCard{3, 4}, PlayingCard{4, 4}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test1) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 1}, PlayingCard{2, 2},
                                   PlayingCard{1, 3}, PlayingCard{1, 4},
                                   PlayingCard{1, 5}}};
  // Two pair.
  TwoCardsHand h_a{.cards = {PlayingCard{2, 1}, PlayingCard{3, 2}}};

  // Triple.
  TwoCardsHand h_b{.cards = {PlayingCard{3, 1}, PlayingCard{4, 3}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test2) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 1}, PlayingCard{2, 1},
                                   PlayingCard{1, 13}, PlayingCard{2, 13},
                                   PlayingCard{3, 13}}};
  // Full House K/A
  TwoCardsHand h_a{.cards = {PlayingCard{1, 2}, PlayingCard{3, 2}}};

  // Full House A/K
  TwoCardsHand h_b{.cards = {PlayingCard{3, 1}, PlayingCard{4, 3}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test3) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 1}, PlayingCard{2, 1},
                                   PlayingCard{3, 1}, PlayingCard{4, 1},
                                   PlayingCard{1, 5}}};
  // 4 of a kind + 5.
  TwoCardsHand h_a{.cards = {PlayingCard{2, 2}, PlayingCard{3, 5}}};

  // 4 of a kind + 5.
  TwoCardsHand h_b{.cards = {PlayingCard{3, 2}, PlayingCard{2, 4}}};

  // 4 of a kind + 6.
  TwoCardsHand h_c{.cards = {PlayingCard{3, 6}, PlayingCard{2, 4}}};
  // neither is better (tie)
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_c, h_b, h_center));
}

TEST(IsBetterThan2, Test4) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 13}, PlayingCard{1, 12},
                                   PlayingCard{1, 11}, PlayingCard{2, 12},
                                   PlayingCard{2, 13}}};
  // Full House
  TwoCardsHand h_a{.cards = {PlayingCard{3, 13}, PlayingCard{3, 2}}};

  // 4 of a kind.
  TwoCardsHand h_b{.cards = {PlayingCard{3, 12}, PlayingCard{4, 12}}};

  // h_b is better than h_a
  EXPECT_FALSE(IsBetterThan(h_a, h_b, h_center));
  EXPECT_TRUE(IsBetterThan(h_a, h_b, h_center));
}

TEST(IsBetterThan2, Test5) {
  FiveCardsHand h_center{.cards = {PlayingCard{1, 1}, PlayingCard{2, 2},
                                   PlayingCard{1, 3}, PlayingCard{1, 4},
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
