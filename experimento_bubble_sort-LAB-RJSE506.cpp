#include <iostream>
#include <chrono>

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;


Node* createNode(int);
void insertEnd(Node**, int); 
void displayList(Node*);

void swapValue(Node**, Node*, Node*);
void bubbleSort(Node**);
void optimizedBubbleSort(Node**);


int main()
{
    Node* head = nullptr;
    
    insertEnd(&head, 3);
    insertEnd(&head, 1);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 2);
    
    displayList(head);
    
    swapValue(&head, head -> ptrNext, head -> ptrNext -> ptrNext);
    
    displayList(head);
    
    // bubbleSort(&head);
    
    // displayList(head);
    
    optimizedBubbleSort(&head);
    
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

// Função para trocar dois nós de uma lista
void swapValue(Node** head, Node* node1, Node* node2)
{
    // Se a lista for nula, não faz nada
    if (*head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    // Se algum nó for nulo, não faz nada
    if (node1 == nullptr || node2 == nullptr)
    {
        cout << "Nó(s) inválido(s)" << endl;
        return;
    }
    
    // Se os nós não forem consecutivos, não faz nada
    if (node1 -> ptrNext != node2)
    {
        cout << "Nós inválidos: precisam ser consecutivos" << endl;
        return;
    }
    
    // Se o nó 1 não for o primeiro da lista...
    if (node1 -> ptrPrev != nullptr)
    {
        // O seguinte ao que vem antes dele passa a ser o nó 2
        node1 -> ptrPrev -> ptrNext = node2;
    }
    // Se o nó 1 for o primeiro da lista...
    else
    {
        // Atualiza o head
        *head = node2;
    }
    // Se o nó 2 não for o último da lista...
    if (node2 -> ptrNext != nullptr)
    {
        // O anterior ao que vem depois dele passa a ser o nó 1
        node2 -> ptrNext -> ptrPrev = node1;
    }
    
    // O seguinte ao nó 1 passa a ser o seguinte ao nó 2
    node1 -> ptrNext = node2 -> ptrNext;
    // O anterior ao nó 2 passa a ser o anterior ao nó 1
    node2 -> ptrPrev = node1 -> ptrPrev;
    // O anterior ao nó 1 passa a ser o nó 2
    node1 -> ptrPrev = node2;
    // O seguinte ao nó 2 passa a ser o nó 1
    node2 -> ptrNext = node1;
}

// Função não otimizada do bubble sort
void bubbleSort(Node** head)
{
    // Se a lista for vazia, não faz nada
    if (*head == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    
    // Se o nó recebido não for o primeiro da lista, não faz nada
    if ((*head) -> ptrPrev != nullptr)
    {
        cout << "Nó inválido: não é o início da lista" << endl;
    }
    
    // Nó para controlar o número de iterações sobre a lista
    Node* outerLoop = *head;
    // Nó para iterar sobre a lista
    Node* innerLoop = *head;
    
    // Enquanto o número de iterações for menor que n-1...
    while (outerLoop -> ptrNext != nullptr)
    {
        // Reseta o innerLoop para o head
        innerLoop = *head;
        
        // Enquanto não chegar ao último elemento da lista...
        while (innerLoop -> ptrNext != nullptr)
        {
            // Se o valor dele for maior que o do seguinte...
            if (innerLoop -> iPayload > innerLoop -> ptrNext -> iPayload)
            {
                // Troca os nós
                swapValue(head, innerLoop, innerLoop -> ptrNext);
                // Mantém o innerLoop no atual
                innerLoop = innerLoop -> ptrPrev;
            }
            
            // Avança na lista
            innerLoop = innerLoop -> ptrNext;
        }
        
        // "Soma" 1 iteração
        outerLoop = outerLoop -> ptrNext;
    }
}

// Função otimizada do bubble sort
void optimizedBubbleSort(Node** head)
{
    // Se a lista for vazia, não faz nada
    if (*head == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    
    // Se o nó recebido não for o primeiro da lista, não faz nada
    if ((*head) -> ptrPrev != nullptr)
    {
        cout << "Nó inválido: não é o início da lista" << endl;
    }
    
    // Nó para controlar as iterações triangulares
    Node* outerLoop = *head;
    
    // Esse nó vai começar igual ao último nó da lista
    while (outerLoop -> ptrNext != nullptr)
    {
        outerLoop = outerLoop -> ptrNext;
    }
    
    // Nó para iterar sobre a lista
    Node* innerLoop = *head;
    
    // Enquanto não acabar as iterações triangulares...
    while (outerLoop -> ptrPrev != nullptr)
    {
        // Reseta o innerLoop para o head
        innerLoop = *head;
        cout << "Teste1  " << outerLoop -> iPayload << endl;
        
        // Enquanto não chegar ao fim dessa iteração...
        while (innerLoop -> ptrNext != outerLoop)
        {
            cout << innerLoop -> iPayload << endl;
            cout << "Next " << innerLoop -> ptrNext -> iPayload << endl;
            
            // Se o valor dele for maior que o do seguinte...
            if (innerLoop -> iPayload > innerLoop -> ptrNext -> iPayload)
            {
                // Troca os nós
                swapValue(head, innerLoop, innerLoop -> ptrNext);
                innerLoop = innerLoop -> ptrPrev;
            }
            
            // Avança na lista
            innerLoop = innerLoop -> ptrNext;
            
            cout << "Depois" << endl;
            cout << innerLoop -> iPayload << endl;
            cout << "Next " << innerLoop -> ptrNext -> iPayload << endl;
            
            // displayList(*head);
        }
        
        // Diminui em 1 as iterações necessárias
        outerLoop = outerLoop -> ptrPrev;
    }
}
















