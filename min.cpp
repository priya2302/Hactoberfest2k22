#include<bits/stdc++.h>
using namespace std;

int mi(vector<int> a,int k)
{
	sort(a.begin(),a.end());
	int tot=a.size()/k;
	vector<int> res;
	int m;
	int d=0;
	int start=0;
	for(int i=0;i<a.size();i++)
	{

		if(d==0)
		{
			start=a[i];
		}
		d++;

		if(d==tot)
		{
			int v=(((a[i]-1)*(a[i]))/2);
			int v1=((start*(start+1))/2);
			v=v-v1;

			v/=(a[i]-start-1);
			start=a[i];
			d=0;
			res.push_back(v);
		}
	}
	d=0;
	int j=0;
	int val;
	for(int i=0;i<res.size();i++)
	{
		d++;
		val=max(val,abs(res[j]-a[i]));
		if(d==tot)
		{
			d=0;
			j++;
		}

	}
	return val;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int ans=mi(arr,k);
	cout<<ans;
}
