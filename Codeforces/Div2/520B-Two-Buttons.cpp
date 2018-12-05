//
//  main.cpp
//  P2.3 V2 Two Buttons
//
//  Created by Victor Villarreal on 9/27/18.
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

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 100000

//using BFS (queue)
struct Nodes{
    int number; //the number it contains
    int pos; //the level position in the tree
} node;

int bfs(int n, int m){
    int level=1;
    int result=0;
    vector<int>used;
    used.push_back(0);
    queue<Nodes> myQ;
    node.number=n;
    node.pos=level;
    myQ.push(node); //top number
    bool found = false;

    while(!myQ.empty()&&found==false){ //or make a bool found and make it while(found==false)
        if(myQ.front().number*2==m || myQ.front().number-1==m){
            found = true;
            result = myQ.front().pos;
        }
        if(find(used.begin(), used.end(), myQ.front().number)==used.end()){
            node.number = myQ.front().number*2;
            node.pos = myQ.front().pos+1;
            if(node.number!=0&&node.number<=10000) myQ.push(node);
            node.number = myQ.front().number-1;
            node.pos = myQ.front().pos +1;
            if(node.number!=0) myQ.push(node);
            used.push_back(myQ.front().number);
            myQ.pop();
        }
        else{
            myQ.pop();
        }
    }
    return result;
}
int main(){
    int n,m;
    cin >> n >> m;

    cout << bfs(n, m) << endl;

    return 0;
}

//end of code
