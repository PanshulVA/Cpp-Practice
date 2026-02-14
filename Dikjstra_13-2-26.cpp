// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>

// using namespace std;

// typedef pair<int, int> pii;

// void dijkstra(int V, vector<vector<pii>>& adj, int source) {
//     vector<int> dist(V, INT_MAX);
//     priority_queue<pii, vector<pii>, greater<pii>> pq;

//     dist[source] = 0;
//     pq.push({0, source});

//     while (!pq.empty()) {
//         int currentDist = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();

//         if (currentDist > dist[u])
//             continue;

//         for (auto edge : adj[u]) {
//             int v = edge.first;
//             int weight = edge.second;

//             if (dist[u] + weight < dist[v]) {
//                 dist[v] = dist[u] + weight;
//                 pq.push({dist[v], v});
//             }
//         }
//     }

//     cout << "Vertex\tDistance from Source\n";
//     for (int i = 0; i < V; i++) {
//         cout << i << "\t" << dist[i] << endl;
//     }
// }

// int main() {
//     int V = 5;
//     vector<vector<pii>> adj(V);

//     adj[0].push_back({1, 9});
//     adj[0].push_back({2, 6});
//     adj[0].push_back({3, 5});
//     adj[0].push_back({4, 3});
//     adj[2].push_back({1, 2});
//     adj[2].push_back({3, 4});

//     int source = 0;
//     dijkstra(V, adj, source);

//     return 0;
// }
// // Ouput
// // Vertex  Distance from Source
// // 0       0
// // 1       8
// // 2       6
// // 3       5
// // 4       3
