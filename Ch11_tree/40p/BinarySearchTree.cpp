// p.40
// 20211542 이유준

// #include "BinaryTree.h"
#include "BST.h"
#include <iostream>
using namespace std;

int main() {

    typedef BST<int> intBST;
    typedef intBST * intBSTPtr;

    intBSTPtr b(new intBST);

    b->insert(17);
    b->insert(10);
    b->insert(26);
    b->insert(6);
    b->insert(14);
    b->insert(20);
    b->insert(28);
    b->insert(11);
    b->insert(31);
    b->insert(37);
    b->insert(12);

    intBSTPtr get11((BST<int>*)b->retrieve(11));
    if (get11 == nullptr || get11->isEmpty()) {
        cout << "11 not found" << endl;
    } else {
        cout << "11 found" << endl;
    }

    intBSTPtr get13((BST<int>*)b->retrieve(13));
    if (get13 == nullptr || get13->isEmpty()) {
        cout << "13 not found" << endl;
    } else {
        cout << "13 found" << endl;
    }


}