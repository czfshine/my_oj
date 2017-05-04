// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2017年04月16日 星期日 23时20分59秒
// File Name     : A.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MaxN=1000;
const int MaxM=1000000;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow,cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int pre[MaxN],couNode[MaxN],lowcost[MaxN];
bool vis[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	Ecou=0;
	S=_S;
	T=_T;

	for(int i=1;i<=N;++i)
		head[i]=-1;
}

void addEdge(int u,int v,int cap,int cost)
{
	E[Ecou].to=v;
	E[Ecou].cap=cap;
	E[Ecou].cost=cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
	E[Ecou].to=u;
	E[Ecou].cap=0;
	E[Ecou].cost=-cost;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

bool SPFA(int N)
{
	queue <int> que;
	int u,v,c;

	for(int i=1;i<=N;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
		pre[i]=-1;
	}
	vis[S]=1;
	lowcost[S]=0;
	couNode[S]=1;

	que.push(S);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;
		
		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			c=E[i].cost;

			if(E[i].cap>E[i].flow && lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;
				pre[v]=i;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	if(pre[T]==-1)
		return 0;
	return 1;
}

void update(int remm,int &minCost)
{
	for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
	{
		E[i].flow+=remm;
		E[i^1].flow-=remm;
		minCost+=E[i].cost*remm;
	}
}

int MinCostMaxFlow(int N,int &minCost)		//返回最大流，minCost是在最大流时的最小费用。
{
	int ret=0,remm;
	minCost=0;

	while(SPFA(N))
	{
		remm=INF;

		for(int i=pre[T];i!=-1;i=pre[E[i^1].to])
			remm=min(remm,E[i].cap-E[i].flow);
		update(remm,minCost);
		ret+=remm;
	}

	return ret;
}

/////////////////////////////////

int N,M;
bool VIS[33][33];

int val1[33][33];
int val2[33][33];

inline int change(int x,int y) {
	return (x-1)*M+y;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,Q;

	while(~scanf("%d %d",&N,&M)) {
		int coui=0,couo=0;

		init(N*M+2,N*M+1,N*M+2);

		memset(VIS,0,sizeof(VIS));
		scanf("%d",&Q);
		while(Q--) {
			scanf("%d %d",&a,&b);
			VIS[a][b]=1;
		}

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(VIS[i][j]);
				else {
					if((i+j)&1) addEdge(change(i,j),T,1,0),++couo;
					else addEdge(S,change(i,j),1,0),++coui;
				}

		for(int i=1;i<=N;++i)
			for(int j=1;j<M;++j)
				scanf("%d",&val1[i][j]);
		for(int i=1;i<N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&val2[i][j]);

		//cout<<coui<<' '<<couo<<endl;

		if(coui!=couo) {
			puts("-1");
			continue;
		}

		for(int i=1;i<=N;++i)
			for(int j=1;j<M;++j)
				if((i+j)&1) addEdge(change(i,j+1),change(i,j),INF,val1[i][j]);
				else addEdge(change(i,j),change(i,j+1),INF,val1[i][j]);

		for(int i=1;i<N;++i)
			for(int j=1;j<=M;++j)
				if((i+j)&1) addEdge(change(i+1,j),change(i,j),INF,val2[i][j]);
				else addEdge(change(i,j),change(i+1,j),INF,val2[i][j]);

		int ans=0;
		if(MinCostMaxFlow(N*M+2,ans)!=coui) puts("-1");
		else printf("%d\n",ans);
	}

	return 0;
}
