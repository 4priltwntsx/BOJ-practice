#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x, y;
};

/* 레이저통신 */
int w, h, ax, ay;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char a[101][101];
int dist[101][101];
pair<int, int> start, dest;
queue<point> Q;

void bfs(){

    while(!Q.empty()){

        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();

        for(int i = 0; i < 4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            while(0 <= nx && nx < h && 0 <= ny && 
            ny < w && a[nx][ny] != '*'){
                
                if(!dist[nx][ny]){
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
                nx += dx[i], ny += dy[i];

            }
        }
    }
}

int main(){

    int tmp = 0;
    //input
    scanf("%d %d", &w, &h);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf(" %1c", &a[i][j]);
            if(a[i][j] == 'C'){
                if(tmp == 0){
                ax = i;
                ay = j;
                tmp++;
                }
                else{
                    Q.push({i,j});
                }
            }
        }
    }

    bfs();
    printf("%d\n", dist[ax][ay]-1);

    return 0;
}

