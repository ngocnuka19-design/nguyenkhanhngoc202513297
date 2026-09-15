#include <iostream>
#include <chrono>

int main() {
    // Start clock
    auto start = std::chrono::high_resolution_clock::now();

    // --- YOUR CODE HERE ---
    for (int i = 0; i < 1000000; ++i) {
        // Simple loop test
    }
    // ----------------------

    // Stop clock
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "\n[Execution Time: " << duration.count() << " ms]" << std::endl;
    return 0;
}