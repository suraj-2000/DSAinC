#include<bits/stdc++.h>
using namespace std;
void is_PowerofTwo1(int n) {
	int res=1;
	while(res<=n) {
		if(res==n) {
			cout<<"Yes";
			return;
		}
		else
		res*=2;
	}
	cout<<"No";
}
bool is_PowerofTwo2(int n) {
	if(n==0)
	return false;
	return ((n & (n-1))==0);
}
bool is_PowerofTwo3(int n) {
	return (n!=0 && ((n &(n-1))==0));
}
int main() {
	int n;
	cin>>n;
	cout<<is_PowerofTwo3(n)?"Yes":"No";	
}
