//
//  main.cpp
//  P5 Odds and Ends
//
//  Created by Victor Villarreal on 9/24/18.
//  Copyright © 2018 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int isEven = false; //Check if any of the extremes of the array are even
    for(int i = 0; i < n; i++)
    {
        int element;
        cin >> element;

        if(i==0||i==(n-1)){
            if(element%2 == 0){
                isEven = true;
            }
        }

    }
    if(n%2==0||isEven==true){
        cout << "No";
    }
    else{
        cout << "Yes";
    }

    return 0;
}
