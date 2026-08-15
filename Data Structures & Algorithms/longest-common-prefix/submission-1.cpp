class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        TrieNode() {
           this->children = {};
        }
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            this->root = new TrieNode;
        }

        void insert(string word) {
            TrieNode* node = this->root;
            for (const char& c : word) {
                if (!node->children.contains(c))
                    node->children[c] = new TrieNode;
                node = node->children[c];
            }
        }

        int lcp(string word, size_t prefixLen) {
            TrieNode* node = this->root;
            for (int i=0;i<prefixLen;i++) {
                if (!node->children.contains(word[i]))
                    return i;

                node = node->children[word[i]];
            }

            return prefixLen;
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];

        size_t min_i = 0;
        for (size_t i=1;i<strs.size();i++) {
            if (strs[min_i].size() > strs[i].size())
                min_i = i;
        }

        Trie* trie = new Trie;
        trie->insert(strs[min_i]);
        size_t prefixLen = strs[min_i].size();

        for (const string& s : strs)
            prefixLen = trie->lcp(s, prefixLen);
        
        return strs[0].substr(0, prefixLen);
    }
};