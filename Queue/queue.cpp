//
// Created by savelii on 07/10/2023.
//

#include "queue.h"

std::size_t Queue::Size() {
    return stack_to_push_.size() + stack_to_pop_.size();
}

bool Queue::Empty() {
    return stack_to_push_.empty() && stack_to_pop_.empty();
}

void Queue::Push(int elem) {
    stack_to_push_.push_back(elem);
}

int Queue::Pop() {
    if (stack_to_pop_.empty()) {
        FillStackToPop_();
    }

    int back = stack_to_pop_.back();
    stack_to_pop_.pop_back();
    return back;
}

int Queue::Front() {
    if (stack_to_pop_.empty()) {
        FillStackToPop_();
    }
    return stack_to_pop_.back();
}

int Queue::Back() {
    if (stack_to_push_.empty()) {
        return stack_to_pop_.front();
    }
    return stack_to_push_.back();
}

void Queue::FillStackToPop_() {
    while (!stack_to_push_.empty()) {
        stack_to_pop_.emplace_back(stack_to_push_.back());
        stack_to_push_.pop_back();
    }
}

