#include "../include/gera_tabuleiro.h"

using namespace gt;

/// ( path parte 1 ) criando variáveis necessárias para o path do arquivo de texto onde serão escritos os puzzles
std::string path1 = "../jogo_Battleship/puzzles/";
std::string path2 = "-puzzles-";
char x = 'x';
std::string lote;
std::string lin;
std::string col;
std::string path3 = ".txt";
std::string finalPath; 

/// fluxo de saída  
std::ofstream writer;

/// ( Path parte 2 e fluxo de saída ) preparando a o fluxo de saída e recebendo do usuário os dados necessários para gerar o path no formato lote-puzzles-linhasxcolunas.txt -> ex: 100-puzzles-10x10.txt
void gt::prepareWriter( unsigned short n, unsigned short a, unsigned short b)
{
    lote = std::to_string(n);
    lin = std::to_string(a);
    col = std::to_string(b);
    finalPath = path1+lote+path2+lin+x+col+path3;
    writer.open( finalPath );
} 

void gt::writePuzzle( const std::vector < std::vector <char> > &a )
{
    for( unsigned short i(1); i < gt::l+1; ++i )
    {
        for( unsigned short j(1); j < gt::c+1; ++j )
        {
            writer<< a[i][j];    
        }
        writer.put('\n');
    }
    /// para não colocar um espaço entre cada puzzle comente a instrução abaixo
    writer.put('\n');
} 

void gt::printPuzzle(const std::vector < std::vector <char> > &a)
{
    for( unsigned short i(1); i < l+1; ++i )
    {
        for( unsigned short j(1); j < c+1; ++j )
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout<<'\n';
    }
}

