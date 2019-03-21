/*********************************************************************
** Program Filename:wall.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: Wall
** Input:na
** Output:na
*********************************************************************/

#ifndef __MAZE_LEVEL_HPP
#define __MAZE_LEVEL_HPP

#include "maze_location.hpp"
#include "wall.hpp"
#include "open_space.hpp"
#include "maze_person.hpp"
#include "ta.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;

class MazeLevel {
	
	private:
	
	int rows;
	int cols;
	
	vector<vector<MazeLocation*> > maze;
	
	public:

	MazeLevel(int rows, int cols, ifstream &is);
	~MazeLevel();
	
	MazeLocation* get_location(int row, int col);
	void display_maze_location(int row, int col);
	MazeLocation* get_empty_space();
	void display_maze();
	void set_skills();
};
#endif