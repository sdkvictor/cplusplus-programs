//
//  main.cpp
//  P4.3 Mammoth's Genome Decoding
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
    int len;
    string gen;
    cin >> len; //First line input
    cin >> gen; //Second line input

    int numA=0,numC=0,numG=0,numT=0;
    int rMax=0; //max repeated letters
    FOR(i, 0, len){
        if(gen[i]=='A'){
            numA++; //sum of As
            if(numA>rMax) rMax=numA;
        }
        if(gen[i]=='C'){
            numC++; //sum of Cs
            if(numC>rMax) rMax=numC;
        }
        if(gen[i]=='G'){
            numG++; //sum of Gs
            if(numG>rMax) rMax=numG;
        }
        if(gen[i]=='T'){
            numT++; //sum of Ts
            if(numT>rMax) rMax=numT;
        }
    }

    bool possible = false;
    FOR(i, 0, (64-rMax)){
        if(len==(4*rMax+4*i)) possible = true; //Its possible to get an answer
    }

    if(possible==true){
        bool bA=false, bC=false, bG=false, bT=false;
        FOR(i, 0, len){
            int count=0;
            bool replace=false;
            if(numA==rMax&&numC==rMax&&numG==rMax&&numT==rMax){
                rMax++;
            }
            if(gen[i]=='?'&&bA==false&&replace==false&&numA<rMax){ //If finds a ? and next is A
                gen[i]='A';
                numA++;
                bA=true;
                replace=true;
            }
            else if(gen[i]=='?'&&bC==false&&replace==false&&numC<rMax){ //If finds a ? and next is C
                gen[i]='C';
                numC++;
                bC=true;
                replace=true;
            }
            else if(gen[i]=='?'&&bG==false&&replace==false&&numG<rMax){ //If finds a ? and next is G
                gen[i]='G';
                numG++;
                bG=true;
                replace=true;
            }
            else if(gen[i]=='?'&&bT==false&&replace==false&&numT<rMax){ //If finds a ? and next is T
                gen[i]='T';
                numT++;
                bA=false;
                bC=false;
                bG=false;
                replace=true;
            }
            else if(replace==false&&gen[i]=='?'){
                bA=false;
                bC=false;
                bG=false;
                i--;
            }
        }

        cout << gen << endl;
    }
    else{
        cout << "===" << endl;
    }
    return 0;
}
