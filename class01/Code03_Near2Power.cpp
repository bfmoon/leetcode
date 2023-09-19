#include<iostream>
using namespace std;

//题目：返回>=num最近的2的某次方的值


//思路：就是将num的1的最高位后面全变为1.然后加一即可
int tableSizeFor(int n)
{
	if(n<0)
	{
		return 0;
	}
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	n|=n>>8;
	n|=n>>16;
	
	return n>0?n+1:0;
}

int main()
{
	int num=35;
	cout<<tableSizeFor(num)<<endl;
	return 0;
}