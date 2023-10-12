//
// Created by savelii on 09/10/2023.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>


template<class Comparator, class T>
class Heap {
public:
    explicit Heap(size_t heap_size) {
        compare_ = Comparator{};
        heap_vec_.reserve(heap_size + 1);
        heap_vec_.emplace_back(T{});
    }

    explicit Heap(std::vector<T> &vector) {
        heap_vec_.reserve(vector.size() + 1);
        heap_vec_.emplace_back(T{});
        for (T &i: vector) {
            heap_vec_.emplace_back(i);
        }
        BuildHeapFromVector();
    }

    friend std::ostream &operator<<(std::ostream &out, const Heap &heap) {
        for (auto el = ++heap.heap_vec_.begin(); el != heap.heap_vec_.end(); ++el) {
            out << *el << " ";
        }
        return out;
    }

    void Insert(T number);

    T ExtractTop();

    T Top();

    void DeleteElem(size_t inx);

    void BuildHeapFromVector();

private:
    std::vector<T> heap_vec_;
    Comparator compare_;

    void SiftDown_(size_t inx = 1);

    void SiftUp_(size_t inx);
};

template<class Comparator, class T>
void Heap<Comparator, T>::Insert(T number) {
    heap_vec_.emplace_back(number);
    SiftUp_(heap_vec_.size() - 1);
}

template<class Comparator, class T>
T Heap<Comparator, T>::ExtractTop() {
    T top = heap_vec_[1];
    heap_vec_[1] = heap_vec_.back();
    heap_vec_.pop_back();
    SiftDown_();
    return top;
}

template<class Comparator, class T>
T Heap<Comparator, T>::Top() {
    return heap_vec_[1];
}

template<class Comparator, class T>
void Heap<Comparator, T>::SiftDown_(size_t inx) {
    while (inx << 1 < heap_vec_.size()) {
        size_t son_to_compare = 0;
        if ((inx << 1) + 1 == heap_vec_.size()) {
            son_to_compare = inx << 1;
        } else {
            son_to_compare = compare_(heap_vec_[inx << 1],
                                      heap_vec_[(inx << 1) + 1]) ? inx << 1 : (inx << 1) + 1;
        }
        if (!compare_(heap_vec_[son_to_compare], heap_vec_[inx])) {
            break;
        }
        std::swap(heap_vec_[inx], heap_vec_[son_to_compare]);
        inx = son_to_compare;
    }
}

template<class Comparator, class T>
void Heap<Comparator, T>::SiftUp_(size_t inx) {
    while (inx >> 1 > 0 && compare_(heap_vec_[inx], heap_vec_[inx >> 1])) {
        std::swap(heap_vec_[inx], heap_vec_[inx >> 1]);
        inx >>= 1;
    }
}

template<class Comparator, class T>
void Heap<Comparator, T>::DeleteElem(size_t inx) {
    std::swap(heap_vec_[inx], heap_vec_[heap_vec_.size() - 1]);
    heap_vec_.pop_back();
    if (compare_(heap_vec_[inx], heap_vec_[inx >> 1])) {
        SiftUp_(inx);
    } else {
        SiftDown_(inx);
    }
}

template<class Comparator, class T>
void Heap<Comparator, T>::BuildHeapFromVector() {
    for (auto i = static_cast<int32_t>(heap_vec_.size() >> 1) - 1; i > 0; --i) {
        SiftDown_(i);
    }
}

#endif //HEAP_HEAP_H
