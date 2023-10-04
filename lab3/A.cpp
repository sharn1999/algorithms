#include <iostream>

using namespace std;

int findNum(int arr[], int find, int lastI){
    int first = 0;
    int last = lastI-1;

    if(arr[first] < arr[last]){
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
    } else{
        while(first <= last){
            int middle = first + (last-first) / 2;
            if(arr[middle] == find){
                return middle;
            } else if(arr[middle] > find){
                first = middle+1;
                
            } else{
                last = middle-1;
            }
        }
    }
    return -1;
}

int main()
{
    int q;
    cin >> q;
    int findArr[q];
    for(int i = 0; i<q; i++){
        int n;
        cin >> n;
        findArr[i] = n;
    }
    
    int a, b;
    cin >> a >> b;
    int arr[a][b];
    
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            int n;
            cin >> n;
            arr[i][j] = n;
        }
    }
    
    for(int i = 0; i<q; i++){
        int counter = 0;
        for(int j = 0; j<a; j++){
            if(findNum(arr[j], findArr[i], b) != -1){
                cout << counter << " ";
                cout << findNum(arr[j], findArr[i], b) << endl;
                break;
            }
            counter++;
            if(findNum(arr[j], findArr[i], b) == -1 && counter == a){
                cout << -1 << endl;
            }
            
        }

    }

    return 0;
}