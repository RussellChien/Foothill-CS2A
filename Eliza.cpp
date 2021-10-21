// Student ID: 20393765
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//
#include <iostream>
#include <sstream>
using namespace std;
// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
string rotate_vowels(string& s) {
	for(size_t i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			s[i] = 'e';
		} else if (s[i] == 'e') {
			s[i] = 'i';
		} else if (s[i] == 'i') {
			s[i] = 'o';
		} else if (s[i] == 'o') {
			s[i] = 'u';
		} else if (s[i] == 'u') {
			s[i] = 'a';
		} else if (s[i] == 'A') {
			s[i] = 'E';
		} else if (s[i] == 'E') {
			s[i] = 'I';
		} else if (s[i] == 'I') {
			s[i] = 'O';
		} else if (s[i] == 'O') {
			s[i] = 'U';
		} else if (s[i] == 'U') {
			s[i] = 'A';
		}
	}
	return s;
}
// Return a string in which all occurrences of s have been replaced by th
string lispify(string s) {
	string result = "";
	for(size_t i = 0; i < s.length(); i++) {
		if (s[i] == 's') {
			result = result + 't';
			result = result + 'h';
		} else if (s[i] == 'S') {
			result = result + 'T';
			result = result + 'h';
		} else {
			result = result + s[i];
		}
	}
	return result;
}
// Enter the user-interaction loop as described earlier
void enter() {
	bool active = true; 
	string s = "";
	std::cout << "What?\n";
	while (active) {
		std::getline(std::cin, s);
		printf("    ");
		std::cout << s;
		printf("\n\n");
		if (s.find("") != std::string::npos) {
			if (s.find("!") !=  std::string::npos) {
				printf("OMG! You don't say!! ");
				std::cout << s;
				printf("!!!!!");
				s = "";
			} 
			if (s.find("what") != std::string::npos || s.find("why") != std::string::npos) {
				printf("\nI'm sorry, I don't like questions that contain what or why." );
				s = "";
			}
			if (s.find("s") != std::string::npos || s.find("S") != std::string::npos) {
				printf("Interethting. When did you thtop thtopping your thibilanth?\n");
				std::cout << lispify(s);
				printf("! Sheesh! Now what?");
				s = "";
			}
			if(s.find("Bye") != std::string::npos || s.find("quit") != std::string::npos) {
				printf("Ok Bye. Nice being a force of change in your life.");
				active = false;
				s = "";
				break;
			} 
			if(rand() % 10 < 8) {
				std::cout << rotate_vowels(s) + "?\n";
				s = "";
			} else {
				printf("\nHuh? Why do you say: ");
				std::cout << s;
				s = "";
			}
			
		}
	}

}