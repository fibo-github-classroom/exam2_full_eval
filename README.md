# Exam 2 Eval
Copy test files from the corresponding folder into your exam and run the run_eval script.
ให้นักศึกษาทำการคัดลอกไฟล์จากในโฟลเดอร์ที่ชื่อตรงกับชุดข้อสอบของตัวเองไปไว้ในโฟลเดอร์ข้อสอบ แล้วใช้ชุดคำสั่ง run_eval เพื่อทดสอบกับเทสเคสทั้งหมด

Scoring:
- Q1: 0.25 point per test case
- Q2.1: 0.5 point per test case
- Q2.2: 0.25 point per test case

ถ้ารันเคสไหนไม่ผ่านสามารถเติม DISABLED_ ไปในเคสนั้นเพื่อข้ามได้ (จะไม่ได้คะแนน)
ตัวอย่างเช่น
```
TEST(Q1_6, DISABLED_Test0) {
  Node s0{5, nullptr};
  Node s1{7, nullptr};
  auto out = SortedIntersect(&s0, &s1);
  EXPECT_EQ(out, nullptr);
}
```
