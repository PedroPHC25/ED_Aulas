#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

///// SELECTION SORT /////

void swapValue(int&, int&);
void printArray(int[], int);
void selectionSort(int[], int);
void optimizedSelectionSort(int[], int);


int main()
{
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    // int arriNumbers_1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int iArraySize = 10;
    
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize);
    
    // time_point<std::chrono::high_resolution_clock> timeStart
    auto timeStart = high_resolution_clock::now();

    selectionSort(arriNumbers_1, iArraySize);
    
    auto timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;
    
    cout << "==================================================================" << endl;

    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    // int arriNumbers_2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout << "Array original: ";
    printArray(arriNumbers_2, iArraySize);
    
    timeStart = high_resolution_clock::now();

    optimizedSelectionSort(arriNumbers_2, iArraySize);
    
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

void selectionSort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++)
    {
        for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++)
        {
            if (arriNumbers[iOuterLoop] > arriNumbers[iInnerLoop])
            {
                swapValue(arriNumbers[iOuterLoop], arriNumbers[iInnerLoop]);
            }
        }
    }
}

void optimizedSelectionSort(int arriNumbers[], int iLength)
{
    int minValue = 0;
    int iSwapIndex = 0;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        minValue = arriNumbers[iOuterLoop];
        iSwapIndex = iOuterLoop;
        
        for (int iInnerLoop = iOuterLoop + 1; iInnerLoop < iLength; iInnerLoop++)
        {
            // É melhor do que procurar os dois valores no array
            if (minValue > arriNumbers[iInnerLoop])
            {
                minValue = arriNumbers[iInnerLoop];
                iSwapIndex = iInnerLoop;
            }
        }
        
        swapValue(arriNumbers[iOuterLoop], arriNumbers[iSwapIndex]);
    }
}