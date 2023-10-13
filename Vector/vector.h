//
// Created by savelii on 13/10/2023.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cassert>
#include <iterator>

template<class T>
class Vector {
private:
    T *begin_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    class Iterator : public std::iterator<std::input_iterator_tag, T> {
        friend class Vector;

    private:
        T *it_;

    public:
        Iterator() : it_(nullptr) {
        }

        Iterator(T *it) : it_(it) {
        }

        bool operator!=(Iterator const &other) const {
            return it_ != other.it_;
        }

        bool operator==(Iterator const &other) const {
            return it_ == other.it_;
        };

        T &operator*() const {
            return *it_;
        }

        Iterator operator++() {
            ++it_;
            return *this;
        }

        Iterator operator--() {
            --it_;
            return *this;
        }

        Iterator operator->() const {
            return *this;
        }
    };

    explicit Vector() : begin_(new T[0]), size_(0), capacity_(0) {
    }

    explicit Vector(size_t n) : begin_(new T[n]), size_(n), capacity_(n) {
        for (size_t i = 0; i < size_; ++i) {
            begin_[i] = 0;
        }
    }

    Iterator begin() {  // NOLINT
        return {&begin_[0]};
    }

    Iterator end() {  // NOLINT
        return {&begin_[size_]};
    }

    Vector(const std::initializer_list<T> &list) : Vector(list.size()) {
        size_t current = 0;
        for (auto &elem: list) {
            begin_[current] = elem;
            ++current;
        }
    }

    ~Vector() {
        delete[] begin_;
    }

    // Конструктор копирования
    Vector(Vector const &other) : begin_(new T[other.size_]), size_(other.size_) {
        for (size_t i = 0; i < size_; ++i) {
            begin_[i] = other.begin_[i];
        }
    }

    Vector(Vector &&other) noexcept {
        if (this != &other) {
            delete[] begin_;
            begin_ = other.begin_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.begin_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
    }

    Vector &operator=(Vector const &other) {
        if (this != &other) {
            Vector(other).Swap(*this);
        }
        return *this;
    }

    T &operator[](const size_t index) {
        assert(index < size_);
        return begin_[index];
    }

    const T &operator[](const size_t index) const {
        assert(index < size_);
        return begin_[index];
    }

    T *Begin() {
        return &begin_[0];
    }

    [[nodiscard]] const T *Begin() const {
        return &begin_[0];
    }

    T *End() {
        return &begin_[size_];
    }

    [[nodiscard]] const T *End() const {
        return &begin_[size_];
    }

    [[nodiscard]] size_t Size() const {
        return size_;
    }

    [[nodiscard]] size_t Capacity() const {
        return capacity_;
    }

    void Swap(Vector &other) {
        size_t const size_tmp = size_;
        size_ = other.size_;
        other.size_ = size_tmp;

        T *const tmp_begin = begin_;
        begin_ = other.begin_;
        other.begin_ = tmp_begin;
    }

    void PushBack(T value) {
        if (size_ < capacity_) {
            ++size_;
            begin_[size_ - 1] = value;
        } else {
            if (capacity_ == 0) {
                ++capacity_;
            }
            T *new_begin = new T[capacity_ * 2];
            for (size_t i = 0; i < size_; ++i) {
                new_begin[i] = begin_[i];
            }
            delete[] begin_;
            begin_ = new_begin;
            capacity_ *= 2;
            ++size_;
            begin_[size_ - 1] = value;
        }
    }

    void PopBack() {
        --size_;
    }

    void Clear() {
        size_ = 0;
    }

    void Reserve(size_t new_size) {
        if (new_size > capacity_) {
            T *new_begin = new T[new_size];
            for (size_t i = 0; i < size_; ++i) {
                new_begin[i] = begin_[i];
            }
            delete[] begin_;
            begin_ = new_begin;
            capacity_ = new_size;
            // buffer_size_ = new_size;
        }
    }
};


#endif //VECTOR_VECTOR_H
