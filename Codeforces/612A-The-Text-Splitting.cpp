//
//  main.cpp
//  P6.3 The Text Splitting
//
//  Created by Victor Villarreal on 9/26/18.
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
    string s;
    int n,p,q,subs;
    cin>>n>>p>>q;
    cin>>s;
    bool found = false;
    //Just 1
    if(n%p==0){
        subs = n/p;
        cout << subs << endl;
        found=true;
        FOR(i, 0, subs){
            cout << s.substr(0,p)<<endl;
            s.erase(0,p);
        }
    }
    else if(n%q==0){
        subs = n/q;
        cout << subs << endl;
        found=true;
        FOR(i, 0, subs){
            cout << s.substr(0,q) << endl;
            s.erase(0,q);
        }
    }

    //include both once
    if((n-p-q)==0&&found==false){
        cout << 2 << endl;
        cout << s.substr(0,p) << endl;
        cout << s.substr(p,q) << endl;
        found=true;
    }
    //include both more than once
    if(n-p-q>0&&found==false){
        int n1=p,n2=q,count1=1,count2=1;

        while((n1<n)&&(n-n1)%q!=0){
            count1++; //Max of p
            n1 += p;
        }

        n1=p;

        int rest=n-(p*count1);

        while(n2<=rest){
            if(rest-n2==0){
                found=true;
                cout << count1+count2 << endl;
                while(count1!=0){
                    cout << s.substr(0,p) << endl;
                    s.erase(0,p);
                    count1--;
                }
                while(count2!=0){
                    cout << s.substr(0,q) << endl;
                    s.erase(0,q);
                    count2--;
                }
            }
            n2 += q;
            count2++; //Max of q
        }
    }

        //can't
        if(found==false){
            cout << -1 << endl;
        }

        return 0;
    }
