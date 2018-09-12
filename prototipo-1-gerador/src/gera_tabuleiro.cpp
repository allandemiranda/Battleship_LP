#include "../include/gera_tabuleiro.h"
#include <iostream>

//using namespace gt;

std::ofstream writer( "../tabuleiros/tabuleiro.txt" );

/// tentativa de usar vector de vector ou a matrix de char estilo c
//const int l( (const int)(gt::n_lines+1) ), c( (const int)(gt::n_cols+1) );
unsigned short l, c;
void gt::getDim( unsigned short line, unsigned short col )
{
    l = line;
    c = col;
}
char a[l+1][c+1];// l = linhas, c = colunas
//std::vector< std::vector<char> > a;
for( auto i(0); i < gt::n_lines; ++i )
{
    for( auto j(0); j < gt::n_cols; ++j )
    {
        a[i][j] = '0';// prenchendo ' ' que simboliza vazio
    }
}
/// fim da tentativa


// for( auto j(0u); j < 1; ++j )
// {
//     a[0][j] = '0';
// }
// for( auto i(0u); i < 1; ++i )
// {
//     a[i][0] = '0';
// }

void gt::geraTab()
{   
    /// comeca em 1 pois a matrix tera uma linha e uma coluna a mais para facilitar a verificação a matrix sera a[n_linhas+1][n_colunas+1];
    /// o algoritmo ta correto o que falta é resolver o problema da matrix de char
    for( auto i(1); i < gt::n_lines; ++i )
    {
        for( auto j(1); j < gt::n_cols; ++j )
        {
            if(gt::escolhasRd() == '0' && a[i][j] == '0' || a[i-1][j] == '0')// agua
            {
                ++j;
                continue;
            } 
            else if(gt::escolhasRd() == '1')// submarine
            {
                if(a[i][j] == ' ' || a[i][j] == '0' && a[i-1][j] == '0')
                {
                    a[i][j] = '1';
                    ++j;
                    a[i][j] = '0';
                }
            }
            else if(gt::escolhasRd() == '4' && a[i][j-1] == '0' && a[i-1][j] == '0' && j+1 < c-1)// destroyer vertical
            {
                a[i][j] = '2';
                a[i+1][j] = '3';
                a[i+2][j] = '0';
            }
            else if(gt::escolhasRd() == '4' && a[i][j] == '0' && a[i-1][j] == '0' && i+1 < l-1)// destroyer horizontal
            {
                a[i][j] = '4';
                ++j;
                a[i][j] = '5';
                ++j;
                a[i][j] = '0';
            }
            else if(gt::escolhasRd() == '4' && a[i][j-1] == '0' && a[i-1][j] == '0' && j+1 < c-1)// cruiser vertical
            {
                a[i][j] = '8';
                a[i+1][j] = 'A';
                a[i+2][j] = '9';
                a[i+3][j] = '0';
            }
            else if(gt::escolhasRd() == '4' && a[i][j] == '0' && a[i-1][j] == '0' && i+1 < l-1)// cruiser horizontal
            {
                a[i][j] = '6';
                ++j;
                a[i][j] = 'A';
                ++j;
                a[i][j] = '7';
                ++j;
                a[i][j] = '0';
            }
            else if(gt::escolhasRd() == '4' && a[i][j-1] == '0' && a[i-1][j] == '0' && j+1 < c-1)// battleship vertical
            {
                a[i][j] = 'D';
                a[i+1][j] = 'F';
                a[i+2][j] = 'F';
                a[i+3][j] = 'E';
                a[i+4][j] = '0';
            }
            else if(gt::escolhasRd() == '4' && a[i][j] == '0' && a[i-1][j] == '0' && i+1 < l-1)// battleship horizontal
            {
                a[i][j] = 'B';
                ++j;
                a[i][j] = 'F';
                ++j;
                a[i][j] = 'F';
                ++j;
                a[i][j] = 'C';
                ++j;
                a[i][j] = '0';
            }
        }
    }
}

char gt::escolhasRd()
{
    gt::escolha = 1 + rand() % 9; // 5 6 7 8 9 são para água
    gt::barcoPos = rand() % 2;// 0 = vertical e 1 = horizontal, obs: 2 não é gerado

    /// BATTLESHIP
    if ( gt::escolha == 1 && barcoQtd[0] < MAX_BATTLESHIPS)
    {
        if(!barcoPos)
        {
            return 'D';
        }
        else if(barcoPos)
        {
            return 'B';
        }
        gt::barcoQtd[0]++;
    }
    /// CRUISER
    else if ( gt::escolha == 2 && barcoQtd[1] < MAX_CRUISERS)
    {
        if(!barcoPos)
        {
            return '8';
        }
        else if(barcoPos)
        {
            return '6';
        }
        gt::barcoQtd[1]++;
    }
    /// DESTROYER
    else if ( gt::escolha == 3 && barcoQtd[2] < MAX_DESTROYERS)
    {
        if(!barcoPos)
        {
            return '4';
        }
        else if(barcoPos)
        {
            return '2';
        }
        gt::barcoQtd[2]++;
    }
    /// SUBMARINE
    else if ( gt::escolha == 4 && barcoQtd[3] < MAX_SUBMARINES)
    {
        return '1';
        gt::barcoQtd[3]++;
    }
    /// AGUA
    else if ( gt::escolha > 4)
    {
        return '0';
    }
}

void gt::printTab()
{
    for( auto i(1u); i < gt::n_lines; ++i )
    {
        for( auto j(1u); j < gt::n_cols; ++j )
        {
            std::cout << a[i][j];
        }
    }
}


