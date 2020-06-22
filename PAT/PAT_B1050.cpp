// PAT B1050

// how to initialize a m*n 2d vector:
// vector< vector<int> > out(m, vector<int>(n));

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Column(int n);
bool cmp(int a, int b);

int main() {
    // data input and initialization
    int m, n, N;
    int t = 0;
    cin >> N;
    n = Column(N);
    m = N / n;
    vector<int> data(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }
    sort(data.begin(), data.end(), cmp);

    // prepare output info
    vector< vector<int> > out(m, vector<int>(n));
    int level = m / 2 + m % 2;
    for(int i = 0; i < level; i++) {
        for(int j = i; j <= n - 1 - i && t < N; j++) {
            out[i][j] = data[t++];
        }
        for(int j = i + 1; j <= m - 2 - i && t < N; j++) {
            out[j][n - 1 - i] = data[t++];
        }
        for(int j = n - i - 1; j >= i && t < N; j--) {
            out[m - 1 - i][j] = data[t++];
        }
        for(int j = m - 2 - i; j >= i + 1 && t < N; j--) {
            out[j][i] = data[t++];
        }
    }

    // print result
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(j != 0) {
                cout << " ";
            }
            cout << out[i][j];
        }
        if(i != m - 1) {
            cout << endl;
        }
    }

    return 0;
}

int Column(int n) {
    int i = sqrt((double)n);
    while(i > 0) {
        if(n % i == 0) {
            return i;
        }
        i--;
    }
    return 1;
}

bool cmp(int a, int b) {
    return a > b;
}

