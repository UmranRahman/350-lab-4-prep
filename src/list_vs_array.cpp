#include <cstddef>  // size_t

#include "timer.h"

#include <iostream>
#include <list>
#include <vector>
#include <random>
#include <string>


constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    //list
    std::list<uint64_t> test_list;
    std::mt19937_64 rng(0); // initialize with seed of 0 
    Timer t;

    for (size_t i = 0; i < SIZE; i++) {
        test_list.push_back(rng()); // next is now the next generated random number
    }
    uint64_t elapsed = t.click<Timer::Micros>();
    std::cout << "Inserting in list: " << elapsed << " microseconds\n";

    //vector - no reserve
    std::vector<uint64_t> test_vector;
    rng.seed(0); // re-initialize with seed of 0 
    t.restart();

    for (size_t i = 0; i < SIZE; i++) {
        test_vector.push_back(rng());
    }
    uint64_t elapsed2 = t.click<Timer::Micros>();
    std::cout << "Inserting in vector (no reserve): " << elapsed2 << " microseconds\n";

    //test vector 2
    std::vector<uint64_t> test_vector_reserved;
    test_vector_reserved.reserve(SIZE);
    rng.seed(0); // re-initialize with seed of 0 
    t.restart();

    for (size_t i = 0; i < SIZE; i++) {
        test_vector_reserved.push_back(rng());
    }
    uint64_t elapsed3 = t.click<Timer::Micros>();
    std::cout << "Inserting in vector (reserve): " << elapsed3 << " microseconds\n";

    return 0;
}
