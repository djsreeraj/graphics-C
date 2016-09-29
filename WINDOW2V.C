#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main(){
	int gd = DETECT,gm;
	int x1,x2,x3,y1,y2,y3,xmin,ymin,xmax,ymax,umin,vmin,umax,vmax;
	float sx,sy,nx1,ny1,nx2,ny2,nx3,ny3;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	printf("Enter the size of window port:");
	scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
	setcolor(4);
	rectangle(xmin,ymin,xmax,ymax);
	printf("Enter the coordinates of the triangle:");
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	setcolor(4);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	printf("Enter the size of the viewport:");
	scanf("%d%d%d%d",&umin,&vmin,&umax,&vmax);
	setcolor(4);
	rectangle(umin,vmin,umax,vmax);
	sx=(umax-umin)/(xmax-xmin);
	sy=(vmax-vmin)/(ymax-ymin);
	nx1=umin+(x1-xmin)*sx;
	ny1=vmin+(y1-ymin)*sy;
	nx2=umin+(x2-xmin)*sx;
	ny2=vmin+(y2-ymin)*sy;
	nx3=umin+(x3-xmin)*sx;
	ny3=vmin+(y3-ymin)*sy;
	line(nx1,ny1,nx2,ny2);
	line(nx2,ny2,nx3,ny3);
	line(nx3,ny3,nx1,ny1);
	getch();
	closegraph();
}

