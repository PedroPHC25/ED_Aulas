#include <iostream>

int someFunc(int arg1)
{
    int result = 5;
    
    if (arg1 < 5) result = 10;
    
    return result;
}


int main()
{
    int ival = 3;
    if (ival > 4 && ival < 6) // "&&" = "and"
    {
        std::cout << "É igual a 5" << std::endl;
    }
    else if (ival < 4 || ival > 6) // "||" = "or"
    {
        std::cout << "É menor que 4 ou maior que 6" << std::endl;
    }
    else
    {
        std::cout << "É igual a 4 ou a 6" << std::endl;
    }
    
    if (!(ival < 4)) // "!" = "not"
    {
        std::cout << "Não é menor que 4" << std::endl;
    }
    else
    {
        if (ival < 2) std::cout << "É menor que 2" << std::endl; // Se for um único comando, pode ser na mesma linha
    }
    
    bool a = true;
    bool b = false;
    
    if ((a || b) && !(a && b)) std::cout << "Apenas a ou b é verdadeiro"; // ou exclusivo (ou "xor")
    
    std::cout << std::endl; // Pulando uma linha
    
    bool previousThing = true;
    int anotherThing = previousThing ? someFunc(4) : 6; // Avalia o booleano do previousThing, atribuindo o valor 5 se for true e 6 se for false ao anotherThing
    
    std::cout << "anotherThing is: " << anotherThing << std::endl;
    
    return 0;
}