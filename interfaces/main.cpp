#include <iostream>
#include <random>
#include <ctime>
#include <memory>

using namespace std;

class MakesSound {
public:
    virtual void make_sound() const = 0;
    virtual ~MakesSound() { };
};

class Cat : public MakesSound {
public:
    void make_sound() const override {
        cout << "Meow!" << endl;
    }
};

class Dog : public MakesSound {
public:
    void make_sound() const override {
        cout << "Woof!" << endl;
    }
};

class Fox : public MakesSound {
public:
    void make_sound() const override {
        cout << "Ring-ding-ding-ding-dingeringeding!" << endl;
    }
};

class Cow : public MakesSound {
    public:
    void make_sound() const override {
        cout << "Mooo!" << endl;
    }
};

int main() {
    srand(time(nullptr));

    vector<unique_ptr<MakesSound>> bought_animals;

    for (int i = 0; i < 10; i++) {
        int random = rand() % 3 + 1;
        switch (random) {
            case 1:
                bought_animals.push_back( make_unique<Cat>());
                break;
            case 2:
                bought_animals.push_back(make_unique<Dog>());
                break;
            case 3:
                bought_animals.push_back(make_unique<Fox>());
                break;
        }
    }

    for (const auto& animal : bought_animals) {
        animal->make_sound();
    }

    return 0;
}
