//
//  main.cpp
//  Floyd
//
//  Created by Amadeus on 2/28/19.
//  Copyright © 2019 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

void floyd(int D[20][20], int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && max(D[i][k],D[k][j]) < D[i][j]){
                    D[i][j] = max(D[i][k],D[k][j]);
                }
            }
        }
    }
}


int main() {
    int n, m, q, a, b ,c;
    int D[20][20];
    int cases;
    cin >> cases;
    for(int x=1; x<=cases; x++){
        cin >> n >> m >> q;
        for(int i=0; i<n; i++){
            D[i][i] = 0;
            for(int j=i+1; j<n; j++){
                D[i][j] = D[j][i] = INT_MAX;
            }
        }
        for(int i=0; i<m; i++){
            cin >> a >> b >> c;
            D[a-1][b-1] = D[b-1][a-1] = c;
        }
        floyd(D,n);
        cout << "Case " << x << ":" << endl;
        for(int i=0; i<q; i++){
            cin >> a >> b;
            if(D[a-1][b-1]<INT_MAX){
                cout << D[a-1][b-1] << endl;
            }
            else{
                cout << "no path" << endl;
            }
        }
    }
}
