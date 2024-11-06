// BTree.h
#ifndef BTREE_H
#define BTREE_H

#include <vector>
#include <string>




struct Book {
    std::string title;
    std::string author;
    std::string isbn;
};

class BTreeNode {
public:
    BTreeNode(int maxKeys, bool isLeaf);
    void insertNonFull(const Book& book);
    void splitChild(int i, BTreeNode* y);
    BTreeNode* search(const std::string& isbn);

    bool isLeaf;
    int maxKeys;
    std::vector<Book> keys;
    std::vector<BTreeNode*> children;
};

class BTree {
public:
    BTree(int maxKeys);
    void insert(const Book& book);
    BTreeNode* search(const std::string& isbn);

    BTreeNode* root;
    int maxKeys;
};

#endif
