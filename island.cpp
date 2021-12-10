#include <iostream>
using namespace std;

class island
{
	public:
	int arr[50][50];
	int parent[50][50];
	int m,n;
	island();
	void Union(int,int,int,int);
	void union_main();
	//void makeset();
	int * find(int,int,int[]);
	int count();
};

island :: island()
{
	int i,j;
	cout<<"Enter the number of rows and columns"<<endl;
	cin>>m>>n;
	
	//for(i=0;i<(m*n)-1;i++)
	//parent[i]=i;
	cout<<"Enter the 2D array"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
			parent[i][j]=-1;
		}
	}
	
}


int * island::find(int a,int b,int r[])
{
	int x,y;
	if(parent[a][b]==-1)
	{
		r[0]=a;
		r[1]=b;
		return r;
	}
	x=parent[a][b]/n;
	y=parent[a][b]%n;
	return find(x,y,r);			
}

void island::Union(int x,int y,int a,int b)
{
	//printf("a");
	int r1[2],r2[2];
	find(x,y,r1);
	find(a,b,r2);
	if(r1[0]==r2[0] && r1[1]==r2[1])
	return;
	else
	parent[r1[0]][r1[1]]=(r2[0]*n)+r2[1];
	//printf("%d",(r2[0]*m)+r2[1]);
}

void island::union_main()
{
	int x,y;//k=-1;
	
	for(x=0;x<m;x++)
	{
		for(y=0;y<n;y++)
		{
			//printf("b");
			//k++;
			//printf("%d ",arr[x][y]);
			if(arr[x][y]==1)
			{
				//printf("b");
				if(x-1>=0 && y-1>=0 && arr[x-1][y-1]==1 && parent[x-1][y-1]==-1)
				Union(x,y,x-1,y-1);
				if(x>=0 && y-1>=0 && arr[x][y-1]==1 && parent[x][y-1]==-1)
				Union(x,y,x,y-1);
				if(x+1>=0 && y-1>=0 && arr[x+1][y-1]==1 && parent[x+1][y-1]==-1)
				Union(x,y,x+1,y-1);
				if(x-1>=0 && y>=0 && arr[x-1][y]==1 && parent[x-1][y]==-1)
				Union(x,y,x-1,y);
				if(x+1>=0 && y>=0 && arr[x+1][y]==1 && parent[x+1][y]==-1)
				Union(x,y,x+1,y);
				if(x-1>=0 && y+1>=0 && arr[x-1][y+1]==1 && parent[x-1][y+1]==-1)
				Union(x,y,x-1,y+1);
				if(x>=0 && y+1>=0 && arr[x][y+1]==1 && parent[x][y+1]==-1)
				Union(x,y,x,y+1);
				if(x+1>=0 && y+1>=0 &&  arr[x+1][y+1]==1 && parent[x+1][y+1]==-1)
				Union(x,y,x+1,y+1);
			}
		}
	}		
}

int island::count()
{
	int count=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(parent[i][j]==-1 && arr[i][j]==1)
			count++;
			//printf("%d ",parent[i][j]);
		}
	}
	return count;
}
		
		
int main()
{
	island is;
	
	is.union_main();
	int c=is.count();
	//printf("\n%d",c);
	cout<<"\nNumber of islands: "<<c;
	return 0;
}
	
	
/*
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1
 */
