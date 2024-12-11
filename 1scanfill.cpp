//#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

class point
{
	public:
	int x,y;
};
class poly : public point
{
	public:
	point p[20];
	int inter[20],x,y;
	int v,xmin,ymin,xmax,ymax;
	public:
	int c;
	void read();
	void calcs();
	void display();
	void ints(float);
	void sort(int);
};

//function for reading the data of the vertices using the array 
void poly::read()
{
	cout<<"\n Scan Fill Algorithm ";
	cout<<"\n Enter Number Of vertices Of polygon";
	cin>>v;
	if(v>2)
	{
		int i;
		for(i=0;i<v;i++) //to accept the verices one after another
		{
			cout<<"\n Enter Co-ordinate no. "<<i+1<<" : ";
			cout<<"\n\t x"<<(i+1)<<"=";
			cin>>p[i].x;
			cout<<"\n\t y"<<(i+1)<<"=";
			cin>>p[i].y;
		}
		p[i].x = p[0].x;
		p[i].y = p[0].y;
		xmin=xmax=p[0].x;
		ymin=ymax=p[0].y;
	}
	else
	cout<<"\n Enter Valid No. of Vertices..";
}
//function to Calculate
void poly::calcs()
{
	for(int i=0;i<v;i++)
	{
		if(xmin>p[i].x)
			xmin=p[i].x;
		if(xmax<p[i].x)
			xmax=p[i].x;
		if(ymin>p[i].y)
			ymin=p[i].y;
		if(ymax<p[i].y)
			ymax=p[i].y;
	}
}
//Function To Display The Menu
void poly::display()
{
	int ch1;// Taking the Chooice of Operation
	char ch='y';
	float s,s2;
	//using do while loop
	do
	{
		cout<<"\n\n MENU: ";
		cout<<"\n\n\t 1. Scan line Fill ";
		cout<<"\n\n\t 2. Exit ";
		cout<<"\n\n Enter Your Choice: ";
		cin>>ch1;
		switch(ch1)
		{
			case 1:
				s=ymin+0.01;
				delay(100);
				cleardevice();
				while(s<=ymax)
				{
					ints(s);
					sort(s);
					s++;
				}
				break;
			case 2:
				exit(0);
		}
		cout<<"Do you Want To continue?: ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
//Input for PolyGon Scan Line 
void poly::ints(float z)
{
	int x1,x2,y1,y2,temp;
	c=0;
	for(int i=0;i<v;i++)
	{
		x1=p[i].x;
		y1=p[i].y;
		x2=p[i+1].x;
		y2=p[i+1].y;
		if(y2<y1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if(z<=y2 && z>=y1)
		{
			if((y1-y2)==0)
				x=x1;
			else
			{
				x=((x2-x1)*(z-y1)/(y2-y1));
				x=x+x1;
			}
			if(x<=xmax && x>= xmin)
			inter[c++]=x;
		}
	}
}
//Sorting The Scan Lines
void poly::sort(int z) // sorting
{
	int temp,j,i;

	for(i=0;i<v;i++)
	{
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
	}
	delay(100);
	for(i=0; i<c;i+=2)
	{
		delay(100);
		line(inter[i],z,inter[i+1],z);
	}
}


int main()
{
	int gd=DETECT,gm;
	int cl;
	initgraph(&gd,&gm,NULL);//opening Graph
	cleardevice();
	poly x;
	x.read();
	x.calcs();
	cleardevice();
	cout<<"\n\tEnter The Color You Want :(In Range 0 To 15 )->"; //selecting color
	cin>>cl;
	setcolor(cl);
	x.display();
	closegraph(); //closing graph
	getch();
	return 0;
}
