#include <iostream>
#include <vector>
#include <sys/time.h>
#include <iomanip>

using namespace std;

const int N = 100000000;

void populate_vector(vector<int>&random_values) {
    for (int i = 0; i < N; i++) {
        int random_number = rand();
        random_values.push_back(random_number);
    }
}

void print_vector(vector<int>&random_values) {
    cout << "random array:" << endl;
    for (auto num : random_values) {
        cout<< num << " ";
    }
    cout << endl;
}

// brute force search algorithm using for loop
// time complexity: O(2n) -> O(n)
bool search_target_with_for_loop(vector<int>& random_values, int target_value) {
    for(int i = 0; i < random_values.size(); i++) {
        if (random_values[i] == target_value) {
            return true;
        }
    }
    return false;
}

// buffer search algorithm using while loop (almost twice as fast as brute force search)
// time complexity: O(n) -> O(n)
bool search_target_with_while_loop(vector<int>& random_values, int target_value, int idx = 0) {
    random_values.push_back(target_value); // not nececary in general imlementation
    while (random_values[idx] != target_value) { idx++; }
    return idx != random_values.size() - 1;
}

void start_timer(timeval& start, timeval& end) {
    // start timer.
    gettimeofday(&start, NULL);
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
}

double stop_timer(timeval& start, timeval& end) {
    // stop timer.
    gettimeofday(&end, NULL);
 
    // Calculating total time taken by the program.
    double time_taken;
 
    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;

    return time_taken;
}

int main() {
    struct timeval start, end;
    vector<int> random_values;
    int target_value = rand();
    cout << "target: " << target_value << endl;
    populate_vector(random_values);
    // print_vector(random_values);

    // MARK: - (Homework) try to export two modules below in a single function
    start_timer(start, end);
    cout << (search_target_with_for_loop(random_values, target_value) ? "target found in the array with for loop" : "target not found in the array with for loop") << endl; 
    cout << "Time taken by brute force search with for loop is : " << fixed << stop_timer(start, end) << setprecision(6) << " sec" << endl;

    start_timer(start, end);
    cout << (search_target_with_while_loop(random_values, target_value) ? "target found in the array with while loop" : "target not found in the array with while loop") << endl; 
    cout << "Time taken by buffer search with while loop is : " << fixed << stop_timer(start, end) << setprecision(6) << " sec" << endl;
}
// MARK: - (Output examples)

// target: 16807
// target not found in the array with for loop
// Time taken by brute force search with for loop is : 0.400511 sec
// target not found in the array with while loop
// Time taken by buffer search with while loop is : 0.227150 sec

// target: 16807
// target not found in the array with for loop
// Time taken by brute force search with for loop is : 0.425890 sec
// target not found in the array with while loop
// Time taken by buffer search with while loop is : 0.231813 sec
