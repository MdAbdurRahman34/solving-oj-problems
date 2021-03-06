#include <bits/stdc++.h>
using namespace std;

#define mx 100005
int arr[mx];
int tree[mx * 4];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
main()
{
    int n,t,i,j,m,x,p,q;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        scanf("%d%d",&n,&m);
        for(j=1;j<=n;j++) scanf("%d",&arr[j]);
        init(1, 1, n);
        for(j=0;j<m;j++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&p);
                printf("%d\n",arr[p+1]);
                update(1, 1, n, p+1, 0);
                arr[p+1]=0;
            }
            else if(x==2)
            {
                scanf("%d%d",&p,&q);
                arr[p+1]+=q;
                update(1, 1, n, p+1, arr[p+1]);
            }
            else if(x==3)
            {
                scanf("%d%d",&p,&q);
                printf("%d\n",query(1, 1, n, p+1, q+1));
            }
        }
    }
    return 0;
}
