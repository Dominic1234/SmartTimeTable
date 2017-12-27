//============================================================================
// Name        : SmartTimeTable.cpp
// Author      : Arun,Aniket,Dhruv,Akif
// Version     :1.0.7
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
 char classtea[40], assoteacher[40];
};

int count=-1, temp=-1;
int checkm=-1;
char newans;
teacher sample[40];
day a12a,b12b,a11a, b11b,a10a,b10b,c10c,a9a,b9b,c9c,a8a,b8b,c8c,a7a,b7b,c7c,a6a,b6b,c6c,a5a,b5b,c5c,a4a,b4b,c4c,a3a,b3b,c3c,a2a,b2b,c2c,a1a,b1b,c1c;
day mroom, biotech, avroom, ground, sstlab, audi, slab, artroom, mathlab, complab1, complab2, lib1, lib2, greenroom;

void teacherzero(day &x, int &ans2);
void algorithm(day &x);
void display(day &x);
void saveteacher(int P[9])
{
	   
	  if(P[0]!=0&&P[1]!=0&&P[2]==0)
	  P[2]=123;
      if(P[0]!=0&&P[2]!=0&&P[1]==0)
	  P[1]=123;
	  if(P[1]!=0&&P[2]!=0&&P[0]==0)
	   P[0]=123;
	  if(P[3]!=0&&P[4]!=0&&P[5]==0)
	  P[5]=123;
	  if(P[5]!=0&&P[4]!=0&&P[3]==0)
	  P[3]=123;
      if(P[3]!=0&&P[5]!=0&&P[4]==0)
	  P[4]=123;
	  if(P[6]!=0&&P[7]!=0&&P[8]==0)
	  P[8]=123;
	  if(P[7]!=0&&P[8]!=0&&P[6]==0)
	  P[6]=123;
      if(P[6]!=0&&P[8]!=0&&P[7]==0)
	  P[7]=123;

}



void resettt(day &x,char ch[3],int subb)
{    int C[9], K[9];
	 if(strcmpi(ch,"Mo")==0)
    { for(int k=0;k<9;k++)
       x.mon[k]=0;
    }

	if(strcmpi(ch,"Tu")==0)
    { for(int k=0;k<9;k++)
       x.tue[k]=0;
    }

	if(strcmpi(ch,"We")==0)
    { for(int k=0;k<9;k++)
       x.wed[k]=0;
    }

	if(strcmpi(ch,"Th")==0)
    { for(int k=0;k<9;k++)
       x.thur[k]=0;
    }

	if(strcmpi(ch,"Fr")==0)
    { for(int k=0;k<9;k++)
       x.fri[k]=0;
    }
		
    for(int p=0; p<=checkm; p++)
	{  
	  if(strcmpi(ch,"Mo")==0)
       { 
          for(int j=0;j<9;j++)
        { 
          K[j]=sample[p].mon[j];
          C[j]=sample[p].mond[j];
        }
       }
      else if(strcmpi(ch,"Tu")==0)
     { 
       for(int j=0;j<9;j++)
      { 
       K[j]=sample[p].tue[j];
       C[j]=sample[p].tues[j];
      }
     }
 else if(strcmpi(ch,"We")==0)
 { for(int k=0;k<9;k++)
   { 
     K[k]=sample[p].wed[k];
     C[k]=sample[p].wedn[k];
    }
 }
 else if(strcmpi(ch,"Th")==0)
 { for(int q=0;q<9;q++)
   { ;
     K[q]=sample[p].thu[q];
     C[q]=sample[p].thur[q];
    }
 }
 else if(strcmpi(ch,"Fr")==0)
 { for(int m=0;m<9;m++)
   {
     K[m]=sample[p].fri[m];
     C[m]=sample[p].frid[m];
    }
 }	
 
 
  for(int y=0; y<9;y++)
  {
	  if(C[y]==subb)
	  {
		  C[y]=0;
		  K[y]=0;
	  }  
  }
  
  if(strcmpi(ch,"Mo")==0)
       { 
          for(int j=0;j<9;j++)
        { 
          sample[p].mon[j]=K[j];
          sample[p].mond[j]=C[j];
        }
       }
      else if(strcmpi(ch,"Tu")==0)
     { 
       for(int j=0;j<9;j++)
      { 
       sample[p].tue[j]=K[j];
       sample[p].tues[j]=C[j];
      }
     }
 else if(strcmpi(ch,"We")==0)
 { for(int k=0;k<9;k++)
   { 
     sample[p].wed[k]=K[k];
     sample[p].wedn[k]=C[k];
    }
 }
 else if(strcmpi(ch,"Th")==0)
 { for(int q=0;q<9;q++)
   { 
     sample[p].thu[q]=K[q];
     sample[p].thur[q]=C[q];
    }
 }
 else if(strcmpi(ch,"Fr")==0)
 { for(int m=0;m<9;m++)
   {
     sample[p].fri[m]=K[m];
     sample[p].frid[m]=C[m];
    }
 }	
	}
	
}





