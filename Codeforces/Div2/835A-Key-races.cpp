//
//  main.cpp
//  P6 Key races
//
//  Created by Victor Villarreal on 9/24/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int time1, time2;
    time1= t1+(s*v1)+t1;
    time2= t2+(s*v2)+t2;
    if(time1<time2){
        cout << "First";
    }
    if(time2<time1){
        cout << "Second";
    }
    if(time2==time1){
        cout << "Friendship";
    }
    return 0;
}
