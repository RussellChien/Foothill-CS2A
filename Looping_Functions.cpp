// Student ID: 20393765
//
// Looping_Functions.cpp
//
// Created by Anand Venkataraman on 8/9/19.
// Copyright © 2019 Anand Venkataraman. All rights reserved.
//
#include <iostream>
#include <sstream>

#include <cmath>
#include <math.h>


using namespace std;
// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.
bool play_game(int n) {
	printf("Welcome to my number guessing game\n\n");
	for (int i = 0; i < 6; i++) {
		printf("Enter your guess: ");
		int guess;
		cin >> guess;
		printf("\nYou entered: ");
		cout << guess; 
		printf("\n");
		if (guess == n) {
			printf("You found it in ");
			cout << i+1; 
			printf(" guess(es).\n");
			return true;
		}
	}
	printf("\nI'm sorry. You didn't find my number.");
	printf("\nIt was ");
	cout << n;
	printf("\n\n");
	return false; 
}
// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.
double etox(double x, size_t n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 1 + x;
	}
	else {
		double sum = 1 + x;
		double factorial = 1; 
		double new_x = x; 
		for(size_t i = 2; i < n; i++) {
	 		new_x = new_x * x;
			factorial = factorial * i;
	 		sum = sum + (new_x/factorial);
		}
		return sum; 
	}
}
// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
	int count = 0;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == c) {
			count++;
		}
	}
	return count;
	
}
// Use Euclid's algorithm to calculate the GCD of the given numbers
size_t gcd(size_t a, size_t b) {
	if (a == 0) {
        return b;
	}
    return gcd(b % a, a);
}
// Return a string of the form n1,n2,n3,... for the given AP.
string get_ap_terms(int a, int d, size_t n) {
	string result = "";
	for (size_t i = 1; i <= n; i++) {
		int tn = a + (i-1) * d;
		if(i != n)
			result = result + to_string(tn) + ",";
		else
			result = result + to_string(tn);
	}
	return result;
}
	
// Return a string of the form n1,n2,n3,... for the given GP.
string get_gp_terms(double a, double r, size_t n) {
	string result = "";
	for (size_t i = 1; i <= n; i++) {
		double tn = a * pow(r, (i-1));
		ostringstream convert;
		convert << tn;
		if(i != n)
			result = result + convert.str() + ",";
		else
			result = result + convert.str();
	}
	return result;
	
}
double get_nth_fibonacci_number(size_t n) { 
	double a = 0, b = 1, c; 
  	if(n == 0) 
    	return a; 
  	for (size_t i = 2; i <= n; i++) { 
   	  	c = a + b; 
    	a = b; 
    	b = c; 
  	} 
  	return b; 
}