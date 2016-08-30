#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void midpointline(int,int,int,int);
int main(){
	int gd = DETECT,gm=0;
	int xa,xb,ya,yb;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	clrscr();
	printf("Enter the coordinates:\n");
	scanf("%d",&xa);
	scanf("%d",&ya);
	scanf("%d",&xb);
	scanf("%d",&yb);
	midpointline(xa,ya,xb,yb);
	getch();
	closegraph();
	return 0;
}

void midpointline(int x0, int y0, int x1,int y1){
	int x,y,d,dx,dy,incre,incrne;
	dx= x1-x0;
	dy= y1-y0;
	d = 2*dy-dx;
	incre = 2*dy;
	incrne= 2*(dy-dx);
	x=x0;
	y=y0;
	putpixel(x,y,1);
	while(x<x1){
		if(d<0){
			d+=incre;
			x++;
		}
		else{
			d+=incrne;
			x++;
			y++;
		}
		putpixel(x,y,1);
	}
}
