#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//R表示绳子压住的尾部,value表示绳头压住的值，也可能不存在，没关系
//就是查有多少值大于绳头的值，返回最近的下标
int nearIndex(vector<int>&arr,int R,int value)
{
	int L=0;
	int index=R;
	while(L<=R)
	{
		int mid=L+((R-L)>>1);
		if(arr[mid]>=value)
		{
			index=mid;
			R=mid-1;
		}
		else
		{
			L=mid+1;
		}
	}
	return index;
}

int maxPoint01(vector<int>&arr,int K)
{
	if(arr.size()==0)
	{
		return 0;
	}
	int len=arr.size();
	int ways=1;
	for(int i=0;i<arr.size();++i)
	{
		int nearindex=nearIndex(arr,i,arr[i]-K);
		ways=max(ways,i-nearindex+1);
	}
	return ways;
}

//利用滑动窗口
int maxPoint02(vector<int>&arr,int K)
{
	int ways=0;
	int left=0;
	int right=0;
	while(left<arr.size())
	{
		while(right<arr.size()&&arr[right]-arr[left]<=K)
		{
			++right;
		}
		ways=max(ways,right-left);
		++left;
	}
	return ways;
}




//方法一：两个for
int test(vector<int>&arr,int K)
{
	int ways=0;
	int count=0;
	for(int i=0;i<arr.size();++i)
	{
		for(int j=i;j<arr.size();++j)
		{
			if(arr[j]-arr[i]>K)
			{
				break;
			}
			++count;
		}
		ways=max(ways,count);
		count=0;
	}
	return ways;
}

void generateRandomArray(vector<int>&arr,int maxLen,int maxValue)
{
	int len=rand()%maxLen;
	arr.resize(len);
	for(int i=0;i<arr.size();++i)
	{
		arr[i]=rand()%maxValue;
	}
	sort(arr.begin(),arr.end());
}

void printArray(vector<int>&arr)
{
	for(int i=0;i<arr.size();++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int maxLen=100;
	int maxValue=100;
	int testTimes=10000;
	vector<int>arr;
	cout<<"test begin"<<endl;
	for(int i=0;i<testTimes;++i)
	{
		generateRandomArray(arr,maxLen,maxValue);
		int K=rand()%maxLen;
		int ways1=test(arr,K);
		int ways2=maxPoint01(arr,K);
		int ways3=maxPoint02(arr,K);
		if(ways1!=ways3||ways1!=ways2||ways2!=ways3)
		{
			cout<<"Opes!!!"<<endl;
			cout<<ways1<<" "<<ways2<<" "<<ways3<<endl;
			cout<<"K=="<<K<<endl;
			printArray(arr);
			break;
		}
	}
	cout<<"test finsh!!!"<<endl;
	
	return 0;
}