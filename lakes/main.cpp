#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class Lake
{
	friend ostream & operator <<(ostream &, const Lake &);
	friend istream & operator >> (istream &, Lake &);
public:
	Lake() = default;
	~Lake() = default;
	friend bool operator > (const Lake&, const Lake&); 
private:
	string name;
	double area, depth;
};
istream & operator >> (istream & in, Lake & m) {
	return in >> m.name >> m.area >> m.depth;
}
ostream & operator <<(ostream & out, const Lake & t) {
	return out << "Name is " << t.name << " , Area is " << t.area
		     << ", Depth is " << t.depth << endl;
}
bool operator > (const Lake& l1, const Lake& l2) {
	return l2.area > l1.area;
}
int fillLakes(Lake *x)
{
	ifstream read("data/Lakes.txt");
	int i{};
	while (read >> x[i]) i++;
	return i;
}
void printLakes(Lake * x, int& size) 
{
	ofstream write("sorted Lakes.txt");
	write << "Some Georgia Lakes are:\n\n";
	cout << "Some Georgia Lakes are:\n\n";
	for (int k = 0; k < size; k++) {
		cout << x[k];
		write << x[k];
	}
}
int main()
{
	int N = 30;
	Lake * LakesArray;
	LakesArray = new (nothrow)Lake[N];
	int size = fillLakes(LakesArray);
	sort(LakesArray, LakesArray + size, [&] (const Lake & l1, const Lake & l2 ) { 
        return l1 > l2;
    });
	printLakes(LakesArray, size);
	delete[] LakesArray;
	LakesArray = nullptr;
}
