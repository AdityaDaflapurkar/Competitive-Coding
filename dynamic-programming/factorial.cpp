/* 	Given an integer N, print the factorial of the N (mod 1000000007). 
 *  	Input:
 *	First line contains one integer, T, number of test cases.
 *	Each test case contains one integer, N.
 *
 *	Output:
 *	For each test case you need to print the factorial of N(mod 1000000007). 
 *
 */

#include <iostream>
using namespace std;

const int limit = 1000000007;
const int maxN = 100001;
int calculate_factorial (int N, int low, long **dp, int *max_used_idx) {
    
    int i = low;
    while(i <= N) {
        (*dp)[i] = ((i % limit) * ((*dp)[i-1] % limit)) % limit;
        i++;
    }
    *max_used_idx = N;
    
    return (*dp)[N];
}

int main() {
    int t, N, i, max_used_idx = 0;
    long *dp = new long[maxN], res;
    dp[0] = 1;
    cin >> t;
    for(i=0; i<t; i++) {
        cin >> N;
        
        if(max_used_idx >= N) {
            res = dp[N];
        }
        else {
            res = calculate_factorial(N, max_used_idx + 1, &dp, &max_used_idx);
        }
        cout << res << endl;
    }
}
