#include <iostream>

using namespace std;

// Estrutura dos nós
typedef struct Node
{
    int iID;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Estrutura da lista circular
typedef struct LoopList
{
    Node* ptrFirst;
} LoopList;

// Protótipos
Node* createNode(int);
void insertNode(LoopList*, int);
void displayList(LoopList*);
LoopList* createLoopList();
LoopList* createListFromArray(int[], int);
int forwardList(LoopList*);
int backwardList(LoopList*);
void removeNode(LoopList*, int);
void deleteList(LoopList*);
LoopList* mixLists(LoopList*, LoopList*);
bool isThereLoop(LoopList*);


int main()
{
    // EXERCÍCIO 1A
    int arriTeste[5] = {1, 2, 3, 4, 5};
    LoopList* list = createListFromArray(arriTeste, 5);
    displayList(list);
    
    int iCurrent = forwardList(list);
    cout << "Atual: " << iCurrent << endl;
    cout << "Novo head: " << list -> ptrFirst -> iID << endl;
    
    iCurrent = backwardList(list);
    cout << "Atual: " << iCurrent << endl;
    cout << "Novo head: " << list -> ptrFirst -> iID << endl;
    
    cout << "=======================================================" << endl;
    
    // EXERCÍCIO 1B
    
    removeNode(list, 1);
    displayList(list);
    
    int arriTeste2[1] = {1};
    LoopList* list2 = createListFromArray(arriTeste2, 1);
    displayList(list2);
    
    removeNode(list2, 1);
    displayList(list2);
    
    deleteList(list);
    displayList(list);
    
    cout << "==================================================" << endl;

    // EXERCÍCIO 1C

    int arriTeste3[5] = {1, 3, 5, 7, 8};
    LoopList* list3 = createListFromArray(arriTeste3, 5);
    displayList(list3);
    
    int arriTeste4[3] = {2, 4, 6};
    LoopList* list4 = createListFromArray(arriTeste4, 3);
    displayList(list4);
    
    LoopList* mixedList = mixLists(list3, list4);
    displayList(mixedList);
    
    cout << "==================================================" << endl;

    // EXERCÍCIO 2
    
    cout << "Teste com loop para frente: " << isThereLoop(mixedList) << endl;
    
    // Quebrando a mixedList manualmente no final para testar quando tem loop apenas de trás pra frente
    Node* current = mixedList -> ptrFirst;
    while (current -> ptrNext != mixedList -> ptrFirst)
    {
        current = current -> ptrNext;
    }
    current -> ptrNext = nullptr;
    
    cout << "Teste com loop apenas para trás: " << isThereLoop(mixedList) << endl;
    
    // Quebrando a mixedList manualmente no início para testar quando não tem loop
    mixedList -> ptrFirst -> ptrPrev = nullptr;
    
    cout << "Teste sem loop: " << isThereLoop(mixedList) << endl;
    
    return 0;
}

//////////////////////// EXERCÍCIO 1A ////////////////////////

// Função para criar um nó
Node* createNode(int iID)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    
    temp -> iID = iID;
    temp -> ptrPrev = nullptr;
    temp -> ptrNext = nullptr;
    
    return temp;
}

// Função para criar uma lista
LoopList* createLoopList()
{
    LoopList* temp = (LoopList*) malloc(sizeof(LoopList));
    
    temp -> ptrFirst = nullptr;
    
    return temp;
}

// Função para exibir uma lista
void displayList(LoopList* loopList)
{
    if (loopList -> ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        cout << "Lista: " << loopList -> ptrFirst -> iID << " ";
        
        Node* current = loopList -> ptrFirst -> ptrNext;
        
        while (current != loopList -> ptrFirst)
        {
            cout << current -> iID << " ";
            current = current -> ptrNext;
        }
        
        cout << endl;
    }
}

// Função para inserir um nó no final da lista
void insertNode(LoopList* loopList, int iID)
{
    Node* temp = createNode(iID);
    
    if (loopList -> ptrFirst == nullptr)
    {
        loopList -> ptrFirst = temp;
        temp -> ptrPrev = temp;
        temp -> ptrNext = temp;
    }
    else
    {
        Node* current = loopList -> ptrFirst;
        
        while (current -> ptrNext != loopList -> ptrFirst)
        {
            current = current -> ptrNext;
        }
        
        current -> ptrNext = temp;
        temp -> ptrPrev = current;
        temp -> ptrNext = loopList -> ptrFirst;
        loopList -> ptrFirst -> ptrPrev = temp;
    }
}


// Função para criar uma lista circular a partir de um array de IDs
LoopList* createListFromArray(int arriIDs[], int sizeArray)
{
    LoopList* loopList = createLoopList();
    
    for (int i = 0; i < sizeArray; i++)
    {
        insertNode(loopList, arriIDs[i]);
    }
    
    return loopList;
}

