#include<iostream>
#include<vector>
#include<deque>
#include<vector>
#include<limits.h>
#include<ctime>
using namespace std;

int MinLengthForSort01(vector<int>&arr)
{
	if(arr.size()<2)
	{
		return 0;
	}
	int right=0;
	int max_value=INT_MIN;
	int N=arr.size();

	for(int i=0;i<N;i++)
	{
		if(max_value>arr[i])
		{
			right=i;
		}
		max_value=max(max_value,arr[i]);
	}

	int left=N;
	int min_value=INT_MAX;

	for(int i=N-1;i>=0;i--)
	{
		if(min_value<arr[i])
		{
			left=i;
		}
		min_value=min(min_value,arr[i]);
	}

	return max(0,right-left+1);
}

void printArray(vector<int>&arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int maxLen=10;
	int maxValue=20;
	srand(time(nullptr));
	vector<int>arr(rand()%maxLen+1);
	for(int i=0;i<arr.size();i++)
	{
		arr[i]=rand()%maxValue;
	}
	
	int ans=MinLengthForSort01(arr);
	cout<<"ans=="<<ans<<endl;
	printArray(arr);
	return 0;
}
