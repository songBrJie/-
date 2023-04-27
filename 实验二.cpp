#include<stdio.h>
#define MAX(a,b) (a>b?a:b)
int state[1001][1001];//存储状态
int main()
{
	int N,V;
	scanf("%d%d",&N,&V);
	int v[1001],w[1001];//v[i]存储第 i 件物品的体积，w[i]第 i 件物品的价值
	int i;
	for(i=1;i<=N;i++){
	    scanf("%d%d",&v[i],&w[i]);
	}
	int j;
	for(i=1;i<=N;i++){//对应于上表中从下到上
	    for(j=1;j<=V;j++){//对应于上表中从左到右
	        if(i>1){
	            if(j-v[i]<0){//第 i 件物品体积太大，不用放入背包
	                state[i][j]=state[i-1][j];
	            }else{//第 i 件物品体积允许，但还需要从价值上衡量
	                state[i][j]=MAX(state[i-1][j],state[i-1][j-v[i]]+w[i]);
	            }
	        }else{//状态初始化
	            if(j>=v[i]){
	                state[i][j]=w[i];
	            }
	        }
	    }
	}
	printf("最后的结果为：%d",state[N][V]);
	return 0;
}	
