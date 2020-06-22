// PAT B1068

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int m, n, threshold;
vector< vector<int> > dots;
int offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                    {1, 1}, {1, 0}, {1, -1}, {0, -1}};

bool Judge(int i, int j);

int main() {
    int cnt = 0, x = 0, y = 0;
    map<int, int> dotMap;   // a map to ensure the dot is unique

    // data input
    scanf("%d%d%d", &m, &n, &threshold);
    dots.resize(n, vector<int>(m));  // resize the 2d dots array
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &dots[i][j]);
            dotMap[dots[i][j]]++;
        }
    }

    // scan dots
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dotMap[dots[i][j]] == 1 && Judge(i, j) == true) {
                cnt++;
                x = i + 1;
                y = j + 1;
            }
        }
    }

    // print result
    if(cnt == 1) {
        printf("(%d, %d): %d", y, x, dots[x-1][y-1]);
    }
    else if(cnt > 1) {
        printf("Not Unique");
    }
    else {
        printf("Not Exist");
    }

    return 0;
}

bool Judge(int i, int j) {
    for(int k = 0; k < 8; k++) {
        int xPos = i + offset[k][0];
        int yPos = j + offset[k][1];
        if(xPos >= 0 && xPos < n && yPos >= 0 && yPos < m
           && abs(dots[i][j] - dots[xPos][yPos]) <= threshold) {
        // first line: to ensure the comparison is inside the matrix
        // second line: to ensure the difference is larger than threshold
            return false;
        }
    }
    return true;
}

