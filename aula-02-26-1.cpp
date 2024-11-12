#include <iostream> // import iostream
#include <cstdlib>

using std::cout; // "from std import cout"

int main() // função
{
    int rpa;
    // int rpa; // Não se pode declarar a mesma variável duas vezes
    int emap = 1;
    
    auto i = 1; // auto: o tipo da variável é automático
    
    cout << "Exemplo de incrementos: " << "\n"; // cout: "vetor" que acumula as saídas no terminal
    cout << "Valor de i: " << i << "\n";
    
    auto c = ++i; // Pré-incremento: Incrementa a variável e depois realiza a operação
    
    cout << "Valor de c: " << c << "\n";
    cout << "Valor de i: " << i << "\n";
    
    auto d = i++; // Pós-incremento: Realiza a operação e depois incrementa a variável
    
    cout << "Valor de d: " << d << "\n";
    cout << "Valor de i: " << i << "\n";
    
    auto e = i--; // Pós-decremento
    
    cout << "Valor de e: " << e << "\n";
    cout << "Valor de i: " << i << "\n";
    
    auto f = --i; // Pré-decremento
    
    cout << "Valor de f: " << f << "\n";
    cout << "Valor de i: " << i << "\n";
    
    return 0; // Saída padrão sem erros da main
}