
#include "maze.hpp"

Maze::Maze(const char * maze_char_array[16], int rows, int cols){
	
	this->maze.resize(cols);
	
	vector<MazeLocation*> v;
	v.resize(rows);
	
	for (int i  = 0; i < cols; ++i){
		this->maze[i] = v;
	}
	
	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col){
			
			if (maze_char_array[row][col] == '#'){
				this->maze[row][col] = new Wall();
			}
			else if (maze_char_array[row][col] == '^'){
				this->maze[row][col] = new OpenSpace();
				this->maze[row][col]->set_is_end(1);
			}
			else if (maze_char_array[row][col] == '@'){
				this->maze[row][col] = new OpenSpace();
				this->maze[row][col]->set_is_start(1);
				this->maze[row][col]->set_has_explorer(1);
			}
			else{
				this->maze[row][col] = new OpenSpace();
			}
		}
	}
	
}

Maze::~Maze(){
	
	for (int row =0; row< this->maze.size(); ++row){
		for (int col =0; col< this->maze[row].size(); ++col){
			delete this->maze[row][col];
		}
	}
}

MazeLocation* Maze::get_location(int row, int col){
	
	return this->maze[row][col];
	
}

void Maze::display_maze_location(int row, int col){
	
	this->maze[row][col]->display_space_data();
	
}

void Maze::display_maze(){
	
	cout << "\nMaze:" << endl;
	for (int row = 0; row<this->maze.size(); ++row){
		for (int col =0; col< this->maze[row].size(); ++col){
			cout << this->maze[row][col]->get_display_character();
		}
		cout << endl;
	}	
}

		
		