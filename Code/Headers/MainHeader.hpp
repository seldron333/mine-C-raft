#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <json.hpp>
#include <sstream>
#include "../Static/Blocks.cpp"
#include "../Static/Entities.cpp"
#include "../WorldGeneration.cpp"
#include "../Base.cpp"

class Chunk;

void StartGraphics();

Blocks::BlockParent &Block(double x, short y, double z);
void SetBlock(Blocks::BlockParent& bl, Blocks::BlockTypes type);

template <typename T>
void log(T tx);