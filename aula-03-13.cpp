#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// FUNÇÕES SEMPRE ANTES DA MAIN!!!

void frasePreferida() // Não retorna nada
{
    cout << "Eu adoro a EMAp!" << endl;
}

void montaFrase(char chArtigo, string strPalavra)
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl;
}

void montaFrasePadrao(char chArtigo = 'a', string strPalavra = "EMAp") // Argumentos padrão
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl;
}

// FUNÇÕES BUILT-IN

int potenciacao(int iBase, int iExpoente)
{
    return pow(iBase, iExpoente);
}

float modulo(float iValor)
{
    return fabs(iValor);
}

void minhaFuncao(int arriNumeros[], int iTamanhoVetor)
{
    for(int i = 0; i < iTamanhoVetor; i++)
    {
        cout << arriNumeros[i] << endl;
    }
}

// POLIMORFISMO ESTÁTICO: FUNÇÕES COM O MESMO NOME
// Assinatura de uma função: seu nome e seus parâmetros ordenados

int soma(int iValor1, int iValor2)
{
    return iValor1 + iValor2;
}

int soma(int iValor1, int iValor2, int iValor3)
{
    return iValor1 + iValor2 + iValor3;
}

// float soma(int iValor1, int iValor2) // A saída não entra na assinatura pois gera ambiguidade
// {
//     return iValor1 + iValor2;
// }

// PROTÓTIPO DE FUNÇÃO
// float soma(float, float);



int main()
{
    frasePreferida();
    frasePreferida();
    frasePreferida();
    
    cout << "=====================" << endl;
    
    montaFrase('a', "EMAp"); // Aspas simples para char e duplas para string
    // montaFrase("a", "EMAp");
    montaFrase('o', "Yuri");
    
    cout << "=====================" << endl;
    
    montaFrasePadrao();
    montaFrasePadrao('o');
    montaFrasePadrao('o', "Yuri");
    
    cout << "=====================" << endl;
    
    cout << "potenciacao(2, 10): " << potenciacao(2, 10) << endl;
    cout << "potenciacao(3, 5): " << potenciacao(3, 5) << endl;
    
    cout << "=====================" << endl;
    
    cout << "modulo(2): " << modulo(2) << endl;
    cout << "modulo(-2): " << modulo(-2) << endl;
    
    cout << "modulo(2.7): " << modulo(2.7) << endl; // Trunca
    cout << "modulo(-2.7): " << modulo(-2.7) << endl;
    
    cout << "=====================" << endl;
    
    // Endereço base + 4 * index
    int arriVetorTeste[5] = {0, 7, 13, 42, 666}; // Ele calcula o tamanho do vetor, mas é má prática
    int iTamanhoVetor = sizeof(arriVetorTeste)/sizeof(arriVetorTeste[0]);
    
    minhaFuncao(arriVetorTeste, iTamanhoVetor);
    
    cout << "=====================" << endl;
    
    int iNum1 = 10;
    int iNum2 = 20;
    int iNum3 = 30;
    
    cout << soma(iNum1, iNum2) << endl;
    cout << soma(iNum1, iNum2, iNum3) << endl;
    cout << soma(2.3, 3.1) << endl;
    
    return 0;   
    
}    

// float soma(float fValor1, float fValor2)
// {
//     return fValor1 + fValor2;
// }
