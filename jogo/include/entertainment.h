/**
 * @brief User entertainment functions
 * 
 * @file entertainment.h
 * @author ./allandemiranda ./JO5U3 
 * @date 2018-09-14
 */

// Input output library
#include <iostream> // several standard stream objects 

/**
 * @brief Welcome function and initial interaction
 * 
 * @param upper_limit Upper limit to the game board
 * @param low_limit Low limit to the game board
 * @return int Size of game board side
 */
int welcome(int const upper_limit, int const low_limit){
    std::cout << "-|--- Welcome to Battleship ---|-" << std::endl;
    int size(0); /* < Game board size */
    // Checking the input value to "size"
    while(true){
        std::cout << "What game board size you want? (side)" << std::endl;
        std::cin >> size;
        if((size <= upper_limit) and (size >= low_limit)){
            // The value is correct
            break;
        } else {
            // The value is incorrect
            std::cout << "Sorry!" << std::endl;
            std::cout << "The low limit is " << low_limit;
            std::cout << " and the upper limit is " << upper_limit << std::endl;
            std::cout << "Please, enter a number that does not exceed the limits." << std::endl;
        }
    }
    return size;
}

void dashboard_user_print(std::vector <std::vector <char>> board, int const ship_one, int const ship_two, int const ship_three, int const ship_four){
    // Print ships left
    std::cout << "Do you have to add: " << std::endl;
    std::cout << ship_one << " submarines (one square in size)" << std::endl;
    std::cout << ship_two << " destroyers (two squares long)" << std::endl;
    std::cout << ship_three << " cruisers (three squares long)" << std::endl;
    std::cout << ship_four << " battleship (four squares long)" << std::endl;
    //Print the Puzzles
    for(int i(0); i<board.size(); ++i){ // Line
        for(int j(0); j<board[i].size(); ++j){ // Column

        }
    }

}