#include <iostream>
#include <new>
#include <stdexcept>
#include <string>

#include "wezel.h"
#include "lista.h"
#include "puzzle.h"


using namespace std;
void Test();

main()
{
    int test;
    cout<<"Jesli chcesz przetestowac, liste wybierz 1"<<endl;
    cin>>test;
    if(test==1)
    {
        Test();
    }
    string str1;
    string str2;
    bool solved=false;
    cout << "PUZZLE" << endl << endl;
    cout << "Solution:      ";
    cin >> str1;
    cout << "Initial value: ";
    cin >> str2;
    if(str1.length()!=str2.length())
    {
        cout<<"Bad size";
    }
    else
    {
         Puzzle PUZZLE(str1.c_str(), str2.c_str());
         while(1)
         {
            cout << "ANAGRAM PUZZLE" << endl;
            PUZZLE.display();
            cout << endl << endl;
            if(PUZZLE.isSolved())
            {
                cout<<"Puzle rozwiazne!"<<endl;
                break;
            }
            cout << "L - shift left." << endl;
            cout << "S - swap ends." << endl<<endl;
            cout << "Choose activity: ";
            cin >> str1;
            if (str1=="L" || str1=="l")
                PUZZLE.shiftLeft();
            else if (str1=="S" || str1=="s")
            {
                PUZZLE.swapEnds();
            }
            else
            {
                cout << "Incorrect instruction. " << endl;
            }
            if(PUZZLE.isSolved())
            {
                cout<<"Puzle rozwiazne!"<<endl;
                break;
            }
        }
    }
}

void Test()
{
    List<string> pList;
    char znak;
    string nowa;
    while(1)
    {
        cout<<"Testowanie listy"<<endl<<endl;
        cout<<"+ wloz do listy element x za kurorem."<<endl;
        cout<<"- usun element na pozycji kursora."<<endl;
        cout<<"= wymien element na pozycji kursora  na element x."<<endl;
        cout<<"@ wyswietl element na danej pozycji kursora."<<endl;
        cout<<"N  idz do nastêpnego elementu."<<endl;
        cout<<"P idz do poprzedniego  elementu ."<<endl;
        cout<<"< idz na pocz¹tek listy."<<endl;
        cout<<"> idz na koniec listy ."<<endl;
        cout<<"E czy lista jest pusta?."<<endl;
        cout<<"F czy lista jest pe³na?."<<endl;
        cout<<"C wyczysc  listê."<<endl;
        cout<<"Q wyjdz z programu."<<endl;

        cin>>znak;
        try
        {
            if(znak=='+')
            {
                cout<<"Podaj element, ktory chcesz wprowadzic do listy."<<endl;
                cin>>nowa;
                pList.insert(nowa);
                cout<<"Element "<<nowa<<" zostal dodany do listy"<<endl;
            }
            else if(znak=='-')
            {
                pList.remove();
                cout<<"Element na pozycji kursora zostal usuniety"<<endl;
            }
            else if(znak=='=')
            {
                cout<<"Podaj element, na ktory chcesz wymienic element listy."<<endl;
                cin>>nowa;
                pList.replace(nowa);
                cout<<"Element "<<nowa<<" zostal dodany do listy"<<endl;
            }
            else if(znak=='@')
            {
                cout<<"Element na pozycji kursora: "<<pList.getCursor()<<endl;
            }
            else if (znak=='N')
            {
                pList.gotoNext();
                cout << "Kursor zostal przesuniety na nastepna pozycje" << endl;
            }
            else if (znak=='P')
            {
                pList.gotoPrior();
                cout << "Kursor zostal przesuniety na poprzednia pozycje." << endl;
            }
            else if (znak=='<')
            {
                pList.gotoBeginning();
                cout << "Kursor zostal przesuniety na pierwsza pozycje."<< endl;
            }
            else if (znak=='>')
            {
                pList.gotoEnd();
                cout << "Kursor zostal przesuniety na ostatnia pozycje." << endl;
            }
            else if (znak=='E')
            {
                if (pList.isEmpty())
                    cout << "Lista jest pusta." << endl;
                else
                    cout << "Lista nie jest pusta." << endl;
            }
            else if (znak=='F')
            {
                if (pList.isFull())
                    cout << "Lista jest pelna." << endl;
                else
                    cout << "Lista nie jest pelna." << endl;
            }
            else if (znak=='C')
            {
                pList.clear();
                cout << "Lista zostala wyczyszczona."  << endl;
            }
            else if (znak=='S')
            {
                cout << "Lista: " << endl;
                pList.showStructure();
                cout << endl;
            }
            else if (znak=='Q')
            {
                cout << "Testowanie listy zakonczylo sie." << endl;
                break;
            }
            else
            {
                cout << "Nieznane polecenie, sporobuj jeszcze raz." << endl << endl;
            }
        }
        catch(bad_alloc &ba)
            {
                cerr<<"Blad pamieci!"<<ba.what()<<"\n";
            }
        catch(logic_error &e)
            {
                cerr<<"Pusta lista! "<<e.what()<<"\n";
            }
    }
}
