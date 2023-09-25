#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct MyQueue{
    queue<int> q;
    MyQueue(){

    }
    void push(int x){
        q.push(x);
    }
    int front(){
        return q.front();
    }
    void pop(){
        q.pop();
    }
    bool empty(){
        return q.empty();
    }
};

int main(){ 
    int n; cin >> n;
    string s; cin >> s;
    MyQueue* kat = new MyQueue();
    MyQueue* sak = new MyQueue();
        for (int i = 0; i < n; i++){
            if (s[i] == 'K'){
                kat->push(i);
            }
            else {
                sak->push(i);
            }
        }
        while (!kat->empty() && !sak->empty()){
            if (kat->front() < sak->front()){
                kat->push(n++);
            }
            else {
                sak->push(n++);
            }
            kat->pop(), sak->pop();
        }
        cout << (kat->empty() ? ("SAKAYANAGI") : ("KATSURAGI"));
}