#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Perform a binary search in an integer vector.
 * 
 * This function searches for the specified 'key' in given 'arr' of integers.
 * 
 * @param arr The vector of inters to search.
 * @param key The integer value to find.
 * @param len The number of elemets in the vector. 
 * 
 * @return The index of 'key' if found; -1 if not found. 
 */
int binary_search(std::vector<int> arr, int key, int len) {
    int mid, low = 0, high = len - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key >= arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

/**
 * @brief Perform a linear search in an integer vector.
 *
 * This function searches for the specified 'key' in the given 'arr' of integers.
 *
 * @param arr The vector of integers to search.
 * @param key The integer value to find.
 * @param len The number of elements in the vector.
 *
 * @return The index of 'key' if found; -1 if not found.
 */
int linear_search(std::vector<int> arr, int key, int len) {
    for (int i = 0; i < len; i++) {
        if (key == arr[i]) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    std::vector<int> input(10e7);
    std::vector<std::chrono::duration<double, std::micro>> ans1;
    std::vector<std::chrono::duration<double, std::micro>> ans2;

    for (int v = 0; v < 10e7; v++) {
        input[v] = v;
    }

    for (int i = 10; i >= 1; i--) {

        auto start = std::chrono::system_clock::now();
        auto t = linear_search(input, (i * 10e6) - 1, i * 10e6);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;
        ans1.push_back(elapsed_seconds);
    }

    int keys[] = {10203, 70089, 50550, 200, 7650, 5000, 40321, 80000, 1101, 900};

    for (int i = 10; i >= 1; i--) {

        auto start = std::chrono::system_clock::now();
        auto temp = binary_search(input, i*10e6-1, i * 10e6);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> elapsed_seconds = end - start;
        ans2.push_back(elapsed_seconds);
    }

    std::cout << "+-----------+---------------+---------------+" << std::endl;
    std::cout << "|" << std::setw(11) << "Size of"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::setw(15) << "Time taken by"
              << "|" << std::endl
              << "|" << std::setw(11) << "the array"
              << "|" << std::setw(15) << "linear search"
              << "|" << std::setw(15) << "Binary search"
              << "|" << std::endl;
    std::cout << "+-----------+---------------+---------------+" << std::endl;

    for (int i = 1; i <= 10; i++) {
        std::cout << "|" << std::setw(11) << (int)(i * 10e6) << "|"
                  << std::setw(13) << ans1[10 - i].count() << "  |"
                  << std::setw(13) << ans2[10 - i].count() << "  |" << std::endl;

        std::cout << "+-----------+---------------+---------------+" << std::endl;
    }
    return 0;
}