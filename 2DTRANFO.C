#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main(){
	void transform(int,int,int,int,int,int,int);

	void triangle(int,int,int,int,int,int);
	int gd = DETECT,gm;
	int x1,x2,x3,y1,y2,y3,choice,repeat;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	printf("Enter the coordinates:");
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	setcolor(3);
	triangle(x1,y1,x2,y2,x3,y3);
      //	line(x1,y1,x2,y2);
      //	line(x2,y2,x3,y3);
      //	line(x3,y3,x1,y1);

	do{
		printf("\n\n......Select Choice....\n");
		printf("...1...TRANSLATION..\n...2...ROTATION..\n...3...SCALING...\n");
		scanf("%d",&choice);
		transform(x1,y1,x2,y2,x3,y3,choice);
		repeat=0;
		printf("\nEnter 1 to repeat...:");
		scanf("%d",&repeat);

	}while(repeat==1);

	getch();
}

void triangle(int x1,int y1,int x2,int y2, int x3,int y3){
	printf("\n.................Plotting.....................\n");
	printf("%d,%d,%d,%d,%d,%d",x1,x2,y1,y2,x3,x3);
	setcolor(3);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);

}

void transform(int x1,int y1,int x2,int y2, int x3,int y3,int choice){

	int nx1,ny1,nx2,ny2,nx3,ny3,tx,ty;
	if(choice==1){
		printf("\nEnter translation factor:");
		scanf("%d%d",&tx,&ty);
		printf("\n\ntranslating.....\n");
		nx1 = x1+tx;
		ny1 = y1+ty;
		nx2 = x2+tx;
		ny2 = y2+ty;
		nx3 = x3+tx;
		ny3 = y3+ty;
		triangle(nx1,ny1,nx2,ny2,nx3,ny3);

	}

	else if(choice==2){
		float angle;
		float t;
		printf("\nEnter rotation angle:");
		scanf("%f",&angle);
		printf("\n.....angle...=%f\n",angle);
		t = 3.14*(angle/180);
		printf("\n......t...=%f\n",t);
		nx1 =  abs(x1*cos(t) - y1*sin(t));
		ny1 =  abs(x1*sin(t) + y1*cos(t));
		nx2 =  abs(x2*cos(t) - y2*sin(t));
		ny2 =  abs(x2*sin(t) + y2*cos(t));
		nx3 =  abs(x3*cos(t) - y3*sin(t));
		ny3 =  abs(x3*sin(t) + y3*cos(t));

		printf("\n\rotating......\n");
		printf("%d,%d,%d,%d,%d,%d",nx1,nx2,ny1,ny2,nx3,nx3);
		triangle(nx1,ny1,nx2,ny2,nx3,ny3);


	}

	else if(choice==3){
		float sx,sy;
		printf("\nEnter scanling factor:");
		scanf("%f%f",&sx,&sy);
		nx1 = abs(x1*sx);
		ny1 = abs(y1*sy);
		nx2 = abs(x2*sx);
		ny2 = abs(y2*sy);
		nx3 = abs(x3*sx);
		ny3 = abs(y3*sy);

		printf("\n\ scaling.....\n");


		triangle(nx1,ny1,nx2,ny2,nx3,ny3);
	}

	else{
		printf("\nWrong choice");
		exit(0);
	}

}

