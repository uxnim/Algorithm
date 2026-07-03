#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n, 1);
    for(const auto &i : lost) {
        student[i-1]--;
    }
    for(const auto &i : reserve) {
        student[i-1]++;
    }
    
    for(int i=0; i<n; i++) {
        if(i == 0) {
            if(student[i] == 0) {
                if(student[i+1] == 2) {
                    student[i]++;
                    student[i+1]--;
                }
            }
            continue;
        }
        if(student[i] == 0) {
            if(student[i-1] == 2) {
                student[i-1]--;
                student[i]++;
            }
            else if(student[i+1] == 2) {
                student[i+1]--;
                student[i]++;
            }
        }
    }
    int count = 0;
    for(int i=0; i<n; i++) {
        if(student[i]>=1) {
            count++;
        }
    }
    return count;
}