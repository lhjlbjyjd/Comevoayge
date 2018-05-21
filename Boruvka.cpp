#include "Boruvka.h"

std::vector<int> Boruvka::findcomp(int n, std::vector<std::vector<int>> &g) {
    std::vector<bool> visited(n,false);
    std::vector<int> comp(n + 1, -1);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                visited[v] = true;
                comp[v] = cur;
                for (int j = 0; j < g[v].size(); j++) {
                    if (!visited[g[v][j]])
                        q.push(g[v][j]);
                }
            }
            cur++;
        }

    }
    comp[n] = cur;
    return comp;
}

std::vector<Edge> Boruvka::getMinOstov(int n, std::vector<Edge> &edges) {
    int m = edges.size();
    edges.push_back(Edge(0,0,INT32_MAX,0));
    std::vector<std::vector<int>> g(n, std::vector<int> (0));
    std::vector<Edge> T(0, Edge(0,0,0,0));
    std::vector<bool> visited(m, false);
    std::vector<int> comp(n + 1, 0);
    while(T.size() < n - 1) {
        comp = findcomp(n, g);
        int kol = comp[n];
        std::vector<int> minEdge(kol, m);
        for (int i = 0; i < edges.size(); i++) {
            int comp1 = comp[std::get<0>(edges[i])], comp2 = comp[std::get<1>(edges[i])];
            if (comp1 != comp2) {
                if (std::get<2>(edges[minEdge[comp1]]) > std::get<2>(edges[i]) ||
                    std::get<2>(edges[minEdge[comp1]]) == std::get<2>(edges[i]) && std::get<3>(edges[minEdge[comp1]]) > std::get<3>(edges[i])) {
                    minEdge[comp1] = i;
                }
                if (std::get<2>(edges[minEdge[comp2]]) > std::get<2>(edges[i]) ||
                    std::get<2>(edges[minEdge[comp2]]) == std::get<2>(edges[i]) && std::get<3>(edges[minEdge[comp2]]) > std::get<3>(edges[i])) {
                    minEdge[comp2] = i;
                }
            }
        }
        for (int i = 0; i < kol; i++) {
            if (!visited[minEdge[i]]) {
                visited[minEdge[i]] = true;
                T.push_back(edges[minEdge[i]]);
                g[std::get<0>(edges[minEdge[i]])].push_back(std::get<1>(edges[minEdge[i]]));
                g[std::get<1>(edges[minEdge[i]])].push_back(std::get<0>(edges[minEdge[i]]));
            }
        }
    }
    return  T;
}