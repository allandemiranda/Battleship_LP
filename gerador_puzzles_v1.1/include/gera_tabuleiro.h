#ifndef GERA_TABULEIRO_H
#define GERA_TABULEIRO_H

/// constantes que serão usadas para verificar se a quantidade
/// de barcos já foi escrita no tabuleiro
#define MAX_BATTLESHIPS 1
#define MAX_CRUISERS 2
#define MAX_DESTROYERS 3
#define MAX_SUBMARINES 4

/// bibliotecas necessárias
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

/// gt = gerador de tabuleiros
namespace gt 
{
    /// número de tabuleiros, linhas e colunas
    unsigned short n_puzzles = 1, l = 7, c = 7;// padrão 1 7 7

    /// posição do barco escolhido
    /// obs: como são apenas duas posições( ou vertical ou horizontal ) fica mais otimizado
    /// usar bool do que usar unsigned short int 
    bool barcoPos;

    /// contador de ocorrências de cada tipo de barco
    std::vector<unsigned short> barcoQtd(4); 

    /// prepara o fluxo de escrita no arquivo de puzzles
    /// \param n_p é o número de puzzles
    /// \param n_l é o número de linhas
    /// \param n_c é o número de colunas  
    void prepareWriter(const unsigned short &n_p, const unsigned short &n_l, const unsigned short &n_c);

    /// escrever puzzle no arquivo de puzzles
    void writePuzzle(const std::vector < std::vector <char> > &a );

    /// exibe os puzzles no console
    void printPuzzle(const std::vector < std::vector <char> > &a); 

    /// escrever na matrix buffer
    void puzzleBuffer(std::vector < std::vector <char> > &a);

    /// zera matrix e o contador de barcos barcoQtd
    void reStartBuffer(std::vector < std::vector <char> > &a);

}

#endif
