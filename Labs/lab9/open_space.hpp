#ifndef __OPEN_SPACE_HPP
#define __OPEN_SPACE_HPP

#include <iostream>
#include "maze_location.hpp"

using std::cout;
using std::endl;

class OpenSpace : public MazeLocation {
	
	private:
	
	bool space_has_explorer;
	bool space_is_start;
	bool space_is_end;
	
	public:
	
	OpenSpace();
	
	char get_display_character();
	bool get_is_occupiable();
	void display_space_data();
	
	void set_has_explorer(bool set);
	void set_is_start(bool set);
	void set_is_end(bool set);
	bool has_explorer();
	bool is_start();
	bool is_end();
	
};

#endif