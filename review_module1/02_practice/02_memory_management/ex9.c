// Có vấn đề gì với hàm copy sau?

void func(void) {
    char *p = malloc(10);
    strcpy(p, "Embedded");
}

/*
1. Không kiểm tra NULL sau khi gọi malloc.
2. Con trỏ p không được free sau khi sử dụng, dẫn đến rò rỉ bộ nhớ.
*/