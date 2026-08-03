#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> maps;
    for(const auto &pock : nums) {
        maps[pock]++;
    }
    
    int typeCount = maps.size();
    int selectCount = nums.size() / 2;

    return min(typeCount, selectCount);
}