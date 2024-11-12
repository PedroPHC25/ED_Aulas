#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node // Nó: elemento da fila
{
    int iData;
    Node* next; // Cada elemento tem um ponteiro para seu sucessor
} Node;

typedef struct Queue
{
    Node* front; // Primeiro da fila
    Node* rear; // Final da fila
} Queue;


Queue* newQueue()
{
    Queue* temp = (Queue*) malloc(sizeof(Queue)); // Pedindo memória pro SO
    temp -> front = nullptr; // Começa com elementos inicial e final vazios
    temp -> rear = nullptr; // ->: acessa os atributos da estrutura para a qual o ponteiro aponta
    
    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iData = iValue;
    temp -> next = nullptr;
    
    return temp;
}

void enQueue(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue); // Criando o nó
    
    if (queue -> front == nullptr) // Se a fila está vazia...
    {
        queue -> front = temp; // Esse elemento vira o primeiro e o último da fila
        queue -> rear = temp;
    }
    else // Se não...
    {
        queue -> rear -> next = temp; // O antes último elemento passa a apontar para o novo elemento
        queue -> rear = temp; // O novo elemento passa a ser o último
    }
    
    return;
}

void deQueue(Queue* const queue)
{
    if (queue -> front == nullptr) // Se a fila está vazia...
    {
        cout << "Fila vazia" << endl;
        return;
    }
    
    Node* temp = queue -> front;
    
    cout << "Elemento removido: " << temp -> iData << endl;
    
    queue -> front = queue -> front -> next; // Passando o papel de primeiro da fila para o próximo
    
    if (queue -> front == nullptr) // Se a fila só tinha um elemento...
    {
        queue -> rear = nullptr; // O último passa a ser nulo também
    }
    
    free(temp); // Libera a memória do nó retirado
    
    return;
}

void showFirstElement(Queue* const queue)
{
    cout << "Primeiro elemento: " << ((queue -> front != NULL) ? (queue -> front) -> iData : -1) << endl;
    return;
}

void showLastElement(Queue* const queue)
{
    cout << "Último elemento: " << ((queue -> rear != NULL) ? (queue -> rear) -> iData : -1) << endl;
    return;
}

void showElements(Queue* const queue)
{
    if (queue -> front == nullptr)
    {
        cout << "Fila vazia" << endl;
        return;
    }
    
    Node* current = queue -> front; // Nó atual, começando no primeiro
    
    while (current != nullptr) // Enquanto não for nulo...
    {
        cout << "Elemento: " << current -> iData << endl; // Printa o elemento
        current = current -> next; // E atualiza para o próximo da fila
    }
}


int main()
{
    // Fila: FIFO (first in, first out) ou FCFS (first come, first served)
    
    // 1. Estrutura de um nó
    // 2. Estrutura de uma fila 
    // 3. Função que cria uma fila
    // 4. Função que cria um nó
    // 5. Função que enfileira um nó
    // 6. Função que exibe o primeiro elemento
    // 7. Função que exibe o último elemento
    // 8. Função que exibe todos os elementos
    // 9. Função que remove um nó
    
    Queue* queue = newQueue();
    
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" << endl;
    showElements(queue);
    deQueue(queue);
    
    cout << "=========================================================" << endl;
    
    enQueue(queue, 0);
    
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" << endl;
    showElements(queue);
    deQueue(queue);
    
    cout << "=========================================================" << endl;
    
    enQueue(queue, 3);
    enQueue(queue, 7);
    enQueue(queue, 13);
    enQueue(queue, 42);
    
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" << endl;
    showElements(queue);
    deQueue(queue);
    
    return 0;
}


















