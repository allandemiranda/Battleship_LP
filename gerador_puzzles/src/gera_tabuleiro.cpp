#include "../include/gera_tabuleiro.h"

std::ofstream writer( "../tabuleiros/tabuleiro.txt" );

using namespace gt;

void gt::printTab(const std::vector < std::vector <char> > &a)
{
    for( unsigned short i(1); i < l+1; ++i )
    {
        for( unsigned short j(1); j < c+1; ++j )
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout<<std::endl;
    }
}
/// posicoes da matrix que serão sorteadas para colocar os barcos se possível
unsigned short i, j; 

void gt::puzzleBuffer(std::vector < std::vector <char> > &a)
{
    srand( (unsigned)time(nullptr));
    /// BATTLESHIP
    while( gt::barcoQtd[0] < MAX_BATTLESHIPS )
    {
        i = 1 + rand() % (l);
        j = 1 + rand() % (c);
        gt::barcoPos = rand() % 2;
        /// não precisa testar a possibilidade de colocar o battleship pq ele é o primeiro barco a ser colocado, sendo necessário testar somente se ele está fora dos limites da matrix
        if(!gt::barcoPos) /// vertical
        {
            if(i+3 < l)
            {
                std::cout << "entrou battleship vertical " << std::endl;
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
                std::cout << "entrou battleship horizontal " << std::endl;
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
        i = 1 + rand() % (l);
        j = 1 + rand() % (c);
        gt::barcoPos = rand() % 2;

        if(a[i][j] == '0')
        {
            if(!gt::barcoPos) /// vertical
            {
                /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                if( i+2 < l && a[i-1][j] == '0' && a[i+1][j] == '0' && a[i+2][j] == '0' && a[i+3][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j+1] == '0' && a[i+1][j-1] == '0' && a[i+2][j+1] == '0' && a[i+2][j-1] == '0' )
                {
                    std::cout << "entrou cruiser vertical " << std::endl;
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
                    std::cout << "entrou cruiser horizontal " << std::endl;
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
        i = 1 + rand() % (l);
        j = 1 + rand() % (c);
        gt::barcoPos = rand() % 2;
        
        if(a[i][j] == '0')
        {
            if(!gt::barcoPos) /// vertical
            {
                /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
                if( i+1 < l && a[i-1][j] == '0' && a[i+2][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' && a[i+1][j+1] == '0' && a[i+1][j-1] == '0' )
                {
                    std::cout << "entrou destroyer vertical " << std::endl;
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
                    std::cout << "entrou destroyer horizontal " << std::endl;
                    a[i][j] = '2';
                    a[i][j+1] = '3';
                    gt::barcoQtd[2]++;
                }
            }
        }
        //std::cout<<"destroyer"<<std::endl;    
    }

    /// SUBMARINE
    while( gt::barcoQtd[3] < MAX_SUBMARINES )
    {
        i = 1 + rand() % (l);
        j = 1 + rand() % (c);

        if(a[i][j] == '0')
        {
            /// testando se há possibilidade de colocar o barco, e se encaixa na matrix
            if( a[i-1][j] == '0' && a[i+1][j] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' )
            {
                std::cout << "entrou submarine" << std::endl;
                a[i][j] = '1';
                gt::barcoQtd[3]++;
            }
        }
        //std::cout<<"submarine"<<std::endl;    
    }
}


