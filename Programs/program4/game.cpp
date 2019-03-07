
/*********************************************************************
** Program Filename:game.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class game
** Input:None
** Output:Text-Based
*********************************************************************/


#include "game.hpp"

/*********************************************************************
** Function:Game
** Description:game constructor
** Parameters:int row, int col, int size
** Pre-Conditions:
** Post-Conditions:created
*********************************************************************/ 

Game::Game (int row, int col, int size){
	
	srand(time(NULL));
	
	int start_row = rand()%(size - 2) + 1;
	int start_col = rand()%(size - 2) + 1;
	
	this->player = new Player(start_row, start_col, size);
	
	// this->start_row = row;
	// this->start_col = col;
	
	// this->row = row;
	// this->col = col;
	
	this->wumpus_is_dead = 0;
	
	this->gold_event = new Gold;
	this->pit_event = new Pit;
	this->bat_event = new Bat;
	this->wumpus_event = new Wumpus;
	
	this->size = size;
	
	Room empty_room;
	
	//this->map.resize(size, vector<Room>(size, empty_room));
	
	for (int i = 0; i < size; ++i){
		this->map.push_back(vector<Room>{});
		for (int j = 0; j < size; j++){
			this->map[i].push_back(empty_room);
		}
	}	
}

/*********************************************************************
** Function:~Game
** Description:game destructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:destroyed
*********************************************************************/ 

Game::~Game(){
	
	delete this->gold_event;
	delete this->pit_event;
	delete this->bat_event;
	delete this->wumpus_event;
	delete this->player;
	
}

