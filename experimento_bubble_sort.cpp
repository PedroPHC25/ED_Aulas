#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::rand;

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
bool isListOrdered(Node**);
void cleanList(Node**);


int main()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    
    int iNumTests = 50;
    
    int arriTimes1[iNumTests] = {0};
    int arriTimes2[iNumTests] = {0};
    
    auto timeStart = high_resolution_clock::now();
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    for (int i = 0; i < iNumTests; i++)
    {
        srand(i);
        
        for (int j = 0; j < 10000; j++)
        {
            insertEnd(&head1, rand());
            insertEnd(&head2, rand());
        }
        
        timeStart = high_resolution_clock::now();
        bubbleSort(&head1);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTimes1[i] = timeDuration.count();
        
        timeStart = high_resolution_clock::now();
        optimizedBubbleSort(&head2);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        arriTimes2[i] = timeDuration.count();
        
        cleanList(&head1);
        cleanList(&head2);
        
        cout << "Testes completos: " << i + 1 << "/" << iNumTests << endl;
    }
    
    float fDiffMean = 0;
    
    for (int i = 0; i < iNumTests; i++)
    {
        fDiffMean = fDiffMean + (arriTimes1[i] - arriTimes2[i]);
    }
    
    fDiffMean = fDiffMean / iNumTests;
    
    cout << "O algoritmo otimizado é, em média, " << fDiffMean / 1000000000 << " segundos melhor que o não otimizado." << endl;
    
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

void swapValue(Node** head, Node* node1, Node* node2)
{
    if (head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    if (node1 == nullptr || node2 == nullptr)
    {
        cout << "Nó(s) inválido(s)" << endl;
        return;
    }

    if (node1 -> ptrPrev != nullptr)
    {
        node1 -> ptrPrev -> ptrNext = node2;
    }
    else
    {
        (*head) = node2;
    }

    if (node2 -> ptrNext != nullptr)
    {
        node2 -> ptrNext -> ptrPrev = node1;
    }

    node1 -> ptrNext = node2 -> ptrNext;
    node2 -> ptrPrev = node1 -> ptrPrev;
    node1 -> ptrPrev = node2;
    node2 -> ptrNext = node1;
}

void bubbleSort(Node** head)
{
    if (head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    Node* outerLoop = *head;
    Node* innerLoop = *head;
    
    do
    {
        innerLoop = *head;
        
        while (innerLoop -> ptrNext != nullptr)
        {
            if (innerLoop -> iPayload > innerLoop -> ptrNext -> iPayload)
            {
                swapValue(head, innerLoop, innerLoop -> ptrNext);
                innerLoop = innerLoop -> ptrPrev;
            }
            
            innerLoop = innerLoop -> ptrNext;
        }
        
        outerLoop = outerLoop -> ptrNext;
    }
    while (outerLoop != nullptr);
}

void optimizedBubbleSort(Node** head)
{
    if (head == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    bool bOrdered = true;
    Node* outerLoop = nullptr;
    Node* innerLoop = (*head);
    
    while (outerLoop == nullptr || outerLoop -> ptrPrev -> ptrPrev != nullptr)
    {
        bOrdered = true;
        innerLoop = *head;
        
        while (innerLoop -> ptrNext != outerLoop)
        {
            if (innerLoop -> iPayload > innerLoop -> ptrNext -> iPayload)
            {
                swapValue(head, innerLoop, innerLoop -> ptrNext);
                innerLoop = innerLoop -> ptrPrev;
                bOrdered = false;
            }
            
            innerLoop = innerLoop -> ptrNext;
        }
        
        if (bOrdered)
        {
            return;
        }
        
        if (outerLoop == nullptr)
        {
            outerLoop = (*head);
            while (outerLoop -> ptrNext != nullptr)
            {
                outerLoop = outerLoop -> ptrNext;
            }
        }
        else
        {
            outerLoop = outerLoop -> ptrPrev;
        }
    }
}

bool isListOrdered(Node** head)
{
    if ((*head) == nullptr)
    {
        cout << "Lista vazia" << endl;
        return true;
    }
    
    Node* current = (*head);
    bool bOrdered = true;
    
    while (current -> ptrNext != nullptr)
    {
        if (current -> iPayload > current -> ptrNext -> iPayload)
        {
            bOrdered = false;
            break;
        }
        
        current = current -> ptrNext;
    }
    
    return bOrdered;
}

void cleanList(Node** head)
{
    if ((*head) == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    
    Node* current = (*head);
    Node* previous = (*head);
    
    while (current != nullptr)
    {
        current = current -> ptrNext;
        free(previous);
        previous = current;
    }
    
    (*head) = nullptr;
}