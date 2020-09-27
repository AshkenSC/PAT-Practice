/*

0344. Reverse String

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

思路：双指针在头尾，交换双指针指向的字母，然后双指针同时向中间移动，再交换。
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
