#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    char val;
    bool dup;
    ListNode* next;
    ListNode(char x){
        val = x;
        dup = false;
        next = NULL;
    }
};

struct LinkedList{
    int size;
    ListNode* head, * tail;

    LinkedList(){
        size = 0;
        head = tail = NULL;
    }


    void addAtTail(char x){
        ListNode* val = new ListNode(x);
        if(!tail){
            head = tail = val;
        }else{
            ListNode* cur = head;
            while(cur){
                if(cur->val == x){
                    cur->dup = true;
                    return;
                } 
                cur = cur->next;
            }
            tail->next = val;
            tail = val;
        }
    }



    void solve() {
        ListNode* cur = head;
        while(cur){
            if(!cur->dup){
                cout << cur->val << " ";
                return;
            }
            cur = cur->next;
        }
        cout << -1 << " ";
    }
};


int main() {
    int n; cin >> n;
    

    while(n--){
        int k; cin >> k;
        LinkedList* ll = new LinkedList();
        while(k--){
            char x; cin >>x;
            ll->addAtTail(x);
            ll->solve();
        }
        cout << endl;
    }

   
}