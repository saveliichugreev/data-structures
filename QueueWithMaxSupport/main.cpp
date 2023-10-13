#include <iostream>
#include <vector>
#include <string>
#include "queue_with_max_support.h"

struct MaxComparator{
    bool operator()(int& a, int& b) const {
        return a > b;
    }
};

int main() {
    QueueWithMaxSupport<int, MaxComparator> q;
    std::vector<int> elems = {2, 12, 85, 0, 6, -2, 17, 76, 14, 1, 67};
    for (int el : elems) {
        q.Push(el);
    }


    std::cout << q.Empty() << '\n';
    std::cout << q.Pop() << '\n';
    std::cout << q.GetMax() << '\n';

    return 0;
}
