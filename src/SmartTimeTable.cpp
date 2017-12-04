//============================================================================
// Name        : SmartTimeTable.cpp
// Author      : Arun,Aniket,Dhruv,Akif
// Version     :1.0.1
// Copyright   : copyright
// Description : A smart time table
//============================================================================
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//#OneTeacherOnedayOneClass
struct teacher
{
 char name[40];
 int mon[9], tue[9], wed[9], thu[9], fri[9];
 char subject[20];
};

struct day
{
 int mon[9], tue[9], wed[9], thur[9], fri[9];
};

int count=-1;
teacher sample[40];
day s;

void teacherzero();
void algorithm();
void display();

int input()
{ count++;
  teacherzero();
 int subjectcount;
 cout<<"ENTER THE NAME OF THE TEACHER";
 cin>>sample[count].name;
 cout<<"\nENTER SUBJECT";
 cin>>sample[count].subject;
 cout<<"\nnenter no of periods for today";
 cin>>subjectcount;
 return subjectcount;
}
void algorithm()
{ int subcount, periodno;
 cout<<"enter teacher details";
 subcount=input();
 for(int i=0; i<subcount; i++)
 {
   randomize();
   periodno=random(9)+1;
   if(sample[count].mon[periodno-1]==0)
   {
    if(s.mon[periodno-1]==0)
    {
     sample[count].mon[periodno-1]=1;
     if(strcmpi(sample[count].subject,"math")==0)
      s.mon[periodno-1]=1;
      if(strcmpi(sample[count].subject,"chem")==0)
      s.mon[periodno-1]=2;
      if(strcmpi(sample[count].subject,"eng")==0)
      s.mon[periodno-1]=3;
      if(strcmpi(sample[count].subject,"phy")==0)
      s.mon[periodno-1]=4;
      if(strcmpi(sample[count].subject,"comp")==0)
      s.mon[periodno-1]=5;
    }
    else
    {
     --i;
     continue;
    }

   }
   else
   {
    --i;
    continue;
   }
 } }



void display()
{
 int i=0;
 cout<<"1     2      3       4      5      6      7      8       9\n";
 for(int j=0; j<9; j++)
 {
   if(s.mon[j]==1)
   cout<<" math ";
   else if(s.mon[j]==2)
   cout<<" chem ";
   else if(s.mon[j]==3)
   cout<<" eng ";
   else if(s.mon[j]==4)
   cout<<" phy ";
   else if(s.mon[j]==5)
   cout<<" comp ";
   else
   cout<<" na ";

  }
}
void teacherzero()
{
  static int k=0;
  for(int i=0; i<9;i++)
  {
    sample[count].mon[i]=0;
    sample[count].tue[i]=0;
    sample[count].wed[i]=0;
    sample[count].thu[i]=0;
    sample[count].fri[i]=0;
   }if(k==0)
   { for(int j=0;j<9;j++)
   {
    s.mon[j]=0;
    s.tue[j]=0;
    s.wed[j]=0;
    s.thur[j]=0;
    s.fri[j]=0;
    } }   k++;
    }
void main()
{
  clrscr();
  algorithm();
  display();
  int y;
  cin>>y;
}


