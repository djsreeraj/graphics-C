#include<stdio.h>
//#include "BOUNDARY.c"
#include<conio.h>
#include<graphics.h>
void main(){
     //
	void floodFill(int,int,int,int);
	void boundaryFill( int,int,int,int);
	int gd = DETECT,gm;
	int x,y,rad,old,fill;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	printf("Enter the coordinates:");
	scanf("%d",&x);
	scanf("%d",&y);
	printf("Enter the radius:");
	scanf("%d",&rad);
	setcolor(1);
	circle(x,y,rad);

	printf("Enter the color:");
	scanf("%d",&old);

	boundaryFill(x,y,old,1);

	printf("Enter the new color:");
	scanf("%d",&fill);

	floodFill(x,y,fill,old);
	getch();

}

void floodFill(int x, int y, int fill, int old){
	if(getpixel(x,y)==old){
		setcolor(fill);
		putpixel(x,y,fill);
		floodFill(x+1,y,fill,old);
		floodFill(x-1,y,fill,old);
		floodFill(x,y+1,fill,old);
		floodFill(x,y-1,fill,old);
	}
}
void boundaryFill(int x, int y, int fill, int boundary){

	int current;
	current = getpixel(x,y);
	if((current!=boundary) && (current!=fill)){
		setcolor(fill);
		putpixel(x,y,fill);
		boundaryFill(x+1,y,fill,boundary);
		boundaryFill(x-1,y,fill,boundary);
		boundaryFill(x,y+1,fill,boundary);
		boundaryFill(x,y-1,fill,boundary);
	}
}
