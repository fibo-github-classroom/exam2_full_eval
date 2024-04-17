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
  Hand h;
  h.cards = {PlayingCard{1}, PlayingCard{2}, PlayingCard{3}, PlayingCard{4},
             PlayingCard{5}};
  EXPECT_TRUE(IsValid(h));
}

TEST(IsValidHand, DISABLED_Test1) {
  // This is valid for blackjack.
  Hand h;
  h.cards = {PlayingCard{1}, PlayingCard{2}, PlayingCard{3}, PlayingCard{4},
             PlayingCard{1}};
  EXPECT_TRUE(IsValid(h));
}

TEST(IsValidHand, Test2) {
  Hand h;
  h.cards = {PlayingCard{1, 1}, PlayingCard{2, 1}};
  EXPECT_TRUE(IsValid(h));
}

TEST(IsValidHand, Test3) {
  Hand h;
  h.cards = {PlayingCard{1}, PlayingCard{2}};
  EXPECT_TRUE(IsValid(h));
  h.cards.push_back(PlayingCard{55});
  EXPECT_FALSE(IsValid(h));
}

TEST(IsBetterThan, Test0) {
  Hand h_a;
  // score = 21.
  h_a.cards = {PlayingCard{1, 1}, PlayingCard{1, 13}};

  Hand h_b;
  // score = 20.
  h_b.cards = {PlayingCard{2, 11}, PlayingCard{2, 10}};

  // h_a is better than h_b
  EXPECT_TRUE(IsBetterThan(h_a, h_b));
  EXPECT_FALSE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test1) {
  Hand h_a;
  // score > 21 (busted).
  h_a.cards = {PlayingCard{1, 12}, PlayingCard{1, 3}, PlayingCard{1, 13}};

  Hand h_b;
  // score = 20.
  h_b.cards = {PlayingCard{2, 11}, PlayingCard{2, 10}};

  // h_b is better than h_a
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
}

TEST(IsBetterThan, Test2) {
  Hand h_a;
  // score = 17.
  h_a.cards = {PlayingCard{1, 1}, PlayingCard{1, 6}};

  Hand h_b;
  // score = 17.
  h_b.cards = {PlayingCard{2, 11}, PlayingCard{2, 7}};

  Hand h_c;
  // score = 16.
  h_c.cards = {PlayingCard{2, 11}, PlayingCard{2, 6}};

  // neither h_a/h_b are better
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
  EXPECT_FALSE(IsBetterThan(h_b, h_a));

  // but better than h_c
  EXPECT_TRUE(IsBetterThan(h_a, h_c));
}

TEST(IsBetterThan, Test3) {
  Hand h_a;
  // score > 21 (busted).
  h_a.cards = {PlayingCard{1, 12}, PlayingCard{1, 3}, PlayingCard{1, 13}};

  Hand h_b;
  // score > 21. (busted)
  h_b.cards = {PlayingCard{4, 2}, PlayingCard{2, 11}, PlayingCard{2, 10}};

  Hand h_c;
  // score = 4.
  h_c.cards = {PlayingCard{2, 2}, PlayingCard{3, 2}};

  // neither one is better
  EXPECT_FALSE(IsBetterThan(h_b, h_a));
  EXPECT_FALSE(IsBetterThan(h_a, h_b));

  // but h_c is better
  EXPECT_TRUE(IsBetterThan(h_c, h_a));
}

TEST(IsBetterThan, Test4) {
  Hand h_a;
  // score = 13.
  h_a.cards = {PlayingCard{1, 1}, PlayingCard{2, 1}, PlayingCard{3, 1},
               PlayingCard{1, 13}};

  Hand h_b;
  // score = 12.
  h_b.cards = {PlayingCard{1, 1}, PlayingCard{2, 1}, PlayingCard{1, 13}};

  // h_a is better than h_b
  EXPECT_TRUE(IsBetterThan(h_a, h_b));
  EXPECT_FALSE(IsBetterThan(h_b, h_a));
}

TEST(IsBetterThan, Test5) {
  Hand h_a;
  // score = 17.
  h_a.cards = {PlayingCard{1, 7}, PlayingCard{2, 10}};

  Hand h_b;
  // score = 18.
  h_b.cards = {PlayingCard{1, 3}, PlayingCard{2, 6}, PlayingCard{1, 9}};

  // h_b is better than h_a
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
}

TEST(IsBetterThan, Test6) {
  Hand h_a;
  // score = 20.
  h_a.cards = {PlayingCard{1, 11}, PlayingCard{2, 10}};
  // score = 21.
  Hand h_b;
  h_b.cards = {PlayingCard{1, 1}, PlayingCard{2, 1}, PlayingCard{3, 1},
               PlayingCard{2, 1}, PlayingCard{3, 1}, PlayingCard{4, 1},
               PlayingCard{3, 1}, PlayingCard{4, 1}, PlayingCard{1, 1},
               PlayingCard{4, 1}, PlayingCard{2, 1}, PlayingCard{2, 1},
               PlayingCard{1, 1}, PlayingCard{3, 1}, PlayingCard{1, 1},
               PlayingCard{2, 1}, PlayingCard{4, 1}, PlayingCard{2, 1},
               PlayingCard{3, 1}, PlayingCard{2, 1}, PlayingCard{3, 1}};

  // h_b is better than h_a
  EXPECT_TRUE(IsBetterThan(h_b, h_a));
  EXPECT_FALSE(IsBetterThan(h_a, h_b));
}

TEST(IsBetterThan, Test7) {
  Hand h_a;
  // score = 11.
  h_a.cards = {PlayingCard{1, 1}};

  Hand h_b;
  // score = 10.
  h_b.cards = {PlayingCard{1, 13}};

  // h_a is better than h_b
  EXPECT_TRUE(IsBetterThan(h_a, h_b));
  EXPECT_FALSE(IsBetterThan(h_b, h_a));
}

TEST(ShouldGetMoreCard, Test0) {
  Hand h;
  // score = 16.
  h.cards = {PlayingCard{1, 9}, PlayingCard{1, 7}};
  EXPECT_TRUE(ShouldGetMoreCard(h));
  // score = 19.
  h.cards.push_back(PlayingCard{1, 3});
  EXPECT_FALSE(ShouldGetMoreCard(h));
}

TEST(ShouldGetMoreCard, Test1) {
  Hand h;
  h.cards = {PlayingCard{1, 1}, PlayingCard{1, 2}};
  // score = 13
  EXPECT_TRUE(ShouldGetMoreCard(h));
  // score = 16
  h.cards.push_back(PlayingCard{1, 3});
  EXPECT_TRUE(ShouldGetMoreCard(h));

  // score = 19
  h.cards.push_back(PlayingCard{2, 3});
  EXPECT_FALSE(ShouldGetMoreCard(h));
 
}

TEST(ShouldGetMoreCard, Test2) {
  Hand h;
  // score = 17 with no ace.
  h.cards = {PlayingCard{1, 11}, PlayingCard{1, 7}};

  EXPECT_FALSE(ShouldGetMoreCard(h));
}

TEST(ShouldGetMoreCard, Test3) {
  Hand h;
  // score = 17 with ace.
  h.cards = {PlayingCard{1, 1}, PlayingCard{1, 6}};

  EXPECT_TRUE(ShouldGetMoreCard(h));
}
} // namespace
