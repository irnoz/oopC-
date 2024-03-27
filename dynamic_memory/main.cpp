#include <iostream>
#include <algorithm>

using namespace std;

class Integer {
    int* value = nullptr;
public: 
    Integer() { }
    Integer(int value) {
        this->value = new int (value);
        // cout << "dynamic memory: " << &this->value << endl;
    }
    ~Integer() {
        delete value;
    }

    int getValue() {
        return *value;
    }
    void setValue(int newValue) {
        this->value = new int (newValue);
    }
};

void print(Integer ** arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << (*(arr + i))->getValue() << " ";
    } cout << endl;
}

int main() {
	Integer ** arr = new Integer* [10];

    for (int i = 0; i < 10; i++) {
        *(arr + i) = new Integer(rand() % 20 + 1);
    }

    print(arr, 10);

    sort(arr, arr + 10, [] (Integer* a, Integer* b) { return a->getValue() < b->getValue(); });

    print(arr, 10);

}
