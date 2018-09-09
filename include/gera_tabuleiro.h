#ifndef GERA_TABULEIRO_H
#define GERA_TABULEIRO_H

// constantes que serão usadas para verificar se a quantidade
// de barcos já foi escrita no tabuleiro
#define MAX_BATTLESHIPS 1
#define MAX_CRUISERS 2
#define MAX_DESTROYERS 3
#define MAX_SUBMARINES 4

// bibliotecas necessárias
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

namespace gt // gt = gerador de tabuleiros
{
    /// variáveis necessárias
    // número de tabuleiros, linhas e colunas
    unsigned short int n_puzzles = 1, n_lines = 10, n_cols = 10;
    // tipos de barcos
    unsigned short int barco;
    // posição do barco escolhido
    // obs: como são apenas duas posições( ou vertical ou horizontal) fica mais otimizado
    // usar bool do que usar unsigned short int 
    bool barcoPos; 
    // contador de ocorrências de cada tipo de barco
    std::vector<unsigned short int> barcoQtd(4); 

    /// procedimentos que faltam fazer

    // void verficaSeTabuleiroExiste()
    // void verifica-se-tem-barcos-ao-redor()
    // void desenha converteTabuleiroParaConsole()

    /// esqueleto dos procedimentos iniciais;

    // escolhe o tipo de barco, sua posição e chama
    // os procedimentos referentes ao barco escolhido
    void escolhaBarcos();

    // procedimentos dos barcos
    void battleship (const bool &pos);// barco de tamanho 4
    void cruiser (const bool &pos);// barco de tamanho 3
    void destroyer (const bool &pos);// barco de tamanho 2
    void submarine (const bool &pos);// barco de tamanho 1
}

#endif
