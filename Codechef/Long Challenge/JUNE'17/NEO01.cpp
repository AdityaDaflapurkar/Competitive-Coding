#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main()
{
    long long int t,e,i,n,happy=0,curr,x,pos,count,ns,ind;
	cin>>t;
	for(e=0;e<t;e++)
	{
	   cin>>n;
	   pos=0;
	   count=0;
	   ind=0;
	   vector<int>neg;
	   happy=0;
	   for(i=0;i<n;i++)
	   {
	        cin>>x;
	        if(x>=0)
	        {
	            pos+=x;
	            count++;
	        }
	        else
	        {
	            neg.push_back(x);
	        }
	        
	   }
	   happy=pos*count;
	   sort(neg.begin(), neg.end());
	   reverse(neg.begin(), neg.end());
	   ns=neg.size();
	   i=0;
	   curr=happy;
	   //cout<<count<<"ccc";
	   //cout<<happy<<"hhh";
	   if(happy!=0)
	   {
	        while(i<ns)
	        {
	            curr=(curr/count+neg[i])*(count+1);
	            count++;
	            
	            //cout<<curr<<"hhh";
	            if(curr>=happy)
	            {
	                happy=curr;
	                i++;
	            } 
	            else
	            {
	                break;
	            }    
	       
	        }
	   }
	   while(i<ns)
	   {
	       happy+=neg[i];
	       i++;
	   }
	   neg.clear();
	   cout<<happy<<endl;
	}
	return 0;
}   