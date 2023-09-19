#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;

//动态规划，暴力尝试
int process01(vector<vector<int>>&income,int index,int rest)
{
	if(index==income.size())
	{
		return 0;
	}
	//表示还有司机
	if(income.size()-index==rest)
	{
		return income[index][0]+process01(income,index+1,rest-1);
	}
	if(rest==0)
	{
		return income[index][1]+process01(income,index+1,rest);
	}
	

	//index位置的的司机有两种选择，可能去A，也可能去B
	int p1=income[index][0]+process01(income,index+1,rest-1);
	int p2=income[index][1]+process01(income,index+1,rest);
	return max(p1,p2);
}

int getMaxMoney01(vector<vector<int>>&income)
{
	if(income.size()<2|| (income.size()&1)!=0)
	{
		return 0;
	}
	int N=income.size();
	int M=N>>1;
	
	return process01(income,0,M);
}

//动态规划，严格的表依赖
int getMaxMoney02(vector<vector<int>>&income)
{
	if(income.size()<2|| (income.size()&1)!=0)
	{
		return 0;
	}
	int N=income.size();
	int M=N>>1;
	vector<vector<int>>dp(N+1,vector<int>(M+1,0));
	for(int index=N-1;index>=0;index--)
	{
		for(int rest=0;rest<=M;rest++)
		{
			if(N-index==rest)
			{
				dp[index][rest]=income[index][0]+dp[index+1][rest-1];
			}
			else if(rest==0)
			{
				dp[index][rest]=income[index][1]+dp[index+1][rest];
			}
			else 
			{
				int p1=income[index][0]+dp[index+1][rest-1];
				int p2=income[index][1]+dp[index+1][rest];
				dp[index][rest]=max(p1,p2);
			}
		}
	}

	return dp[0][M];
}

int getMaxMoney03(vector<vector<int>>& income)
{
	if(income.size()<2||(income.size()&1)!=0)
	{
		return 0;
	}
	int N=income.size();
	int M=N>>1;

	vector<int>arr(N,0);

	int sum=0;
	for(int i=0;i<N;i++)
	{
		//计算等会那几个司机改变策略
		arr[i]=income[i][1]-income[i][0];
		//这是全部去A地区
		sum+=income[i][0];
	}
	sort(arr.begin(),arr.end());
	for(int i=N-1;i>=M;i--)
	{
		sum+=arr[i];
	}
	return sum;
}
//for test
vector<vector<int>> randomMatrix(int maxLen,int maxValue)
{
	int len=(rand()%maxLen+1)*2;
	vector<vector<int>>income(len,vector<int>(2,0));
	for(int i=0;i<income.size();i++)
	{
		for(int j=0;j<income[0].size();j++)
		{
			income[i][j]=rand()%maxValue;
		}
	}
	return income;
}

void printArray(vector<vector<int>>& income)
{
	for(int i=0;i<income.size();i++)
	{
		for(int j=0;j<income[0].size();j++)
		{
			cout<<income[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int maxLen=10;
	int maxValue=100;
	int testTime=500;
	srand(time(nullptr));
	cout<<"test begin!!!"<<endl;
	for(int i=0;i<testTime;i++)
	{
		vector<vector<int>>income=randomMatrix(maxLen, maxValue);
		int ans1=getMaxMoney01(income);
		int ans2=getMaxMoney02(income);
		int ans3=getMaxMoney03(income);
		if(ans1!=ans2||ans1!=ans3||ans2!=ans3)
		{
			cout<<"Opes!!!"<<endl;
			cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
			printArray(income);
			break;
		}
	}
	cout<<"test finsh!!!"<<endl;
				
	return 0;
}
