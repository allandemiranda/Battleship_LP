/**
 * @brief It contains all the manipulation functions of the Puzzle
 * 
 * @file manipulation_puzzles.h
 * @author ./allandemiranda ./JO5U3
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
 * @param upper_rand Define parameter to upper randon
 * @param size Side size from game board
 * @return std::vector <char> Game board
 */
std::vector <char> game_board_response(int const upper_rand, int const size){
    std::vector <char> board; /* < Vector to create the puzzels */
    //std::srand(std::time(nullptr)); // Use current time as seed for random generator // Desativado
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
    for(int i(0); i<(size * size); ++i){
            board.push_back(temp[element + i]);
    }
    return board;
}

/**
 * @brief Function to generate board for user to play
 * 
 * @param board_final The Vector with final puzzles
 * @param board_user The Puzzles User
 * @param size Side of Puzzles
 * @param dificult How many pixels is to open
 */
std::vector < std::vector <char> > generator_board_user(std::vector <char> board_final, int const size, int const dificult){
    std::vector < std::vector <char> > board_user; /* < Vector to create the puzzels USER */    
    // Preparing pixel that will be visible
    int pixel_open[dificult];
    for(int i(0); i<dificult; ++i){
        //std::srand(std::time(nullptr)); // Use current time as seed for random generator // Desativado
        int random_number = std::rand()/((RAND_MAX + 1u)/((size * size) - 1)); /* < Random number to select the pixel that will be visible */
        pixel_open[i] = random_number;
    }
    // Preparing the pixel puzzles User
    int pixel(0);
    for(int i(0); i<size; ++i){
        std::vector <char> temp;
        for(int j(0); j<size; ++j, ++pixel){
            bool pixel_to_open = false; // if the generated pixel is the need opened
            for(int k(0); k<dificult; ++k){
                if(pixel_open[k] == pixel){
                    pixel_to_open = true;
                    break;
                }
            }
            if(pixel_to_open){
                temp.push_back(board_final[pixel]);
            } else {
                temp.push_back(' ');
            }
        }
        board_user.push_back(temp);
    }
    return board_user;
}

/**
 * @brief Function to check if it's the same as the original
 * 
 * @param user User puzzles
 * @param puzzles Original puzzles
 * @return true Difference found
 * @return false Not difference found
 */
bool cheking_answer(std::vector<std::vector<char>> user, std::vector<char> puzzles){
    int pixel(0); /* < Pixel from puzzles orientation */
    for(int i(0); i<user.size(); ++i){ // Line
        for(int j(0); j<user[i].size(); ++j, ++pixel){ // Column
            if(user[i][j] != puzzles[pixel]){
                // Difference found
                return false;
            }
        }
    }
    // Not difference found
    return true;
}