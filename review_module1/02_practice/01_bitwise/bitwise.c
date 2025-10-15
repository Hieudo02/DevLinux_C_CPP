#include <stdio.h>

// 1. How to set a specific bit in a byte to 1?
// Use the OR (|) operator with a mask that has the bit to be set as 1.
// For example: x |= (1 << n); // set bit n of x
void set_bit_example()
{
    unsigned char x = 0; // 0000 0000
    int n = 3;           // 1 << 3 -> 0000 1000
    printf("\nThe value of x before setting bit %d: 0x", n);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");

    // Set bit n of x
    x |= (1 << n);
    /*
    OR (|) table:
        0 | 0 = 0
        0 | 1 = 1
        1 | 0 = 1
        1 | 1 = 1
    Explanation:
        1 << 3 = 0000 1000 (left shift 1 by 3 positions)
        x = 0000 0000

        0000 0000
        0000 1000
        ----------
        0000 1000
    */
    printf("The value of x after setting bit %d: 0x", n);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");
}

// 2. How to clear a specific bit in a byte to 0?
// Use the AND (&) operator with a mask that has the bit to be cleared as 0.
// For example: x &= ~(1 << n); // clear bit n of x
// Note: ~ is the NOT operator that inverts all bits.
// For example: ~(0000 1000) = 1111 0111
void clear_bit_example()
{
    unsigned char x = 0xFF; // 1111 1111
    int n = 3;              // 1 << 3 -> 0000 1000
    printf("\nThe value of x before clearing bit %d: 0x", n);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");

    // Clear bit n of x
    x &= ~(1 << n);
    /*
    AND (&) table:
        0 & 0 = 0
        0 & 1 = 0
        1 & 0 = 0
        1 & 1 = 1
    Explanation:
        1 << 3 = 0000 1000 (left shift 1 by 3 positions) => ~(0000 1000) = 1111 0111 (invert all bits)
        x = 1111 1111

        1111 1111
        1111 0111
        ----------
        1111 0111
    */
    printf("The value of x after clearing bit %d: 0x", n);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");
}

// 3. How to toggle a specific bit in a byte?
// Use the XOR (^) operator.
// For example: x ^= (1 << n); // toggle bit n of x
void toggle_bit_example()
{
    unsigned char x = 0; // 0000 0000
    int n = 3;           // 1 << 3 -> 0000 1000
    printf("\nThe value of x before toggling bit %d: 0x", n);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");

    // Toggle bit n of x
    x ^= (1 << n);
    /*
    XOR (^) table:
        0 ^ 0 = 0
        0 ^ 1 = 1
        1 ^ 0 = 1
        1 ^ 1 = 0
    Explanation:
        1 << 3 = 0000 1000 (left shift 1 by 3 positions)
        x = 0000 0000

        0000 0000
        0000 1000
        ----------
        0000 1000
    */
    printf("The value of x after toggling bit %d: 0x", n);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");
}

// 4. How to check if a specific bit in a byte is set (1) or not (0)?
// Use the AND (&) operator with a mask that has the bit to be checked as 1.
// For example: if (x & (1 << n)) { /* bit n is set */ }
void check_bit_example(unsigned char x, int position)
{
    printf("\nThe value of x before checking bit %d: 0x", position);
    for (int i = 7; i >= 0; i--)
    {
        printf(" %x", (x >> i) & 1);
    }
    printf("\n");

    /*
    AND (&) table:
        0 & 0 = 0
        0 & 1 = 0
        1 & 0 = 0
        1 & 1 = 1
    Explanation:
    for example
        if: x = 0000 1000
            position = 3 => 1 << 3 = 0000 1000 (left shift 1 by 3 positions)
            0000 1000
            0000 1000
            ----------
            0000 1000 (non-zero, bit is set)

        If: x = 0000 0000
            position = 3 => 1 << 3 = 0000 1000 (left shift 1 by 3 positions)
            0000 0000
            0000 1000
            ----------
            0000 0000 (zero, bit is not set)
    */

    // if(zero) -> false
    // if(non-zero) -> true
    if (x & (1 << position))
    {
        printf("Bit %d is set in x\n", position);
    }
    else
    {
        printf("Bit %d is not set in x\n", position);
    }
}

// 5. How to swap two numbers without a third variable?
// Use the XOR swap (^) operator.
void swap(int *a, int *b)
{
    *a = *a ^ *b; // Step 1: a now holds the XOR of a and b
    *b = *a ^ *b; // Step 2: b is now the original value of a
    *a = *a ^ *b; // Step 3: a is now the original value of b

    /*
    Explanation:
        Let original values be:
            a = A
            b = B

        After Step 1:
            a = A ^ B
            b = B

        After Step 2:
            a = A ^ B
            b = (A ^ B) ^ B = A (since B ^ B = 0 and A ^ 0 = A)

        After Step 3:
            a = (A ^ B) ^ A = B (since A ^ A = 0 and B ^ 0 = B)
            b = A

        Now the values are swapped:
            a = B
            b = A
    */
}

