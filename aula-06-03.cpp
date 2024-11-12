#include <iostream>

using namespace std;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
int treeHeight(Node*);


int main()
{
    Node* root = nullptr;
    
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    cout << "Tree Height: " << treeHeight(root) << endl;

    return 0;
}


Node* createNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    
    
    if (temp == nullptr)
    {
        // cout de erro
        cerr << "Erro em createNode: malloc" << endl;
        // Sai completamente do programa (1: deu erro)
        exit(1);
    }
    
    temp -> iPayload = iValue;
    temp -> ptrLeft = nullptr;
    temp -> ptrRight = nullptr;
    
    return temp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if (startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if (iData < startingNode -> iPayload)
    {
        startingNode -> ptrLeft = insertNode(startingNode -> ptrLeft, iData);
    }
    else
    {
        startingNode -> ptrRight = insertNode(startingNode -> ptrRight, iData);
    }

    return startingNode;
}

void bfsTraversal(Node* startingNode)
{
    if (startingNode == nullptr)
    {
        return;
    }
    
    // Parte 1 do trabalho: alterar para lista encadeada
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
    
    while (iQueueFront != iQueueRear)
    {
        Node* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;
        
        cout << currentNode -> iPayload << " ";
        
        if (currentNode -> ptrLeft != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode -> ptrLeft;
            iQueueRear++;
        }
        if (currentNode -> ptrRight != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode -> ptrRight;
            iQueueRear++;
        }
    }
    
    cout << endl;
}

// Parte 2 do trabalho: Elaborar busca utilizando BFS (já fizemos o DFS)
// Parte 3 do trabalho: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
// Parte 4 do trabalho: Monitorar o desempenho de criação de listas
// Parte 5 do trabalho: Monitorar o desempenho de criação de árvores
//      Considerar a SOMA do tempo de criação com o tempo de busca

int treeHeight(Node* startingNode)
{
    if (startingNode == nullptr)
    {
        return 0;
    }
    else
    {
        int iLeftHeight = treeHeight(startingNode -> ptrLeft);
        int iRightHeight = treeHeight(startingNode -> ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1;
    }
}