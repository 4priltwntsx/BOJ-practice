#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int dp[101][10001] = { 0, };
int m[101] = { 0, };
int c[101] = { 0, };
int sum = 0;
int result = 100000;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];
	}
	for (int i = 1; i <= N; i++) {
		int memory = m[i];
		int cost = c[i];

		for (int j = 0; j <= sum; j++) {
			if (j < c[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + memory);
			}
			if (dp[i][j] >= M) result = min(result, j);

		}
	}
	cout << result;
	return 0;
}

