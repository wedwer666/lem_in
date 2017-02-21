/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:14:00 by mmitriuc          #+#    #+#             */
/*   Updated: 2017/02/08 20:13:03 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void dij(int n,int v,int cost[10][10],int dist[]);
int	 main()
{
	int n,v,i,j,cost[10][10],dist[10];
	printf("*** Dijkstra Algorithm ***\n");
	printf("Enter the total number of Nodes.\t");
	scanf("%d",&n);
	printf("Enter the cost matrix.\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	printf("Enter the source Vertex.\t");
	scanf("%d",&v);
	dij(n,v,cost,dist);
	printf("\nShortest path:\n");
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("V%d->V%d,cost=%d\n",v,i,dist[i]);
}
void dij(int n,int v,int cost[10][10],int dist[])
{
	int i,u,count,w,flag[10],min;
	for(i=1;i<=n;i++)
		flag[i]=0,dist[i]=cost[v][i];
	count=2;
	while(count<=n)
	{
		min=99;
		for(w=1;w<=n;w++)
			if(dist[w]<min && !flag[w])
				min=dist[w],u=w;
		flag[u]=1; count++;
		for(w=1;w<=n;w++)
			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
				dist[w]=dist[u]+cost[u][w];
	}

}
