#include "wall.hpp"
// #include "maze_location.hpp"

Wall::Wall() : MazeLocation ('#', 0) {}

char Wall::get_display_character(){
	
	return this->display_character;
	
}

bool Wall::get_is_occupiable(){
	
	return this->is_occupiable_bool;
	
}

void Wall::display_space_data(){
	
	cout << "Wall" << endl;
	
}