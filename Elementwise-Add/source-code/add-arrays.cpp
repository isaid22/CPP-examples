#include <iostream>  
#include <chrono>
#include <future>
#include <numeric>

int main() {
    int array_size = 4096;
    int myArray1[array_size]; 
    int myArray2[array_size];
    int myArray3[array_size];
    std::fill_n(myArray1, array_size, 1);
    std::fill_n(myArray2, array_size, 1);
    std::fill_n(myArray3, array_size, 0);

    int i = 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    do {
        myArray3[i] = myArray1[i] + myArray2[i];
        // cout << arr3[i] << "\n";
        i++;
    }
    while (i < array_size);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    
    std::cout << "Adding two integer vector arrays of size: " << array_size << std::endl;
    std::cout << "Elapse time in " << duration << " microseconds " << std::endl;
    
    int j = 0;
    std::cout << "Print some results to show addition is executed..." << std::endl;
    do {
        
        std::cout << myArray3[j];
        j++; 
    }
    while (j < 10);

    return 0;

}