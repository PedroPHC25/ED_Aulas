#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int iContador = 1;
    while (iContador <= 5)
    {
        cout << iContador << "\n";
        iContador++; // Soma 1
    }
    
    iContador = 42;
    do {
        cout << iContador << "\n";
        iContador++; // Soma 1
    }
    while (iContador <= 5); // "do while" executa e depois checa a condição (sempre executa pelo menos uma vez)
    
    for (int i = 1; i < 11; i++) // Inicializa a variável, dá a condição e faz a atualização da variável
    {
        cout << "(" << i << ")" << "\n";
    }
    
    // cout << i << endl; // A variável i não existe fora do "for"
    
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++) // Inicializa a variável, dá a condição e faz a atualização da variável
        {
            cout << "(" << i << "," << j << ")" << "\n";
        }
    }
    
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++) // Inicializa a variável, dá a condição e faz a atualização da variável
        {
            for (int k = 1; k < 11; k++)
            {
                cout << "(" << i << "," << j << "," << k << ")" << "\n";
            }
        }
    }
    
    
    
    // TIPO NOME TAMANHO
    int x[100] = {0}; // Inicia o vetor com zeros
    cout << "x[0] = " << x[0] << ", endereço: " << &x[0] << endl;
    cout << "x[1] = " << x[1] << ", endereço: " << &x[1] << endl;
    cout << "x[99] = " << x[99] << ", endereço: " << &x[99] << endl;
    cout << "Tamanho de x = " << sizeof(x)/sizeof(x[0]) << endl; // Tamanho de um vetor
    cout << "-----------------------------------------" << endl;
    
    int array[4];
    
    array[0] = 8;
    array[1] = 16;
    array[2] = 256;
    array[3] = 512;
    array[4] = 4646; // WTF?!
    
    cout << "array[0] = " << array[0] << ", endereço: " << &array[0] << endl;
    cout << "array[1] = " << array[1] << ", endereço: " << &array[1] << endl;
    cout << "array[2] = " << array[2] << ", endereço: " << &array[2] << endl;
    cout << "array[3] = " << array[3] << ", endereço: " << &array[3] << endl;
    cout << "array[4] = " << array[4] << ", endereço: " << &array[4] << endl;
    cout << "Tamanho de x = " << sizeof(array)/sizeof(array[0]) << endl;
    
    // offset => array + (index * sizeof(elemento)) // Buscando o endereço de um elemento do array
    
    if (&array[0] == array) {cout << "Faz sentido!" << endl;} // O array é o endereço em que ele começa
    
    cout << "-----------------------------------------" << endl;
    
    // Row Major
    // Prova: Fazer funções que trabalhem com um row major como se fosse column major
    int arriTest1[2][3] = {2, 4, 5, 9, 0, 19};
    int arriTest2[2][3] = {{2, 4, 5}, {9, 0, 19}};
    
    cout << "--- Testando Array 1 ---" << endl;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Array 1 em [" << i << "][" << j << "] = " << arriTest1[i][j] << ", Endereço: " << &arriTest1[i][j] << endl;
        }
    }
    
    cout << "--- Testando Array 2 ---" << endl;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    cout << "--- Aluno: Diagnosticado com TDAH ---" << endl;
    // Matriz_m_n em (i, j) = (i*n + j) * sizeof(elemento)
    // Matriz [2, 3] em (1, 1) = (3 + 1) * 4 
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    cout << "--- Aluno: Diagnosticado com Transtorno Psicótico ---" << endl;
    
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    return 0;
    
}