#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void midpointcircle(int);
void circlepoints(int, int, int);
int main(){
	int gd = DETECT,gm;
	int r;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	clrscr();
	printf("Enter the radius:");
	scanf("%d",&r);
	midpointcircle(r);
	getch();
	closegraph();
	return 0;
}
void midpointcircle(int radius){
	int x=0,v=4;
	int y = radius;
	double d = (5.0/4.0) -radius;
	circlepoints(x,y,v);
	while(y>x){
		if(d<0){
			d+=2.0*x+3.0;
		}
		else{
			d+=2.0*(x-y)+5.0;
			y--;
		}
		x++;
		circlepoints(x,y,x);
	}
}
void circlepoints(int x,int y,int v){
	int a,b;
	a=getmaxx()/2;
	b=getmaxy()/2;
	putpixel(a+x,b+y,v);
	putpixel(a+y,b+x,v);
	putpixel(a+y,b-x,v);
	putpixel(a+x,b-y,v);
	putpixel(a-x,b-y,v);
	putpixel(a-y,b-x,v);
	putpixel(a-y,b+x,v);
	putpixel(a-x,b+y,v);
}
