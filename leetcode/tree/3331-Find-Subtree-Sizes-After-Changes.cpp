#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; ++i) {
            origAdj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        array<int, 26> lastSeen;
        lastSeen.fill(-1);

        auto findNewParents = [&](auto& self, int u) -> void {
            int idx = s[u] - 'a';
            int prevAncestor = lastSeen[idx];

            if (u != 0 && prevAncestor != -1) {
                newParent[u] = prevAncestor;
            }

            lastSeen[idx] = u;
            for (int v : origAdj[u]) {
                self(self, v);
            }
            lastSeen[idx] = prevAncestor;
        };

        findNewParents(findNewParents, 0);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; ++i) {
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto computeSizes = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : finalAdj[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        computeSizes(computeSizes, 0);
        return ans;
    }
};