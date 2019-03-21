//application.cpp

#include <iostream>

using std::cout;
using std::endl;

#include "maze.hpp"
//#include "maze_location.hpp"
#include "maze_data.hpp"
#include "player.hpp"



int main(){
	
	cout << " == Application Started!" << endl;
	
	Maze thismaze(MAZE_DATA, 16, 16);
	thismaze.display_maze();

	Player explorer;
	
	char direction;
	int target_row, target_col, row, col, done;
	
	explorer.set_location(1,1);
	
	
	
	while (done != 1){
		
		direction = explorer.get_move();
		target_row = explorer.get_row();
		target_col = explorer.get_col();
		
		row = target_row;
		col = target_col;
		
		
		
		switch (direction){
			
			case 'W':
				target_row--;
				//cout << "W - UP" << endl;
				break;
			
			case 'A':
				target_col--;
				//cout << "A - LEFT" << endl;
				break;
			
			case 'S':
				target_row++;
				//cout << "S - DOWN" << endl;
				break;
				
			case 'D':
				target_col++;
				//cout << "D - RIGHT" << endl;
				break;
		}
		
		
		MazeLocation * target_location = thismaze.get_location(target_row, target_col);
		
		//print a plus for every time this loop runs, to prove it is doing something
		//cout << "+";
		
		if (target_location->get_is_occupiable()){
			
			//set the target square
			explorer.set_location (target_row, target_col);
			target_location->set_has_explorer(1);
			
			//now that we have set the target, unset the old square
			target_location = thismaze.get_location(row, col);
			target_location->set_has_explorer(0);
		}
		
		target_location = thismaze.get_location(target_row, target_col);
		
		if (target_location->is_end()){
			done == 1; 
			cout << "END FOUND" << endl;
			thismaze.display_maze();
			break;
		}
		

	}
	
	cout << " == Application Finished! " << endl;
	
}
