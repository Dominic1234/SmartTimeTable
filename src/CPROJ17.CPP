
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


struct teacher
{
    char name[40];
    int mon[9], tue[9], wed[9], thu[9], fri[9];//Stores the period taught by the teacher on a particular day   
    char subject[20];
    int mond[9], tues[9], wedn[9], thur[9], frid[9];//Stores the class taught by the teacher
};

struct day
{
    int mon[9], tue[9], wed[9], thur[9], fri[9];//stores subjects assigned to a particular class
    char classtea[40], assoteacher[40];
};

int count=-1, temp=-1;
int checkm=-1;
char newans;
int answer12312;
teacher sample[100];
day a12a,b12b,a11a, b11b,a10a,b10b,c10c,a9a,b9b,c9c,a8a,b8b,c8c,a7a,b7b,c7c,a6a,b6b,c6c,a5a,b5b,c5c,a4a,b4b,c4c,a3a,b3b,c3c,a2a,b2b,c2c,a1a,b1b,c1c;  //classes
day mroom, biotech, avroom, ground, sstlab, audi, slab, artroom, mathlab, complab1, complab2, lib1, lib2, greenroom; //Rooms

void teacherzero(day &x, int &ans2);
void algorithm(day &x);
void display(day &x, int &answer, int u,int v);
int input(day &x,char ch[3], int suanswer,int u);                 //Function Prototypes
int menu(int pass=0);
void initial2(day &x);
int search(char searcha[40], int k);
void inputweird(day &y,char yun[3],int su);
void assembly(day &x, int ans3);


void addclass(day &y,int su) //Add class function allows user to add a class to a period taken by another class
{  int pono;
    day x;
    clrscr();
    char yun[3];
    int aws;
    cout<<"\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n";
    cin>>aws;
    cout<<"\nEnter the period to be assigned to the class: ";
    cin>>pono;
    cout<<"\nEnter first two letters of the day\nMonday - mo\nTuesday - tu\nWednesday - we\nThursday - th\nFriday - fr\n\n";
    cin>>yun;
    if(aws==1) x=a12a;
    else if(aws==2) x=b12b;
    else if(aws==3) x=a11a;
    else if(aws==4) x=b11b;
    else if(aws==5) x=a10a;
    else if(aws==6) x=b10b;
    else if(aws==7) x=c10c;
    else if(aws==8) x=a9a;
    else if(aws==9) x=b9b;
    else if(aws==10) x=c9c;
    else if(aws==11) x=a8a;
    else if(aws==12) x=b8b;
    else if(aws==13) x=c8c;
    else if(aws==14) x=a7a;
    else if(aws==15) x=b7b;
    else if(aws==16) x=c7c;
    else if(aws==17) x=a6a;
    else if(aws==18) x=b6b;
    else if(aws==19) x=c6c;       //Depending on option chooses the necessary class
    else if(aws==20) x=a5a;
    else if(aws==21) x=b5b;
    else if(aws==22) x=c5c;
    else if(aws==23) x=a4a;
    else if(aws==24) x=b4b;
    else if(aws==25) x=c4c;
    else if(aws==26) x=a3a;
    else if(aws==27) x=b3b;
    else if(aws==28) x=c3c;
    else if(aws==29) x=a2a;
    else if(aws==30) x=b2b;
    else if(aws==31) x=c2c;
    else if(aws==32) x=a1a;
    else if(aws==33) x=b1b;
    else if(aws==34) x=c1c;

    if(x.mon[pono-1]==0||x.tue[pono-1]==0||x.wed[pono-1]==0||x.thur[pono-1]==0||x.fri[pono-1]==0) //Checks if the period requested is free
    {
        if(strcmpi(yun,"Mo")==0)
        x.mon[pono-1]=y.mon[pono-1];

        else if(strcmpi(yun,"Tu")==0)
        x.tue[pono-1]=y.tue[pono-1];


        else if(strcmpi(yun,"We")==0)
        x.wed[pono-1]=y.wed[pono-1];


        else if(strcmpi(yun,"Th")==0)
        x.thur[pono-1]=y.thur[pono-1];


        else if(strcmpi(yun,"Fr")==0)
        x.fri[pono-1]=y.fri[pono-1];

    }

    else
    cout<<"Cannot assign as class not free. Try for another period";
    if(aws==1) a12a=x;
    else if(aws==2) b12b=x;
    else if(aws==3) a11a=x;
    else if(aws==4) b11b=x;
    else if(aws==5) a10a=x;
    else if(aws==6) b10b=x;
    else if(aws==7) c10c=x;
    else if(aws==8) a9a=x;
    else if(aws==9) b9b=x;
    else if(aws==10) c9c=x;
    else if(aws==11) a8a=x;
    else if(aws==12) b8b=x;
    else if(aws==13) c8c=x;
    else if(aws==14) a7a=x;
    else if(aws==15) b7b=x;
    else if(aws==16) c7c=x;
    else if(aws==17) a6a=x;
    else if(aws==18) b6b=x;
    else if(aws==19) c6c=x;
    else if(aws==20) a5a=x;
    else if(aws==21) b5b=x;
    else if(aws==22) c5c=x;
    else if(aws==23) a4a=x;
    else if(aws==24) b4b=x;
    else if(aws==25) c4c=x;
    else if(aws==26) a3a=x;
    else if(aws==27) b3b=x;
    else if(aws==28) c3c=x;
    else if(aws==29) a2a=x;
    else if(aws==30) b2b=x;
    else if(aws==31) c2c=x;
    else if(aws==32) a1a=x;
    else if(aws==33) b1b=x;
    else if(aws==34) c1c=x;

}


void addteacher(day &y,int su) //Add teacher takes care of multiple teachers
{  int pono;
    char yun[3];
    cout<<"\nEnter the period to be assigned to the teacher: ";
    cin>>pono;
    cout<<"\nEnter first two letters of the day\nMonday - mo\nTuesday - tu\nWednesday - we\nThursday - th\nFriday - fr\n\n";
    cin>>yun;
    inputweird(y,yun,su);
    if(sample[count].mon[pono]==0||sample[count].tue[pono]==0||sample[count].wed[pono]==0||sample[count].thu[pono]==0||sample[count].fri[pono]==0)
    {
        if(strcmpi(yun,"Mo")==0)
        {

            sample[count].mon[pono-1]=y.mon[pono-1];            //Checks if teacher is free for requested period
            sample[count].mond[pono-1]=su;
        }
        else if(strcmpi(yun,"Tu")==0)
        {

            sample[count].tue[pono-1]=y.tue[pono-1];
            sample[count].tues[pono-1]=su;
        }
        else if(strcmpi(yun,"We")==0)
        {

            sample[count].wed[pono-1]=y.wed[pono-1];
            sample[count].wedn[pono-1]=su;
        }
        else if(strcmpi(yun,"Th")==0)
        {

            sample[count].thu[pono-1]=y.thur[pono-1];
            sample[count].thur[pono-1]=su;
        }
        else if(strcmpi(yun,"Fr")==0)
        {

            sample[count].fri[pono-1]=y.fri[pono-1];
            sample[count].frid[pono-1]=su;
        }

    }
    else
    cout<<"Cant Assign as teacher not free";
}


