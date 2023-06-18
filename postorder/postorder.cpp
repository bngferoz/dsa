#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char info[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int leftChild[10] = {1, 3, 5, -1, -1, 8, -1, -1, -1, -1};
    int rightChild[10] = {2, 4, 6, 7, -1, 9, -1, -1, -1, -1};
    int root = 0;
    stack<int> tree;
    stack<int> output; // Stack to store the postorder traversal
    tree.push(root);

    while (!tree.empty()) {
        int pointer = tree.top();
        tree.pop();
        output.push(pointer);

        if (leftChild[pointer] != -1)
            tree.push(leftChild[pointer]);
        if (rightChild[pointer] != -1)
            tree.push(rightChild[pointer]);
    }

    while (!output.empty()) {
        int pointer = output.top();
        output.pop();
        cout << info[pointer] << endl;
    }

    return 0;
}
