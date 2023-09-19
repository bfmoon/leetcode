#include<iostream>
#include<vector>
using namespace std;

/*
返回组成target的方法数
leetcode:494
*/

//数组，下标，剩余值
int process01(vector<int>&arr,int index,int rest)
{
	if(index==arr.size())
	{
		return rest==0?1:0;
	}
	//两数相减和相加的总和
	return process01(arr,index+1,rest-arr[index])+process01(arr,index+1,rest+arr[index]);
}

int findTargetSumWays1(vector<int>&arr,int target)
{
	return process01(arr,0,target);
}

//记忆化搜索,要三维数组的表，利用哈希表
int process02(vector<int>&arr,int index,int rest,vector<int>&dp)
{
	
}

int findTargetSumWays2(vector<int>&arr,int target)
{
	int len=arr.size();
	vector<int>dp(len,0);
	return process02(arr,0,target,dp);
}

