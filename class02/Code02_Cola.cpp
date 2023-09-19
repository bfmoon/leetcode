#include<iostream>
#include<vector>
#include<ctime>


using namespace std;

void giveRest(vector<int>&money,vector<int>&zhang,int i,int curMoney,int times)
{
	for(;i<3;i++)
	{
		zhang[i]+=(curMoney/money[i])*times;
		curMoney%=money[i];
	}
}

int minBuyFre01(int m,int a,int b,int c,const int X)
{
	vector<int>zhang={c,b,a};
	vector<int>money={100,50,10};
	//表示之前剩余的总钱数
	int preQianRest=0;
	//表示之前面值剩余的张数
	int preZhangRest=0;
	int puts=0;
	for(int i=0;i<3&&m!=0;i++)
	{
		//表示当前面值第一次买可乐的张数，就是除去上一次剩下的面值后，当前面值买一平的张数
		int curQianFirstBuyZhang=(X-preQianRest+money[i]-1)/money[i];
		//如果当前面值的张数大于除去上一次余额后买可乐的张数，则足够买
		if(zhang[i]>=curQianFirstBuyZhang)
		{
			//买一次之后的找零
			giveRest(money,zhang,i+1,(curQianFirstBuyZhang*money[i]+preQianRest)-X,1);
			//投币的次数加上当前面值购买的张数和上一次的张数
			puts+=curQianFirstBuyZhang+preZhangRest;
			//当前面值减去，买后的张数
			zhang[i]-=curQianFirstBuyZhang;
			m--;
		}
		//如果当前面值的张数小于除去上一次余额后买可乐的张数，则说明该面值也是剩余的了
		else 
		{
			//累加之前剩余的总钱数
			preQianRest +=zhang[i]*money[i];
			preZhangRest +=zhang[i];
			continue;
		}
		//这里是处理买完第一瓶之后的情况
		//当前面值买一瓶需要多少张
		int curQianBuyOneColaZhang=(X+money[i]-1)/money[i];
		//当前面值购买可乐的个数
		int curQianBuyColas=min(m,zhang[i]/curQianBuyOneColaZhang);
		//买完之后，当前面值剩余的钱
		int oneTimeRest=money[i]*curQianBuyOneColaZhang-X;
		//找零
		giveRest(money,zhang,i+1,oneTimeRest,curQianBuyColas);

		puts+=curQianBuyOneColaZhang*curQianBuyColas;

		m-=curQianBuyColas;

		zhang[i]-=curQianBuyOneColaZhang*curQianBuyColas;
		//处理之前的面值剩余
		preQianRest=zhang[i]*money[i];
		preZhangRest=zhang[i];
	}
	return m==0?puts:-1;	
}

//暴力方法
int minBuyFre02(int m,int a,int b,int c,int x)
{
    vector<int>zhang={c,b,a};
	vector<int>qian={100,50,10};
	int puts=0;
	int rest=0;
	
	while(m!=0)
	{
		rest=x;
		while(rest!=0)
		{
			int first=-1;
			for(int i=0;i<3;i++)
			{
				if(zhang[i]!=0)
				{
					first=i;
					break;
				}
			}

			if(first!=-1)
			{
				if(qian[first]>=rest)
				{
					giveRest(qian,zhang,first+1,qian[first]-rest,1);
					zhang[first]--;
					puts++;
					rest=0;
				}
				else
				{
					zhang[first]--;
					rest=rest-qian[first];
					puts++;
				}
			}
			else
			{
				return m==0?puts:-1;
			}
		}
		m--;
	}
	return puts;
}

int main()
{
	int zhangMax=10;
	int colaMax=10;
	int qianMax=20;
	int testTimes=1000;
	cout<<"test begin"<<endl;
	srand(time(nullptr));
	for(int i=0;i<testTimes;i++)
	{
		int m=rand()%colaMax+1;
		int a=rand()%zhangMax;
		int b=rand()%zhangMax;
		int c=rand()%zhangMax;
		int X=(rand()%qianMax+1)*10;
			
		int ans1=minBuyFre01(m,a,b,c,X);
		int ans2=minBuyFre02(m,a,b,c,X);
		if(ans1!=ans2)
		{
			cout<<"Opes!!!"<<endl;
			cout<<"ans1=="<<ans1<<endl;
			cout<<"ans2=="<<ans2<<endl;
			cout<<"m=="<<m<<";a=="<<a<<";b=="<<b<<";c=="<<c<<";X=="<<X<<endl;
			break;
		}
	}
	cout<<"test finsh!!!!"<<endl;

	return 0;
}
