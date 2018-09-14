/**
 * @brief Battleship Game LP 2018.2
 * 
 * @file main.cpp
 * @author ./allandemiranda ./JO5U3 
 * @date 2018-09-14
 */

// Define
#define UPPER_LIMIT_SIDE 15 // Upper limit to the game board side
#define LOW_LIMIT_SIDE 7 // Low limit to the game board side
#define MAX_OF_PUZZLES_GENERATED 3 // Maximum of Puzzles generated per file
#define DIFICULT_PIXELS 5 // How many pixels is to open

// Containers library
#include <vector> // std::vector container

// Include
#include "../include/entertainment.h"
#include "../include/manipulation_puzzles.h"
#include "../include/user_manipulation.h"

/**
 * @brief The game
 * 
 * @return int EXIT_SUCCESS if finalized the game
 */
int main(void)
{
    // Welcome and size board side
    int size_board = welcome(UPPER_LIMIT_SIDE, LOW_LIMIT_SIDE); /* < Size of game board side */

    // Select Puzzles and start the game
    std::vector <char> final_board;
    game_board_response(final_board, MAX_OF_PUZZLES_GENERATED, size_board);

    // The game Puzzles to the User
    std::vector < std::vector <char> > puzzles_user;
    generator_board_user(final_board, puzzles_user, size_board, DIFICULT_PIXELS);






    // Esperar entrada de linha x coluna
    // Imprimir status dos barcos a cada interação
    // Ao preencher todo campo retornar se acertou ou não

    return EXIT_SUCCESS;
}