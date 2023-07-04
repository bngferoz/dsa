#include<iostream>
#include<queue>
using namespace std;

int r = 0;
int Q();
int key[8];
int pi[8];
int T[8];
int G[8][8];

void prim(){

    for(int i=0;i<8;i++){
        key[i] = 777;
        T[i] = 0;
        pi[i] = -1;
    }

    key[r] = 0;
    pi[r] = -1;

    for(int i=0;i<8;i++){
        int u = Q();
        T[u]= 1;

        for (int v = 0; v < 8; v++){
            if (G[u][v]>0 && T[v] == 0 && G[u][v] < key[v]){
                    pi[v] = u;
                    key[v] = G[u][v];
				}
        }


    }
}



void add_edge(int u, int v, int weight) {
   G[u][v] = weight;
   G[v][u] = weight;
}
void print();
int main(){

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            G[i][j] = 0;
        }
    }

    add_edge(0,2,47);
    add_edge(0,4,80);
    add_edge(0,5,54);

    add_edge(1,2,55);
    add_edge(1,3,31);
    add_edge(1,4,32);
    add_edge(1,6,78);
    add_edge(1,7,79);

    add_edge(2,3,88);
    add_edge(2,4,23);
    add_edge(2,5,75);
    add_edge(2,6,66);


    add_edge(3,5,74);
    add_edge(3,7,29);

    add_edge(4,6,93);


    add_edge(6,7,68);

    prim();

    print();

    return 0;
}


int Q()
{
	int min = 777, min_index;

	for (int v = 0; v < 8; v++)
		if (T[v] == 0 && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void print()
{
    int sum = 0;
	cout << "Edge \tWeight\n";
	for (int i = 1; i < 8; i++){
        sum=sum+G[i][pi[i]];
	}
    cout<<sum<<endl;
}
