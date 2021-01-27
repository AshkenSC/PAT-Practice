#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <numeric>
#include <unordered_set>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(): key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int curSize;
    int capacity;

public:
    LRUCache(int _capacity): curSize(0), capacity(_capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        else {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        // 若key不存在
        if (!cache.count(key)) {
            Node* node = new Node(key, value);
            
            cache[key] = node;
            addToHead(node);
            ++curSize;
            // cache已经满了
            if (curSize > capacity) {
                Node* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                
                cache[key] = node;
                addToHead(node);
                --curSize;
            }
        }
        // 若key存在
        else {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
            ++curSize;
        }
    }

    // 自定义函数

    // 将已经存在的结点挪到前面
    void moveToHead(Node* node) {
        // 断开node前后并重连
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 挪到前面
        addToHead(node);
    }

    // 新加入的结点放在前面
    void addToHead(Node* node) {
        // 修改node指针
        node->next = head->next;
        node->prev = head;
        // 修改原head->next指针
        head->next->prev = node;
        // 修改head指针
        head->next = node;  
    }

    // 删除最后一个结点
    Node* removeTail() {
        Node* removed = tail->prev;
        tail->prev = removed->prev;
        removed->prev->next = tail;
        return removed;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2, 2);
    int p1 = obj->get(1);
    obj->put(3,3);
    int p2 = obj->get(2);
    obj->put(4,4);
    int p3 = obj->get(1);

    return 0;
}