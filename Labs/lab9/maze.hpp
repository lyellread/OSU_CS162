#ifndef __MAZE_HPP
#define __MAZE_HPP

#include "maze_location.hpp"
#include "wall.hpp"
#include "open_space.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Maze {
	
	private:
	
	vector<vector<MazeLocation*> > maze;
	
	public:

	Maze(const char * maze_char_array[16], int rows, int cols);
	~Maze();
	
	MazeLocation* get_location(int row, int col);
	void display_maze_location(int row, int col);
	void display_maze();
	
};
#endif