int initial()  //Used in initial assignment mode to call for assignment based on class chosen
{

    answer12312=menu(1);
    if(answer12312==1)
    initial2(a12a);
    else if(answer12312==2)
    initial2(b12b);
    else if(answer12312==3)
    initial2(a11a);
    else if(answer12312==4)
    initial2(b11b);
    else if(answer12312==5)
    initial2(a10a);
    else if(answer12312==6)
    initial2(b10b);
    else if(answer12312==7)
    initial2(c10c);
    else if(answer12312==8)
    initial2(a9a);
    else if(answer12312==9)
    initial2(b9b);
    else if(answer12312==10)
    initial2(c9c);
    else if(answer12312==11)
    initial2(a8a);
    else if(answer12312==12)
    initial2(b8b);
    else if(answer12312==13)
    initial2(c8c);
    else if(answer12312==14)
    initial2(a7a);
    else if(answer12312==15)
    initial2(b7b);
    else if(answer12312==16)
    initial2(c7c);
    else if(answer12312==17)
    initial2(a6a);
    else if(answer12312==18)
    initial2(b6b);
    else if(answer12312==19)
    initial2(c6c);
    else if(answer12312==20)
    initial2(a5a);
    else if(answer12312==21)
    initial2(b5b);
    else if(answer12312==22)
    initial2(c5c);
    else if(answer12312==23)
    initial2(a4a);
    else if(answer12312==24)
    initial2(b4b);
    else if(answer12312==25)
    initial2(c4c);
    else if(answer12312==26)
    initial2(a3a);
    else if(answer12312==27)
    initial2(b3b);
    else if(answer12312==28)
    initial2(c3c);
    else if(answer12312==29)
    initial2(a2a);
    else if(answer12312==30)
    initial2(b2b);
    else if(answer12312==31)
    initial2(c2c);
    else if(answer12312==32)
    initial2(a1a);
    else if(answer12312==33)
    initial2(b1b);
    else if(answer12312==34)
    initial2(c1c);
    else if(answer12312==35)return 1;
    else cout<<"Not available";

}

void initial2(day &x) //Is very similar to algorithm. See algorithm for details.
{   char subjecta[20];
    char dayt[3];
    int pno;
    int asss;
    int B[9],C[9],D[9],E[9];
    clrscr();
    cout<<"\nEnter number of periods you want to fix (Only 1):   ";
    cin>>pno;

    if(pno==1)
    {cout<<"\nEnter first two letters of the day\nMonday - mo\nTuesday - tu\nWednesday - we\nThursday - th\nFriday - fr\n\n";
    cin>>dayt;
    pno=input(x,dayt,answer12312,1);
    if(strcmpi(dayt,"Mo")==0)
    {for(int i=0;i<9;i++)
        {   B[i]=x.mon[i];
            C[i]=sample[count].mon[i];
            D[i]=sample[count].mond[i];
            E[i]=slab.mon[i];
        }
    }
    else if(strcmpi(dayt,"Tu")==0)
    {for(int i=0;i<9;i++)
        {   B[i]=x.tue[i];
            C[i]=sample[count].tue[i];
            D[i]=sample[count].tues[i];
            E[i]=slab.tue[i];
        }
    }
    else if(strcmpi(dayt,"We")==0)
    {for(int k=0;k<9;k++)
        {   B[k]=x.wed[k];
            C[k]=sample[count].wed[k];
            D[k]=sample[count].wedn[k];
            E[k]=slab.wed[k];
        }
    }
    else if(strcmpi(dayt,"Th")==0)
    {for(int i=0;i<9;i++)
        {   B[i]=x.thur[i];
            C[i]=sample[count].thu[i];
            D[i]=sample[count].thur[i];
            E[i]=slab.thur[i];
        }
    }
    else if(strcmpi(dayt,"Fr")==0)
    {for(int i=0;i<9;i++)
        {   B[i]=x.fri[i];
            C[i]=sample[count].fri[i];
            D[i]=sample[count].frid[i];
            E[i]=slab.fri[i];
        }
    }


    cout<<"Enter the period number to be assigned to this subject (1-9): ";
    cin>>asss;
    int flag=1;
    if((strcmpi(sample[count].subject,"sl")== 0))
    {
        if(E[asss-1]!=0)
        flag=0;
    }


    if(C[asss-1]==0&&B[asss-1]==0&&flag==1)
    {
        if(strcmpi(sample[count].subject,"Math")==0)
        {   B[asss-1]=1;
            C[asss-1]=1;
        }
        else if(strcmpi(sample[count].subject,"Chem")==0)
        {   B[asss-1]=2;
            C[asss-1]=2;
        }
        else if(strcmpi(sample[count].subject,"Eng")==0)
        {   B[asss-1]=3;
            C[asss-1]=3;
        }
        else if(strcmpi(sample[count].subject,"Phy")==0)
        {   B[asss-1]=4;
            C[asss-1]=4;
        }
        else if(strcmpi(sample[count].subject,"Comp")==0)
        {   B[asss-1]=5;
            C[asss-1]=5;
        }
        else if(strcmpi(sample[count].subject,"bio")==0)
        {   B[asss-1]=6;
            C[asss-1]=6;
        }
        else if(strcmpi(sample[count].subject,"elec")==0)
        {   B[asss-1]=7;
            C[asss-1]=7;
        }
        else if(strcmpi(sample[count].subject,"gs")==0)
        {   B[asss-1]=8;
            C[asss-1]=8;
        }
        else if(strcmpi(sample[count].subject,"ee")==0)
        {   B[asss-1]=9;
            C[asss-1]=9;
        }
        else if(strcmpi(sample[count].subject,"vpa")==0)
        {   B[asss-1]=10;
            C[asss-1]=10;
        }
        else if(strcmpi(sample[count].subject,"art")==0)
        {   B[asss-1]=11;
            C[asss-1]=11;
        }
        else if(strcmpi(sample[count].subject,"yoga")==0)
        {   B[asss-1]=12;
            C[asss-1]=12;
        }
        else if(strcmpi(sample[count].subject,"pt")==0)
        {   B[asss-1]=13;
            C[asss-1]=13;
        }
        else if(strcmpi(sample[count].subject,"club")==0)
        {   B[asss-1]=14;
            C[asss-1]=14;
        }
        else if(strcmpi(sample[count].subject,"lang")==0)
        {   B[asss-1]=15;
            C[asss-1]=15;
        }
        else if(strcmpi(sample[count].subject,"seclang")==0)
        {   B[asss-1]=16;
            C[asss-1]=16;
        }
        else if(strcmpi(sample[count].subject,"hist")==0)
        {   B[asss-1]=17;
            C[asss-1]=17;
        }
        else if(strcmpi(sample[count].subject,"civ")==0)
        {   B[asss-1]=18;
            C[asss-1]=18;
        }
        else if(strcmpi(sample[count].subject,"geo")==0)
        {   B[asss-1]=19;
            C[asss-1]=19;
        }
        else if(strcmpi(sample[count].subject,"ss")==0)
        {   B[asss-1]=20;
            C[asss-1]=20;
        }
        else if(strcmpi(sample[count].subject,"aep")==0)
        {   B[asss-1]=21;
            C[asss-1]=21;
        }
        else if(strcmpi(sample[count].subject,"evs")==0)
        {   B[asss-1]=22;
            C[asss-1]=22;
        }
        else if(strcmpi(sample[count].subject,"gsc")==0)
        {   B[asss-1]=23;
            C[asss-1]=23;
        }
        else if(strcmpi(sample[count].subject,"rp")==0)
        {   B[asss-1]=24;
            C[asss-1]=24;

        }
        else if(strcmpi(sample[count].subject,"im")==0)
        {   B[asss-1]=25;
            C[asss-1]=25;
        }
        else if(strcmpi(sample[count].subject,"wm")==0)
        {   B[asss-1]=26;
            C[asss-1]=26;
        }
        else if(strcmpi(sample[count].subject,"dan")==0)
        {   B[asss-1]=27;
            C[asss-1]=27;
        }
        else if(strcmpi(sample[count].subject,"ls")==0)
        {   B[asss-1]=28;
            C[asss-1]=28;
        }
        else if(strcmpi(sample[count].subject,"ml")==0)
        {   B[asss-1]=29;
            C[asss-1]=29;
        }
        else if(strcmpi(sample[count].subject,"mp")==0)
        {   B[asss-1]=30;
            C[asss-1]=30;
        }
        else if(strcmpi(sample[count].subject,"sl")==0)
        {   B[asss-1]=31;
            C[asss-1]=31;
            E[asss-1]=answer12312;
        }

        D[asss-1]=answer12312;
    }
    else
    {
        cout<<"\nThe period is already taken please specify another period by continuing.\n";
    }

    if(strcmpi(dayt,"Mo")==0)
    { for(int i=0;i<9;i++)
        {   x.mon[i]=B[i];
            sample[count].mon[i]=C[i];
            sample[count].mond[i]=D[i];
            slab.mon[i]=E[i];
        }
    }
    else if(strcmpi(dayt,"Tu")==0)
    { for(int i=0;i<9;i++)
        {   x.tue[i]=B[i];
            sample[count].tue[i]=C[i];
            sample[count].tues[i]=D[i];
            slab.tue[i]=E[i];
        }
    }
    else if(strcmpi(dayt,"We")==0)
    { for(int i=0;i<9;i++)
        {   x.wed[i]=B[i];
            sample[count].wed[i]=C[i];
            sample[count].wedn[i]=D[i];
            slab.wed[i]=E[i];
        }
    }
    else if(strcmpi(dayt,"Th")==0)
    { for(int i=0;i<9;i++)
        {   x.thur[i]=B[i];
            sample[count].thu[i]=C[i];
            sample[count].thur[i]=D[i];
            slab.thur[i]=E[i];
        }
    }
    else if(strcmpi(dayt,"Fr")==0)
    { for(int i=0;i<9;i++)
        {   x.fri[i]=B[i];
            sample[count].fri[i]=C[i];
            sample[count].frid[i]=D[i];
            slab.tue[i]=E[i];
        }
    }
}

display(x,answer12312,0,0) ;



}


