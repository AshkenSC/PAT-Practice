// 20190310-2

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long addr;
    long data;
    long next;
};

int main() {
    Node input[99999];
    vector<Node> sorted;
    long num, first;
    Node temp;

    // data input
    cin >> num >> first;
    for(long i = 0; i < num; i++) {
        cin >> temp.addr >> temp.data >> temp.next;
        input[temp.addr] = temp;
    }

    // resort list
    printf("%ld %ld\n", num, first);
    for(long i = first; i != -1; i = input[i].next) {
        sorted.push_back(input[i]);
    }

    // test
    for(long i = 0; i < sorted.size(); i++) {
        if(sorted[i].next != -1) {
            printf("%05ld %ld %05ld\n", sorted[i].addr, sorted[i].data, sorted[i].next);
        }
        else {
            printf("%05ld %ld -1", sorted[i].addr, sorted[i].data);
        }
    }

    return 0;
}