#include<iostream>
#include<fstream>
using namespace std;

int main() {
    vector<int> vec = {1,2,3,4,5,6,7};
    ofstream ofs("bls.txt");
    for (const auto & el: vec) {
        ofs << el << " ";
    }
    return 0;
}