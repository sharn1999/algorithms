#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {

    int n; 
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack <int> st;
    vector <int> ans;
    for(int i = 0; i < v.size(); i++) {

        while(!st.empty() && st.top() > v[i]) {
            st.pop();
        }

        if(st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top());
        }
        st.push(v[i]);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}