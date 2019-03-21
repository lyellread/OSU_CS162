/*********************************************************************
** Program Filename:instructor.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: Instructor
** Input:na
** Output:na
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "maze_person.hpp"

#include <iostream>

using std::cout;
using std::endl;

class Instructor : public MazePerson {
	
	private:
	
	bool satisfied;
	
	public:
	
	Instructor();
	int get_move();
	bool get_satisfied();
	void set_satisfied(int set);
	// void set_location (int row, int col);
	// int get_row();
	// int get_col();
	
};

#endif