#include "../include/gera_tabuleiro.h"
#include "./gera_tabuleiro.cpp" // só pra diminuir a linha de comando na compilação

int main ( int argc, char **argv )
{
    /// testa se o primeiro argumento está correto
    if( atoi(argv[1]) > 100 || atoi(argv[1]) < 1 )
    {
        std::cerr << "Erro: argumento 1 deve ser maior ou igual a 1 e menor ou igual a 100";
        return EXIT_FAILURE;
    }
    /// testa se o segundo e terceiro argumentos estão corretos
    if( atoi(argv[2]) > 15 || atoi(argv[2]) < 7 || atoi(argv[3]) > 15 || atoi(argv[3]) < 7 )
    {
        std::cerr << "Erro: argumento 2 e 3 se especificados devem ser maiores ou iguais a 7 e menores ou iguais a 15";
        return EXIT_FAILURE;
    }
    /// importante para o funcionamento da função gt::puzzlesBuffer
    /// so que nao ta funcionando como o esperado ta saindo tudo repetido 
    srand( (unsigned)time(NULL) ); 
    /// armazenando e convertendo os parametros argv para int
    gt::n_puzzles = atoi(argv[1]); /// número de tabuleiros
    gt::l = argv[2] != NULL ? atoi(argv[2]) : gt::l;/// linhas
    gt::c = argv[3] != NULL ? atoi(argv[3]) : gt::c; /// colunas
    
    std::vector< std::vector<char> > a(gt::l+2, std::vector<char>(gt::c+2));
    
    for ( unsigned short i(0); i < gt::l+2; ++i)
    {
        for ( unsigned short j(0); j < gt::c+2; ++j)
        {
            a[i][j] = '0';
        }
    }

    // teste de criação de varios puzzles( so sai puzzles repetidos, srand sem funcionar)
    // unsigned short i(0);
    // while( i < gt::n_puzzles )
    // {
    //     //srand( (unsigned)time(nullptr)); 
    //     gt::puzzleBuffer(a);
    //     gt::printTab(a);
    //     for ( unsigned short i(0); i < gt::l+1; ++i)
    //     {
    //         for ( unsigned short j(0); j < gt::c+1; ++j)
    //         {
    //             a[i][j] = '0';
    //         }
    //     }
    //     //sleep(2); // so um teste 
    //     std::cout.put('\n'); 
    //     ++i;
    // }
    // std::cout<<a.size();
    gt::puzzleBuffer(a);
    gt::printTab(a);

    return 0;
}
