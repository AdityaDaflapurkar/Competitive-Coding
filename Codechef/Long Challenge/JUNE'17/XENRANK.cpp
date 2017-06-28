#include<iostream>
using namespace std;
 
int main()
{
    long long int t,n,j,a,b,sum,rank;
	cin>>t;
	for(j=0;j<t;j++)
	{
		cin>>a>>b;
		n=a+b;
		sum=n*(n+1)/2;
		rank=sum+a+1;
		cout<<rank<<endl;	
	}
}    