// 6. How to check if a number is a power of 2?
// A number is a power of 2 if it has exactly one bit set.
void is_power_of_two(unsigned int x)
{
    /*
    Explanation:
        A number x is a power of 2 if:
            x != 0 (to exclude 0)
            x & (x - 1) == 0 (to ensure only one bit is set)
        For example:
            If x = 8 (which is 2^3), in binary: 0000 1000
            x - 1 = 7, in binary: 0000 0111
            0000 1000
          & 0000 0111
            ----------
            0000 0000 (which is 0)

            If x = 10, in binary: 0000 1010
            x - 1 = 9, in binary: 0000 1001
            0000 1010
          & 0000 1001
            ----------
            0000 1000 (which is not 0)
    */
    if ((x != 0) && ((x & (x - 1)) == 0))
    {
        printf("%d is a power of 2\n", x);
    }
    else
    {
        printf("%d is not a power of 2\n", x);
    }
}

// 7. How to count the number of 1 bits in the binary representation of a number?
// Use the Brian Kernighan’s Algorithm
// Reference: https://www.geeksforgeeks.org/count-set-bits-in-an-integer
// __builtin_popcount
// Reference: https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
int count_set_bits(unsigned int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1); // Clear the least significant bit set
        count++;
    }
    return count;

    // Alternatively, using GCC built-in function
    // return __builtin_popcount(n);
}

// 8. How to determine if a number is even or odd?
// Use the AND (&) operator with 1.
// For example: if (x & 1) { /* x is odd */ } else { /* x is even */ }
int is_even_or_odd(int x)
{
    if (x & 1)
    {
        return 0; // odd
    }
    else
    {
        return 1; // even
    }
}

// 9. How to find the 2’s complement of a binary number?
// Invert all bits and add 1 to the least significant bit (LSB).
// For example: -x = ~x + 1;
int twos_complement(int x)
{
    // Bù 2 của 1 số nhị phân là số mà khi cộng với số ban đầu sẽ cho ra 0.
    // VD: 5 + (-5) = 0
    // Cách tính: Đảo tất cả các bit và cộng thêm 1 vào bit ít quan trọng (LSB)
    return ~x + 1;
}

// 10. How to check if two numbers are equal without using comparison operators?
// Use the XOR (^) operator.
// For example: if ((a ^ b) == 0) { /* a and b are equal */ }
void compare_without_using_comparison_operators(int a, int b)
{
    // include printf to show the result
    if ((a ^ b) == 0)
    {
        printf("\n%d and %d are equal\n", a, b);
    }
    else
    {
        printf("\n%d and %d are not equal\n", a, b);
    }
}

// 11. How to find the Most Significant Bit (MSB) of a number?
// Use bitwise operations to isolate the MSB.
// 1. Shift the number right until only the MSB remains.
// 2. Alternatively, use a loop to check each bit from the highest position down to the lowest.
int find_msb(unsigned int x)
{
    if (x == 0)
        return -1; // No MSB for 0

    int msb_position = 0;
    while (x >>= 1)
    {
        msb_position++;
    }
    // Explanation:
    // For example, if x = 18 (which is 10010 in binary):
    // 1. Initial value: x = 10010, msb_position = 0
    // 2. Shift right: x = 01001, while(not 0), msb_position = 1 => as long as while(!0) => continue
    // 3. Shift right: x = 00100, while(not 0),msb_position = 2
    // 4. Shift right: x = 00010, while(not 0),msb_position = 3
    // 5. Shift right: x = 00001, while(not 0),msb_position = 4
    // 6. Shift right: x = 00000, loop ends (while (0) => break), msb_position = 4

    return msb_position; // Return the position of the MSB (0-indexed)
}

// 12. How to find the Least Significant Bit (LSB) of a number?
// Use the AND (&) operator with 1.
int find_lsb(unsigned int x)
{
    if (x == 0)
        return -1; // No LSB for 0

    int lsb_position = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        lsb_position++;
    }
    // Explanation:
    // For example, if x = 18 (which is 10010 in binary):
    // 1. Initial value: x = 10010, lsb_position = 0
    // 2. Check LSB: x & 1 = 0 (false), shift right: x = 01001, lsb_position = 1
    // 3. Check LSB: x & 1 = 1 (true), loop ends, lsb_position = 1

    return lsb_position; // Return the position of the LSB (0-indexed)
}

