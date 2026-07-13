#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int count = 1;
    
    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            answer[top][col] = count++;
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            answer[row][right] = count++;
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                answer[bottom][col] = count++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                answer[row][left] = count++;
            }
            left++;
        }
    }
    
    return answer;
}