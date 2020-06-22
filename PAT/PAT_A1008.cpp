// PAT A1008

/*
第一个数不是楼层！只是停靠次数！
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    int currentFloor = 0;
    int sum = 0;
    int temp;
    vector<int> floor;

    // data input
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> temp;
        floor.push_back(temp);
    }

    // calculate
    for(int i = 0; i < num; i++) {
        if(floor[i] > currentFloor) {
            sum += 6 * (floor[i] - currentFloor);
        }
        else {
            sum += 4 * (currentFloor - floor[i]);
        }
        sum += 5;
        currentFloor = floor[i];
    }

    // print result
    cout << sum;

    return 0;
}
