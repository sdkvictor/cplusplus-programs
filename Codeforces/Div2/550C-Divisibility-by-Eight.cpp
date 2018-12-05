//
//  main.cpp
//  P1.2 Divisibility by Eight
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
using namespace std;

typedef long long ll;

ll digits(ll n){ //Returns number of digits in a ll
    ll digits=0;
    ll temp=n;
    while(temp>0){
        temp=temp/10;
        digits++;
    }
    return digits;
}

ll getSubsets(ll size){ //Returns number of subsets (2^n)
    ll result = pow(2,size);
    return result;
}


int main() {
    bool valid=false;
    string n;
    cin >> n;
    // ll size = digits(n);
    ll size = n.length();
    ll num[size];
    ll res; //stores the valid subsets

    // Single digit answers (8 or 0)
    FOR(i, 0, size){
        if(n[i]=='8' || n[i]=='0'){
            res=stoi(n.substr(i,1));
            valid=true;
        }
    }

    //Two digits
    ll total, a, b;
    FOR(i, 0, size){
        FOR(j, i+1, size){
            a=stoi(n.substr(i,1));
            b=stoi(n.substr(j,1));
            total=(a*10)+b;
            if(total%8==0){
                res=total;
                valid=true;
            }
        }
    }

    //Three digits
    ll c;
    FOR(i, 0, size){
        FOR(j, i+1, size){
            FOR(k, j+1, size){
                a=stoi(n.substr(i,1));
                b=stoi(n.substr(j,1));
                c=stoi(n.substr(k,1));
                total=(a*100)+(b*10)+c;
                if(total%8==0){
                    valid=true;
                    res=total;
                }
            }
        }
    }

    if(valid==true){
        cout << "YES" << endl;
        cout << res << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
