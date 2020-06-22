// PAT B1066

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {

    int m, n, a, b, gray;
    cin >> m >> n >> a >> b >> gray;
    vector< vector<int> > input(m);

    for(int i = 0; i < m; i++) {
        vector<int> line(n);
        int temp;
        for(int j = 0; j < n; j++) {
            cin >> temp;
            line[j] = temp;
        }
        input[i] = line;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(j != 0) {
                printf(" ");
            }
            if(input[i][j] >= a && input[i][j] <= b) {
                printf("%03d", gray);
            }
            else {
                printf("%03d", input[i][j]);
            }
            if(j == n - 1) {
                cout << endl;
            }
        }
    }

    return 0;
}

