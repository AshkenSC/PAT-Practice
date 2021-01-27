/*
0146. LRU Cache

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。


*/

#include <unordered_map>
using namespace std;

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
    
    // ！！！容易错的一个函数！！！
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
                --curSize;
            }
        }
        // 若key存在
        else {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
            // 这里不要再加++curSize
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

