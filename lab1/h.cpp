#include <stdio.h>
#include <math.h>
#include <iostream>
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
    
    if(isPrime(a)){
        cout << "YES";
    } else{
        cout << "NO";
    }
}