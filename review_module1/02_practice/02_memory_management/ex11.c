// Các biến a, b, c, d được lưu ở đâu trong bộ nhớ?

int a = 10;
const int b = 5;
static int c = 3;
int func(void) {
    int d = 2;
    return a + b + c + d;
}

/*
    a: Toàn cục - khác 0 => .data (RAM, copy từ ROM lúc khởi động)
    b: Toàn cục - hằng số => .rodata (Vùng chỉ đọc, thường ở ROM/Flash)
    c: Toàn cục - static => .data (RAM, copy từ ROM lúc khởi động)
    d: Cục bộ trong hàm => Stack (Bộ nhớ ngăn xếp)
*/