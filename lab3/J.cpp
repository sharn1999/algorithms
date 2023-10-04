#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
      int k=0;
      int left=1, right= 10000000000;          
	
    while(left<=right){
         k= (left+right)/2;  
        int count=0;
        for(int i=0;i<piles.size();i++){
            count+= (piles[i]+k-1)/k;
             
        }
        
        if(count>h){ 
            
            left=k+1;
        }
        
        else{
            right=k-1;
        }
    }
    
    return left;
}

int main()
{
    int a,b;
    vector<int> ans;
    cin>> a >> b;
    for(int i = 0; i<a; i++){
        int n;
        cin>>n;
        ans.push_back(n);
    }
    cout << minEatingSpeed(ans, b);

    return 0;
}