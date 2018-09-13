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
    unsigned short int n_puzzles = 1, n_lines = 7, n_cols = 7;// padrão 1 7 7
    // escolhas entre barcos e agua
    unsigned short int escolha;
    // posição do barco escolhido
    // obs: como são apenas duas posições( ou vertical ou horizontal) fica mais otimizado
    // usar bool do que usar unsigned short int 
    bool barcoPos; 
    // contador de ocorrências de cada tipo de barco
    std::vector<unsigned short int> barcoQtd(4); 

    /// procedimentos que faltam fazer
    // void verficaSeTabuleiroExiste()
    // void desenha converteTabuleiroParaConsole()

    /// esqueleto dos procedimentos iniciais;
    std::vector< std::vector<char> > a;
    // escolhe entre barcos ou água, sua posição e chama
    // os procedimentos referentes ao barco escolhido
    char escolhasRd();
    /// gera o tabuleiro na matrix
    void geraTab(std::vector < std::vector <char> > a);

    // procedimentos dos barcos
    void printTab(std::vector < std::vector <char> > a);
}

#endif
