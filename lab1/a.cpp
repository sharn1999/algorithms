#include <bits/stdc++.h>
#define ll long long 
using namespace std;
void solve() {
    int x;
    cin >> x;
    deque <int> dq;
    
    for(int i = x; i >= 1; i--) {
        dq.push_back(i);
        for(int j = 0; j <= i; j++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
    
    while(!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}

int main() {

    int n;
    cin >> n;
    while(n--) {
        solve();
    }

}