#include<stdio.h>
int main()
{
    int n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        printf("%d\n",(a/2)+1);
    }
    return 0;
}
