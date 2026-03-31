#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <condition_variable>
using namespace std;

// implementing a spin lock using atomic flag 
atomic_flag spinLock = ATOMIC_FLAG_INIT;

void lock() {
    while(!spinLock.test_and_set(memory_order_acquire)) {
        // busy wait
    }
}

void unlock() {
    spinLock.clear(memory_order_release);
}

int main() {

    auto start = chrono::high_resolution_clock::now();




    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}



// condition variables 
// different types of locks 
// deadlock scenarios 
// semaphores 
// object pool threading 
// lock free programming
    // spsc queue
    // mpmc queue
    // spmc queue
    // mpsc queue

