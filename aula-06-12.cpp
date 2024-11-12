#include <iostream>

using namespace std;

///// TORRE DE HANÓI /////

void moveDisk(char, char, unsigned int);
void solveHanoi(unsigned int, char, char, char);


int main()
{
    unsigned int uiNumberOfDisks = 5;
    
    solveHanoi(uiNumberOfDisks, 'A', 'C', 'B');

    return 0;
}


void moveDisk(char fromRod, char toRod, unsigned int iDisk)
{
    cout << "Move o disco " << iDisk << " de " << fromRod << " para " << toRod << endl;
}

void solveHanoi(unsigned int uiNumberOfDisks, char fromRod, char toRod, char auxRod)
{
    if (uiNumberOfDisks == 1)
    {
        moveDisk(fromRod, toRod, 1);
        return;
    }
    
    solveHanoi(uiNumberOfDisks - 1, fromRod, auxRod, toRod);
    moveDisk(fromRod, toRod, uiNumberOfDisks);
    solveHanoi(uiNumberOfDisks - 1, auxRod, toRod, fromRod);
}























