#include <iostream>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n){
        value = n;
        left = NULL;
        right = NULL;
    }
};

struct Bst{
    TreeNode* root;
    Bst(){
        root = NULL;
    }
    
    TreeNode* add(TreeNode* cur, int x){
        if(cur == NULL){
            cur = new TreeNode(x);
        } else if(cur -> value > x){
            if(cur->left == NULL){
                cur->left = add(cur->left, x);
            } else{
                add(cur->left, x);
            }
        } else{
            if(cur->right == NULL){
                cur->right = add(cur->right, x);
            } else{
                add(cur->right, x);
            }
        }
        return cur;
    }
};

int main()
{
    Bst *B = new Bst();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (B->root == NULL)
            B->root = B->add(B->root, x);
        else
            B->add(B->root, x);
    }
    
    while(m--) {
        string s; cin >> s;
        TreeNode *current = B->root;
        for (int i = 0; i < s.length(); i++) {
            if (current == NULL) {
                break;
            }
            if (s[i] == 'L') {
                current = current->left;

            }
            if (s[i] == 'R') {
                current = current->right;
            }
        }
        if (current != NULL)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}