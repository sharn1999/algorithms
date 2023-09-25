#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;
int main()
{
    deque<int> B;
    deque<int> N;
    int counter = 0;
    for(int i = 0 ; i<5; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }
    
    for(int i = 0 ; i<5; i++){
        int a;
        cin >> a;
        N.push_back(a);
    }
    bool h = true;
    while(h){
        if(B.front() > N.front() && B.front() == 9 && N.front() ==0){
            N.push_back(B.front());
            N.push_back(N.front());
            counter++;
        }else if(B.front() > N.front()){
            B.push_back(B.front());
            B.push_back(N.front());
            counter++;
        } 
        
        
        if(N.front() > B.front() && B.front() == 0 && N.front() ==9){
            B.push_back(B.front());
            B.push_back(N.front());
            counter++;
        }else if(N.front() > B.front()){
            N.push_back(B.front());
            N.push_back(N.front());
            counter++;
        } 
        B.pop_front();
        N.pop_front();
        if(B.empty()){
            cout << "Nursik" << " ";
            cout << counter << endl;
            h = false;
        }
        if(N.empty()){
            cout << "Boris" << " ";
            cout << counter << endl;
            h = false;
        }
        if(counter >= 1000000){
            cout << "blin nichya";
            h = false;
        }
    }

}