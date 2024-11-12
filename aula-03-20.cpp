#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
} Livro;

struct Ponto
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};

typedef struct Biblioteca // Com typedef, agora posso chamar apenas de Biblioteca se quiser
{
    string strNome;
    int iTamAcervo;
    Livro livros[1000]; // Array de structs livros
} Biblioteca;

void listarLivros(Biblioteca);
void adicionarLivros(Biblioteca&, struct Livro);


int main()
{
    // UDT: User Defined Types

    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp;
    
    alunoEMAp.iIdade = 18;
    alunoEMAp.strNome = "Ana";
    
    cout << "Idade do alunoEMAp: " << alunoEMAp.iIdade << endl;
    cout << "Nome do alunoEMAp: " << alunoEMAp.strNome << endl;
    
    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp1;

    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp2;
    
    alunoEMAp1.iIdade = 20;
    alunoEMAp1.strNome = "Antonio";
    
    alunoEMAp2.iIdade = 17;
    alunoEMAp2.strNome = "Henzo";
    
    cout << "Idade do alunoEMAp1: " << alunoEMAp1.iIdade << endl;
    cout << "Nome do alunoEMAp1: " << alunoEMAp1.strNome << endl;
    
    cout << "Idade do alunoEMAp2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do alunoEMAp2: " << alunoEMAp2.strNome << endl;
    
    cout << "\n==================================================================\n" << endl;

    Livro livro1;
    
    livro1.strTitulo = "Outliers: The Story of Success";
    livro1.strAutor = "Malcolm Gladwell";
    livro1.iPublicacao = 2008;
    
    Livro livro2;
    
    livro2.strTitulo = "How to Grow Old";
    livro2.strAutor = "Marus Tullius Cicero";
    livro2.iPublicacao = -44;

    cout << "Título 1: " << livro1.strTitulo << ", por " << livro1.strAutor << endl;
    cout << "Publicado em: " << livro1.iPublicacao << ".\n" << endl;

    cout << "Título 2: " << livro2.strTitulo << ", por " << livro2.strAutor << endl;
    cout << "Publicado em: " << livro2.iPublicacao << ".\n" << endl;
    
    struct Ponto telaComputador[640][480]; // Matriz de structs
    
    telaComputador[0][0].usRed = 0;
    telaComputador[0][0].usGreen = 0;
    telaComputador[0][0].usBlue = 0;
    
    cout << "RGB [0,0] (" << telaComputador[0][0].usRed << "," << telaComputador[0][0].usGreen << "," << telaComputador[0][0].usBlue << ")" << endl;
    
    Biblioteca biblioteca;
    
    biblioteca.strNome = "Biblioteca do Palácio Botafogo";
    biblioteca.iTamAcervo = 0;
    
    cout << "\n==================================================================\n" << endl;
    
    listarLivros(biblioteca);
    
    biblioteca.livros[0] = livro1;
    biblioteca.iTamAcervo += 1;
    biblioteca.livros[1] = livro2;
    biblioteca.iTamAcervo += 1;

    Livro livro3;
    
    livro3.strTitulo = "1984";
    livro3.strAutor = "George Orwell";
    livro3.iPublicacao = 1949;
    
    cout << "\n==================================================================\n" << endl;

    listarLivros(biblioteca);
    
    biblioteca.livros[2] = livro3;
    biblioteca.iTamAcervo += 1;
    
    cout << "\n==================================================================\n" << endl;

    listarLivros(biblioteca);
    
    adicionarLivros(biblioteca, livro1);
    adicionarLivros(biblioteca, livro2);
    adicionarLivros(biblioteca, livro3);
    
    cout << "\n==================================================================\n" << endl;
    
    listarLivros(biblioteca);
    
  return 0;
}

// Verificar tamanho vazio
void listarLivros(Biblioteca biblioteca)
{
    cout << "\nLivros do acervo da " << biblioteca.strNome << ":\n" << endl;
    for (int i = 0; i < biblioteca.iTamAcervo; i++)
    {
        cout << "Título: " << biblioteca.livros[i].strTitulo << ", por " << biblioteca.livros[i].strAutor << endl;
        cout << "Publicado em: " << biblioteca.livros[i].iPublicacao << ".\n" << endl;
    }
}

// Verificar se a biblioteca está cheia
void adicionarLivros(Biblioteca& biblioteca, Livro novoLivro)
{
    biblioteca.livros[biblioteca.iTamAcervo] = novoLivro;
    biblioteca.iTamAcervo += 1;
}












