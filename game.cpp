#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<dos.h>
char *lname[] = {
   "SOLID_LINE",
   "DOTTED_LINE",
   "CENTER_LINE",
   "DASHED_LINE",
   "USERBIT_LINE"
   };
int gdriver = DETECT, gmode, errorcode;
int userpat=1,style,radius=7,radius1=9;
     char stylestr[40];
int x,y,w,z,col,num,p1=0,p2=0,m;
int t1,t2,tp1,tp2,chance=0;
     char ce,ch;
     char pl1[15]={""},pl2[15]={"computer"};

   void window();                                   //global function declaration.
   void board();
   void intro();
   void score();
   void snake();
   void ladder();
   void postion(int p1,int p2);
   void singlemode();
   void doublemode();
   void dicerun(int num)
{
setcolor(12);
setfillstyle(1,12);
bar(447,217,492,245);
setcolor(15);
setfillstyle(1,15);
    if(num==1)
fillellipse(469,231,3,1);
    if(num==2)
    {
	fillellipse(460,231,3,1);  fillellipse(475,231,3,1);
    }
    if(num==3)
    {
fillellipse(455,220,3,1);  fillellipse(467,228,3,1); fillellipse(483,237,3,1);
    }
    if(num==4)
    {
fillellipse(459,225,3,1); fillellipse(479,225,3,1);
fillellipse(459,238,3,1);  fillellipse(479,238,3,1);
    }
    if(num==5)
    {
fillellipse(456,225,3,1); fillellipse(482,225,3,1); fillellipse(456,238,3,1);
fillellipse(482,238,3,1); fillellipse(469,231,3,1);
  }
    if(num==6)
    {
fillellipse(456,225,3,1); fillellipse(482,225,3,1); fillellipse(456,238,3,1);
fillellipse(482,238,3,1); fillellipse(469,225,3,1); fillellipse(469,238,3,1);
    }
}
int modes (void)          // select modes
{
int gdriver = DETECT, gmode, errorcode;
int t=0,i=350,p=1;
   char ch;
	initgraph(&gdriver, &gmode, "");
setcolor(4);    setfillstyle(1,4);
     bar(47,417,553,438);
setfillstyle(SOLID_FILL,14);
bar(55,420,545,435);
outtextxy(335,425,"Press ESC to exit anytime");
outtextxy(75,425,"Enter:select");
outtextxy(190,425,"8:up");
outtextxy(250,425,"2:dowm");
setfillstyle(SOLID_FILL,4);
bar(50,60,550,400);
    for(i=1;i<=60;i++)
    {
       setfillstyle(1,14);
      bar(60,70,getmaxx()-100,390);
setcolor(1);
settextstyle(7,0,5);
outtextxy(70+i,150-i,"SNAKE");
outtextxy(370-i,150-i,"LADDER");
delay(20);
      }
 outtextxy(200,150,"GAME");
	settextstyle(7,0,3);
	outtextxy(200,300,"PRESS ENTER ");
getch();
   for(i=0;i<=100;i++)
   {
setfillstyle(SOLID_FILL,14);
bar(60,70,540,390);
settextstyle(10,0,3);
outtextxy(65+i,90,"GAME");
outtextxy(400-i,90,"MODES");
delay(10);
   }
setlinestyle(0,3,3);
line(160,140,440,140);
   for(i=1;i<70;i++)
   {
setfillstyle(1,14);
bar(80,220,540,360);
settextstyle(1,0,3);
outtextxy(190+i,260,"SINGLE PLAYER");
outtextxy(330-i,290,"DOUBLE PLAYER");
delay(20);
   }
delay(400);
outtextxy(240,260,">");
settextstyle(1,0,3);
outtextxy(100,170,"SELECT MODE");
ch=getch();
   for(t=0;t<=100;t++)
   {
     if((int)ch==50)
     {
setcolor(14);
outtextxy(240,260,">");
setcolor(4);
outtextxy(240,290,">");
      p=2;
     }
     if((int)ch==56)
      {
setcolor(4);
outtextxy(240,260,">");
setcolor(14);
outtextxy(240,290,">");
      p=1;
      }
ch=getch();
      if((int)ch==27) exit(0);
      if((int)ch==13) break;
     }
	bar(100,150,540,350);  outtextxy(160,230,"Player 1"); outtextxy(160,265,"Player 2");
	gotoxy(100,240);
	cout<<"\tPlayer 1:";
	cin.getline(pl1,10);
	cout<<"\tPlayer 2:";
	if(p==1)
	cout<<pl2;
	else if(p==2)
	cin.getline(pl2,10);
	setfillstyle(1,14);
	outtextxy(340,230,pl1);outtextxy(340,265,pl2);delay(1500);
	return(p);
     }
  void clrpos( int p1,int p2)                                                                            // clear position
   {
int i,j,x=72,y=65,w=87,z=80,t=100;
     for(i=1;i<=10;i++)
      {
       for(j=1;j<=10;j++)
	{
	 if(p1==t)
	  {
	if(j%2!=0 && i%2==0)
	  {
	setcolor(3);
	   circle(x,y,6);
	  }
	  else if(i%2!=0 &&j%2==0)
	      {
		setcolor(3);
		circle(x,y,6);
	      }
	  else
	     {
	setcolor(15);
	      circle(x,y,6);
	      }
	  }
	 if(p2==t)
	  {
	if(j%2!=0 && i%2==0)
	  {
	setcolor(3);
	   circle(x,y,6);
	  }
	  else if(i%2!=0 &&j%2==0)
	      {
		setcolor(3);
		circle(x,y,6);
	      }
	  else
	     {
	setcolor(15);
	      circle(x,y,6);
	      }
	  }
	  t--;
	  x+=35;   w+=35;
	}
	y+=40;       z+=40;      x=72;      w=87;
      }
   }
