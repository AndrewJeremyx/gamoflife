#include <iostream>
#include "Game.h"
#include "Printer.h"
void FieldPrinter::print(Field& field)
{
    for (int i = 0; i < field.getLength(); i++)
    {
        for (int j = 0 ; j < field.getHeight(); j++)
        {
            if (field.getCell(i,j) == 1)
                std::cout<<"*";
            else
                std::cout<<" ";
        }
        std::cout<<"\n";
    }
}
