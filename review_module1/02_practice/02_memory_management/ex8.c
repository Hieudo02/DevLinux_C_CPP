// Có vấn đề gì với hàm copy sau?

int copy(char *scr, char *dst, unsigned int size)
{
    char *s1;
    while (size--)
    {
        *s1++ = *scr++;
        *dst++ = *s1;
    }
    return 0;
}

// Vấn đề 1: Sử dụng con trỏ chưa được khởi tạo
// Giải thích: Trong hàm copy, con trỏ 's1' được khai báo nhưng không được khởi tạo trước khi sử dụng.
// Khi cố gắng dereference con trỏ này với '*s1++', chương trình sẽ truy cập vào một vị trí bộ nhớ không xác định,
// dẫn đến hành vi không xác định và có thể gây ra lỗi chương trình hoặc dữ liệu không chính xác.

// Vấn đề 2: Logic sao chép dữ liệu không đúng
// Giải thích: Mục đích của hàm copy là sao chép dữ liệu từ nguồn (scr) sang đích (dst).
// Tuy nhiên, trong vòng lặp, sau khi gán giá trị từ 'scr' sang 's1', s1 được  tăng lên (s1++) rồi gán sang 'dst'.
// Điều này có nghĩa là giá trị được gán vào 'dst' không phải là giá trị gốc từ 'scr', mà là giá trị tiếp theo trong bộ nhớ sau 's1'.
// (Dòng đầu copy src[0] vào s1[0], sau đó s1 tăng lên thành s1[1], rồi gán s1[1] (giá trị không xác định) vào dst[0])

// Cách sửa 1: Nên loại bỏ con trỏ 's1' và sao chép trực tiếp từ 'scr' sang 'dst'.
int copy_fixed(char *scr, char *dst, unsigned int size)
{
    while (size--)
    {
        *dst++ = *scr++;
        // Giải thích chi tiết:
        // 1. *dst = *scr;  // Gán giá trị từ vị trí hiện tại của scr sang vị trí hiện tại của dst
        // 2. dst++;        // Di chuyển con trỏ dst sang vị trí tiếp theo
        // 3. scr++;        // Di chuyển con trỏ scr sang vị trí tiếp theo
        // 4. Quá trình này lặp lại cho đến khi size giảm về 0
    }
    return 0;
}

// Cách sửa 2: Nếu muốn sử dụng con trỏ trung gian, cần khởi tạo nó đúng cách và điều chỉnh logic sao chép.
int copy_fixed_with_intermediate(char *scr, char *dst, unsigned int size)
{
    char *s1 = scr; // Khởi tạo s1 trỏ đến scr
    while (size--)
    {
        *dst++ = *s1++; // Sao chép từ s1 (đang trỏ đến scr) sang dst
        // Giải thích chi tiết:
        // 1. *dst = *s1;  // Gán giá trị từ vị trí hiện tại của s1 (tương đương với scr) sang vị trí hiện tại của dst
        // 2. dst++;       // Di chuyển con trỏ dst sang vị trí tiếp theo
        // 3. s1++;       // Di chuyển con trỏ s1 (vẫn trỏ đến scr) sang vị trí tiếp theo
        // 4. Quá trình này lặp lại cho đến khi size giảm về 0
    }
    return 0;
}
