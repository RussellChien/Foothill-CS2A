// Pet.cpp
// 2a-Lab-06-Pets
//
#include <iostream>
#include <sstream>
#include <vector>

#include "Pet.h"

using namespace std;

// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;
size_t _population_counter = 0;

string _name;
long _id;
int _num_limbs;
static size_t _population;

Pet::Pet(string name, long id, int num_limbs) {
	_name = name;
	_id = id;
	_num_limbs = num_limbs;
	_population_counter++;
	_population = _population_counter;
}

Pet::~Pet() {
	_population_counter--;
	_population = _population_counter;
}

string Pet::get_name() const { return _name; }

long Pet::get_id() const { return _id; }

int Pet::get_num_limbs() const { return _num_limbs; }

bool Pet::set_name(string name) {
	if (name == "") {
		return false;
	} else {
		_name = name;
		return true;
	}
}

bool Pet::set_id(long id) {
	if (id < 0) {
		return false;
	} else {
		_id = id;
		return true;
	}
}

bool Pet::set_num_limbs(int num_limbs) {
	if (num_limbs < 0) {
		return false;
	} else {
		_num_limbs = num_limbs;
		return true;
	}

}

string Pet::to_string() const {
	string result = "(Name: " +  _name + ", ID: " + std::to_string(_id) + ", Limb Count: " + std::to_string(_num_limbs) + ")";
	return result;
}

// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {
	pets.resize(n);
	long prev_id = 0;
	for (size_t i = 0; i < n; i++) {
		long id = prev_id + 1 + rand() % 10;
		pets[i].set_id(id);
		pets[i].set_num_limbs(rand() % 9); // up to arachnids
		pets[i].set_name(make_a_name(name_len));
		pets.push_back(pets[i]);
		prev_id = pets[i].get_id();
	}
	pets.resize(n);
}
// ---------------------------------------------------------------------
string Pet::make_a_name(int len) {
	string vowels = "aeiou", consonants = "bcdfghjklmnpqrstvwxyz", result = "";
	bool start;
	if (len == 1) {
		if(rand() % 2 == 0) {
				result = result + consonants[rand() % consonants.length()];
			} else {
				result = result + vowels[rand() % vowels.length()];
			}
		return result;
	}
	for(int i = 0; i < len-1; i++) {
		if (i == 0) {
			if(rand() % 2 == 0) {
				result = result + consonants[rand() % consonants.length()];
				start = true;
			} else {
				result = result + vowels[rand() % vowels.length()];
				start = false;
			}
			
		}
		if (start) {
			if (i % 2 != 0) {
				result = result + consonants[rand() % consonants.length()];
			} else {
				result = result + vowels[rand() % vowels.length()];
			}
		} else {
			if (i % 2 != 0) {
				result = result + vowels[rand() % vowels.length()];
			} else {
				result = result + consonants[rand() % consonants.length()];
			}
		}
	}
	_population++;
	return result;
}
// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2) {
	return pet1.get_name() == pet2.get_name() && pet1.get_id() == pet2.get_id() && pet1.get_num_limbs() == pet2.get_num_limbs();
}

bool operator!=(const Pet& pet1, const Pet& pet2) {
	return pet1.get_name() != pet2.get_name() || pet1.get_id() != pet2.get_id() || pet1.get_num_limbs() != pet2.get_num_limbs();
}

ostream& operator<<(ostream& os, const Pet& pet) {
	os << "(Name: " << pet.get_name() << ", ID: " << std::to_string(pet.get_id()) << ", Limb Count: " << std::to_string(pet.get_num_limbs()) << ")";
	return os;

}