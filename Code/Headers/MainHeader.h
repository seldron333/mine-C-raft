#pragma once
#include "../Blocks.cpp"
#include "../Entities.cpp"
#include "../Base.cpp"
#include "../Graphics.cpp"
#include "../WorldGeneration.cpp"

class Chunk;

Blocks::BlockParent &Block(double x, short y, double z);

template <typename T>
void log(T tx);