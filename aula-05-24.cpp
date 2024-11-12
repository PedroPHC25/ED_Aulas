#include <iostream>

using namespace std;

// ÁRVORES

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

Node* newNode(int);
Node* insertNode(Node*, int);
Node* searchNode(Node*, int);
Node* deleteNode(Node*, int);
Node* lesserLeaf(Node*);

void traversePreOrder(Node*);
void traverseInOrder(Node*);
void traversePostOrder(Node*);



int main()
{
    // Exemplo 1: árvore binária
    Node* root_1 = newNode(1);
    root_1 -> ptrLeft = newNode(7);
    root_1 -> ptrRight = newNode(13);
    root_1 -> ptrLeft -> ptrLeft = newNode(42);
    root_1 -> ptrLeft -> ptrRight = newNode(111);
    
    // Exemplo 2: árvore binária de busca
    // Valores menores à esquerda e maiores à direita
    Node* root_2 = newNode(42);
    root_2 -> ptrLeft = newNode(7);
    root_2 -> ptrRight = newNode(666);
    root_2 -> ptrLeft -> ptrLeft = newNode(1);
    root_2 -> ptrLeft -> ptrRight = newNode(13);
    
    cout << "Atravessar root_2 - PreOrder: ";
    traversePreOrder(root_2);
    cout << endl;
    
    cout << "Atravessar root_2 - InOrder:  ";
    traverseInOrder(root_2);
    cout << endl;
    
    cout << "Atravessar root_2 - PostOrder:";
    traversePostOrder(root_2);
    cout << endl;
    
    cout << "================================================" << endl;
    
    // Busca de nós
    string resultado;
    
    resultado = (nullptr == searchNode(nullptr, 42)) ? "OK" : "Deu ruim";
    cout << "Busca 42 em nullptr: " << resultado << endl;
    
    resultado = (root_2 == searchNode(root_2, 42)) ? "OK" : "Deu ruim";
    cout << "Busca 42 em root_2: " << resultado << endl;
    
    resultado = (root_2 -> ptrLeft == searchNode(root_2, 7)) ? "OK" : "Deu ruim";
    cout << "Busca 7 em root_2: " << resultado << endl;
    
    resultado = (root_2 -> ptrLeft -> ptrLeft == searchNode(root_2, 1)) ? "OK" : "Deu ruim";
    cout << "Busca 1 em root_2: " << resultado << endl;
    
    resultado = (nullptr == searchNode(root_2, 10)) ? "OK" : "Deu ruim";
    cout << "Busca 10 em root_2: " << resultado << endl;
    
    cout << "================================================" << endl;
    
    // Menor nó do root_2
    Node* ptrLesserLeaf = lesserLeaf(root_2);
    cout << "Menor nó folha: " << ptrLesserLeaf -> iPayload << endl;
    
    cout << "================================================" << endl;
    
    // Exemplo 3: agora com insertNode
    Node* root = nullptr;
    root = insertNode(root, 42);
    root = insertNode(root, 7);
    root = insertNode(root, 666);
    root = insertNode(root, 1);
    root = insertNode(root, 13);
    
    cout << "Atravessar root - PreOrder: ";
    traversePreOrder(root);
    cout << endl;
    
    cout << "Atravessar root - InOrder:  ";
    traverseInOrder(root);
    cout << endl;
    
    cout << "Atravessar root - PostOrder:";
    traversePostOrder(root);
    cout << endl;
    
    cout << "================================================" << endl;
    
    // Menor nó do root
    ptrLesserLeaf = lesserLeaf(root);
    cout << "Menor nó folha: " << ptrLesserLeaf -> iPayload << endl;
    
    cout << "================================================" << endl;
    
    cout << "Atravessar root - PreOrder: ";
    traversePreOrder(root);
    cout << endl;
    
    deleteNode(root, 7);
    
    cout << "Atravessar root - PreOrder: ";
    traversePreOrder(root);
    cout << endl;
    
    return 0;
}


Node* newNode(int iData)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    
    if (temp != nullptr)
    {
        temp -> iPayload = iData;
        temp -> ptrLeft = nullptr;
        temp -> ptrRight = nullptr;
    }
    
    return temp;
}

// Agora, a função retorna a árvore com o nó inserido
Node* insertNode(Node* startingNode, int iData)
{
    if (startingNode == nullptr)
    {
        return newNode(iData);
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

Node* searchNode(Node* ptrStartingNode, int iData)
{
    if (ptrStartingNode == nullptr)
    {
        cout << "Elemento não encontrado" << endl;
        return nullptr;   
    }
    else if (iData == ptrStartingNode -> iPayload)
    {
        return ptrStartingNode;
    }
    else if (iData < ptrStartingNode -> iPayload)
    {
        return searchNode(ptrStartingNode -> ptrLeft, iData);
    }
    else
    {
        return searchNode(ptrStartingNode -> ptrRight, iData);
    }
}

Node* lesserLeaf(Node* ptrStartingNode)
{
    Node* ptrCurrent = ptrStartingNode;
    
    while (ptrCurrent && ptrCurrent -> ptrLeft != nullptr)
    {
        ptrCurrent = ptrCurrent -> ptrLeft;
    }
    
    return ptrCurrent;
}

Node* deleteNode(Node* ptrStartingNode, int iData)
{
    if (ptrStartingNode == nullptr)
    {
        cout << "Elemento não encontrado" << endl;
        return nullptr;
    }
    
    if (iData < ptrStartingNode -> iPayload)
    {
        ptrStartingNode -> ptrLeft = deleteNode(ptrStartingNode -> ptrLeft, iData);
    }
    else if (iData > ptrStartingNode -> iPayload)
    {
        ptrStartingNode -> ptrRight = deleteNode(ptrStartingNode -> ptrRight, iData);
    }
    else
    {
        Node* ptrTemp = nullptr;
        
        if (ptrStartingNode -> ptrLeft == nullptr)
        {
            ptrTemp = ptrStartingNode -> ptrRight;
            free(ptrStartingNode);
            return ptrTemp;
        }
        else if (ptrStartingNode -> ptrRight == nullptr)
        {
            ptrTemp = ptrStartingNode -> ptrLeft;
            free(ptrStartingNode);
            return ptrTemp;
        }
        
        ptrTemp = lesserLeaf(ptrStartingNode -> ptrRight);
        
        ptrStartingNode -> iPayload = ptrTemp -> iPayload;
        
        ptrStartingNode -> ptrRight = deleteNode(ptrStartingNode -> ptrRight, ptrTemp -> iPayload);
    }
    
    return ptrStartingNode;
}

void traversePreOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode -> iPayload;
        traversePreOrder(ptrStartingNode -> ptrLeft);
        traversePreOrder(ptrStartingNode -> ptrRight);
    }
}

void traverseInOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traverseInOrder(ptrStartingNode -> ptrLeft);
        cout << " " << ptrStartingNode -> iPayload;
        traverseInOrder(ptrStartingNode -> ptrRight);
    }
}

void traversePostOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traversePostOrder(ptrStartingNode -> ptrLeft);
        traversePostOrder(ptrStartingNode -> ptrRight);
        cout << " " << ptrStartingNode -> iPayload;
    }
}

// As reversas é apenas trocar o ramo direito pelo esquerdo