//MULTDIV PRINT FILE -- LYELL READ

#include "multdiv.hpp"

int main (int argc, char ** argv) {
	
	if (argc != 2){
		exit(EXIT_FAILURE);
	}
	
	int n;
	struct multdiv_entry**grid;
	n=parameter_Check(argv[1], 1, 100000);
	
	grid=generate_tables(n);
	populate(grid, n);
	print_tables(grid, n);
	free_memory(grid,n);
}