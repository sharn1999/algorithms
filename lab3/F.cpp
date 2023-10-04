#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int findN(vector<int> arr, int target){
    int l = 0;
    int r = arr.size()-1;
    int cur = 0;
    while(l<=r){
        int middle = l + (r-l)/2;
        if(arr[middle] <= target){
            cur = middle+1;
            l = middle+1;
        } else if(arr[middle] > target){
            r = middle-1;
        }
    }

    return cur;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int p;
    cin >> p;
    for(int i = 0; i<p; i++){
        int r;
        cin >> r;
        int cur = findN(arr, r);
        int sum = 0;
        for(int i = 0; i<cur;i++){
            sum+= arr[i];
        }
        cout << cur << " " << sum << endl;
    }

    return 0;
}