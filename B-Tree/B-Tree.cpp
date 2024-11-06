// BTree.cpp
#include "BTree.h"
#include <iostream>

BTreeNode::BTreeNode(int maxKeys, bool isLeaf)
    : maxKeys(maxKeys), isLeaf(isLeaf) {
    keys.resize(0);
    children.resize(maxKeys + 1, nullptr);
}

void BTree::insert(const Book& book) {
    if (!root) {
        root = new BTreeNode(maxKeys, true);
        root->keys.push_back(book);
    }
    else {
        if (root->keys.size() == maxKeys) {
            BTreeNode* newRoot = new BTreeNode(maxKeys, false);
            newRoot->children[0] = root;
            newRoot->splitChild(0, root);
            int i = (newRoot->keys[0].isbn < book.isbn) ? 1 : 0;
            newRoot->children[i]->insertNonFull(book);
            root = newRoot;
        }
        else {
            root->insertNonFull(book);
        }
    }
}

void BTreeNode::insertNonFull(const Book& book) {
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
}

BTreeNode* BTreeNode::search(const std::string& isbn) {
}


BTreeNode* BTree::search(const std::string& isbn) {
    return (root == nullptr) ? nullptr : root->search(isbn);
}

