#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main(){
	void boundaryFill(int,int,int,int);
	int gd =DETECT,gm;
	int x,y,rad;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	printf("Enter the coordinates:");
	scanf("%d",&x);
	scanf("%d",&y);
	printf("Enter the radius:");
	scanf("%d",&rad);
	setcolor(3);
	circle(x,y,rad);
	boundaryFill(x,y,4,3);
	getch();
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


