/**
 * @brief It contains all the manipulation functions of the Puzzle during the game
 * 
 * @file user_manipulation.h
 * @author ./allandemiranda ./JO5U3
 * @date 2018-09-14
 */

// Containers library
#include <vector> // std::vector container 

/**
 * @brief 
 * 
 * @param puzzle User Puzzle
 * @param size Side of puzzle
 * @param ship Code of ship
 * @param position_line Cartesian number [0->size] to the line
 * @param position_column Cartesian number [0->size] to the column
 * @param position_z If is horizontal (code = 1) or vertical (code = 2)
 * @return int Erro code
 */
int put_new_boat(std::vector<std::vector <char>> & puzzle, int const size, int const ship, int const position_line, int const position_column, int const position_z){
    // Check the position_z
    if((position_z == 1) or (position_z == 2)){    
        // To the Battleship (four squares long) -> $code 1
        if(ship == 1){
            if(puzzle[position_line][position_column] == (' ')){
                if(position_z == 1){ // If position H
                    // Check for barriers               
                    for(int i(0); i<4; ++i){
                        if((position_line + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line + i][position_column] != ' '){
                            return 1; // Erro code 2: Have something in the way
                        }
                    }                
                    // If everything is ok
                    puzzle[position_line][position_column] = '^';
                    puzzle[position_line + 1][position_column] = '+';
                    puzzle[position_line + 2][position_column] = '+';
                    puzzle[position_line + 3][position_column] = 'v';
                } 
                if(position_z == 2){ // If position V
                    for(int i(0); i<4; ++i){
                        if((position_column + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line][position_column + i] != ' '){
                            return 1; // Erro code 2: Have somethin in the way
                        }
                    }
                    // If everything is ok
                    puzzle[position_line][position_column] = '<';
                    puzzle[position_line][position_column + 1] = '+';
                    puzzle[position_line][position_column + 2] = '+';
                    puzzle[position_line][position_column + 3] = '>';
                }
            } else {
                return 2; // Erro code 2: Have something in the way
            }
        }
        // To the Cruisers (three squares long) -> $code 2
        if(ship == 2){
            if(puzzle[position_line][position_column] == (' ')){
                if(position_z == 1){ // If position H
                    // Check for barriers               
                    for(int i(0); i<3; ++i){
                        if((position_line + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line + i][position_column] != ' '){
                            return 1; // Erro code 2: Have something in the way
                        }
                    }                
                    // If everything is ok
                    puzzle[position_line][position_column] = '^';
                    puzzle[position_line + 1][position_column] = '+';
                    puzzle[position_line + 2][position_column] = 'v';
                }
                if(position_z == 2){ // If position V
                    for(int i(0); i<3; ++i){
                        if((position_column + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line][position_column + i] != ' '){
                            return 1; // Erro code 2: Have somethin in the way
                        }
                    }
                    // If everything is ok
                    puzzle[position_line][position_column] = '<';
                    puzzle[position_line][position_column + 1] = '+';
                    puzzle[position_line][position_column + 2] = '>';
                }
            } else {
                return 2; // Erro code 2: Have something in the way
            }
        }
        // To the Destroyers (two squares long) -> $code 3
        if(ship == 3){
            if(puzzle[position_line][position_column] == (' ')){
                if(position_z == 1){ // If position H
                    // Check for barriers               
                    for(int i(0); i<2; ++i){
                        if((position_line + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line + i][position_column] != ' '){
                            return 1; // Erro code 2: Have something in the way
                        }
                    }                
                    // If everything is ok
                    puzzle[position_line][position_column] = '^';
                    puzzle[position_line + 1][position_column] = 'v';
                }
                if(position_z == 2){ // If position V
                    for(int i(0); i<2; ++i){
                        if((position_column + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line][position_column + i] != ' '){
                            return 1; // Erro code 2: Have somethin in the way
                        }
                    }
                    // If everything is ok
                    puzzle[position_line][position_column] = '<';
                    puzzle[position_line][position_column + 1] = '>';
                }
            } else {
                return 2; // Erro code 2: Have something in the way
            }
        }
        // Submarines (one square in size) -> $code 4
        if(ship == 4){
            if(puzzle[position_line][position_column] == (' ')){
                if(position_z == 1){ // If position H
                    // Check for barriers               
                    for(int i(0); i<1; ++i){
                        if((position_line + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line + i][position_column] != ' '){
                            return 1; // Erro code 2: Have something in the way
                        }
                    }                
                    // If everything is ok
                    puzzle[position_line][position_column] = '+';
                }
                if(position_z == 2){ // If position V
                    for(int i(0); i<1; ++i){
                        if((position_column + i)>size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line][position_column + i] != ' '){
                            return 1; // Erro code 2: Have somethin in the way
                        }
                    }
                    // If everything is ok
                    puzzle[position_line][position_column] = '+';
                }
            } else {
                return 2; // Erro code 2: Have something in the way
            }
        }
    } else {
        return 3; // Erro in the horizontal (code = 1) or vertical (code = 2)
    }
    return 0; //  Everything is ok
}