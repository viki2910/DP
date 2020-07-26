//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> a(n,0),lis(n,1);
	    
	    for(int m=0;m<n;m++){
	        int x;
	        cin>>x;
	        a[m]=x;
	    }
	    
	   
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[i]>a[j]){
	                lis[i]=max(lis[i],lis[j]+1);
	            }
	        }
	    }
	    
	    sort(lis.begin(),lis.end());
	    cout<<lis[n-1]<<endl;
	    
	    
	}
	return 0;
}