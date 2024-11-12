#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Pilha: LIFO (last in, first out)

typedef struct Node 
{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Stack 
{
    Node* ptrTop;
} Stack;

Node* newNode(int);
Stack* newStack();
void push(Stack* const, int);
void showTopElement(Stack* const);
void showElements(Stack* const);
void pop(Stack* const);


int main () 
{ 
    Stack* stack = newStack();
    showTopElement(stack);
    showElements(stack);
    pop(stack);
    cout << "---" << endl;
    push(stack, 0);
    showTopElement(stack);
    cout << "---" << endl;
    push(stack, 3);
    showTopElement(stack);
    cout << "---" << endl;
    push(stack, 7);
    showTopElement(stack);
    cout << "---" << endl;
    push(stack, 10);
    showTopElement(stack);
    cout << "---" << endl;
    push(stack, 13);
    showTopElement(stack);
    cout << "---" << endl;
    push(stack, 42);
    showTopElement(stack);
    showElements(stack);
    pop(stack);
    showTopElement(stack);
    pop(stack);
    showTopElement(stack);
    pop(stack);
    showTopElement(stack);
    pop(stack);
    showTopElement(stack);
    pop(stack);
    showTopElement(stack);
    pop(stack);
    showTopElement(stack);
  
    cout << "=========================================================" << endl;
  
    return 0;
}

 
Node* newNode(int iValue) 
{ 
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iData = iValue;
    temp -> ptrNext = nullptr; // Elemento do topo da pilha
    
    return temp;
}

Stack* newStack() 
{ 
    Stack* temp = (Stack*) malloc(sizeof(Stack)); // Pedindo memória pro SO
    temp -> ptrTop = nullptr; // Começa com elemento inicial vazio
    
    return temp;
}
 
void push(Stack* const stack, int iValue) 
{ 
    Node* temp = newNode(iValue); // Criando o nó
    
    temp -> ptrNext = stack -> ptrTop;
    stack -> ptrTop = temp;
}

void showTopElement(Stack* const stack)
{
    cout << "Topo da pilha: " << ((stack -> ptrTop != nullptr) ? (stack -> ptrTop) -> iData : -1) << endl;
}

void showElements(Stack* const stack)
{
    if (stack -> ptrTop == nullptr)
    {
        cout << "Pilha vazia" << endl;
        return;
    }

    Node* current = stack -> ptrTop;
    
    while (current != nullptr)
    {
        cout << "Elemento: " << current -> iData << endl;
        current = current -> ptrNext;
    }
}

void pop(Stack* const stack)
{
    if (stack -> ptrTop == nullptr)
    {
        cout << "Pilha vazia" << endl;
        return;
    }
    
    cout << "Elemento removido: " << stack -> ptrTop -> iData << endl;
    
    Node* temp = stack -> ptrTop;
    
    stack -> ptrTop = stack -> ptrTop -> ptrNext;
    
    free(temp);
}
















