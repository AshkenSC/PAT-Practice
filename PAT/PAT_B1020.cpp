// PAT B1020

/*

先计算单价，按单价降序排列月饼。然后逐个月饼存量与剩余总需求量比较。
如果当前最贵月饼存量比剩余需求大，则全部剩余需求买当前最贵月饼，更新总价，退出循环。 
如果当前剩余需求比当前最贵月饼大，则购买当前全部最贵月饼 ，进入下一轮。 

注意：计算总价的for循环 ，条件必须是 maxNeed > 0 && i < num，
必须同时考虑i < num，即所有月饼都买！且！总需求还没满足的情况。
否则测试点3报段错误。 

Use sort() to sort a custom structure vector:
sort(mooncakes.begin(), mooncakes.end(), cmp);

*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Mooncake {
    double storage;
    double totalPrice;
    double unitPrice;
};

bool cmp(Mooncake a, Mooncake b);

int main() {
    // data input
    int num;
    double maxNeed;
    cin >> num >> maxNeed;
    vector<Mooncake> mooncakes(num);
    for(int i = 0; i < num; i++) {
        cin >> mooncakes[i].storage;
    }
    for(int i = 0; i < num; i++) {
        cin >> mooncakes[i].totalPrice;
        mooncakes[i].unitPrice = mooncakes[i].totalPrice / mooncakes[i].storage;
    }
    sort(mooncakes.begin(), mooncakes.end(), cmp);

    // calculate profit
    double totalProfit = 0.0;
    for(int i = 0; maxNeed > 0 && i < num; i++) {
        if(maxNeed < mooncakes[i].storage) {
            totalProfit += maxNeed * mooncakes[i].unitPrice;
            break;
        }
        else {
            totalProfit += mooncakes[i].totalPrice;
            maxNeed -= mooncakes[i].storage;
        }
    }

    // print result
    printf("%.2lf", totalProfit);

    return 0;
}

bool cmp(Mooncake a, Mooncake b) {
    return a.unitPrice > b.unitPrice;
}


