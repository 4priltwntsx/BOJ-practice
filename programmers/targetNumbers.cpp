#include <string>
#include <vector>

using namespace std;

int answer = 0;

void targetNumber(vector<int> numbers, int target, int sum, int count){
    if(count == numbers.size()){
        if(sum == target)
            answer++;
        return;
    }
    targetNumber(numbers, target, sum+numbers[count], count+1);
    targetNumber(numbers, target, sum-numbers[count],count+1);
}

int solution(vector<int> numbers, int target) {
    targetNumber(numbers,target, 0, 0);
    return answer;
}

int main(){
    vector<int> a = {1,1,1,1,1};
    int ans = solution(a,3);
    printf("%d", ans);

    return 0;
}