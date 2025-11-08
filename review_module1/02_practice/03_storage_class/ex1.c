/*
1. Kết quả in ra là gì?
2. Nếu bỏ từ khóa static, kết quả có khác không?
3. Biến count được lưu ở vùng nhớ nào?
*/

#include <stdio.h>

void counter(void) {
    static int count = 0;
    count++;
    printf("%d ", count);
}

int main(void) {
    for (int i = 0; i < 3; i++)
        counter();
    return 0;
}

/*
- KQ in ra: 1 2 3

- Nếu bỏ từ khóa static, kết quả sẽ là: 1 1 1, vì biến count sẽ được khởi tạo lại mỗi lần hàm được gọi.

- Vùng nhớ lưu trữ:
+ Biến "count" có thời gian sống toàn chương trình (static storage duration), không có linkage, và không nằm trên stack.
+ Về phân đoạn bộ nhớ (phổ biến với ELF/gcc):
    ++ Nếu khởi tạo bằng 0: thường đặt ở .bss.
    ++ Nếu khởi tạo khác 0 (ví dụ static int count = 5;): thường đặt ở .data.
Vì ở đây là = 0, "count" nằm ở .bss (không phải “Data Segment”, trừ khi khởi tạo khác 0).
*/