/*
1207. Unique Number of Occurrences

1）用字典记录数组每个数出现的次数；
2）再用字典记录出现的次数出现的次数；
3）如果有出现的次数出现的次数大于1，就返回false。
*/

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occur;
        map<int, int> occurOccur;
        for (int i = 0; i < arr.size(); i++) {
            occur[arr[i]] = occur[arr[i]] + 1;
        }
        map<int, int>::iterator it;
        for (it = occur.begin(); it != occur.end(); it++) {
            occurOccur[it->second] = occurOccur[it->second] + 1;
            if (occurOccur[it->second] > 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    Solution sol;
    vector<int> A = { 1,2 };
    bool res = sol.uniqueOccurrences(A);
    cout << res;

    return 0;
}