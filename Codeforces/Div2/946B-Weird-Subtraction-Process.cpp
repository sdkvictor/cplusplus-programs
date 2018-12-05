//
//  main.cpp
//  P3 Weird Subtraction Process
//
//  Created by Victor Villarreal on 9/24/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    while(n!=0 && m!=0 &&(n >= 2*m || m >= 2*n)){
        if(n >= 2*m)
        {
            n%=(2*m);
        }
        else if(m >= 2*n)
        {
            m%=(2*n);
        }
    }
    cout << n << " " << m;
    return 0;
}
