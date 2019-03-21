/*********************************************************************
** Program Filename:maze.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: Maze
** Input:na
** Output:na
*********************************************************************/

#include "maze.hpp"

/*********************************************************************
** Function:Maze
** Description:constructor
** Parameters:char * filename
** Pre-Conditions:file provided
** Post-Conditions:reads from file, allocates map
*********************************************************************/ 

Maze::Maze(char * filename){
	
	this->filename = filename;
	
	ifstream is(filename);
	
	is >> this->levels;
	is >> this->rows;
	is >> this->cols;
	
	is.get(); // get that last space
	
	
	for (int i = 0; i < this->levels; ++i){
		
		this->maze_vector.push_back(new MazeLevel(this->rows, this->cols, is));
		
	}
		
	MazeLevel * current_level = this->maze_vector[0];
	
	//set the player's location
	for (int row = 0; row< this->rows; ++row){
		for (int col =0; col< this->cols; ++col){
			
			MazeLocation * current_location = current_level->get_location(row, col);
			if (current_location->is_start()){
				this->p1.set_location(0, row, col);
				current_location->set_has_explorer(1);
				break; 
			
			}
			
		}
	}
	
	
	//set the instructor location
	current_level = this->maze_vector[this->levels-1];
	MazeLocation * instructor_target_location = current_level->get_empty_space();
	instructor_target_location->set_has_instructor(1);
	
	
}

/*********************************************************************
** Function:~Maze
** Description:deletes allocated mem
** Parameters:
** Pre-Conditions:
** Post-Conditions:destructed
*********************************************************************/ 

Maze::~Maze(){
	
	for (int i = 0; i < this->levels; ++i){
		
		delete this->maze_vector[i];
		
	}
}

/*********************************************************************
** Function:dbg_print_all
** Description:prints the grid
** Parameters:
** Pre-Conditions:
** Post-Conditions:grid printed
*********************************************************************/ 

void Maze::dbg_print_all(){
	
	// for (int i = 0; i < this->levels; ++i){
		
		// this->maze_vector[i]->display_maze();
		
	// }
	
	cout << "Player's Programming Skills: " << this->p1.get_skills() << endl;
	this->maze_vector[this->p1.get_level()]->display_maze();
	cout << endl;
	
}

/*********************************************************************
** Function:play_game
** Description:plays game
** Parameters:
** Pre-Conditions:game start called
** Post-Conditions:game done
*********************************************************************/ 

void Maze::play_game(){

	int win_state = 0;
	
	//clear screen:
	
	clear_screen();
	
	//print grid:
	
	dbg_print_all();
	
	
	while (win_state == 0){
		win_state = play_turn();
		//cout << "Current Win State: " << win_state << endl;
	}
	
	return;
}

/*********************************************************************
** Function:clear_screen
** Description:clears screen
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Maze::clear_screen(){
	
	for (int i = 0; i<100; ++i){
		cout << "\n";
		
	}
}

/*********************************************************************
** Function:play_turn
** Description:plays turn
** Parameters:
** Pre-Conditions:
** Post-Conditions:turn played
*********************************************************************/ 

int Maze::play_turn () {
	
	//move player:
	
	move_player();
	
	//check for win
	
	int win = 0;
	win = check_for_win();
	if (win){return 1;}
		
	//move TA's
	
	move_tas();
	
	//check if the player is next to a ta, if so do action
	
	check_ta_satisfaction();
	
	//check if the player is next to a instructor, if so do action
	
	check_instructor_satisfaction();
	
	//decrement ta appeasal
	
	this->ta1.decrement_appeasal();
	
	//check for skills
	
	check_collect_skills();		
	
	//clear screen:
	
	dbg_print_all();
		
	return 0;
	
}

/*********************************************************************
** Function:check_for_win
** Description:checks for win case
** Parameters:
** Pre-Conditions:
** Post-Conditions:returns win
*********************************************************************/ 

int Maze::check_for_win(){
	
	MazeLocation * current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col());
	if (this->i1.get_satisfied() && current_location->is_end()){
		cout << "You Win! " << endl;
		return 1;
	}
	
	return 0;
}

/*********************************************************************
** Function:check_ta_satisfaction
** Description:checks surrounding cells and makes sure tas are satisfied
** Parameters:
** Pre-Conditions:
** Post-Conditions:done
*********************************************************************/ 

