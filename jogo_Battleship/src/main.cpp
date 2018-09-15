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
#define DIFICULT_PIXELS 20 // How many pixels is to open
#define QUANTITY_OF_SUBMARINES 4 // Submarines (one square in size) -> $code 4
#define QUANTITY_OF_DESTROYERS 3 // Destroyers (two squares long) -> $code 3
#define QUANTITY_OF_CRUISERS 2 // Cruisers (three squares long) -> $code 2
#define QUANTITY_OF_BATTLESHIP 1 // Battleship (four squares long) -> $code 1

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
    std::vector <char> final_board = game_board_response(MAX_OF_PUZZLES_GENERATED, size_board);

    // The game Puzzles to the User
    std::vector < std::vector <char> > puzzles_user = generator_board_user(final_board, size_board, DIFICULT_PIXELS);

    // Ship quantity declareition
    int submarines_quantity = QUANTITY_OF_SUBMARINES; // $code 4
    int destroyers_quantity = QUANTITY_OF_DESTROYERS; // $code 3
    int cruisers_quantity = QUANTITY_OF_CRUISERS; // $code 2
    int battleship_quantity = QUANTITY_OF_BATTLESHIP; // $code 1

    // Playing
    while(true){
        // Print puzzles
        dashboard_user_print(final_board, puzzles_user, submarines_quantity, destroyers_quantity, cruisers_quantity, battleship_quantity);
        // Start the parameters for coordinates
        int coordinates[4];
        coordinates_input_print(&coordinates[0]);
        // Check if ships are available
        if(!ships_available(coordinates[0],submarines_quantity, destroyers_quantity, cruisers_quantity, battleship_quantity)){
            // Skip drawing the puzzles
            continue;
        }
        // Draw the ship
        int code_erro = put_new_boat(puzzles_user, size_board, coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
        if(code_erro == 0){
            // Remove the ship added
            if(coordinates[0] == 1){
                battleship_quantity--;                
            } 
            if(coordinates[0] == 2){
                cruisers_quantity--;
            }
            if(coordinates[0] == 3){
                destroyers_quantity--;
            }
            if(coordinates[0] == 4){
                submarines_quantity--;
            }
            // Check if all boats have been added
            if(battleship_quantity == 0){
                if(cruisers_quantity == 0){
                    if(destroyers_quantity == 0){
                        if(submarines_quantity == 0){
                            break;
                        }
                    }
                }
            }
        } else { // If have erro
            puzzles_erro_code(code_erro);
        }        
    }

    // Check if it's the same as the original
    if(cheking_answer(puzzles_user, final_board)){
        std::cout << std::endl;
        std::cout << "-----------" << std::endl;
        std::cout << std::endl;
        std::cout <<  "Congratulations!" << std::endl;
        std::cout <<  "You won the game!" << std::endl;
        std::cout <<  "bye" << std::endl;
        std::cout << std::endl;
    } else  {
        std::cout << std::endl;
        std::cout << "-----------" << std::endl;
        std::cout << std::endl;
        std::cout <<  "Sorry!" << std::endl;
        std::cout <<  "You lost the game!" << std::endl;
        std::cout <<  "bye" << std::endl;
        std::cout << std::endl;
    }  

    return EXIT_SUCCESS;
}