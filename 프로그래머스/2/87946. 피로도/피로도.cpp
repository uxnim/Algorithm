#include<bits/stdc++.h>

using namespace std;

int max_index = 0;

void dfs(int k, vector<vector<int>> dungeons, int index, vector<bool> check) {
    max_index = max(max_index, index);
    
    for(int i=0; i<dungeons.size(); i++) {
        if(!check[i] && k >= dungeons[i][0]) {
            check[i] = true;
            dfs(k - dungeons[i][1], dungeons, index+1, check);
            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, 0, visited);
    return max_index;
}