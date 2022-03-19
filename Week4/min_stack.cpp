#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int maximum;
};


void insert(stack<node> &s2 , int val)
{
	node other;
	other.data=val;
	
	if(s2.empty()) other.maximum=val;
	else
	{
		node front=s2.top();
		other.maximum=max(val,front.maximum);
	}
	s2.push(other);
	return;
}

void delete(stack<node> &s1 ,stack<node> &s2 )
{
	if(s1.size()) s1.pop();        
	else
	{
		while(!s2.empty())
		{
			node val=s2.top();
			insert(s1,val.data);
			s2.pop();
		}
		s1.pop();
	}
}

int get_max(stack<node> &s1 ,stack<node> &s2 )
{
	int ans=-1;
	if(s1.size()) ans=max(ans,s1.top().maximum);
	if(s2.size()) ans=max(ans,s2.top().maximum);
	return ans;
}


vector<int> slidingMaximum(int a[], int b,int n) {
	vector<int>ans;
	stack<node>s1,s2;
	
	for(int i=0;i<b-1;i++) insert(s2,a[i]);
	
	for(int i=0;i<=n-b;i++)
	{
		if(i-1>=0) delete(s1,s2);
		
		insert(s2,a[i+b-1]);
		
		ans.push_back(get_max(s1,s2));
	}
	return ans;
}

int main()
{
	int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	vector<int> ans=slidingMaximum(arr,k,n);
	for(auto x:ans) cout<<x<<" ";
	return 0;
}
