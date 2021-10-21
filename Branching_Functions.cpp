// Student ID: 20393765
//
// Branching-Functions.cpp
// 2a-Lab-03
//
#include <iostream>
// This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3) {
	double sum;
	sum = n1 + n2 + n3;
	return sum/3; 
}
// This function returns the maximum of the 5 given numbers
int max_of_5(int n1, int n2, int n3, int n4, int n5) {
	int max = n1;
	if (max < n2) {
		max = n2;
	}
	if (max < n3) {
		max = n3;
	}
	if (max < n4) {
		max = n4;
	}
	if(max < n5) {
		max = n5;
	}
	return max;

}
// This function returns the minimum of the 5 given numbers
int min_of_5(int n1, int n2, int n3, int n4, int n5) {
	int min = n1;
	if (min > n2) {
		min = n2;
	}
	if (min > n3) {
		min = n3;
	}
	if (min >n4) {
		min = n4;
	}
	if(min > n5) {
		min = n5;
	}
	return min;
	
}
// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid trianges. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
bool sides_make_triangle(int a, int b, int c) {
	if(c > a && c > b) {
		if ((a+b) == c || (a+b) > c) {
			return true;
		} else {
			return false;
		}
	} else if (b > a && b > c) {
		if ((a+c) == b || (a+c) > b) {
			return true;
		} else {
			return false;
		}
	} else if (a > b && a > c) {
		if ((b+c) == a || (b+c) > a) {
			return true;
		} else {
			return false;
		}
	} 
	return false;
}
// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {
	if (A + B + C == 180) {
		return true;
	} else {
		return false;
	}
}
// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {
	if (yyyy % 4 == 0) {
		if (yyyy % 100 == 0) {
			if (yyyy % 400 == 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return true;
		}
	} else {
		return false; 
	}
}