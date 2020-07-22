/*
1）新建二维vector
vector<vector<int>> result = vector<vector<int>> (高, vector<int>(宽))

2) 二维vector初始化赋值
vector<vector<int>> A = { { 1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 } };

*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        vector<vector<int>> result = vector<vector<int>>(A.size());

        for(int i = 0; i < A.size(); i++) {
            for (int j = A[0].size() - 1; j >= 0; j--) {
                if (A[i][j] == 0) {
                    result[i].push_back(1);
                }
                else
                {
                    result[i].push_back(0);
                }
            }
        }

        return result;
    }
};