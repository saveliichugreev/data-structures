#include <iostream>
#include "heap.h"
#include <string>

struct MinComparator {
    bool operator()(int32_t &a, int32_t &b) const {
        return a < b;
    }
};

struct MaxComparator {
    bool operator()(size_t &a, size_t &b) const {
        return a > b;
    }
};

struct Point {
    int x;
    int y;
};

struct PointComparator {
    bool operator()(Point &a, Point &b) const {
        return a.x > b.x;
    }
};

int main() {
    // test heap
    Heap<MinComparator, int> heap(10);

    for (auto el : {44, 17, 48, 43,  8,  6, 22, 19,  2, 26}) {
        heap.Insert(el);
    }

    std::cout << "heap: " << heap << '\n';

    heap.Insert(1);
    heap.ExtractTop();
    heap.ExtractTop();
    heap.Insert(23);
    heap.Insert(0);

    std::cout << heap << '\n';

    // test heap based on vector
    std::vector<size_t> vector = {44, 17, 48, 43,  8,  6, 22, 19,  2, 26};
    Heap<MaxComparator, size_t> heap_on_vec(vector);

    std::cout << "heap_on_vec: " << heap_on_vec << '\n';

    heap_on_vec.Insert(1);
    heap_on_vec.ExtractTop();
    heap_on_vec.ExtractTop();
    heap_on_vec.Insert(23);
    heap_on_vec.Insert(0);

    std::cout << heap_on_vec << '\n';

    Heap<PointComparator, Point> hp(1);

    hp.Insert({1, 2});
    auto p = hp.ExtractTop();
    std::cout << "Top point: " << p.x << " " << p.y << '\n';

    return 0;
}
