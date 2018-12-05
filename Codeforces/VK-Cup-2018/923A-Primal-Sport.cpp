#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maximum 1000000 //10^6

using namespace std;

int mem[maximum + 1];

int maxP(int k) {
    for(int i=2; i<=sqrt(k); i++) {
        if(k%i == 0){
            return mem[k] = max(maxP(i), maxP(k / i));
        }
    }
    return mem[k] = k;
}

int main() {
    int x2;
    cin >> x2;
    int FacX2 = maxP(x2);
    int x0 = x2;

    for(int x1=x2-FacX2+1; x1<=x2; x1++){
        int FacX1 = maxP(x1);
        if(FacX1 < x1) {
            x0 = min(x0, x1-FacX1+1);
        }
    }
    cout << x0;
    return 0;
}
