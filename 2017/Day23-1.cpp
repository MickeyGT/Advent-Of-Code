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
long long i, j, k, x, y, z, ok, nr, n, m, el, min1, max1, cost, a, b, viz[150150],sum,howDown,maxHowDown,nod=0;
vector < tuple <string, char,string>> v;
string instr,value;
char registr;
long long regs[10];

void execute()
{
	tie(instr,registr,value) = v[nod];
	if (instr == "set")
	{
		if (value.length() == 1 && value[0] >= 'a'&&value[0] <= 'i')
		{
			regs[registr - 'a'] = regs[value[0]-'a'];
		}
		else
			regs[registr - 'a'] = stoi(value);
		++nod;
	}
	else
		if (instr == "sub")
		{
			if (value.length() == 1 && value[0] >= 'a'&&value[0] <= 'i')
			{
				regs[registr - 'a'] -= regs[value[0] - 'a'];
			}
			else
				regs[registr - 'a'] -= stoi(value);
			++nod;
		}
		else
			if (instr == "mul")
			{
				nr++;
				if (value.length() == 1 && value[0] >= 'a'&&value[0] <= 'i')
				{
					regs[registr - 'a'] *= regs[value[0] - 'a'];
				}
				else
					regs[registr - 'a'] *= stoi(value);
				++nod;
			}
			else
				if (instr == "jnz")
				{
					if (registr != '0')
					{
						if (registr == '1')
						{
							if (value.length() == 1 && value[0] >= 'a'&&value[0] <= 'i')
							{
								nod += regs[value[0] - 'a'];
							}
							else
								nod += stoi(value);
						}
						else
						{
							if (regs[registr - 'a'] != 0)
							{
								if (value.length() == 1 && value[0] >= 'a'&&value[0] <= 'i')
								{
									nod += regs[value[0] - 'a'];
								}
								else
									nod += stoi(value);
							}
							else
								nod++;
						}
					}
					else
						nod++;
				}
}
int main()
{
	ifstream f("file.in");
	ofstream g("file.out");
	for (int i = 1; i <= 32; i++)
	{
		f >> instr>>registr>>value;
		v.push_back(make_tuple(instr, registr, value));
	}
	while(nod < v.size())
		execute();
	cout << nr;
	return 0;
}
