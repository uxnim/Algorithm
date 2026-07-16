#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<int>> edge) {
    queue<int> q;
    vector<int> dist(n+1, -1);
    vector<vector<int>> graph(n+1);
    
    for(const auto &node : edge) {
        graph[node[0]].push_back(node[1]);
        graph[node[1]].push_back(node[0]);
    }
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(const auto &next : graph[now]) {
            if(dist[next] != -1) continue;
            
            dist[next] = dist[now]+1;
            q.push(next);
        }
    }
    
    int max_dist = 0;
    for(int i=1; i<=n; i++) {
        max_dist = max(dist[i], max_dist);
    }
    
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (dist[i] == max_dist) ans++;
    }

    return ans;
}

int solution(int n, vector<vector<int>> edge) {
    return bfs(n, edge);
}