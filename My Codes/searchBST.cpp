#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node *root, int data) {
    if (data < root->data) {
        if (root->left == nullptr) root->left = new Node(data);
        else insert(root->left, data);
    } else {
        if (root->right == nullptr) root->right = new Node(data);
        else insert(root->right, data);
    }
}

bool search(Node *root, int data) {
    if (root == nullptr) return false;
    if (root->data == data) return true;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

int main(){
    int size;
    cin >> size;

    Node *root = nullptr;
    for (int i=0; i<size; i++) {
        int num;
        cin >> num;
        if (root == nullptr) root = new Node(num);
        else insert(root, num);
    }

    int target;
    cin >> target;

    if (search(root, target)) {
        cout << target << " is found in the tree";
    } else {
        cout << target << " is not found in the tree";
    }
}