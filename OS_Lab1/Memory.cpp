#include "Memory.h"
#include <iostream>
#include <string>
int Memory::findIndexToInsert(std::vector<float> vector, float value) {
    int begin = 0;
    int end = vector.size() - 1;

    while (end - begin > 1) {
        int currentIndex = (end - begin) / 2 + begin;

        if (vector[currentIndex] > value) {
            end = currentIndex;
        }
        else if (vector[currentIndex] < value) {
            begin = currentIndex;
        }
        else
            return -1;
    }
    if (vector[end] == value || vector[begin] == value)
        return -1;
    if (vector[end] < value)
        return end + 1;
    else if (vector[begin] > value)
        return begin;
    else
        return end;
}
int Memory::elementEaqual(float value)
{
    if (size == 0)
        return -1;
    if (size == 1) {
        if (inputs[0] == value) {
            return 0;
        }
        return -1;
    }
    int begin = 0;
    int end = size - 1;
    while (end - begin > 1) {
        int currentIndex = (end - begin) / 2 + begin;
        if (inputs[currentIndex] > value) {
            end = currentIndex;
        }
        else if (inputs[currentIndex] < value) {
            begin = currentIndex;
        }
        else
            return currentIndex;
    }
    if (inputs[begin] == value)
        return begin;
    if (inputs[end] == value)
        return end;
    return -1;
}
Memory::Memory()
{
    std::string inputTemp;
    std::string outputTemp;

    std::fstream file("Memory.txt");
    while (!file.eof()) {
        std::getline(file, inputTemp);
        std::getline(file, outputTemp);
        if (inputTemp == "")
            break;
        float input = std::stof(inputTemp);
        float output = std::stof(outputTemp);
        AddPairSimple(input, output);
    }
    file.close();
}
void Memory::AddPair(float input, float output)
{
    if (size == 0) {
        size++;
        inputs.push_back(input);
        outputs.push_back(output);
        return;
    }
    else if (size == 1) {
        if (inputs[0] == input) {
            std::cout << "Has alredy added \n";
            return;
        }
        size++;
        if (inputs[0] > input) {
            inputs.insert(inputs.begin(), input);
            outputs.insert(outputs.begin(), output);
        }
        else{
            inputs.insert(inputs.begin() + 1, input);
            outputs.insert(outputs.begin() + 1, output);
        }
        return;
    }

    int index = findIndexToInsert(inputs, input);
    if (index == -1) {
        std::cout << "Has alredy added \n";
        return;
    }
    size++;
    inputs.insert(inputs.begin() + index, input);
    outputs.insert(outputs.begin() + index, output);
}
void Memory::AddPairSimple(float input, float output)
{
    outputs.push_back(output);
    inputs.push_back(input);
    size++;
}
float Memory::GetOutput(float input)
{
    int index = elementEaqual(input);
    if (index == -1) {
        std::cout << "Element is not in memory \n";
        return -1;
    }
    return outputs[index];
}
void Memory::Print()
{
    for (int i = 0; i < size; i++) {
        std::cout << inputs[i] << " : " << outputs[i] << std::endl;
    }
}
bool Memory::ContainElement(float value)
{
    int index = elementEaqual(value);
    return index != -1;
}
Memory::~Memory()
{
    std::fstream file("Memory.txt");
    for (int i = 0; i < size; i++) {
        file << inputs[i] << "\n";
        file << outputs[i];
        if (i < size - 1)
            file << "\n";
    }
    file.close();
}