void substitution()
{    clrscr();
     int subday;
     int periodno;
     cout<<"\nEnter day to generate substitution\nMonday - 1\nTuesday - 2\nWednesday - 3\nThursday - 4\nFriday - 5\n";
     cin>>subday;
     cout<<"\nWhich period needs to be substituted? Enter period number (1-9): ";
     cin>>periodno;
     int i;
      switch(subday)
      { 
       case 1: {cout<<"Substitution teachers for requested day and period: ";
               for(i=0; i<=checkm; i++)
               {
                 if(sample[i].mon[periodno-1]==0)
                 {
                   cout<<"\n"<<sample[i].name<<" is available";
                   }
	   } break;}
       case 2: {cout<<"Substitution teachers for requested day and period: ";
               for(i=0; i<=checkm; i++)
               {
                 if(sample[i].tue[periodno-1]==0)
                 {
                   cout<<"\n"<<sample[i].name<<" is available";
                   }
	   } break;}
      case 3: {cout<<"Substitution teachers for requested day and period: ";
               for(i=0; i<=checkm; i++)
               {
                 if(sample[i].wed[periodno-1]==0)
                 {
                   cout<<"\n"<<sample[i].name<<" is available";
                   }
	  } break;}
     case 4: {cout<<"Substitution teachers for requested day and period: ";
               for(i=0; i<=checkm; i++)
               {
                 if(sample[i].thu[periodno-1]==0)
                 {
                   cout<<"\n"<<sample[i].name<<" is available";
                   }
	 } break;}
     case 5: {cout<<"Substitution teachers for requested day and period: ";
               for(int i=0; i<=checkm; i++)
               {
                 if(sample[i].fri[periodno-1]==0)
                 {
                   cout<<"\n"<<sample[i].name<<" is available";
                   }
	 } break;}
}}
int menu()
{ int answer;
 cout<<"Timetable generator\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n35.Display teacher timetable\n36.Display timetable for any class\n37.Check for substitution\n38.Reset any class timetable\n39.Exit\n\nEnter option number: ";
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
  }
  }
  else if(k==1)
  {
    for(int i=0; i<=count; i++)
  {
    if(strcmpi(searcha,sample[i].name)==0)
    {
      return i;
    }
  } cout<<"teacher does not exist try again displaying teacher 1 by default protection case"<<endl;
    return 0;
  }
