#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapValue(int&, int&);
void printArray(int[], int);
void bubbleSort(int[], int);
void optimizedBubbleSort(int[], int);


int main()
{
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    int iArraySize = 10;
    
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize);
    
    // time_point<std::chrono::high_resolution_clock> timeStart
    auto timeStart = high_resolution_clock::now();

    bubbleSort(arriNumbers_1, iArraySize);
    
    auto timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;
    
    cout << "==================================================================" << endl;

    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    
    cout << "Array original: ";
    printArray(arriNumbers_2, iArraySize);
    
    timeStart = high_resolution_clock::now();

    optimizedBubbleSort(arriNumbers_2, iArraySize);
    
    timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_2, iArraySize);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;
    
    cout << "==================================================================" << endl;

    return 0;
}


void swapValue(int& irefValue_1, int& irefValue_2)
{
    int iTemp = irefValue_1;
    irefValue_1 = irefValue_2;
    irefValue_2 = iTemp;
}

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i++)
    {
        cout << arriNumbers[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++)
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
}

void optimizedBubbleSort(int arriNumbers[], int iLength)
{
    bool bUnordered = false;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        bUnordered = false;
        
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1 - iOuterLoop; iInnerLoop++)
        {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
                bUnordered = true;
            }
        }
        if (bUnordered == false)
        {
            break;
        }
    }
}

// Atividade: Implementar com lista duplamente encadeada e testar com muitos valores
// Fazer o teste com umas 100 listas diferentes








