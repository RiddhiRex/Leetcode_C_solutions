/*
Explanation:
We define the my_offsetof macro, which takes two arguments: the type of the struct (type) and the name of the member within that struct (member).
Inside the macro, we cast a null pointer (0) to a pointer to the specified struct type ((type *)0), and then we access the specified member using the -> operator (->member). This expression represents a pointer to the specified member within the struct.
We then take the address of this member pointer expression (&((type *)0)->member), which effectively gives us the byte offset of the member within the struct.
Finally, we cast this byte offset to a size_t to ensure correct arithmetic and return the result.
*/

#include <stdio.h>

#define my_offsetof(type, member) ((size_t)(&((type *)0)->member))

// Example usage
struct Example {
    int a;
    char b;
    double c;
};

int main() {
    size_t offset = my_offsetof(struct Example, c);
    printf("Offset of member 'c' in struct Example: %zu bytes\n", offset);
    return 0;
}
