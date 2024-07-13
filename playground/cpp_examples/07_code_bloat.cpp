#include <cstdint>

template <typename T>
class Example {
private:
    T m_data[10000];
public:
    __attribute__ ((noinline)) void init() {
        for (int i = 0; i < 10000; i++) {
            m_data[i] = i;
        }
    }
};

int main (void) {

    Example<int> example_int;
    example_int.init();

    Example<char> example_char;
    example_char.init();

    while (true) { /* ... */ }
}
