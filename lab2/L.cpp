# include <bits/stdc++.h>

 
using namespace std;
 
struct ListNode {
  int val;
  ListNode *next;
 
  ListNode(int x) {
    val = x;
    next = NULL;
  }
 
};

struct LinkedList{
  int size;
  ListNode* head, * tail;
  LinkedList(){
    head = tail = NULL;
  }

  void addAtTail(int x){
    ListNode* newNode = new ListNode(x);
    if(!tail){
      head = tail = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
  }
  
  int findMaxSum() {  
          ListNode* cur = head;
          int maxLast = INT_MIN, maxCur = 0;
          while(cur) {
      maxCur += cur->val;
      maxCur = max(maxCur, cur->val);
      maxLast = max(maxLast, maxCur);
      cur = cur->next;
          }
          return maxLast;
}
};
 
 
 

 
int main() {
  int n; cin >> n;
  LinkedList* ll = new LinkedList();
  while(n--){
    int x; cin >> x;
    ll->addAtTail(x);
  }
  cout << ll->findMaxSum() << endl;
}