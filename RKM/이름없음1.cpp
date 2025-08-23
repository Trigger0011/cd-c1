
#include<cstdio>
char f[51] = {0, };

int go(int now)
{
	printf("%d %c",now, f[now]);

	if(now > 50) 
	{
		return 50;
	} 
	else if (now < 1) 
	{
		return 1;
	}
	
	if (f[now] == 0){
		return now;
	}
	
	int next;
	if (f[now] <= 'z' && f[now] >= 'a') 
	{
		next = now - (f[now] - 'a' + 1);
	} 
	else if (f[now] <= 'Z' && f[now] >= 'A') 
	{
		next = now + (f[now] - 'A' + 1);
	}
	return go(next);
}
int main()
{
	int a;	
	int n; 
	int b;
	int j;
	char k;
	scanf("%d",&n);                               
	for(int i=0;i<n;i++)
	{
		scanf("%d %c",&j, &k); 
		f[j]=k;
	}
	scanf("%d",&b);
	int result = go(1 + b);
	printf("%d", result);
}

