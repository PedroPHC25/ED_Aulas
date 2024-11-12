 #include <iostream>
 
 using std::cin;
 using std::cout;
 using std::endl;
 using std::string;
 
 int main()
 {
    int iValor = 42;
    int iValorLido = 0;
    int iResultado = 0;
    
    cin >> iValorLido;
    
    iResultado = (iValorLido < iValor) ? 123 : 15000; // Não usar!
    
    cout << "Resultado: " << iResultado << endl;
     
    
    int iDia = 10;
    
    switch (iDia) // Realiza cada bloco de código de acordo com o valor da variável
    {
        case 1:
            cout << "Segunda-feira" << endl;
            break;
        case 2:
            cout << "Terça-feira" << endl;
            break;
        case 3:
            cout << "Quarta-feira" << endl;
            break;
        case 4:
            cout << "Quinta-feira" << endl;
            break;
        default:
            cout << "Dia louco!" << endl;
    }
     
    return 0;
 }