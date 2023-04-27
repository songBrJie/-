#include <iostream>
using namespace std;
 
#define N 2010
int w[N];    //每个物品的重量
int v[N];    //每个物品的价值
int x[N];     //x[i]=1：物品i放入背包，0代表不放入
int n,c;       //n：一共有多少物品，c：背包的最大容量
int CurrentWeight = 0;  //当前放入背包的物品总重量
int CurrentValue = 0;   //当前放入背包的物品总价值
/*
*BestValue 和 BestX在找到一个叶子节点时进行 约束函数 判断，满足的话就连同修改储存的最优解
*/
int BestValue = 0;  //最优值；当前的最大价值，初始化为0
int BestX[N];       //最优解；BestX[i]=1代表物品i放入背包，0代表不放入
 
void input()
{   int p;
	cin>>p;
    while(p--){
    cout<<"请输入物品个数和背包最大容量："<<endl;
    cin>>n; 
	cin>>c;
    cout<<"输入物品的价值"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    cout<<"输入物品的重量"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>w[i];
    }
	}
}
void output()
{
    cout<<"最优值是:"<<BestValue<<endl;
    cout<<"(";
    for(int i=1;i<=n;i++)
        cout<<BestX[i]<<" ";
    cout<<")";
 
}
/*
*回溯函数 参数t表示当前处在第几层做抉择，t=1时表示当前在决定是否将第一个物品放入背包
*/
void backtrack(int t)
{ 
    //叶子节点，输出结果
    if(t>n)
    {
        //如果找到了一个更优的解
        if(CurrentValue>BestValue)
        {
            //保存更优的值和解
            BestValue = CurrentValue;
            for(int i=1; i<=n; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //遍历当前节点的子节点：0 不放入背包，1放入背包
        for(int i=0; i<=1; ++i)
        {
            x[t]=i;
            //cout<<t<<" "<<i<<endl;     查看遍历结果 
            if(i==0) //不放入背包
            {   
                backtrack(t+1);
            }
            else //放入背包
            {
                //约束条件：放的下
                if((CurrentWeight+w[t])<=c)
                {
                    CurrentWeight += w[t];
                    CurrentValue += v[t];
                    backtrack(t+1);
                    CurrentWeight -= w[t];
                    CurrentValue -= 
					v[t];
                }
            }
        }
    }
}
int main(int argc, char* argv[])
{
 
    input();  
    backtrack(1);
    output();
    return 0;
}

