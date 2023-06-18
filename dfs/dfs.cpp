#include<iostream>
#include<queue>
using namespace std;
int vertArr[6][6];
int count = 0;
queue<int> q;
//q.push(0);
//q.pop();
//int u = tree.front();
int color[6], previous[6], d[6], f[6];
int time = 0;

void DFS_Visit(int u){
    color[u] = 1;
    time++;
    d[u] = time;
    for(int v=0;v<6;v++){
        if(vertArr[u][v] == 1 && color[v] == 0){
            previous[v] = u;
            DFS_Visit(v);
        }
    }
    color[u] = 2;
    time++;
    f[u] = time;
}
void DFS(){
    for(int u=0;u<6;u++){
        color[u] = 0;
        previous[u] = -1;
        d[u] = -1;
        f[u] = -1;
    }
    time = 0;
    for(int u=0;u<6;u++){
        if(color[u] == 0){
            DFS_Visit(u);
        }
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
   DFS();
   cout<<"color"<<endl;
   for(int i=0;i<6;i++){
    cout<<color[i]<<endl;
   }
   cout<<"finish time"<<endl;
   for(int i=0;i<6;i++){
    cout<<f[i]<<endl;
   }

}


