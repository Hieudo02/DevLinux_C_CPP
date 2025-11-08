// Đoạn mã sau có hợp lệ không?

void test(void) {
    char *str = "Hello";
    str[0] = 'h';
}

/*
1. Chuỗi "str" được lưu trong vùng nhớ Read-Only, nên thay đổi nội dung của nó sẽ dẫn đến lỗi thời gian chạy (segmentation fault).
2. Để sửa lỗi, nên sử dụng mảng ký tự hoặc cấp phát động bộ nhớ cho chuỗi nếu cần thay đổi nội dung.
Cụ thể:
    char str[] = "Hello"; // Sử dụng mảng ký tự
    // hoặc
    char *str = malloc(6);
    strcpy(str, "Hello");
*/