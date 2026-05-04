#include <bits/stdc++.h>
using namespace std;

int S,E,N,D,M,O,R,Y;

bool valid() {
    if(S==0 || M==0) return false;

    int SEND = 1000*S + 100*E + 10*N + D;
    int MORE = 1000*M + 100*O + 10*R + E;
    int MONEY = 10000*M + 1000*O + 100*N + 10*E + Y;

    return SEND + MORE == MONEY;
}

int main() {
    vector<int> perm = {0,1,2,3,4,5,6,7,8,9};

    do {
        S=perm[0]; E=perm[1]; N=perm[2]; D=perm[3];
        M=perm[4]; O=perm[5]; R=perm[6]; Y=perm[7];

        if(valid()) {
            cout << "Solution:\n";
            cout << "SEND=" << 1000*S+100*E+10*N+D << "\n";
            cout << "MORE=" << 1000*M+100*O+10*R+E << "\n";
            cout << "MONEY=" << 10000*M+1000*O+100*N+10*E+Y << "\n";
            break;
        }

    } while(next_permutation(perm.begin(), perm.end()));
}

/*
Sample Input:
Equation SEND + MORE = MONEY

Sample Output:
SEND=9567
MORE=1085
MONEY=10652

Problem: Solve cryptarithmetic puzzle using CSP.
*/