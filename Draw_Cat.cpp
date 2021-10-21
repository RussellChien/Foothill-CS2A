// Student ID: 20393765
// Draw_Cat.cpp
//
// When this program is run it should print the following lines on the console:
// For reference, Schrodinger on the last output line starts at col 1.
//
//  -------
// | /\_/\ |
// |( o o )|
// | > ^ < |
//  -------
// Schrodinger
//
#include <iostream>

using namespace std;

void draw_cat() {
	printf("  -------\n");
	printf(" | /\\_/\\ |\n");
	printf(" |( o o )|\n");
	printf(" | > ^ < |\n");
	printf("  -------\n");
	printf("Schrodinger\n");
}

int main(int argc, const char * argv[]) {
	draw_cat();

	return 0;
}