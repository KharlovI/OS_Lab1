#pragma once
#include <vector>
#include <fstream>
class Memory
{
private:
	int size = 0;
	std::vector<float> inputs = std::vector<float>();
	std::vector<float> outputs = std::vector<float>();
	
	// Methods
	int elementEaqual(float value);
	int findIndexToInsert(std::vector<float> vector, float value);
    
public:
	Memory();
	void AddPair(float input, float output);
	void AddPairSimple(float input, float output);
	float GetOutput(float input);
	void Print();
	bool ContainElement(float value);
	~Memory();
};

