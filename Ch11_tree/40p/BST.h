//
// Created by 이유준 on 2025. 5. 19..
//

#ifndef BST_H
#define BST_H
#include "BinaryTree.h"

template<class btElementType>
class BST : public BinaryTree<btElementType> {
public:
    BST();
    void insert(const btElementType & d) override;
    BinaryTree<btElementType> * retrieve(const btElementType & d);
protected:
    using BinaryTree<btElementType>::nullTree;
    using BinaryTree<btElementType>::treeData;
    using BinaryTree<btElementType>::leftTree;
    using BinaryTree<btElementType>::rightTree;
};

template<class btElementType>
BST<btElementType>::BST() {
}

template<class btElementType>
void BST<btElementType>::insert(const btElementType &d) {

    if (nullTree) {
        nullTree = false;
        leftTree = new BST;
        rightTree = new BST;
        treeData = d;
    } else if (d == treeData) {
        treeData = d;
    } else if (d < treeData) {
        leftTree->insert(d);
    } else {
        rightTree->insert(d);
    }
}

// template<class btElementType>
// void BST<btElementType>::insert(const btElementType &d) {
//     if (nullTree) {
//         nullTree = false;
//         leftTree = new BST;
//         rightTree = new BST;
//         treeData = d;
//     } else if (d == treeData) {
//         treeData = d;
//     } else if (d < treeData) {
//         static_cast<BST<btElementType>*>(leftTree)->insert(d);
//     } else {
//         static_cast<BST<btElementType>*>(rightTree)->insert(d);
//     }
// }

template<class btElementType>
BinaryTree<btElementType> * BST<btElementType>::retrieve(const btElementType &d) {
    if (nullTree) {
        return nullptr;
    }
    if (d == treeData) {
        return this;
    } else if (d < treeData) {
        if (!leftTree || leftTree->isEmpty()) return nullptr;
        return ((BST<btElementType>*)leftTree)->retrieve(d);
    } else {
        if (!rightTree || rightTree->isEmpty()) return nullptr;
        return ((BST<btElementType>*)rightTree)->retrieve(d);
    }
}
#endif //BST_H
