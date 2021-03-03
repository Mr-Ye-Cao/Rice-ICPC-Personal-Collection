/***
 Minimum spanning tree
 https://open.kattis.com/problems/communicationssatellite
***/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
public:
	double x,y,r;	
};

class Edge
{
public:
	double src,des,weight;	
};

class subset
{
public:
	int parent;
	int rank;	
};

int comp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

int find(subset subsets[], int i){
	if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
	int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin>>n;

	Node * nodes = new Node[n];
	for(int i=0;i<n;i++){
		double a,b,c;
		cin>>a>>b>>c;
		nodes[i].x=a;
		nodes[i].y=b;
		nodes[i].r=c;
	}

	Edge * edges = new Edge[n*(n-1)/2];
	int k=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			edges[k].src=i;
			edges[k].des=j;
			edges[k].weight=sqrt(pow(nodes[i].x-nodes[j].x,2)+pow(nodes[i].y-nodes[j].y,2))-nodes[i].r-nodes[j].r;
			k++;
		}
	}

	qsort(edges,n*(n-1)/2,sizeof(edges[0]),comp);

	subset* subsets = new subset[(n*sizeof(subset))];

	for(int i=0;i<n;i++){
		subsets[i].parent=i;
		subsets[i].rank=0;	
	}

	int e=0;
	int i=0;
	double result=0;
	while(e<n-1 && i<n*(n-1)/2){
		Edge next_edge = edges[i++];

		int x=find(subsets,next_edge.src);
		int y=find(subsets,next_edge.des);

		if(x!=y){
			result += next_edge.weight;
			Union(subsets,x,y);
		}
	}
	cout<<result<<endl;

	return 0;
}
