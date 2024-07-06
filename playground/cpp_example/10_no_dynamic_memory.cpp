#include <cstdint>
//#include <vector>
#include <array>
#include <algorithm>

int main (void) {
    int index = 0;
    while (true) {
        std::array<int, 3> arr;
        //std::vector<int> arr (3);
        arr[0] = index;
        arr[3] = arr[2] + 3;
    }
}