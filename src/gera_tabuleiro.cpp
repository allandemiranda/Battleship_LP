#include "../include/gera_tabuleiro.h"

std::ifstream writer( "../tabuleiros/tabuleiro.txt" );

void gt::escolhaBarcos()
{
    gt::barco = 1 + rand() % 4;
    gt::barcoPos = rand() % 2;// 0 = vertical e 1 = horizontal, obs: 2 não é
    
    /// obs: falta a parte de verificar se existem barcos na posição atual ou ao redor

    if ( gt::barco == 1 && barcoQtd[0] < MAX_BATTLESHIPS)
    {
        gt::battleship(barcoPos);
        gt::barcoQtd[0]++;
    }
    else if ( gt::barco == 2 && barcoQtd[1] < MAX_CRUISERS)
    {
        gt::cruiser(barcoPos);
        gt::barcoQtd[1]++;
    }
    else if ( gt::barco == 3 && barcoQtd[2] < MAX_DESTROYERS)
    {
        gt::destroyer(barcoPos);
        gt::barcoQtd[2]++;
    }
    else if ( gt::barco == 4 && barcoQtd[3] < MAX_SUBMARINES)
    {
        gt::submarine(barcoPos);
        gt::barcoQtd[3]++;
    }
}

// esqueletos das funções que gerarão os tabuleiros

void gt::battleship( const bool &pos )
{
    // obs: !pos = false e pos = true 

    if(!pos)
    {
        std::cout << "desenha o battleship na vertical" << std::endl;
    }
    else if(pos)
    {
        std::cout << "desenha o battleship na horizontal" << std::endl;
    }
}

void gt::cruiser( const bool &pos )
{
    if(!pos)
    {
        std::cout << "desenha o cruiser na vertical" << std::endl;
    }
    else if(pos)
    {
        std::cout << "desenha o cruiser na horizontal" << std::endl;
    }
}

void gt::destroyer( const bool &pos )
{
    if(!pos)
    {
        std::cout << "desenha o destroyer na vertical" << std::endl;
    }
    else if(pos)
    {
        std::cout << "desenha o destroyer na horizontal" << std::endl;
    }
}

void gt::submarine( const bool &pos )
{
    if(!pos)
    {
        std::cout << "desenha o submarine na vertical" << std::endl;
    }
    else if(pos)
    {
        std::cout << "desenha o submarine na horizontal" << std::endl;
    }
}
