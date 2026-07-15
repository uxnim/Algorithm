#include <string>
#include <vector>
#include <queue>

using namespace std;
bool isOneLetterDifferent(const string& word1, const string& word2) {
    int diff_count = 0;
    
    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) {
            diff_count++;
        }
        if (diff_count > 1) {
            return false;
        }
    }
    
    return diff_count == 1;
}

int bfs(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    vector<int> visited(words.size(), 0);
    q.push({begin, 0});
    
    while(!q.empty()) {
        string now = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(now == target) {
            return count;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && isOneLetterDifferent(now, words[i])) {
                visited[i] = 1;
                q.push({words[i], count + 1});
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = bfs(begin, target, words);
    return answer;
}