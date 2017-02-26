#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>
#include <stdio.h>
#include <sstream>
#include<vector>
using namespace std;
const int MAX=100;
string delimiter=":";
class Transaction
{
	public:
		Transaction();
		int getStockID();
		void setStockID(int);
		
		string getStockDescription();
		void setStockDescription(string);
		
		string getStockCategory();
		void setStockCategory(string);
		
		string getStockSubCategory();
		void setStockSubCategory(string);
		
		double getAmountPerUnit();
		void setAmountPerUnit(double);
		
		int getQty();
		void setQty(int);
		
		string getTransactedDate();
		void setTransactedDate(string);
		
		int getTransactionID();
		void setTransactionID(int);
		
		
		double getTotalStockAmount();
		void  setTotalStockAmount(double);
		double calculateTotalAmount( int,double);
		
		int getCounter();
		void setCounter(int);
		
	private:
		int stockID;
		string stockDescript;
		string stockCat;
		string stockSubCat;
		double amountPerUnit;
		int qty;
		string transactedDate;
		double totalStockAmount;
		int transactionID;
		int counter;
		

};

class TransactionList
{
	public:
		TransactionList();
		~TransactionList();
		void retrieveFromTextFile(fstream&, char[]);
		void storeToTextFile();
		void displayAllTransaction();
		void displayDaily(string ,string );
		void displayMonthly();
		void displayWeekly();
		void displayYearly();
		void push();
		void pop();
		string splitDay(string);
		string splitMonth(string);
		string splitYear(string);
	
	private:
		vector <Transaction> tv;
};

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
	string date ="14-Oct-15";
	string date1= "15-Oct-15";
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

	
}



Transaction::Transaction()
{
	stockID=0;
	amountPerUnit=0;
	qty=0;
	totalStockAmount=0;
	transactionID=0;


}
int Transaction::getStockID()
{
	return stockID;

}
void Transaction::setStockID(int stockID)
{
	this->stockID=stockID;

}
string Transaction::getStockDescription()
{
	return stockDescript;
}
void Transaction::setStockDescription(string stockDescript)
{
	this->stockDescript=stockDescript;	  

}
string Transaction::getStockCategory()
{
	return stockCat;
}

void Transaction::setStockCategory(string stockCat)
{
	this->stockCat=stockCat;
}
string Transaction::getStockSubCategory()
{
	return stockSubCat;
}

void Transaction::setStockSubCategory(string stockSubCat)
{
	this->stockSubCat=stockSubCat;
}
double Transaction::getAmountPerUnit()
{
	return amountPerUnit;
}	 

void Transaction::setAmountPerUnit(double amountPerUnit)
{
	this->amountPerUnit=amountPerUnit;
}
int Transaction::getQty()
{
	return qty;

}
void Transaction::setQty(int qty)
{
	this->qty = qty;
}

string Transaction::getTransactedDate()
{
	return transactedDate;
}

void Transaction::setTransactedDate(string transactedDate)
{
	this->transactedDate=transactedDate;

}
int Transaction::getTransactionID()
{
	return transactionID;
}
void Transaction::setTransactionID(int transactionID)
{
	this->transactionID=transactionID;
}
double Transaction::getTotalStockAmount()
{
	return totalStockAmount;
}
void  Transaction::setTotalStockAmount(double totalStockAmount)
{
	this->totalStockAmount=totalStockAmount;
}
double Transaction::calculateTotalAmount( int qty,double amountPerUnit)
{
	int x=0;
	x= qty*amountPerUnit;
	return x;

}

int Transaction::getCounter()
{
	return counter;
}
void Transaction::setCounter(int counter)
{

	this->counter=counter;
}