void Maze::check_ta_satisfaction(){
	
	MazeLocation * current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col());
	if (current_location->has_ta() && !(this->ta1.get_is_appeased())){return_to_start(); this->p1.reset_skills(); return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row()+1, this->p1.get_col());
	if (current_location->has_ta() && !(this->ta1.get_is_appeased())){return_to_start(); this->p1.reset_skills(); return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row()-1, this->p1.get_col());
	if (current_location->has_ta() && !(this->ta1.get_is_appeased())){return_to_start(); this->p1.reset_skills(); return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col()+1);
	if (current_location->has_ta() && !(this->ta1.get_is_appeased())){return_to_start(); this->p1.reset_skills(); return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col()-1);
	if (current_location->has_ta() && !(this->ta1.get_is_appeased())){return_to_start(); this->p1.reset_skills(); return;}

}

/*********************************************************************
** Function:check_instructor_satisfaction
** Description:checks surrounding cells and does action 
** Parameters:
** Pre-Conditions:
** Post-Conditions:action called
*********************************************************************/ 

void Maze::check_instructor_satisfaction(){
	
	MazeLocation * current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row()+1, this->p1.get_col());
	if (current_location->has_instructor() && this->p1.get_skills() >= 3){this->i1.set_satisfied(1); return;}
	else if (current_location->has_instructor() && this->p1.get_skills() < 3){return_to_level_0_start();return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row()-1, this->p1.get_col());
	if (current_location->has_instructor() && this->p1.get_skills() >= 3){this->i1.set_satisfied(1); return;}
	else if (current_location->has_instructor() && this->p1.get_skills() < 3){return_to_level_0_start();return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col()+1);
	if (current_location->has_instructor() && this->p1.get_skills() >= 3){this->i1.set_satisfied(1); return;}
	else if (current_location->has_instructor() && this->p1.get_skills() < 3){return_to_level_0_start();return;}

	current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col()-1);
	if (current_location->has_instructor() && this->p1.get_skills() >= 3){this->i1.set_satisfied(1); return;}
	else if (current_location->has_instructor() && this->p1.get_skills() < 3){return_to_level_0_start();return;}

	
}

/*********************************************************************
** Function:return_to_start
** Description:returns to current level start
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned to start
*********************************************************************/ 

void Maze::return_to_start(){
	
	for (int row = 0; row < this->rows; ++row){
		for (int col = 0; col < this->cols; ++col){
			
			MazeLocation * current_location = this->maze_vector[this->p1.get_level()]->get_location(row, col);
			if (current_location->is_start()){
				
				current_location->set_has_explorer(1);
				current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col());
				current_location->set_has_explorer(0);
				this->p1.set_location(this->p1.get_level(), row, col);
			}
		}
	}
}

/*********************************************************************
** Function:return_to_level_0_start
** Description:resets game
** Parameters:
** Pre-Conditions:
** Post-Conditions:game reset
*********************************************************************/ 

void Maze::return_to_level_0_start(){
	
	for (int i = 0; i < this->levels; ++i){
		
		this->maze_vector[i]->set_skills();
		
	}
	
	for (int row = 0; row< this->rows; ++row){
		for (int col =0; col< this->cols; ++col){
			
			MazeLocation * current_location = this->maze_vector[0]->get_location(row, col);
			if (current_location->is_start()){
				
				current_location->set_has_explorer(1);
				current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col());
				current_location->set_has_explorer(0);
				this->p1.set_location(0, row, col);
			}
		}
	}
	
	cout << "The Instructor was not satisfied. You have been restarted!" << endl;
}

/*********************************************************************
** Function:check_collect_skills
** Description:checks for and collects skill to player
** Parameters:
** Pre-Conditions:
** Post-Conditions:if skill present collected
*********************************************************************/ 

void Maze::check_collect_skills(){
	
	MazeLocation * current_location = this->maze_vector[this->p1.get_level()]->get_location(p1.get_row(), p1.get_col());
	if(current_location->has_skill()){
		current_location->set_has_skill(0);
		this->p1.add_skill();
	}
}

/*********************************************************************
** Function:move_tas
** Description:moves ta's
** Parameters:
** Pre-Conditions:
** Post-Conditions:ta's moved
*********************************************************************/ 
	
