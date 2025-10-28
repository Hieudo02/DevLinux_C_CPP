// Đoạn mã sau có vấn đề gì không? Làm sao để in ra "hello"?

/*
    void myfunction(char *q)
    {
        q = (char *)malloc(8);
        if (q)
        {
            memcpy(q, "hello", 6);
        }
    }
    void main(void)
    {
        char *p = NULL;
        myfunction(p);
        printf("%s\n", p);
    }
*/

/*
    - Hàm myfunction không thể thay đổi con trỏ p trong hàm main vì con trỏ q chỉ là một bản sao của con trỏ p.
    - Để in ra "hello", ta có thể thay đổi hàm myfunction để nhận con trỏ đến con trỏ (char **q) hoặc trả về con trỏ đã cấp phát bộ nhớ.
*/

// 1. Sửa đổi hàm myfunction để trả về con trỏ đã cấp phát bộ nhớ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *myfunction(void)
{
    char *q = (char *)malloc(8);
    if (q)
    {
        memcpy(q, "hello", 6);
    }
    return q;
}

void main(void)
{
    char *p = NULL;
    p = myfunction();
    printf("%s\n", p);
}

// 2. Hoặc sửa đổi hàm myfunction để nhận con trỏ đến con trỏ (tham số là con trỏ cấp 2)
/*
void myfunction(char **q)
{
    *q = (char *)malloc(8);
    if (*q)
    {
        memcpy(*q, "hello", 6);
    }
}
void main(void)
{
    char *p = NULL;
    myfunction(&p);
    printf("%s\n", p);
}
*/