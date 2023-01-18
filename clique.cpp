#include <iostream>
using namespace std;

const int MAX = 5000;

int store[MAX], n;

int graph[MAX][MAX];

int d[MAX];
int k;

int max (int a,int b)
{
    if(a>b){
        return a;
    }
    return b;
}

bool is_clique(int b)
{
	
	for (int i = 1; i < b; i++)
    {
		for (int j = i + 1; j < b; j++)
        {

			if (graph[store[i]][store[j]] == 0)
            {
				return false;
            }
        }
	}
	return true;
}


void print(int n)
{
    cout<<"( ";
for (int i = 1; i < n; i++)
    {
		cout << store[i] << " ";
    }
    cout<<" ) ";
	cout << ", ";
	
}

int maxCliques(int i, int l)
{
    int maximum = 0;


    for (int j = i + 1; j <= n; j++)
    {
        store[l] = j;

        if (is_clique(l + 1)) 
        {

            maximum = max(maximum, l);

            maximum = max(maximum, maxCliques(j, l + 1));
        }
    }
    return maximum;
}

void findCliques(int i, int l, int s)
{
	for (int j = i + 1; j <= n - (s - l); j++)
    {

		if (d[j] >= s - 1) 
        {

			store[l] = j;

			
			if (is_clique(l + 1))
            {


				if (l < s)
                {

					findCliques(j, l + 1, s);
                }

				else
                {
					print(l + 1);
                }
            }
		}
    }    
}

int main()
{
    int pairs ;
    cout<<"Enter the number of pairs to join "<<endl;
    cin>>pairs;
    int c=2;
    int edges[pairs][c];
    cout<<"Enter vertices pair wise "<<endl;
    for(int i=0;i<pairs;i++)
    {
        for(int j=0;j<c;j++ )
        {
            cin>>edges[i][j];
        }
    }

cout<<"Enter the size of clique to find whether its there or not "<<endl;
cin>>k;
	int size = sizeof(edges) / sizeof(edges[0]);
	n = pairs-1;


	for (int i = 0; i < size; i++) 
    {
		graph[edges[i][0]][edges[i][1]] = 1;
		graph[edges[i][1]][edges[i][0]] = 1;
		d[edges[i][0]]++;
		d[edges[i][1]]++;
	}
cout <<"The entered graph has maximum clique of size "<<maxCliques(0, 1)<<endl;
cout<<"The pairs with the size "<<k<<" are"<<endl;
if(k>maxCliques(0, 1))
{
    cout<<"0 "<<endl;
}
else
{
	findCliques(0, 1, k);
}

	return 0;
}
/*
1 2     
2 3
3 1
4 3
4 5
5 3 
2 4
*/