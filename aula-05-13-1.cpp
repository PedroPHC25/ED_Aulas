#include <iostream>

// Qualquer variável ou função é procurada primeiro no std
// from std import *
using namespace std;



// NAMESPACE

/*
namespace [identifier]
{
    [entities]
}
*/

namespace EMAp
{
    int iValor = 42;
    
    void mockFunction()
    {
        cout << "Namespace EMAp" << endl;
    }
}

namespace FGV
{
    int iValor = 666;
    
    void mockFunction()
    {
        cout << "Namespace FGV" << endl;
    }
}

// Pertence ao namespace global
int iValor = 1;

// using EMAp::mockFunction;
using namespace FGV;

int main()
{
    // Pertence ao namespace local
    int iValor = 10;
    
    cout << "Namespace Local: " << iValor << endl;
    cout << "Namespace Global: " << ::iValor << endl;
    cout << "Namespace EMAp: " << EMAp::iValor << endl;
    cout << "Namespace FGV: " << FGV::iValor << endl;
    
    EMAp::mockFunction();
    FGV::mockFunction();
    
    mockFunction();
    
    return 0;
}