// Função para retornar o ID atual e avançar a lista
int forwardList(LoopList* loopList)
{
    if (loopList -> ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
        return 0;
    }
    else
    {
        loopList -> ptrFirst = loopList -> ptrFirst -> ptrNext;
        return loopList -> ptrFirst -> ptrPrev -> iID;
    }
}

// Função para retornar o ID atual e retroceder a lista
int backwardList(LoopList* loopList)
{
    if (loopList -> ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
        return 0;
    }
    else
    {
        loopList -> ptrFirst = loopList -> ptrFirst -> ptrPrev;
        return loopList -> ptrFirst -> ptrNext -> iID;
    }
}

//////////////////////// EXERCÍCIO 1B ////////////////////////

// Função para retirar um nó por ID
void removeNode(LoopList* loopList, int iIdRemove)
{
    if (loopList -> ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    else if (loopList -> ptrFirst -> ptrNext == loopList -> ptrFirst)
    {
        if (loopList -> ptrFirst -> iID == iIdRemove)
        {
            free(loopList -> ptrFirst);
            loopList -> ptrFirst = nullptr;
        }
        else
        {
            cout << "Música não encontrada" << endl;
            return;
        }
    }
    else
    {
        Node* current = loopList -> ptrFirst;
        
        while (current -> iID != iIdRemove)
        {
            if (current == loopList -> ptrFirst -> ptrPrev)
            {
                cout << "Música não encontrada" << endl;
                return;
            }
            current = current -> ptrNext;
        }
        
        if (current == loopList -> ptrFirst)
        {
            loopList -> ptrFirst = current -> ptrNext;
        }
        current -> ptrPrev -> ptrNext = current -> ptrNext;
        current -> ptrNext -> ptrPrev = current -> ptrPrev;
        
        free(current);
    }
}

// Função para deletar a lista e liberar sua memória
void deleteList(LoopList* loopList)
{
    if (loopList -> ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    else if (loopList -> ptrFirst -> ptrNext == loopList -> ptrFirst)
    {
        free(loopList -> ptrFirst);
        free(loopList);
    }
    else
    {
        Node* current = loopList -> ptrFirst -> ptrNext;
        Node* previous = nullptr;
        
        while (current != loopList -> ptrFirst)
        {
            previous = current;
            current = current -> ptrNext;
            free(previous);
        }
        
        free(loopList -> ptrFirst);
        
        loopList -> ptrFirst = nullptr;
    }
}

//////////////////////// EXERCÍCIO 1C ////////////////////////

// Função para juntar duas listas
LoopList* mixLists(LoopList* list1, LoopList* list2)
{
    LoopList* mixedList = createLoopList();
    
    if (list1 -> ptrFirst == nullptr || list2 -> ptrFirst == nullptr)
    {
        cout << "Lista(s) vazia(s)" << endl;
        return mixedList;
    }
    else
    {
        Node* current1 = list1 -> ptrFirst;
        Node* current2 = list2 -> ptrFirst;
        
        insertNode(mixedList, current1 -> iID);
        insertNode(mixedList, current2 -> iID);
        
        current1 = current1 -> ptrNext;
        current2 = current2 -> ptrNext;
        
        while (current1 != list1 -> ptrFirst && current2 != list2 -> ptrFirst)
        {
            insertNode(mixedList, current1 -> iID);
            insertNode(mixedList, current2 -> iID);
            
            current1 = current1 -> ptrNext;
            current2 = current2 -> ptrNext;
        }
        
        if (current1 == list1 -> ptrFirst)
        {
            while (current2 != list2 -> ptrFirst)
            {
                insertNode(mixedList, current2 -> iID);
                current2 = current2 -> ptrNext;
            }
        }
        else if (current2 == list2 -> ptrFirst)
        {
            while (current1 != list1 -> ptrFirst)
            {
                insertNode(mixedList, current1 -> iID);
                current1 = current1 -> ptrNext;
            }
        }
        
        return mixedList;
    }
}


//////////////////////// EXERCÍCIO 2 ////////////////////////

// Função para checar se existe um loop em uma lista
bool isThereLoop(LoopList* list)
{
    if (list -> ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
        return false;
    }
    else
    {
        Node* slow = list -> ptrFirst;
        Node* fast = list -> ptrFirst -> ptrNext;
        
        while (fast -> ptrNext != nullptr && fast != nullptr && fast != slow)
        {
            fast = fast -> ptrNext -> ptrNext;
            slow = slow -> ptrNext;
        }
        
        if (fast -> ptrNext != nullptr && fast != nullptr)
        {
            return true;
        }
        else
        {
            while (slow -> ptrNext != nullptr)
            {
                slow = slow -> ptrNext;
            }
            
            fast = slow -> ptrPrev;
            
            while (fast -> ptrPrev != nullptr && fast != nullptr && fast != slow)
            {
                fast = fast -> ptrPrev -> ptrPrev;
                slow = slow -> ptrPrev;
            }
            
            if (fast -> ptrPrev != nullptr && fast != nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}







