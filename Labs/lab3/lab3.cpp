//LAB 3 -- LYELL READ -- 1/24/2019

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

//ASCII RANGES
//A-Z : 65-90  : adjust -65
//a-z : 97-122 : adjust -97


void count_all (int * count_array, ifstream &is){ //length of count_array is known to be 0..25 aka 26
	
	char temp_char;
	
	while (is.eof() == false){
		
		is.get(temp_char);
		
		if (int(temp_char) >= 65 && int(temp_char) <=90){
			//we got a lower case number
			++count_array[(int(temp_char)-65)];
		}
				if (int(temp_char) >= 97 && int(temp_char) <=122){
			//we got an upper case number
			++count_array[(int(temp_char)-97)];
		}
	}
	
}

void print_all (int * count_array){
	
	for (int i=0; i<26; ++i){
		
		cout << char(i+97) << "\t" << count_array[i] << endl;
		
	}
	
}


void write_all (int * count_array, ofstream &of){
	
	for (int i=0; i<26; ++i){
		
		of << char(i+97) << "\t" << count_array[i] << endl;
		
	}

}

int main (int argc, char ** argv){
	ifstream is(argv[1]);
	
	int * char_list = new int[26];
	
	count_all(char_list, is);
	print_all(char_list);
	is.close();
	
	ofstream of(argv[2]);
	write_all (char_list, of);
	of.close();
}