#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Find the factorial of an number.
 * 
 * This function uses the recursive approach.
 * 
 * @param n The of that we have to find factorial of.
 * @return The factorial of 'n'.
 */
int factorial_r(int n) {
    if (n <= 1) 
        return 1;
    
    return factorial_r(n - 1) * n;
}

/**
 * @brief Find the factorial of an number.
 * 
 * This function uses the iterative approach.
 *  
 * @param n The of that we have to find factorial of.
 * @return The factorial of 'n'.
 */
int factorial_i(int n) {
    int ans = 1;
    while (n >= 2) {
        ans *= n;
        n--;
    }
    return ans;
}

/**
 * @brief Find the nth number in fibonacci series.
 * 
 * This function uses the recursive approach.
 * 
 * @param n The 'nth' number. 
 * @return The 'nth' fibonacci number.
 */
int fibonacci_r(int n) {
    if (n <= 1) 
        return 1;
    
    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

/**
 * @brief Find the nth number in fibonacci series.
 * 
 * This function uses the iterative approach.
 * 
 * @param n The 'nth' number. 
 * @return The 'nth' fibonacci number.
 */
int fibonacci_i(int n) {
    if(n <= 2)
        return n-1;
    
    int prev = 0;
    int curr = 1;
    int ans;

    for (int i = 3; i <= n; i++) {
        ans = prev + curr;
        prev = curr;
        curr = ans;
    }

    return ans;
}

int main() {
    std::cout<<fibonacci_i(7);
    // std::vector<std::chrono::duration<double, std::nano>> ans;
    // std::vector<std::chrono::duration<double, std::milli>> ans1;

    // for (int i = 20; i > 10; i--) {
    //     auto start = std::chrono::system_clock::now();
    //     auto t = fibonacci_i(i);
    //     auto end = std::chrono::system_clock::now();
    //     std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
    //     ans.push_back(elapsed_seconds);
    // }

    // for (int i = 20; i > 10; i--) {
    //     auto start = std::chrono::system_clock::now();
    //     auto t = fibonacci_r(i);
    //     auto end = std::chrono::system_clock::now();
    //     std::chrono::duration<double, std::milli> elapsed_seconds = end - start;
    //     ans1.push_back(elapsed_seconds);
    // }

    // for (int i = 15; i > 5; i--) {
    //     auto start = std::chrono::system_clock::now();
    //     auto t = factorial_i(i);
    //     auto end = std::chrono::system_clock::now();
    //     std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
    //     ans.push_back(elapsed_seconds);
    // }

    // for (int i = 15; i > 5; i--) {
    //     auto start = std::chrono::system_clock::now();
    //     auto t = factorial_r(i);
    //     auto end = std::chrono::system_clock::now();
    //     std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
    //     ans.push_back(elapsed_seconds);
    // }

    // std::cout << "+----------+---------------+---------------+---------------+---------------+" << std::endl;
    // std::cout << "|" << std::setw(10) << "Number"
    //           << "|" << std::setw(15) << "Iterative"
    //           << "|" << std::setw(15) << "Recursive"
    //           << "|" << std::setw(15) << "Iterative"
    //           << "|" << std::setw(15) << "Recursive"
    //           << "|" << std::endl
    //           << "|" << std::setw(10) << "of inputs"
    //           << "|" << std::setw(15) << "fibonacci"
    //           << "|" << std::setw(15) << "fibonacci"
    //           << "|" << std::setw(15) << "factorial"
    //           << "|" << std::setw(15) << "factorial"
    //           << "|" << std::endl;
    // std::cout << "+----------+---------------+---------------+---------------+---------------+" << std::endl;

    // for (int i = 9; i >= 0; i--) {
    //     std::cout << "|" << std::setw(10) << 40 + (10 - i) << "|"
    //               << std::setw(11) << ans[i].count() << " ns |"
    //               << std::setw(11) << ans1[i].count() << " ms |"
    //               << std::setw(11) << ans[i + 10].count() << " ns |"
    //               << std::setw(11) << ans[i + 20].count() << " ns |" << std::endl;
    //     std::cout << "+----------+---------------+---------------+---------------+---------------+" << std::endl;
    // }

    return 0;
}