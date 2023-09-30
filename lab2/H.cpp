#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p==0){
        node->next = head;
        head = node;
        return head;
    }else{
        Node* cur = head;
        for(int i = 0; i < p - 1; i++){
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    }
}
 
Node* remove(Node* head, int p){
        if(p==0){
            Node* new_head = head->next;
            return new_head;
        }
        Node* cur = head;
        for(int i = 0; i < p - 1; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node* node = head;
    if(p1!=0){
        Node* cur = head;
        for(int i = 0; i < p1 - 1; i++){
            cur = cur->next;
        }
        node = cur->next; 
        cur->next = cur->next->next;
    }else{
        head = head->next;
    }
    return insert(head, node, p2);
}
 
Node* reverse(Node* head){
    Node* prev = NULL, * _next = NULL, *cur = head;
    while(cur){
        _next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = _next;
    }
    return prev;
}
 
void print(Node* head){
    Node* cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
  if(x == 0) return head;
  Node* prev = NULL, *newHead = head;
  while(x--){
    prev = newHead;
    newHead  = newHead -> next;
  }
  prev -> next = NULL;
  Node*tail = newHead;
  while(tail->next){
    tail = tail->next;
  }
  tail -> next = head;
    return newHead;
}
 
Node* cyclic_right(Node* head, int x){
    if(x == 0) return head;
  Node* prev = NULL, *tail = head;
  int size = 0;
  while(tail->next){
    size++;
    tail = tail->next;
  }
  int idx = size - x;
    Node* last = head;
    while(idx--){
        last  = last->next;
    }
    Node* newHead = last->next;
    last->next = NULL;
    tail->next = head;
    return newHead;
}
 
int main(){
    Node* head = NULL;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}