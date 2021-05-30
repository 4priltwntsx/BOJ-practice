#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix;

int N;
long long int M; //nxn의 행렬을 m번 제곱

//행렬 곱 함수
matrix calc(const matrix &a, const matrix &b, int n){

    matrix c(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }

    return c;
}

//제곱 분할정복
matrix expo(matrix a, int n, long long int m){

    matrix temp(n,vector<int>(n));

    for (int i = 0; i < n; i++) temp[i][i] = 1;

    if(m == 0) return temp;

    temp = expo(a, n, m/2);
    temp = calc(temp, temp, n);

    if(m % 2){
        return calc(temp, a, n);
    }else return temp;

}


int main(){

    scanf("%d %lld", &N, &M);
    matrix A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &A[i][j]);
        }
    }

    //printf("result----\n");

    A = expo(A,N,M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", A[i][j]);
        }
        if(i == (N-1)) break;
        printf("\n");
    }

    return 0;
}

