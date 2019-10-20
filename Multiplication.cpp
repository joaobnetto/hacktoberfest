#include <bits/stdc++.h>
#include <algorithm>
 
#define ll long long
#define db(a) cout << "hey - " << a << "\n";
#define min(a, b) ((a<b)? a:b)
#define max(a, b) ((a>b)? a:b)
#define abs(a) ((a>=0)? a:-a)
#define ini(a, n, v) for (int i=0;i<n;i++) a[i]=v;
 
#define mod 1000000007
#define ip pair<int,int>
#define iv vector<int>
#define vr vector
#define pb push_back
 
#define ct(a,b,c) {cout << a << " " << b << " " << c << "\n";}
 
using namespace std;
 
int n;
 
void addh(int p, int c, int y) {
	for (int i=1;i<n;i++) {
		ct(0,p,p+1);
		ct(2,p+1,p+2);
		for (int j=1;j<n;j++) {	
			ct(y,p+1,p+12);
			ct(c+1,p+12,c+1);
		}
		for (int j=1;j<n;j++) {		
			ct(p+2,c+1,p+3);
			ct(y,p+3,p+13);
			ct(c,p+13,c);
		}
		ct(y,p+1,p+14);
		ct(p,p+14,p);	
	}
}
 
void add(int a, int b, int c) {
	ct(n+a,1,n+100);
	ct(n+b,1,n+c+1);
	ct(0,1,n+110);
	ct(2,n+110,n+111);
	addh(n+100,n+c,n+111);
}
 
void mul(int a, int b, int c) {
	ct(n+b,1,n+100);
	for (int i=1;i<n;i++) {
		ct(0,n+100,n+101);
		ct(2,n+101,n+102);
		ct(n+a,1,n+1000);
		addh(n+1000,n+c,n+102);
		ct(n+100,n+101,n+100);
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int l[n][n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			l[i][j] = ((j>0)?i:((i>0)?(i-1):(n-1)));
			cout << l[i][j] << " ";
		}
		cout << "\n";
	}
	
	int m[9];
	for (int i=0;i<9;i++) {
		m[i] = 16+i*2;
	}
	if (n == 3) cout << 552 << "\n";
	if (n == 5) cout << 2508 << "\n";
	if (n == 7) cout << 6872 << "\n";
	mul(0,2,8);
	mul(1,2,10);
	mul(0,3,12);
	mul(1,3,14);
	add(14,13,m[0]);
	add(m[0]+1,11,m[1]);
	add(m[0],m[1],m[2]);
	add(m[2]+1,12,m[3]);
	add(m[3]+1,10,m[4]);
	add(m[4]+1,9,m[5]);
	add(m[3],m[4],m[6]);
	add(m[6]+1,m[5],m[7]);
	add(m[7]+1,8,m[8]);
	ct(n+15,1,n+7);
	ct(n+m[1]+1,1,n+6);
	ct(n+m[5]+1,1,n+5);
	ct(n+m[8]+1,1,n+4);
} 
