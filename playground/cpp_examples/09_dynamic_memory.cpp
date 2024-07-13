#include <cstdint>
#include <vector>
#include <algorithm>

int main (void) {
    int index = 0;
    while (true) {
        std::vector<int> arr (3);
        arr[0] = index;
        arr[3] = arr[2] + 3;
    }
}