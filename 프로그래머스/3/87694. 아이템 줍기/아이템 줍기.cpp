#include <string>

#include <vector>

#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> map(102, vector<int>(102, 0));    
    for(const auto &rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        for(int i=x1; i<=x2; i++) {
            for(int j=y1; j<=y2; j++) {
                map[i][j] = 1;
            }
        }
    }
    for(const auto &rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        for(int i=x1+1; i<x2; i++) {
            for(int j=y1+1; j<y2; j++) {
                map[i][j] = 0;
            }
        }
    }

    vector<vector<int>> dist(102, vector<int>(102, -1));
    queue<pair<int, int>> q;
    
    int startX = characterX * 2;
    int startY = characterY * 2;
    int endX = itemX * 2;
    int endY = itemY * 2;

    q.push({startX, startY});
    dist[startX][startY] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==endX && y==endY) {
            return dist[x][y] / 2;
        }

        for(int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
            if(map[nx][ny] != 1) continue;
            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y]+1;
            q.push({nx, ny});
        }
    }
    return -1;
}



int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    return bfs(rectangle, characterX, characterY, itemX, itemY);
}