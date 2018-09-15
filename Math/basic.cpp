#include <bits/stdc++.h>
using namespace std;

template<typename T> T gcd(T a, T b) {
	return (b ? __gcd(a,b) : a);
}

template<typename T> T lcm(T a, T b) {
	return (a * (b / gcd(a,b)));
}

template<typename T> T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1;
	while(b) {
		T q = a / b, t = b;
		b = a % b; a = t;
		t = xx; xx = x - q * xx;
		x = t; t = yy;
		yy = y - q * yy; y = t;
	}
	return a;
}

template<typename T> T mod_inverse(T a, T n) {
	T x, y, z = 0;
	T d = extended_euclid(a, n, x, y);
	return (d > 1 ? -1 : mod_neg(x, z, n));
}

// computes x and y such that ax + by = c
// on failure, x = y = -1
void linear_diophantine(int a, int b, int c, int &x, int &y) {
	int d = gcd(a,b);
	if (c%d) x = y = -1;
	else {
		x = c/d * mod_inverse(a/d, b/d);
		y = (c-a*x)/b;
	}
}

//(a + b) % c
int add(int a, int b, int c) {
	int res = a + b;
	return (res >= c ? res - c : res);
}

//(a - b) % c
int mod_neg(int a, int b, int c) {
	int res; if(abs(a-b) < c) res = a - b;
	else res = (a-b) % c;
	return (res < 0 ? res + c : res);
}

//(a * b) % c
int mul(int a, int b, int c) {
	long long res = (long long)a * b;
	return (res >= c ? res % c : res);
}

//(a * b) % c for very large numbers, to avoid overflows
//O(1) hack taken from http://codeforces.com/blog/entry/15884
long long modmul(long long a, long long b, long long m) {
	long long q = (long long)(((long double)a*(long double)b)/(long double)m);
	long long r = a * b - q * m;
	if(r > m) r %= m; if( r < 0) r += m;
	return r;
}