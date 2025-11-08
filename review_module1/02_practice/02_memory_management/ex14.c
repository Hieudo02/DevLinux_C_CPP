// Đoạn mã sau có vấn đề gì?

#include <stdio.h>
#include <stdlib.h>

char *getString(void) {
    char str[] = "hello";
    return str;
}
int main(void) {
    char *s = getString();
    printf("%s\n", s);
}

/*
- Hàm getString trả về con trỏ trỏ đến mảng cục bộ str, nhưng str được tạo trên ngăn xếp (stack) và sẽ bị hủy khi hàm kết thúc.
- Do đó, con trỏ s trong hàm main sẽ trỏ đến vùng nhớ không hợp lệ, dẫn đến hành vi không xác định khi in chuỗi.

- Để sửa lỗi, có thể sử dụng cấp phát động bộ nhớ cho chuỗi hoặc sử dụng biến tĩnh.
Cụ thể:
    Cách 1: Sử dụng cấp phát động
    char *getString(void) {
        char *str = malloc(6);
        strcpy(str, "hello");
        return str;
    }
    // Đừng quên giải phóng bộ nhớ sau khi sử dụng:
    free(s);

    Cách 2: Sử dụng biến tĩnh
    char *getString(void) {
        static char str[] = "hello";
        return str;
    }
*/