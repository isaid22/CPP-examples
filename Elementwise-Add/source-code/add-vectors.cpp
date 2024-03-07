#include <iostream>     // std::cout, std::endl
#include <chrono>
#include <future>
#include <numeric>      // std::accumulate
#include <thread>
#include <vector>

using namespace std;

// void f() {
//   // use this to verify printed time
//   std::this_thread::sleep_for(std::chrono::seconds(1));
// }

int main() {
    // create a vector with n integer elements of value 1
    int array_size = 4096;
    std::vector<int> arr1(array_size, 1);
    std::vector<int> arr2(array_size, 1);
    std::vector<int> arr3(array_size, 1);
    int i = 0;

    auto t1 = std::chrono::high_resolution_clock::now();

    do {
        arr3[i] = arr1[i] + arr2[i];
        // cout << arr3[i] << "\n";
        i++;
    }
    while (i < arr1.size());

    // f();

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    
    std::cout << "Adding two integer vector arrays of size: " << array_size << std::endl;
    std::cout << "Elapse time in " << duration << " microseconds " << std::endl;
    
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

    std::cout << "Elapse time in " << duration_ms << " milliseconds " << std::endl;

    return 0;
}