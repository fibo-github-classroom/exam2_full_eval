#pragma once

/*
class Card has single member which is an integer number of any value.
การ์ดเป็นคลาสที่มีสมาชิก 1 ตัวซึ่งจะเก็บค่าตัวเลขของการ์ด
*/
class Card {
public:
  // Need one integer number to construct a card.
  Card(int v) : value_(v) {}

  // Returns a value of the card.
  int get_val() const { return value_; }

private:
  int value_;
};
