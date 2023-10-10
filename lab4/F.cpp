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
    
    TreeNode* search(TreeNode* cur, int x){
        if (cur == NULL){
            return NULL;
        }
        if(cur->value == x){
            return cur;
        } else if(cur->value > x){
            return search(cur->left, x);
        } else if(cur->value < x){
            return search(cur->right, x);
        }
    }
    
    int count(TreeNode* cur){
        int counter = 0;
        if(cur != NULL){
            if(cur->left != NULL && cur->right != NULL){
                counter++;
            }
        
            counter+= count(cur->left);
            counter+= count(cur->right);
            
        }
        
        return counter;

    }
};

int main()
{
    Bst *B = new Bst();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (B->root == NULL)
            B->root = B->add(B->root, x);
        else
            B->add(B->root, x);
    }
    TreeNode *cur = B->root;
    cout << B->count(cur);
    
}