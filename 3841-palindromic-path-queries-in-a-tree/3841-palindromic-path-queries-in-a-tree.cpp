
class Solution {
    static const int LOG = 17;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    vector<int> nodeMask;
    int timer = 0;

    // Fenwick Tree with XOR operations
    void updateBIT(int idx, int val) {
        for (int i = idx; i < (int)bit.size(); i += i & -i) {
            bit[i] ^= val;
        }
    }

    int queryBIT(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            res ^= bit[i];
        }
        return res;
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;

        up[u][0] = p;
        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    bool canFormPalindrome(int mask) {
        return (mask & (mask - 1)) == 0;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));

        nodeMask.resize(n);
        bit.assign(n + 2, 0);
        timer = 0;

        for (int i = 0; i < n; i++) {
            nodeMask[i] = 1 << (s[i] - 'a');
        }

        dfs(0, 0);

        // Initialize the Fenwick Tree.
        for (int u = 0; u < n; u++) {
            updateBIT(tin[u], nodeMask[u]);
            updateBIT(tout[u] + 1, nodeMask[u]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = nodeMask[u] ^ newMask;

                updateBIT(tin[u], delta);
                updateBIT(tout[u] + 1, delta);

                nodeMask[u] = newMask;
            } else {
                ss >> v;

                int l = lca(u, v);

                int maskU = queryBIT(tin[u]);
                int maskV = queryBIT(tin[v]);

                int pathMask = maskU ^ maskV ^ nodeMask[l];

                ans.push_back(canFormPalindrome(pathMask));
            }
        }

        return ans;
    }
};
