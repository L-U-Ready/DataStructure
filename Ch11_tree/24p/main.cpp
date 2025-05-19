// p.24
// 20211542 이유준
#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main() {
    typedef BinaryTree<char> charTree;
    typedef charTree * charTreePtr;

    charTreePtr bt1(new charTree);
    bt1 -> insert('D');

    charTreePtr bt2(new charTree);
    bt2 -> insert('E');

    charTreePtr bt3(new charTree);
    bt3 -> insert('B');
    bt3->makeLeft(bt1);
    bt3->makeRight(bt2);

    charTreePtr bt4(new charTree);
    bt4 -> insert('F');

    charTreePtr bt5(new charTree);
    bt5 -> insert('C');
    bt5->makeRight(bt4);

    charTreePtr bt6(new charTree);
    bt6 -> insert('A');
    bt6->makeLeft(bt3);
    bt6->makeRight(bt5);

    function<void(charTreePtr, int)> print_tree = [&](charTreePtr node, int depth) {
        if (!node || node->isEmpty()) return;
        print_tree(node->right(), depth + 1);
        for (int i = 0; i < depth; ++i) cout << "    ";
        cout << node->getData() << endl;
        print_tree(node->left(), depth + 1);
    };


    cout << "Root contains : " << bt6 -> getData() << endl;

    cout << "Left subTree root : " << bt6 -> left() -> getData() << endl;

    cout << "Right subTree root : " << bt6 -> right() -> getData() << endl;

    cout << "Leftmost child is : " << bt6 -> left() -> left() -> getData() << endl;

    cout << "Rightmost child is : " << bt6 -> right() -> right() -> getData() << endl;

    cout << "\n🗂 트리 구조 (Top-Down 방식):\n";
    print_tree(bt6, 0);

    charTreePtr bt_1(new charTree);
    bt_1->insert('A');

    bt_1->makeLeft(new charTree);
    bt_1->left()->insert('B');

    bt_1->makeRight(new charTree);
    bt_1->right()->insert('C');

    bt_1->left()->makeLeft(new charTree);
    bt_1->left()->left()->insert('D');

    bt_1->left()->makeRight(new charTree);
    bt_1->left()->right()->insert('E');

    bt_1->right()->makeRight(new charTree);
    bt_1->right()->right()->insert('F');

    cout << "Root contains : " << bt_1 -> getData() << endl;
    cout << "Left subTree root : " << bt_1 -> left() -> getData() << endl;
    cout << "Right subTree root : " << bt_1 -> right() -> getData() << endl;
    cout << "Leftmost child is : " << bt_1 -> left() -> left() -> getData() << endl;
    cout << "Rightmost child is : " << bt_1 -> right() -> right() -> getData() << endl;

    cout << "\n🗂 트리 구조 (Top-Down 방식):\n";
    print_tree(bt_1, 0);



    cout << "20211542 이유준";

    return 0;

}