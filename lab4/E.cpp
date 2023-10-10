#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    int cnt;
    Node(int val){
        this -> val = val;
        this -> left = this -> right = nullptr;
        cnt = 1;
    }
};

class BST{
private:
    Node* root;

    Node* push(Node* cur, int val){
        if (!cur) return new Node(val);

        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);

        return cur;
    }

    Node* find(Node* cur, int tar){
        if(!cur) return nullptr;
        else if(cur -> val == tar) return cur;
        else if (cur -> val > tar) return find(cur -> left, tar);
        else if (cur -> val < tar) return  find(cur -> right, tar);
    }

    void preOrder(Node* cur){
        if(cur){
            int sum = 0;
            
            preOrder(cur -> left);
            preOrder(cur -> right);
           
        }
    }
    void sol(Node* cur){
        vector<int> v;
        if (!cur) return;
        queue<Node*> q;
        q.push(cur);
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            for(int i = 0; i < sz; i++){
                Node* temp = q.front();
                q.pop();
                if (temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);
                sum += temp -> val;
            }
            v.push_back(sum);
        }
        cout << v.size() << endl;
        for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    }

    int size(Node* cur){
        if (!cur) return 0;
        else return size(cur->left)+size(cur->right)+1;
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void find(int val){
        if(find(root, val)){
            root = find(root, val);
        }
    }

    void size(){
        cout << size(root);
    }
    void preOrder(){
        preOrder(root);
    }
    void sol(){
        sol(root);
    }

};

int main(){
    BST tree;
    int n#include <iostream>

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

Node *search (Node *root, int x) {
    if (root == NULL)
        return NULL;
    if (root->val == x)
        return root;
    Node *found = search(root->left, x);
    if (found == NULL)
    found = search(root->right, x);
    return found;
}

int getHeight (Node *root) {
    if (root == NULL)
        return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}

int getWidth (Node *root, int level) {
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else {
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    }
}

int getMaxWidth (Node *root) {
    int max = 0, width;
    int h = getHeight(root);
    for (int i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > max)
            max = width;
    }
    return max;
}

int main() {
    int n; cin >> n;
    Node *root = NULL;
    Node *current;
    for (int i = 0; i < n - 1; i++) {
        int x, y, z; cin >> x >> y >> z;
        if (root == NULL) {
            current = new Node(x);
            root = current;
        }
        else {
            current = search(root, x);
        }
        Node *tmp = new Node(y);
        if (z == 0)
            current->left = tmp;
        else
            current->right = tmp;
    }
    cout << getMaxWidth(root);
}
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.sol();
}