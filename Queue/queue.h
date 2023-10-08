//
// Created by savelii on 07/10/2023.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

template<class T>
class Queue {
public:

    // returns current number of elements in the queue
    std::size_t Size();

    // returns if queue is empty or not
    bool Empty();

    // inserts an element to the back of the queue
    void Push(T elem);

    // removes an element from the front of the queue and returns it
    T Pop();

    // returns the first element of the queue
    T Front();

    // returns the last element of the queue
    T Back();

private:
    std::vector<T> stack_to_push_;
    std::vector<T> stack_to_pop_;

    // moves all the elements from stack_to_push_ to stack_to_pop_ if stack_to_pop_ is empty
    void FillStackToPop_();
};

template<class T>
std::size_t Queue<T>::Size() {
    // queue size is the sum of stack_to_push_ and stack_to_pop_ sizes
    return stack_to_push_.size() + stack_to_pop_.size();
}

template<class T>
bool Queue<T>::Empty() {
    // queue is empty if both stack_to_push_ and stack_to_pop_ are empty
    return stack_to_push_.empty() && stack_to_pop_.empty();
}

template<class T>
void Queue<T>::Push(T elem) {
    stack_to_push_.push_back(elem);
}

template<class T>
T Queue<T>::Pop() {
    // if stack_to_pop_ is empty, we have to move all the elements from stack_to_push_ to it
    if (stack_to_pop_.empty()) {
        FillStackToPop_();
    }

    T back = stack_to_pop_.back();
    stack_to_pop_.pop_back();
    return back;
}

template<class T>
T Queue<T>::Front() {
    // if stack_to_pop_ is empty, we have to move all the elements from stack_to_push_ to it
    if (stack_to_pop_.empty()) {
        FillStackToPop_();
    }
    // first element of the queue is the last element of stack_to_pop_
    return stack_to_pop_.back();
}

template<class T>
T Queue<T>::Back() {
    // if stack_to_push_ is empty, the last element of the queue is the first element in stack_to_pop_
    if (stack_to_push_.empty()) {
        return stack_to_pop_.front();
    }
    // otherwise, it is the last element of stack_to_push_
    return stack_to_push_.back();
}

template<class T>
void Queue<T>::FillStackToPop_() {
    while (!stack_to_push_.empty()) {
        stack_to_pop_.emplace_back(stack_to_push_.back());
        stack_to_push_.pop_back();
    }
}

#endif //QUEUE_H
