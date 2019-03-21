/*********************************************************************
** Program Filename:maze.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: Maze
** Input:na
** Output:na
*********************************************************************/

#ifndef __MAZE_HPP
#define __MAZE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "player.hpp"
#include "ta.hpp"
#include "instructor.hpp"
#include "wall.hpp"
#include "open_space.hpp"
#include "maze_location.hpp"
#include "maze_level.hpp"

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

class Maze {
	
	private:
				
		int rows;
		int cols;
		int levels;
		
		Instructor i1;
		TA ta1;
		Player p1;
		vector<MazeLevel*> maze_vector;
		
		char * filename;
	
	public:
	
		Maze (char * filename);
		~Maze();
		void dbg_print_all();
		
		void move_player();
		void move_tas();
		void special_player_move(char move);
		
		void clear_screen();
		int check_for_win();
		void check_ta_satisfaction();
		void check_instructor_satisfaction();
		void return_to_start();
		void return_to_level_0_start();
		void check_collect_skills();
		MazeLocation * find_next_start_place(int level, int &new_row, int &new_col);
		
		int play_turn();
		void play_game();
	
};

#endif