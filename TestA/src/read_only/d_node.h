#pragma once

/* DO NOT MODIFY THIS CODE
 * IT WILL BE OVERWRITTEN DURING EVALUATION SO ANY CHANGES YOU MADE WILL BE LOST
 */

/* อย่าทำการแก้ไขใดๆ ในไฟล์นี้เพราะไฟล์นี้จะถูกเขียนทับจากต้นฉบับในการตรวจ
 * การแก้ไขใดๆที่เกิดขึ้นจะถูกแก้ให้กลับไปเป็นค่าเริ่มต้นตอนตรวจข้อสอบ
 */

// struct DNode (Doubly Node) โดยจะมีสมาชิกเป็น right, left แทน next เพื่อสนับสนุนการใช้งานของ DoublyLinkedList
struct DNode {
  char val;
  DNode *right; // equivalent to next in Lab4/5
  DNode *left;  // additional field to support doubly linked list.
};
