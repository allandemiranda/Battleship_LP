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
        std::cout << "What game puzzle size you want? (side)" << std::endl;
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
    std::cout << std::endl;
    return size;
}

/**
 * @brief Function to print the status of the Puzzles
 * 
 * @param board_final The Vector with final puzzles
 * @param board_user The Puzzles User
 * @param ship_one submarines (one square in size)
 * @param ship_two destroyers (two squares long)
 * @param ship_three cruisers (three squares long)
 * @param ship_four battleship (four squares long)
 */
void dashboard_user_print(std::vector <char> board_final, std::vector <std::vector <char>> board_user, int const ship_one, int const ship_two, int const ship_three, int const ship_four){
    // Print ships left
    std::cout << std::endl;
    std::cout << "Do you have to add: " << std::endl;
    std::cout << ship_one << " submarines (one square in size) -> $code 4" << std::endl;
    std::cout << ship_two << " destroyers (two squares long) -> $code 3" << std::endl;
    std::cout << ship_three << " cruisers (three squares long) -> $code 2" << std::endl;
    std::cout << ship_four << " battleship (four squares long) -> $code 1" << std::endl;
     std::cout << std::endl;
    //Print the Puzzles
    int pixel(0); /* < Pixel from board_final orientation */
    for(int i(0); i<board_user.size(); ++i){ // Line
        int number_ship(0); /* < Number of ship os the line */
        for(int j(0); j<board_user[i].size(); ++j, ++pixel){ // Column
            std::cout << board_user[i][j] << " ";
            if(board_final[pixel] != '0'){
                ++number_ship;
            }
        }
        std::cout << "| " << number_ship << std::endl;
    }
    std::cout << "--------------------" << std::endl;
    // Need a clumn number_ship
    for(int i(0); i<board_user.size(); ++i){
        int number_ship(0); /* < Number of ship os the Column */
        for(int j(0); j<board_user.size(); ++j){
            if(board_final[(j * board_user.size()) + i] != '0'){
                ++number_ship;
            }
        }
        std::cout << number_ship << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Function to show to the user the erro experience
 * 
 * @param code Code number erro
 */
void puzzles_erro_code(int const code){
    // Everything is ok
    if(code == 0){
        // Debug erro
        std::cout << std::endl;
        std::cout << "Everything is ok!" << std::endl;
        std::cout << std::endl;
    }
    // The limit gone
    if(code == 1){
        std::cout << std::endl;
        std::cout << "The limit gone!" << std::endl;
        std::cout << "Try another entry." << std::endl;
        std::cout << std::endl;
    }
    // Have somethin in the way
    if(code == 2){
        std::cout << std::endl;
        std::cout << "Have somethin in the way!" << std::endl;
        std::cout << "Try another entry." << std::endl;
        std::cout << std::endl;
    }
    // Have somethin in the way
    if(code == 3){
        std::cout << std::endl;
        std::cout << "Erro in the horizontal (code = 1) or vertical (code = 2)!" << std::endl;
        std::cout << "Try another entry." << std::endl;
        std::cout << std::endl;
    }
}

/**
 * @brief Function to taype the code and coordinates
 * 
 * @param coordinates_code Vector with code ad coordinates
 */
void coordinates_input_print(int *coordinates_code){
    std::cout << std::endl;
    std::cout << "Type in the code ship [1-4]: " << std::endl;
    std::cin >> coordinates_code[0];
    std::cout << "Type in the Coordinates Line [0-side]: " << std::endl;
    std::cin >> coordinates_code[1];
    std::cout << "Type in the Coordinates Colunm [0-side]: " << std::endl;
    std::cin >> coordinates_code[2];
    std::cout << "Type in the Horizontal (code = 1) or Vertical (code = 2): " << std::endl;
    std::cin >> coordinates_code[3];
}

/**
 * @brief Function to check if ships are available
 * 
 * @param ship_code Ship code
 * @param ship_one Quantity battleship
 * @param ship_two Quantity cruisers
 * @param ship_three Quantity destroyers
 * @param ship_four Quantity submarines
 * @return true It's ok
 * @return false No longer available this ship
 */
bool ships_available(int const ship_code, int const ship_four, int const ship_three, int const ship_two, int const ship_one){
    if((ship_one == 0) and (ship_code == 1)){
        std::cout << "No longer available this ship!" << std::endl;
        return false;
    }
    if((ship_two == 0) and (ship_code == 2)){
        std::cout << "No longer available this ship!" << std::endl;
        return false;
    }
    if((ship_three == 0) and (ship_code == 3)){
        std::cout << "No longer available this ship!" << std::endl;
        return false;
    }
    if((ship_four == 0) and (ship_code == 4)){
        std::cout << "No longer available this ship!" << std::endl;
        return false;
    }
    return true;
}