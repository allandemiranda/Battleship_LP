#include "../include/gera_tabuleiro.h"
#include "./gera_tabuleiro.cpp" // só pra diminuir a linha de comando na compilação

int main ( int argc, char **argv )
{
    /// variável auxiliar que recebe os argumentos de **argv
    unsigned short argvAux[argc];
    
    /// inicializa argvAux com os argumentos de **argv
    for( unsigned short i(1); i < argc; ++i )
    {
        argvAux[i] = atoi(argv[i]);
    }
    
    /// verifica se a quantidade de argumentos é válida
    if ( argc == 1 || argc > 4)
    {
        std::cerr << "Erro: número inválido de argumentos, o programa deve conter 3 argumentos de usuário: [n_puzzles, lines, cols]";
        return EXIT_FAILURE;
    }

    /// testa a validade do primeiro argumento
    if( argvAux[1] > 100 || argvAux[1] < 1 )
    {
        std::cerr << "Erro: argumento 1 deve ser maior ou igual a 1 e menor ou igual a 100";
        return EXIT_FAILURE;
    }

    /// testa a validade do primeiro e/ou do segundo argumento 
    if( (argc > 2 && argvAux[3] > 15) || (argvAux[3] < 7 && argvAux[3] != 0 ) || (argvAux[2] > 15 || (argvAux[2] < 7 && argvAux[2] != 0) ) )
    {
        std::cerr << "Erro: argumento 2 e 3 se especificados devem estar dentro do intervalo válido [7, 15]";
        return EXIT_FAILURE;
    }

    /// armazena e converte os parametros argv para int

    /// número de puzzles
    gt::n_puzzles = atoi(argv[1]);
    /// número de linhas e colunas
    if( argc == 4 )
    {
        gt::l = argv[2] != NULL ? atoi(argv[2]) : gt::l;/// linhas
        gt::c = argv[3] != NULL ? atoi(argv[3]) : gt::c; /// colunas
    }
    /// número de linhas se apenas as linhas forem especificadas
    else if ( argc == 3 )
    {
        gt::l = argv[2] != NULL ? atoi(argv[2]) : gt::l;/// linhas
    }

    /// vector de vector de char que será o buffer dos puzzles
    std::vector< std::vector<char> > a(gt::l+2, std::vector<char>(gt::c+2));

    /// inicializa a com '0' que representa água e é necessário para o correto funcionamento dos algoritmos que irão gerar os puzzles
    for ( unsigned short i(0); i < gt::l+2; ++i )
    {
        for ( unsigned short j(0); j < gt::c+2; ++j )
        {
            a[i][j] = '0';
        }
    }

    /// prepara a geração e o nome do arquivo de puzzle que tem o formato = lote-puzzles-linhasXcolunas.txt -> ex: 100-puzzles-10x10.txt 
    gt::prepareWriter(gt::n_puzzles, gt::l, gt::c);

    /// gera, escreve os puzzles no arquivo .txt, e exibe no console os puzzles
    gt::puzzleBuffer(a);

    return 0;
}