void gt::puzzleBuffer(std::vector < std::vector <char> > &a)
{
    /// posicoes da matrix que serão sorteadas para colocar os barcos se possível
    unsigned short i, j;
    /// procedimentos necessários para o sorteio das posições em i,j 
    std::random_device gen;
    std::mt19937 rng(gen());
    std::uniform_int_distribution<int> distribution(1, l); /// entre 1 e número de linhas
    std::uniform_int_distribution<int> distribution2(1, c); /// entre 1 e número de colunas
    std::uniform_int_distribution<int> distribution3(0, 1); /// entre vertical e horizontal
    
    /// contador de ocorrências das gerações de puzzles
    unsigned short k(0);

    while( k < gt::n_puzzles )
    {
        /// BATTLESHIP
        while( gt::barcoQtd[0] < MAX_BATTLESHIPS )
        {
            i = distribution(rng);
            j = distribution2(rng);
            gt::barcoPos = distribution3(rng);

            /// não precisa testar a possibilidade de colocar o battleship porque ele é o primeiro barco a ser colocado, sendo necessário testar somente se ele está dentro dos limites da matrix(encaixa)
            if(!gt::barcoPos) /// vertical
            {
                if(i+3 < l)
                {
                    a[i][j] = 'D';
                    a[i+1][j] = 'F';
                    a[i+2][j] = 'F';
                    a[i+3][j] = 'E';
                    gt::barcoQtd[0]++;
                }
            }
            else if(gt::barcoPos) /// horizontal
            {
                if(j+3 < c)
                {
                    a[i][j] = 'B';
                    a[i][j+1] = 'F';
                    a[i][j+2] = 'F';
                    a[i][j+3] = 'C';
                    gt::barcoQtd[0]++;
                }
            }
        }

        /// CRUISER
        while( gt::barcoQtd[1] < MAX_CRUISERS )
        {
            i = distribution(rng);
            j = distribution2(rng);
            gt::barcoPos = distribution3(rng);

            if(a[i][j] == '0')
            {
                if(!gt::barcoPos) /// vertical
                {
                    /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                    if( i+2 < l && a[i-1][j] == '0' && a[i+1][j] == '0' && a[i+2][j] == '0' && a[i+3][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j+1] == '0' && a[i+1][j-1] == '0' && a[i+2][j+1] == '0' && a[i+2][j-1] == '0' )
                    {
                        a[i][j] = '8';
                        a[i+1][j] = 'A';
                        a[i+2][j] = '9';
                        gt::barcoQtd[1]++;
                    }
                }
                else if(gt::barcoPos) /// horizontal
                {
                    /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                    if( j+2 < c && a[i-1][j] == '0' && a[i-1][j+1] == '0' && a[i-1][j+2] == '0' && a[i+1][j] == '0' && a[i+1][j+1] == '0' && a[i+1][j+2] == '0' && a[i][j-1] == '0' && a[i][j+1] == '0' && a[i][j+2] == '0' && a[i][j+3] == '0' )
                    {
                        a[i][j] = '6';
                        a[i][j+1] = 'A';
                        a[i][j+2] = '7';
                        gt::barcoQtd[1]++;
                    }
                }
            }    
        }

        /// DESTROYER
        while( gt::barcoQtd[2] < MAX_DESTROYERS )
        {
            /// se o puzzle tiver as linhas e colunas maiores que 7 essa será a estratégia adotada
            if( gt::l > 7 && gt::c > 7)
            {
                i = distribution(rng);
                j = distribution2(rng);
                gt::barcoPos = distribution3(rng);
                
                if(a[i][j] == '0')
                {
                    if(!gt::barcoPos) /// vertical
                    {
                        /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                        if( i+1 < l && a[i-1][j] == '0' && a[i+2][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j+1] == '0' && a[i+1][j-1] == '0' )
                        {
                            a[i][j] = '4';
                            a[i+1][j] = '5';
                            gt::barcoQtd[2]++;
                        }
                    }
                    else if(gt::barcoPos) /// horizontal
                    {
                        /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                        if( j+1 < c && a[i-1][j] == '0' && a[i-1][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j] == '0' && a[i+1][j+1] == '0' && a[i][j+1] == '0' && a[i][j+2] == '0' )
                        {
                            a[i][j] = '2';
                            a[i][j+1] = '3';
                            gt::barcoQtd[2]++;
                        }
                    }
                }
            }
            /// se o puzzle tiver as linhas ou colunas iguais a 7 será usada essa estratégia
            else
            for( unsigned short i(1); i < gt::l+1; ++i )
            {
                for( unsigned short j(1); j < gt::c+1; ++j )
                {
                    gt::barcoPos = distribution3(rng);
            
                    if(a[i][j] == '0' && gt::barcoQtd[2] < MAX_DESTROYERS )
                    {
                        if(!gt::barcoPos) /// vertical
                        {
                            /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                            if( i+1 < l && a[i-1][j] == '0' && a[i+2][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j+1] == '0' && a[i+1][j-1] == '0' )
                            {
                                a[i][j] = '4';
                                a[i+1][j] = '5';
                                gt::barcoQtd[2]++;
                            }
                        }
                        else if(gt::barcoPos) /// horizontal
                        {
                            /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                            if( j+1 < c && a[i-1][j] == '0' && a[i-1][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j] == '0' && a[i+1][j+1] == '0' && a[i][j+1] == '0' && a[i][j+2] == '0' )
                            {
                                a[i][j] = '2';
                                a[i][j+1] = '3';
                                gt::barcoQtd[2]++;
                            }
                        }
                    }
                }
            }
            /// se não foi possível encaixar os barcos então finaliza o laço
            if( gt::barcoQtd[2] < MAX_DESTROYERS && (gt::l == 7 || gt::c == 7) )
            {
                break;
            }    
        }
        /// se não foi possível encaixar os barcos então reinicie a geração do puzzle
        if( gt::barcoQtd[2] < MAX_DESTROYERS)
        {
            reStartBuffer(a);
            continue;
        }

        /// SUBMARINE
        while( gt::barcoQtd[3] < MAX_SUBMARINES )
        {
            /// se o puzzle tiver as linhas e colunas maiores que 7 essa será a estratégia adotada
            if( gt::l > 7 && gt::c > 7 )
            {
                i = distribution(rng);
                j = distribution2(rng);

                if(a[i][j] == '0')
                {
                    /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                    if( a[i-1][j] == '0' && a[i+1][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' )
                    {
                        a[i][j] = '1';
                        gt::barcoQtd[3]++;
                    }
                }
            }
            /// se o puzzle tiver as linhas ou colunas iguais a 7 será usada essa estratégia usada
            else 
            for( unsigned short i(1); i < gt::l+1; ++i )
            {
                for( unsigned short j(1); j < gt::c+1; ++j )
                {
                    if(a[i][j] == '0' && barcoQtd[3] < MAX_SUBMARINES)
                    {
                        /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                        if( a[i-1][j] == '0' && a[i+1][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' )
                        {
                            a[i][j] = '1';
                            gt::barcoQtd[3]++;
                        }
                    }
                }
            }
            /// se não foi possível encaixar os barcos então encerra o laço
            if( gt::barcoQtd[3] < MAX_SUBMARINES && (gt::l == 7 || gt::c == 7) )
            {
                break;
            }
        }
        /// se não foi possível encaixar os barcos então reinicie a geração do puzzle
        if( gt::barcoQtd[3] < MAX_SUBMARINES)
        {
            reStartBuffer(a);
            continue;
        }
        else
        {
            ++k;
            std::cout<<k<<std::endl; /// opcional mostrar numero do puzzle gerado
            gt::writePuzzle(a);
            gt::printPuzzle(a);/// opcional mostrar os puzzles no console
            gt::reStartBuffer(a);
        }
    }   
}

void gt::reStartBuffer(std::vector < std::vector <char> > &a)
{
    /// zera a matrix
    for( unsigned short i(0); i < gt::l+2; ++i)
    {
        for ( unsigned short j(0); j < gt::c+2; ++j )
        {
            a[i][j] = '0';
        }
    }
    /// zera o contador de barcos
    for( unsigned short i(0); i < 4; ++i )
    {
        gt::barcoQtd[i] = 0;
    }
}


