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

Node* findMinNode(Node* node) {
    while (node->left!= nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        } else if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        } else {
            Node* minNode = findMinNode(root->right);
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }
    }

    return root;
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
}