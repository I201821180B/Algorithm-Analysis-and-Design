#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int w,d; //d: dest or source
};

struct st
{
	int node,sn;
};

struct edges
{
	int s,d,w; //source,destination,weight
};

vector<edges> k_edge;
vector<vector<edge> > adjlist;
bool visited[9];
st sets[9];

void prims(int src);

void insert_edges(int src,int dest,int w)
{
	edge e1,e2;
	edges e;
	e1.w=e2.w=w;
	e1.d=dest;
	e2.d=src;
	adjlist[src].push_back(e1);
    adjlist[dest].push_back(e2);
    e.s=src;
    e.d=dest;
    e.w=w;
    k_edge.push_back(e);
}

void reset()
{
	for(int i=0;i<9;i++)
	    visited[i]=false;
}

bool compare(edge x,edge y)
{
	return x.w>y.w;
}

void kruskal();
int parent(int s)
{
	if(sets[s].sn==sets[s].node)
	    return sets[s].node;
	return parent(sets[s].sn);
}

void matchpar(int s,int d)
{
	int ps=parent(s);
	int ds=parent(d);
	sets[ds].sn=sets[ps].sn;
}
bool kcomp(edges x,edges y)
{
	return x.w<y.w;
}


void prims(int src)
{

	cout<<"source is "<<src<<endl;
	vector<edge> edge_w;
	for(vector<edge>::iterator it=adjlist[src].begin();it!=adjlist[src].end();++it)
	{
		edge_w.push_back(*it);
	}

    make_heap(edge_w.begin(),edge_w.end(),compare);
	visited[src]=true;
	int cnt=1;
	while(cnt<9)
	{
		edge taken;
		pop_heap(edge_w.begin(),edge_w.end(),compare);
		taken=edge_w.back();
		edge_w.pop_back();
		if(visited[taken.d])
		    continue;
		visited[taken.d]=true;cnt++;
		cout<<"node included is "<<taken.d<<"  with edge weight : "<<taken.w<<endl;
		for(vector<edge>::iterator it=adjlist[taken.d].begin();it!=adjlist[taken.d].end();++it)
		    {
			   //not visited
				if(!visited[it->d])
				{
	                edge_w.push_back(*it);
					push_heap(edge_w.begin(),edge_w.end(),compare);
		    }
		}
	}

}


void kruskal()
{

	for(int i=0;i<9;i++)
	    sets[i].node=sets[i].sn=i;

   //edges sorted in non decreasing order
	sort(k_edge.begin(),k_edge.end(),kcomp);

	int cnt=0;
	int i=0;
	edges x;
	while(cnt!=8)
	{
		x=k_edge[i++];

		if(parent(x.s)==parent(x.d))
		{
			continue;
		}
		else
		{
			//should not form a cycle
			matchpar(x.s,x.d);
			cnt++;
			cout<<"edge included has nodes "<<x.s<<"\t"<<x.d<<" with edge weight "<<x.w<<endl;
		}
	}

}

int main()
{

	adjlist.resize(9);

	insert_edges(0,1,4);
    insert_edges(0,7,8);
    insert_edges(1,2,8);
    insert_edges(1,8,17);
    insert_edges(1,7,11);
    insert_edges(2,3,9);
    insert_edges(2,5,4);
    insert_edges(2,8,2);
    insert_edges(3,4,4);
    insert_edges(3,5,14);
    insert_edges(4,5,7);
    insert_edges(5,8,9);
    insert_edges(5,6,2);
    insert_edges(6,8,6);
    insert_edges(6,7,1);
    insert_edges(7,8,7);

	reset();
	int source = 0;
	cout<<"Prim's algorithm:\n";
	prims(source);
	cout<<endl;
	cout<<"Kruskal's algorithm:\n";
	kruskal();

   system("pause");
	return 0;

}
