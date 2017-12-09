//============================================================================
// Name        : SmartTimeTable.cpp
// Author      : Arun,Aniket,Dhruv,Akif
// Version     :1.0.6
// Copyright   : copyright
// Description : A smart time table
//============================================================================ 
//#AlmostDone
 #include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


struct teacher
{
 char name[40];
 int mon[9], tue[9], wed[9], thu[9], fri[9];
 char subject[20];
 int mond[9], tues[9], wedn[9], thur[9], frid[9];
};

struct day
{
 int mon[9], tue[9], wed[9], thur[9], fri[9];
};

int count=-1, temp=-1;
char newans;
teacher sample[40];
day a12a,b12b,a11a, b11b,a10a,b10b,c10c,a9a,b9b,c9c,a8a,b8b,c8c,a7a,b7b,c7c,a6a,b6b,c6c,a5a,b5b,c5c,a4a,b4b,c4c,a3a,b3b,c3c,a2a,b2b,c2c,a1a,b1b,c1c;

void teacherzero(day &x);
void algorithm(day &x);
void diplay(day &x);

int menu()
{ int answer;
 cout<<"Timetable generator\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n35.Display teacher timetable\n\nEnter option number: ";
cin>>answer;
return answer;
}

int search(char searcha[40]="09389219", int k=0)
{  if(k==0){
  for(int i=0; i<count; i++)
  {
    if(strcmpi(sample[count].name,sample[i].name)==0)
    {
      return i;
    }
  } }
  else if(k==1)
  { 
    for(int i=0; i<=count; i++)
  {
    if(strcmpi(searcha,sample[i].name)==0)
    {
      return i;
    }
  }}
return -1;
}


int input(day &x,char ch[3])
{   if(temp>count)
     count=temp;
    count++;
  teacherzero(x);
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
 cout<<"Enter First2 letters of day eg:Mo ";
 cin>>ch;
 cout<<"\nEnter no. of periods required for today: ";
 cin>>subjectcount;

 return subjectcount;
}

int temp2=15;

