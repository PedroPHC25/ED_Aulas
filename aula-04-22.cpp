#include <iostream>

using std::cout;
using std::endl;

///// LISTA DUPLAMENTE ENCADEADA /////

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;


Node* createNode(int);
// A estrutura agora é apenas um ponteiro pra nó
// Ela é um ponteiro pro ponteiro pro primeiro elemento
void insertFront(Node**, int); 
void insertEnd(Node**, int); 
void displayList(Node*);
void insertAfter(Node*, int);
void deleteNode(Node**, Node*);
void insertBefore(Node*, int); // TODO
void deleteNodebyValue(Node**, int); // TODO
Node* searchNodebyValue(Node**, int); // TODO


int main()
{
    // A lista agora é um ponteiro pro primeiro elemento
    Node* head = nullptr; 

    cout << "===================================================================" << endl;
    
    displayList(head);

    cout << "===================================================================" << endl;
    
    // O endereço do ponteiro pro primeiro elemento é um ponteiro pro ponteiro pro primeiro elemento
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    
    displayList(head);
    
    cout << "===================================================================" << endl;
    
    insertFront(&head, 65);
    insertFront(&head, 78);
    
    displayList(head);
    
    cout << "===================================================================" << endl;
    
    insertAfter(head, 10);
    insertAfter(head, 13);
    
    displayList(head);
    
    cout << "===================================================================" << endl;
    
    deleteNode(&head, head);
    
    displayList(head);
    
    return 0;
}


Node* createNode(int iPayload)
{
    // Sem a conversão dá um ponteiro pra void
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node)
{
    // Se o nó é nulo, a lista é vazia
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }
    
    // Se o nó tem algo antes dele, é um nó do meio da lista ou o último
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou fim da lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    Node* temp = node;
    
    cout << "Payload: ";
    
    while (temp != nullptr)
    {
        cout << temp -> iPayload << " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    // newNode -> ptrPrev = nullptr;
    
    // Se a lista não está vazia...
    if (*head != nullptr)
    {
        // O anterior ao antigo primeiro passa a ser o novo
        (*head) -> ptrPrev = newNode;
        // O seguinte ao novo nó é o antigo primeiro
        newNode -> ptrNext = (*head);
        // O novo nó passa a ser o primeiro
        (*head) = newNode;
        
        return;
    }
    
    // Se ela está vazia, o novo nó passa a ser o primeiro
    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload)
{
    // Criando o nó
    Node* newNode = createNode(iPayload);
    // newNode -> ptrNext = nullptr;
    
    // Se o ponteiro pro head for nulo
    if (*head == nullptr) 
    {
        // newNode -> ptrPrev = nullptr;
        
        // Parênteses: convenção de programação
        // O primeiro passa a ser o novo
        (*head) = newNode; 
        return;
    }
    
    Node* temp = (*head);
    
    // Encontra o final da lista
    while (temp -> ptrNext != nullptr)
    {
        temp = temp -> ptrNext;
    }
    
    // O anterior do novo é o antigo último
    newNode -> ptrPrev = temp;
    // O seguinte do antigo último é o novo
    temp -> ptrNext = newNode;
}

void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    // Corrigir nó a ser inserido
    // O anterior ao novo nó é a localização
    newNode -> ptrNext = ptrLocation -> ptrNext;
    // O seguinte ao novo nó é o seguinte à localização
    newNode -> ptrPrev = ptrLocation;
    
    // Corrigir o ponto de inserção
    // O seguinte à localização passa a ser o novo nó
    ptrLocation -> ptrNext = newNode;
    
    // Se a localização não for o final da lista...
    if (newNode -> ptrNext != nullptr)
    {
        // O anterior do seguinte ao novo nó passa a ser o novo nó
        newNode -> ptrNext -> ptrPrev = newNode;
    }
}

void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }
    
    // Se for o primeiro elemento...
    if (*head == ptrDelete)
    {
        // O novo passa a ser o segundo
        (*head) = ptrDelete -> ptrNext;
    }
    
    // Se não for o último nó...
    if (ptrDelete -> ptrNext != nullptr)
    {
        ptrDelete -> ptrNext -> ptrPrev = ptrDelete -> ptrPrev;
    }
    
    // Se não for o primeiro nó...
    if (ptrDelete -> ptrPrev != nullptr)
    {
        ptrDelete -> ptrPrev -> ptrNext = ptrDelete -> ptrNext;
    }
    
    free(ptrDelete);
}

////////////////////////////////////////////////////////////////////////////////
// Exercício 1. Elaborar a função "void insertBefore(Node*, int)".
// Exercício 2. Elaborar a função "void deleteNodebyValue(Node**, int)".
// Exercício 3. Elaborar a função "Node* searchNodebyValue(Node**, int)".
////////////////////////////////////////////////////////////////////////////////