int checkpos(int p)                                //position cheaking.
{
switch(p)
 {
   // snakes
 case 99: sound(10);delay(200);nosound(); return(44);
 case 94: sound(10);delay(200);nosound(); return(72);
 case 79: sound(10);delay(200);nosound(); return(60);
 case 67: sound(10);delay(200);nosound(); return(25);
 case 40: sound(10);delay(200);nosound(); return(18);
   // Ladders
   case 68: sound(10);delay(200);nosound(); return(96);
   case 78: sound(10);delay(200);nosound(); return(97);
   case 51: sound(10);delay(200);nosound(); return(74);
   case 35: sound(10);delay(200);nosound(); return(81);
   case 27: sound(10);delay(200);nosound(); return(59);
   case 6:  sound(10);delay(200);nosound(); return(23);
default:return(p);
 }
}
       void bcreate(int x,int y,int w,int z,int col)
	   {
	setcolor(7);
	    rectangle(x,y,w,z);
	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	    rectangle(x+1,y+1,w,z);
	floodfill(x+5,y+5,8);
	setfillstyle(SOLID_FILL,col);
	    bar(x+5,y+5,w-5,z-5);
	   }
void checkwinner(int p1,int p2)
{
int i;
setfillstyle(SOLID_FILL,1);
bar(420,348,602,394);
setcolor(4);
rectangle(418,346,604,396);
settextstyle(TRIPLEX_FONT,0,1);
 if(p1>=100)
  {
   for(i=100;i<200;i++)
   {
setcolor(i/3);
outtextxy(430,364,"Player 1 won.");
delay(500);
getch(); exit(0);
   }  }
  else if(p2>=100)
  {
  for(i=100;i<200;i++)
   {
setcolor(i/2);
outtextxy(460,364,"Player 2 won.");
delay(500);
getch();exit(0);
   }  }    }
