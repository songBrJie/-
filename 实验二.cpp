#include<stdio.h>
#define MAX(a,b) (a>b?a:b)
int state[1001][1001];//�洢״̬
int main()
{
	int N,V;
	scanf("%d%d",&N,&V);
	int v[1001],w[1001];//v[i]�洢�� i ����Ʒ�������w[i]�� i ����Ʒ�ļ�ֵ
	int i;
	for(i=1;i<=N;i++){
	    scanf("%d%d",&v[i],&w[i]);
	}
	int j;
	for(i=1;i<=N;i++){//��Ӧ���ϱ��д��µ���
	    for(j=1;j<=V;j++){//��Ӧ���ϱ��д�����
	        if(i>1){
	            if(j-v[i]<0){//�� i ����Ʒ���̫�󣬲��÷��뱳��
	                state[i][j]=state[i-1][j];
	            }else{//�� i ����Ʒ�������������Ҫ�Ӽ�ֵ�Ϻ���
	                state[i][j]=MAX(state[i-1][j],state[i-1][j-v[i]]+w[i]);
	            }
	        }else{//״̬��ʼ��
	            if(j>=v[i]){
	                state[i][j]=w[i];
	            }
	        }
	    }
	}
	printf("���Ľ��Ϊ��%d",state[N][V]);
	return 0;
}	
