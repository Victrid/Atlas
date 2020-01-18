#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	bool *Isprime = new bool[2000001];
	bool SPACE_FLAG = false;
	Isprime[0] = false;
	Isprime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (!Isprime[i])continue;
		for (int j = 2; i * j <= n; j++) {
			Isprime[i * j] = false;
		}
		if (SPACE_FLAG)cout << ' ';
		cout << i;
		SPACE_FLAG = true;
	}
	return 0;
}