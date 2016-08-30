#include<graphics.h>
#include<conio.h>
int main(){
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	getch();
	closegraph();
	return 0;
}
