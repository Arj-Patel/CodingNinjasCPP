#include<iostream>
using namespace std;

class Increment
{

    int num;

public:
    Increment(int n)
    {
        num = n;
    }
    Increment(){}

    // Pre-increment operator
    Increment& operator++()
    {
        num++;
        return *this;
    }   
    
    // post-increment operator
    Increment operator++(int){
        Increment n;
        n.num = this->num + 1;
        return n.num;
    }

    Increment& operator+=(Increment const &i){
        this->num = i.num + this->num;
        return *this;
    }

    void print() const
    {
        cout << num << endl;
    }
};