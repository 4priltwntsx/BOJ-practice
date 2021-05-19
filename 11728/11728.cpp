#include <stdio.h>
#include <iostream>

int a[1000001];
int b[1000001];
int c[2000002];
int n, m;

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<n && j<m){
        if(a[i]<b[j]) 
            c[k++] = a[i++];
        else 
            c[k++] = b[j++];
    }
    while(i<n){
        c[k++] = a[i++];
    }
    while(j<m){
        c[k++] = b[j++];
    }

    for(i = 0; i< n+m; i++){
        printf("%d ",c[i]);
    }
    return 0;
}

// void merge(int ls, int le, int rs, int re, int A[]){
//     int lptr = ls, rptr = rs, bptr = 0;
//     while(lptr<=le && rptr <=re){
//         if(A[lptr]<A[rptr]) 
//             B[bptr++] = A[lptr++];
//         else 
//             B[bptr++] = A[rptr++];
//     }
//     if(lptr>le){
//         for(int i = rptr; i<=re; i++){
//             B[bptr++] = A[i];
//         }
//     }
//     if(rptr>re){
//         for(int i = lptr; i<= le; i++){
//             B[bptr++] = A[i];
//         }
//     }
// }