#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node (int x) {
        this->val = x;
        this->left = this->right = NULL;
    }
};

struct Bst {
    Node *root;

    Bst () {
        this->root = NULL;
    }

    Node *add (Node *current, int x) {
        if (current == NULL) {
            current = new Node(x);
        }
        else if (current->val == x) {
            return current;
        }
        else if (current->val > x) {
            if (current->left == NULL)
                current->left = add(current->left, x);
            else
                add(current->left, x);
        }
        else {
            if (current->right == NULL)
                current->right = add(current->right, x);
            else
                add(current->right, x);
        }
        return current;
    }

    Node *search (Node *current, int x) {
        if (current == NULL)
            return NULL;
        if (current->val == x)
            return current;
        else if (current->val > x)
            return search(current->left, x);
        else if (current->val < x)
            return search(current->right, x);
    }

    void print(Node *current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

    int height(Node *current, int& diameter) {
        if (current == NULL)
            return 0;
        int lH = height(current->left, diameter);
        int rH = height(current->right, diameter);
        diameter = max(diameter, lH + rH);
        return 1 + max(lH, rH);
    }

    int getPath(Node *root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

int main() {
    int n; cin >> n;
    Bst *B = new Bst();
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if (B->root == NULL)
            B->root = B->add(B->root, a);
        else
            B->add(B->root, a);
    }
    cout << B->getPath(B->root) + 1;
}