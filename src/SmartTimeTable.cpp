//============================================================================
// Name        : SmartTimeTable.cpp
// Author      : Arun,Aniket,Dhruv,Akif
// Version     :1.0.2
// Copyright   : copyright
// Description : A smart time table
//============================================================================ 
//#MultipleTeacherSameTeachers2classesOneDay
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


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

int count=-1, temp=-1;
teacher sample[40];
day a11a, b11b;

void teacherzero();
void algorithm();
void diplay();
void teacherzero11b();

int search()
{ 
  for(int i=0; i<count; i++)
  {
    if(strcmpi(sample[count].name,sample[i].name)==0)
    {
      return i;
    }
}
return -1;
}
        

int input()
{   if(temp>count)
     count=temp;
    count++;
  teacherzero();
 int subjectcount;
 cout<<"\nEnter name of the teacher:  ";
 cin>>sample[count].name;
 int store = search();
 if(store!=-1)
 { count--;
   temp=count;
   count=store;
}
 cout<<"\nEnter subject:  ";
 cin>>sample[count].subject;
 cout<<"\nEnter no. of periods required for today: ";
 cin>>subjectcount;

 return subjectcount;
}

int input11b()
{   if(temp>count)
     count=temp;
    count++;
  teacherzero11b();
 int subjectcount;
 cout<<"\nEnter the name of the teacher:  ";
 cin>>sample[count].name;
 int store = search();
 
 
 if(store!=-1)
 { --count;
   temp=count;
   count=store;
}
 cout<<"\nEnter subject taught:  ";
 cin>>sample[count].subject;
 cout<<"\nEnter no of periods for today:  ";
 cin>>subjectcount;

 return subjectcount;
}

void algorithm()
{ int subcount, periodno;
 cout<<"\nEnter teacher details for 11A";
 subcount=input();
 for(int i=0; i<subcount; i++)
 { 
   randomize();
   periodno=random(9)+1;
   if(sample[count].mon[periodno-1]==0)
   {
    if(a11a.mon[periodno-1]==0)
    {
     sample[count].mon[periodno-1]=1;
     if(strcmpi(sample[count].subject,"Math")==0)
      a11a.mon[periodno-1]=1;
      if(strcmpi(sample[count].subject,"Chem")==0)
      a11a.mon[periodno-1]=2;
      if(strcmpi(sample[count].subject,"Eng")==0)
      a11a.mon[periodno-1]=3;
      if(strcmpi(sample[count].subject,"Phy")==0)
      a11a.mon[periodno-1]=4;
      if(strcmpi(sample[count].subject,"Comp")==0)
     a11a.mon[periodno-1]=5;
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
 } 
 }
 
 
 void algorithm11b()
{ int subcount, periodno;
 cout<<"\nEnter teacher details for 11B";
 subcount=input11b();
 for(int i=0; i<subcount; i++)
 { 
   randomize();
   periodno=random(9)+1;
   if(sample[count].mon[periodno-1]==0)
   {
    if(b11b.mon[periodno-1]==0)
    {
     sample[count].mon[periodno-1]=1;
     if(strcmpi(sample[count].subject,"Math")==0)
      b11b.mon[periodno-1]=1;
      if(strcmpi(sample[count].subject,"Chem")==0)
      b11b.mon[periodno-1]=2;
      if(strcmpi(sample[count].subject,"Eng")==0)
      b11b.mon[periodno-1]=3;
      if(strcmpi(sample[count].subject,"Phy")==0)
      b11b.mon[periodno-1]=4;
      if(strcmpi(sample[count].subject,"Comp")==0)
      b11b.mon[periodno-1]=5;
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
 } 
 }




void display()
{
 int i=0;
 cout<<"\n1 \t  2 \t   3  \t  4 \t   5 \t  6 \t  7 \t  8  \t  9\n";
 for(int j=0; j<9; j++)
 {
   if(a11a.mon[j]==1)
   cout<<"Math\t ";
   else if(a11a.mon[j]==2)
   cout<<"Chem\t ";
   else if(a11a.mon[j]==3)
   cout<<"Eng\t ";
   else if(a11a.mon[j]==4)
   cout<<"Phy\t ";
   else if(a11a.mon[j]==5)
   cout<<"Comp\t ";
   else
   cout<<"NA\t ";

  }
}

void displayteacher()
{ 
 for(int i=0; i<9; i++)
  cout<<sample[count].mon[i]<<"   ";
  cout<<endl;
}


void display11b()
{
 int i=0;
 cout<<"\n1 \t  2 \t   3  \t  4 \t   5 \t  6 \t  7 \t  8  \t  9\n";
 for(int j=0; j<9; j++)
 {
   if(b11b.mon[j]==1)
   cout<<"Math\t ";
   else if(b11b.mon[j]==2)
   cout<<"Chem\t ";
   else if(b11b.mon[j]==3)
   cout<<"Eng\t ";
   else if(b11b.mon[j]==4)
   cout<<"Phy\t ";
   else if(b11b.mon[j]==5)
   cout<<"Comp\t ";
   else
   cout<<"NA\t ";

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
    a11a.mon[j]=0;
    a11a.tue[j]=0;
    a11a.wed[j]=0;
    a11a.thur[j]=0;
    a11a.fri[j]=0;
    } }   k++;
    }
    
void teacherzero11b()
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
    b11b.mon[j]=0;
    b11b.tue[j]=0;
    b11b.wed[j]=0;
    b11b.thur[j]=0;
    b11b.fri[j]=0;
    } }   k++;
    }
void main()
{
  clrscr();
  do{
  char ans;
  algorithm();
  display();
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans==y);

do{
  char ans2;
  algorithm11b();
  display11b();
  cout<<endl;
  displayteacher();
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans2;
  clrscr();
}while(ans2==y);
  int y;
  cin>>y;
}



