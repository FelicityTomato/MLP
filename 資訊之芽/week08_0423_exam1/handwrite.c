#include <stdio.h>

inline static int func (int x, int y) {
    int a = 3;
    int b = 5;
    int c = 7;
    printf("%p %p %p %p %p\n", &x, &y, &a, &b, &c);
    return 0;
}

int main () {
    func (1, 2);
    return 0;
}