// Problem: Minimize Hamming Distance After Swap Operations
// Link: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
// Date: 2026-04-21
// Difficulty: Medium
// Language: C++

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        // Step 1: Build components
        for (auto &e : allowedSwaps) {
            dsu.unite(e[0], e[1]);
        }

        // Step 2: Group indices by root
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            components[root].push_back(i);
        }

        int ans = 0;

        // Step 3: Process each component
        for (auto &comp : components) {
            unordered_map<int, int> freq;

            // Count source values
            for (int idx : comp.second) {
                freq[source[idx]]++;
            }

            // Match with target
            for (int idx : comp.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++; // mismatch
                }
            }
        }

        return ans;
    }
};
