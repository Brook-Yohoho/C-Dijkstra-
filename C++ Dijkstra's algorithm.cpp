#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// グラフを表す構造体
struct Edge {
    int to;     // 隣接する頂点
    int cost;   // 重み
    Edge(int t, int c) : to(t), cost(c) {}
};

typedef vector<vector<Edge>> Graph;   // グラフ

// Dijkstraアルゴリズムで最短経路を求める関数
vector<int> dijkstra(const Graph& G, int s) {
    int N = G.size();   // 頂点の数
    vector<int> dist(N, INF);   // 最短経路を格納する配列
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

    // 初期化
    dist[s] = 0;
    que.push(make_pair(0, s));

    // ダイクストラ法
    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) {
            continue;
        }
        for (int i = 0; i < G[v].size(); ++i) {
            Edge e = G[v][i];
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    Graph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(Edge(t, d));
    }

    vector<int> dist = dijkstra(G, r);

    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
