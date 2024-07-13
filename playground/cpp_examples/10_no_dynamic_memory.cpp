#include <cstdint>
#include <array>
#include <algorithm>

int main (void) {
    int index = 0;
    while (true) {
        std::array<int, 3> arr;
        arr[0] = index;
        arr[3] = arr[2] + 3;
    }
}