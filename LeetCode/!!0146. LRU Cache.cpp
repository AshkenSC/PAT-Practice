/*
0146. LRU Cache

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。


*/

#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;

    DLinkedNode() {
        key = 0;
        value = 0;
        prev = nullptr;
        next = nullptr;
    }

    DLinkedNode(int _key, int _value) {
        key = _key;
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int capacity;
    int size;

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
       if (!cache.count(key)) {
           return -1;
       }
       else {
           DLinkedNode* node = cache[key];
            moveToHead(node);
            return node->value;
       }
    }
    
    void put(int key, int value) {
       if (!cache.count(key)) {
           DLinkedNode *node = new DLinkedNode(key, value);
           cache[key] = node;
           addToHead(node);
           size++;
           if (size > capacity) {
               DLinkedNode *removed = removeTail();
               cache.erase(removed->key);
               delete removed;
               --size;
           }
       }
       else {
           DLinkedNode *node = cache[key];
           node->value = value;
           moveToHead(node);
       }
    }

    void addToHead(DLinkedNode* node) {
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        node->next = head->next;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 但是不能现在delete，因为后面还用得上
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};