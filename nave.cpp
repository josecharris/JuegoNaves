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

int main(){
	hide_coursor();
	int x = 10,	y = 10;
	gotoxy(x,y);
	cout<<"*"<<endl;
	bool game_over = false;
	while(!game_over){
		if(kbhit()){
			char tecla = getch();
			gotoxy(x,y);
			cout<<" "<<endl;
			if(tecla == IZQUIERDA){	x--;	}
			if(tecla == DERECHA){	x++;	}
			if(tecla == ARRIBA){	y--;	}
			if(tecla == ABAJO){		y++;	}
			gotoxy(x,y);
			cout<<"*"<<endl;
		}
		Sleep(30);
	}
	return 0;
}