void TransactionList::retrieveFromTextFile(fstream& infile, char variable[])
{
	
	Transaction t2;
	TransactionList tl;
	string text;
	string stockID;
	int a=0,c=0;
	double b=0;
	int i =0;
	bool x=false;
	string description,category,subcategory,amountPerUnit,quantity,date,TransID;
	int counter=0;
	
	if(strcmp(variable,"Transaction_List.txt")==0)
	{
		infile.open("Transaction_List.txt",ios::in );
	
	}
	else
		infile.open(variable,ios::in);
	if(!infile)
	{
		infile.close();
		cout << "infile failed to open"<<endl;
		exit(-1);
	
	}
	cout << "Begin Reading In Data From" << variable <<endl; 
	//infile.seekg(0,ios::end);
//	  noOfBytes=infile.tellg();
//	  totalRecord=noOfBytes/sizeof(Transaction);
//	  infile.close();
//	  cout << totalRecord<<endl;
	while(getline(infile,text))
	{
		
		stringstream linestream(text);
		if(strcmp(variable,"Transaction_List.txt")==0)
		{
			getline(linestream,TransID ,':');
			
		}
	
		getline(linestream,stockID ,':');
		getline(linestream,description,':' );
		getline(linestream,category,':' );
				getline(linestream,subcategory,':' );
					getline(linestream,amountPerUnit,':' );
						getline(linestream,quantity ,':');
							getline(linestream,date ,':');
		   //  linestream>>description>>category>>subcategory>>amountPerUnit>>quantity >> date ; 	
	
		
	    a=atoi(stockID.c_str());
		b=atof(amountPerUnit.c_str());
		c=atoi(quantity.c_str());
		t2.setStockID(a);
		t2.setStockDescription(description);
		t2.setStockCategory(category);
		t2.setStockSubCategory(subcategory);
		t2.setAmountPerUnit(b);
		t2.setQty(c);
		t2.setTransactedDate(date);
		t2.setCounter(counter);
		counter++;
	//	  cout<<description<<category<<subcategory<<amountPerUnit<<quantity << date ; 	 
	
		tv.push_back(t2);
		
	}


	//displayAllTransaction();
  
	
	infile.close();
}


TransactionList::TransactionList()
{

}
TransactionList::~TransactionList()
{

}

void TransactionList::displayAllTransaction()
{
	cout <<left << setw(10)<<setfill(' ') << "TransID"
	 	 <<left << setw(10)<<setfill(' ') <<"StockID"
		 <<left << setw(25)<<setfill(' ') <<"Description"
		 <<left << setw(25)<<setfill(' ') <<"Category"
		 <<left << setw(25)<<setfill(' ') <<"Sub Category"
		 <<left << setw(10)<<setfill(' ') <<"amount"
		 <<left << setw(10)<<setfill(' ') <<"qty"
		 <<left << setw(10)<<setfill(' ') <<"date"
		 <<endl;
	cout <<"---------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i =0; i<tv.size(); i++)
	{
			cout<<left << setw(10)<<setfill(' ')<<tv[i].getCounter()  
				<<left<< setw(10)<<setfill(' ')<<tv[i].getStockID()
				<<left<< setw(25)<<setfill(' ')<<tv[i].getStockDescription()
				<<left<< setw(25)<<setfill(' ')<<tv[i].getStockCategory()
				<<left<< setw(25)<<setfill(' ')<<tv[i].getStockSubCategory()
				<<left<< setw(10)<<setfill(' ')<<tv[i].getAmountPerUnit()
				<<left<< setw(10)<<setfill(' ')<<tv[i].getQty()
				<<left<< setw(20)<<setfill(' ')<<tv[i].getTransactedDate()<<endl;
			
	
	}
}
void TransactionList::displayDaily(string fromDay ,string toDay )
{

	
	string day ,month ,year;
	string day2,month2,year2;
	int date=0,date2=0;
	string delimiter2 ="-";
	int i =0, diff=0;
	size_t pos = 0;
	string token;
	
	day=splitDay(fromDay).c_str();
	month =splitMonth(fromDay).c_str();
	year= splitYear(fromDay.c_str());
	
	day2=splitDay(toDay).c_str();
	date=atoi(day.c_str());
	date2=atoi(day2.c_str());
	diff= date2-date;
	
	
	
}
string TransactionList::splitDay(string date)
{
	int i =0;
	size_t pos = 0;
	string token,day2,month2;
	string delimiter2 ="-";
	
	while ((pos = date.find(delimiter2)) != string::npos) 
  {
   		token = date.substr(0, pos);
    	if(i==0)
			day2=token;
		else if (i==1)
			month2=token;
		i++;
    	date.erase(0, pos + delimiter2.length());
    
    
	}

	return day2;

}
string TransactionList::splitMonth(string date)
{
	int i =0;
	size_t pos = 0;
	string token,day2,month2;
	string delimiter2 ="-";
	
	while ((pos = date.find(delimiter2)) != string::npos) 
  {
   		token = date.substr(0, pos);
    	if(i==0)
			day2=token;
		else if (i==1)
			month2=token;
		i++;
    	date.erase(0, pos + delimiter2.length());
    
    
	}

	return month2;	     
}


string TransactionList::splitYear(string date)
{
	int i =0;
	size_t pos = 0;
	string token,day2,month2;
	string delimiter2 ="-";
	
	while ((pos = date.find(delimiter2)) != string::npos) 
  {
   		token = date.substr(0, pos);
    	if(i==0)
			day2=token;
		else if (i==1)
			month2=token;
		i++;
    	date.erase(0, pos + delimiter2.length());
    
    
	}

	return date;
}
void TransactionList::displayMonthly()
{

}
void TransactionList::displayWeekly()
{

}
void TransactionList::displayYearly()
{

}

