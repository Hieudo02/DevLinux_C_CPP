// Đoạn mã sau có vấn đề gì không?

#include <stdio.h>

void main(void) {
    char array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    int *p = (int *)array;
    p++;
    p++;
    printf("Value at p: 0x%x\n", *p);
}

// Vấn đề: Truy cập bộ nhớ không hợp lệ
// Giải thích: Trong đoạn mã trên, con trỏ 'p' được tăng lên hai lần,
// dẫn đến việc truy cập vào một vị trí bộ nhớ không đúng với kiểu dữ liệu int.
// Điều này có thể gây ra hành vi không xác định vì con trỏ không được căn chỉnh đúng cách
// cho kiểu int. Việc truy cập bộ nhớ không hợp lệ có thể dẫn đến lỗi chương trình hoặc dữ liệu không chính xác.

// Sửa lỗi: Để tránh vấn đề này, cần đảm bảo rằng con trỏ 'p' được căn chỉnh đúng cách
// trước khi truy cập dữ liệu. Một cách để làm điều này là sử dụng con trỏ char để truy cập từng byte một,
// hoặc đảm bảo rằng con trỏ int được tăng lên theo kích thước của kiểu int thay vì tăng theo số lượng phần tử. Ví dụ:
#include <stdio.h>
#include <string.h>
void main(void) {
    char array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    // Sử dụng con trỏ char để truy cập từng byte
    char *pChar = array + 8; // Truy cập byte thứ 8
    int value;
    memcpy(&value, pChar, sizeof(int)); // Sao chép dữ liệu vào biến int
    printf("Value at p: 0x%x\n", value);
}