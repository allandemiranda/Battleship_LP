#include "../include/gera_tabuleiro.h"
#include <iostream>

//using namespace gt;

std::ofstream writer( "../tabuleiros/tabuleiro.txt" );

unsigned short l = gt::n_lines-1, c = gt::n_cols-1;

void gt::geraTab(std::vector < std::vector <char> > &a)
{   
    /// comeca em 1 pois a matrix tera uma linha e uma coluna a mais para facilitar a verificação a matrix sera a[n_linhas+1][n_colunas+1];
    
    while( barcoQtd[0] < MAX_BATTLESHIPS && barcoQtd[1] < MAX_CRUISERS && barcoQtd[2] < MAX_DESTROYERS && barcoQtd[4] < MAX_SUBMARINES )
    {
        for( unsigned short int i(1); i < gt::n_lines; ++i )
        {
            for( unsigned short int j(1); j < gt::n_cols; ++j )
            {
                // if(gt::escolhasRd() == '0' && a[i][j] == '0') //|| a[i-1][j] == '0')// agua
                // {
                //     ++j;
                // } 
                if(gt::escolhasRd() == '1' && a[i][j] == '0' && a[i-1][j] == '0' && j+1 < c &&a[i][j+1] == '0' && a[i][j-1] == '0' )// submarine
                {
                    std::cout << "entrou submarine" << std::endl;
                    a[i][j] = '1';
                    ++j;
                    gt::barcoQtd[3]++;
                    //a[i][j] = j <= c ? '0' : a[i][j]; // proxima posição a direita recebe agua
                }
                else if(gt::escolhasRd() == '4' && a[i][j] == '0' && a[i-1][j] == '0' && i+1 < l && a[i][j+1] == '0' && a[i][j-1] == '0' )// destroyer vertical
                {
                    std::cout << "entrou destroyer vertical " << std::endl;
                    a[i][j] = '4';
                    a[i+1][j] = '5';
                    //a[i+2][j] = i+2 <= l ? '0' : a[i+2][j]; // proxima posição abaixo recebe agua
                    ++j;
                    gt::barcoQtd[2]++;
                    //a[i][j] = j <= c ? '0' : a[i][j]; // proxima posição a direita recebe agua
                }
                else if(gt::escolhasRd() == '2' && a[i][j] == '0' && a[i-1][j] == '0' && j+1 < c && a[i-1][j+1] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' )// destroyer horizontal
                {
                    std::cout << "entrou destroyer horizontal " << std::endl;
                    a[i][j] = '2';
                    ++j;
                    a[i][j] = '3';
                    ++j;
                    gt::barcoQtd[2]++;
                    //a[i][j] = j <= c ? '0' : a[i][j]; // proxima posição a direita recebe agua
                }
                else if(gt::escolhasRd() == '8' && a[i][j] == '0' && a[i-1][j] == '0' && i+2 < l && a[i][j+1] == '0' && a[i][j-1] == '0' )// cruiser vertical
                {
                    std::cout << "entrou cruiser vertical " << std::endl;
                    a[i][j] = '8';
                    a[i+1][j] = 'A';
                    a[i+2][j] = '9';
                    //a[i+3][j] = a[i+2][j] = i+3 <= l ? '0' : a[i+3][j]; // proxima posição abaixo recebe agua
                    ++j;
                    gt::barcoQtd[1]++;
                    //a[i][j] = j <= c ? '0' : a[i][j]; // proxima posição a direita recebe agua
                }
                else if(gt::escolhasRd() == '6' && a[i][j] == '0' && a[i-1][j] == '0' && a[i-1][j+1] == '0' && j+2 < c && a[i-1][j+2] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' )// cruiser horizontal
                {
                    std::cout << "entrou cruiser horizontal " << std::endl;
                    a[i][j] = '6';
                    ++j;
                    a[i][j] = 'A';
                    ++j;
                    a[i][j] = '7';
                    ++j;
                    gt::barcoQtd[1]++;
                    //a[i][j] = j <= c ? '0' : a[i][j]; // proxima posição a direita recebe agua                
                }
                else if(gt::escolhasRd() == 'D' && a[i][j] == '0' && a[i-1][j] == '0' && i+3 < l && a[i][j+1] == '0' && a[i][j-1] == '0' )// battleship vertical
                {
                    std::cout << "entrou battleship vertical " << std::endl;
                    a[i][j] = 'D';
                    a[i+1][j] = 'F';
                    a[i+2][j] = 'F';
                    a[i+3][j] = 'E';
                    //a[i+4][j] = a[i+4][j] = i+4 <= l ? '0' : a[i+4][j]; // proxima posição abaixo recebe agua
                    ++j;
                    gt::barcoQtd[0]++;
                    //a[i][j] = j <= c ? '0' : a[i][j]; // proxima posição a direita recebe agua
                }
                else if(gt::escolhasRd() == 'B' && a[i][j] == '0' && a[i-1][j] == '0' && j+3 < c && a[i-1][j+1] == '0' && a[i-1][j+2] == '0' && a[i-1][j+3] == '0' && a[i][j+1] == '0' && a[i][j-1] == '0' )// battleship horizontal
                {
                    std::cout << "entrou battleship horizontal " << std::endl;
                    a[i][j] = 'B';
                    ++j;
                    a[i][j] = 'F';
                    ++j;
                    a[i][j] = 'F';
                    ++j;
                    a[i][j] = 'C';
                    ++j;
                    gt::barcoQtd[0]++;
                    //a[i][j] = j < c ? '0' : a[i][j];
                }
                // else
                // {
                //     --j;
                // }
                    
            }
        }
    }
        
}

char gt::escolhasRd()
{
    gt::escolha = 1 + rand() % 10; // 5 6 7 8 9 são para água
    gt::barcoPos = rand() % 2;// 0 = vertical e 1 = horizontal, obs: 2 não é gerado
    // std::cout << "escolha = " << gt::escolha << " | barcoPos = " << gt::barcoPos << std::endl;

    // if( escolha == 1 && barcoQtd[0] == MAX_BATTLESHIPS)
    //     gt::escolha = 2 + rand() % 4;
    // if( escolha == 2 && barcoQtd[1] == MAX_CRUISERS )
    // {
    //     if()
    //     while( ( gt::escolha = 1 + rand() % 4 ) == 1 )
    // }
    //     ;
    // if( escolha == 3 && barcoQtd[2] == MAX_DESTROYERS )
    //     gt::escolha = 1 + rand() % 4;
    // if( escolha == 4 && barcoQtd[3] == MAX_SUBMARINES )
    //     gt::escolha = 1 + rand() % 3;

    /// BATTLESHIP
    if ( gt::escolha <= 3 && barcoQtd[0] < MAX_BATTLESHIPS)
    {
        //gt::barcoQtd[0]++;
        if(!barcoPos)
        {
            return 'D';
        }
        else if(barcoPos)
        {
            return 'B';
        }
    }
    /// CRUISER
    else if ( ( gt::escolha <= 5 || gt::escolha == 10 ) && barcoQtd[1] < MAX_CRUISERS)
    {
        //gt::barcoQtd[1]++;
        if(!barcoPos)
        {
            return '8';
        }
        else if(barcoPos)
        {
            return '6';
        }   
    }
    /// DESTROYER
    else if ( gt::escolha <= 8 && barcoQtd[2] < MAX_DESTROYERS)
    {
        //gt::barcoQtd[2]++;
        if(!barcoPos)
        {
            return '4';
        }
        else if(barcoPos)
        {
            return '2';
        }  
    }
    /// SUBMARINE
    else if ( gt::escolha <= 10 && barcoQtd[3] < MAX_SUBMARINES)
    {
        //gt::barcoQtd[3]++;
        return '1'; 
    }
    /// AGUA
    // else if ( gt::escolha > 8)
    // {
    //     return '0';
    // }
    return '0';
}

void gt::printTab(const std::vector < std::vector <char> > &a)
{
    for( unsigned short int i(1); i < gt::n_lines; ++i )
    {
        for( unsigned short int j(1), count = 0; j < gt::n_cols; ++j, ++count )
        {
            std::cout << a[i][j] << ' ';
            if(count == c+2)
            {
                std::cout<<std::endl;
                //std::cout << std::flush;
                count = 0;
            }
        }
    }
}


