#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

long long int recursive2(long long int a, long long int b, long long int c) {
	if (b == 0)
		return 1;
	long long int temp = recursive2(a, b / 2, c);
	long long int result = temp * temp;
	result %= c;
	if (b % 2)
		return result * a%c;
	else return result;
}

int main() {
	long long int a, b, c;

	cin >> a >> b >> c;
	cout << recursive2(a, b, c);

	return 0;
}




////bottom up
//long long int iterative(long long  int n,long long int m,long long int d) {
//	if (m == 1) {
//		return n % d;
//	}
//
//	long long int n2 = n;
//	long long int result = 1;
//
//	while (m > 0) {
//		if (m % 2 == 1) {
//			result = (result*n2) % d;
//		}
//		n2 = (n2*n2) % d;
//		m /= 2;
//	}
//	return result;
//}
//
//int main() {
//	long long int A, B, C;
//	cin >> A >> B >> C;
//
//	cout << iterative(A, B, C);
//
//	return 0;
//
//}


//
////Top Down
//long long int recursive(long long int n, long long int m, long long int d) {
//	if (m == 1) {
//		return n % d;
//	}
//
//	long long int n2;
//	if (m % 2 == 0) {
//		n2 = recursive(n, m / 2, d);
//		return (n2*n2) % d;
//	}
//	else {
//		n2 = recursive(n, m / 2, d);
//		return (n2*n2*n) % d;
//	}
//}
//
//int main() {
//	long long int A, B, C;
//	cin >> A >> B >> C;
//
//	cout << recursive(A, B, C);
//}

