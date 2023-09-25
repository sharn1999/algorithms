#include <stdio.h>
#include <math.h>
#include <iostream>
#include <set>
using namespace std;

int isPrime(int num){
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int a;
    cin >> a;
    
    int counter = 0;
    int prim = 1;
    
    while(counter<a){
        prim++;
        if(isPrime(prim)){
            counter++;
        }
    }
    
    cout << prim;
}