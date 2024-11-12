#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

///// INSERTION SORT /////

void printArray(int[], int);
void insertionSort(int[], int);


int main()
{
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    // int arriNumbers_1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int iArraySize = 10;
    
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize);
    
    // time_point<std::chrono::high_resolution_clock> timeStart
    auto timeStart = high_resolution_clock::now();

    insertionSort(arriNumbers_1, iArraySize);
    
    auto timeStop = high_resolution_clock::now();
    
    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos." << endl;

    return 0;
}

void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i++)
    {
        cout << arriNumbers[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arriNumbers[], int iLength)
{
    int iInsertValue = 0;
    int iInnerLoop = 0;
    
    for (int iOuterLoop = 1; iOuterLoop < iLength; iOuterLoop++)
    {
        iInsertValue = arriNumbers[iOuterLoop];
        iInnerLoop = iOuterLoop - 1;
        
        while (iInsertValue < arriNumbers[iInnerLoop] && iInnerLoop >= 0)
        {
            arriNumbers[iInnerLoop + 1] = arriNumbers[iInnerLoop];
            iInnerLoop--;
        }
        
        arriNumbers[iInnerLoop + 1] = iInsertValue;
    }
}