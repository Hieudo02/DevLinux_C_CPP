// Đoạn mã sau có in ra đúng giá trị ban đầu không? Tại sao?

#include <stdio.h>

int main(void) {
    int a = 0x12345678;
    char *p = (char *)&a;
    p[0] = 0xAA;
    printf("a = 0x%x\n", a);
}

/*
- Không, KQ in ra phụ thuộc vào kiến trúc hệ thống (endianness).
- Nếu hệ thống sử dụng little-endian, thì byte thấp nhất được lưu ở địa chỉ thấp nhất.
Do đó, p[0] sẽ thay đổi byte thấp nhất của a, dẫn đến a = 0x123456AA.
        a = 0x 12 34 56 78
        (byte thấp -> byte cao)
    p[0] = 0xAA sẽ thay đổi byte thấp nhất
        a = 0x 12 34 56 AA

- Nếu hệ thống sử dụng big-endian, thì byte cao nhất được lưu ở địa chỉ thấp nhất.
Do đó, p[0] sẽ thay đổi byte cao nhất của a, dẫn đến a = 0xAA345678.
        a = 0x 12 34 56 78
        (byte cao -> byte thấp)
    p[0] = 0xAA sẽ thay đổi byte cao nhất
        a = 0x AA 34 56 78
*/