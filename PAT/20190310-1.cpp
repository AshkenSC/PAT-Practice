// 20190310-1

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string input, sub, sub1, sub2;
    int index;

    cin >> input >> index;
    sub = input.substr(0, index);

    int next = 0;
    for(int i = 1; i < index; i++) {
        sub1 = sub.substr(0, i);
        sub2 = sub.substr(index - i, index);
        if(sub1 == sub2) {
            next = i;
        }
    }

    cout << next;

    return 0;
}
