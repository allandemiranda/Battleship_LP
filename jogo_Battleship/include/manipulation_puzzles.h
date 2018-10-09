/**
 * @brief It contains all the manipulation functions of the Puzzle
 * 
 * @file manipulation_puzzles.h
 * @author ./allandemiranda ./JO5U3
 * @date 2018-09-14
 */

// Input output library
#include <fstream> // std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates and several typedefs 
#include <string> // The class template basic_string stores and manipulates sequences of char-like objects

// Containers library
#include <vector> // std::vector container 

// C compatibility headers
#include <cstdlib> // This header provides miscellaneous utilities
#include <ctime> // C-style time/date utilites

/**
 * @brief Function to change characters os puzzles
 * 
 * @param name The character
 * @return char The new character
 */
char change_characters(char const name){
    if(name != '0'){
        if(name == '1'){
            return '+';
        }
        if(name == '2'){
            return '<';
        }
        if(name == '3'){
            return '>';
        }
        if(name == '4'){
            return '^';
        }
        if(name == '5'){
            return 'v';
        }
        if(name == '6'){
            return '<';
        }
        if(name == '7'){
            return '>';
        }
        if(name == '8'){
            return '^';
        }
        if(name == '9'){
            return 'v';
        }
        if(name == 'A'){
            return '+';
        }
        if(name == 'B'){
            return '<';
        }
        if(name == 'C'){
            return '>';
        }
        if(name == 'D'){
            return '^';
        }
        if(name == 'E'){
            return 'v';
        }
        if(name == 'F'){
            return '+';
        }
    }
    return '0'; // Whater
}

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
    std::string name_arq;
    if(size == 7){
        name_arq = "../puzzles/100-puzzle(s)-7x7.txt";
    } 
    if(size == 8){
        name_arq = "../puzzles/100-puzzle(s)-8x8.txt";
    }    
    if(size == 9){
        name_arq = "../puzzles/100-puzzle(s)-9x9.txt";
    }   
    if(size == 10){
        name_arq = "../puzzles/100-puzzle(s)-10x10.txt";
    }  
    if(size == 11){
        name_arq = "../puzzles/100-puzzle(s)-11x11.txt";
    }  
    if(size == 12){
        name_arq = "../puzzles/100-puzzle(s)-12x12.txt";
    }  
    if(size == 13){
        name_arq = "../puzzles/100-puzzle(s)-13x13.txt";
    }  
    if(size == 14){
        name_arq = "../puzzles/100-puzzle(s)-14x14.txt";
    }  
    if(size == 15){
        name_arq = "../puzzles/100-puzzle(s)-15x15.txt";
    }  
    std::ifstream puzzles(name_arq); /* < Open tem puzzles doc */
    std::vector <char> temp; /* < Temp vector to swap to the real board */
    char val; /* < Valuer to copy */
    while (puzzles >> val) {
        // Change of characters
        char new_c = change_characters(val);
        // Save the new characters
		temp.push_back(new_c);
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