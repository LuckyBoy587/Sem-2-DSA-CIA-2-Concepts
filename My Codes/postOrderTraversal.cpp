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

void postOrder(Node *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
    }
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

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;
}