#include <stdio.h>
#include <algorithm>

using namespace std;

long long int N, K, A, B;
long long mod = 1000000007;

//지수승 처리
long long int exponent(long long int a , long long int p) {
	if (p == 0)
		return 1;
	long long int temp = exponent(a, p/2);
	long long int result = temp * temp;
	result %= mod;
	if (p % 2)
		return result * a%mod;
	else return result;
}


int main(){
    scanf("%d %d", &N, &K);
    A = 1;
    // A = N!
    for(long long int i = 1; i<=N; i++){
        A = (A*i)%mod;
    }

    // B = (K!(N-K)!)
    B = 1;
    for(long long int i = 1; i <= K; i++){
        B = (B*i)%mod;
    }
    for(long long int i = 1; i <= (N-K); i++){
        B = (B*i)%mod;
    }

    // B^(-1) => B^(mod-2);
    B = exponent(B, mod-2);

    long long int C = (A*B)%mod;

    printf("%d",C);

    return 0;

}