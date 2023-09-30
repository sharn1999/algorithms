#include <iostream>

using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x){
        value = x;
        next = NULL;
    }
};

struct LinkedList{
    int size;
    
    ListNode* head;
    ListNode* tail;
    
    LinkedList(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    void pushEl(int n){
        ListNode* node = new ListNode(n);
        if(tail == NULL){
            head = node;
            tail = node;
        } else{
            tail -> next = node;
            tail = node;
        }
    }
    
    void view(){
        ListNode* temp = head;
        while(temp != NULL){
            cout << temp -> value;
            temp = temp -> next;
        }
    }
    
    void viewC(){
        ListNode* temp = head;
        int pos = 1;
        while(temp != NULL){
            if(pos%2 == 1){
                cout << temp -> value << " ";
            }
            pos++;
            temp = temp -> next;
            
        }
    }
};

int main()
{
    LinkedList* ll = new LinkedList();
    int a;
    cin >> a;
    for(int i = 0; i< a; i++){
        int n;
        cin >> n;
        ll -> pushEl(n);
    }
    
    ll -> viewC();
    
    return 0;
}