#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    int bS(vector<int>& a, int target) {
        int n=a.size();
		
        int i,j,sum, minlen=n+1;
        i=j=sum=0;
		
        while(j<n){
            sum+=a[j];
			
            while(i<=j && sum>=target){
                minlen = min(minlen,j-i+1);
                sum-=a[i];
                i++;
            }
			
            j++;
        }
        
        return (minlen==n+1 ? 0:minlen);
    }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for(int i = 0; i< n; i++){
        int s;
        cin >>s;
        arr.push_back(s);
    }
    cout << bS(arr, m);
}