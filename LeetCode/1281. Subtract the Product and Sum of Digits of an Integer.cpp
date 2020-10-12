/*
1281. Subtract the Product and Sum of Digits of an Integer

计算给定数字的各位积与和之差。

*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        string n_str = to_string(n);
        int sum = 0, product = 1;
        
        // 计算和积
        for (char c : n_str) {
            sum += c - '0';
            product *= c - '0';
        }

        return product - sum;
    }
};