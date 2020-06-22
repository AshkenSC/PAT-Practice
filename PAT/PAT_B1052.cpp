// PAT B1052

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    // materials and requests input
    vector< vector<string> > sym;
    for(int i = 0; i < 3; i++) {
        string s;
        getline(cin, s);
        vector<string> row;
        int j = 0, k = 0;
        while(j < s.length()) {
            if(s[j] == '[') {
                while(k++ < s.length()) {
                    if(s[k] == ']') {
                        row.push_back(s.substr(j+1, k-j-1));
                        break;
                    }
                }
            }
            j++;
        }
        sym.push_back(row);
    }

    // emotions output
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if(a > sym[0].size() || b > sym[1].size() || c > sym[2].size() ||
           d > sym[1].size() || e > sym[0].size() || a < 1 ||
           b < 1 || c < 1 || d < 1 || e < 1) {
            printf("Are you kidding me? @\\/@\n");
            continue;
           }
            cout << sym[0][a-1] << "(" << sym[1][b-1] << sym[2][c-1]
            << sym[1][d-1] << ")" << sym[0][e-1] << endl;
    }

    return 0;
}
