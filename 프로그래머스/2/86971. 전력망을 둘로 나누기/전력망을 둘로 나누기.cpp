#include <bits/stdc++.h>

using namespace std;

int bfs(int n, vector<vector<int>> &wires, int cut_index, int start) {
    queue<int> q;
    vector<bool> visited(n+1, false);
    
    q.push(start);
    visited[start] = true;
    
    int count = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        count++;
        
        for(int i=0; i<wires.size(); i++) {
            if(i==cut_index) {
                continue;
            }
            
            int next = -1;
            if (wires[i][0] == cur) {
                next = wires[i][1];
            }
            else if (wires[i][1] == cur) {
                next = wires[i][0];
            }
            
            if (next != -1 && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    for(int i=0; i<wires.size(); i++) {
        int first = bfs(n, wires, i, 1);
        int second = n - first;
        int diff = abs(first - second);
        answer = min(answer, diff);
    }
    return answer;
}