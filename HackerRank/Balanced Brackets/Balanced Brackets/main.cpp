//
//  main.cpp
//  Balanced Brackets
//
//  Created by Amadeus on 2/5/19.
//  Copyright © 2019 Victor Villarreal. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

string isBalanced(string s){
    stack<char> myStack; //Crea el stack
    
    for(int j=0; j<s.length(); j++){
        if(s[j]=='('||s[j]=='['||s[j]=='{'||myStack.empty()){ //Push si es un corchete de entrada
            myStack.push(s[j]);
        }
        
        //Pop si se cierra el top
        else if(s[j]==')'){
            if(myStack.top()=='('){
                myStack.pop();
            }
            else{
                myStack.push(s[j]);
            }
        }
        else if(s[j]==']'){
            if(myStack.top()=='['){
                myStack.pop();
            }
            else{
                myStack.push(s[j]);
            }
        }
        else if(s[j]=='}'){
            if(myStack.top()=='{'){
                myStack.pop();
            }
            else{
                myStack.push(s[j]);
            }
        }
        
    } //Se acaba la linea
    
    if(myStack.empty()){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main() {
    
    string line;
    int lines;
    
    cin >> lines; //Lee el numero de lineas
    
    for(int i=0; i<lines; i++){
        cin >> line; //lee la linea
        cout << isBalanced(line) << endl;
    }
    
    return 0;
}

