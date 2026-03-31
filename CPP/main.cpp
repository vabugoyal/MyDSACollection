#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <condition_variable>
using namespace std;













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

