#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int a[100001];
int n;
//큰거부터 pop
priority_queue<int,vector<int>, less<int>> maxpq; 
//작은 거부터 pop
priority_queue<int, vector<int>, greater<int>> minpq;

void priority_solution(){

    for(int i = 0; i < n; i++){
        if(maxpq.size() > minpq.size()){
            minpq.push(a[i]);
        }
        else maxpq.push(a[i]);

        if(maxpq.empty() == false && minpq.empty() == false){
            if (maxpq.top() > minpq.top()){
                int maxvalue = maxpq.top();
                int minvalue = minpq.top();

                maxpq.pop();
                minpq.pop();

                maxpq.push(minvalue);
                minpq.push(maxvalue);
            }
        }
        printf("%d\n", maxpq.top());
    }
}


int main(){

    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    //printf("---results print---\n");
    //priority queue
    priority_solution();

    return 0;

}

