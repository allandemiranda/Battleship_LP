/**
 * @brief 
 * 
 * @file main.cpp
 * @author ./allandemiranda ./JO5U3 
 * @date 2018-09-14
 */

// Define
#define UPPER_LIMIT_SIDE 15 // Upper limit to the game board side
#define LOW_LIMIT_SIDE 7 // Low limit to the game board side
#define MAX_OF_PUZZLES_GENERATED 3 // Maximum of Puzzles generated per file

// Containers library
#include <vector> // std::vector container

// Include
#include "../include/entertainment.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    // Welcome and size board side
    int size_board = welcome(UPPER_LIMIT_SIDE, LOW_LIMIT_SIDE); /* < Size of game board side */

    // Select Puzzles and start the game
    std::vector < std::vector <char> > final_board;
    game_board_response(final_board, MAX_OF_PUZZLES_GENERATED, size_board);

    // Selecinar um Puzzles gerado
    // Imrimir 5 posições abertas aleatoriamente
    // Esperar entrada de linha x coluna
    // Imprimir status dos barcos a cada interação
    // Ao preencher todo campo retornar se acertou ou não

    return 0;
}