#include <iostream>

using std::cout;
using std::endl;

// Hungarian Notation: Systems Hungarian x Apps. Hungarian

int main()
{
    int iNum = 42;
    
    cout << "Valor de Num: " << iNum << endl;
    cout << "Endereço de Num: " << &iNum << endl;
    
    iNum = 111;
    
    cout << "Valor de Num: " << iNum << endl;
    cout << "Endereço de Num: " << &iNum << endl;
    
    return 0;
}