//
//  main.cpp
//  P7 - The number on the board
//
//  Created by Victor Villarreal on 9/24/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k, sum=0;
    string n;
    cin >> k; //sum of digits
    cin >> n; //number
    int arreglo[n.length()];
    int ordenado[n.length()];

    for(int i=0; i<n.length(); i++){
        arreglo[i] = stoi(n.substr(i,1));
        ordenado[i]=stoi(n.substr(i,1));
        sum=sum+stoi(n.substr(i,1));
    }

    sort(ordenado, ordenado + n.length()); //order array

    int counter=0;
    if(sum<k){
        sum=k-sum;
        for(int k=0; k<n.length(); k++){
            if(sum>0){
                sum=sum+(ordenado[k]-9);
                counter++;
            }
        }
        cout << counter;
    }
    else{
        cout << 0;
    }

    return 0;
}
