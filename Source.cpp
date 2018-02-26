//  #define _CRT_SECURE_NO_WARNINGS
//             ��� ������� ������

#include<iostream>	
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cmath>
#include<climits>
#include<string>
#include<iomanip>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>
#include<fstream>
#include<bitset>
using namespace std;
//********************************************************************************************
//******************************************************************************************** 
/*
jesus help me.......
*/
typedef long long lld;
typedef char c;



/*
jesus help me.......
jesus help me.......
jesus help me.......
*/



int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;

}





bool sortbysec(const pair<char, int> &a, const pair<char, int> &b)
{
	return (a.second > b.second);
}
////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
long long sum1(int n, long long a)
{
	if (n == 0)
		return 1;
	return 	a*sum1(n - 1, a + 1);


}
////////////////////////////////////////////////////////////////////
int n;
vector<string>v;
int sum = 0;
vector<vector<int>>vis(102, vector<int>(102, 0));
int d[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
//////////////////////////////////////////////////////////////////
void dfs(int a, int b, int n, int m, int x, int y, int &count, bool &bo)
{

	if (a < 0 || b < 0 || a >= n || b >= m)
	{
		return;
	}
	if (vis[a][b] == 1 || v[a][b] != v[x][y])
		return;
	if (a == x&&b == y)
	{
		count = 0;
		bo = false;
		return;
	}
	vis[a][b] = 1;
	count++;

	if (b == m - 1)
	{
		dfs(a, 0, n, m, x, y, count, bo);
	}
	if (b == 0)
	{
		dfs(a, m - 1, n, m, x, y, count, bo);
	}
	for (int i = 0; i < 4; i++)
	{
		dfs(a + d[i][0], b + d[i][1], n, m, x, y, count, bo);

	}

}
////////////////////////////////////////////////////////////////////
/*int connected_component(int n,vector<vector<int>>v,vector<bool>&vis)
{
int count = 0;
for (int i = 'A'; i <= n; i++)
{
if (!vis[i])
{
count++;
dfs(i,v,vis);
}
}
return count;

}*/
//////////////////////////////////////////////////////////////////
long long s = LLONG_MAX;

void flood_fill(int x, int y)
{


}
void fun()
{

}
/////////////////////////////////////////////////////////////////
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);


	//freopen("keys.in", "r", stdin);

	int n;

		cin >> n;
	vector<int>v(n);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
		
	}
	int q;
	cin >> q;
	vector<pair<int, int>>pr;
	for (int i = 0; i<q; i++)
	{
		int x, y;
		cin >> x >> y;
		pr.push_back(make_pair(x-1, y-1));
	}
	sort(pr.begin(), pr.end());
	vector<int>v2;
	for (int i = 0; i < pr[0].first;i++)	{
		v2.push_back(v[i]);
	}									   
	int x = pr[0].first, y = pr[0].second;
	for (int i = 1; i < pr.size(); i++)
	{
		if (pr[i].first <= y)
		{
			if (pr[i].second > y)
				y = pr[i].second;
		}
		else
		{
			for (int j = y+1; j < pr[i].first; j++)
				v2.push_back(v[j]);
			y = pr[i].second;
		}
	}
	for (int j = y + 1; j < v.size(); j++)
		v2.push_back(v[j]);
	cout << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	system("pause");

	return 0;
}