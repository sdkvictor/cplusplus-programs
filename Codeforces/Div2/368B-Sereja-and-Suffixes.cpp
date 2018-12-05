//
//  main.cpp
//  P8.2 Sereja and Suffixes
//
//  Created by Victor Villarreal on 9/25/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <vector>
#include <cmath>
#include <array>

#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define MAXN 100000
using namespace std;

typedef long long ll;

int main() {
    int n,m;
    cin>>n>>m;

    ll dif[MAXN] = {0}; //Differences
    ll repetido[MAXN] = {0}; //Tests

    ll elements[n];
    ll ints[m];

    FOR(i, 0, n){ //Enter elements of the array
        cin >> elements[i];
    }
    for(int i=n-1; i>=0; i--){ //Count different numbers
        if(i==n-1){
            dif[i]=1; //True because its the first number
            repetido[elements[i]]=1; //Also true because we just tried the first number
        }
        else{
            if(repetido[elements[i]]!=1){ //If not true yet
                dif[i] = 1+dif[i+1]; //Increase number of dif by 1 and the rest accumulated
            }
            else{
                dif[i] = dif[i+1]; //Increase dif just by the accumulated one since its repeated
            }
            repetido[elements[i]]=1; //Now it has been seen so it will count as repeated
        }
    }

    FOR(i, 0, m){
        cin >> ints[i];
    }

    FOR(i, 0, m){
        cout << dif[ints[i]-1] << endl;
    }

    return 0;
}
