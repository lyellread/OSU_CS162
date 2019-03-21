#ifndef __WALL_HPP
#define __WALL_HPP

#include <iostream>
#include "maze_location.hpp"

using std::cout;
using std::endl;

class Wall : public MazeLocation {
	
	public:
	
	Wall();
	
	void display_space_data();
	char get_display_character();
	bool get_is_occupiable();

	void set_has_explorer(bool set) {};
	void set_is_start(bool set) {};
	void set_is_end(bool set) {};
	bool has_explorer(){return 0;};
	bool is_start(){return 0;};
	bool is_end(){return 0;};
};

#endif