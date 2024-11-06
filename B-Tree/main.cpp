// main.cpp
#include "BTree.h"
#include <iostream>

int main() {
    BTree tree(3);  // maxKeys = 3, can adjust as needed

    tree.insert({ "Book A", "Author A", "001" });
    tree.insert({ "Book B", "Author B", "002" });
    tree.insert({ "Book C", "Author C", "003" });

    BTreeNode* result = tree.search("002");
    if (result != nullptr) {
        std::cout << "Book found: " << result->keys[0].title << std::endl;
    }
    else {
        std::cout << "Book not found!" << std::endl;
    }

    return 0;
}