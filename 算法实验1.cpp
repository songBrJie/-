#include<stdio.h>
 
int f[105][105];
void package(int *w,int *v,int n,int c)
{
	for(int i=1;i<=n;i++)//背包容量
		f[i][0] = 0;i -
	for(int i=1;i<=c;i++)//物品个数
		f[0][i] = 0;	
	int i,j;	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			//当容量(注1)够放入第i个物品,并且放入之后的价值(放入之后他的价值+剩余背包容量对应的价值)要比不放(不放入他,背包当前容量对应的价值)大
			if(j>=w[i]&&f[i-1][j-w[i]]+v[i]>f[i-1][j])
			{
				f[i][j]=f[i-1][j-w[i]]+v[i];			
			}else
				f[i][j]=f[i-1][j];
		}
	}
}
//1.(此容量并非剩余容量(相同当前背包容量下,上一步较少物品时对应的剩余的背包容量)而是当前背包总容量(并非全局背包总容量)即j非c) 
int main()
{
	int c,n,w[105],v[105];
	scanf("%d %d",&c,&n);
	//c:背包容量     n:物品数量 
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


