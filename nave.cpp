#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

using namespace std;

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void hide_coursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 50;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &info);
}

void pintar_limites(){
	for(int i=2;i<78; i++){
		gotoxy(i,3);
		printf("%c",205);
		gotoxy(i,33);
		printf("%c",205);
	}
	
	for(int i=4;i<33;i++){
		gotoxy(2,i);
		printf("%c",186);
		gotoxy(77,i);
		printf("%c",186);
	}
	
	gotoxy(2,3); printf("%c",201);
	gotoxy(2,33); printf("%c",200);
	gotoxy(77,3); printf("%c",187);
	gotoxy(77,33); printf("%c",188);
}

class Nave{
	int x, y;
	int corazones;
	public:
		Nave(int _x, int _y, int _corazones);
		void pintar();
		void borrar();
		void mover();
		void pintar_corazones();
};

Nave::Nave(int _x, int _y, int _corazones){
	x=_x;
	y=_y;
	corazones = _corazones;
}

void Nave::pintar(){
	gotoxy(x, y);
	printf("  %c",30);
	gotoxy(x, y+1);
	printf(" %c%c%c",40,207,41);
	gotoxy(x, y+2);
	printf("%c%c %c%c",30,190,190,30);
	
}

void Nave::borrar(){
	gotoxy(x, y);
	printf("     ");
	gotoxy(x, y+1);
	printf("     ");
	gotoxy(x, y+2);
	printf("     ");
}

void Nave::mover(){
	if(kbhit()){
		char tecla = getch();
		borrar();
		if(tecla == IZQUIERDA && x > 3){	x--;	}
		if(tecla == DERECHA && x+6 < 77){	x++;	}
		if(tecla == ARRIBA && y>4){	y--;	}
		if(tecla == ABAJO && y+3 < 33){		y++;	}
		pintar();
		pintar_corazones();
	}
}

void Nave::pintar_corazones(){
	gotoxy(64,2);
	printf("Salud");
	gotoxy(70,2);
	printf("     ");
	for(int i=0; i<corazones;i++){
		gotoxy(70+i,2);
		printf("%c",3);
	}
}


int main(){
	hide_coursor();
	pintar_limites();
	Nave nave = Nave(7,7,3);
	nave.pintar();
	bool game_over = false;
	while(!game_over){
		nave.mover();
		Sleep(30);
	}
	return 0;
}