return -1;
}
void assembly(day &x, int ans3);
int input(day &x,char ch[3], int suanswer)
{   if(temp>count)
     count=temp;
    count++;
    checkm++;
  teacherzero(x,suanswer);
  assembly(x, suanswer);
 int subjectcount;
 cout<<"\nEnter name of the teacher:  ";
 cin>>sample[count].name;
 int store = search();
 if(store!=-1)
 { count--;
   checkm--;
   temp=count;
   count=store;
 }
 cout<<"\nEnter subject"<<endl<<"1. Physics - phy\n2. Chemistry - chem\n3. Mathematics - math\n4. English - eng\n5. Computer - comp\n6. Biology - bio\n7. Grade 11 elective - elec\n8. General studies - GS\n9. EE - EE\n10. VPA - VPA\n11. Art - art\n12. Yoga - yoga\n13. PT - PT\n14. Club\n15. Third Language Elective - lang\n16. Second Language elective grades 9-10 - seclang\n17. History - hist\n18. Civics - civ\n19. Geography- geo\n20. Social studies (for grades below 6) - SS \n21. AEP - AEP\n22. EVS - EVS\n23. Gen. Science - GSc\n24. Reading period - RP\n25. Indian Music - IM\n26. Western Music - WM\n27. Dance - Dan\n28. Life Skills - LS\n29. Math lab - ML\n30. March Past - MP\n";
 cin>>sample[count].subject;
 cout<<"\nEnter first two letters of the day\nMonday - mo\nTuesday - tu\nWednesday - we\nThursday - th\nFriday - fr\n\n";
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
 subcount=input(x,say,subanswer);
   int A[9];
   int B[9];
   int C[9];
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
     C[j]=sample[count].tues[j];
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

long double idiot =0;
int flag=0;

 for(int i=0; i<subcount; i++)
 { 
   idiot++;
   if(idiot==5000000)
   {
	   flag=1;
	   break;
   }
   saveteacher(A);randomize();
	periodno=random(9999)+1;
	periodno=periodno%9;
   if(periodno==0)
	periodno=9;
   if(A[periodno-1]==0)
   {   
    if(B[periodno-1]==0)
    { C[periodno-1]=subanswer; 
      if(strcmpi(sample[count].subject,"Math")==0)
      { B[periodno-1]=1;
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
      else if(strcmpi(sample[count].subject,"bio")==0)
      {B[periodno-1]=6;
       A[periodno-1]=6;}
       else if(strcmpi(sample[count].subject,"elec")==0)
      {B[periodno-1]=7;
       A[periodno-1]=7;}
       else if(strcmpi(sample[count].subject,"gs")==0)
      {B[periodno-1]=8;
       A[periodno-1]=8;}
       else if(strcmpi(sample[count].subject,"ee")==0)
      {B[periodno-1]=9;
       A[periodno-1]=9;}
       else if(strcmpi(sample[count].subject,"vpa")==0)
      {B[periodno-1]=10;
       A[periodno-1]=10;}
       else if(strcmpi(sample[count].subject,"art")==0)
      {B[periodno-1]=11;
       A[periodno-1]=11;}
       else if(strcmpi(sample[count].subject,"yoga")==0)
      {B[periodno-1]=12;
       A[periodno-1]=12;}
       else if(strcmpi(sample[count].subject,"pt")==0)
      {B[periodno-1]=13;
       A[periodno-1]=13;}
       else if(strcmpi(sample[count].subject,"club")==0)
      {B[periodno-1]=14;
       A[periodno-1]=14;}
       else if(strcmpi(sample[count].subject,"lang")==0)
      {B[periodno-1]=15;
       A[periodno-1]=15;}
       else if(strcmpi(sample[count].subject,"seclang")==0)
      {B[periodno-1]=16;
       A[periodno-1]=16;}
	   else if(strcmpi(sample[count].subject,"hist")==0)
      {B[periodno-1]=17;
       A[periodno-1]=17;}
	   else if(strcmpi(sample[count].subject,"civ")==0)
      {B[periodno-1]=18;
       A[periodno-1]=18;}
	   else if(strcmpi(sample[count].subject,"geo")==0)
      {B[periodno-1]=19;
       A[periodno-1]=19;}
	   else if(strcmpi(sample[count].subject,"ss")==0)
      {B[periodno-1]=20;
       A[periodno-1]=20;}
	   else if(strcmpi(sample[count].subject,"aep")==0)
      {B[periodno-1]=21;
       A[periodno-1]=21;}
	   else if(strcmpi(sample[count].subject,"evs")==0)
      {B[periodno-1]=22;
       A[periodno-1]=22;}
	   else if(strcmpi(sample[count].subject,"gsc")==0)
      {B[periodno-1]=23;
       A[periodno-1]=23;}
	   else if(strcmpi(sample[count].subject,"rp")==0)
      {B[periodno-1]=24;
       A[periodno-1]=24;}
	   else if(strcmpi(sample[count].subject,"im")==0)
      {B[periodno-1]=25;
       A[periodno-1]=25;}
	   else if(strcmpi(sample[count].subject,"wm")==0)
      {B[periodno-1]=26;
       A[periodno-1]=26;}
	   else if(strcmpi(sample[count].subject,"dan")==0)
      {B[periodno-1]=27;
       A[periodno-1]=27;}
	   else if(strcmpi(sample[count].subject,"ls")==0)
      {B[periodno-1]=28;
       A[periodno-1]=28;}
	   else if(strcmpi(sample[count].subject,"ml")==0)
      {B[periodno-1]=29;
       A[periodno-1]=29;}
	   else if(strcmpi(sample[count].subject,"mp")==0)
      {B[periodno-1]=30;
       A[periodno-1]=30;}
	   
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
  if(flag==1)
 {
   cout<<"The day has been reset due to teacher unavailability. Please enter details again.     ";
   char y;
   cin>>y;
   resettt(x,say,subanswer);
 }
 }

 
 




void display(day &x)
{
 int A[9];
 cout<<"\n     1     2     3     4     5     6     7     8     9\n";
 for(int i=1;i<=5;i++)
 {
     if(i==1)cout<<"Mon  ";
	   else if(i==2)cout<<"Tue  ";
	   else if(i==3)cout<<"Wed  ";
	   else if(i==4)cout<<"Thu  ";
	   else cout<<"Fri  ";
 for(int j=0; j<9; j++)
 {   if(i==1)
	  { for(int q=0;q<9;q++)
	 A[q]=x.mon[q];
	   }
	  else if(i==2)
	  { for(int q=0;q<9;q++)
	      A[q]=x.tue[q];
	   }
	  else if(i==3)
	  { for(int q=0;q<9;q++)
	      A[q]=x.wed[q];
	   }
	  else if(i==4)
	  { for(int q=0;q<9;q++)
	      A[q]=x.thur[q];
	   }
	  else if(i==5)
	  { for(int q=0;q<9;q++)
	      A[q]=x.fri[q];
	   }



   if(A[j]==1)
   cout<<"Math  ";
   else if(A[j]==2)
   cout<<"Chem  ";
   else if(A[j]==3)
   cout<<"Eng   ";
   else if(A[j]==4)
   cout<<"Phy   ";
   else if(A[j]==5)
   cout<<"Comp  ";
   else if(A[j]==6)
   cout<<"Bio   ";
   else if(A[j]==7)
   cout<<"Elec  ";
   else if(A[j]==8)
   cout<<"GS    ";
   else if(A[j]==9)
   cout<<"EE    ";
   else if(A[j]==10)
   cout<<"VPA   ";
   else if(A[j]==11)
   cout<<"Art   ";
   else if(A[j]==12)
   cout<<"Yoga  ";
   else if(A[j]==13)
   cout<<"PT    ";
   else if(A[j]==14)
   cout<<"Club  ";
   else if(A[j]==15)
   cout<<"3rd   ";
   else if(A[j]==16)
   cout<<"II L  ";
   else if(A[j]==100)
   cout<<"Ass   ";
   else if(A[j]==30)
   cout<<"MP    ";
else if(A[j]==17)
   cout<<"His   ";
else if(A[j]==18)
   cout<<"Civ   ";
else if(A[j]==19)
   cout<<"Geo   ";
else if(A[j]==20)
   cout<<"SS    ";
else if(A[j]==21)
   cout<<"AEP   ";
else if(A[j]==22)
   cout<<"EVS   ";
else if(A[j]==23)
   cout<<"GSc   ";
else if(A[j]==24)
   cout<<"RP    ";
else if(A[j]==25)
   cout<<"IM    ";
else if(A[j]==26)
   cout<<"WM    ";
else if(A[j]==27)
   cout<<"Dan   ";
else if(A[j]==28)
   cout<<"LS    ";
else if(A[j]==29)
   cout<<"ML    ";
else if(i==123)
	cout<<"R    ";
   else
   cout<<"NA    ";

  }
  cout<<"\n";
 }
}

void displayteacher(int &x)
{ int Ar[9];
  int A[9];

 cout<<"\n     1     2     3     4     5     6     7     8     9\n";
  for(int i=1;i<=5;i++)
 {
	   if(i==1)cout<<"Mon  ";
	   else if(i==2)cout<<"Tue  ";
	   else if(i==3)cout<<"Wed  ";
	   else if(i==4)cout<<"Thu  ";
	   else cout<<"Fri  ";
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
	cout<<"Math  ";
	else if(A[j]==2)
	cout<<"Chem  ";
	else if(A[j]==3)
	cout<<"Eng   ";
	else if(A[j]==4)
	cout<<"Phy   ";
	else if(A[j]==5)
	cout<<"Comp  ";
	else if(A[j]==6)
   cout<<"Bio   ";
   else if(A[j]==7)
   cout<<"Elec  ";
   else if(A[j]==8)
   cout<<"GS    ";
   else if(A[j]==9)
   cout<<"EE    ";
   else if(A[j]==10)
   cout<<"VPA   ";
   else if(A[j]==11)
   cout<<"Art   ";
   else if(A[j]==12)
   cout<<"Yoga  ";
   else if(A[j]==13)
   cout<<"PT    ";
   else if(A[j]==14)
   cout<<"Club  ";
   else if(A[j]==15)
   cout<<"3rd   ";
   else if(A[j]==16)
   cout<<"II L  ";
   else if(A[j]==100)
   cout<<"Ass   ";
else if(A[j]==30)
   cout<<"MP  ";
else if(A[j]==17)
   cout<<"His   ";
else if(A[j]==18)
   cout<<"Civ   ";
else if(A[j]==19)
   cout<<"Geo   ";
else if(A[j]==20)
   cout<<"SS    ";
else if(A[j]==21)
   cout<<"AEP   ";
else if(A[j]==22)
   cout<<"EVS   ";
else if(A[j]==23)
   cout<<"GSc   ";
else if(A[j]==24)
   cout<<"RP    ";
else if(A[j]==25)
   cout<<"IM    ";
else if(A[j]==26)
   cout<<"WM    ";
else if(A[j]==27)
   cout<<"Dan   ";
else if(A[j]==28)
   cout<<"LS    ";
else if(A[j]==29)
   cout<<"ML    ";
else if(i==123)
	cout<<"R    ";
	else
	cout<<"NA    ";
 }
 cout<<"\n     ";
for(j=0; j<9; j++)
{   
	if(Ar[j]==1)cout<<"12A   ";
	else if(Ar[j]==2)cout<<"12B   ";
	else if(Ar[j]==3)cout<<"11A   ";
	else if(Ar[j]==4)cout<<"11B   ";
	else if(Ar[j]==5)cout<<"10A   ";
	else if(Ar[j]==6)cout<<"10B   ";
	else if(Ar[j]==7)cout<<"10C   ";
	else if(Ar[j]==8)cout<<"9A    ";
	else if(Ar[j]==9)cout<<"9B    ";
	else if(Ar[j]==10)cout<<"9C    ";
	else if(Ar[j]==11)cout<<"8A    ";
	else if(Ar[j]==12)cout<<"8B    ";
	else if(Ar[j]==13)cout<<"8C    ";
	else if(Ar[j]==14)cout<<"7A    ";
	else if(Ar[j]==15)cout<<"7B    ";
	else if(Ar[j]==16)cout<<"7C    ";
	else if(Ar[j]==17)cout<<"6A    ";
	else if(Ar[j]==18)cout<<"6B    ";
	else if(Ar[j]==19)cout<<"6C    ";
	else if(Ar[j]==20)cout<<"5A    ";
	else if(Ar[j]==21)cout<<"5B    ";
	else if(Ar[j]==22)cout<<"5C    ";
	else if(Ar[j]==23)cout<<"4A    ";
	else if(Ar[j]==24)cout<<"4B    ";
	else if(Ar[j]==25)cout<<"4C    ";
	else if(Ar[j]==26)cout<<"3A    ";
	else if(Ar[j]==27)cout<<"3B    ";
	else if(Ar[j]==28)cout<<"3C    ";
	else if(Ar[j]==29)cout<<"2A    ";
	else if(Ar[j]==30)cout<<"2B    ";
	else if(Ar[j]==31)cout<<"2C    ";
	else if(Ar[j]==32)cout<<"1A    ";
	else if(Ar[j]==33)cout<<"1B    ";
	else if(Ar[j]==34)cout<<"1C    ";
	else cout<<"NA    ";
    }
	cout<<"\n\n";
  }

}

void roomzero()
{
	for(int i=0; i<9; i++)
	{
	mroom.mon[i]=0;
	mroom.tue[i]=0;
	mroom.wed[i]=0;
	mroom.thur[i]=0;
	mroom.fri[i]=0;
	biotech.mon[i]=0;
	biotech.tue[i]=0;
	biotech.wed[i]=0;
	biotech.thur[i]=0;
	biotech.fri[i]=0;
	avroom.mon[i]=0;
	avroom.tue[i]=0;
	avroom.wed[i]=0;
	avroom.thur[i]=0;
	avroom.fri[i]=0;
	ground.mon[i]=0;
	ground.tue[i]=0;
	ground.wed[i]=0;
	ground.thur[i]=0;
	ground.fri[i]=0;
	sstlab.mon[i]=0;
	sstlab.tue[i]=0;
	sstlab.wed[i]=0;
	sstlab.thur[i]=0;
	sstlab.fri[i]=0;
	audi.mon[i]=0;
	audi.tue[i]=0;
	audi.wed[i]=0;
	audi.thur[i]=0;
	audi.fri[i]=0;
	slab.mon[i]=0;
	slab.tue[i]=0;
	slab.wed[i]=0;
	slab.thur[i]=0;
	slab.fri[i]=0;
	artroom.mon[i]=0;
	artroom.tue[i]=0;
	artroom.wed[i]=0;
	artroom.thur[i]=0;
	artroom.fri[i]=0;
	mathlab.mon[i]=0;
	mathlab.tue[i]=0;
	mathlab.wed[i]=0;
	mathlab.thur[i]=0;
	mathlab.fri[i]=0;
	complab1.mon[i]=0;
	complab1.tue[i]=0;
	complab1.wed[i]=0;
	complab1.thur[i]=0;
	complab1.fri[i]=0;
	complab2.mon[i]=0;
	complab2.tue[i]=0;
	complab2.wed[i]=0;
	complab2.thur[i]=0;
	complab2.fri[i]=0;
	lib1.mon[i]=0;
	lib1.tue[i]=0;
	lib1.wed[i]=0;
	lib1.thur[i]=0;
	lib1.fri[i]=0;
	lib2.mon[i]=0;
	lib2.tue[i]=0;
	lib2.wed[i]=0;
	lib2.thur[i]=0;
	lib2.fri[i]=0;
	greenroom.mon[i]=0;
	greenroom.tue[i]=0;
	greenroom.wed[i]=0;
	greenroom.thur[i]=0;
	greenroom.fri[i]=0;
     }
}

void assembly(day &x, int ans3)
{
       static int f=0;
       if(ans3>0&&ans3<20)
       {
        x.wed[0]=100;
        if(f==0)
        x.thur[0]=0;

        }
       else {
            
       x.thur[0]=100; 
       if(f==0)x.wed[0]=0;}
       f++;
}

void teacherzero(day &x,int &ans2)
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
    if(j!=0)
    x.wed[j]=0;
    if(j!=0)
    x.thur[j]=0;
    x.fri[j]=0;
    }
    }
   

   k++;
}

