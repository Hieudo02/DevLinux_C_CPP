// Đoạn mã sau có vấn đề gì?

void recursion(int x) {
    int a[100];
    recursion(x + 1);
}

/*
- Hàm đệ quy không có điều kiện dừng, dẫn đến việc gọi hàm liên tục cho đến khi ngăn xếp (stack) bị tràn.
- Mỗi lần gọi hàm, một mảng cục bộ a[100] được tạo trên ngăn xếp, làm tăng nhanh kích thước ngăn xếp.
- Kết quả là chương trình sẽ bị sập (crash) do tràn ngăn xếp (stack overflow).
- Để khắc phục, cần thêm điều kiện dừng cho hàm đệ quy hoặc tránh sử dụng đệ quy vô hạn.
VD:
    void recursion(int x) {
        if (x >= MAX_DEPTH) return; // Điều kiện dừng
        int a[100];
        recursion(x + 1);
    }
*/