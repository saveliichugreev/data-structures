#include <iostream>
#include <string>
#include "vector.h"

int main() {
    Vector vector = {1, 3, 10, 15};
    std::cout << vector.Capacity() << '\n';
    vector.PushBack(239);
    std::cout << *vector.End() << '\n';
    std::cout << vector.Capacity() << '\n';
    std::cout << vector[vector.Size() - 1] << "\n\n";

    Vector<std::string> str_vec;
    str_vec.PushBack("aba");
    str_vec.PushBack("trash");
    str_vec.PushBack("cringe");
    std::cout << str_vec.Size() << '\n';
    std::cout << str_vec[1] << '\n';
    str_vec.PopBack();
    std::cout << str_vec.Size();
    return 0;
}
