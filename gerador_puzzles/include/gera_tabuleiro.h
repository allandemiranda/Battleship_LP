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
#include <unistd.h>

namespace gt // gt = gerador de tabuleiros
{
    /// número de tabuleiros, linhas e colunas
    unsigned short n_puzzles = 1, l = 7, c = 7;// padrão 1 7 7
    /// posição do barco escolhido
    /// obs: como são apenas duas posições( ou vertical ou horizontal) fica mais otimizado
    /// usar bool do que usar unsigned short int 
    bool barcoPos;
    /// contador de ocorrências de cada tipo de barco
    std::vector<unsigned short int> barcoQtd(4); 
   
    void printTab(const std::vector < std::vector <char> > &a); /// printar no console
    void puzzleBuffer(std::vector < std::vector <char> > &a); /// escrever na matrix
    void writePuzzle(std::vector < std::vector <char> > &a); /// escrever no arquivo
}

#endif
