// PAT B1067

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {

    string correctPwd, inputPwd;
    int maxTryTime;
    int timeTried = 0;

    cin >> correctPwd >> maxTryTime;
    getchar();
    while(1) {
        if(++timeTried > maxTryTime) {
            cout << "Account locked" << endl;
            break;
        }
        getline(cin, inputPwd);
        if(inputPwd == correctPwd) {
            cout << "Welcome in" << endl;
            break;
        }
        else if(inputPwd == "#") {
            break;
        }
        else {
            cout << "Wrong password: " << inputPwd << endl;
        }

    }

    return 0;
}

