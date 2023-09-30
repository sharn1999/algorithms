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
    
    void view(int data, int index){
        ListNode* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(pos == index){
                cout << data << " ";
            } else{
                cout << temp -> value << " ";
                temp = temp -> next;
            }
            pos++;
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
    
    int data;
    cin >> data;
    int index;
    cin>>index;
    ll -> view(data, index);
    
    return 0;
}