/*********************************************************************
** Function:print_map
** Description:debug map printout
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::print_map(){
	
	for (int i = 0; i<this->map.size(); ++i){
		
		cout << " -";
		for (int x = 0; x < this->map.size(); ++x){cout << "----";}
		cout << endl;
		
		for (int j = 0; j<this->map[i].size(); ++j){
			
			if (i == this->player->row && j == this->player->col){cout << " | X";}
			else if (i == this->player->start_row && j == this->player->start_col){cout << " | o";}
			else {cout << " | "; this->map[i][j].debug_print();}
			
		}
		cout << " |\n";
	}
	cout << " -";
	for (int x = 0; x < this->map.size(); ++x){cout << "----";}
	cout << endl;
}

/*********************************************************************
** Function:fill_map
** Description:adds events to map
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
	
void Game::fill_map(){

	//assign a proportional amount of bad things (except wump and gold) to the side length
	for (int j = 0; j<this->size/4; ++j){
		for (int i = 0; i<2; ++i){assign_events(2); assign_events(3);}
	}
	
	assign_events(4);
	assign_events(1);

}

/*********************************************************************
** Function:assign_events
** Description:fill an empty square with the event of type event
** Parameters:int event
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
	
void Game::assign_events(int event){
	
	int row_index;
	int col_index;
	Event * temp;
	
	do{
	
		row_index = rand()%size;
		col_index = rand()%size;
	
	} while (this->map[row_index][col_index].has_event() != -1 || 
			(row_index == this->player->row && col_index == this->player->col) || 
			(row_index == this->player->start_row && col_index == this->player->start_col));
	
	switch (event){
		
		case 1:
			//gold
			temp = gold_event;
			break;
			
		case 2:
			//batssss
			temp = bat_event;
			break;
			
		case 3:
			//pitssss
			temp = pit_event;
			break;
			
		case 4:
			//wumpus
			temp = wumpus_event;
			break;		
			
	}
	
	this->map[row_index][col_index].set_room_event(temp);
	
}

/*********************************************************************
** Function:wake_wumpus
** Description:wakes the wumpus boi
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::wake_wumpus(){
	
	cout << "The Wumpus was awakened by your arrow." << endl;
	int dice_roll = rand()%4;
	
	if (dice_roll == 3){ return;}
	
	cout << "You hear the wumpus relocate." << endl;
	
	int wumpus_row, wumpus_col;
	
	for (int row = 0; row < this->size; ++row){
		for (int col = 0; col < this->size; ++col){
			if (this->map[row][col].has_event() == 4){wumpus_row = row; wumpus_col = col; break;}
		}
	}
	
	
	this->map[wumpus_row][wumpus_col].set_room_event(NULL);
	assign_events(4);//assign a new wumpus somewhere else

}

/*********************************************************************
** Function:get_event_at_offset
** Description:returns the event type at offset from current player position
** Parameters:int row_offset, int col_offset
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

int Game::get_event_at_offset(int row_offset, int col_offset){
	//cout << "Start with offsets: "<< row_offset << col_offset << " and rc " << this->player->row << this->player->col << endl;
	if (this->player->row + row_offset >= size || this->player->row + row_offset < 0){
		return -1;
	}
	else if (this->player->col + col_offset >= size || this->player->col + col_offset < 0){
		return -1;
	}
	else{
		//cout << "=event=> Reached ELSE Condition. Value: " << this->player->row + row_offset << ", " << this->player->col + col_offset << endl;
		return (this->map[this->player->row + row_offset][this->player->col + col_offset].has_event());
	}
}

/*********************************************************************
** Function:get_percept_at_offset
** Description:calls the percept for the square at offset
** Parameters:int row_offset, int col_offset
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::get_percept_at_offset(int row_offset, int col_offset){
	//cout << "Start with offsets: "<< row_offset << col_offset << " and rc " << this->player->row << this->player->col << endl;
	if (this->player->row + row_offset >= size || this->player->row + row_offset < 0){
		return;
	}
	else if (this->player->col + col_offset >= size || this->player->col + col_offset < 0){
		return;
	}
	else{
		//cout << "=event=> Reached ELSE Condition. Value: " << this->player->row + row_offset << ", " << this->player->col + col_offset << endl;
		if (this->map[this->player->row + row_offset][this->player->col + col_offset].has_event() != -1){
			this->map[this->player->row + row_offset][this->player->col + col_offset].room_event->percept();
		}
		else{return;}
	}
}

/*********************************************************************
** Function:shoot
** Description:controls shooting in direction
** Parameters:int direction
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::shoot(int direction){
	//0 - N; 1 - S; 2 - W; 3 - E
	int arrow_range = this->size * 3 / 4; //4 --> 3 per requirements. 
	
	if (this->player->arrows == 0){cout << "You can't do that - you are out of arrows." << endl; return;}
	
	this->player->arrows--;
	
	switch (direction){
		
		case 0: //north
		
			for (int cells_travelled = 1; cells_travelled < arrow_range; ++cells_travelled){
				if (this->player->row - cells_travelled == -1){cout << "Your arrow hit a wall." << endl; return;}
				
				if (get_event_at_offset(cells_travelled * -1, 0) == 4){
					//hit dat wumpus
					this->wumpus_is_dead = 1;
					kill_wumpus();
					return;				
				}
				
				if (get_event_at_offset(cells_travelled*-1, 1) == 4 || get_event_at_offset(cells_travelled*-1, -1) == 4){
						wake_wumpus();
						break;
					}
			}
			cout << "Your arrow fell to the floor after travelling " << arrow_range << " cells." << endl; 	
			return;
		
		case 1: //south
			
			for (int cells_travelled = 1; cells_travelled < arrow_range; ++cells_travelled){
				
				if (this->player->row + cells_travelled == this->size){cout << "Your arrow hit a wall." << endl;return;}
				
				if (get_event_at_offset(cells_travelled, 0) == 4){
					//hit dat wumpus
					this->wumpus_is_dead = 1;
					kill_wumpus();
					return;				
				}
				
				if (get_event_at_offset(cells_travelled, 1) == 4 || get_event_at_offset(cells_travelled, -1) == 4){
						wake_wumpus();
						break;
					}
			}
			cout << "Your arrow fell to the floor after travelling " << arrow_range << " cells." << endl;
			return;
			
		case 2://west
		
			for (int cells_travelled = 1; cells_travelled < arrow_range; ++cells_travelled){
				
				if (this->player->col + cells_travelled == 0){cout << "Your arrow hit a wall." << endl;return;}
				
				if (get_event_at_offset(0, cells_travelled*-1) == 4){
					//hit dat wumpus
					this->wumpus_is_dead = 1;
					kill_wumpus();
					return;				
				}
				
				if (get_event_at_offset(1, cells_travelled*-1) == 4 || get_event_at_offset(-1, cells_travelled*-1) == 4){
						wake_wumpus();
						break;
					}
			}
			cout << "Your arrow fell to the floor after travelling " << arrow_range << " cells." << endl;
			return;
			
		case 3:
		
			for (int cells_travelled = 1; cells_travelled < arrow_range; ++cells_travelled){
				
				if (this->player->col + cells_travelled == this->size){cout << "Your arrow hit a wall." << endl;return;}
				
				if (get_event_at_offset(0, cells_travelled) == 4){
					//hit dat wumpus
					this->wumpus_is_dead = 1;
					kill_wumpus();
					return;				
				}
				
				if (get_event_at_offset(1, cells_travelled) == 4 || get_event_at_offset(-1, cells_travelled) == 4){
						wake_wumpus();
						break;
					}
			}
			cout << "Your arrow fell to the floor after travelling " << arrow_range << " cells." << endl;
			return;
			
	}
	
}

/*********************************************************************
** Function:kill_wumpus
** Description:kills the wumpus
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::kill_wumpus(){
	
	int wumpus_row, wumpus_col;
	
	for (int row = 0; row < this->size; ++row){
		for (int col = 0; col < this->size; ++col){
			if (this->map[row][col].has_event() == 4){wumpus_row = row; wumpus_col = col; break;}
		}
	}
	
	
	this->map[wumpus_row][wumpus_col].set_room_event(NULL);
	
	cout << "You hit and killed the Wumpus." << endl;
	
}

/*********************************************************************
** Function:turn_menu
** Description:prints turn menu, manages the game menus
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::turn_menu(){
	
	int shoot_or_move;
	int direction;
	
	cout << "What do you want to do? (0: Shoot, 1: Move) :";
	shoot_or_move = input_on_range(0,1);
	cout << "\nWhat direction? (0: N, 1: S, 2: W, 3: E) :";
	direction = input_on_range(0,3);
	
	cout << endl;
	
	switch (shoot_or_move){
		
		case 0://shoot
			
			shoot(direction);
			break;
			
		case 1:
		
			this->player->move(direction);
			//percepts_and_events();
			break;
	}
}

/*********************************************************************
** Function:percepts_and_events
** Description:manages calling percepts and events for a player
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::percepts_and_events(){
	
	if (get_event_at_offset(0,0) != -1){//not null
		
		this->map[this->player->row][this->player->col].room_event->encounter(this->player);
		
		//check for gold, if so remove
		if (get_event_at_offset(0,0) == 1){//we've got gold
			this->map[this->player->row][this->player->col].set_room_event(NULL);//clear the gold from there
		}
		
		//check if at original spot, if so, check if there's gold, and wumpus ded, if so exit.

	}
	
	if (this->player->at_start() && this->wumpus_is_dead == 1 && this->player->has_gold == 1){
	cout << "YOU WIN! The Gold was Retrieved and you made it back to the entrance hole." << endl;
	this->player->is_dead = 1;
	}
	
	if (this->player->is_dead == 1){
		return;
	}
	cout << "\nPercepts:\n---------\n";
	get_percept_at_offset(1,0);
	get_percept_at_offset(0,1);
	get_percept_at_offset(-1,0);
	get_percept_at_offset(0,-1);
	

}

/*********************************************************************
** Function:string_Is_Int
** Description:checks a string is integer
** Parameters: string input
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int Game::string_is_int (string input){
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) return 0;
	}
	return 1;
}

/*********************************************************************
** Function:parameter_Check
** Description: checks for input on range
** Parameters:string parameter
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int Game::input_on_range(int low, int high){
	string user_input;
	cin >> user_input;
	
	if (string_is_int(user_input)){
		int int_user_input = stoi (user_input);
		if (int_user_input >= low && int_user_input <= high){
			return int_user_input;
		}
	}
	
	cout << endl << "ERROR: Out of Range or Not Int. Enter again: ";
	input_on_range(low, high);
}

/*********************************************************************
** Function:clear_screen
** Description:clears screen
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::clear_screen(){
	
	for (int i = 0; i<100; ++i){
		cout << "\n";
		
	}
}

/*********************************************************************
** Function:play_game
** Description:plays game
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::play_game(){
	
	fill_map();
	
	while (this->player->is_dead == 0){
		
		clear_screen();
		percepts_and_events();
		
		if (this->player->is_dead == 1){return;}
		
		print_map();
		turn_menu();
		
		cout << "Press any key to continue . . . " ;

		getchar();
		getchar();
	}	
	
}
	
