#include <vector>
using namespace std;

template <typename T>
class treeNode
{

public:
    T data;
    vector<treeNode<T> *> children; // If we just write vector<treeNode*> children then the compiler would
                                    //  automatically ajjume treeNode* would point to nodes with integer data.

    treeNode(T data)
    {
        this->data = data;
    }
};