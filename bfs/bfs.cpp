#include<iostream>
#include<queue>
using namespace std;
int vertArr[6][6];
int count = 0;
queue<int> q;
//q.push(0);
//q.pop();
//int u = tree.front();
int color[6], previous[6], d[6];

BFS(){
    for(int u=0;u<6;u++){
        color[u] = 0;
        previous[u] = -1;
        d[u] = -1;
    }
    color[0] = 1;
    d[0] = 0;
    previous[0] = -1;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0;v<6;v++){
            if(vertArr[u][v]==1 && color[v]==0){
                color[v] = 1;
                d[v] = d[u]+1;
                previous[v] = u;
                q.push(v);
            }
        }
        color[u] = 2;
    }
}

void displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}
void add_edge(int u, int v) {
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}
main(int argc, char* argv[]) {
   int v = 6;
   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);
   displayMatrix(v);
   BFS();
   for(int i=0;i<6;i++){
    cout<<color[i]<<endl;
   }
}


