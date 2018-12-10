//
//  main.cpp
//  Codeforces1
//
//  Created by Amadeus on 12/10/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

long long int result(long long int X, long long int M){
    if(X<=M){
        return 1;
    }
    else{
        if(X%M==0)
            return X/M;
        else
            return (X/M)+1;
    }
}

int main() {
    long long int M,N,K,L;
    bool possible = true;
    cin >> N >> M >> K >> L;
    long long int X = K+L; //minimum total coins needed
    
    //conditions
    if(L>(N-K))
        possible = false;
    if(M>N)
        possible = false;
    if((result(X, M))*M > N)
        possible = false;
    
    //result
    if(possible==true){
        cout << result(X, M);
    }
    else{
        cout << -1;
    }
    return 0;
}
