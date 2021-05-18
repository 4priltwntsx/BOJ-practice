#include <stdio.h>
#include <iostream>

using namespace std;

/*
N이 3보다 클 경우, 크기 N의 패턴은 
공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 
크기 N/3의 패턴으로 둘러싼 형태이다. 
첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 
즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.
*/

void print_stars(int n, int x, int y){
    //n은 3^k, (x,y)=(0,0)
    if((x/n)%3 == 1 && (y/n)%3 == 1 ){
        cout << " ";
    }
    else{
        if(n/3==0) cout << "*";
        else print_stars(n/3,x,y);
    }
}

int main(){ 
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j = 0; j < n; j++){
            print_stars(n,i,j);
        }
        cout << "\n";
    }
    return 0;
}    