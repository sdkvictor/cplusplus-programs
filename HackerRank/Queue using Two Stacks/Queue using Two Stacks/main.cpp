//
//  main.cpp
//  Queue using Two Stacks
//
//  Created by Amadeus on 2/5/19.
//  Copyright © 2019 Victor Villarreal. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    stack<int> pila1, pila2;
    int q, type, x;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>type;
        //Enqueue
        if(type==1){
            cin>>x;
            pila1.push(x);
        }
        //Dequeue
        else if(type==2){
            if(pila2.empty()){
                if(!pila1.empty()){
                    while(!pila1.empty()){
                        //Move all items to stack 2
                        pila2.push(pila1.top());
                        pila1.pop();
                    }
                }
            }
            //Dequeue value
            pila2.pop();
        }
        //Print
        else if(type==3){
            if(pila2.empty()){
                if(!pila1.empty()){
                    int k=0;
                    while(k<pila1.size()){
                        //Move all items to stack 2
                        pila2.push(pila1.top());
                        pila1.pop();
                    }
                }
            }
            
            //Print value
            cout <<  pila2.top() << endl;

            }
        }
    
    return 0;

    }
    
