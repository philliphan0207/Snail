#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void init();
void gLoop();
int keyControl();
void title();
int menu();
int snailNum();
void MAP(int*,int*,int*,int*,int*,int*);
void move(int*, int*, int, int);
void move2(int*, int*, int, int);
void move3(int*, int*, int, int);
int after();


void gotoxy(int, int);
void setColor();

int snail;

void setColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

char map[9][300] = { //´ÞÆØÀÌ a, b, c
	{"111111111111111111111111111111111111"},
	{"1000000000000000000000000000000000000000000000000000000000000000000001"},
	{"100a00000000000000000000000000000000000000000000000000000000000000000F"},
	{"1000000000000000000000000000000000000000000000000000000000000000000001"},
	{"100b00000000000000000000000000000000000000000000000000000000000000000F"},
	{"1000000000000000000000000000000000000000000000000000000000000000000001"},
	{"100c00000000000000000000000000000000000000000000000000000000000000000F"},
	{"1000000000000000000000000000000000000000000000000000000000000000000001"},
	{"111111111111111111111111111111111111"}

};


int main() {
	while (1) {
		int input;
		printf("Input '1' to start : ");
		scanf("%d", &input);
		init();
		title();
		int menuCode = menu();
		if (menuCode == 0) {
			int n = snailNum();	
			if (n == 0) {
				snail = 0;
			}
			else if (n == 4) {
				snail = 1;
			}
			else if (n == 8) {
				snail = 2;
			}
			gLoop();
		}
		else if (menuCode == 1) {
			return 0;
		}
		system("cls");
	}
	return 0;

	int keyCode = keyControl();
}

void gotoxy(int x, int y)

{

	COORD pos = { x,y };
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

int keyControl() {
	char tmp = getch();
	
	if (tmp == 'w') {

		return UP;

	} 
	else if (tmp == 'a'){

		return LEFT;

	}
	else if (tmp == 'd') {
	
		return RIGHT;
	
	}
	else if (tmp == 's') {
	
		return DOWN;
	
	}
	else if (tmp == ' ') {
		
		return SUBMIT;
 
	}

}

void init() {
	system("mode con cols=100 lines=20");
}

void title() {
	setColor(7, 0);
	printf("\n\n\n\n");
	printf("   ###   #    #      #      ###   #     \n");
	printf("  #      ##   #     # #      #    #     \n");
	printf("  ####   #  # #    #####     #    #     \n");
	setColor(8, 0);
	printf("      #  #   ##   #     #    #    #     \n");
	printf("  ####   #    #   #     #   ###   ##### \n");
	setColor(15, 0);
}


int menu() {

	int x = 18;
	int y = 12;
	gotoxy(x - 2, y);
	printf("> °ÔÀÓ½ÃÀÛ");
	gotoxy(x + 2, y + 1);
	printf("Á¾·á");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 13) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 12;
		}



		}
	}
}

void MAP(int* x,int* y,int* x2,int* y2,int* x3,int* y3) {
	system("cls");
	int h, w;
	for (h = 0; h < 9; h++) {
		for (w = 0; w < 300; w++) {
			char tmp = map[h][w];
			if (tmp == '0') {
				printf(" ");
			}
			else if (tmp == '1') {
				printf("¢Ì");
			}
			else if (tmp == 'a') {
				printf("a");
				*x = 3;
				*y = 2;
			}
			else if (tmp == 'b') {
				printf("b");
				*x2 = 3;
				*y2 = 2;
			}
			else if (tmp == 'c') {
				printf("c");
				*x3 = 3;
				*y3 = 2;
			}
			else if (tmp == 'B') {
				printf("B");
			}
			else if (tmp == 'S') {
				printf("S");
			}
			else if (tmp == 'F') {
				printf("F");
			}
		}
		printf("\n");
	}
}

int snailNum() {
	int x = 10;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("	[´ÞÆØÀÌ ¼±ÅÃ]				\n\n");
	gotoxy(x - 2, y);
	printf("> 1¹ø ´ÞÆØÀÌ");
	gotoxy(x, y + 4);
	printf("2¹ø ´ÞÆØÀÌ");
	gotoxy(x, y + 8);
	printf("3¹ø ´ÞÆØÀÌ");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 6) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 6;
		}
		}
	}
}