char ans;

/*void classteacher()
{
 clrscr();
 cout<<"\nEnter class teacher for 12A: ";
 gets(a12a.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 12B: ";
 gets(b12b.classtea);
 cout<<"\nEnter associate teacher for 12B: ";
 gets(b12b.assoteacher);
 cout<<"\nEnter class teacher for 11A: ";
 gets(a11a.classtea);
 cout<<"\nEnter associate teacher for 11A: ";
 gets(a11a.assoteacher);
 cout<<"\nEnter class teacher for 11B: ";
 gets(b11b.classtea);
 cout<<"\nEnter associate teacher for 11B: ";
 gets(b11b.assoteacher);
 cout<<"\nEnter class teacher for 10A: ";
 gets(a10a.classtea);
 cout<<"\nEnter associate teacher for 10A: ";
 gets(a10a.assoteacher);
 cout<<"\nEnter class teacher for 10B: ";
 gets(b10b.classtea);
 cout<<"\nEnter associate teacher for 10B: ";
 gets(b10b.assoteacher);
 cout<<"\nEnter class teacher for 10C: ";
 gets(c10c.classtea);
 cout<<"\nEnter associate teacher for 10C: ";
 gets(c10c.assoteacher);
 cout<<"\nEnter class teacher for 9A: ";
 gets(a9a.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 9B: ";
 gets(b9b.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 9C: ";
 gets(c9c.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 8A: ";
 gets(a8a.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 8B: ";
 gets(b8b.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 8C: ";
 gets(c8c.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 7A: ";
 gets(a7a.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 7B: ";
 gets(b7b.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 7C: ";
 gets(c7c.classtea);
 cout<<"\nEnter associate teacher for 12A: ";
 gets(a12a.assoteacher);
 cout<<"\nEnter class teacher for 6A: ";
 gets(a6a.classtea);
 cout<<"\nEnter class teacher for 6B: ";
 gets(b6b.classtea);
 cout<<"\nEnter class teacher for 6C: ";
 gets(c6c.classtea);
 cout<<"\nEnter class teacher for 5A: ";
 gets(a5a.classtea);
 cout<<"\nEnter class teacher for 5B: ";
 gets(b5b.classtea);
 cout<<"\nEnter class teacher for 5C: ";
 gets(c5c.classtea);
 cout<<"\nEnter class teacher for 4A: ";
 gets(a4a.classtea);
 cout<<"\nEnter class teacher for 4B: ";
 gets(b4b.classtea);
 cout<<"\nEnter class teacher for 4C: ";
 gets(c4c.classtea);
 cout<<"\nEnter class teacher for 3A: ";
 gets(a3a.classtea);
 cout<<"\nEnter class teacher for 3B: ";
 gets(b3b.classtea);
 cout<<"\nEnter class teacher for 3C: ";
 gets(c3c.classtea);
 cout<<"\nEnter class teacher for 2A: ";
 gets(a2a.classtea);
 cout<<"\nEnter class teacher for 2B: ";
 gets(b2b.classtea);
 cout<<"\nEnter class teacher for 2C: ";
 gets(c2c.classtea);
 cout<<"\nEnter class teacher for 1A: ";
 gets(a1a.classtea);
 cout<<"\nEnter class teacher for 1B: ";
 gets(b1b.classtea);
 cout<<"\nEnter class teacher for 1C: ";
 gets(c1c.classtea);
 
 for(int i=1; i<=34; i++)
 {
  cout<<"\nEnter class teacher for
 */

