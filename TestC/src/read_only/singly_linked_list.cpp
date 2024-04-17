#include "singly_linked_list.h"

// Destructor for SinglyLinkedList
// ฟังก์ชั่นที่จะถูกเรียกเพื่อทำลายตัวแปรประเภท SinglyLinkedList
SinglyLinkedList::~SinglyLinkedList() {
  Node *cur = head_;
  // วนลูปเพื่อเข้าถึง Node ทุกตัวใน SinglyLinkedList โดยเริ่มจาก head_ และเลื่อนไปเรื่อยๆ
  // จนกว่าจะเลยตัวสุดท้าย
  while (cur != nullptr) {
    Node *temp = cur;
    cur = cur->next;
    delete temp;
  }
}

// Returns the number of Nodes in the SinglyLinkedList
int SinglyLinkedList::Size() const {
  // จำนวนสมาชิกใน SinglyLinkedList ได้ถูกบันทึกไว้ตลอดทำให้สามารถตรวจสอบได้ทันทีว่ามีสมาชิกกี่ตัว
  return num_nodes_;
}

// Returns const pointer (value is read-only) to Node at position |pos|.
// If |pos| is invalid, return nullptr.
const Node *SinglyLinkedList::GetNodeAt(int pos) const {
  return GetMutableNodeAt(pos);
}

// Returns pointer (value can be modified) to Node at position |pos|. 
// If |pos| is invalid, return nullptr.
Node *SinglyLinkedList::GetMutableNodeAt(int pos) const {
  // กรณีที่ขอข้อมูลในตำแหน่งที่ไม่ถูกต้อง ให้คืนค่าเป็น nullptr ทันที
  if (pos < 0 || pos >= num_nodes_) {
    return nullptr;
  }
  // วน loop เพื่อให้ cur ชี้ไปที่ตำแหน่ง pos ที่ต้องการ
  Node *cur = head_;
  for (int i = 0; i < pos; ++i) {
    cur = cur->next;
  }
  return cur;
}


// Add a new Node with value |v| at the end of the SinglyLinkedList
void SinglyLinkedList::Append(char v, double p) {
  // สร้าง Node ที่จะนำไปต่อข้างหลังสุดของ LinkedList
  Node *n = new Node{v, p, nullptr};
  // ถ้า SinglyLinkedList ไม่ได้ว่างเปล่า (มี tail_) ให้นำ Node n ไปต่อข้างหลัง tail.
  if (tail_ != nullptr) {
    tail_->next = n;
  } else {
    // ถ้า SinglyLinkedList ว่างเปล่า กำหนด n เป็น head_ ได้เลย
    head_ = n;
  }
  // ย้าย tail_ ไปชี้ Node n ซึ่งเป็นตัวสุดท้ายตัวใหม่และเพิ่มจำนวน Node ที่นับไว้
  tail_ = n;
  num_nodes_++;
}

// Add a new Node with value |v| at the specified location in the
// SinglyLinkedList
void SinglyLinkedList::InsertAt(char v, double p, int pos) {
  // ถ้าตำแหน่งที่ต้องการใส่อยู่ที่ตำแหน่งสุดท้าย (หรือเกินกว่านั้น) ให้เรียกใช้ฟังก์ชั่น Append
  if (pos >= num_nodes_) {
    return Append(v, p);
  }

  // สร้าง Node n มาเตรียมไว้และเพิ่มจำนวน Node ที่นับไว้
  Node *n = new Node{v, p, nullptr};
  num_nodes_++;

  // ทำกรณีที่ต้องการใส่ Node n ไปในตำแหน่งแรก (หรือกรณี SinglyLinkedList ว่างเปล่า)
  if (pos <= 0 || head_ == nullptr) {
    // นำ head_ มาต่อหลัง Node n และย้าย head_ มาชี้ที่ Node n
    n->next = head_;
    head_ = n;
    // ถ้า LinkedList ว่างเปล่าให้เอา tail_ มาชี้ตัวใหม่ด้วย
    if (tail_ == nullptr) {
      tail_ = n;
    }
    return;
  }

  Node *cur = head_;
  // Move cur to the position pos-1
  // วน Loop เพื่อให้ cur ชี้ไปที่ Node ในตำแหน่งก่อนหน้า pos
  for (int i = 1; i < pos; ++i) {
    cur = cur->next;
  }
  // นำ Node n มาต่อท้าย cur
  n->next = cur->next;
  cur->next = n;
  // ถ้า Node n มาต่อแล้วเป็นตำแหน่งสุดท้าย ให้ย้าย tail_ มาชี้ n
  if (n->next == nullptr) {
    tail_ = n;
  }
}

// Erase the Node at the specified location in the SinglyLinkedList
bool SinglyLinkedList::EraseAt(int pos) {
  // ถ้าตำแหน่ง pos ที่ต้องการลบอยู่นอกขอบเขตของ SinglyLinkedList ให้คืนค่า false ทันที
  if (pos < 0 || pos >= num_nodes_) {
    return false;
  }

  // Handle erase head
  // กรณีที่ลบตำแหน่งแรก, เก็บตำแหน่งที่ต้องการลบจาก head_
  // แล้วย้าย head_ ไปตัวต่อไป
  if (pos == 0) {
    Node *temp = head_;
    head_ = temp->next;
    // กรณีที่มีตัวเดียว tail_ จะชี้ไปที่ temp จึงต้องอัพเดท tail_ ให้ชี้ไปที่เดียวกับ head_
    // ซึ่งจะมีค่าเป็น nullptr
    if (tail_ == temp) {
      tail_ = head_;
    }
    // ทำการลบที่อยู่ที่ตัวแปร temp ชี้ไปและลดจำนวน Node ที่นับไว้
    delete temp;
    num_nodes_--;
    return true;
  }

  // Move cur to the position pos-1
  // วน Loop เพื่อให้ cur ชี้ไปที่ Node ในตำแหน่งก่อนหน้า pos
  Node *cur = head_;
  for (int i = 1; i < pos; ++i) {
    cur = cur->next;
  }
  // บันทึกค่า Node ที่ต้องการลบไว้ใน temp แล้วย้าย cur ไปชี้ที่ตัวถัดไป
  Node *temp = cur->next;
  cur->next = temp->next;
  // ถ้าหลังจากการลบแล้ว cur ไม่มีตัวถัดไปให้ย้าย tail_ มาชี้ที่ cur
  if (cur->next == nullptr) {
    tail_ = cur;
  }
  // ทำการลบที่อยู่ที่ตัวแปร temp ชี้ไปและลดจำนวน Node ที่นับไว้
  delete temp;
  num_nodes_--;
  return true;
}