void gLoop() {
	srand(time(NULL));
	int x, y; // ÁÂÇ¥ ¼±¾ð
	int x2, y2;
	int x3, y3;
	int playing = 1;
	MAP(&x, &y, &x2, &y2, &x3, &y3); // ÁÂÇ¥ Àü´Þ
	int random = rand() % 3;
	while (playing) {
		if(random == 2){
		for (int i = 0; i < 1; ++i) {
			move(&x, &y, 1, 0);
			Sleep(100);
		}
		for (int i = 0; i < 1; ++i) {
			move3(&x3, &y, 1, 0);
			Sleep(100);
		}
		for (int i = 0; i < 1; ++i) {
			move2(&x2, &y, 1, 0);
			Sleep(100);
		}
		}

		if (random == 1) {
			for (int i = 0; i < 1; ++i) {
				move3(&x3, &y, 1, 0);
				Sleep(100);
			}
			for (int i = 0; i < 1; ++i) {
				move(&x, &y, 1, 0);
				Sleep(100);
			}
			for (int i = 0; i < 1; ++i) {
				move2(&x2, &y, 1, 0);
				Sleep(100);
			}
		}

		if (random == 0) {
			for (int i = 0; i < 1; ++i) {
				move2(&x2, &y, 1, 0);
				Sleep(100);
			}
			for (int i = 0; i < 1; ++i) {
				move(&x, &y, 1, 0);
				Sleep(100);
			}
			for (int i = 0; i < 1; ++i) {
				move3(&x3, &y, 1, 0);
				Sleep(100);
			}
		}



	}
}

void move(int* x, int* y, int _x, int _y) {
	char mapObject = map[*y + _y][*x + _x];
	if (mapObject == '0') {

		gotoxy(*x, *y);
		printf(" ");

		gotoxy(*x + _x, *y + _y);
		printf("a");
		
		
	}
	else if (mapObject == 'S') {
		map[*y + _y][*x + _x] = '0';
		gotoxy(*x + _x-1 , *y + _y);
		printf(" ");

		gotoxy(*x + _x - 1, *y + _y - 1);
		printf("½½·Î¿ì..");
	}
	else if (mapObject == 'F') {
		system("cls");
		gotoxy(30, 7);
		printf("1¹ø ´ÞÆØÀÌ ¿ì½Â");
		Sleep(2000);
		int t = after();
		if (t = 1) {
			exit(0);
		}
	}
	
	

	*x += _x;
	*y += _y;
}

void move2(int* x2, int* y2, int _x, int _y) {
	char mapObject2 = map[*y2 + _y + 2][*x2 + _x];
	if (mapObject2 == '0') {

		gotoxy(*x2, *y2 + 2);
		printf(" ");

		gotoxy(*x2 + _x, *y2 + _y + 2);
		printf("b");
	}
	else if (mapObject2 == 'F') {
		system("cls");
		gotoxy(30, 7);
		printf("2¹ø ´ÞÆØÀÌ ¿ì½Â");
		Sleep(2000);
		int t = after();
		if (t = 1) {
			exit(0);
		}
	}

	*x2 += _x;
	*y2 += _y;
}

void move3(int* x3, int* y3, int _x, int _y) {
	char mapObject3 = map[*y3 + _y + 2][*x3 + _x];
	if (mapObject3 == '0') {

		gotoxy(*x3, *y3 + 4);
		printf(" ");

		gotoxy(*x3 + _x, *y3 + _y + 4);
		printf("c");

	}
	else if (mapObject3 == 'F') {
		system("cls");
		gotoxy(30, 7);
		printf("3¹ø ´ÞÆØÀÌ ¿ì½Â");
		Sleep(2000);
		int t = after();
		if (t = 1) {
			exit(0);
		}
	}

	*x3 += _x;
	*y3 += _y;
}



int after() {
	int x = 10;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("	[ °è¼ÓÇÏ½Ã°Ú½À´Ï±î ? ]				\n\n");
	gotoxy(x - 2, y);
	printf("> ¿¹");
	gotoxy(x, y + 4);
	printf("¾Æ´Ï¿ä");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 6) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 6;
		}
		}
	}
}