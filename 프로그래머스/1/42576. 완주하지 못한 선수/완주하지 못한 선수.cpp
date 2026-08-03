#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    for(const auto &player : participant) {
        map[player]++;
    }
    for(const auto &player : completion) {
        map[player]--;
    }
    for (const auto &item : map) {
        if (item.second > 0) {
            return item.first;
        }
    }
}