int main(void)
{
   /* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "");
delay(300);
   m=modes();
doublemode();
getch();
closegraph();                        /* clean up */
   return 0;
  }
     void doublemode()                                       //function for game modes.
      {
window();
board();
snake();
ladder();
ch=getch();
       if((int)ch!=27)
	 {
	setfillstyle(SOLID_FILL,1);
	bar(420,348,602,394);
	setcolor(2);
	rectangle(418,346,604,396);
	settextstyle(TRIPLEX_FONT,0,1);
	outtextxy(450,364,"GAME IS ON");
	 }
       do
       {
	setfillstyle(SOLID_FILL,1);
	bar(420,348,602,394);
	setcolor(2);
	rectangle(418,346,604,396);
	settextstyle(TRIPLEX_FONT,0,1);
	outtextxy(450,364,"GAME Is ON");
	postion(p1,p2);
	   tp1=p1;
	   tp2=p2;
	   if(chance%2==0)
	     {
	setfillstyle(SOLID_FILL,4);
	bar(430,415,445,428);
	setfillstyle(SOLID_FILL,11);
	bar(520,415,535,428);
	ce=getch();
	randomize();
	      t1=random(6)+1;
	      if(t1==6)
	      chance--;
	dicerun(t1);
	      if(p1+t1<=100);
	      p1 = checkpos(p1+t1);
	     }
	   else
	     {
	setfillstyle(SOLID_FILL,14);                                   //indicate the chance of player.
	bar(520,415,535,428);
	setfillstyle(SOLID_FILL,11);
	bar(430,415,445,428);
	       if(m==2)
	       {
	ce=getch();
	       if((int)ce==27)
		  {
		exit(0);
		  }}
	randomize();
	       t2=rand()%6+1;
	       if(t2==6)
	       chance--;
	dicerun(t2);
	       if(p2+t2<=100)
		 {
		 p2 = checkpos(p2+t2);
		 }
	      }
	     chance++;
	delay(500);
	clrpos(tp1,tp2);
	postion(p1,p2);
	score();
	checkwinner(p1,p2);
	  }
	while(1);
       }
      void board()             // main box.
     {
int x,y,num=100,j,i,m;
       char cc[3];
      int a=60,b=50,c=95,d=90;
       for(i=1;i<=10;i++)
	 {
	  for(j=1;j<=10;j++)
	     {
	if(j%2!=0 &&i%2==0)
		{  setfillstyle(1,3);
		     bar(a,b,c,d);
		  }
	      else if(i%2!=0&&j%2==0)
		{  setfillstyle(1,3);
		     bar(a,b,c,d);
		  }
		 a=a+35;      c=c+35;
	     }
	      b=b+40;      d=d+40;    a=60;      c=95;
	    }
setfillstyle(1,0);
      x=68;     y=71;      num=100;         m=2;
	for(i=0;i<10;i++)
	  {
	   for(j=0;j<10;j++)
	     {
	      if(m==2)
	       {
		if(j%2)
		setfillstyle(1,0);
		}
	      else
		 {
		  if(!(j%2))
		setfillstyle(1,4);
		 }
	sprintf(cc,"%d",num);
	num--;
	outtextxy(x,y,cc);
	    x+=35;
	    }
	  if(m==3)
	     m=2;
	    else
	    m=3;
	    x=70;
	    y+=40;
	      }               }

