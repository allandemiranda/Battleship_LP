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
    if( atoi(argv[2]) > 15 || atoi(argv[2]) < 7 || atoi(argv[3]) > 15 || atoi(argv[3]) < 7 )
    {
        std::cerr << "Erro: argumento 2 e 3 se especificados devem ser maior ou igual a 7 e menor ou igual a 15";
        return EXIT_FAILURE;
    }
    /// importante para o funcionamento da função gt::escolhaBarcos
    srand( time(NULL) ); 
    /// armazenando e convertendo os parametros argv para int
    gt::n_puzzles = atoi(argv[1]); /// número de tabuleiros
    gt::n_lines = argv[2] != NULL ? atoi(argv[2]) : 7;/// linhas
    gt::n_cols = argv[3] != NULL ? atoi(argv[3]) : 7; /// colunas

    //char base[gt::n_lines][gt::n_cols];
    // std::vector< std::vector<char> > base;
    // for ( auto i(0u); i < gt::n_lines; ++i)
    // {
    //     for ( auto j(0u); j < gt::n_cols; ++j)
    //     {
    //         base[i][j] = '0';// prenchendo '0' que simboliza a agua
    //     }
    // }

    gt::geraTab();
    gt::printTab();

    return 0;
}
