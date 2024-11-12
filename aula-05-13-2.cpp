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

namespace FGV
{
    int iValor = 666;
    
    void mockFunction()
    {
        cout << "Namespace FGV" << endl;
    }
    
    namespace EMAp
    {
        int iValor = 42;
        
        void mockFunction()
        {
            cout << "Namespace EMAp" << endl;
        }
    }
}

int main()
{
    cout << "Namespace EMAp: " << FGV::EMAp::iValor << endl;
    cout << "Namespace FGV: " << FGV::iValor << endl;
    
    FGV::EMAp::mockFunction();
    FGV::mockFunction();
    
    return 0;
}













