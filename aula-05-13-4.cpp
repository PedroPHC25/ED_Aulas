#include <iostream>
#include <cstring>

using namespace std;

// TEMPLATES

/*
int MAX(int x, int y)
{
    return x > y ? x:y;
}

float MAX(float x, float y)
{
    return x > y ? x:y;
}
*/

template<typename T>
T MAX(T x, T y)
{
    cout << typeid(T).name() << endl;
    return x > y ? x:y;
}

// Instanciação explícita
template char MAX(char x, char y);

// Especialização explícita
template<> const char* MAX<const char*>(const char* x, const char* y)
{
    return strcmp(x, y) > 0 ? x : y;
}

template<typename T>
T somaElementos(T* arr, int size)
{
    T soma;
    
    for (int i = 0; i < size; i++)
    {
        soma += arr[i];
    }
    
    return soma;
}


int main()
{
    // auto resultado_1 = MAX(13, 42);
    auto resultado_1 = MAX(static_cast<float>(13), 42.11f);
    cout << resultado_1 << endl;
    
    auto resultado_2 = MAX<double>(13, 42.11f);
    cout << resultado_2 << endl;
    
    cout << "================================" << endl;
    
    // String clássica
    const char* b {"B"};
    const char* a {"A"};

    cout << "Endereço de A: " << &a << endl;
    cout << "Endereço de B: " << &b << endl;
    
    // Único caso de uso do auto é template
    auto resultado_3 = MAX(a, b);
    // Não funcionou para string
    cout << resultado_3 << endl;
    
    cout << "================================" << endl;
    
    int arr[] = {13, 10, 42, 7, 3};
    
    int soma = somaElementos(arr, 5);
    cout << "Soma: " << soma << endl;
    
    return 0;
}


