void snake()                                        //function for snake.
{
setfillstyle(3,9);
setcolor(1);
setfillstyle(2,3);          /* draw the circle */
    circle(255,350,radius);  circle(252,337,radius);  circle(245,326,radius);
   circle(235,315,radius); circle(222,305,radius);  circle(213,291,radius);
  circle(207,277,radius);  circle(202,264,radius);   circle(199,248,radius);
   circle(195,232,radius);  circle(189,218,radius);   circle(186,204,radius);
     //snake2
   circle(124,80,radius);  circle(129,93,radius);  circle(138,106,radius);
   circle(146,119,radius);  circle(155,132,radius);   circle(169,143,radius);
   circle(182,153,radius);   circle(195,163,radius);   circle(209,173,radius);
   circle(220,183,radius);   circle(225,193,radius);  circle(233,203,radius);
   circle(243,213,radius);   circle(250,223,radius);   circle(261,233,radius);
   circle(270,243,radius);   circle(279,253,radius); circle(283,263,radius);
   //snake 3
    circle(116,170,radius);   circle(110,184,radius);    circle(104,198,radius);
    circle(99,212,radius);  circle(93,226,radius);    circle(83,238,radius);
    //snake 3
    circle(298,86,radius);  circle(307,102,radius);   circle(316,118,radius);
    circle(330,130,radius);  circle(339,146,radius);   circle(354,156,radius);
     //snake 4
    circle(89,324,radius);  circle(97,338,radius);   circle(106,352,radius);
    circle(116,366,radius); circle(128,378,radius);   circle(142,390,radius);
      //heads
setcolor(4); int radius2=4,radius3=2;
     circle(187,190,radius1);  circle(110,70,radius1);  circle(80,310,radius1);
    circle(290,70,radius1);  circle(120,156,radius1);
setcolor(0);
     circle(187,190,radius2);  circle(187,190,radius3);     circle(110,70,radius2);
     circle(110,70,radius3);    circle(290,70,radius2);    circle(290,70,radius3);
     circle(120,156,radius2);   circle(120,156,radius3);   circle(80,310,radius2);
     circle(80,310,radius3);
    }
    void ladder()                                             //  function  for   ladder
    {
setcolor(8);
line(205,430,315,340);   line(225,439,335,348);                // L1
line(190,350,115,223);   line(170,352,98,228);                   //L2
line(240,320,390,96);     line(260,320,406,96);                   //L3
line(140,150,180,60);     line(160,152,198,60);                   //L4
line(395,230,290,145);   line(380,240,275,150);                //L5
}
void window()
{
setfillstyle(1,8);
     bar(0,0,getmaxx()-0,getmaxy()-0);
setcolor(1);
     rectangle(2,2,getmaxx()-2,getmaxy()-2);
setfillstyle(SOLID_FILL,12);
bar(200,4,420,20);
setcolor(6);
rectangle(198,2,423,22);
setcolor(15);
settextstyle(TRIPLEX_FONT,0,1);
outtextxy(210,1,"! SNAKE AND LADDER !");
setlinestyle(style,userpat,3);
strcpy(stylestr, lname[style]);
setfillstyle(1,1);
bar(30,25,610,465);
setcolor(14);
rectangle(28,23,612,467);
setlinestyle(style,userpat,3);
strcpy(stylestr, lname[style]);
setfillstyle(SOLID_FILL,15);
bar(60,50,410,450);
setcolor(15);
rectangle(60,50,410,450);
setcolor(4);
rectangle(60,50,410,450);
setfillstyle(SOLID_FILL,2);
bar(415,50,607,180);
settextstyle(SMALL_FONT,0,4);
setcolor(2);
bcreate(420,56,602,169,9);
setfillstyle(SOLID_FILL,7);
	setcolor(6);
	bar(415,280,607,451);    rectangle(459,79,521,103);  bar(460,80,520,102);
	setcolor(1);
	settextstyle(3,0,1);
	outtextxy(422,80," Hit ENTER  to play");
	bar(460,114,560,116);
	rectangle(469,129,521,151);
	setcolor(4);
	bar(470,130,520,150);
	setcolor(1);
	outtextxy(445,130,"Hit ESC  To Exit");
	bcreate(420,400,505,440,11);
	bcreate(510,400,600,440,11); 
    bcreate(434,306,484,341,0 );
	bcreate(510,306,560,341,0);                        //scoreboard.
	setcolor(2);
	line(497,296,497,342);
	setfillstyle(SOLID_FILL,4);                                  //game starter.
	rectangle(418,346,604,396);
	setfillstyle(SOLID_FILL,1);
	bar(420,348,602,394);
	settextstyle(TRIPLEX_FONT,0,3);
	outtextxy(450,364,"START GAME");
	setfillstyle(SOLID_FILL,15);
	bar(425,200,515,260);
	setfillstyle(SOLID_FILL,13);
	bar(438,210,500,250);
	setfillstyle(SOLID_FILL,9);
	bar(525,188,600,273);
	setcolor(15);
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(532,186,"DICE");   outtextxy(542,207,"Shake");
	outtextxy(556,229,"&");      outtextxy(541,245,"Throw");
	settextstyle(DEFAULT_FONT,0,1);
	setcolor(6);
	outtextxy(418,285,"SCORE BOARD");
	setcolor(11);
	outtextxy(455,320,"0");   outtextxy(538,320,"0");
	setcolor(1);
	outtextxy(430,296,pl1);    outtextxy(505,296,pl2);
	outtextxy(433,406,"Player-1");   outtextxy(450,418,"CHANCE");
	outtextxy(523,406,"Player-2");   outtextxy(540,418,"CHANCE");
    }
   void postion( int p1,int p2)              //position
   {
int i,j,x=72,y=65,w=87,z=80,t=100;
     for(i=1;i<=10;i++)
      {
       for(j=1;j<=10;j++)
	{
	 if(p1==t)
	  {
	setcolor(1);
	   circle(x,y,6);
	  }
	 if(p2==t)
	  {
	setcolor(4);
	   circle(x,y,6);
	  }
	  t--;     x+=35;   w+=35;
	}
	y+=40;  
               z+=40;
                x=72;
	w=87;
      }
   } 

   void score()
{
char s1[3],s2[3];
setfillstyle(SOLID_FILL,15);
bar(434,306,484,341);
bar(510,306,560,341);
setfillstyle(SOLID_FILL,8);
rectangle(434,306,484,341);
rectangle(510,306,560,341);
itoa(p1,s1,10);itoa(p2,s2,10);
outtextxy(450,320,s1);
outtextxy(527,320,s2);
}


