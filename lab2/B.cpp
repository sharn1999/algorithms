#include <iostream>

using namespace std;

struct ListNode{
    string value;
    ListNode* next;
    ListNode(string x){
        value = x;
        next = NULL;
    }
};

struct LinkedList{
    int size;
    ListNode* head;
    ListNode* tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void push(string x){
        ListNode* node = new ListNode(x);
        if(tail == NULL){
            head = node;
            tail = node;
        } else{
            tail -> next = node;
            tail = node;
        }
    }
    
    void view(int b) {
        for(int i = 0; i<b; i++){
            // tail = head;
            // tail -> next = NULL;
            
            // tail = head;
            // tail -> next = head;
            // head = head->next;
            string s = head->value;
            ListNode* newNode = new ListNode(s);
            
            tail->next = newNode;
            tail = newNode;
            head = head->next;
        }
        
        ListNode* temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp->next;
        }
        
    }
};

int main(){
    LinkedList* ll = new LinkedList();
    
    int a;
    cin>>a;
    int b;
    cin >> b;
    
    for(int i = 0; i<a; i++){
        string n;
        cin >> n;
        ll -> push(n);
    }
    
    ll -> view(b);
}