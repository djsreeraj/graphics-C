#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void midpointEllipse(float,float);
void ellipsePoints(float,float,int);
int main(){
   int gd = DETECT,gm;
   float a,b;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   clrscr();
   printf("Enter the axis\n");
   scanf("%f",&a);
   scanf("%f",&b);
   midpointEllipse(a,b);
   getch();
   closegraph();
   return 0;
}

void midpointEllipse(float a,float b){
     float d2;
     float x=0;
     float y=b;
     int v=1;
     float d1 = b*b - (a*a*b)+(0.25*a*a);
     ellipsePoints(x,y,v);
     while((a*a*(y-0.5))>(b*b*(x+1))){
	if(d1<0)
		d1+=b*b*(2*x+3);

	else{
		d1+=(b*b*(2*x+3)+(a*a*((-2*y)+2)));
		y--;
	}
	x++;
	ellipsePoints(x,y,v);
     }
     d2=(b*b*(x+0.5)*(x+0.5))+(a*a*((y-1)*(y-1)))-(a*a*b*b);
     while(y>0){
	if(d2<0){
		d2+=b*b*((2*x)+2)+a*a*((-2*y)+3);
		x++;
	}
	else
		d2+=a*a*((-2*y)+3);
		y--;
		ellipsePoints(x,y,v);
	}
     }

void ellipsePoints(float x,float y,int v){
	int a=getmaxx()/2;
	int b = getmaxy()/2;
	putpixel(a+x,b+y,v);
	putpixel(a+x,b-y,v);
	putpixel(a-x,b-y,v);
	putpixel(a-x,b+y,v);
}