// 13. How to turn off the rightmost 1 bit?
// Use the AND (&) operator with (x - 1).
// For example: x &= (x - 1);
void turn_off_rightmost_1_bit(unsigned int *x)
{
    printf("\nThe value of x before turning off the rightmost 1 bit: 0b");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (*x >> i) & 1);
    }
    printf("\n");

    *x &= (*x - 1);
    /*
    Explanation:
        For example, if x = 18 (which is 10010 in binary):
        1. Initial value: x = 10010
        2. x - 1 = 10001
        3. AND operation:
            10010
          & 10001
          --------
            10000 (rightmost 1 bit turned off)
    */
    printf("The value of x after turning off the rightmost 1 bit: 0b");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (*x >> i) & 1);
    }
    printf("\n");
}

// 14. How to isolate the rightmost 1 bit?
// Use the AND (&) operator with the negation of the number.
// For example: rightmost_1_bit = x & -x;
unsigned int isolate_rightmost_1_bit(unsigned int x)
{
    return x & -x;
}

// 15. How to check if a number is a multiple of 8?
// Use the AND (&) operator with 7 (which is 111 in binary).
int is_multiple_of_8(unsigned int x)
{
    return (x & 7) == 0;
    // Explanation:
    // A number is a multiple of 8 if its last three bits are 0.
    // For example, if x = 16 (which is 10000 in binary):
    // 16 & 7 = 10000 & 00111 = 00000 (which is 0, so 16 is a multiple of 8)
    // If x = 18 (which is 10010 in binary):
    // 18 & 7 = 10010 & 00111 = 00010 (which is not 0, so 18 is not a multiple of 8)

    // what if multiple of 6
    // return (x & 5) == 0; // 6 = 110, 5 = 101
    // what if multiple of 4
    // return (x & 3) == 0; // 4 = 100
    // what if multiple of 2
    // return (x & 1) == 0; // 2 = 10
}

int main(int argc, char *argv[])
{
    // example no.1,2,3,4
    set_bit_example();
    clear_bit_example();
    toggle_bit_example();
    check_bit_example(0b00001000, 3);

    // example no.5
    int x = 5, y = 10;
    printf("\nBefore swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    // example no.6
    is_power_of_two(16);
    is_power_of_two(18);

    // example no.7
    unsigned int num = 29; // Binary: 11101, Number of set bits = 4
    int set_bits = count_set_bits(num);
    printf("\nBinary representation of %d: 0b", num);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\nNumber of set bits in %d = %d\n", num, set_bits);

    // example no.8
    int number = 4;
    if (is_even_or_odd(number))
    {
        printf("\n%d is even\n", number);
    }
    else
    {
        printf("\n%d is odd\n", number);
    }

    // example no.9
    int val = 121;
    int neg_val = twos_complement(val);
    printf("\nThe 2's complement of %d is %d\n", val, neg_val);

    // example no.10
    compare_without_using_comparison_operators(100, 50);

    // example no.11
    // unsigned int val_msb = 18; // Binary: 10010, MSB position = 4
    // unsigned int val_msb = 0; // Edge case: No MSB for 0
    unsigned int val_msb = 0b00000010; // Binary: 00000010, MSB position = 1
    int msb_pos = find_msb(val_msb);
    printf("\nThe Most Significant Bit (MSB) of %d is at position %d\n", val_msb, msb_pos);

    // example no.12
    // unsigned int val_lsb = 18; // Binary: 10010, LSB position = 1
    // unsigned int val_lsb = 0; // Edge case: No LSB for 0
    unsigned int val_lsb = 0b00001000; // Binary: 00001000, LSB position = 3
    int lsb_pos = find_lsb(val_lsb);
    printf("\nThe Least Significant Bit (LSB) of %d is at position %d\n", val_lsb, lsb_pos);

    // example no.13
    unsigned int val_turn_off = 18; // Binary: 10010
    turn_off_rightmost_1_bit(&val_turn_off);

    // example no.14
    unsigned int val_isolate = 18; // Binary: 10010
    unsigned int rightmost_1_bit = isolate_rightmost_1_bit(val_isolate);
    printf("\nThe rightmost 1 bit of %d is: 0b", val_isolate);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (rightmost_1_bit >> i) & 1);
    }
    printf("\n");
    
    // example no.15
    unsigned int val_multiple_of_8 = 24; // 24 is a multiple of 8
    if (is_multiple_of_8(val_multiple_of_8))
    {
        printf("\n%d is a multiple of 8\n", val_multiple_of_8);
    }
    else
    {
        printf("\n%d is not a multiple of 8\n", val_multiple_of_8);
    }
    return 0;
}