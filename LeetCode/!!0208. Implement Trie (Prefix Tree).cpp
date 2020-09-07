/*
0208. Implement Trie (Prefix Tree)

实现一个前缀树，包含insert，search和startsWith三个操作。

该数据结构较为陌生，还需要熟悉。
*/

class Trie {
private:
    bool isEnd;
    Trie* next[26];

public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char currentChar : word) {
            if (node->next[currentChar - 'a'] == NULL)
                node->next[currentChar - 'a'] = new Trie();
            node = node->next[currentChar - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char currentChar : word) {
            node = node->next[currentChar - 'a'];
            if (node == NULL)
                return false;
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char currentChar : prefix) {
            node = node->next[currentChar - 'a'];
            if (node == NULL)
                return false;
        }
        return true;
    }
};
