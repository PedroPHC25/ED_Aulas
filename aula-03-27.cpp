#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int square(int*);
int somaVetor(const int* valores, const size_t); // size_t: tipo de tamanho

int main()
{
    // Ponteiros
    
    int* ptrInt = nullptr; // Não aponta para lugar nenhum
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "==================================================================" << endl;
    
    int iNumMagico = 42;
    
    cout << "Endereço de iNumMagico: " << &iNumMagico << endl;
    
    ptrInt = &iNumMagico;
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "Conteúdo de iNumMagico: " << *ptrInt << endl;
    cout << "==================================================================" << endl;

    int iNumSagrado = 7;
    
    cout << "Endereço de iNumSagrado: " << &iNumSagrado << endl;

    ptrInt = &iNumSagrado; // Ponteiro é resetável
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "iNumMagico: " << iNumMagico << endl;
    cout << "Endereço de iNumMagico: " << &iNumMagico << endl;
    cout << "Conteúdo de iNumSagrado: " << *ptrInt << endl;
    
    cout << "==================================================================" << endl;
    
    int iNum1 = 42;
    int iNum2 = 666;
    
    int* const ptrNum1 = &iNum1; // Ponteiro constante para inteiro
    
    // ptrNum1 = &iNum2; // Não é possível redefinir um ponteiro constante
    
    *ptrNum1 = 7; // Mudando o valor da variável apontada
    
    const int* ptrNum2 = &iNum1; // Ponteiro para inteiro constante
    
    ptrNum2 = &iNum2; // Agora pode alterar o Ponteiro
    
    // *ptrNum2 = 7; // Mas não pode mais alterar o valor
    
    /*
    No entanto, a variável não é constante,
    apenas o ponteiro que acha que ela é.
    Eu ainda posso alterar a variável, mas não por meio do ponteiro.
    */
    
    const int* const ptrNum3 = &iNum1; // Ponteiro constante para inteiro constante
    
    // ptrNum3 = &iNum2; // Não pode ser redefinido
    // *ptrNum3 = 7;     // e nem redefinir a variável a que aponta.
    
    cout << "Quadrado: " << square(&iNum1) << endl;
    
    int arriValores[3] = {0, 1, 2};
    
    cout << "==================================================================" << endl;
    
    cout << "somaVetor: " << somaVetor(arriValores, 3) << endl;
    
    cout << "==================================================================" << endl;

    // Vetores x Ponteiros
    
    int arriValores2[5] = {0, 7, 13, 42, 666};
    
    cout << "Endereço de [0]: " << arriValores2 << endl;
    
    int* ptrArrayValores1 = arriValores2; // O vetor é um ponteiro para inteiro
    
    cout << "PTR1: " << ptrArrayValores1 << endl; // O ponteiro se torna o endereço para o primeiro elemento do vetor
    
    int* ptrArrayValores2 = &arriValores2[0];
    
    cout << "PTR2: " << ptrArrayValores2 << endl;
    
    cout << "==================================================================" << endl;
    
    cout << "Valor de ptrArrayValores1[0]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[0]: " << ptrArrayValores1 << endl;
    
    ptrArrayValores1++; // Somar 1 adiciona o número de bites do tamanho do tipo referenciado (no caso, 4)
    
    cout << "Valor de ptrArrayValores1[1]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[1]: " << ptrArrayValores1 << endl;
    
    ptrArrayValores1+=3;
    
    cout << "Valor de ptrArrayValores1[4]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[4]: " << ptrArrayValores1 << endl;
    
    ptrArrayValores1-=2;
    
    cout << "Valor de ptrArrayValores1[2]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[2]: " << ptrArrayValores1 << endl;
    
    cout << "==================================================================" << endl;
    
    cout << "Subtração de ponteiros: " << ptrArrayValores1 - ptrArrayValores2 << endl; // 2 - 0 = 2
    
    return 0;
}


int square(int* ptrNum)
{
    return *ptrNum * *ptrNum;
}

// O nome de um vetor é um ponteiro para seu primeiro elemento
// Vetor = ponteiro
int somaVetor(const int valores[], const size_t tamVetor) // Notação de size_t: s ou sz
{
    return -1;
}




















