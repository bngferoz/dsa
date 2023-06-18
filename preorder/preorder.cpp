#include <iostream>
#include<stack>
using namespace std;

int main()
{
    char info[10] = {'A', 'B', 'C', 'D', 'E', 'F','G','H','I','J'};
    int leftChild[10] = {1,3,5,-1,-1,8,-1,-1,-1,-1};
    int rightChild[10] = {2,4,6,7,-1,9,-1,-1,-1,-1};
    int root = 0;
    stack<int> tree;
    tree.push(-1);
    int pointer = root;
    while(pointer !=-1){
        cout<<info[pointer]<<endl;
        if(rightChild[pointer]!=-1){
            tree.push(rightChild[pointer]);
        }
        if(leftChild[pointer]!=-1){
            pointer = leftChild[pointer];
        }
        else{
            pointer = tree.top();
            tree.pop();
        }

    }

    return 0;
}






