#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

void troca(int&, int&);
int& trocaElemento(int, int[]);

int main()
{
    // REFERÊNCIA
    
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl;
    cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor << endl;
    
    cout << "=============================================================================" << endl; 
    
    // Referência é uma outra forma de apontar para um endereço com uma variável atribuída
    
    int& irefValor = iValor;
    string& strrefNome = strNome;
    
    cout << "Valor da Ref. String: " << strrefNome << ". Endereço da Ref. String: " << &strrefNome << endl;
    cout << "Valor da Ref. Inteiro: " << irefValor << ". Endereço da Ref. Inteiro: " << &irefValor << endl;
    
    cout << "=============================================================================" << endl;
    
    strrefNome = "C. Camacho";
    irefValor = iValorFuturo; // Vai apenas atribuir o valor da outra variável (referência não é resetável)
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl;
    cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor << endl;
    
    cout << "=============================================================================" << endl;
    
    int iNum1 = 7;
    int iNum2 = 42;
    
    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    
    troca(iNum1, iNum2); // A função referencia a variável original e consegue alterar ela
    
    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    
    cout << "=============================================================================" << endl;
    
    int arriVetor[5] = {0, 7, 13, 42, 666};
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }
    
    cout << "-----" << endl;
    
    trocaElemento(4, arriVetor) = 111; // Atribui o valor ao endereço retornado pela função
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }
    
    cout << "=============================================================================" << endl;
    
    // ENUMERAÇÃO
    
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, Netflix, Max};
    
    Streaming streamingSubscription = CrunchyRoll; // Atribui o inteiro do índice (alias do 2)
    
    switch (streamingSubscription)
    {
        case AppleTV:
            cout << "Nunca usei.. Não sei como é... [" << streamingSubscription << "]" << endl;
            break;
        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
            break;
        default:
            cout << "NADA" << endl;
    }
    
    enum Mes {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};
    
    Mes mesProvas = MAIO;
    cout << mesProvas << endl;
    
    enum Semana {Segunda = 10, Terca = 1, Quarta = -3};
    
    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;
    
    return 0;
}

void troca(int& irefValor1, int& irefValor2)
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2; // Troca pelo valor a que a referência se refere
    irefValor2 = iTemp;
}

int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}









