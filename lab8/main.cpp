#include <iostream>

using namespace std;

class FirstBase
{
public:
    int firstBaseVal = 12;
};

class Base
{
public:
    int public_val = 5;

private:
    int private_var = 15;
};

class Child : private Base, FirstBase
{
public:
    int getPublic()
    {
        return public_val;
    }
    void setPublic(int val)
    {
        public_val = val;
    }
    int getPrivate()
    {
        // return private_val;
    }
    void setPrivate(int val)
    {
        // private_val = val;
    }
};

int main()
{
    Child obj = Child();
    cout << obj.getPublic() << endl;

    return 0;
}