void Maze::move_tas(){
	
	MazeLevel * current_level = this->maze_vector[this->p1.get_level()];
	
	MazeLocation * moveto_location = NULL;
	MazeLocation * current_location = NULL;
	int current_row, current_col, moveto_row, moveto_col;
	
	for (int row = 0; row< this->rows; ++row){
		for (int col =0; col< this->cols; ++col){
			
			current_location = current_level->get_location(row, col);
			
			if (current_location->has_ta()){
				
				//cout << "EVAL TA @ " << row << " | " << col << endl;
				
				do{
					
					current_row = row;
					current_col = col;
					current_location = current_level->get_location(row, col);
					
					moveto_row = row;
					moveto_col = col;
					
					//we have a place with a ta in it at current_location
					
					char move = this->ta1.get_move();
					
					switch (move){
						
						case 'w': //up
						
							moveto_row = current_row - 1;
							break;
							
						case 'a': //left
						
							moveto_col = current_col - 1;
							break;
							
						case 's': //down
							
							moveto_row = current_row + 1;
							break;
							
						case 'd': //right
						
							moveto_col = current_col + 1;
							break;
					}
					
					moveto_location = current_level->get_location(moveto_row, moveto_col);
					
				} while (!moveto_location->get_is_occupiable() || moveto_location->has_ta());
			
				//cout << "[ta] Access to: LV: " << this->p1.get_level() << ", ROW | COL: " << moveto_row << " | " << moveto_col << endl;
				
				current_location->set_has_ta(0);
				moveto_location->set_has_ta(1);
				
			}
		}
	}
}

/*********************************************************************
** Function:move_player
** Description:handles moving the player
** Parameters:
** Pre-Conditions:
** Post-Conditions:player move handled
*********************************************************************/ 

void Maze::move_player() {
	
	MazeLocation * moveto_location = NULL;
	MazeLocation * current_location = NULL;
	int current_row, current_col, moveto_row, moveto_col;

	do{
		char move;
		move = char(this->p1.get_move());
	
		
		current_row = this->p1.get_row();
		current_col = this->p1.get_col();
		current_location = this->maze_vector[this->p1.get_level()]->get_location(current_row, current_col);
		
		moveto_row = current_row;
		moveto_col = current_col;
		
		//cout << "MOVE: " << move << endl;
		
		switch (move){
			
			case 'w': //up
			
				moveto_row = current_row - 1;
				break;
				
			case 'a': //left
			
				moveto_col = current_col - 1;
				break;
				
			case 's': //down
				
				moveto_row = current_row + 1;
				break;
				
			case 'd': //right
			
				moveto_col = current_col + 1;
				break;
				
			default:
			
				//cout << "SPECIAL ACTION" << endl;
				clear_screen();
				special_player_move(move);
				return;
			
		}
		
		//cout << "Access to: LV: " << this->p1.get_level() << ", ROW | COL: " << moveto_row << " | " << moveto_col << endl;
		moveto_location = this->maze_vector[this->p1.get_level()]->get_location(moveto_row, moveto_col);
		
	} while (!moveto_location->get_is_occupiable());
	
	this->p1.set_location(this->p1.get_level(), moveto_row, moveto_col);
	
	//swap dose valuse
	
	current_location->set_has_explorer(0);
	moveto_location->set_has_explorer(1);
	
	clear_screen();

	
}

/*********************************************************************
** Function:find_next_start_place
** Description:finds next start place at level
** Parameters:int level, int &new_row, int &new_col
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

MazeLocation * Maze::find_next_start_place(int level, int &new_row, int &new_col){
	
	MazeLevel * mazeleveltemp = maze_vector[level];
	
	for (int row = 0; row< this->rows; ++row){
		for (int col =0; col< this->cols; ++col){
			
			MazeLocation * return_location = mazeleveltemp->get_location(row, col);
			
			if (return_location->is_start()){
				new_row = row;
				new_col = col;
				return return_location;
			}
		}
	}
}

/*********************************************************************
** Function:special_player_move
** Description:handles u or p
** Parameters: char move
** Pre-Conditions:
** Post-Conditions:handled
*********************************************************************/ 

void Maze::special_player_move(char move){
	
	if (move == 'u'){
		
		MazeLocation * current_location = this->maze_vector[this->p1.get_level()]->get_location(this->p1.get_row(), this->p1.get_col());
		int old_level = this->p1.get_level();
		
		if (current_location->is_ladder()){
			cout << "Ladder Entered" << endl;
			
			current_location->set_has_explorer(0);
			
			// int new_row, new_col;
			
			//current_location = this->maze_vector[this->p1.get_level() + 1]->get_location(1,1);
			
			int new_row, new_col;
			
			current_location = find_next_start_place(old_level+1, new_row, new_col);
			
			current_location->set_has_explorer(1);
			
			
			
			this->p1.set_location(this->p1.get_level() + 1, new_row, new_col);
			
			
			// current_location = this->maze_vector[old_level + 1]->get_location(1, 1); //assuming start at 1,1;
			
			
		}
		
		else{
			
			cout << "You Can't Climb Here..." << endl;
		}
	}
	
	if (move == 'p'){
		
		if (p1.get_skills() > 0){
			cout << "You Displayed a Skill." << endl;
			this->p1.remove_skill();
			this->ta1.appease();
		}
		else{
			cout << "You Do Not Have Enough Skills..." << endl;
		}
		
	}
}
	
	
		
		
		
		
	
	








