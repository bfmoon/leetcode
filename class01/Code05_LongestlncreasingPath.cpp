#include<iostream>
#include<vector>
using namespace std;

/*
leetcode:392
*/

int process01(vector<vector<int>>&arr,int i,int j)
{
	int up=i>0&&arr[i][j]<arr[i-1][j]?process01(arr,i-1,j):0;
	int down=i<(arr.size()-1)&&arr[i][j]<arr[i+1][j]?process01(arr,i+1,j):0;
	int left=j>0&&arr[i][j]<arr[i][j-1]?process01(arr,i,j-1):0;
	int right=j<(arr.size()-1)&&arr[i][j]<arr[i][j+1]?process01(arr,i,j+1):0;
	
	return max(max(up,down),max(left,right));
}

int longestIncreasingPath1(vector<vector<int>>&arr)
{
	int x=arr.size();
	int y=arr[0].size();
	int ans=0;
	for(int i=0;i<x;++i)
	{
		for(int j=0;j<y;++j)
		{
			ans=min(ans,process01(arr,i,j);
		}
	}
	return ans;
}

//记忆化搜索
int process02(vector<vector<int>>&arr,int i,int j,vector<vector<int>>&dp)
{
	//从缓存中找
	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}
	int up=i>0&&arr[i][j]<arr[i-1][j]?process01(arr,i-1,j):0;
	int down=i<(arr.size()-1)&&arr[i][j]<arr[i+1][j]?process01(arr,i+1,j):0;
	int left=j>0&&arr[i][j]<arr[i][j-1]?process01(arr,i,j-1):0;
	int right=j<(arr.size()-1)&&arr[i][j]<arr[i][j+1]?process01(arr,i,j+1):0;
	
	int ans=max(max(up,down),max(left,right));
	//挂缓存
	dp[i][j]=ans;
	return ans;
}

int longestIncreasingPath2(vector<vector<int>>&arr)
{
	
	int N=arr.size();
	int M=arr.size();
	vector<vector<int>>dp(N,vector<int>(M,0));
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			ans=min(ans,process02(arr,i,j,dp);
		}
	}
}


