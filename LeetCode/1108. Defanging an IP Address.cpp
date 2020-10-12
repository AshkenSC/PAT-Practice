/*
1108. Defanging an IP Address

给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char c : address) {
            if (c == '.')
                res += "[.]";
            else
                res += c;
        }
        return res;
    }
};