//
//  main.cpp
//  1 and 0s
//
//  Created by Amadeus on 1/20/19.
//  Copyright © 2019 Victor Villarreal. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;




int numsLeft(string number, int length){
    int zeros = 0;
    for(int i=0; i<length; i++){
        if(number[i]=='0')
            zeros++;
    }
    return abs(length-zeros-zeros);
}

int main() {
    string number;
    int length;
    cin >> length;
    cin >> number;
    cout << numsLeft(number, length) << endl;
    return 0;
}
