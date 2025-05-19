//
// Created by 이유준 on 2025. 5. 19..
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <assert.h>

template<class btElementType>
class BinaryTree {
public:
    BinaryTree();
    bool isEmpty() const;
    btElementType getData() const;
    void insert(const btElementType & d);
    BinaryTree<btElementType> * left();
    BinaryTree<btElementType>  * right();
    void makeLeft(BinaryTree * T1);
    void makeRight(BinaryTree * T1);
private:
    bool nullTree;
    btElementType treeData;
    BinaryTree * leftTree;
    BinaryTree * rightTree;
};

template<class btElementType>
BinaryTree<btElementType>::BinaryTree() {

    nullTree = true;
    leftTree = 0;
    rightTree = 0;

}

template<class btElementType>
bool BinaryTree<btElementType>::isEmpty() const {
    return nullTree;
}

template<class btElementType>
btElementType BinaryTree<btElementType>::getData() const {
    assert(!isEmpty());
    return treeData;
}

template<class btElementType>
void BinaryTree<btElementType>::insert(const btElementType &d) {

    treeData = d;
    if (nullTree) {
        nullTree = false;
        leftTree = new BinaryTree;
        rightTree = new BinaryTree;
    }
}

template<class btElementType>
BinaryTree<btElementType> * BinaryTree<btElementType>::left() {

    assert(!isEmpty());
    return leftTree;

}

template<class btElementType>
BinaryTree<btElementType> * BinaryTree<btElementType>::right() {

    assert(!isEmpty());
    return rightTree;

}

template<class btElementType>
void BinaryTree<btElementType>::makeLeft(BinaryTree *T1) {
    assert(!isEmpty());
    assert(left() -> isEmpty());
    delete left();
    leftTree = T1;
}

template<class btElementType>
void BinaryTree<btElementType>::makeRight(BinaryTree *T1) {

    assert(!isEmpty());
    assert(right() -> isEmpty());
    delete right();
    rightTree = T1;
}
#endif //BINARYTREE_H
