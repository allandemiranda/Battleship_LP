/**
 * @brief It contains all the manipulation functions of the Puzzle
 * 
 * @file manipulation_puzzles.h
 * @author your name
 * @date 2018-09-14
 */

// Input output library
#include <fstream> // std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates and several typedefs 

// Containers library
#include <vector> // std::vector container 

// C compatibility headers
#include <cstdlib> // This header provides miscellaneous utilities
#include <ctime> // C-style time/date utilites

/**
 * @brief Function for picking up a game board valid
 * 
 * @param board Game board
 * @param upper_rand Define parameter to upper randon
 * @param size Side size from game board
 */
void game_board_response(std::vector < std::vector <char> > board, int const upper_rand, int const size){
    std::srand(std::time(nullptr)); // Use current time as seed for random generator
    int random_number = std::rand()/((RAND_MAX + 1u)/(upper_rand - 1)); /* < Random number to select the puzzles */
    // Add the board to the vector
    /**
     * 
     * Aqui coloque o complemento da fubnção para caso haja mais tamanhos de puzzles disponíveis
     * Use a contante int size para saber que arquivo de tamanhod e puzzles abrir
     * 
     */
    std::ifstream puzzles("../puzzles/puzzles.txt"); /* < Open tem puzzles doc */
    std::vector <char> temp; /* < Temp vector to swap to the real board */
    char val; /* < Valuer to copy */
    while (puzzles >> val) {
		temp.push_back(val);
	}
	puzzles.close(); // Close de doc puzzçes.txt
    // Swaping to board vector
    int element = random_number * (size * size); /* < Position of the element "temp" to be copied */
    for(int i(0); i<size; ++i){
        for(int j(0); j<size; ++j){
            board[i].push_back(temp[element]);
            ++element;
        }
    }
}