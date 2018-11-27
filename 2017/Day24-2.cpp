#include<fstream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string.h>
#include<bitset>
#include<ctime>
#include<set>
#include<cmath>
#include<unordered_map>
#include<iomanip>
#include<map>
#include<stack>
#include<vector>
#include<bitset>
#include<functional>
#include<iostream>
#include<deque>
#include<unordered_set>
#include<queue>
#include<list>
#include<array>
#include<ctype.h>
using namespace std;
long long i, j, k, x, y, z, ok, nr, n, m, el, min1, max1, cost, a, b, viz[150150],sum,howDown,maxHowDown;
string bridge,maxq;
vector<int>v[100];
vector<bool>removed[100];

void goDown(int nod)
{
	sum += nod;
	howDown++;
	for (auto it = v[nod].begin(); it != v[nod].end(); it++)
		if(removed[nod][it - v[nod].begin()]==0)
		{
			sum += *it;
			removed[nod][it - v[nod].begin()] = 1;
			for(auto iter=v[*it].begin();iter!=v[*it].end();iter++)
				if (*iter == nod&& removed[*it][iter - v[*it].begin()] == 0)
				{
					removed[*it][iter - v[*it].begin()] = 1;
					break;
				}
			goDown(*it);
			removed[nod][it - v[nod].begin()] = 0;
			for (auto iter = v[*it].begin(); iter != v[*it].end(); iter++)
				if (*iter == nod&&removed[*it][iter - v[*it].begin()] == 1)
				{
					removed[*it][iter - v[*it].begin()] = 0;
					break;
				}
			if (howDown == 30)
			{
				max1 = max(max1, sum);
				maxHowDown = max(maxHowDown, howDown);
			}
			sum -= *it;
		}
	sum -= nod;
	howDown--;
}
int main()
{
	ifstream f("file.in");
	ofstream g("file.out");
	for (int i = 1; i <= 54; i++)
	{
		f >> bridge;
		j = 0;
		x = 0;
		y = 0;
		while (bridge[j] != '/')
		{
			x = x * 10 + (bridge[j] - '0');
			j++;
		}
		j++;
		while (j != bridge.length())
		{
			y = y * 10 + (bridge[j] - '0');
			j++;
		}
		v[x].push_back(y);
		v[y].push_back(x);
		removed[x].push_back(0);
		removed[y].push_back(0);
	}
	goDown(0);
	cout << max1;
	return 0;
}