void main()
{ roomzero();
 int answer;
do{
  clrscr();
  answer=menu();
  clrscr();
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

case 36:
int caseans;
do{
	clrscr();
	cout<<"\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n";
    cin>>caseans;
	
	if(caseans==1)display(a12a);
	else if(caseans==2)display(b12b);
	else if(caseans==3)display(a11a);
	else if(caseans==4)display(b11b);
	else if(caseans==5)display(a10a);
	else if(caseans==6)display(b10b);
	else if(caseans==7)display(c10c);
	else if(caseans==8)display(a9a);
	else if(caseans==9)display(b9b);
	else if(caseans==10)display(c9c);
	else if(caseans==11)display(a8a);
	else if(caseans==12)display(b8b);
	else if(caseans==13)display(c8c);
	else if(caseans==14)display(a7a);
	else if(caseans==15)display(b7b);
	else if(caseans==16)display(c7c);
	else if(caseans==17)display(a6a);
	else if(caseans==18)display(b6b);
	else if(caseans==19)display(c6c);
	else if(caseans==20)display(a5a);
	else if(caseans==21)display(b5b);
	else if(caseans==22)display(c5c);
	else if(caseans==23)display(a4a);
	else if(caseans==24)display(b4b);
	else if(caseans==25)display(c4c);
	else if(caseans==26)display(a3a);
	else if(caseans==27)display(b3b);
	else if(caseans==28)display(c3c);
	else if(caseans==29)display(a2a);
	else if(caseans==30)display(b2b);
	else if(caseans==31)display(c2c);
	else if(caseans==32)display(a1a);
	else if(caseans==33)display(b1b);
	else if(caseans==34)display(c1c);
	
	}while(ans=='y'); break;
	
case 37: substitution();break;

case 38: 
    clrscr();
	cout<<"\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n";
	cin>>caseans;
	clrscr();
	char ansday[3];
	cout<<"\nEnter day to be reset: \nMonday - mo\nTuesday- tu\nWednesday - we\nThursday - th\nFriday - fr\n";
	cin>>ansday;
	if(caseans==1)resettt(a12a,ansday,caseans);
	else if(caseans==2)resettt(b12b,ansday,caseans);
	else if(caseans==3)resettt(a11a,ansday,caseans);
	else if(caseans==4)resettt(b11b,ansday,caseans);
	else if(caseans==5)resettt(a10a,ansday,caseans);
	else if(caseans==6)resettt(b10b,ansday,caseans);
	else if(caseans==7)resettt(c10c,ansday,caseans);
	else if(caseans==8)resettt(a9a,ansday,caseans);
	else if(caseans==9)resettt(b9b,ansday,caseans);
	else if(caseans==10)resettt(c9c,ansday,caseans);
	else if(caseans==11)resettt(a8a,ansday,caseans);
	else if(caseans==12)resettt(b8b,ansday,caseans);
	else if(caseans==13)resettt(c8c,ansday,caseans);
	else if(caseans==14)resettt(a7a,ansday,caseans);
	else if(caseans==15)resettt(b7b,ansday,caseans);
	else if(caseans==16)resettt(c7c,ansday,caseans);
	else if(caseans==17)resettt(a6a,ansday,caseans);
	else if(caseans==18)resettt(b6b,ansday,caseans);
	else if(caseans==19)resettt(c6c,ansday,caseans);
	else if(caseans==20)resettt(a5a,ansday,caseans);
	else if(caseans==21)resettt(b5b,ansday,caseans);
	else if(caseans==22)resettt(c5c,ansday,caseans);
	else if(caseans==23)resettt(a4a,ansday,caseans);
	else if(caseans==24)resettt(b4b,ansday,caseans);
	else if(caseans==25)resettt(c4c,ansday,caseans);
	else if(caseans==26)resettt(a3a,ansday,caseans);
	else if(caseans==27)resettt(b3b,ansday,caseans);
	else if(caseans==28)resettt(c3c,ansday,caseans);
	else if(caseans==29)resettt(a2a,ansday,caseans);
	else if(caseans==30)resettt(b2b,ansday,caseans);
	else if(caseans==31)resettt(c2c,ansday,caseans);
	else if(caseans==32)resettt(a1a,ansday,caseans);
	else if(caseans==33)resettt(b1b,ansday,caseans);
	else if(caseans==34)resettt(c1c,ansday,caseans);
	cout<<"\nTimetable for the day requested has been successfully reset.";
	
	
	
case 39:
     newans='n'; break;
}
cout<<"\nDo you want to continue the timetable generator>> Yes(y) or No(n) ";
cin>>newans;
}while(newans=='y') ;

  int y;
  cin>>y;
}








