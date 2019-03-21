#ifndef __MAZE_LOCATION_HPP
#define __MAZE_LOCATION_HPP

class MazeLocation {
	
	public:
	
	char display_character;
	bool is_occupiable_bool;
	
	
	MazeLocation(char display_character, bool is_occubiable);
	
	virtual char get_display_character () = 0;
	virtual bool get_is_occupiable() = 0;
	virtual void display_space_data() = 0;
	virtual void set_has_explorer(bool set) = 0;
	virtual void set_is_start(bool set) = 0;
	virtual void set_is_end(bool set) = 0;
	virtual bool has_explorer() = 0;
	virtual bool is_start() = 0;
	virtual bool is_end() = 0;
};
	
#endif