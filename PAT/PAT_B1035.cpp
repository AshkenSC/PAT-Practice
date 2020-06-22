// PAT B1035

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // data input
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // sort mode judge
    int i, j;
    for(i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for(j = i + 1; a[j] == b[j] && j < n; j++);
    if(j == n) {
        cout << "Insertion Sort" << endl;
        sort(a.begin(), a.begin() + i + 2);
    }
    else {
        cout << "Merge Sort" << endl;
        bool isSameAsB = 0;
        int mergeStep = 1;
        while(isSameAsB == 0) {
            // check if current a[] is the same as b[]
            isSameAsB = 1;
            for(int k = 0; k < n; k++) {
                if(a[k] != b[k]) {
                    isSameAsB = 0;
                }
            }
            // if not, proceed merge sort
            mergeStep *= 2;
            for(i = 0; i < n / mergeStep; i++) {
                sort(a.begin() + i * mergeStep, a.begin() + (i + 1) * mergeStep);
            }
            sort(a.begin() + n / mergeStep * mergeStep, a.begin() + n);
        }
    }

    // print result of next iteration
    for(j = 0; j < n; j++) {
        cout << a[j];
        if(j < n - 1) {
            cout << " ";
        }
    }

    return 0;
}

