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
 * @brief Function to draw the ships
 * 
 * @param puzzle User Puzzle
 * @param size_of_ship Size of the ship
 * @param position_z If is horizontal (code = 1) or vertical (code = 2)
 * @param position_line Cartesian number [0->size] to the line
 * @param position_column Cartesian number [0->size] to the column
 */
void draw_ship_z(std::vector<std::vector<char>> & puzzle, int const size_of_ship, int const position_z, int const position_line, int const position_column){
    if(size_of_ship == 1){
        puzzle[position_line][position_column] = '+';
    } else {
        if(position_z == 1){ // If position H
            puzzle[position_line][position_column] = '<';
            for(int i(1); i<(size_of_ship-1); ++i){
                puzzle[position_line][position_column + i] = '+';
            }
            puzzle[position_line][position_column + size_of_ship - 1] = '>';
        } else { // If position V
            puzzle[position_line][position_column] = '^';
            for(int i(1); i<(size_of_ship-1); ++i){
                puzzle[position_line + i][position_column] = '+';
            }
            puzzle[position_line][position_column + size_of_ship - 1] = 'v';
        }
    }
}
/**
 * @brief Function to check the area aroud the ship
 * 
 * @param puzzle User Puzzle
 * @param size Side of puzzle
 * @param size_of_ship Size of the ship
 * @param position_line Cartesian number [0->size] to the line
 * @param position_column Cartesian number [0->size] to the column
 * @param position_z If is horizontal (code = 1) or vertical (code = 2)
 * @return int Erro code or 0 to OK
 */
