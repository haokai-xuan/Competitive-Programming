// only solves 3/15 points

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, m;
vector<vector<int>> adj(MAXN);
int depth[MAXN];
int par[MAXN];

void dfs(int node, int parent, int dep)
{
    par[node] = parent;
    depth[node] = dep; // assign node to current depth

    for (int child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node, dep + 1);
        }
    }
}

int lca(int node1, int node2)
{
    while (depth[node1] > depth[node2])
    {
        node1 = par[node1];
    }

    while (depth[node2] > depth[node1])
    {
        node2 = par[node2];
    }

    while (node1 != node2)
    {
        node1 = par[node1];
        node2 = par[node2];
    }

    return node1; // node1 is equal to node2
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> phos;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        phos.push_back(x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // calculate depths of nodes
    dfs(0, -1, 0); // use node 0 as base of tree, -1 means no parent, depth is 0

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Depth of node " << i << ": " << depth[i] << '\n';
    // }

    int lca_node = lca(phos[0], phos[1]); // finding the lowest common ancestor of the two pho nodes

    cout << depth[phos[0]] + depth[phos[1]] - 2 * depth[lca_node] << '\n';

    return 0;
}