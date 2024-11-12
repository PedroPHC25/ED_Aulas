#include <iostream>

using namespace std;

///// RECURSÃO /////

unsigned long long iterativeFactorial(unsigned int);
unsigned long long recursiveFactorial(unsigned int);

unsigned long long iterativeFibonacci(unsigned int);
unsigned long long recursiveFibonacci(unsigned int);

void moveDisk(char, char, unsigned int);
void solveHanoi(unsigned int, char, char, char);


int main()
{
    unsigned int uiNumber = 6;
    
    // cout << "Digite um número inteiro positivo: ";
    // cin >> uiNumber;
    
    cout << "Fatorial iterativo de " << uiNumber << " é: " << iterativeFactorial(uiNumber) << endl;
    cout << "Fatorial recursivo de " << uiNumber << " é: " << recursiveFactorial(uiNumber) << endl;
    
    cout << "Fibonacci iterativo de " << uiNumber << " é: " << iterativeFibonacci(uiNumber) << endl;
    cout << "Fibonacci recursivo de " << uiNumber << " é: " << recursiveFibonacci(uiNumber) << endl;
    
    uiNumber = 1;
    
    solveHanoi(uiNumber, 'A', 'C', 'B');

    return 0;
}


unsigned long long iterativeFactorial(unsigned int uiNumber)
{
    unsigned long long ullResult = 1;
    
    for (int i = 1; i <= uiNumber; i++)
    {
        ullResult = ullResult * i;
    }
    
    return ullResult;
}

unsigned long long recursiveFactorial(unsigned int uiNumber)
{
    // Caso base
    if (uiNumber <= 1)
    {
        return 1;
    }
    
    return uiNumber * recursiveFactorial(uiNumber - 1);
}

unsigned long long iterativeFibonacci(unsigned int uiNumber)
{
    if (uiNumber == 0)
    {
        return 0;
    }
    if (uiNumber == 1)
    {
        return 1;
    }
    
    unsigned long long ullPrevious = 0;
    unsigned long long ullCurrent = 1;
    unsigned long long ullNext = 1;
    
    for (int i = 2; i <= uiNumber; i++)
    {
        ullNext = ullPrevious + ullCurrent;
        ullPrevious = ullCurrent;
        ullCurrent = ullNext;
    }
    
    return ullCurrent;
}

unsigned long long recursiveFibonacci(unsigned int uiNumber)
{
    if (uiNumber == 0)
    {
        return 0;
    }
    if (uiNumber == 1)
    {
        return 1;
    }
    
    return recursiveFibonacci(uiNumber - 1) + recursiveFibonacci(uiNumber - 2);
}

void moveDisk(char fromRod, char toRod, unsigned int disk)
{
    
}

void solveHanoi(unsigned int numberOfDisks, char fromRod, char toRod, char auxRod)
{
    
}