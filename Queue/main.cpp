#include <iostream>

#include "queue.h"

int main() {
    Queue<int64_t> q;

    for (int i = 0; i < 10; ++i) {
        q.Push(i);
    }
    std::cout << q.Front() << '\n'; // 0
    std::cout << q.Back() << '\n'; // 9
    std::cout << q.Size() << '\n'; // 10

    while (!q.Empty()) {
        std::cout << q.Pop() << " popped!\n"; // 0..9
    }

    std::cout << q.Empty() << '\n'; // true
    std::cout << q.Size() << '\n'; // 0

    q.Push(10);
    std::cout << q.Front() << '\n'; // 10
    std::cout << q.Back() << '\n'; // 10
    std::cout << q.Size() << '\n'; // 1

    std::cout << q.Pop() << " popped!\n"; // 10
    std::cout << q.Empty(); // true
    return 0;
}
