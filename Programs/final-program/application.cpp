/*********************************************************************
** Program Filename:application.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for the application
** Input:na
** Output:na
*********************************************************************/


#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

#include "maze.hpp"
//#include "maze_location.hpp"
#include "player.hpp"

/*********************************************************************
** Function:main
** Description:main function
** Parameters:int argc, char ** argv
** Pre-Conditions:none
** Post-Conditions:game done or exit with error
*********************************************************************/ 


int main(int argc, char ** argv){
	
	cout << " == Application Started!" << endl;
	
	srand(time(NULL));

	
	if (argc < 2 || argc > 2){
		cout << "TOO MANY OR TOO FEW ARGUMENTS PROVIDED. QUITTING." << endl;
		exit(EXIT_FAILURE);
	}
	
	ifstream is(argv[1]);
	
	if (!is.good()){
		cout << "ERROR OPENING FILE. QUITTING." << endl;
		is.close();
		exit(EXIT_FAILURE);
	}
	
	//now were good to go:
	
	Maze game(argv[1]);
	game.play_game();
	
	
	
	
	cout << " == Application Finished! " << endl;
	
}
