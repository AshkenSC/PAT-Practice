// PAT B1055

/*
首先按要求格式申请vetor并输入数据
然后对每行进行身高降序排列（注意相等身高按名字排序！第一次忘记了）
接下来对每行按要求排序：
	1） 用临时数组temp存放当前行副本
	2） 最高者temp[0]先放在 m/2
	3） 其他人相对于m/2的偏移值依次为-1 +1 -2 +2...在一个循环中放入原数组
最后输出即可 
*/ 

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
    string name;
    int height;
};

bool cmp(Data a, Data b);

int main() {
    // data input
    int n, k;
    cin >> n >> k;
    vector<Data> tmp(n);
    vector< vector<Data> > matrix(k, vector<Data>(n/k));
    for(int i = 0; i < n; i++) {
        cin >> tmp[i].name >> tmp[i].height;
    }
    sort(tmp.begin(), tmp.end(), cmp);

    // initialize matrix
    for(int i = 0, t = 0; i < k; i++) {
        for(int j = 0; j < n / k; j++) {
            matrix[i][j] = tmp[t++];
        }
        if(i == 0) {
            for(int j = 0; j < n % k; j++) {
                matrix[i].push_back(tmp[t++]);
            }
        }
    }

    // resort people
    for(int i = 0; i < k; i++) {
        // a temp array to store current line
        vector<Data> temp(matrix[i].size());
        for(int j = 0; j < matrix[i].size(); j++) {
            temp[j] = matrix[i][j];
        }
        // resort current line
        int mid = matrix[i].size() / 2;
        matrix[i][mid] = temp[0];   // put the highest at mid position
        for(int j = 1; j < matrix[i].size(); j++) {
            int offset = (j + 1) / 2;
            if(j % 2 != 0) {
                matrix[i][mid - offset] = temp[j];
            }
            else {
                matrix[i][mid + offset] = temp[j];
            }
        }
    }

    // print test
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(j != 0) {
                cout << " ";
            }
            cout << matrix[i][j].name;
        }
        cout << endl;
    }

    return 0;
}

bool cmp(Data a, Data b) {
    if(a.height != b.height) {
        return a.height > b.height;
    }
    else {
        return a.name < b.name;
    }
}

