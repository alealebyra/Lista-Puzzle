#ifndef PUZZLE_H
#define PUZZLE_H
#include "wezel.h"
#include "lista.h"
#include <iostream>
#include <new>
#include <stdexcept>
#include <string.h>

using namespace std;

class Puzzle
{
private:
    List<char> solution; // rozwi¹zanie  puzzli
    List<char> puzzle; // Aktualna  konfiguracja liter
    int length;
public:
    Puzzle(const char answ[],const char init[] ); // Konstruuje puzzle
    void shiftLeft();
    void swapEnds();
    void display();
    bool isSolved();

};

Puzzle::Puzzle(const char answ[],const char init[] )
{
    length=strlen(answ);
    char _answ[length], _init[length];
    strcpy(_answ,answ);
    strcpy(_init,init);
    char i;
    try
    {
        for(i=0; i<length; i++)
            solution.insert(_answ[i]);

        for(i=0; i<length; i++)
            puzzle.insert(_init[i]);
    }
    catch (bad_alloc &ba)
    {
        cerr << "Tu jestem! bad_alloc caught: " << ba.what() << '\n';
    }
}

void Puzzle::shiftLeft()
{
    try
    {
        puzzle.gotoPrior();
    }
    catch(logic_error &e)
        {
            cerr << "Caught: " << e.what( ) << endl;
        }
}

void Puzzle::swapEnds()
{
    char first, last;
    try
    {
        first=puzzle.getCursor();
        puzzle.gotoPrior();
        last=puzzle.getCursor();
        puzzle.replace(first);
        puzzle.gotoNext();
        puzzle.replace(last);
    }
    catch(logic_error &e)
        {
            cerr << "Caught: " << e.what( ) << endl;
        }
}

void Puzzle::display()
{
        solution.showStructure();
        cout<<endl;
        puzzle.showStructure();
}

bool Puzzle::isSolved()
{
    int i;
    for(i=0;i<length;i++)
    {
        try
        {
            if(puzzle.getCursor()!=solution.getCursor()) return false;
            puzzle.gotoNext();
            solution.gotoNext();
        }
        catch(logic_error &e)
        {
            cerr << "Caught: " << e.what( ) << endl;
        }
    }
    return true;
}

#endif // PUZZLE_H
