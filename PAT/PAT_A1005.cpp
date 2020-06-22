// PAT A1005

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

string number[] = {"zero", "one", "two", "three",
                   "four", "five", "six", "seven",
                   "eight", "nine"};

int main() {

    string input, output;
    int sum = 0;

    getline(cin, input);
    for(int i = 0; i < input.size(); i++) {
        sum += input[i] - '0';
    }
    output = to_string(sum);

    for(int i = 0; i < output.size(); i++) {
        cout << number[output[i] - '0'];
        if(i < output.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
