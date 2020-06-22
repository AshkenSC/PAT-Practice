// PAT B1029

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    char text1[85], text2[85];
    vector<char> printed;   // store printed chars

    scanf("%s\n%s", text1, text2);
    for(int i = 0, j = 0, isPrinted = 0; i < strlen(text1); i++) {
        isPrinted = 0;
        if(text1[i] == text2[j]) {
        // the char is correctly printed
            j++;
        }
        else {
        // the char is not printed, key broken
            if(text1[i] >= 'a' && text1[i] <= 'z') {
            // meet lower-case letters
                text1[i] = text1[i] - 'a' + 'A';
                for(vector<char>::iterator it = printed.begin(); it != printed.end(); it++) {
                    if(text1[i] == *it) {
                        isPrinted = 1;
                        break;
                    }
                }
                if(isPrinted == 0) {
                    printf("%c", text1[i]);
                    printed.push_back(text1[i]);
                }
            }
            else {
                for(vector<char>::iterator it = printed.begin(); it != printed.end(); it++) {
                    if(text1[i] == *it) {
                        isPrinted = 1;
                        break;
                    }
                }
                if(isPrinted == 0) {
                    printf("%c", text1[i]);
                    printed.push_back(text1[i]);
                }
            }
        }
    }

    return 0;
}





