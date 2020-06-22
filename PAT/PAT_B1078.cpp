// PAT B1078

/*
在吸收模式字符和字符串之间的换行符时，必须使用getchar()
使用scanf("%c\n")，测试点2和3会报错。 
*/ 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    char tempChar, tempStr[1010];

    // select mode
    scanf("%c", &tempChar);
    getchar();
    if(tempChar == 'C') {
    // compress mode
        fgets(tempStr, 1010, stdin);
        int charCount;
        for(int i = 0; i < strlen(tempStr) - 1; i++) {
            charCount = 0;
            while(tempStr[i] == tempStr[i+1]) {
                i++;
                charCount++;
            }
            if(charCount > 0) {
                printf("%d", charCount + 1);
            }
            printf("%c", tempStr[i]);
        }
    }
    else if(tempChar == 'D') {
    // decompress mode
        fgets(tempStr, 1010, stdin);
        int repeat = 0;
        for(int i = 0; i < strlen(tempStr) - 1; i++) {
            if(tempStr[i] >= '0' && tempStr[i] <= '9') {
            // current position is a number
                repeat = repeat * 10 + tempStr[i] - '0';
            }
            else {
            // current position is a char
                if(repeat == 0) {
                // current char is not compressed
                    printf("%c", tempStr[i]);
                }
                else {
                // current char is compressed
                    for(int j = 0; j < repeat; j++) {
                        printf("%c", tempStr[i]);
                    }
                    repeat = 0;     // reset repeat time counter
                }
            }
        }
    }

    return 0;
}

