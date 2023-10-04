#include <iostream>

using namespace std;

int findNum(int arr[], int find, int lastI){
    int first = 0;
    int last = lastI-1;

    while(first <= last){
        int middle = first + (last-first) / 2;
        if(arr[middle] == find){
            return middle;
        } else if(arr[middle] < find){
            first = middle+1;
            
        } else{
            last = middle-1;
        }
    }
    return -1;
}

int main()
{
    int q;
    cin >> q;
    int arr[q];
    for(int i = 0; i<q; i++){
        int n;
        cin >> n;
        arr[i] = n;
    }
    
    int a;
    cin >> a;
    if(findNum(arr, a, q) == -1){
        cout << "No";
    } else{
        cout << "Yes";
    }

    return 0;
}