void saveteacher(int P[9]) //Reserving a period
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



void resettt(day &x,char ch[3],int subb,int m=0) //resets the timetable for one day for one class or deletes 1 period as specified
{    int C[9], K[9];
    if(m==0)
    {  if(strcmpi(ch,"Mo")==0)
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
    }                                   //deletes timetable for requested day

    if(strcmpi(ch,"Th")==0)
    { for(int k=0;k<9;k++)
        x.thur[k]=0;
    }

    if(strcmpi(ch,"Fr")==0)
    { for(int k=0;k<9;k++)
        x.fri[k]=0;
    }
}
else
{
cout<<"\nEnter period number to be deleted:  ";
cin>>m;
if(strcmpi(ch,"Mo")==0)
x.mon[m-1]=0;
if(strcmpi(ch,"Tu")==0)
x.tue[m-1]=0;
if(strcmpi(ch,"We")==0)
x.wed[m-1]=0;                             //deletes specific period
if(strcmpi(ch,"Th")==0)
x.thur[m-1]=0;
if(strcmpi(ch,"Fr")==0)
x.fri[m-1]=0;
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
    else if(strcmpi(ch,"We")==0)            //stores teacher data in temporary arrays
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

    if(m==0)
    {
        for(int y=0; y<9;y++)
        {
            if(C[y]==subb)
            {
                C[y]=0;
                K[y]=0;                //if the class is taught by the teacher the temporary arrays are reset
            }
        }
    }
    else{

        if(C[m-1]==subb)
        {
            C[m-1]=0;
            K[m-1]=0;
        }
    }

    if(strcmpi(ch,"Mo")==0)
    {
        for(int j=0;j<9;j++)
        {
            sample[p].mon[j]=K[j];           //data is restored back to original teacher arrays
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





void substitution()  //Function to display all teachers available for substitution
{    clrscr();
    int subday;
    int periodno;
    cout<<"\nEnter day to generate substitution\nMonday - 1\nTuesday - 2\nWednesday - 3\nThursday - 4\nFriday - 5\n";
    cin>>subday;
    cout<<"\nWhich period needs to be substituted? Enter period number (1-9): ";
    cin>>periodno;
    int i;
    switch(subday)  //checks which day substitution asked for
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
                cout<<"\n"<<sample[i].name<<" is available"; //displays all teachers free in the required period by comparing with original array
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
    int menu(int pass) //displays the main menu
    { int answer;
        if(pass==0)
        {cout<<"Timetable generator\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n35.Display teacher timetable\n36.Display timetable for any class\n37.Check for substitution\n38.Reset any class timetable\n39.Manual Period assignment mode\n40.Add teacher\n41.Add class\n42.Delete\n43.Display Science Lab\n44.Exit\n\nEnter option number: ";
        cin>>answer;
        return answer;}
        else{cout<<"\nTimetable generator\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C\n35. Go to main generator     \n\nEnter option number: ";
        cin>>answer;
        return answer;
    }
}

int search(char searcha[40]="09389219", int k=0) //function to search for teacher. Regular logic
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
    } cout<<"Teacher does not exist.\nTry again.\nDisplaying first teacher's timetable as default protection case"<<endl;
    return 0;
}
return -1;
}


void inputweird(day &x,char ch[3], int suanswer) //input function utilized specifically for add teacher function
{
    if(temp>count)
    count=temp;
    count++;
    checkm++;
    teacherzero(x,suanswer);
    int subjectcount;
    cout<<"\nEnter name of the teacher:  ";
    cin>>sample[count].name;
    int store = search();
    if(store!=-1)
    {  count--;
        checkm--;
        temp=count;
        count=store;
    }
}

int input(day &x,char ch[3], int suanswer,int u=0) //Primary function that performs input operation
{   if(temp>count)
    count=temp;
    count++;
    checkm++;
    teacherzero(x,suanswer); //initializes the teacher's periods to zero value
    assembly(x, suanswer); //initializes assembly
    int subjectcount;
    cout<<"\nEnter name of the teacher:  ";
    cin>>sample[count].name;
    int store = search();
    if(store!=-1)
    { count--;                               //data taken
        checkm--;
        temp=count;
        count=store;
    }
    cout<<"\nEnter subject"<<endl<<"1. Physics - phy                   16. Second Lang elective grade 9-10 - seclang2. Chemistry - chem                17. History - hist\n3. Mathematics - math              18. Civics - civ\n4. English - eng                   19. Geography- geo\n5. Computer - comp                 20. Social studies (for grades below 6) - SS\n6. Biology - bio                   21. AEP - AEP\n7. Grade 11 elective - elec        22. EVS - EVS\n8. General studies - GS            23. Gen. Science - GSc\n9. EE - EE                         24. Reading period - RP\n10. VPA - VPA                      25. Indian Music - IM\n11. Art - art                      26. Western Music - WM\n12. Yoga - yoga                    27. Dance - Dan\n13. PT - PT                        28. Life Skills - LS\n14. Club - club                    29. Math lab - ML\n15. Third Language Elective - lang 30. March Past - MP\n                                   31. Science Lab - sl\n\n";
    cin>>sample[count].subject;
    if(u==0)
    {cout<<"\nEnter first two letters of the day\nMonday - mo\nTuesday - tu\nWednesday - we\nThursday - th\nFriday - fr\n\n";
    cin>>ch;
    cout<<"\nEnter no. of periods required for today: ";
    cin>>subjectcount;
    return subjectcount;
}
else
return 1;
}

int temp2=15;

void algorithm(day &x, int &subanswer)  //Primary Algorithm on which assignment of periods works
{ int subcount; //Stores no. of periods required
    int periodno;
    char say[3];
    subcount=input(x,say,subanswer);
    int A[9];//array for storing teacher's timetable
    int B[9];//array for storing class timetable
    int C[9];//array for storing which class the teacher teaches
    int D[9];
    if(strcmpi(say,"Mo")==0)
    { for(int i=0;i<9;i++)
        {   B[i]=x.mon[i];
            A[i]=sample[count].mon[i];              //stores data in temporary arrays based on day selected
            C[i]=sample[count].mond[i];
            D[i]=slab.mon[i];
        }
    }
    else if(strcmpi(say,"Tu")==0)
    { for(int j=0;j<9;j++)
        {   B[j]=x.tue[j];
            A[j]=sample[count].tue[j];
            C[j]=sample[count].tues[j];
            D[j]=slab.tue[j];
        }
    }
    else if(strcmpi(say,"We")==0)
    { for(int k=0;k<9;k++)
        {   B[k]=x.wed[k];
            A[k]=sample[count].wed[k];
            C[k]=sample[count].wedn[k];
            D[k]=slab.wed[k];
        }
    }
    else if(strcmpi(say,"Th")==0)
    { for(int i=0;i<9;i++)
        {   B[i]=x.thur[i];
            A[i]=sample[count].thu[i];
            C[i]=sample[count].thur[i];
            D[i]=slab.thur[i];

        }
    }
    else if(strcmpi(say,"Fr")==0)
    { for(int i=0;i<9;i++)
        {   B[i]=x.fri[i];
            A[i]=sample[count].fri[i];
            C[i]=sample[count].frid[i];
            D[i]=slab.fri[i];
        }
    }

    long double idiot =0;
    int flag=0;
    int mag;
    for(int i=0; i<subcount; i++) //for loop that does the assignment of the period "subcount" number of times 
    {
        idiot++;
        if(idiot==5000000)
        {
            flag=1;                 //High number of iterations to tackle errors when entering data. Will lead to error message
            break;
        }
        saveteacher(A);randomize();
        periodno=random(9999)+1;  //randomize generates random value and divides by 9 to get a number from 0 to 8 which are index values for period number
        periodno=periodno%9;
        if(periodno==0)
        periodno=9;
         mag=1;
        if(strcmpi(sample[count].subject,"sl")==0)
        {  if(D[periodno-1]!=0)
            mag=0;
        }
        if(A[periodno-1]==0&&mag==1) //if teacher is free
        {
            if(B[periodno-1]==0)   //if class is free
            { C[periodno-1]=subanswer;
                if(strcmpi(sample[count].subject,"Math")==0)
                {   B[periodno-1]=1;
                    A[periodno-1]=1;
                }
                else if(strcmpi(sample[count].subject,"Chem")==0)
                {   B[periodno-1]=2;
                    A[periodno-1]=2;
                }
                else if(strcmpi(sample[count].subject,"Eng")==0)
                {   B[periodno-1]=3;
                    A[periodno-1]=3;
                }
                else if(strcmpi(sample[count].subject,"Phy")==0)
                {   B[periodno-1]=4;
                    A[periodno-1]=4;
                }
                else if(strcmpi(sample[count].subject,"Comp")==0)     //assigns subject to class and teacher based on subject chosen
                {   B[periodno-1]=5;
                    A[periodno-1]=5;
                }
                else if(strcmpi(sample[count].subject,"bio")==0)
                {   B[periodno-1]=6;
                    A[periodno-1]=6;
                }
                else if(strcmpi(sample[count].subject,"elec")==0)
                {   B[periodno-1]=7;
                    A[periodno-1]=7;
                }
                else if(strcmpi(sample[count].subject,"gs")==0)
                {   B[periodno-1]=8;
                    A[periodno-1]=8;
                }
                else if(strcmpi(sample[count].subject,"ee")==0)
                {   B[periodno-1]=9;
                    A[periodno-1]=9;
                }
                else if(strcmpi(sample[count].subject,"vpa")==0)
                {   B[periodno-1]=10;
                    A[periodno-1]=10;
                }
                else if(strcmpi(sample[count].subject,"art")==0)
                {   B[periodno-1]=11;
                    A[periodno-1]=11;
                }
                else if(strcmpi(sample[count].subject,"yoga")==0)
                {   B[periodno-1]=12;
                    A[periodno-1]=12;
                }
                else if(strcmpi(sample[count].subject,"pt")==0)
                {   B[periodno-1]=13;
                    A[periodno-1]=13;
                }
                else if(strcmpi(sample[count].subject,"club")==0)
                {   B[periodno-1]=14;
                    A[periodno-1]=14;
                }
                else if(strcmpi(sample[count].subject,"lang")==0)
                {   B[periodno-1]=15;
                    A[periodno-1]=15;
                }
                else if(strcmpi(sample[count].subject,"seclang")==0)
                {   B[periodno-1]=16;
                    A[periodno-1]=16;
                }
                else if(strcmpi(sample[count].subject,"hist")==0)
                {   B[periodno-1]=17;
                    A[periodno-1]=17;
                }
                else if(strcmpi(sample[count].subject,"civ")==0)
                {   B[periodno-1]=18;
                    A[periodno-1]=18;
                }
                else if(strcmpi(sample[count].subject,"geo")==0)
                {   B[periodno-1]=19;
                    A[periodno-1]=19;
                }
                else if(strcmpi(sample[count].subject,"ss")==0)
                {   B[periodno-1]=20;
                    A[periodno-1]=20;
                }
                else if(strcmpi(sample[count].subject,"aep")==0)
                {   B[periodno-1]=21;
                    A[periodno-1]=21;
                }
                else if(strcmpi(sample[count].subject,"evs")==0)
                {   B[periodno-1]=22;
                    A[periodno-1]=22;
                }
                else if(strcmpi(sample[count].subject,"gsc")==0)
                {   B[periodno-1]=23;
                    A[periodno-1]=23;
                }
                else if(strcmpi(sample[count].subject,"rp")==0)
                {   B[periodno-1]=24;
                    A[periodno-1]=24;
                }
                else if(strcmpi(sample[count].subject,"im")==0)
                {   B[periodno-1]=25;
                    A[periodno-1]=25;
                }
                else if(strcmpi(sample[count].subject,"wm")==0)
                {   B[periodno-1]=26;
                    A[periodno-1]=26;
                }
                else if(strcmpi(sample[count].subject,"dan")==0)
                {   B[periodno-1]=27;
                    A[periodno-1]=27;
                }
                else if(strcmpi(sample[count].subject,"ls")==0)
                {   B[periodno-1]=28;
                    A[periodno-1]=28;
                }
                else if(strcmpi(sample[count].subject,"ml")==0)
                {   B[periodno-1]=29;
                    A[periodno-1]=29;
                }
                else if(strcmpi(sample[count].subject,"mp")==0)
                {   B[periodno-1]=30;
                    A[periodno-1]=30;
                }
                else if(strcmpi(sample[count].subject,"sl")==0)
                {   B[periodno-1]=31;
                    A[periodno-1]=31;
                    D[periodno-1]=subanswer;
                }

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
        {   x.mon[i]=B[i];
            sample[count].mon[i]=A[i];
            sample[count].mond[i]=C[i];
            slab.mon[i]=D[i];
        }
    }
    else if(strcmpi(say,"Tu")==0)
    { for(int i=0;i<9;i++)                            //restore data to the original arrays
        {   x.tue[i]=B[i];
            sample[count].tue[i]=A[i];
            sample[count].tues[i]=C[i];
            slab.tue[i]=D[i];
        }
    }
    else if(strcmpi(say,"We")==0)
    { for(int i=0;i<9;i++)
        {   x.wed[i]=B[i];
            sample[count].wed[i]=A[i];
            sample[count].wedn[i]=C[i];
            slab.wed[i]=D[i];
        }
    }
    else if(strcmpi(say,"Th")==0)
    { for(int i=0;i<9;i++)
        {   x.thur[i]=B[i];
            sample[count].thu[i]=A[i];
            sample[count].thur[i]=C[i];
            slab.thur[i]=D[i];
        }
    }
    else if(strcmpi(say,"Fr")==0)
    { for(int i=0;i<9;i++)
        {   x.fri[i]=B[i];
            sample[count].fri[i]=A[i];
            sample[count].frid[i]=C[i];
            slab.fri[i]=D[i];
        }
    }
    if(flag==1)  //if error is found it will recommend a reset of the day
    { char y;
        cout<<"We recommend that the day be reset. Do you want to reset the timetable for this day? (y/n) ";
        cin>>y;
        if(y=='y'||y=='Y')
        {
            cout<<"The day has been reset due to teacher unavailability. \nPlease enter details again. ";
            resettt(x,say,subanswer);
        }
    }
}
void displaylab() //Function to display Science Lab Timetable
{
    int A[9];
    cout<<"\n     1     2     3    |4     5     6    |7     8     9\n";
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
                A[q]=slab.mon[q];
            }
            else if(i==2)
            { for(int q=0;q<9;q++)
                A[q]=slab.tue[q];
            }
            else if(i==3)
            { for(int q=0;q<9;q++)
                A[q]=slab.wed[q];
            }
            else if(i==4)
            { for(int q=0;q<9;q++)
                A[q]=slab.thur[q];
            }
            else if(i==5)
            { for(int q=0;q<9;q++)
                A[q]=slab.fri[q];
            }
        }
        for(j=0; j<9; j++)
        {
            if(A[j]==1){if(j==2||j==5)cout<<"12A  |";else cout<<"12A   ";}
            else if(A[j]==2){if(j==2||j==5)cout<<"12B  |";else cout<<"12B   ";}
            else if(A[j]==3){if(j==2||j==5)cout<<"11A  |";else cout<<"11A   ";}
            else if(A[j]==4){if(j==2||j==5)cout<<"11B  |";else cout<<"11B   ";}
            else if(A[j]==5){if(j==2||j==5)cout<<"10A  |";else cout<<"10A   ";}
            else if(A[j]==6){if(j==2||j==5)cout<<"10B  |";else cout<<"10B   ";}
            else if(A[j]==7){if(j==2||j==5)cout<<"10C  |";else cout<<"10C   ";}
            else if(A[j]==8){if(j==2||j==5)cout<<"9A   |";else cout<<"9A    ";}
            else if(A[j]==9){if(j==2||j==5)cout<<"9B   |";else cout<<"9B    ";}
            else if(A[j]==10){if(j==2||j==5)cout<<"9C   |";else cout<<"9C    ";}
            else if(A[j]==11){if(j==2||j==5)cout<<"8A   |";else cout<<"8A    ";}
            else if(A[j]==12){if(j==2||j==5)cout<<"8B   |";else cout<<"8B    ";}
            else if(A[j]==13){if(j==2||j==5)cout<<"8C   |";else cout<<"8C    ";}
            else if(A[j]==14){if(j==2||j==5)cout<<"7A   |";else cout<<"7A    ";}
            else if(A[j]==15){if(j==2||j==5)cout<<"7B   |";else cout<<"7B    ";}
            else if(A[j]==16){if(j==2||j==5)cout<<"7C   |";else cout<<"7C    ";}
            else if(A[j]==17){if(j==2||j==5)cout<<"6A   |";else cout<<"6A    ";}
            else if(A[j]==18){if(j==2||j==5)cout<<"6B   |";else cout<<"6B    ";}
            else if(A[j]==19){if(j==2||j==5)cout<<"6C   |";else cout<<"6C    ";}
            else if(A[j]==20){if(j==2||j==5)cout<<"5A   |";else cout<<"5A    ";}
            else if(A[j]==21){if(j==2||j==5)cout<<"5B   |";else cout<<"5B    ";}
            else if(A[j]==22){if(j==2||j==5)cout<<"5C   |";else cout<<"5C    ";}
            else if(A[j]==23){if(j==2||j==5)cout<<"4A   |";else cout<<"4A    ";}
            else if(A[j]==24){if(j==2||j==5)cout<<"4B   |";else cout<<"4B    ";}
            else if(A[j]==25){if(j==2||j==5)cout<<"4C   |";else cout<<"4C    ";}
            else if(A[j]==26){if(j==2||j==5)cout<<"3A   |";else cout<<"3A    ";}
            else if(A[j]==27){if(j==2||j==5)cout<<"3B   |";else cout<<"3B    ";}
            else if(A[j]==28){if(j==2||j==5)cout<<"3C   |";else cout<<"3C    ";}
            else if(A[j]==29){if(j==2||j==5)cout<<"2A   |";else cout<<"2A    ";}
            else if(A[j]==30){if(j==2||j==5)cout<<"2B   |";else cout<<"2B    ";}
            else if(A[j]==31){if(j==2||j==5)cout<<"2C   |";else cout<<"2C    ";}
            else if(A[j]==32){if(j==2||j==5)cout<<"1A   |";else cout<<"1A    ";}
            else if(A[j]==33){if(j==2||j==5)cout<<"1B   |";else cout<<"1B    ";}
            else if(A[j]==34){if(j==2||j==5)cout<<"1C   |";else cout<<"1C    ";}
			else {if(j==2||j==5)cout<<"NA   |";else cout<<"NA    ";}
        }
		cout<<endl;
    }
}





