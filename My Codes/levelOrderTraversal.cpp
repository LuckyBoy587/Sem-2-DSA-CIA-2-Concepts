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

void levelOrder(Node *root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        for (int i=0; i<len; i++) {
            Node *curr = q.front();
            cout << curr->data << ' ';
            q.pop();

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
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

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;
}