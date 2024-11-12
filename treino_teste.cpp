#include <iostream>
#include <cmath>

using std::endl;
using std::cout;

void trocar(int& irefNum1, int& irefNum2)
{
    int temp = irefNum1;
    irefNum1 = irefNum2;
    irefNum2 = temp;
}

void dobrar_numero(int& irefNum)
{
    irefNum = irefNum * 2;
}

void substituir_por_media(int& irefNum1, int& irefNum2, int& irefNum3)
{
    int iMedia = (irefNum1 + irefNum2 + irefNum3)/3;
    irefNum1 = iMedia;
    irefNum2 = iMedia;
    irefNum3 = iMedia;
}

int& substituir_maior_valor(int& iNum1, int& iNum2)
{
    if (iNum1 >= iNum2)
    {
        return iNum1;
    }
    else
    {
        return iNum2;
    }
}

int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}

void incrementar(int& iNum)
{
    iNum++;
}

void trocarElementos(int arriVetor[], int iTamanhoVetor, int iPos1, int iPos2)
{
    if (iPos1 >= iTamanhoVetor || iPos2 >= iTamanhoVetor)
    {
        cout << "Índice(s) inválido(s)" << endl;
        return;
    }
    
    int temp = arriVetor[iPos1];
    arriVetor[iPos1] = arriVetor[iPos2];
    arriVetor[iPos2] = temp;
}

void normalizarArray(float arrfVetor[], int iTamanhoVetor)
{
    float fNorma = 0;
    
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        fNorma += arrfVetor[i]*arrfVetor[i];
    }
    fNorma = sqrt(fNorma);
    
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        arrfVetor[i] = arrfVetor[i] / fNorma;
    }
}

int somaArray(int arriVetor[], int iTamanhoVetor)
{
    int iSoma = 0;
    
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        iSoma += abs(arriVetor[i]);
    }
    
    return iSoma;
}

int maiorElemento(int arriVetor[], int iTamanhoVetor)
{
    int iMaiorValor = 0;
    
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        if (abs(arriVetor[i]) > iMaiorValor)
        {
            iMaiorValor = arriVetor[i];
        }
    }
    
    return iMaiorValor;
}

void inverterArray(int arriVetor[], int iTamanhoVetor)
{
    int iNumInversoes = iTamanhoVetor / 2;
    
    for (int i = 0; i < iNumInversoes; i++)
    {
        int temp = arriVetor[i];
        arriVetor[i] = arriVetor[iTamanhoVetor - 1 - i];
        arriVetor[iTamanhoVetor - 1 - i] = temp;
    }
}

int mediaArray(int arriVetor[], int iTamanhoVetor)
{
    float fMedia = 0;
    
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        fMedia += arriVetor[i];
    }
    
    fMedia = fMedia / iTamanhoVetor;
    
    return fMedia;
}

int contarOcorrencias(int arriVetor[], int iTamanhoVetor, int iValor)
{
    int iNumOcorrencias = 0;
    
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        if (arriVetor[i] == iValor)
        {
            iNumOcorrencias++;
        }
    }
    
    return iNumOcorrencias;
}


int main()
{
    int iNum1 = 5;
    int iNum2 = 10;
    
    cout << iNum1 << ", " << iNum2 << endl;

    trocar(iNum1, iNum2);
    
    cout << iNum1 << ", " << iNum2 << endl;
    
    dobrar_numero(iNum1);
    
    cout << iNum1 << endl;
    
    int iX = 5;
    int iY = 10;
    int iZ = 15;
    
    substituir_por_media(iX, iY, iZ);
    
    cout << iX << ", " << iY << ", " << iZ << endl;
    
    cout << iNum1 << ", " << iNum2 << endl;
    
    substituir_maior_valor(iNum1, iNum2) = -3;
    
    cout << iNum1 << ", " << iNum2 << endl;
    
    int arriVetor[5] = {1, 2, 3, 4, 5};
    
    trocaElemento(3, arriVetor) = 10;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    
    cout << endl;
    
    cout << "Esse vetor tem " << sizeof(arriVetor)/sizeof(arriVetor[0]) << " elementos" << endl;
    
    cout << iX << endl;
    incrementar(iX);
    cout << iX << endl;
    
    enum Dia {Seg = 2, Ter, Qua};
    Dia hoje = Qua;
    cout << hoje << endl;
    
    cout << "===============" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    trocarElementos(arriVetor, 5, 2, 4);
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    cout << "================" << endl;
    
    float arrfVetor[5] = {1.6, 0.4, 2.0, 2.4, 1.5};
    
    normalizarArray(arrfVetor, 5);
    
    for (int i = 0; i < 5; i++)
    {
        cout << arrfVetor[i] << " ";
    }
    cout << endl;
    
    cout << "================" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    cout << somaArray(arriVetor, 5) << endl;
    
    cout << "================" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    cout << maiorElemento(arriVetor, 5) << endl;
    
    cout << "================" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    inverterArray(arriVetor, 5);
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    cout << "================" << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    cout << mediaArray(arriVetor, 5) << endl;
    
    cout << "================" << endl;
    
    arriVetor[0] = 2;
    for (int i = 0; i < 5; i++)
    {
        cout << arriVetor[i] << " ";
    }
    cout << endl;
    
    cout << contarOcorrencias(arriVetor, 5, 2) << endl;
    
    return 0;
}
























