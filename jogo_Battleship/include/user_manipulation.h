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
 * @return int Erro code or 0 to OK
 */
int put_new_boat(std::vector<std::vector <char>> & puzzle, int const size, int const ship, int const position_line, int const position_column, int const position_z){
    if(puzzle[position_line][position_column] == (' ')){
        // ADICIONARA REGRA AQUI|!
    }
    // Check the position_z
    if((position_z == 1) or (position_z == 2)){
        int size_of_ship(0);    
        // To the Battleship (four squares long) -> $code 1
        if(ship == 1){
            size_of_ship = 4; // The Battleship (four squares long)
            if(puzzle[position_line][position_column] == (' ')){
                if(position_z == 1){ // If position H
                    // Check for barriers               
                    for(int i(0); i<size_of_ship; ++i){
                        if((position_line + i)>=size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line + i][position_column] != ' '){
                            return 2; // Erro code 2: Have something in the way
                        }
                    }
                    // Check for barriers around
                    for(int i(0); i<size_of_ship; ++i){ // To check the middle of the ship
                        if((position_line - 1)<0){ 
                            if((puzzle[position_line+1][position_column + i] != '0') and (puzzle[position_line+1][position_column + i] != ' ')){
                                return 2; // Erro code 2: Have something in the way
                            } 
                        }
                        if((position_line + 1)>=size){
                            if((puzzle[position_line-1][position_column + i] != '0') and (puzzle[position_line-1][position_column + i] != ' ')){
                                return 2; // Erro code 2: Have something in the way
                            } 
                        }
                    }
                    if(((position_line - 1) < 0) and ((position_column - 1) < 0)){ // To check the middle of the upper left tip
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line + 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship); ++i){ // Fill in low row
                            puzzle[position_line + 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left                        
                    }
                    if(((position_line - 1) < 0) and ((position_column + size_of_ship + 1) >= size)){ // To check the middle of the upper right tip
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        } 
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship); ++i){ // Fill in low row
                            puzzle[position_line + 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left                       
                    }
                    if(((position_line - 1) < 0) and ((position_column + size_of_ship + 1) < (size - 1)) and ((position_column - 1) > 0)){ // To check the middle of the upper
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line + 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship + 1); ++i){ // Fill in low row
                            puzzle[position_line + 1][position_column + i] = '0';
                        }  
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left
                        puzzle[position_line][position_column + size_of_ship + 1] = '0'; // Fill the line right
                    }
                    if(((position_line + 1) >= size) and ((position_column - 1) < 0)){ // To check the middle of the low left tip
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line - 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(0); i<(size_of_ship + 1); ++i){ // Fill in top row
                            puzzle[position_line - 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column + size_of_ship + 1] = '0'; // Fill the line right                        
                    }
                    if(((position_line + 1) >= size) and ((position_column + size_of_ship + 1) >= size)){ // To check the middle of the low right tip
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship); ++i){ // Fill in top row
                            puzzle[position_line - 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left
                    }
                    if(((position_line + 1) >= size) and ((position_column + size_of_ship + 1) <= (size - 1)) and ((position_column - 1) > 0)){ // To check the middle of the low
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line - 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        } 
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship + 1); ++i){ // Fill in top row
                            puzzle[position_line - 1][position_column + i] = '0';
                        }  
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left
                        puzzle[position_line][position_column + size_of_ship + 1] = '0'; // Fill the line right
                    }                
                    
                    // If everything is ok
                    puzzle[position_line][position_column] = '^';
                    puzzle[position_line + 1][position_column] = '+';
                    puzzle[position_line + 2][position_column] = '+';
                    puzzle[position_line + 3][position_column] = 'v';
                } 
                if(position_z == 2){ // If position V
                    for(int i(0); i<size_of_ship; ++i){
                        if((position_column + i)>=size){
                            return 1; // Erro code 1: The limit gone
                        }
                        if(puzzle[position_line][position_column + i] != ' '){
                            return 2; // Erro code 2: Have somethin in the way
                        }
                    }
                    // Check for barriers around
                    for(int i(0); i<size_of_ship; ++i){ // To check the middle of the ship
                        if((position_line - 1)<0){ 
                            if((puzzle[position_line+1][position_column + i] != '0') and (puzzle[position_line+1][position_column + i] != ' ')){
                                return 2; // Erro code 2: Have something in the way
                            } 
                        }
                        if((position_line + 1)>=size){
                            if((puzzle[position_line-1][position_column + i] != '0') and (puzzle[position_line-1][position_column + i] != ' ')){
                                return 2; // Erro code 2: Have something in the way
                            } 
                        }
                    }
                    if(((position_line - 1) < 0) and ((position_column - 1) < 0)){ // To check the middle of the upper left tip
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line + 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship); ++i){ // Fill in low row
                            puzzle[position_line + 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left                        
                    }
                    if(((position_line - 1) < 0) and ((position_column + size_of_ship + 1) >= size)){ // To check the middle of the upper right tip
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        } 
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship); ++i){ // Fill in low row
                            puzzle[position_line + 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left                       
                    }
                    if(((position_line - 1) < 0) and ((position_column + size_of_ship + 1) < (size - 1)) and ((position_column - 1) > 0)){ // To check the middle of the upper
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line + 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line + 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship + 1); ++i){ // Fill in low row
                            puzzle[position_line + 1][position_column + i] = '0';
                        }  
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left
                        puzzle[position_line][position_column + size_of_ship + 1] = '0'; // Fill the line right
                    }
                    if(((position_line + 1) >= size) and ((position_column - 1) < 0)){ // To check the middle of the low left tip
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line - 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(0); i<(size_of_ship + 1); ++i){ // Fill in top row
                            puzzle[position_line - 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column + size_of_ship + 1] = '0'; // Fill the line right                        
                    }
                    if(((position_line + 1) >= size) and ((position_column + size_of_ship + 1) >= size)){ // To check the middle of the low right tip
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship); ++i){ // Fill in top row
                            puzzle[position_line - 1][position_column + i] = '0';
                        }
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left
                    }
                    if(((position_line + 1) >= size) and ((position_column + size_of_ship + 1) <= (size - 1)) and ((position_column - 1) > 0)){ // To check the middle of the low
                        if((puzzle[position_line][position_column + size_of_ship + 1] != '0') and (puzzle[position_line][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column + size_of_ship + 1] != '0') and (puzzle[position_line - 1][position_column + size_of_ship + 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        } 
                        if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                            return 2; // Erro code 2: Have something in the way
                        }
                        // If everything is ok
                        for(int i(-1); i<(size_of_ship + 1); ++i){ // Fill in top row
                            puzzle[position_line - 1][position_column + i] = '0';
                        }  
                        puzzle[position_line][position_column - 1] = '0'; // Fill the line left
                        puzzle[position_line][position_column + size_of_ship + 1] = '0'; // Fill the line right
                    }                
                    
                    // If everything is ok
                    puzzle[position_line][position_column] = '^';
                    puzzle[position_line + 1][position_column] = '+';
                    puzzle[position_line + 2][position_column] = '+';
                    puzzle[position_line + 3][position_column] = 'v';
                }
                    // If everything is ok
                    //puzzle[position_line][position_column] = '<';
                    //puzzle[position_line][position_column + 1] = '+';
                    //puzzle[position_line][position_column + 2] = '+';
                    //puzzle[position_line][position_column + 3] = '>';
                
            } else {
                return 2; // Erro code 2: Have something in the way
            }
        } else {
            // To the Cruisers (three squares long) -> $code 2
            if(ship == 2){
                if(puzzle[position_line][position_column] == (' ')){
                    if(position_z == 1){ // If position H
                        // Check for barriers               
                        for(int i(0); i<3; ++i){
                            if((position_line + i)>=size){
                                return 1; // Erro code 1: The limit gone
                            }
                            if(puzzle[position_line + i][position_column] != ' '){
                                return 2; // Erro code 2: Have something in the way
                            }
                        }                
                        // If everything is ok
                        puzzle[position_line][position_column] = '^';
                        puzzle[position_line + 1][position_column] = '+';
                        puzzle[position_line + 2][position_column] = 'v';
                    }
                    if(position_z == 2){ // If position V
                        for(int i(0); i<3; ++i){
                            if((position_column + i)>=size){
                                return 1; // Erro code 1: The limit gone
                            }
                            if(puzzle[position_line][position_column + i] != ' '){
                                return 2; // Erro code 2: Have somethin in the way
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
            } else {
                // To the Destroyers (two squares long) -> $code 3
                if(ship == 3){
                    if(puzzle[position_line][position_column] == (' ')){
                        if(position_z == 1){ // If position H
                            // Check for barriers               
                            for(int i(0); i<2; ++i){
                                if((position_line + i)>=size){
                                    return 1; // Erro code 1: The limit gone
                                }
                                if(puzzle[position_line + i][position_column] != ' '){
                                    return 2; // Erro code 2: Have something in the way
                                }
                            }                
                            // If everything is ok
                            puzzle[position_line][position_column] = '^';
                            puzzle[position_line + 1][position_column] = 'v';
                        }
                        if(position_z == 2){ // If position V
                            for(int i(0); i<2; ++i){
                                if((position_column + i)>=size){
                                    return 1; // Erro code 1: The limit gone
                                }
                                if(puzzle[position_line][position_column + i] != ' '){
                                    return 2; // Erro code 2: Have somethin in the way
                                }
                            }
                            // If everything is ok
                            puzzle[position_line][position_column] = '<';
                            puzzle[position_line][position_column + 1] = '>';
                        }
                    } else {
                        return 2; // Erro code 2: Have something in the way
                    }
                } else {
                    // Submarines (one square in size) -> $code 4
                    if(ship == 4){
                        if(puzzle[position_line][position_column] == (' ')){
                            if(position_z == 1){ // If position H
                                // Check for barriers               
                                for(int i(0); i<1; ++i){
                                    if((position_line + i)>=size){
                                        return 1; // Erro code 1: The limit gone
                                    }
                                    if(puzzle[position_line + i][position_column] != ' '){
                                        return 2; // Erro code 2: Have something in the way
                                    }
                                }                
                                // If everything is ok
                                puzzle[position_line][position_column] = '+';
                            }
                            if(position_z == 2){ // If position V
                                for(int i(0); i<1; ++i){
                                    if((position_column + i)>=size){
                                        return 1; // Erro code 1: The limit gone
                                    }
                                    if(puzzle[position_line][position_column + i] != ' '){
                                        return 2; // Erro code 2: Have somethin in the way
                                    }
                                }
                                // If everything is ok
                                puzzle[position_line][position_column] = '+';
                            }
                        } else {
                            return 2; // Erro code 2: Have something in the way
                        }
                    } else {
                        return 4; // Erro code 4: Ship code not found
                    }
                }
            }
        }
    } else {
        return 3; // Erro in the horizontal (code = 1) or vertical (code = 2)
    }
    return 0; //  Everything is ok
}