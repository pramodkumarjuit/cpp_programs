//
// ++ -std=c++11 promise_future.cpp -lpthread
//
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// Function that will be executed in a separate thread
void computeValue(std::promise<int>&& promise) {
    // Simulate some computation
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // Set the value in the promise
    int result = 42; // Example result
    promise.set_value(result);
}

int main() {
    // Create a promise to store the result
    std::promise<int> promise;

    // Get the future associated with the promise
    std::future<int> future = promise.get_future();

    // Create a thread and pass the promise to it
    std::thread worker(computeValue, std::move(promise));

    // Do some other work in the main thread
    std::cout << "Main thread is doing some other work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));

    // Wait for the result from the future.
    // locks the main thread until the result is available in the future.
    int result = future.get();

    // Print the result
    std::cout << "Result from the thread: " << result << std::endl;

    // Join the thread to ensure it completes
    worker.join();

    return 0;
}
