// Player.cpp

#include "player.hpp"

Player::Player(){
	
	this->row = -1;
	this->col = -1;
	srand(time(NULL));

}

char Player::get_move(){
	
	int direction = rand()%4;
	
	//0..3
	switch (direction) {
		
		case 0:
			
			return 'W';
			break;
			
		case 1:
		
			return 'A';
			break;
			
		case 2: 
		
			return 'S';
			break;
			
		case 3:
		
			return 'D';
			break;
			
	}
		
	cout << "ERROR ON GET MOVE" << endl;
	
}
			
void Player::set_location (int row, int col){

		this->row = row;
		this->col = col;
		
}

int Player::get_row(){
	
	return this->row;
	
}
	
int Player::get_col(){
	
	return this->col;
	
}
			