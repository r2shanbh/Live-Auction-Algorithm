/*
 * auction.cpp
 *
 *  Created on: Jan. 11, 2020
 *      Author: Raksha
 */
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>

using namepace std;
class antiques
{
long int itcode;
char iname[20];
char status[20];
char country[20];
double price;
int age;

public:
char*Getstatus()
{
return status;
}
long int ico()
{
return itcode;
}
void input()
{
cout<<"\nEnter the item code : ";
cin>>itcode;
cout<<"\nEnter the antique name : ";
gets(iname);
cout<<"\nEnter the country of origin : ";
gets(country);
cout<<"\nEnter the price: ";
cin>>price;
cout<<"\nEnter the estimated age: ";
cin>>age;
cout<<"\nEnter the status of the item:";
gets(status);
}

void show()
{
cout<<"\nitem code:"<<itcode;
cout<<"\nitem name:"<<iname;
cout<<"\nStatus:"<<status;
cout<<"\nCountry of origin:"<<country;
cout<<"\nPrice:"<<price;
cout<<"\n Age:"<<age;
}
};

void main()
{ clrscr();
fstream f1,f2;
int n,n1,i;
long int fico,fico1;
char ans;
antiques a;
cout<<"\n Welcome! Please refer to the following instructions";
cout<<"\n\n New staff member?(y/n)";
char staff;
cin>>staff;
if(staff=='y'||staff=='Y')
{ cout<<"\n\n Add the antiques you are in-charge of:";
f1.open("item.dat",ios::out|ios::binary);
if(!f1)
{
cout<<"error";
exit(0);
}
cout<<"\n\n How many antiques have you been assigned?";
int b;
cin>>b;
for(i=0;i<b;i++)
{a.input();
f1.write((char*)&a,sizeof(a));}
f1.close();

do
{ clrscr();
cout<<"\t\tMenu\n";
cout<<"\t\t_ _ _ _ _";
cout<<"\n1. Add a new antique";
cout<<"\n2. Search for an antique by code";
cout<<"\n3. Delete sold items";
cout<<"\n4. Modify the details of the antique";
cout<<"\n5. Display all the items";
cout<<"\n\nEnter choice : ";
cin>>n;

switch(n)
{
case 1:
cout<<"\nHow many items to be added? ";
cin>>n1;
f1.open("item.dat",ios::app|ios::binary);
if(!f1)
{
cout<<"\nError";
exit(0);
}
for(i=0;i<n1;i++)
{
a.input();
f1.write((char*)&a,sizeof(a));
}
f1.close();
clrscr();
cout<<"\nThe new item(s) has/have been added to your list";
break;

case 2:
cout<<"\n Enter the item code";
cin>>fico;
f1.open("item.dat",ios::in);
if(!f1)
{
cout<<"\nError";
exit(0);
}
int y=0;
while(f1.read((char*)&a,sizeof(a)))
{
if(a.ico()==fico)
{y=1;
cout<<"\nItem found";
a.show();}}
if(y==0)
{cout<<"\nThis antique is not a part of your list";}
f1.close();
break;

case 3:
f1.open("item.dat",ios::in|ios::binary);
f2.open("i.dat",ios::out|ios::binary);

if(!f1||!f2)
{
cout<<"\nError";
exit(0);
}

while(f1.read((char*)&a,sizeof(a)))
{
if(strcmpi(a.Getstatus(),"sold")!=0)
f2.write((char*)&a,sizeof(a));
}
f1.close();
f2.close();

remove("item.dat");
rename("i.dat","item.dat");

clrscr();
cout<<"\nAll the sold items are deleted";
cout<<"\n\nAntiques on sale and bidding\n";

f1.open("item.dat",ios::in|ios::binary);
if(!f1)
{
cout<<"\nError";
exit(0);
}
while(f1.read((char*)&a,sizeof(a)))
{
a.show();
}
f1.close();
break;

case 4:
int p,c;
f1.open("item.dat",ios::out|ios::in|ios::binary);
if(!f1)
{
cout<<"\nError";
exit(0);
}
cout<<"\n Enter the item code ofthe antique you wish to modify ";
cin>>fico1;
c=f1.tellg();
while(f1.read((char*)&a,sizeof(a)))
{
if(a.ico()==fico1)
{p=1;
cout<<"Record Found";
cout<<"\nEnter new details ";
a.input();
f1.seekp(c);
f1.write((char*)&a,sizeof(a));
}}
if(p==0)
{f1.seekg(0);
cout<<"\nThe antique is not a part of your list";}
f1.close();
clrscr();
cout<<"\nantique details after modifying : \n";
f1.open("item.dat",ios::in|ios::binary);
if(!f1)
{
cout<<"\nError";
exit(0);
}
while(f1.read((char*)&a,sizeof(a)))
{
a.show();
}
f1.close();
break;

case 5:

cout<<"\nDetails of all antiques : \n\n";
f1.open("item.dat",ios::in|ios::binary);
if(!f1)
{
cout<<"\nError";
exit(0);
}
while(f1.read((char*)&a,sizeof(a)))
{
a.show();
}
f1.close();
break;

default:
cout<<"\nInvalid choice !!";
}

cout<<"\nDo you want to continue ? ";
cin>>ans;
}while(ans=='y'||ans=='Y');
}
else
cout<<"\nPlease use the other site!";
getch();
}




