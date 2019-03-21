//Player.hpp

#include <iostream>
#include <random>

using std::cout;
using std::endl;

class Player {
	
	private:
	
	int row;
	int col;
	
	public:
	
	Player();
	char get_move();
	void set_location (int row, int col);
	int get_row();
	int get_col();
	
};