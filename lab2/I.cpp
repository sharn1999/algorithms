#include <iostream>

using namespace std;

struct ListNode{
  string value;
  ListNode* next;
  
  ListNode(string n){
      value = n;
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
    
    void add_back(string n){
        ListNode* node = new ListNode(n);
        node->next = NULL;
        if(head == NULL) {
            head = node;
            tail = node;
        } else {
            ListNode* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
        }  
    }
    
    void add_front(string s){
        ListNode* node = new ListNode(s);
        if(head == NULL) {
            head = node;
            tail = node;
        } else {
            node -> next = head;
            head = node;
        }
    }
    
    void erase_front(){
        if(head== NULL){
            cout << "error"<<endl;
        } else{
        ListNode* temp = head;

        head = head->next;
        cout << temp->value << endl;
        delete temp;
        }
    }
    
    void erase_back(){
        if (head == NULL){
            cout << "error"<<endl;
        }else if(head->next == NULL){
            cout << head->value<<endl;
            head = NULL;
        }else{
            ListNode* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            cout << temp->next->value<<endl;
            temp->next = nullptr;
        }


    }
    
    void front(){
        if(head == NULL){
            cout << "error" << endl;
        } else{
            cout << head->value << endl;
        }
    }
    
    void back(){
        if(head == NULL){
            cout << "error" << endl;
        } else{
            ListNode* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    }
    
    void clear(){
        head = NULL;
    }
    
};
int main(){
    LinkedList* ll = new LinkedList();
    bool b = true;
    while(b){
        string s;
        cin >> s;
        if(s == "add_front"){
            string t;
            cin>>t;
            ll -> add_front(t);
            cout << "ok" << endl;
        } else  if(s == "add_back"){
            string t;
            cin>>t;
            ll -> add_back(t);
            cout << "ok" << endl;
        }else  if(s == "erase_front"){
            ll -> erase_front();
        } else  if(s == "erase_back"){
            ll -> erase_back();
        }else  if(s == "front"){
            ll -> front();
        }else  if(s == "back"){
            ll -> back();
        }else  if(s == "clear"){
            ll -> clear();
            cout << "ok"<<endl;
        }else if(s == "exit"){
            cout << "goodbye"<<endl;
            b = false;
        }
    }
}