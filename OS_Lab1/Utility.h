#pragma once

enum ERROR {
	Soft,
	Hard,
	Null
};

class Constants {
public:
	static const int _timeSegmentsCount = 50;
};

class Result {
public:
	Result() {};
	Result(float value, int limit, ERROR error = ERROR::Null) 
	{
		this->errorLimit = limit;
		this->value = value;
		this->error = error;		
	}
	int GetValue() { return value; }
	ERROR GetError() { return error; }
	int GetLimit() { return errorLimit; }
	void IncrementErrorCount() { this->softErrorCount++; }
	bool ErrorLimitAchiened() { return softErrorCount >= errorLimit; }
	void SetValue(float v) { this->value = v; }
	void SetError(ERROR e) { this->error = e; }
	void SetLimit(int lim) { this->errorLimit = lim; }
private:
	ERROR error;
	float value = 0;
	int softErrorCount = 0;
	int errorLimit = 0;
};