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

bool isComplete(Node *root) {
    queue<Node*> q;
    q.push(root);
    bool lastLevel = false;
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

        if (curr->left != nullptr) {
            if (lastLevel) return false;
            q.push(curr->left);
        } else {
            lastLevel = true;
        }

        if (curr->right != nullptr) {
            if (lastLevel) return false;
            q.push(curr->right);
        } else {
            lastLevel = true;
        }
    }

    return true;
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

    if (isComplete(root)) {
        cout << "Tree is Complete";
    } else {
        cout << "Tree is not Complete";
    }
}