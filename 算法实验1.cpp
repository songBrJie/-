#include<stdio.h>
 
int f[105][105];
void package(int *w,int *v,int n,int c)
{
	for(int i=1;i<=n;i++)//��������
		f[i][0] = 0;i -
	for(int i=1;i<=c;i++)//��Ʒ����
		f[0][i] = 0;	
	int i,j;	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			//������(ע1)�������i����Ʒ,���ҷ���֮��ļ�ֵ(����֮�����ļ�ֵ+ʣ�౳��������Ӧ�ļ�ֵ)Ҫ�Ȳ���(��������,������ǰ������Ӧ�ļ�ֵ)��
			if(j>=w[i]&&f[i-1][j-w[i]]+v[i]>f[i-1][j])
			{
				f[i][j]=f[i-1][j-w[i]]+v[i];			
			}else
				f[i][j]=f[i-1][j];
		}
	}
}
//1.(����������ʣ������(��ͬ��ǰ����������,��һ��������Ʒʱ��Ӧ��ʣ��ı�������)���ǵ�ǰ����������(����ȫ�ֱ���������)��j��c) 
int main()
{
	int c,n,w[105],v[105];
	scanf("%d %d",&c,&n);
	//c:��������     n:��Ʒ���� 
	w[0]=0;
	for(int i=1;i<n+1;i++)
		scanf("%d",&w[i]);
	v[0]=0;
	for(int i=1;i<n+1;i++)
		scanf("%d",&v[i]);

	int i,j;
	package(w,v,n,c);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=c;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}

}


