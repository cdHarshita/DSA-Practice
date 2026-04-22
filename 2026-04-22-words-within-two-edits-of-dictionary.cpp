// Problem: Words Within Two Edits of Dictionary
// Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/
// Date: 2026-04-22
// Difficulty: Medium
// Language: C++

class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    bool dfs(TrieNode* node, string &word, int index, int mismatches) {
        if (!node) return false;

        // If mismatches exceed 2 → stop
        if (mismatches > 2) return false;

        // If reached end of word
        if (index == word.size()) {
            return node->endOfWord && mismatches <= 2;
        }

        int currChar = word[index] - 'a';

        // Try all possible children
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                if (i == currChar) {
                    // no mismatch
                    if (dfs(node->children[i], word, index + 1, mismatches))
                        return true;
                } else {
                    // mismatch
                    if (dfs(node->children[i], word, index + 1, mismatches + 1))
                        return true;
                }
            }
        }

        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endOfWord = true;
    }

    bool searchWithTwoSkips(string word) {
        return dfs(root, word, 0, 0);
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        Trie dict; 
        for (auto &word : dictionary) {
            dict.insert(word);
        }

        for (auto &word : queries) {
            if (dict.searchWithTwoSkips(word)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
