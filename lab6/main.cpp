#include <iostream>

using namespace std;

class Person {
public:
    string name;
    int age;
    
    Person() { }
    Person(string name, int age) : name(name), age(age) { }
    // Person(string name, int age) {
    //     this->name = name;
    //     this->age = age;
    // }
    ~Person() { }

    virtual void sayHello() {
        cout << "Person " << this->name << " says hello." << endl;
    }

    virtual void sayHello(Person anotherPerson) {
        cout << "Person " << this->name << "says hello to " << anotherPerson.name << endl;
    }

    bool operator < (Person anotherPerson) {
        return this->age < anotherPerson.age;
    }

    ostream& operator << (ostream& out) {
	    return out << "Person: (" << "Name = " << this->name << ", " << "Age = " << this->age << ")" << endl;
    }
    istream& operator >> (istream& in) {
        cout << "Please input name and age.\n";
        return in >> this->name >> this->age;
    }

};

class Student: Person {
public:
    Student() { }
    Student(string name, int age) : Person(name, age) { }

    bool hasActiveStatus() {
        return true;
    }

    bool isYounger(Student anotherStudent) {
        return this->age < anotherStudent.age;
    }

    void sayHello() override {
        cout << (hasActiveStatus() ? "Student " : "Person ") << this->name << " says hello." << endl;
    }

    void sayHello(Person anotherPerson) override {
        cout << (hasActiveStatus() ? "Student " : "Person ") << this->name << "says hello to " << anotherPerson.name << endl;
    }
    
};

int main() {
    Person bob = Person("bob", 30);
    Person jon = Person("jon", 20);

    cout << (bob < jon ? "jon " : "bob ") << "is older" << endl;
    Student studentBob = Student("bob", 19);
    Student studentJon = Student("jon", 20);
    cout << (studentBob.isYounger(studentJon) ? "bob" : "jon") << "is younger" << endl;
    studentBob.sayHello();
    studentBob.sayHello(jon);

    bob.sayHello();
    bob.sayHello(jon);
    return 0;
}