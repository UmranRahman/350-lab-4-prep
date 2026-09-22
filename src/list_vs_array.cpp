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
    std::list<uint64_t> test_list;
    std::mt19937_64 rng(0); // initialize with seed of 0 
    Timer t;

    for (size_t i = 0; i < SIZE; i++) {
        test_list.push_back(rng()); // next is now the next generated random number
    }
    uint64_t elapsed = t.click<Timer::Micros>();
    std::cout << "Inserting in list" << elapsed << " microseconds\n";


    return 0;
}
