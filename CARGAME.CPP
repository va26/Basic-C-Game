# include <iostream.h>
# include <conio.h>
# include <stdlib.h>
# include <dos.h>

void car(int,int,int);
void discar(int,int);
void track(int);
void move(int,int,int &,int[]);
void design(int,int);


void main()
 {
 clrscr();
 track(25);

 int x=0,y=0,x1=0,y1=0;
 char key; int exit=0,exit1=0,quit=0,level=0,d=1,i=1,sel=0;
 //Array which gives valus to delay function to increase speed with increase in level
 int del[]={100,150,110,100,90,70,65,60,55,50,40,39,38,37,36,35,34,30,30,30,30,20,20,20,20,20,20,20,20,20};
 //Displays the staring phrases
 gotoxy(35,8);
 cprintf("ARE YOU READY!");delay(1000);
 gotoxy(30,10);
 cprintf("THE RACE BEGINS IN : 3!");delay(500);
 gotoxy(30,10);
 cprintf("THE RACE BEGINS IN :   ");delay(500);
 gotoxy(30,10);
 cprintf("THE RACE BEGINS IN : 2!");delay(500);
 gotoxy(30,10);
 cprintf("THE RACE BEGINS IN :   ");delay(500);
 gotoxy(30,10);
 cprintf("THE RACE BEGINS IN : 1!");delay(1000); 
 gotoxy(38,12);
 cprintf("Go!!!");delay(1000);
 clrscr();

 track(25);  //Function to display thr track defined after main
 car(33,23,2);//Funtion to display car

 do
  {
  if(kbhit())// checks for the key hit
   {
   key= getch(); //Gets the input
   switch(key)
    {
    case 75 :car(33,23,2);  //75 is ASCII value of left arrow key
	     discar(48,23);
	     x=33;y=21;
	     break;

    case 77 :car(48,23,2); //73 is ASCII value of Right arrow key
	     discar(33,23);
	     x=48,y=21;
	     break;

    case 13 :quit=1;  //13 is ASCII value of Enter key
	     break;

    }
   }
  //This else scope randomly selects the path for the cars coming from above
  else
   {
    int no;
    switch(sel)
     {
     case 0 : randomize();
	      no =random(500);
	      move(i,33,d,del);
	      i++;
	      x1=33;y1=i;
	      gotoxy(60,20);
	      cout<<"Level : "<<level/2;
	      if((i==24)&&(!exit))
	       {
	       i=1;
	       d++;
	       sel=random(no)%2;
	       gotoxy(60,20);
	       cout<<"Level : "<<(level++)/2;
	       if(d==29)
		{
		d=0;
		exit1=1;
		}
	       }
	      break;

     case 1 : randomize();
	      no =random(500);
	      move(i,48,d,del);
	      i++;
	      x1=48;y1=i;
	      gotoxy(60,20);
	      cout<<"Level : "<<level/2;
	      if((i==24)&&(!exit))
	       {
	       i=1;
	       d++;
	       sel=random(no)%2;
	       gotoxy(60,20);
	       cout<<"Level : "<<(level++)/2;
	       if(d==29)
		{
		d=0;
		exit1=1;
		}
	       }
	      break;
     }

   }
   //CHECKS WHETHER THE COORDINATES MATCH IF THEY DO THEN YOU HIT THE CAR AND GAME IS OVER!
   if((x==x1)&&(y==y1)||(x==x1)&&(y==y1-1)||(x==x1)&&(y==y1-2))
    {
    exit=1;
    quit=1;
    gotoxy(30,10);
    textcolor(15);
    cprintf("      GAME OVER\n");
    gotoxy(30,12);
    cprintf("  PRESS ENTER TO EXIT");
    }
   //IF YOU CLEAR ALL THE STAGES YOU WIN!
   if(exit1==1)
    {
    quit=1;
    gotoxy(30,10);
    textcolor(15);
    cprintf("      YOU WIN\n");
    gotoxy(30,12);
    cprintf("  PRESS ENTER TO EXIT");
    }

  }while(!quit);
 getch();

 }
//Displays the Car.
void car(int x,int y,int col)
 {
 textcolor(col);
 gotoxy(x,y);
 cprintf("%c",(char)219);
 gotoxy(x,y+1);
 cprintf("%c",(char)219);
 gotoxy(x,y+2);
 cprintf("%c",(char)219);
 gotoxy(x+2,y+2);
 cprintf("%c",(char)220);
 gotoxy(x-2,y+2);
 cprintf("%c",(char)220);
 gotoxy(x-2,y);
 cprintf("%c",(char)220);
 gotoxy(x+2,y);
 cprintf("%c",(char)220);
 }
//Diappears the Car.
void discar(int x,int y)
 {
 gotoxy(x,y);
 cprintf(" ");
 gotoxy(x,y+1);
 cprintf(" ");
 gotoxy(x,y+2);
 cprintf(" ");
 gotoxy(x+2,y+2);
 cprintf(" ");
 gotoxy(x-2,y+2);
 cprintf(" ");
 gotoxy(x-2,y);
 cprintf(" ");
 gotoxy(x+2,y);
 cprintf(" ");
 }
//Displays the Track.
void track(int j)
 {
 for(int i=1;i<=25;i++)
  {
  textcolor(15);
  gotoxy(j+30,i);
  cprintf("%c",(char)219);
  gotoxy(j+31,i);
  cprintf("%c",(char)219);
  gotoxy(j,i);
  cprintf("%c",(char)219);
  gotoxy(j+1,i);
  cprintf("%c",(char)219);
  }
 for(i=1;i<=25;i+=2)
  {
  textcolor(15);
  gotoxy(j+15,i);
  cprintf("%c",(char)219);
  }
 }
//Moves the Car.
void move (int i,int x,int &d,int del[] )
 {
  car(x,i,9);
  delay(del[d]);
  discar(x,i);
 }

