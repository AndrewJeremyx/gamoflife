#include <random>
#include "Game.h"
cell& Field::at(unsigned int x,unsigned int y)
{
    return cells_[(y % height_) * length_ + (x % length_)];
}
Field::Field()
{
    cells_ = nullptr;
    length_ = 0;
    height_ = 0;
}
Field::Field(unsigned int length,unsigned int height,bool IsRand = 1) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,10000);
    cells_ = new cell[height * length];
    height_ = height;
    length_ = length;
    for (int i = 0; i < (height_ * length_); i++)
    {
        if (IsRand)
        {
            if(dis(gen) % 15 == 0)
                cells_[i].condition = 1; 
        }
        else
            cells_[i].condition = 0;
    }
}
Field::~Field()
{
    if (cells_ != nullptr)
    {
        delete[] cells_;
    }
}
unsigned int Field::getLength()
{
    return length_;
}
unsigned int Field::getHeight()
{
    return height_;
}
bool Field::getCell(unsigned int x, unsigned int y)
{
    return cells_[(y % height_) * length_ + (x % length_)].condition;
}
void Field::setCell(unsigned int x, unsigned int y, bool statement)
{
    at(x,y).condition = statement;
}
unsigned int Field::CountNei(unsigned int x,unsigned int y)
{
    unsigned int count = 0;
    for (int i = x - 1; i < x + 2; i++)
    {
        for (int j = y - 1; j < y + 2; j++)
        {
            if (i != x || j != y)
                count += at(i,j).condition;
        }
    }
    return count;
}
void Field::NextGen()
{
    Field Next(length_,height_,0);
    for (int i = 0; i < length_; i++)
    {
        for (int j = 0; j < height_; j++)
        {
            if (getCell(i,j) == 0)
            {
                if (CountNei(i,j) == 3)
                    setCell(i,j,1);
            }
            else
                if (CountNei(i,j) != 3 && CountNei(i,j) != 2)
                    setCell(i,j,0);
        }
    }
}

//14 2 %2321
