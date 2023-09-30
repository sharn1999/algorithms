#include <iostream>

using namespace std;
struct node{
    int value;
    node* next;
    node(int x){
        value = x;
        next = NULL;
    }
};

struct LinkedList{
    int size;
    node* head;
    node* tail;
    
    LinkedList(){
        size=0;
        head = NULL;
        tail = NULL;
    }
    
    void pushEl(int n){
        node* lnode = new node(n);
        if(tail == NULL){
            head = lnode;
            tail = lnode;
        } else{
            tail -> next = lnode;
            tail = lnode;
        }
    }
    int findMin(int n){
        node* temp = head;
        int min;
        int t;
        if(temp ->value - n < 0){
            min = (temp->value-n) * (-1);
        } else{
            min = temp->value-n;
        }
        
        while(temp != NULL){
            if(temp->value-n<0){
                t = (temp->value-n) * (-1);
            } else{
                t = temp->value-n;
            }
            if(t < min){
                min = t;
            }
            temp = temp -> next;
        }
        return min;
    }
    void view(int n){
        node* temp = head;
        int pos = 0;
        int min = findMin(n);
        while(temp != NULL){
            if(temp->value-n == min || (temp->value-n) *(-1) == min){
                cout << pos << " ";
                break;
            }
            temp = temp -> next;
            pos++;
        }
    }
};
int main(){
    LinkedList* ll = new LinkedList();
    int b;
    cin >> b;
    for(int i = 0; i<b; i++){
        int a;
        cin >> a;
        ll -> pushEl(a);
    }
    int n;
    cin >> n;
    
    ll->view(n);
}
