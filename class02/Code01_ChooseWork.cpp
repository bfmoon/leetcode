#include<iostream>
#include <type_traits>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ChooseWork1(vector<int>&hard,vector<int>&money,
				vector<int>&ability)
{
	int N=hard.size();
	int M=ability.size();
	vector<int>ans(M);
	for(int i=0;i<M;i++)
	{
		int ret=0;
		for(int j=0;j<N;j++)
		{
			if(ability[i]>=hard[j])
			{
				ret=max(ret,money[j]);
			}
		}
		ans[i]=ret;
	}
	return ans;
}

class Info
{
public:
	Info(int h,int m):hard(h),money(m){}
	int hard;
	int money;
};

void setValue(vector<int>&hard,vector<int>&money,
				vector<Info>&info)
{
	int N=hard.size();
	for(int i=0;i<N;i++)
	{
		Info info1(hard[i],money[i]);
		info.push_back(info1);
	}
}

vector<int> ChoseWork2(vector<int>&hard,vector<int>&money,
				vector<int>&ability)
{
	int M=ability.size();
	int N=hard.size();
	vector<Info>info;
	vector<int>ans(M);
	setValue(hard,money,info);
	sort(info.begin(),info.end(),[&](Info info1,Info info2)->bool{
				return info1.hard==info2.hard?info1.money>info2.money:
				info1.hard<info2.hard;
				});



}
