//
//  main.cpp
//  P5.3 Han Solo and Lazer Gun
//
//  Created by Victor Villarreal on 9/26/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000000000000LL
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 10000 //10^4
#define PI 3.14159265358979


struct Point { //tipo Punto
    double x, y;
    bool operator <(const Point &r) const {
        return x < r.x || x == r.x && y < r.y;
    }
} pNew, laser;


int main(){
    int n;
    double x0,y0;
    cin >> n >> x0 >> y0;
    laser.x = x0;
    laser.y = y0;
    Point st[n]; //array of stormtroopers points
    double xNew,yNew;
    FOR(i, 0, n){ //Fill array with coordinates of stormtroopers
        cin >> xNew >> yNew;
        pNew.x = xNew;
        pNew.y = yNew;
        st[i] = pNew;
    }
    //st.erase( unique( st.begin(), st.end() ), st.end() ); //erase duplicates
    int dead=0, shots=0;
    int erased[maxN]={0};
    for(int i=0; (i<n)&&(dead<n); i++){
        if(erased[i]!=1){
            shots++;
            double x1,x2,y1,y2;
            x1 = st[i].x - laser.x;
            y1 = st[i].y - laser.y;
            for(int j=i+1; (j<n)&&(dead<n); j++){
                if(erased[j]!=1){
                    x2 = st[j].x - laser.x;
                    y2 = st[j].y - laser.y;
                    if(((x1/x2)==(y1/y2))||((x2/x1)==(y2/y1))){
                        erased[j]=1;
                        dead++;
                    }
                    else if((st[i].x==st[j].x && st[i].x==laser.x)||(st[i].y==st[j].y && st[i].y==laser.y)){
                        erased[j]=1;
                        dead++;
                    }
                }
            }
            dead++;
            erased[i]=1;
        }
    }

    cout << shots << endl;

    return 0;
}

//Fin del programa
