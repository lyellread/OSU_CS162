/*********************************************************************
** Program Filename:maze_level.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: MazeLevel
** Input:na
** Output:na
*********************************************************************/


#include "maze_level.hpp"

/*********************************************************************
** Function:MazeLevel
** Description:constructor - allocates vector and sets everything up
** Parameters:int rows, int cols, ifstream &is
** Pre-Conditions:none
** Post-Conditions:new mazelevel created
*********************************************************************/ 

MazeLevel::MazeLevel(int rows, int cols, ifstream &is){
		
	this->rows = rows;
	this->cols = cols;

	//set up vector to store that data
	this->maze.resize(rows);
	vector<MazeLocation*> v;
	v.resize(cols);
	for (int i  = 0; i < rows; ++i){
		this->maze[i] = v;
	}
		
	//read the map in from file
	char current_character;
	
	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col){
			
			current_character = is.get();
			
			if (current_character == '#'){
				this->maze[row][col] = new Wall();
			}
			else if (current_character == '^'){
				this->maze[row][col] = new OpenSpace();
				this->maze[row][col]->set_is_ladder(1);
			}
			else if (current_character == '%'){
				this->maze[row][col] = new OpenSpace();
				this->maze[row][col]->set_is_end(1);
			}
			else if (current_character == '@'){
				this->maze[row][col] = new OpenSpace();
				this->maze[row][col]->set_is_start(1);
			}
			else{
				this->maze[row][col] = new OpenSpace();
			}
		}
		is.get(); // remove newline
	}
	
	//set up TA's (x2)
	MazeLocation* temp_loc = NULL;
	
	for (int j = 0; j < 2; ++j){
		temp_loc = get_empty_space();
		temp_loc->set_has_ta(1);
		//temp_loc->room_occupant = new TA;
	}
	
	set_skills();
}

/*********************************************************************
** Function:~MazeLevel
** Description:deallocates and destructs
** Parameters:
** Pre-Conditions:
** Post-Conditions:done. - deleted
*********************************************************************/ 

MazeLevel::~MazeLevel(){
	
	for (int row = 0; row< this->maze.size(); ++row){
		for (int col =0; col< this->maze[row].size(); ++col){
			
			// if (!this->maze[row][col]->room_occupant == NULL){
				// delete this->maze[row][col]->room_occupant;
			// }
			
			delete this->maze[row][col];
			
		}
	}
}

/*********************************************************************
** Function:set_skills
** Description:sets three skills throughout the maze
** Parameters:
** Pre-Conditions:
** Post-Conditions:3 new skills are placed
*********************************************************************/ 

void MazeLevel::set_skills(){
	
	MazeLocation* temp_loc = NULL;
	
	for (int j = 0; j < 3; ++j){
		temp_loc = get_empty_space();
		temp_loc->set_has_skill(1);
	}
	
}

/*********************************************************************
** Function:get_location
** Description:returns the location at row, col
** Parameters:int row, int col
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

MazeLocation* MazeLevel::get_location(int row, int col){
	
	return this->maze[row][col];
	
}

/*********************************************************************
** Function:get_empty_space
** Description:finds an empty spot
** Parameters:
** Pre-Conditions:
** Post-Conditions:found, returned
*********************************************************************/ 

MazeLocation* MazeLevel::get_empty_space(){
	
	int row = rand() % this->rows; // rows 
	int col = rand() % this->cols; // cols
		
	while (!maze[row][col]->get_is_occupiable() || 
			maze[row][col]->has_instructor() ||
			maze[row][col]->has_ta() ||
			maze[row][col]->is_ladder() ||
			maze[row][col]->is_end() ||
			maze[row][col]->is_start()){
				
				row = rand() % this->rows; // rows 
				col = rand() % this->cols; // cols
			}
			
	
	return maze[row][col];
	
}

/*********************************************************************
** Function:display_maze
** Description:prints this level of the maze
** Parameters:
** Pre-Conditions:
** Post-Conditions:printed
*********************************************************************/ 

void MazeLevel::display_maze(){
	
	// cout << "\nMazeLevel:" << endl;
	// cout << "Size: " << maze.size() << " | " << maze[0].size() << endl;
	for (int row = 0; row<this->rows; ++row){
		for (int col =0; col< this->cols; ++col){
			
			//cout << " =dbg=>print row | col: " << row << " | " << col << endl;		
	
			cout << this->maze[row][col]->get_display_character();
			cout << " ";
		}
		cout << endl;
	}	
}

		
		