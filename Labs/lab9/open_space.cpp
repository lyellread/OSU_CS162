#include "open_space.hpp"
// #include "maze_location.hpp"

OpenSpace::OpenSpace() : MazeLocation (' ', 1) {}

char OpenSpace::get_display_character(){
	
	if (this->space_has_explorer){return 'P';}
	if (this->space_is_start){return 'S';}
	if (this->space_is_end){return 'E';}
	return this->display_character;
	
}

void OpenSpace::display_space_data(){
	
	cout << "Open Space with attributes: Explorer: " << this->space_has_explorer 
		<< ", Start: " << this->space_is_start 
		<< ", End: " << this->space_is_end << endl;
	
}

bool OpenSpace::get_is_occupiable(){
	
	return this->is_occupiable_bool;
	
}

void OpenSpace::set_has_explorer(bool set){
	
	this->space_has_explorer = set;
	
}

void OpenSpace::set_is_start(bool set){
	
	this->space_is_start = set;
	
}

void OpenSpace::set_is_end(bool set){
	
	this->space_is_end = set;

}

bool OpenSpace::has_explorer(){
	
	return this->space_has_explorer;
	
}

bool OpenSpace::is_start(){
	
	return this->space_is_start;
	
}

bool OpenSpace::is_end(){
	
	return this->space_is_end;
	
}
