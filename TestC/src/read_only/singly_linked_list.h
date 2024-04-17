#pragma once

#include <vector>

/* DO NOT MODIFY THIS CODE
 * IT WILL BE OVERWRITTEN DURING EVALUATION SO ANY CHANGES YOU MADE WILL BE LOST
 */

/* อย่าทำการแก้ไขใดๆ ในไฟล์นี้เพราะไฟล์นี้จะถูกเขียนทับจากต้นฉบับในการตรวจ
 * การแก้ไขใดๆที่เกิดขึ้นจะถูกแก้ให้กลับไปเป็นค่าเริ่มต้นตอนตรวจข้อสอบ
 */

struct Node {
  char val;
  double priority;
  Node *next;
};

class SinglyLinkedList {
public:
  // Constructor for class SinglyLinkedList
  SinglyLinkedList() = default;

  // Destructor for class SinglyLinkedList
  ~SinglyLinkedList();

  // Returns the number of Nodes in the SinglyLinkedList
  int Size() const;

  // Returns const pointer (value is read-only) to Node at position |pos|. If
  // |pos| is invalid, return nullptr.
  const Node *GetNodeAt(int pos) const;

  // Returns pointer (value can be modified) to Node at position |pos|. If
  // |pos| is invalid, return nullptr.
  Node *GetMutableNodeAt(int pos) const;

  // Add a new Node with value |v| at the end of the SinglyLinkedList
  void Append(char v, double p);

  // Add a new Node with value |v| at the specified location in the
  // SinglyLinkedList
  void InsertAt(char v, double p, int pos);

  // Erase the Node at the specified location in the SinglyLinkedList
  bool EraseAt(int pos);

private:
  // beginning of the linked list.
  Node *head_ = nullptr;
  // the last node of the linked list.
  Node *tail_ = nullptr;
  // number of nodes in the linked list.
  int num_nodes_ = 0;
};
