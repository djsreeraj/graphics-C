#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void CohenSutherland(double,double,double,double,double,double,double,double);
typedef unsigned int OutCode;
enum{ TOP=0x1, BOTTOM=0x2 , RIGHT=0x4,LEFT=0x8};
OutCode ComOutCode(double,double,double,double,double,double);
void main(){
	int gd = DETECT,gm;
	double xa,xb,ya,yb,xmin,ymin,xmax,ymax;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	printf("\nEnter the coordinates:");
	scanf("%lf",&xa);
	scanf("%lf",&ya);
	scanf("%lf",&xb);
	scanf("%lf",&yb);
	printf("\nEnter the min & max coordinates:");
	scanf("%lf",&xmin);
	scanf("%lf",&ymin);
	scanf("%lf",&xmax);
	scanf("%lf",&ymax);
	setcolor(4);
	rectangle(xmin,ymin,xmax,ymax);
	setcolor(5);
	line(xa,ya,xb,yb);
	getch();
	clrscr();
	setcolor(4);
	rectangle(xmin,ymin,xmax,ymax);
	CohenSutherland(xa,ya,xb,yb,xmin,ymin,xmax,ymax);
	getch();
	closegraph();


}
void CohenSutherland(double x0,double y0,double x1,double y1,double xmin,double ymin,double xmax,double ymax){
	OutCode OutCode0,OutCode1,OutCodeOut;
	int value;
	int accept = 0, done = 0;
	OutCode0=ComOutCode(x0,y0,xmin,xmax,ymin,ymax);
	OutCode1=ComOutCode(x1,y1,xmin,xmax,ymin,ymax);
	do{
		if(OutCode0==0 && OutCode1==0){  //both inside clipng
			accept =1;
			done=1;
		}
		else if(OutCode0 & OutCode1){
			done =1;
		}
		else{
			double x,y;
			OutCodeOut = OutCode0?OutCode0:OutCode1;

			if(OutCodeOut & TOP){
				x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
				y=ymax;
			}
			else if(OutCodeOut & BOTTOM){
				x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
				x=xmax;
			}
			else if(OutCodeOut & RIGHT){
				y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
				x=xmin;
			}
			else{
				y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
				x=xmin;
			}
			if(OutCodeOut==OutCode0){
				x0=x;
				y0=y;
			}
			else{
				x1=x;
				y1=y;
				OutCode1=ComOutCode(x1,y1,xmin,xmax,ymin,ymax);
			}

		}

	}while(done==0);
	if(accept){
		setcolor(2);
		line(x0,y0,x1,y1);
	}
}

OutCode ComOutCode(double x, double y, double xmin, double xmax, double ymin, double ymax){
	OutCode code=0;
	if(y>ymax)
		code |= TOP;
	else if(y<ymin)
		code |= BOTTOM;
	if(x>xmax)
		code |= RIGHT;
	else if(x<xmin)
		code |= LEFT;
	return code;
}