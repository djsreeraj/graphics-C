#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
FILE *fp;

int main(){
	int gd=DETECT,gm=0;
	int xa,xb,ya,yb;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	clrscr();
	printf("Enter the End Points:");
	scanf("%d",&xa);
	scanf("%d",&ya);
	scanf("%d",&xb);
	scanf("%d",&yb);

	ddaline(xa,ya,xb,yb);
	getch();
	closegraph();
	return 1;
}
int ddaline(int x1,int y1,int x2,int y2){
	int dx,dy,i;
	float x,y,xinc,yinc;
	int step,k;
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	fp=fopen("Result.txt","w");
	if(dx==0){
		for(i=y;i<y2;i++){
			putpixel(x1,i,4);
			fprintf(fp,("%d%d"),x1,i);
		}
	}
	else if(dy==0){
		for(i=x;i<x2;i++){
			putpixel(i,y1,4);
			fprintf(fp,("%d%d"),i,y1);
		}
	}
	else{
		if(dx>dy){
			step=dx;
			k=y1;
		}
		else{
			step=dy;
			k=x1;
		}
		xinc=dx/step;
		yinc=dy/step;
		for(i=k;i<=step;i++){
			x=x+xinc;
			y=y+yinc;
			putpixel(floor(x),floor(y),5);
		}
	}
	return 0;
}

