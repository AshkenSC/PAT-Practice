// PAT A1049

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int input;
    int cnt = 0;
    string temp;

    cin >> input;
    for(int i = 1; i <= input; i++) {
        temp = to_string(i);
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j] == '1') {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
