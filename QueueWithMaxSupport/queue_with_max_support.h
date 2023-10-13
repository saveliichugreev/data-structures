//
// Created by savelii on 12/10/2023.
//

#ifndef QUEUE_WITH_MAX_SUPPORT_QUEUE_WITH_MAX_SUPPORT_H

#define QUEUE_WITH_MAX_SUPPORT_QUEUE_WITH_MAX_SUPPORT_H

#include <vector>

template<class T, class Comparator>
class QueueWithMaxSupport {
public:

    QueueWithMaxSupport() {
        compare_ = Comparator{};
    }

    // returns current number of elements in the queue
    std::size_t Size();

    // returns if queue is empty or not
    bool Empty();

    // inserts an element to the back of the queue
    void Push(T elem);

    // removes an element from the front of the queue and returns it
    T Pop();

    // returns the first element of the queue
    T& Front();

    // returns the last element of the queue
    T& Back();

    // returns current max (or min -- depends on the comparator) of the queue
    T& GetMax();

private:
    std::vector<T> stack_to_push_;
    std::vector<T> stack_to_pop_;

    std::vector<T> max_stack_to_push_;
    std::vector<T> max_stack_to_pop_;

    Comparator compare_;

    // moves all the elements from stack_to_push_ to stack_to_pop_ if stack_to_pop_ is empty
    void FillStackToPop_();
};

template<class T, class Comparator>
std::size_t QueueWithMaxSupport<T, Comparator>::Size() {
    // queue size is the sum of stack_to_push_ and stack_to_pop_ sizes
    return stack_to_push_.size() + stack_to_pop_.size();
}

template<class T, class Comparator>
bool QueueWithMaxSupport<T, Comparator>::Empty() {
    // queue is empty if both stack_to_push_ and stack_to_pop_ are empty
    return stack_to_push_.empty() && stack_to_pop_.empty();
}

template<class T, class Comparator>
void QueueWithMaxSupport<T, Comparator>::Push(T elem) {
    stack_to_push_.push_back(elem);
    if (max_stack_to_push_.empty() || compare_(elem, max_stack_to_push_.back())) {
        max_stack_to_push_.emplace_back(elem);
    } else {
        max_stack_to_push_.emplace_back(max_stack_to_push_.back());
    }
}

template<class T, class Comparator>
T QueueWithMaxSupport<T, Comparator>::Pop() {
    // if stack_to_pop_ is empty, we have to move all the elements from stack_to_push_ to it
    if (stack_to_pop_.empty()) {
        FillStackToPop_();
    }

    T back = stack_to_pop_.back();
    stack_to_pop_.pop_back();
    max_stack_to_pop_.pop_back();
    return back;
}

template<class T, class Comparator>
T& QueueWithMaxSupport<T, Comparator>::Front() {
    // if stack_to_pop_ is empty, we have to move all the elements from stack_to_push_ to it
    if (stack_to_pop_.empty()) {
        FillStackToPop_();
    }
    // first element of the queue is the last element of stack_to_pop_
    return stack_to_pop_.back();
}

template<class T, class Comparator>
T& QueueWithMaxSupport<T, Comparator>::Back() {
    // if stack_to_push_ is empty, the last element of the queue is the first element in stack_to_pop_
    if (stack_to_push_.empty()) {
        return stack_to_pop_.front();
    }
    // otherwise, it is the last element of stack_to_push_
    return stack_to_push_.back();
}

template<class T, class Comparator>
void QueueWithMaxSupport<T, Comparator>::FillStackToPop_() {
    while (!stack_to_push_.empty()) {
        T& push_back = stack_to_push_.back();
        if (stack_to_pop_.empty() || compare_(push_back, max_stack_to_pop_.back())) {
            max_stack_to_pop_.emplace_back(push_back);
        } else {
            max_stack_to_pop_.emplace_back(max_stack_to_pop_.back());
        }
        stack_to_pop_.emplace_back(push_back);
        stack_to_push_.pop_back();
        max_stack_to_push_.pop_back();
    }
}

template<class T, class Comparator>
T& QueueWithMaxSupport<T, Comparator>::GetMax() {
    if (max_stack_to_push_.empty() || compare_(max_stack_to_pop_.back(), max_stack_to_push_.back())) {
        return max_stack_to_pop_.back();
    }
    return max_stack_to_push_.back();
}

#endif //QUEUE_WITH_MAX_SUPPORT_QUEUE_WITH_MAX_SUPPORT_H
