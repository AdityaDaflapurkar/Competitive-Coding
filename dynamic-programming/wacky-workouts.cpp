/* 
 *	PLatform : Hackerearth
 *	Problem : Wacky Workouts
 *	Section : Dynamic Programming, Practice
 *	Learnings : Matrix Exponentiation, Basic DP
 *
 */
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const ll MAX_NUM = 1000000007;
void matmul(ll a[2][2], ll b[2][2]) {

	ll i, j, k;
	ll c[2][2] = {{0, 0}, {0, 0}};
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++) {
			c[i][j] = 0;
			for(k=0; k<2; k++) {
				c[i][j] = ((c[i][j] % MAX_NUM) + ((a[i][k] % MAX_NUM) * (b[k][j] % MAX_NUM)) % MAX_NUM) % MAX_NUM;
			}	
		}	
	}	
	a[0][0] = c[0][0];
	a[0][1] = c[0][1];
	a[1][0] = c[1][0];
	a[1][1] = c[1][1];
}

void matexp(ll f[2][2], ll n) {
	ll result[2][2] = {{1, 0}, {0, 1}};
	while(n > 0) {
		if(n%2 == 1) {
			matmul(result, f);		
		}
		matmul(f, f);
		n = n/2;
	}
	f[0][0] = result[0][0];
	f[0][1] = result[0][1];
	f[1][0] = result[1][0];
	f[1][1] = result[1][1];	
}


ll get_num_ways(ll n) {
	ll f[2][2] = {{1,1},{1,0}};
	ll res[2] = {2, 1};
	matexp(f, n-1);
	
	return (((res[0] % MAX_NUM) * (f[0][0] % MAX_NUM)) % MAX_NUM + ((res[1] % MAX_NUM) * (f[1][0] % MAX_NUM)) % MAX_NUM) % MAX_NUM;
}

int main() {
	ll n, t;
    	cin >> t;
    	while(t--) {
        	cin >> n;
        	cout << get_num_ways(n) << endl;
    	}
	return 0;
}
