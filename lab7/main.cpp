#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class book
{
  protected:
	string bookName, authorName;
	int pages, pubYear;
  public:
	book(string bn, string an, int = 1025, int = 2022);
	~book() = default;
	void set_year(int y);
	int get_pages()const;
	void printBook()const;
};
class library_card : public book
{
	string catalogID;
	bool borrowing;
  public:
	library_card(string bn,string an, int = 1025, int = 2022, 
string = "150CPP", bool = false);
	~library_card() = default;
	void set_pages(int p);
	void set_catalogID(string id);
	void set_borrowing(bool b);
void printCard()const;	
};
book::book(string bn, string an, int pp , int y)
{
	bookName = bn, authorName = an, pages = pp, pubYear = y;
}
library_card::library_card(string bn, string an, int pp, int y, string id, bool st)
		: book(bn, an, pp, y), catalogID(id), borrowing(st){ }
void book::set_year(int y){ 
     pubYear = y; 
}
int book::get_pages()const {
	return pages;
}
void book::printBook()const{
	cout << bookName << ' ' << authorName << ' ' << pages << ' ' 
           << pubYear << endl;
}
void library_card::set_pages(int p) {
	pages = p;
}
void library_card::set_catalogID(string id) {
	catalogID = id;
}
void library_card::set_borrowing(bool b) {
	borrowing = b;
}
void library_card::printCard()const{
	printBook();
	cout << catalogID << ' ' << boolalpha << borrowing << endl;
}
int main()
{
    ofstream ofs ("bla");
    ofs << "wazaaaap";
}