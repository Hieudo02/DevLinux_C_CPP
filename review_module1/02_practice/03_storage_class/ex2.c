/*
1. Code này có biên dịch được không?
2. Nếu không, compiler báo lỗi gì? Tại sao?
*/

#include <stdio.h>

int main(void) {
    register int x = 5;
    printf("%d\n", x);
    printf("%p\n", &x);
    return 0;
}

/*
- Không biên dịch được: "address of register variable 'x' requested".

- Lý do: 
+ Biến khai báo với từ khóa 'register' được khuyến nghị lưu trữ trong thanh ghi CPU để truy cập nhanh. 
+ Biến 'register' không có địa chỉ bộ nhớ cố định, nên không thể lấy địa chỉ của nó.
+ Do đó, việc lấy địa chỉ của biến này bằng toán tử '&' là không hợp lệ, dẫn đến lỗi biên dịch.

- Cách khắc phục:
+ Loại bỏ từ khóa 'register' để biến được lưu trữ trong bộ nhớ thông thường, cho phép lấy địa chỉ của nó.
*/