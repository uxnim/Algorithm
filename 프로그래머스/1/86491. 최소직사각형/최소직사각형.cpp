#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0;
    int max_h = 0;
    
    for(const auto& i : sizes) {
        int longer = max(i[0], i[1]);
        int shorter = min(i[0], i[1]);
        
        max_w = max(max_w, longer);
        max_h = max(max_h, shorter);
    }
    return max_w*max_h;
}