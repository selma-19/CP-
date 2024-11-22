#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/network-delay-time/

map<int, vector<pair<int, int>>> get_adjacency_list_from_edges(vector<vector<int>> edges) {
    map<int, vector<pair<int, int>>> adjacency;
    for (vector<int> edge : edges) {
    adjacency[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    return adjacency;
}

int networkDelayTime(vector<vector<int>>& edges, int n, int start_node) {
    map<int, vector<pair<int, int>>> adjacency =
    get_adjacency_list_from_edges(edges);

    vector<int> d(n, 1e9);

    d[start_node-1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>>
    pq;
    pq.push(make_pair(0, start_node));

    while (!pq.empty()) {
        int weight = pq.top().first, node = pq.top().second;
        pq.pop();
        for (pair<int, int> neighbour : adjacency[node]) {
            int cost = weight + neighbour.second;
            if (cost < d[neighbour.first-1]) {
                d[neighbour.first-1] = cost;
                pq.push(make_pair(cost, neighbour.first));
            }
        }
    }
    int res = *max_element(d.begin(), d.end());
    return res != 1e9 ? res : -1;
}