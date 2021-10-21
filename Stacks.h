// Student ID: 20393765
//
#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>

class Stack_Int {
private:
	std::vector<int> _data;

public:
	// No explicit constructor or destructor
	size_t size() const {
		return _data.size();
	}

	bool is_empty() const {
		return _data.empty();
	}

	void push(int val) {
		_data.push_back(val);
	}

	int top(bool& success) const {
		if (is_empty()) {
			success = false;
			return 0;
		} else {
			success = true;
			return _data[size()-1];
		}
	}

	bool pop() {
		if (is_empty()) {
			return false;
		} else {
			_data.pop_back();
			return true;
		}
	}

	bool pop(int& val) {
        bool result;
        val = top(result);
        if (result)
            _data.pop_back();
        return result;
    }

	std::string to_string() const {
        std::string result = "Stack (";
        result = result + std::to_string(_data.size()) ;
        result = result + " elements):\n";
        if (_data.size() > 10) {
            for (size_t i = size()-1; i > size()-11; i--) {
                result = result + std::to_string(_data[i]) + "\n";
            }
            result = result + "...\n";
        }
        else
        {
            for (size_t i = size()-1; i > 0; i--) {
                result = result + std::to_string(_data[i]) + "\n";
            }
        }
        result = result + "Elements, if listed above, are in increasing order of age.";
        return result;
    }

// Don't remove the following line
friend class Tests;
};


class Stack_String {
private:
	std::vector<std::string> _data;

public:
	// No explicit constructor or destructor
	size_t size() const {
		return _data.size();
	}

	bool is_empty() const {
		return _data.empty();
	}

	void push(std::string val) {
		_data.push_back(val);
	}

	std::string top(bool& success) const {
		if (is_empty()) {
			success = false;
			return "";
		} else {
			success = true;
			return _data[size()-1];
		}
	}

	bool pop() {
		if (is_empty()) {
			return false;
		} else {
			_data.pop_back();
			return true;
		}
	}

	bool pop(std::string& val) {
        bool result;
        val = top(result);
        if (result)
            _data.pop_back();
        return result;
    }

	std::string to_string() const {
        std::string result = "Stack (";
        result = result + std::to_string(_data.size()) ;
        result = result + " elements):\n";
        if (_data.size() > 10) {
            for (size_t i = size()-1; i > size()-11; i--) {
                result = result + _data[i] + "\n";
            }
            result = result + "...\n";
        }
        else
        {
            for (size_t i = size()-1; i > 0; i--) {
                result = result + _data[i] + "\n";
            }
        }
        result = result + "Elements, if listed above, are in increasing order of age.";
        return result;
    }
	

friend class Tests;
};

#endif /* Stacks_h */