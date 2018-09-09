#include "../include/gera_tabuleiro.h"
#include "./gera_tabuleiro.cpp" // só pra diminuir a linha de comando na compilação

int main ( int argc, char **argv )
{
    srand( (unsigned)time(0) ); // importante para o funcionamento da função gt::escolhaBarcos
    //std::ifstream writer( "../tabuleiros/tabuleiros.txt" );
    
    // armazenando e convertendo os parametros argv para int
    gt::n_puzzles = argv[1] != NULL ? atoi(argv[1]) : gt::n_puzzles; // número de tabuleiros
    gt::n_lines = argv[2] != NULL ? atoi(argv[2]) : gt::n_lines;// linhas
    gt::n_cols = argv[3] != NULL ? atoi(argv[3]) : gt::n_puzzles; // colunas

    // tabuleiro base apenas com agua( ' ' ), no qual será reutilizado para todos 
    // os outros tabuleiros que serão criados, para ter uma performance melhor.
    char base[gt::n_lines][gt::n_cols];

    for ( auto i(0u); i < gt::n_lines; ++i)
    {
        for ( auto j(0u); j < gt::n_cols; ++j)
        {
            base[i][j] = ' ';// prenchendo ' ' que simboliza a agua
        }
    }

    gt::escolhaBarcos();

    return 0;
}
