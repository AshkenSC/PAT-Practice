// PAT B1008

/*
�͵�ѭ������Mλ�ɷ�Ϊ�������У�
��1�������������飻
��2������ǰMλ��
��3����������λ��

reverse���������������ֱ�Ϊ��
��1�������õķ�Χ��㣻
��2����ע�⣩�����õķ�Χ�յ�ĺ�һλ��
���ɼ򵥼���������ҿ���������sort�����ķ�Χ��
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    // ע�⣡m�п��ܴ���n����ʱ�൱��ѭ������m % nλ
    // Ϊ��������Σ���Ҫm = m % n
    m = m % n;
    if(m != 0) {
        // ע��reverse�ĵڶ���������Ϊ�����õ�ĩλԪ�صĺ�һλ
        reverse(a.begin(), a.begin() + n);
        reverse(a.begin(), a.begin() + m);
        reverse(a.begin() + m, a.begin() + n);
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
        // ȷ��ĩβû�пո�
        if(i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}


