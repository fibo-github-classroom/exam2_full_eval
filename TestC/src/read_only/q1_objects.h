#pragma once

#include <vector>

/* DO NOT MODIFY THIS CODE
 * IT WILL BE OVERWRITTEN DURING EVALUATION SO ANY CHANGES YOU MADE WILL BE LOST
 */

/* อย่าทำการแก้ไขใดๆ ในไฟล์นี้เพราะไฟล์นี้จะถูกเขียนทับจากต้นฉบับในการตรวจ
 * การแก้ไขใดๆที่เกิดขึ้นจะถูกแก้ให้กลับไปเป็นค่าเริ่มต้นตอนตรวจข้อสอบ
 */

struct Point {
  double x, y;
};

struct PersonInfo {
  double height; // meter
  int weight;    // kg
};

struct Node {
  int val;
  Node *next;
};
