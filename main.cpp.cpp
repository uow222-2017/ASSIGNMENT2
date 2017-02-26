#include <iostream>
#include <iomanip>
#include <string>
#include "Transaction.h"
#include "TransactionList.h"

using namespace std;

int main()
{
	//everything below is just for testing purpose only
	fstream infile;
	fstream outfile;
	TransactionList tL;
	char a[MAX];
	char textFileName[MAX];
	string option;
	bool firstTimeUse=false;
	string date ="17-03-14";
	string date1= "23-03-14";
	cout << "Is this the first time that you are using this system .Do you wish to transfer over your database to our system(Yes/No):";
	cin >>option;
	if((strcmp(option.c_str(),"Yes")==0)||(strcmp(option.c_str(),"yes")==0))
	{
		cin.clear();
		cin.ignore(MAX,'\n');
		cout <<"\nPlease enter the file name that store your data to be transfered:";
		cin.getline(textFileName,MAX);
		
		tL.retrieveFromTextFile(infile,textFileName);
		tL.storeToTextFile();
	}
	else
	{
		tL.retrieveFromTextFile(infile,"Transaction_List.txt");	  
		tL.storeToTextFile();
	}

/*	  while(strcmp(a,"yes")!=0)
	{
		tL.push();
		cout << "do you wanna quit ? Yes/No "<< endl;;
		cin.get(a,'\n');
	}
	tL.pop();
	tL.storeToTextFile();*/
	
	tL.displayDaily(date,date1);
		tL.displayDaily(date,date1);
	
}

