//
//  main.cpp
//  Find the Unique Character
//
//  Created by Amadeus on 1/15/19.
//  Copyright © 2019 Victor Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

int searchPos(string s, int left, int right){
    int length = right-left+1;
    int mid = left + ((length-1)/2); // Get the middle position
    if(length/2%2==0){ //Case 1
        if(s[mid]==s[mid-1]){ //If repeated to the left
            return searchPos(s, left, mid-2); //Take left
        }
        else if(s[mid]==s[mid+1]){ //If repeated to the right
            return searchPos(s, mid+2, right); //Take right
        }
        else //Not repeated
            return mid; //Result
    }
    else{ //Case 2
        if(s[mid]==s[mid-1]){ //If repeated to the left
            return searchPos(s, mid+1, right); //Take right
        }
        else if(s[mid]==s[mid+1]){ //If repeated to the right
            return searchPos(s, left, mid-1); //Take left
        }
        else //Not repeated
            return mid; //Result
    }
}

int main() {
    string s;
    cin >> s;
    if(s==" ")
        cout << "" << endl;
    else
        cout << s[searchPos(s, 0, s.length()-1)] << endl;
    return 0;
}
