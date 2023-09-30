#include <iostream>
using namespace std;

struct ListNode{
    string value;
    ListNode* next;
    
    ListNode(string s){
        value = s;
        next = NULL;
    }
};

struct LinkedList{
    
    ListNode* head;
    ListNode* tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    int getCount(){
        int counter = 0;
        ListNode* temp = head;
        while(temp != NULL){
            counter++;
            temp = temp -> next;
        }
        return counter;
    }
    
    void push(string s){
        ListNode* node = new ListNode(s);
        if(head == NULL){
            head = node;
            tail = node;
        } else{
            // ListNode* t = head;
            // head = node;
            // head -> next = t;
            node->next = head;
            head = node;
            
        }
    }
    
    void removeDub(){
        ListNode* cur = head;
        while(cur ->next != NULL){
            
            if(cur->value == cur -> next -> value){
                cur->next = cur->next->next;   
            } else{
                cur = cur->next;
            }
        }
        
    }
    
    void view(){
        removeDub();
        
        ListNode* temp = head;
        cout << "All in all: ";
        cout << getCount() << endl;
        cout << "Students: " << endl;
        while(temp != NULL){
            cout << temp->value << endl;
            temp = temp -> next;
        }
    }
};

int main() {
    LinkedList* ll = new LinkedList();
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        ll -> push(s);
    }
    ll -> view();
}