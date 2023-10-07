#include <iostream>

#include "queue.h"

int main() {
    Queue q;
    q.Push(1);
    std::cout << q.Front() << '\n';

    q.Push(10);
    q.Push(100);
    std::cout << q.Pop() << '\n';

    std::cout << q.Front() << '\n';
    std::cout << q.Pop() << '\n';
    std::cout << q.Front() << " " << q.Back() << '\n';
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
