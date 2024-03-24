#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector> 
#include <iomanip>
#include <functional>

using namespace std;

const int N = 9;
// #define size 18

class Mountain {
private: 
    string name;
    int height;
    static int object_count;
public: 
    Mountain() { object_count++; }
    Mountain(ifstream & fin) {
        fin >> name >> height;
        object_count++;
    }

    string get_name() {
        return name;
    }

    int get_height() {
        return height;
    }

    void print_data() {
        cout << "Mountain data:" << setw(15)
            << " Name = " << name << "\t"
            << " heihgt = " << height << endl;
    }

    int get_object_count() {
        return object_count;
    }
};

int Mountain::object_count = 0;

void output_data_to_file(vector<Mountain> mountains) {
    ofstream fout("sorted_data.txt");
    fout << "mountains data sorted in ascending order" << endl;
    for (auto mountain: mountains) {
        fout << "Name: " << mountain.get_name() << ", Heihgt: " << mountain.get_height() << endl;
    }
}

// 1 3 4
void my_sort_pointer(vector<Mountain> & mountains, bool (func(Mountain &, Mountain &))) {
    for (int i = 0; i < mountains.size(); i++) {
        for (int j = i + 1; j < mountains.size(); j++) {
            if (func(mountains[i], mountains[j])) {
                swap(mountains[i], mountains[j]);
            }
        }
    }
}
void my_sort(vector<Mountain> & mountains, function<bool(Mountain &, Mountain &)> func) {
    for (int i = 0; i < mountains.size(); i++) {
        for (int j = i + 1; j < mountains.size(); j++) {
            if (func(mountains[i], mountains[j])) {
                swap(mountains[i], mountains[j]);
            }
        }
    }
}
bool compare(Mountain & first_mountain, Mountain & second_mountain) {
    return first_mountain.get_height() > second_mountain.get_height();
}

int main() {
    ifstream fin("data.txt");

    vector<Mountain> mountains;
    for (int i = 0; i < N; i++) {
        Mountain mountain(fin);
        mountains.push_back(mountain);
    }
    string objects = "";
    cout <<  objects  << endl;

    // sort(mountains.begin(), mountains.end(), [&] (Mountain first_mountain, Mountain second_mountain) {
    //     return first_mountain.get_height() < second_mountain.get_height();
    // });

    // my_sort(mountains, [] (Mountain first_mountain, Mountain second_mountain) { 
    //     return  first_mountain.get_height() > second_mountain.get_height();
    // });

    my_sort_pointer(mountains, &compare);

    for (Mountain mountain: mountains) {
        mountain.print_data();
    }

    output_data_to_file(mountains);

    return 0;
}