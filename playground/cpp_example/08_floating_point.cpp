#include <cstdint>

int main (void) {

    volatile double a = 15.5, b = 20.5, c;

    c = a + b;
    a = c * b;
    b = a / c;

    while (true) { /* ... */ }
}
