#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
/**
 * 연결요소의 개수
 **/

using namespace std;

vector<int> edge[10001];
bool visit[10001] = {false};


//dfs(v)
void dfs(int v){
    if(visit[v] == true) return;

    visit[v] = true;
    for(int i = 0; i < edge[v].size(); i++){
        dfs(edge[v][i]);
    }
}

int main(){
    int n, m, u, v;
    int i;

    scanf("%d %d",&n, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    // for(i = 1; i <= n; i++){
    //     sort(edge[i].begin(), edge[i].end());
    // }
    int cnt = 0;
    for(i = 1; i <= n; i++){
        if(visit[i] == false){
            cnt++;
            dfs(i);
        }
    }
    printf("%d",cnt);

}


