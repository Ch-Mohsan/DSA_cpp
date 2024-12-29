#include <iostream>
template <class T>
class TreeNode {
public:
    TreeNode() {
        this->data = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(T* data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    T* getInfo() {
        return this->data;
    }
    void setInfo(T* data) {
        this->data = data;
    }
    TreeNode* getLeft() {
        return this->left;
    }
    void setLeft(TreeNode* left) {
        this->left = left;
    }
    TreeNode* getRight() {
        return this->right;
    }
    void setRight(TreeNode* right) {
        this->right = right;
    }
private:
    TreeNode* left;
    TreeNode* right;
    T* data;
};