void TransactionList::storeToTextFile()
{
	fstream outfile;
	outfile.open("Transaction_List.txt",ios::out);
	if(!outfile)
	{
		cout << "failed to create transaction list" <<endl;
		exit(-1);
	
	}
	cout <<"Begin storing to text file"<<endl;
	for(int i =0; i<tv.size(); i++)
	{
		outfile <<	tv[i].getCounter() <<":"
			<<  tv[i].getStockID() << ":"
			<< tv[i].getStockDescription() << ":"
			<< tv[i].getStockCategory() <<":"
			<< tv[i].getStockSubCategory()<<":"
			<< tv[i].getAmountPerUnit()<< ":"
			<< tv[i].getQty() <<":"
			<< tv[i].getTransactedDate()
			<<endl;
			
	
	}
	outfile.close();
}
	
void TransactionList::push()
{
	
	int stockID=0,qty=0,pos=0,pos2=0;
	double apu;
	string description ,stockCat,stockSubCat;
	string describe,date;
	bool x = false,y=false;
	char des[MAX];
	Transaction t2;
	fstream infile;
	//retrieveFromTextFile(infile,"Transaction_List.txt");
	do
	{	 
		cin.clear();
		cin.ignore(MAX,'\n');
		cout << "Please enter new stock ID "<<" : ";
		cin  >> stockID;
		
		cin.clear();
		cin.ignore(MAX,'\n');
		cout << "\nPlease enter new stock description" <<" : ";
		getline(cin,description);
	
		cin.clear();
		cin.ignore(MAX,'\n');
		cout << "\nPlease enter new stock category " << " : ";
		getline(cin,stockCat);
		
		cin.clear();
		cin.ignore(MAX,'\n');
		cout << "Please enter new stock sub category " <<" : ";
		getline(cin, stockSubCat);
	
		for(int i = 0 ; i <tv.size();i++)
		{
			
			if(stockID==tv[i].getStockID() && (strcmp(description.c_str(),tv[i].getStockDescription().c_str())==0) && (strcmp(stockCat.c_str(),tv[i].getStockCategory().c_str())==0)
				&&(strcmp(stockSubCat.c_str(),tv[i].getStockSubCategory().c_str())==0))
			{
				x= true;
				
			}
			if(stockID==tv[i].getStockID())
			{
				pos=i;
			
			}
			if((strcmp(description.c_str(),tv[i].getStockDescription().c_str())==0))
			{
				pos2=i;
				y=true;
				
			}
			
			
			
		}
			
		if(!x)
		{
			cout << "stock ID and stock description does not match.Please enter the correct ID and description "<<endl;
			cout << "Did you mean to enter : " <<tv[pos].getStockID() << "/ " << tv[pos].getStockDescription() << "/ " << tv[pos].getStockCategory()
				 << "/ " << tv[pos].getStockSubCategory()
				 << endl;
			if(y)
			{
				cout << "Or did you mean to enter : " <<tv[pos2].getStockID() << "/ " << tv[pos2].getStockDescription() << "/ " << tv[pos2].getStockCategory()
					 << "/ " << tv[pos2].getStockSubCategory()
				 	<< endl;
			}
		}
	}while(!x);
	//the above do while loop is to check if the entered details exist in the list of transaction
	
		
		cout << "\nPlease enter amount per unit : ";
		cin >> apu;
		cout <<"\nPlease enter qty: ";
		cin >>qty;
		
		cin.clear();
		cin.ignore(MAX,'\n');
		cout <<"\nPlease enter transacted date : ";
		
		getline(cin,date);
		cout << date<<endl;
		
		t2.setStockID(stockID);
		t2.setStockDescription(description);
		t2.setStockCategory(stockCat);
		t2.setStockSubCategory(stockSubCat);
		t2.setAmountPerUnit(apu);
		t2.setQty(qty);
		t2.setTransactedDate(date);
		t2.setCounter(tv[tv.size()-1].getCounter()+1);
		tv.push_back(t2);
		
		
		
}
void TransactionList::pop()
{
	int transID;
	string description;
	

	displayAllTransaction();

	do
	{
		cout << "\nPlease enter the transaction ID of the transaction that you wish to remove"<<endl;
		cin >>transID;
		if(transID>=tv.size())
		{
			cout << "Invalid transaction ID Please enter a valid one" <<endl;
		}
	}while(transID>=tv.size());
	for(int j = 0 ;j<tv.size(); j++)
	{
		
		if(transID==tv[j].getCounter())
		{
			tv.erase(tv.begin()+j);
		}
		
	}
	for(int k=0;k<tv.size();k++)
	{
		tv[k].setCounter(k);
	
	}

	
	
}
	



