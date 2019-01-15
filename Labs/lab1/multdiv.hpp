//MULTDIV HEADER FILE -- LYELL READ

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct multdiv_entry {
	
	int mul;
	float div;
	
};

float float_round (float num);
int s_to_i (string input);
int string_Is_Int (string input);
int parameter_Check(string parameter, int low, int high);

struct multdiv_entry ** generate_tables(int n);
void free_memory (struct multdiv_entry** grid, int n);
void print_tables (struct multdiv_entry** grid, int n);
void populate (struct multdiv_entry** grid, int n);