void algorithm(day &x, int &subanswer)
{ int subcount;
  int periodno;
  char say[3];
 cout<<"\nEnter teacher details for the selected class";
 subcount=input(x,say);
   int A[9]={0};
   int B[9]={0};
   int C[9]={0};


  if(strcmpi(say,"Mo")==0)
 { for(int i=0;i<9;i++)
   { B[i]=x.mon[i];
     A[i]=sample[count].mon[i];
     C[i]=sample[count].mond[i];
    }
 }
 else if(strcmpi(say,"Tu")==0)
 { for(int j=0;j<9;j++)
   { B[j]=x.tue[j];
     A[j]=sample[count].tue[j];
     A[j]=sample[count].tues[j]=C[j];
    }
 }
 else if(strcmpi(say,"We")==0)
 { for(int k=0;k<9;k++)
   { B[k]=x.wed[k];
     A[k]=sample[count].wed[k];
     C[k]=sample[count].wedn[k];
    }
 }
 else if(strcmpi(say,"Th")==0)
 { for(int i=0;i<9;i++)
   { B[i]=x.thur[i];
     A[i]=sample[count].thu[i];
     C[i]=sample[count].thur[i];
    }
 }
 else if(strcmpi(say,"Fr")==0)
 { for(int i=0;i<9;i++)
   { B[i]=x.fri[i];
     A[i]=sample[count].fri[i];
     C[i]=sample[count].frid[i];
    }
 }


 for(int i=0; i<subcount; i++)
 {
   randomize();
	periodno=random(9999)+1;
	periodno=periodno%9;
   if(periodno==0)
	periodno=9;
   if(A[periodno-1]==0)
   {
    if(B[periodno-1]==0)
    {
      A[periodno-1]=1;
      if(strcmpi(sample[count].subject,"Math")==0)
      {       B[periodno-1]=1;
		A[periodno-1]=1;
		}
      else if(strcmpi(sample[count].subject,"Chem")==0)
      {B[periodno-1]=2;
       A[periodno-1]=2;}
      else if(strcmpi(sample[count].subject,"Eng")==0)
      {B[periodno-1]=3;
       A[periodno-1]=3;}
      else if(strcmpi(sample[count].subject,"Phy")==0)
		{B[periodno-1]=4;
		 A[periodno-1]=4;}
      else if(strcmpi(sample[count].subject,"Comp")==0)
      {B[periodno-1]=5;
       A[periodno-1]=5;}
       int C[9];
	 C[periodno-1]=subanswer;
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

 if(strcmpi(say,"Mo")==0)
 { for(int i=0;i<9;i++)
   { x.mon[i]=B[i];
     sample[count].mon[i]=A[i];
     sample[count].mond[i]=C[i];
    }
 }
else if(strcmpi(say,"Tu")==0)
 { for(int i=0;i<9;i++)
   { x.tue[i]=B[i];
     sample[count].tue[i]=A[i];
     sample[count].tues[i]=C[i];
    }
 }
 else if(strcmpi(say,"We")==0)
 { for(int i=0;i<9;i++)
   { x.wed[i]=B[i];
     sample[count].wed[i]=A[i];
     sample[count].wedn[i]=C[i];
    }
 }
 else if(strcmpi(say,"Th")==0)
 { for(int i=0;i<9;i++)
   { x.thur[i]=B[i];
     sample[count].thu[i]=A[i];
     sample[count].thur[i]=C[i];
    }
 }
 else if(strcmpi(say,"Fr")==0)
 { for(int i=0;i<9;i++)
   { x.fri[i]=B[i];
     sample[count].fri[i]=A[i];
     sample[count].frid[i]=C[i];
    }
 }
 }
 }


void display(day &x)
{
 int i=0;
 int A[9];
 cout<<"\n1 \t  2 \t   3  \t  4 \t   5 \t  6 \t  7 \t  8  \t  9\n";
 for(int i=1;i<=5;i++)
 { 
	 
 for(int j=0; j<9; j++)
 {   if(i==1)
	  { for(int q=0;q<9;q++)
         A[q]=x.mon[j];
	   }
	  else if(i==2)
	  { for(int q=0;q<9;q++)
	      A[q]=x.tue[j];
	   }
	  else if(i==3)
	  { for(int q=0;q<9;q++)
	      A[q]=x.wed[j];
	   }
	  else if(i==4)
	  { for(int q=0;q<9;q++)
	      A[q]=x.thur[j];
	   }
	  else if(i==5)
	  { for(int q=0;q<9;q++)
	      A[q]=x.fri[j];
	   }
   if(A[j]==1)
   cout<<"Math\t ";
   else if(A[j]==2)
   cout<<"Chem\t ";
   else if(A[j]==3)
   cout<<"Eng\t ";
   else if(A[j]==4)
   cout<<"Phy\t ";
   else if(A[j]==5)
   cout<<"Comp\t ";
   else
   cout<<"NA\t ";

  }
  cout<<"\n";
 }
}

void displayteacher(int &x)
{ int Ar[9];
  int A[9];

 cout<<"\n1 \t  2 \t   3  \t  4 \t   5 \t  6 \t  7 \t  8  \t  9\n";
  for(int i=1;i<=5;i++)
 {
 for(int j=0; j<9; j++)
 {
       if(i==1)
	  { for(int q=0;q<9;q++)
	    {Ar[q]=sample[x].mond[q];
	     A[q]=sample[x].mon[q];
	    }
	   }
	  else if(i==2)
	  { for(int q=0;q<9;q++)
	    {Ar[q]=sample[x].tues[q];
	     A[q]=sample[x].tue[q];
	    }
	   }
	  else if(i==3)
	  { for(int q=0;q<9;q++)
	    {Ar[q]=sample[x].wedn[q];
	     A[q]=sample[x].wed[q];
	    }
	   }
	  else if(i==4)
	  { for(int q=0;q<9;q++)
	    {Ar[q]=sample[x].thur[q];
	     A[q]=sample[x].thu[q];
	    }
	   }
	  else if(i==5)
	  { for(int q=0;q<9;q++)
	    {Ar[q]=sample[x].frid[q];
	     A[q]=sample[x].fri[q];
	    }
	   }
	if(A[j]==1)
	cout<<"Math ";
	else if(A[j]==2)
	cout<<"Chem\t ";
	else if(A[j]==3)
	cout<<"Eng\t ";
	else if(A[j]==4)
	cout<<"Phy\t ";
	else if(A[j]==5)
	cout<<"Comp\t ";
	else
	cout<<"NA\t ";

	if(sample[x].mond[j]==1)cout<<"12A";
	else if(Ar[j]==2)cout<<"12B";
	else if(Ar[j]==3)cout<<"11A";
	else if(Ar[j]==4)cout<<"11B";
	else if(Ar[j]==5)cout<<"10A";
	else if(Ar[j]==6)cout<<"10B";
	else if(Ar[j]==7)cout<<"10C";
	else if(Ar[j]==8)cout<<"9A";
	else if(Ar[j]==9)cout<<"9B";
	else if(Ar[j]==10)cout<<"9C";
	else if(Ar[j]==11)cout<<"8A";
	else if(Ar[j]==12)cout<<"8B";
	else if(Ar[j]==13)cout<<"8C";
	else if(Ar[j]==14)cout<<"7A";
	else if(Ar[j]==15)cout<<"7B";
	else if(Ar[j]==16)cout<<"7C";
	else if(Ar[j]==17)cout<<"6A";
	else if(Ar[j]==18)cout<<"6B";
	else if(Ar[j]==19)cout<<"6C";
	else if(Ar[j]==20)cout<<"5A";
	else if(Ar[j]==21)cout<<"5B";
	else if(Ar[j]==22)cout<<"5C";
	else if(Ar[j]==23)cout<<"4A";
	else if(Ar[j]==24)cout<<"4B";
	else if(Ar[j]==25)cout<<"4C";
	else if(Ar[j]==26)cout<<"3A";
	else if(Ar[j]==27)cout<<"3B";
	else if(Ar[j]==28)cout<<"3C";
	else if(Ar[j]==29)cout<<"2A";
	else if(Ar[j]==30)cout<<"2B";
	else if(Ar[j]==31)cout<<"2C";
	else if(Ar[j]==32)cout<<"1A";
	else if(Ar[j]==33)cout<<"1B";
	else if(Ar[j]==34)cout<<"1C";
    }
    cout<<endl;
  }

}


void teacherzero(day &x)
{
  static int k=0;
  for(int i=0; i<9;i++)
  {
    sample[count].mon[i]=0;
    sample[count].tue[i]=0;
    sample[count].wed[i]=0;
    sample[count].thu[i]=0;
    sample[count].fri[i]=0;
   }
   if(k==0)
   {
    for(int j=0;j<9;j++)
    {
    x.mon[j]=0;
    x.tue[j]=0;
    x.wed[j]=0;
    x.thur[j]=0;
    x.fri[j]=0;
    }
   }
   k++;
}

char ans;

void main()
{
 int answer;
do{
  clrscr();
  answer=menu();
  switch(answer)
 {
  case 1:
  do{
  algorithm(a12a, answer);
  display(a12a);
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 2:
do{
  algorithm(b12b, answer);
  display(b12b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 3:
do{
  algorithm(a11a, answer);
  display(a11a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 4:
do{
  algorithm(b11b, answer);
  display(b11b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 5:
do{
  algorithm(a10a, answer);
  display(a10a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 6:
do{
  algorithm(b10b, answer);
  display(b10b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 7:
do{
  algorithm(c10c, answer);
  display(c10c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 8:
do{
  algorithm(a9a, answer);
  display(a9a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 9:
do{
  algorithm(b9b, answer);
  display(b9b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 10:
do{
  algorithm(c9c, answer);
  display(c9c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 11:
do{
  algorithm(a8a, answer);
  display(a8a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 12:
do{
  algorithm(b8b, answer);
  display(b8b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 13:
do{
  algorithm(c8c, answer);
  display(c8c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 14:
do{
  algorithm(a7a, answer);
  display(a7a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 15:
do{
  algorithm(b7b, answer);
  display(b7b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 16:
do{
  algorithm(c7c, answer);
  display(c7c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 17:
do{
  algorithm(a6a, answer);
  display(a6a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 18:
do{
  algorithm(b6b, answer);
  display(b6b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 19:
do{
  algorithm(c6c, answer);
  display(c6c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 20:
do{
  algorithm(a5a, answer);
  display(a5a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 21:
do{
  algorithm(b5b, answer);
  display(b5b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 22:
do{
  algorithm(c5c, answer);
  display(c5c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 23:
do{
  algorithm(a4a, answer);
  display(a4a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 24:
do{
  algorithm(b4b, answer);
  display(b4b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 25:
do{
  algorithm(c4c, answer);
  display(c4c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 26:
do{
  algorithm(a3a, answer);
  display(a3a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 27:
do{
  algorithm(b3b, answer);
  display(b3b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 28:
do{
  algorithm(c3c, answer);
  display(c3c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 29:
do{
  algorithm(a2a, answer);
  display(a2a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 30:
do{
  algorithm(b2b, answer);
  display(b2b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 31:
do{
  algorithm(c2c, answer);
  display(c2c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 32:
do{
  algorithm(a1a, answer);
  display(a1a);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 33:
do{
  algorithm(b1b, answer);
  display(b1b);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 34:
do{
  algorithm(c1c, answer);
  display(c1c);
  cout<<endl;
  cout<<"\nDo you want to enter details for more teachers? Yes(y) or No(n)";
  cin>>ans;
  clrscr();
}while(ans=='y'); break;

case 35:
char searchitem[40];
do{
   clrscr();
   cout<<"Enter teacher to be searched: ";
   cin>>searchitem;
	int ivalue=search(searchitem,1);
   displayteacher(ivalue);
}while(ans=='y'); break;
}
cout<<"\nDo you want to continue the timetable generator>> Yes(y) or No(n) ";
cin>>newans;
}while(newans=='y') ;

  int y;
  cin>>y;
}





