// Đoạn mã sau có vấn đề gì không? Với RAM = 2000 byte?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myfunction()
{
    char *q;
    for (int i = 0; i < 1000; i++)
    {
        q = (char *)malloc(8);
        if (q != NULL)
        {
            memcpy(q, "hello", 6);
        }
    }
}

// => Với RAM = 2000 byte, chương trình sẽ nhanh chóng cạn heap do không free, gây memory leak và làm malloc trả NULL ở các vòng sau.

/*
- q mấy byte? 
    => 8 byte, vì kích thước con trỏ phụ thuộc vào kiến trúc máy (32bit-4byte hay 64bit-8byte) chứ không phụ thuộc vào kích thước vùng nhớ được cấp phát. 
- malloc(8) là cấp mấy byte? 
    => 8 byte
- Copy 6 byte vào block 8 byte: 2 byte còn lại thế nào?
    + "malloc" trả về bộ nhớ không khởi tạo.
    + Sau memcpy(q, "hello", 6), 6 byte đầu là {'h','e','l','l','o','\0'}.
    + 2 byte còn lại vẫn chưa xác định (rác), không nên đọc chúng trước khi được gán giá trị hợp lệ.
- Mỗi vòng lặp malloc có cấp vùng mới "liền kề" cái trước rồi q nhảy tiếp không?
    + Không có đảm bảo liền kề hay tăng đều. Allocator có thể trả về địa chỉ bất kỳ phù hợp (thường đã căn chỉnh, ví dụ bội số của 8/16).
    + Vì code trên không free, các block cũ vẫn giữ chỗ (bị rò rỉ). Biến q (trên stack) chỉ bị gán lại để trỏ tới block mới; không "nhảy" bản thân sang heap.
    + Ví dụ địa chỉ có thể là 0x1000, rồi 0x1080, rồi 0x2070…
*/

// Giải pháp: Thêm free(q); sau memcpy để giải phóng bộ nhớ đã cấp phát trong mỗi vòng lặp.
/*
void myfunction()
{
    char *q;
    for (int i = 0; i < 1000; i++)
    {
        q = (char *)malloc(8);
        if (q != NULL)
        {
            memcpy(q, "hello", 6);
        } else {
            // Xử lý lỗi cấp phát bộ nhớ
            fprintf(stderr, "Memory allocation failed at iteration %d\n", i);
            break; // Thoát vòng lặp nếu không cấp phát được bộ nhớ
        }
        free(q); // Giải phóng bộ nhớ sau khi sử dụng
    }
}
*/