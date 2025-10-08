//生成10个1—100之间的随机数存入数组，要求数据不能重复
//1）求出所有数据的和
//2）求出所有数据的平均数
//3）统计有多少个数据比平均值小
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int contains(int arr[],int len,int num);

int main()
{
	
	int arr[10]={0};
	int len = sizeof(arr)/sizeof(int);
	//生成随机数 
	srand(time(NULL));
	int i=0;
	for(;i<len;)
	{
		int num = rand()%100+1;
		int flag = contains(arr, len , num);
		if (!flag)
		{
			arr[i] = num;
			printf("%d\n",arr[i]);
			i++;
		}
	}
	//再做一个循环来相加
	int sum=0;
	i=0; 
	for (;i<len;i++)
	{
		sum = sum + arr[i];
	}
	printf("%d\n",sum); 
	//求所有数的平均数
	double avg=sum/i;
	printf("平均数是%.2lf\n",avg);
	//统计有多少个数比平均数小
	int stats=0;
	i=0;
	for(;i<len;i++)
	{
		if(arr[i]<avg)
		{
			stats++;
		}
	} 
	printf("%d",stats);
	return 0;
 } 
 //判断这个数字是否存在
 //如果存在，返回1   不存在返回0 
 int contains(int arr[],int len,int num)
 {
 	int i=0;
 	for(; i < len; i++)
 	{
 		if (arr[i] == num)
 		{
 			return 1;
		}
	}
	return 0;
 }
