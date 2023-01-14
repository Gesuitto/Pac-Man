#include <ctime>
#include<locale>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include<iostream>
#include <future>
#include <chrono>
#include <fstream>
#include<stdlib.h>
#include <io.h>
#include <fcntl.h>
using namespace std;

char grid [23][49] = {
	'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',' ',' ',' ','+',' ',' ',' ','+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',
	'|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',
	'|',' ','.',' ','+','-','-','-','-','-','+',' ',' ',' ','+','-','-','-','-','-','+',' ','.',' ','|',' ','.',' ','+','-','-','-','-','-','+',' ','.',' ','+','-','-','-','-','-','+',' ','.',' ','|',
	'|',' ','.',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ','.',' ','|',' ','.',' ','|',' ',' ',' ',' ',' ','|',' ','.',' ','|',' ',' ',' ',' ',' ','|',' ','.',' ','|',
	'|',' ','.',' ','+','-','-','-','-','-','+',' ',' ',' ','+','-','-','-','-','-','+',' ','.',' ','|',' ','.',' ','+','-','-','-','-','-','+',' ','.',' ','+','-','-','-','-','-','+',' ','.',' ','|',
	'|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',
	'|',' ','.',' ','-','-','-','-','-','-','-',' ',' ',' ','|',' ',' ',' ','-','-','-','-','-','-','+','-','-','-','-','-','-',' ','.',' ','|',' ','.',' ','-','-','-','-','-','-','-',' ','.',' ','|',
	'|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',   
	'+','-','-','-','-','-','-','-','-','-','+',' ','.',' ','+','-','-','-','-','-','-',' ',' ',' ','|',' ',' ',' ','-','-','-','-','-','-','+',' ','.',' ','+','-','-','-','-','-','-','-','-','-','+',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','.',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','.',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	'-','-','-','-','-','-','-','-','-','-','+',' ','.',' ','|',' ',' ',' ','+','-','-','-','-','-',' ','-','-','-','-','-','+',' ',' ',' ','|',' ','.',' ','+','-','-','-','-','-','-','-','-','-','-',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	'-','-','-','-','-','-','-','-','-','-','+',' ','.',' ','|',' ',' ',' ','+','-','-','-','-','-',' ','-','-','-','-','-','+',' ',' ',' ','|',' ','.',' ','+','-','-','-','-','-','-','-','-','-','-',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','.',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','.',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	'+','-','-','-','-','-','-','-','-','-','+',' ','.',' ','|',' ',' ',' ','-','-','-','-','-','-','+','-','-','-','-','-','-',' ',' ',' ','|',' ','.',' ','+','-','-','-','-','-','-','-','-','-','+',
	'|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',
	'|',' ','.',' ','-','-','-','-','-','-','+',' ','.',' ','-','-','-','-','-','-','-',' ','.',' ','|',' ','.',' ','-','-','-','-','-','-','-',' ','.',' ','+','-','-','-','-','-','-',' ','.',' ','|',
	'|','.',' ','.',' ','.',' ','.',' ','.','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ',' ',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','|',
	'+','-','-','-','-','-','-',' ','.',' ','|',' ','.',' ','|',' ','.',' ','-','-','-','-','-','-','-','-','-','-','-','-','-',' ','.',' ','|',' ','.',' ','|',' ','.',' ','-','-','-','-','-','-','+',
	'|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',
	'|',' ','.',' ','-','-','-','-','-','-','-','-','-','-','+','-','-','-','-','-','-',' ','.',' ','|',' ','.',' ','-','-','-','-','-','-','+','-','-','-','-','-','-','-','-','-','-',' ','.',' ','|',
	'|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','.',' ','|',
	'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',' ',' ',' ','+',' ',' ',' ','+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',
};

class basic_entity {//classe base per pacman e fantasmi
	protected:
	char shape;
	int xpos;
	int ypos;	
	
	public:
	basic_entity(): shape('c'), xpos(13), ypos(15) {};
	int get_ypos () {
		return ypos;
	}
	int get_xpos () {
		return xpos;
	}
	
};
class pac_man : public basic_entity {
	protected: 	//  ᴖ  ᴗ  ᴐ  c
	int punteggio=0; 
	public:
	pac_man() : basic_entity() {};
	
	void eliminascia(char);
	//void forma (char);
	int controllomangiato();
	void controllomuro(char&);
    void continuo(char,int,int);
    void print ();
};

void pac_man::continuo(char mossa, int xx, int yy){//serve per far continuare pacman anche se non si inserisce la mossa
	if(mossa=='w'){
		this->xpos--;
		this->shape='U';
		grid[xx][yy]=' ';//elimina la scia di pacman
	}
    if(mossa=='a') {
        this->ypos--;
		this->shape=']';
		grid[xx][yy]=' ';//elimina la scia di pacman	
	}
    if(mossa=='s') {
        this->xpos++;
		this->shape='^';
		grid[xx][yy]=' ';//elimina la scia di pacman	
	}
    if(mossa=='d') {
		this->ypos++;
		this->shape='c';
		grid[xx][yy]=' ';//elimina la scia di pacman
	}
	this->controllomuro(mossa);
}

int pac_man::controllomangiato() {//controlla quando pacman pangia un punto
	if (grid[this->xpos][this->ypos]=='.') {//se mangia il punto lo sostituisce con uno spazio
		grid[this->xpos][this->ypos]=' ';
		this->punteggio++;
	}
	return this->punteggio;
}

void pac_man::controllomuro(char& a){//se pacman è diverso dallo spazio o dal punto vuol dire che è per forza su un bordo
	if (grid[this->xpos][this->ypos]=='+' || grid[this->xpos][this->ypos]=='|'||grid[this->xpos][this->ypos]=='-')
		switch (this->shape) {
			case 'U':
				this->xpos++;
				break;
			case ']':
				this->ypos++;
				break;
			case '^':
				this->xpos--;
				break;
			case 'c':
				this->ypos--;
				break;
}
}

/*char pac_man::mossa() {//legge la mossa inserita dall'utente
    char a;
    if (a=(char)_getch())
        return a;
}*/

/*void pac_man::forma (char a) {//modifica la forma di pacman in base alla mossa
        switch (a) {
            case 'w':
				this->shape='ᴗ'; //u+1D55
            case 'a':					
				this->shape='ᴐ'; //u+1D53
            case 's':
				this->shape='\u001D54';  //u+1D54
            case 'd':
            	this->shape='c'; 
        }
}*/

void pac_man::print() {//stampa la matrice
    grid[this->xpos][this->ypos]=this->shape;//inserisce pacman nella matrice
    for (int i=0; i<23; i++) {
		for (int j=0; j<49; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}	
	cout<<flush;
}

//function colors
void SetColor(short Color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,Color);
}

char imossa(){
	char mossa;
	if(mossa=(char)_getch())
	return mossa;
	return mossa;
}

int main () {
	// https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
	pac_man ut;
	char direzione='d';
	setlocale(LC_ALL,"");
	
    int x=ut.get_xpos();
    int y=ut.get_ypos();
	std::ios_base::sync_with_stdio(false); // Rompe la sincronicità dell'I/O
	while(true)
    {
	    auto input = std::async(std::launch::async, imossa);
		while (input.wait_for(0.2s) != std::future_status::ready) {
            ut.continuo(direzione, ut.get_xpos(), ut.get_ypos());
            //ut.forma(direzione);
            ut.controllomangiato();
			cout << "\x1b[2J\x1b[1;1H";
            ut.print();
            //system("cls");
		}
		direzione=input.get();
 	}
 	
	return 0;
}