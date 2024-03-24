#include <iostream>

namespace first_namespace {
    void print() {
        std::cout << "I am first namespace" << std::endl;
    }

    int random_number() {
        return rand() % 9 + 1;
    }
}

namespace second_namespace {
    void print() {
        std::cout << "I am second namespace" << std::endl;
    }
    int add(int a, int b) {
        return a + b;
    }
}

namespace third_namespace {
    void print() {
        std::cout << "I am third namespace" << std::endl;
    }
    void print(int result) {
        std::cout << "Result equals " << result << std::endl;
    }
}

int main() {
    first_namespace::print();
    second_namespace::print();
    third_namespace::print();
    third_namespace::print(
        second_namespace::add(
            first_namespace::random_number(), 
            first_namespace::random_number()));
}