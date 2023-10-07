//
// Created by savelii on 07/10/2023.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

class Queue {
public:

    // returns current number of elements in queue
    std::size_t Size();

    bool Empty();

    void Push(int elem);

    int Pop();

    int Front();

    int Back();

private:
    std::vector<int> stack_to_push_;
    std::vector<int> stack_to_pop_;

    void FillStackToPop_();
};

#endif //QUEUE_H
