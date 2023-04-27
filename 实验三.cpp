#include <iostream>
using namespace std;
 
#define N 2010
int w[N];    //ÿ����Ʒ������
int v[N];    //ÿ����Ʒ�ļ�ֵ
int x[N];     //x[i]=1����Ʒi���뱳����0��������
int n,c;       //n��һ���ж�����Ʒ��c���������������
int CurrentWeight = 0;  //��ǰ���뱳������Ʒ������
int CurrentValue = 0;   //��ǰ���뱳������Ʒ�ܼ�ֵ
/*
*BestValue �� BestX���ҵ�һ��Ҷ�ӽڵ�ʱ���� Լ������ �жϣ�����Ļ�����ͬ�޸Ĵ�������Ž�
*/
int BestValue = 0;  //����ֵ����ǰ������ֵ����ʼ��Ϊ0
int BestX[N];       //���Ž⣻BestX[i]=1������Ʒi���뱳����0��������
 
void input()
{   int p;
	cin>>p;
    while(p--){
    cout<<"��������Ʒ�����ͱ������������"<<endl;
    cin>>n; 
	cin>>c;
    cout<<"������Ʒ�ļ�ֵ"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    cout<<"������Ʒ������"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>w[i];
    }
	}
}
void output()
{
    cout<<"����ֵ��:"<<BestValue<<endl;
    cout<<"(";
    for(int i=1;i<=n;i++)
        cout<<BestX[i]<<" ";
    cout<<")";
 
}
/*
*���ݺ��� ����t��ʾ��ǰ���ڵڼ���������t=1ʱ��ʾ��ǰ�ھ����Ƿ񽫵�һ����Ʒ���뱳��
*/
void backtrack(int t)
{ 
    //Ҷ�ӽڵ㣬������
    if(t>n)
    {
        //����ҵ���һ�����ŵĽ�
        if(CurrentValue>BestValue)
        {
            //������ŵ�ֵ�ͽ�
            BestValue = CurrentValue;
            for(int i=1; i<=n; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //������ǰ�ڵ���ӽڵ㣺0 �����뱳����1���뱳��
        for(int i=0; i<=1; ++i)
        {
            x[t]=i;
            //cout<<t<<" "<<i<<endl;     �鿴������� 
            if(i==0) //�����뱳��
            {   
                backtrack(t+1);
            }
            else //���뱳��
            {
                //Լ���������ŵ���
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

