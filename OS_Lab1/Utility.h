#pragma once

enum ERROR {
	Soft,
	Hard,
	Null
};

class Constants {
public:

};

class Result {
public:
	Result(ERROR error = ERROR::Null) { this->error = error; };
	Result(int value, ERROR error = ERROR::Null) 
	{
		this->value = value;
		this->error = error;		
	}
	int GetValue() { return value; }
	ERROR GetError() { return error; }
	void SetValue(int value) {this->value = value; }
private:
	ERROR error;
	int value;
};