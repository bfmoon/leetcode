#include<iostream>
#include<vector>
using namespace std;

/*
题目：让B和G交换，返回B交换到左边或者G交换到左边的那个交换次数少？
注意：只相邻的才可以交换
*/


int minSteps1(vector<char>& str)
{
	if(str.size()==0)
	{
		return 0;
	}
	int step1=0;
	int step2=0;
	int bi=0;
	int gi=0;
	for(int i=0;i<str.size();++i)
	{
		if(str[i]=='G')
		{
			step1+=i-gi;
			gi++;
		}
		else
		{
			step2+=i-bi;
			bi++;
		}
	}
	return min(step1,step2);
}

int minSteps2(vector<char>& str)
{
	if(str.size()==0)
	{
		return 0;
	}
	int step1=0;
	int step2=0;
	int bi=0;
	int gi=0;
	for(int i=0;i<str.size();++i)
	{
		if(str[i]=='G')
		{
			step1+=i-gi;
			gi++;
		}
	}
	
	for(int i=0;i<str.size();++i)
	{
		if(str[i]=='B')
		{
			step2+=i-bi;
			bi++;
		}
	}
	return min(step1,step2);
}



//for test
void randomString(vector<char>&str,int maxLen)
{
	int len=rand()%maxLen;
	str.resize(len);
	for(int i=0;i<str.size();++i)
	{
		str[i]=(((rand()%10)+1.0)/10.0)<0.5?'G':'B';
	}
}

void printArray(vector<char>&str)
{
	for(int i=0;i<str.size();++i)
	{
		cout<<str[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int maxLen=100;
	int testTimes=10000;
	vector<char>str;
	cout<<"test begin"<<endl;
	for(int i=0;i<testTimes;++i)
	{
		randomString(str,maxLen);
		int ans1=minSteps1(str);
		int ans2=minSteps2(str);
		if(ans1!=ans2)
		{
			cout<<"Opes!!!"<<endl;
			cout<<ans1<<" "<<ans2<<endl;
			printArray(str);
			break;
		}
	}
	cout<<"test finsh"<<endl;
	return 0;
}