void display(day &x, int &subanswer, int u=0,int v=0) //Function to display the timetable of a class
{
    int A[9];
    cout<<"\n     1     2     3    |4     5     6    |7     8     9\n";
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
            {
                if(j==2||j==5)
                cout<<"Math |";
                else
                cout<<"Math  ";
            }
            else if(A[j]==2)
            {
                if(j==2||j==5)
                cout<<"Chem |";
                else
                cout<<"Chem  ";
            }
            else if(A[j]==3)
            {
                if(j==2||j==5)
                cout<<"Eng  |";
                else
                cout<<"Eng   ";
            }
            else if(A[j]==4)
            {
                if(j==2||j==5)
                cout<<"Phy  |";
                else
                cout<<"Phy   ";
            }
            else if(A[j]==5)
            {
                if(j==2||j==5)
                cout<<"Comp |";
                else
                cout<<"Comp  ";
            }
            else if(A[j]==6)
            {
                if(j==2||j==5)
                cout<<"Bio  |";
                else
                cout<<"Bio   ";
            }
            else if(A[j]==7)
            {
                if(j==2||j==5)
                cout<<"Elec |";
                else
                cout<<"Elec  ";
            }
            else if(A[j]==8)
            {
                if(j==2||j==5)
                cout<<"GS   |";
                else
                cout<<"GS    ";
            }
            else if(A[j]==9)
            {
                if(j==2||j==5)
                cout<<"EE   |";
                else
                cout<<"EE    ";
            }
            else if(A[j]==10)
            {
                if(j==2||j==5)
                cout<<"VPA  |";
                else
                cout<<"VPA   ";
            }
            else if(A[j]==11)
            {
                if(j==2||j==5)
                cout<<"Art  |";
                else
                cout<<"Art   ";
            }
            else if(A[j]==12)
            {
                if(j==2||j==5)
                cout<<"Yoga |";
                else
                cout<<"Yoga  ";
            }
            else if(A[j]==13)
            {
                if(j==2||j==5)
                cout<<"PT   |";
                else
                cout<<"PT    ";
            }
            else if(A[j]==14)
            {
                if(j==2||j==5)
                cout<<"Club |";
                else
                cout<<"Club  ";
            }
            else if(A[j]==15)
            {
                if(j==2||j==5)
                cout<<"3rd  |";
                else
                cout<<"3rd   ";
            }
            else if(A[j]==16)
            {
                if(j==2||j==5)
                cout<<"II L |";
                else
                cout<<"II L  ";
            }
            else if(A[j]==100)
            cout<<"Ass   ";
            else if(A[j]==30)
            {
                if(j==2||j==5)
                cout<<"MP   |";
                else
                cout<<"MP    ";
            }
            else if(A[j]==17)
            {
                if(j==2||j==5)
                cout<<"His  |";
                else
                cout<<"His   ";
            }
            else if(A[j]==18)
            {
                if(j==2||j==5)
                cout<<"Civ  |";
                else
                cout<<"Civ   ";
            }
            else if(A[j]==19)
            {
                if(j==2||j==5)
                cout<<"Geo  |";
                else
                cout<<"Geo   ";
            }
            else if(A[j]==20)
            {
                if(j==2||j==5)
                cout<<"SS   |";
                else
                cout<<"SS    ";
            }
            else if(A[j]==21)
            {
                if(j==2||j==5)
                cout<<"AEP  |";
                else
                cout<<"AEP   ";
            }
            else if(A[j]==22)
            {
                if(j==2||j==5)
                cout<<"EVS  |";
                else
                cout<<"EVS   ";
            }
            else if(A[j]==23)
            {
                if(j==2||j==5)
                cout<<"GSc  |";
                else
                cout<<"GSc   ";
            }
            else if(A[j]==24)
            {
                if(j==2||j==5)
                cout<<"RP   |";
                else
                cout<<"RP    ";
            }
            else if(A[j]==25)
            {
                if(j==2||j==5)
                cout<<"IM   |";
                else
                cout<<"IM    ";
            }
            else if(A[j]==26)
            {
                if(j==2||j==5)
                cout<<"WM   |";
                else
                cout<<"WM    ";
            }
            else if(A[j]==27)
            {
                if(j==2||j==5)
                cout<<"Dan  |";
                else
                cout<<"Dan   ";
            }
            else if(A[j]==28)
            {
                if(j==2||j==5)
                cout<<"LS   |";
                else
                cout<<"LS    ";
            }
            else if(A[j]==29)
            {
                if(j==2||j==5)
                cout<<"ML   |";
                else
                cout<<"ML    ";
            }
            else if(i==123)
            {
                if(j==2||j==5)
                cout<<"R    |";
                else
                cout<<"R     ";
            }
            else if(A[j]==31)
            {
                if(j==2||j==5)
                cout<<"ScLab|";
                else
                cout<<"ScLab ";
            }
            else
            {
                if(j==2||j==5)
                cout<<"NA   |";
                else
                cout<<"NA    ";}

            }
            cout<<"\n";
        }
        if(u==0)
        { char response;
            do
            {
                if(v!=2) //part that is executed when display is called in add teacher or class function
                {
                    cout<<"\nIs there another teacher teaching this class for the periods assigned? (y/n) ";
                    cin>>response;
                    if(response=='y'||response=='Y')
                    addteacher(x,subanswer);
                }
                if(v!=1)
                {
                    cout<<"\nIs there another class to be assigned same period (y/n) ";
                    cin>>response;
                    if(response=='y'||response=='Y')
                    addclass(x,subanswer);
                }
            }while(response=='y'||response=='Y');
        }
    }

    void displayteacher(int &x) //Function to display teacher timetable
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
                {
                    if(j==2||j==5)
                    cout<<"Math |";
                    else
                    cout<<"Math  ";
                }
                else if(A[j]==2)
                {
                    if(j==2||j==5)
                    cout<<"Chem |";
                    else
                    cout<<"Chem  ";
                }
                else if(A[j]==3)
                {
                    if(j==2||j==5)
                    cout<<"Eng  |";
                    else
                    cout<<"Eng   ";
                }
                else if(A[j]==4)
                {
                    if(j==2||j==5)
                    cout<<"Phy  |";
                    else
                    cout<<"Phy   ";
                }
                else if(A[j]==5)
                {
                    if(j==2||j==5)
                    cout<<"Comp |";
                    else
                    cout<<"Comp  ";
                }
                else if(A[j]==6)
                {
                    if(j==2||j==5)
                    cout<<"Bio  |";
                    else
                    cout<<"Bio   ";
                }
                else if(A[j]==7)
                {
                    if(j==2||j==5)
                    cout<<"Elec |";
                    else
                    cout<<"Elec  ";
                }
                else if(A[j]==8)
                {
                    if(j==2||j==5)
                    cout<<"GS   |";
                    else
                    cout<<"GS    ";
                }
                else if(A[j]==9)
                {
                    if(j==2||j==5)
                    cout<<"EE   |";
                    else
                    cout<<"EE    ";
                }
                else if(A[j]==10)
                {
                    if(j==2||j==5)
                    cout<<"VPA  |";
                    else
                    cout<<"VPA   ";
                }
                else if(A[j]==11)
                {
                    if(j==2||j==5)
                    cout<<"Art  |";
                    else
                    cout<<"Art   ";
                }
                else if(A[j]==12)
                {
                    if(j==2||j==5)
                    cout<<"Yoga |";
                    else
                    cout<<"Yoga  ";
                }
                else if(A[j]==13)
                {
                    if(j==2||j==5)
                    cout<<"PT   |";
                    else
                    cout<<"PT    ";
                }
                else if(A[j]==14)
                {
                    if(j==2||j==5)
                    cout<<"Club |";
                    else
                    cout<<"Club  ";
                }
                else if(A[j]==15)
                {
                    if(j==2||j==5)
                    cout<<"3rd  |";
                    else
                    cout<<"3rd   ";
                }
                else if(A[j]==16)
                {
                    if(j==2||j==5)
                    cout<<"II L |";
                    else
                    cout<<"II L  ";
                }
                else if(A[j]==100)
                cout<<"Ass   ";
                else if(A[j]==30)
                {
                    if(j==2||j==5)
                    cout<<"MP   |";
                    else
                    cout<<"MP    ";
                }
                else if(A[j]==17)
                {
                    if(j==2||j==5)
                    cout<<"His  |";
                    else
                    cout<<"His   ";
                }
                else if(A[j]==18)
                {
                    if(j==2||j==5)
                    cout<<"Civ  |";
                    else
                    cout<<"Civ   ";
                }
                else if(A[j]==19)
                {
                    if(j==2||j==5)
                    cout<<"Geo  |";
                    else
                    cout<<"Geo   ";
                }
                else if(A[j]==20)
                {
                    if(j==2||j==5)
                    cout<<"SS   |";
                    else
                    cout<<"SS    ";
                }
                else if(A[j]==21)
                {
                    if(j==2||j==5)
                    cout<<"AEP  |";
                    else
                    cout<<"AEP   ";
                }
                else if(A[j]==22)
                {
                    if(j==2||j==5)
                    cout<<"EVS  |";
                    else
                    cout<<"EVS   ";
                }
                else if(A[j]==23)
                {
                    if(j==2||j==5)
                    cout<<"GSc  |";
                    else
                    cout<<"GSc   ";
                }
                else if(A[j]==24)
                {
                    if(j==2||j==5)
                    cout<<"RP   |";
                    else
                    cout<<"RP    ";
                }
                else if(A[j]==25)
                {
                    if(j==2||j==5)
                    cout<<"IM   |";
                    else
                    cout<<"IM    ";
                }
                else if(A[j]==26)
                {
                    if(j==2||j==5)
                    cout<<"WM   |";
                    else
                    cout<<"WM    ";
                }
                else if(A[j]==27)
                {
                    if(j==2||j==5)
                    cout<<"Dan  |";
                    else
                    cout<<"Dan   ";
                }
                else if(A[j]==28)
                {
                    if(j==2||j==5)
                    cout<<"LS   |";
                    else
                    cout<<"LS    ";
                }
                else if(A[j]==29)
                {
                    if(j==2||j==5)
                    cout<<"ML   |";
                    else
                    cout<<"ML    ";
                }
                else if(i==123)
                {
                    if(j==2||j==5)
                    cout<<"R    |";
                    else
                    cout<<"R     ";
                }
                else if(A[j]==31)
                {
                    if(j==2||j==5)
                    cout<<"ScLab|";
                    else
                    cout<<"ScLab ";
                }
                else
                {
                    if(j==2||j==5)
                    cout<<"NA   |";
                    else
                    cout<<"NA    ";}
                }
                cout<<"\n     ";
                for(j=0; j<9; j++)
                {
                    if(Ar[j]==1){if(j==2||j==5)cout<<"12A  |";else cout<<"12A   ";}
                    else if(Ar[j]==2){if(j==2||j==5)cout<<"12B  |";else cout<<"12B   ";}
                    else if(Ar[j]==3){if(j==2||j==5)cout<<"11A  |";else cout<<"11A   ";}
                    else if(Ar[j]==4){if(j==2||j==5)cout<<"11B  |";else cout<<"11B   ";}
                    else if(Ar[j]==5){if(j==2||j==5)cout<<"10A  |";else cout<<"10A   ";}
                    else if(Ar[j]==6){if(j==2||j==5)cout<<"10B  |";else cout<<"10B   ";}
                    else if(Ar[j]==7){if(j==2||j==5)cout<<"10C  |";else cout<<"10C   ";}
                    else if(Ar[j]==8){if(j==2||j==5)cout<<"9A   |";else cout<<"9A    ";}
                    else if(Ar[j]==9){if(j==2||j==5)cout<<"9B   |";else cout<<"9B    ";}
                    else if(Ar[j]==10){if(j==2||j==5)cout<<"9C   |";else cout<<"9C    ";}
                    else if(Ar[j]==11){if(j==2||j==5)cout<<"8A   |";else cout<<"8A    ";}
                    else if(Ar[j]==12){if(j==2||j==5)cout<<"8B   |";else cout<<"8B    ";}
                    else if(Ar[j]==13){if(j==2||j==5)cout<<"8C   |";else cout<<"8C    ";}
                    else if(Ar[j]==14){if(j==2||j==5)cout<<"7A   |";else cout<<"7A    ";}
                    else if(Ar[j]==15){if(j==2||j==5)cout<<"7B   |";else cout<<"7B    ";}
                    else if(Ar[j]==16){if(j==2||j==5)cout<<"7C   |";else cout<<"7C    ";}
                    else if(Ar[j]==17){if(j==2||j==5)cout<<"6A   |";else cout<<"6A    ";}
                    else if(Ar[j]==18){if(j==2||j==5)cout<<"6B   |";else cout<<"6B    ";}
                    else if(Ar[j]==19){if(j==2||j==5)cout<<"6C   |";else cout<<"6C    ";}
                    else if(Ar[j]==20){if(j==2||j==5)cout<<"5A   |";else cout<<"5A    ";}
                    else if(Ar[j]==21){if(j==2||j==5)cout<<"5B   |";else cout<<"5B    ";}
                    else if(Ar[j]==22){if(j==2||j==5)cout<<"5C   |";else cout<<"5C    ";}
                    else if(Ar[j]==23){if(j==2||j==5)cout<<"4A   |";else cout<<"4A    ";}
                    else if(Ar[j]==24){if(j==2||j==5)cout<<"4B   |";else cout<<"4B    ";}
                    else if(Ar[j]==25){if(j==2||j==5)cout<<"4C   |";else cout<<"4C    ";}
                    else if(Ar[j]==26){if(j==2||j==5)cout<<"3A   |";else cout<<"3A    ";}
                    else if(Ar[j]==27){if(j==2||j==5)cout<<"3B   |";else cout<<"3B    ";}
                    else if(Ar[j]==28){if(j==2||j==5)cout<<"3C   |";else cout<<"3C    ";}
                    else if(Ar[j]==29){if(j==2||j==5)cout<<"2A   |";else cout<<"2A    ";}
                    else if(Ar[j]==30){if(j==2||j==5)cout<<"2B   |";else cout<<"2B    ";}
                    else if(Ar[j]==31){if(j==2||j==5)cout<<"2C   |";else cout<<"2C    ";}
                    else if(Ar[j]==32){if(j==2||j==5)cout<<"1A   |";else cout<<"1A    ";}
                    else if(Ar[j]==33){if(j==2||j==5)cout<<"1B   |";else cout<<"1B    ";}
                    else if(Ar[j]==34){if(j==2||j==5)cout<<"1C   |";else cout<<"1C    ";}
                    else {if(j==2||j==5)cout<<"NA   |";else cout<<"NA    ";}
                }
                cout<<"\n\n";
            }

        }

        void roomzero() //initializes the rooms to zero value
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

        void assembly(day &x, int ans3) //initializes assembly
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

            void teacherzero(day &x,int &ans2) //initializes teacher's timetable to zero value
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

            void main() //main function
            { roomzero();
                day x;
                int answer,ansq;
                do{ clrscr();
                    cout<<"INTIAL PERIOD ASSIGNMENT MODE\nIn this mode you can manually assign periods as and when required\n";
                    int z=initial();
                    if(z==1)break;
                    cout<<"Continue? Yes -> 1    No -> 0  ";
                    cin>>ansq;
                }while(ansq==1);
                do{
                    clrscr();
                    answer=menu();
                    clrscr();
                    if(answer==1) x=a12a;
                    else if(answer==2) x=b12b;
                    else if(answer==3) x=a11a;
                    else if(answer==4) x=b11b;
                    else if(answer==5) x=a10a;
                    else if(answer==6) x=b10b;
                    else if(answer==7) x=c10c;
                    else if(answer==8) x=a9a;
                    else if(answer==9) x=b9b;
                    else if(answer==10) x=c9c;
                    else if(answer==11) x=a8a;
                    else if(answer==12) x=b8b;
                    else if(answer==13) x=c8c;
                    else if(answer==14) x=a7a;
                    else if(answer==15) x=b7b;
                    else if(answer==16) x=c7c;
                    else if(answer==17)  x=a6a;
                    else if(answer==18)  x=b6b;
                    else if(answer==19)  x=c6c;
                    else if(answer==20)  x=a5a;
                    else if(answer==21) x=b5b;
                    else if(answer==22) x=c5c;
                    else if(answer==23)  x=a4a;
                    else if(answer==24)  x=b4b;
                    else if(answer==25)  x=c4c;
                    else if(answer==26)  x=a3a;
                    else if(answer==27)  x=b3b;
                    else if(answer==28) x=c3c;
                    else if(answer==29)    x=a2a;
                    else if(answer==30)   x=b2b;
                    else if(answer==31)   x=c2c;
                    else if(answer==32)   x=a1a;
                    else if(answer==33)   x=b1b;
                    else if(answer==34)   x=c1c;
                    int answer1=answer;
                    if (answer>=1&&answer<=34)
                    answer=1;
                    int q=1;
                    if(answer==41)
                    {  answer=40;
                        q=2;
                    }

                    switch(answer)
                    {
                        case 1:
                        do{
                            algorithm(x,answer1);
                            display(x,answer1,0,0);
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

                            if(caseans==1)display(a12a,answer,1);
                            else if(caseans==2)display(b12b,answer,1);
                            else if(caseans==3)display(a11a,answer,1);
                            else if(caseans==4)display(b11b,answer,1);
                            else if(caseans==5)display(a10a,answer,1);
                            else if(caseans==6)display(b10b,answer,1);
                            else if(caseans==7)display(c10c,answer,1);
                            else if(caseans==8)display(a9a,answer,1);
                            else if(caseans==9)display(b9b,answer,1);
                            else if(caseans==10)display(c9c,answer,1);
                            else if(caseans==11)display(a8a,answer,1);
                            else if(caseans==12)display(b8b,answer,1);
                            else if(caseans==13)display(c8c,answer,1);
                            else if(caseans==14)display(a7a,answer,1);
                            else if(caseans==15)display(b7b,answer,1);
                            else if(caseans==16)display(c7c,answer,1);
                            else if(caseans==17)display(a6a,answer,1);
                            else if(caseans==18)display(b6b,answer,1);
                            else if(caseans==19)display(c6c,answer,1);
                            else if(caseans==20)display(a5a,answer,1);
                            else if(caseans==21)display(b5b,answer,1);
                            else if(caseans==22)display(c5c,answer,1);
                            else if(caseans==23)display(a4a,answer,1);
                            else if(caseans==24)display(b4b,answer,1);
                            else if(caseans==25)display(c4c,answer,1);
                            else if(caseans==26)display(a3a,answer,1);
                            else if(caseans==27)display(b3b,answer,1);
                            else if(caseans==28)display(c3c,answer,1);
                            else if(caseans==29)display(a2a,answer,1);
                            else if(caseans==30)display(b2b,answer,1);
                            else if(caseans==31)display(c2c,answer,1);
                            else if(caseans==32)display(a1a,answer,1);
                            else if(caseans==33)display(b1b,answer,1);
                            else if(caseans==34)display(c1c,answer,1);

                        }while(ans=='y'); break;

                        case 37: substitution();break;

                        case 38:
                        {clrscr();
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
                            cout<<"\nTimetable for the day requested has been successfully reset. Please enter 1 to continue. ";
                            char y;
                            cin>>y;
                            break;
                        }
                        case 39:
                        do{ clrscr();
                            cout<<"INTIAL PERIOD ASSIGNMENT MODE\n";
                            int n=initial();
                            if(n==1)break;
                            cout<<"Continue? Yes -> 1    No -> 0  ";
                            cin>>ansq;
                        }while(ansq==1); break;

                        case 40:
                        clrscr();
                        do{
                            clrscr();
                            cout<<"Enter class to which teacher or additional class must me added to"<<endl;
                            cout<<"\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n";
                            cin>>caseans;
                            if(caseans==1)display(a12a,caseans,0,q);
                            else if(caseans==2)display(b12b,caseans,0,q);
                            else if(caseans==3)display(a11a,caseans,0,q);
                            else if(caseans==4)display(b11b,caseans,0,q);
                            else if(caseans==5)display(a10a,caseans,0,q);
                            else if(caseans==6)display(b10b,caseans,0,q);
                            else if(caseans==7)display(c10c,caseans,0,q);
                            else if(caseans==8)display(a9a,caseans,0,q);
                            else if(caseans==9)display(b9b,caseans,0,q);
                            else if(caseans==10)display(c9c,caseans,0,q);
                            else if(caseans==11)display(a8a,caseans,0,q);
                            else if(caseans==12)display(b8b,caseans,0,q);
                            else if(caseans==13)display(c8c,caseans,0,q);
                            else if(caseans==14)display(a7a,caseans,0,q);
                            else if(caseans==15)display(b7b,caseans,0,q);
                            else if(caseans==16)display(c7c,caseans,0,q);
                            else if(caseans==17)display(a6a,caseans,0,q);
                            else if(caseans==18)display(b6b,caseans,0,q);
                            else if(caseans==19)display(c6c,caseans,0,q);
                            else if(caseans==20)display(a5a,caseans,0,q);
                            else if(caseans==21)display(b5b,caseans,0,q);
                            else if(caseans==22)display(c5c,caseans,0,q);
                            else if(caseans==23)display(a4a,caseans,0,q);
                            else if(caseans==24)display(b4b,caseans,0,q);
                            else if(caseans==25)display(c4c,caseans,0,q);
                            else if(caseans==26)display(a3a,caseans,0,q);
                            else if(caseans==27)display(b3b,caseans,0,q);
                            else if(caseans==28)display(c3c,caseans,0,q);
                            else if(caseans==29)display(a2a,caseans,0,q);
                            else if(caseans==30)display(b2b,caseans,0,q);
                            else if(caseans==31)display(c2c,caseans,0,q);
                            else if(caseans==32)display(a1a,caseans,0,q);
                            else if(caseans==33)display(b1b,caseans,0,q);





                            else if(caseans==34)display(c1c,answer,0);
                        }while(ans=='y'); break;
                        case 42:
                        {clrscr();
                            cout<<"\nPlease select a class\n1. 12A     2. 12B     3. 11A     4. 11B     5. 10A      6. 10B\n7. 10C     8. 9A      9. 9B      10. 9C     11. 8A     12. 8B\n13. 8C     14. 7A     15. 7B     16. 7C     17. 6A     18. 6B\n19. 6C     20. 5A     21. 5B     22. 5C     23. 4A     24. 4B\n25. 4C     26. 3A     27. 3B     28. 3C     29. 2A     30. 2B\n31. 2C     32. 1A     33. 1B     34. 1C     \n\n";
                            cin>>caseans;
                            clrscr();
                            char ansday[3];
                            cout<<"\nEnter day to be reset: \nMonday - mo\nTuesday- tu\nWednesday - we\nThursday - th\nFriday - fr\n\n";
                            cin>>ansday;
                            if(caseans==1)resettt(a12a,ansday,caseans,1);
                            else if(caseans==2)resettt(b12b,ansday,caseans,1);
                            else if(caseans==3)resettt(a11a,ansday,caseans,1);
                            else if(caseans==4)resettt(b11b,ansday,caseans,1);
                            else if(caseans==5)resettt(a10a,ansday,caseans,1);
                            else if(caseans==6)resettt(b10b,ansday,caseans,1);
                            else if(caseans==7)resettt(c10c,ansday,caseans,1);
                            else if(caseans==8)resettt(a9a,ansday,caseans,1);
                            else if(caseans==9)resettt(b9b,ansday,caseans,1);
                            else if(caseans==10)resettt(c9c,ansday,caseans,1);
                            else if(caseans==11)resettt(a8a,ansday,caseans,1);
                            else if(caseans==12)resettt(b8b,ansday,caseans,1);
                            else if(caseans==13)resettt(c8c,ansday,caseans,1);
                            else if(caseans==14)resettt(a7a,ansday,caseans,1);
                            else if(caseans==15)resettt(b7b,ansday,caseans,1);
                            else if(caseans==16)resettt(c7c,ansday,caseans,1);
                            else if(caseans==17)resettt(a6a,ansday,caseans,1);
                            else if(caseans==18)resettt(b6b,ansday,caseans,1);
                            else if(caseans==19)resettt(c6c,ansday,caseans,1);
                            else if(caseans==20)resettt(a5a,ansday,caseans,1);
                            else if(caseans==21)resettt(b5b,ansday,caseans,1);
                            else if(caseans==22)resettt(c5c,ansday,caseans,1);
                            else if(caseans==23)resettt(a4a,ansday,caseans,1);
                            else if(caseans==24)resettt(b4b,ansday,caseans,1);
                            else if(caseans==25)resettt(c4c,ansday,caseans,1);
                            else if(caseans==26)resettt(a3a,ansday,caseans,1);
                            else if(caseans==27)resettt(b3b,ansday,caseans,1);
                            else if(caseans==28)resettt(c3c,ansday,caseans,1);
                            else if(caseans==29)resettt(a2a,ansday,caseans,1);
                            else if(caseans==30)resettt(b2b,ansday,caseans,1);
                            else if(caseans==31)resettt(c2c,ansday,caseans,1);
                            else if(caseans==32)resettt(a1a,ansday,caseans,1);
                            else if(caseans==33)resettt(b1b,ansday,caseans,1);
                            else if(caseans==34)resettt(c1c,ansday,caseans,1);

                            cout<<"\nTimetable for the period requested has been successfully reset. ";
                            break;
                        }
                        case 43:
                        {
                            displaylab();
                        }
                        case 44:
                        newans='n'; break;

                    }
                    if(answer1==1) a12a=x;
                    else if(answer1==2) b12b=x;
                    else if(answer1==3) a11a=x;
                    else if(answer1==4) b11b=x;
                    else if(answer1==5) a10a=x;
                    else if(answer1==6) b10b=x;
                    else if(answer1==7) c10c=x;
                    else if(answer1==8) a9a=x;
                    else if(answer1==9) b9b=x;
                    else if(answer1==10) c9c=x;
                    else if(answer1==11) a8a=x;
                    else if(answer1==12) b8b=x;
                    else if(answer1==13) c8c=x;
                    else if(answer1==14) a7a=x;
                    else if(answer1==15) b7b=x;
                    else if(answer1==16) c7c=x;
                    else if(answer1==17)  a6a=x;
                    else if(answer1==18)  b6b=x;
                    else if(answer1==19)  c6c=x;
                    else if(answer1==20) a5a=x;
                    else if(answer1==21) b5b=x;
                    else if(answer1==22) c5c=x;
                    else if(answer1==23)  a4a=x;
                    else if(answer1==24)  b4b=x;
                    else if(answer1==25)  c4c=x;
                    else if(answer1==26)  a3a=x;
                    else if(answer1==27)  b3b=x;
                    else if(answer1==28)  c3c=x;
                    else if(answer1==29)   a2a=x;
                    else if(answer1==30)   b2b=x;
                    else if(answer1==31)   c2c=x;
                    else if(answer1==32)   a1a=x;
                    else if(answer1==33)   b1b=x;
                    else if(answer1==34)   c1c=x;


                    cout<<"\nDo you want to continue the timetable generator>> Yes(y) or No(n) ";
                    cin>>newans;
                }while(newans=='y') ;

            }
