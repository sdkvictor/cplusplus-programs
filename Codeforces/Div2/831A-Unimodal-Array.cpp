//
//  main.cpp
//  P8 Unimodal Array
//
//  Created by Victor Villarreal on 9/24/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    int numbers[n];
    for(int i=0; i<n; i++){
        cin >> num;
        numbers[i]=num;
    }
    int i=1;
    while(numbers[i]>numbers[i-1]&&i<n){
        i++;
    }
    while(numbers[i]==numbers[i-1]&&i<n){
        i++;
    }
    while(numbers[i]<numbers[i-1]&&i<n){
        i++;
    }
    if(i==n){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
