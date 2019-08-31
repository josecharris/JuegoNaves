#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define LETRA_A 97

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
	int vida;
	public:
		Nave(int _x, int _y, int _corazones, int _vidas);
		void pintar();
		void borrar();
		void mover();
		void pintar_corazones();
		void morir();
};

Nave::Nave(int _x, int _y, int _corazones, int _vidas){
	x=_x;
	y=_y;
	corazones = _corazones;
	vida = _vidas;
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
	printf("        ");
	gotoxy(x, y+1);
	printf("        ");
	gotoxy(x, y+2);
	printf("        ");
}

void Nave::mover(){
	if(kbhit()){
		char tecla = getch();
		borrar();
		if(tecla == IZQUIERDA && x > 3){	x--;	}
		if(tecla == DERECHA && x+6 < 77){	x++;	}
		if(tecla == ARRIBA && y>4){	y--;	}
		if(tecla == ABAJO && y+3 < 33){		y++;	}
		if(tecla == LETRA_A){		corazones--;	}
		pintar();
		pintar_corazones();
	}
}

void Nave::pintar_corazones(){
	gotoxy(50,2);
	printf("Vidas %d", vida);
	gotoxy(64,2);
	printf("Salud");
	gotoxy(70,2);
	printf("     ");
	for(int i=0; i<corazones;i++){
		gotoxy(70+i,2);
		printf("%c",3);
	}
}

void Nave::morir(){
	if(corazones==0){
		borrar(); //BORRA NAVE
		gotoxy(x,y);   printf("   **      ");
		gotoxy(x,y+1); printf("  ****     ");
		gotoxy(x,y+2); printf("   **      ");
		Sleep(200);
		borrar();
		gotoxy(x,y);   printf(" * ** *");
		gotoxy(x,y+1); printf("  **** ");
		gotoxy(x,y+2); printf(" * ** *");
		Sleep(200);
		borrar();
		vida--;
		corazones=3;
		pintar_corazones();
		pintar();
	}
}

class Asteroide{
	int x,y;
	public:
		Asteroide(int _x,int _y);
		void pintar();
		void mover();
		
};

Asteroide::Asteroide(int _x, int _y){
	x = _x;
	y = _y;
}

void Asteroide::pintar(){
	gotoxy(x,y);
	printf("%c",184);
}

void Asteroide::mover(){
	gotoxy(x,y); printf(" ");
	y++;
	if(y>32){
		x = rand()%71 + 4;
		y = 4;
	}
	pintar();
}

int main(){
	hide_coursor();
	pintar_limites();
	Nave nave = Nave(7,7,3,3);
	nave.pintar();
	bool game_over = false;
	Asteroide asteroide(10, 4);
	while(!game_over){
		asteroide.mover();
		nave.morir();
		nave.mover();
		Sleep(30);
	}
	return 0;
}








