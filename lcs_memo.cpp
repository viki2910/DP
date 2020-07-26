//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int calcSeq(char a[],char b[],int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    if(a[i-1]==b[j-1])
    {
        return dp[i][j]=1+calcSeq(a,b,i-1,j-1);
    }
    return dp[i][j]=max(calcSeq(a,b,i,j-1),calcSeq(a,b,i-1,j));
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    for(int i=0;i<101;i++)
	        for(int j=0;j<101;j++)
	            dp[i][j]=-1;
	    int n1,n2;
	    cin>>n1>>n2;
	    char a[n1],b[n2];
	    for(int i=0;i<n1;i++)
	        cin>>a[i];
	    for(int j=0;j<n2;j++)
	        cin>>b[j];
	    cout<<calcSeq(a,b,n1,n2)<<endl;
	}
	return 0;
}