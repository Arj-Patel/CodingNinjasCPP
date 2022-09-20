#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // vector<int>* vp = new vector<int>(); //dynamic allocation of vector.
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    v.pop_back();

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    cout << "size " << v.size() << endl;

    return 0;
}