int barriers_ship_way(std::vector<std::vector <char>> & puzzle, int const size, int const size_of_ship, int const position_line, int const position_column, int const position_z){
    if(position_z == 1){ // If position H (deitado)
        // Check for barriers in the ship wey  
        if((position_column + size_of_ship)>size){
            return 1; // Erro code 1: The limit gone
        }            
        for(int i(1); i<size_of_ship; ++i){                
            if(puzzle[position_line][position_column + i] != ' '){
                //return 2; // Erro code 2: Have something in the way
            }
        }

        // Check for barriers around the ship            
        if((position_line - 1) < 0){ // if the ship on the top
            // check the mid down ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line + 1][position_column + i] != '0') and (puzzle[position_line + 1][position_column + i] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the tips ship
            if(position_column == 0){ // if the ship on the left side
                // check the right side tip
                if((puzzle[position_line][position_column + size_of_ship] != '0') and (puzzle[position_line][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip down
                if((puzzle[position_line + 1][position_column + size_of_ship] != '0') and (puzzle[position_line + 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water down and right tip down
                for(int i(0); i<(size_of_ship+1); ++i){
                    puzzle[position_line+1][position_column + i] = '0';
                }
                puzzle[position_line][position_column + size_of_ship] = '0';
            }
            if((position_line + size_of_ship) == size){ // if the ship on the right side
                // check the left side tip
                if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip down
                if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water down and right tip down
                for(int i(-1); i<size_of_ship; ++i){
                    puzzle[position_line+1][position_column + i] = '0';
                }
                puzzle[position_line][position_column - 1] = '0';
            }
            if((position_column != 0) and ((position_line + size_of_ship) != size)){
                // check the right side tip
                if((puzzle[position_line][position_column + size_of_ship] != '0') and (puzzle[position_line][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip down
                if((puzzle[position_line + 1][position_column + size_of_ship] != '0') and (puzzle[position_line + 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip
                if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip down
                if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water down and tip down
                for(int i(-1); i<(size_of_ship+1); ++i){
                    puzzle[position_line+1][position_column + i] = '0';
                }
                puzzle[position_line][position_column - 1] = '0';
                puzzle[position_line][position_column + 1] = '0';
            }
        }
        if((position_line + 1) == size){ // if the ship on the dow
            // check the mid top ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line - 1][position_column + i] != '0') and (puzzle[position_line - 1][position_column + i] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the tips ship
            if(position_column == 0){ // if the ship on the left side
                // check the right side tip
                if((puzzle[position_line][position_column + size_of_ship] != '0') and (puzzle[position_line][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip top
                if((puzzle[position_line - 1][position_column + size_of_ship] != '0') and (puzzle[position_line - 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water top and right tip top
                for(int i(0); i<(size_of_ship+1); ++i){
                    puzzle[position_line-1][position_column + i] = '0';
                }
                puzzle[position_line][position_column + size_of_ship] = '0';
            }
            if((position_line + size_of_ship) == size){ // if the ship on the right side
                // check the left side tip
                if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip top
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water top and right tip top
                for(int i(-1); i<size_of_ship; ++i){
                    puzzle[position_line-1][position_column + i] = '0';
                }
                puzzle[position_line][position_column - 1] = '0';
            }
            if((position_column != 0) and ((position_line + size_of_ship) != size)){
                // check the right side tip
                if((puzzle[position_line][position_column + size_of_ship] != '0') and (puzzle[position_line][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip top
                if((puzzle[position_line - 1][position_column + size_of_ship] != '0') and (puzzle[position_line - 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip
                if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip top
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }                    
                // Fill water down and tip down
                for(int i(-1); i<(size_of_ship+1); ++i){
                    puzzle[position_line-1][position_column + i] = '0';
                }
                puzzle[position_line][position_column - 1] = '0';
                puzzle[position_line][position_column + 1] = '0';
            } 
        }
        if(((position_line - 1) >= 0) and ((position_line + 1) < size)){ // if the ship on the mid
            // check the mid top ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line - 1][position_column + i] != '0') and (puzzle[position_line - 1][position_column + i] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the mid down ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line + 1][position_column + i] != '0') and (puzzle[position_line + 1][position_column + i] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the tips ship
            if(position_column == 0){ // if the ship on the left side
                // check the right side tip
                if((puzzle[position_line][position_column + size_of_ship] != '0') and (puzzle[position_line][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip top
                if((puzzle[position_line - 1][position_column + size_of_ship] != '0') and (puzzle[position_line - 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip down
                if((puzzle[position_line + 1][position_column + size_of_ship] != '0') and (puzzle[position_line + 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water top and down, and right tip top and down
                for(int i(0); i<(size_of_ship+1); ++i){
                    puzzle[position_line-1][position_column + i] = '0';
                    puzzle[position_line+1][position_column + i] = '0';
                }
                puzzle[position_line][position_column + size_of_ship] = '0';
            }
            if((position_line + size_of_ship) == size){ // if the ship on the right side
                // check the left side tip
                if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip top
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip down
                if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water top and right tip top
                for(int i(-1); i<size_of_ship; ++i){
                    puzzle[position_line-1][position_column + i] = '0';
                    puzzle[position_line+1][position_column + i] = '0';
                }
                puzzle[position_line][position_column - 1] = '0';
            }
            if((position_column != 0) and ((position_line + size_of_ship) != size)){
                // check the right side tip
                if((puzzle[position_line][position_column + size_of_ship] != '0') and (puzzle[position_line][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip top
                if((puzzle[position_line - 1][position_column + size_of_ship] != '0') and (puzzle[position_line - 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip
                if((puzzle[position_line][position_column - 1] != '0') and (puzzle[position_line][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the left side tip top
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the right side tip down
                if((puzzle[position_line + 1][position_column + size_of_ship] != '0') and (puzzle[position_line + 1][position_column + size_of_ship] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }                    
                // check the left side tip down
                if((puzzle[position_line + 1][position_column - 1] != '0') and (puzzle[position_line + 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water down and tip down
                for(int i(-1); i<(size_of_ship+1); ++i){
                    puzzle[position_line-1][position_column + i] = '0';
                    puzzle[position_line+1][position_column + i] = '0';
                }
                puzzle[position_line][position_column - 1] = '0';
                puzzle[position_line][position_column + 1] = '0';
            }
        }
    }
    if(position_z == 2){ // If position V (em pé)
        if((position_line + size_of_ship)>size){
            return 1; // Erro code 1: The limit gone
        }            
        for(int i(1); i<size_of_ship; ++i){                
            if(puzzle[position_line + i][position_column] != ' '){
                //return 2; // Erro code 2: Have something in the way
            }
        }
        // Check for barriers around the ship  
        if((position_column - 1) < 0){ // if in left side
            // check the mid right ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line + i][position_column + 1] != '0') and (puzzle[position_line + i][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the tips ship
            if(position_line == 0){ // if the ship on the top side
                // check the down side tip
                if((puzzle[position_line + size_of_ship][position_column] != '0') and (puzzle[position_line + size_of_ship][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip right
                if((puzzle[position_line + size_of_ship][position_column + 1] != '0') and (puzzle[position_line + size_of_ship][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(0); i<(size_of_ship+1); ++i){
                    puzzle[position_line + i][position_column + 1] = '0';
                }
                puzzle[position_line + size_of_ship][position_column] = '0';
            }
            if((position_column + size_of_ship) == size){ // if the ship on the down side
                // check the top side tip
                if((puzzle[position_line - 1][position_column] != '0') and (puzzle[position_line - 1][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip right
                if((puzzle[position_line - 1][position_column + 1] != '0') and (puzzle[position_line - 1][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(-1); i<size_of_ship; ++i){
                    puzzle[position_line + i][position_column + 1] = '0';
                }
                puzzle[position_line - 1][position_column] = '0';
            }
            if((position_line != 0) and ((position_column + size_of_ship) != size)){
                // check the down side tip
                if((puzzle[position_line + size_of_ship][position_column] != '0') and (puzzle[position_line + size_of_ship][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip right
                if((puzzle[position_line + size_of_ship][position_column + 1] != '0') and (puzzle[position_line + size_of_ship][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip
                if((puzzle[position_line - 1][position_column] != '0') and (puzzle[position_line - 1][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip right
                if((puzzle[position_line - 1][position_column + 1] != '0') and (puzzle[position_line - 1][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(-1); i<(size_of_ship+1); ++i){
                    puzzle[position_line + i][position_column + 1] = '0';
                }
                puzzle[position_line - 1][position_column] = '0';
                puzzle[position_line + 1][position_column] = '0';
            }
        }
        if((position_column + 1) == size){ // if the ship on the right
            // check the mid left ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line + i][position_column - 1] != '0') and (puzzle[position_line + i][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the tips ship
            if(position_line == 0){ // if the ship on the top side
                // check the down side tip
                if((puzzle[position_line + size_of_ship][position_column] != '0') and (puzzle[position_line + size_of_ship][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip left
                if((puzzle[position_line + size_of_ship][position_column - 1] != '0') and (puzzle[position_line + size_of_ship][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(0); i<(size_of_ship+1); ++i){
                    puzzle[position_line + i][position_column - 1] = '0';
                }
                puzzle[position_line + size_of_ship][position_column] = '0';
            }
            if((position_column + size_of_ship) == size){ // if the ship on the down side
                // check the top side tip
                if((puzzle[position_line - 1][position_column] != '0') and (puzzle[position_line - 1][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip left
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(-1); i<size_of_ship; ++i){
                    puzzle[position_line + i][position_column + 1] = '0';
                }
                puzzle[position_line - 1][position_column] = '0';
            }
            if((position_line != 0) and ((position_column + size_of_ship) != size)){
                // check the top side tip
                if((puzzle[position_line - 1][position_column] != '0') and (puzzle[position_line - 1][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip left
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip
                if((puzzle[position_line + size_of_ship][position_column] != '0') and (puzzle[position_line + size_of_ship][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip left
                if((puzzle[position_line + size_of_ship][position_column - 1] != '0') and (puzzle[position_line + size_of_ship][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(-1); i<(size_of_ship+1); ++i){
                    puzzle[position_line + i][position_column - 1] = '0';
                }
                puzzle[position_line - 1][position_column] = '0';
                puzzle[position_line + 1][position_column] = '0';
            }
        }
        if(((position_line - 1) >= 0) and ((position_line + 1) < size)){ // if the ship on the mid
            // check the mid left ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line + i][position_column - 1] != '0') and (puzzle[position_line + i][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the mid right ship side
            for(int i(0); i<size_of_ship; ++i){
                if((puzzle[position_line + i][position_column + 1] != '0') and (puzzle[position_line + i][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                } 
            }
            // check the tips ship
            if(position_line == 0){ // if the ship on the top side
                // check the down side tip
                if((puzzle[position_line + size_of_ship][position_column] != '0') and (puzzle[position_line + size_of_ship][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip right
                if((puzzle[position_line + size_of_ship][position_column + 1] != '0') and (puzzle[position_line + size_of_ship][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip left
                if((puzzle[position_line + size_of_ship][position_column - 1] != '0') and (puzzle[position_line + size_of_ship][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(0); i<(size_of_ship+1); ++i){
                    puzzle[position_line + i][position_column - 1] = '0';
                    puzzle[position_line + i][position_column + 1] = '0';
                }
                puzzle[position_line + size_of_ship][position_column] = '0';
            }
            if((position_column + size_of_ship) == size){ // if the ship on the down side
                // check the top side tip
                if((puzzle[position_line - 1][position_column] != '0') and (puzzle[position_line - 1][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip left
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip right
                if((puzzle[position_line - 1][position_column + 1] != '0') and (puzzle[position_line - 1][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // Fill water
                for(int i(-1); i<size_of_ship; ++i){
                    puzzle[position_line + i][position_column + 1] = '0';
                    puzzle[position_line + i][position_column - 1] = '0';
                }
                puzzle[position_line - 1][position_column] = '0';
            }
            if((position_line != 0) and ((position_column + size_of_ship) != size)){
                // check the top side tip
                if((puzzle[position_line - 1][position_column] != '0') and (puzzle[position_line - 1][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip left
                if((puzzle[position_line - 1][position_column - 1] != '0') and (puzzle[position_line - 1][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the top side tip right
                if((puzzle[position_line - 1][position_column + 1] != '0') and (puzzle[position_line - 1][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip
                if((puzzle[position_line + size_of_ship][position_column] != '0') and (puzzle[position_line + size_of_ship][position_column] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip right
                if((puzzle[position_line + size_of_ship][position_column + 1] != '0') and (puzzle[position_line + size_of_ship][position_column + 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                // check the down side tip left
                if((puzzle[position_line + size_of_ship][position_column - 1] != '0') and (puzzle[position_line + size_of_ship][position_column - 1] != ' ')){
                    return 2; // Erro code 2: Have something in the way
                }
                    // Fill water
                for(int i(-1); i<(size_of_ship+1); ++i){
                    puzzle[position_line + i][position_column] = '0';
                    puzzle[position_line + i][position_column] = '0';
                }
                puzzle[position_line - 1][position_column] = '0';
                puzzle[position_line + 1][position_column] = '0';
            }
        }    
    }
    return 0; //  Everything is ok
}

/**
 * @brief Function to put a new ship in the terminal
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
    // Check your place is clean
    if(puzzle[position_line][position_column] != (' ')){
        //return 2; // Erro code 2: Have something in the way
    }

    // Check the position_z
    if((position_z != 1) and (position_z != 2)){
        return 3; // Erro in the horizontal (code = 1) or vertical (code = 2)
    }

    // Check the code ship
    if((ship != 1) and (ship != 2) and (ship != 3) and (ship != 4)){
        return 4; // Erro code 4: Ship code not found
    }

    // Check the area around the ship and code defalt
    int size_of_ship(0);  /* < Size of the ship */
    int erro_code(0); /* < Erro code defalt */

    // To the Battleship (four squares long) -> $code 1
    if(ship == 1){
        size_of_ship = 4; // The Battleship (four squares long)            
        erro_code = barriers_ship_way(puzzle, size, size_of_ship, position_line, position_column, position_z);
        if(erro_code > 0){
            return erro_code;
        }
        draw_ship_z(puzzle, size_of_ship,position_z, position_line, position_column);
        return 0; //  Everything is ok
    }
    // To the Cruisers (three squares long) -> $code 2
    if(ship == 2){
        size_of_ship = 3; // The Cruisers (three squares long)          
        erro_code = barriers_ship_way(puzzle, size, size_of_ship, position_line, position_column, position_z);
        if(erro_code > 0){
            return erro_code;
        }
        draw_ship_z(puzzle, size_of_ship,position_z, position_line, position_column);
        return 0; //  Everything is ok
    }
    // To the Destroyers (two squares long) -> $code 3
    if(ship == 3){
        size_of_ship = 2; // The Destroyers (two squares long)          
        erro_code = barriers_ship_way(puzzle, size, size_of_ship, position_line, position_column, position_z);
        if(erro_code > 0){
            return erro_code;
        }
        draw_ship_z(puzzle, size_of_ship,position_z, position_line, position_column);
        return 0; //  Everything is ok
    }
    // To the Submarines (one square in size) -> $code 4
    if(ship == 4){
        size_of_ship = 1; // The Submarines (one square in size)         
        erro_code = barriers_ship_way(puzzle, size, size_of_ship, position_line, position_column, position_z);
        if(erro_code > 0){
            return erro_code;
        }
        draw_ship_z(puzzle, size_of_ship,position_z, position_line, position_column);
        return 0; //  Everything is ok
    }
    return 0; //  Everything is ok
}