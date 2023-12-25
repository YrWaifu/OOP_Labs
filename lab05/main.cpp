#include "./include/allocator.hpp"
#include "./include/myqueue.hpp"

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    std::map<int, int, std::less<>, MyAllocator<std::pair<const int, int>, 1000>> myMap;

    for (int i = 0; i < 10; ++i) {
        myMap.emplace(i, factorial(i));
    }

    for (const auto& pair : myMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    MyQueue<int, 1000, MyAllocator<int, 1000>> myQueue;

    for (int i = 0; i < 10; ++i) {
        myQueue.enqueue(i);
    }

    for (const auto& element : myQueue) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    int searchValue = 5;
    std::cout << "Queue contains " << searchValue << ": " << (myQueue.contains(searchValue) ? "Yes" : "No")
              << std::endl;

    return 0;
}