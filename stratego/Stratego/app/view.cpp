#include "view.h"
#include <iostream>
#include <algorithm>
#include "color.h"
using namespace std;

View::View(Game * g):g_{g}
{

}

void View::displayTitle(){
    cout << "Stratego" << endl;
}
void View::displayState(){
    cout<< "STATE=>"<<g_->getState()<<endl;
}
void View::displayBoard(){

    for(int j = 0; j < 10; j++){

        if(j+1 < 10){
            cout <<WHITE<< " " << (j+1) << "| ";
        }else{
            cout <<WHITE<< (j+1) << "| ";
        }
        for(int i = 0; i < 10; i++){

            if(!g_->getCase(Position{i, j})->isHole()){
                if(g_->getCase(Position{i, j})->getEntity() != nullptr){
                    Entity * e = g_->getCase(Position{i, j})->getEntity();
                    if(e->getOwner() == g_->getCurrentPlayer()){
                        if(g_->getCurrentPlayer()==1){
                            cout<<RED;
                        }
                        else{
                            cout<<BLUE;
                        }
                        cout <<g_->getCase(Position{i, j})->getEntity()->getSymbol() << WHITE << " ";
                    }else{
                        if(g_->getCurrentPlayer()==1){
                            cout<<BLUE;
                        }
                        else{
                            cout<<RED;
                        }
                        cout << " ? " << WHITE;
                    }

                }else{
                    cout <<WHITE<< " X ";
                }
            }else{
                cout << "   " ;

            }
        }

        cout << endl;

    }

    for(int j = 0; j < 2; j++){
        cout <<WHITE<< "    ";
        for(int i = 1; i <= 10; i++){
            if(j == 0){
                cout << "___";
            }else{
                if(i == 9){
                    cout << " "<< i;
                }else{
                    cout << " "<< i << " ";
                }
            }
        }

        cout << endl;

    }
}
string toUpper(string w){
    string u = "";
    for(unsigned i = 0; i < w.length(); i++){

        if(w.at(i) != ' '){
            if(w.at(i)>= 97)
                u += w.at(i)-32;
            else
                u += w.at(i);
        }else{
            u+= ' ';
        }
    }
    return u;
}
bool View:: askChoice(){
    string r = "";
    do {
        displayMessage("Voulez vous chargez le fichier (O/N)");
        cin >> r;
        r=toUpper(r);
    }while(r.at(0) != 'O' && r.at(0) != 'N');
    return r.at(0) == 'O';

}

void View::displayTurn(){
    cout << "Tour du joueur : " << g_->getCurrentPlayer() << endl;
}

void View::displayMessage(std::string m){
    cout << m << endl;
}
void View::clean(){
    system("CLS");
}


string View::askRole(){
    //ROLE r = NONE;
    string role;
    bool retry=true;
    do{
        role = "";
        cin.clear();
        cout << "Marshal =10 -> Spy =1 ;Drapeau =D ; Bombe= B\nRole: " ;
        cin >> role;
        if(role=="d"||role=="b"){
            role = toUpper(role);
            retry=false;
        }
        if (role.compare("10") == 0 ||role == "9"||role == "8"||role == "7"||
            role == "6"||role == "5"||role == "4"||role == "3"||role == "2"||role == "1"){
            retry=false;
        }
    }while(retry);
    return role;
}

void View::displayErreur(std::string m){

    cout <<RED<< m <<WHITE<< endl;
}

Position View::askPosition(){


    int x = 0;
    int y = 0;
    do{
        cout << "Position: (colonne ligne) entre 1 et 10" << endl;
        while(!(cin>>x) || !(cin>>y)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veuillez entrez un nombre " << endl;

        }
        x--;
        y--;
    } while(x < 0 || x >= 10 || y < 0 || y >= 10);


    return Position{x, y};
}

int View::askNumber(string message){

    cout << message;
    int x = 0;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Veuillez entrez un nombre " << endl;
        cout << message;
    }
    return x;
}
void View::displayWinner(){
    cout<<GREEN<<"Le gagnant est " ;

    if(g_->getCurrentPlayer() == 1){
        cout << "2";
    } else {
        cout << "1";
    }


      cout << WHITE << endl;
}




