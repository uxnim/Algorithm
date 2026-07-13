#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int count[201] = {0};
    
    for(const auto &line : lines) {
        for(int i=line[0]; i<line[1]; i++) {
            count[i+100]++;
        }
    }
    for(const auto &i : count) {
        if(i >= 2) {
            answer++;
        }
    }
    return answer;
}