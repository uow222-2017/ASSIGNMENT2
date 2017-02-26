
#include "Transaction_List.h"

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
	cout << "Begin Reading In Data From " << variable <<endl; 
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
		getline(linestream,description,':');
		getline(linestream,category,':'  );
				getline(linestream,subcategory,':' );
					getline(linestream,amountPerUnit,':' );
						getline(linestream,quantity ,':' );
							getline(linestream,date ,':' );
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

	
	string day ,monthInInt ,year;
	string day2,month2,year2;
	string month;
	int date=0,date2=0,x=0,position=0;
	int yearInt=0;
	int incoming =0,outgoing=0;
	double positiveIncome =0 , negativeIncome=0;
	string delimiter2 ="-";
	int i =0, diff=0;
	 int n=1;
	size_t pos = 0;
	string token;
	bool isUnique =true;
	Transaction t;
	
	day=splitDay(fromDay).c_str();
	monthInInt =splitMonth(fromDay).c_str();
	year= splitYear(fromDay.c_str());
	x=atoi(monthInInt.c_str());
	day2=splitDay(toDay).c_str();
	month2=splitMonth(toDay).c_str();
	year2= splitYear(toDay.c_str());
	switch(x)
	{
		case 1: month="Jan";
				break;
		case 2:month="Feb";
				break;
		case 3:month="Mar";
				break;
		case 4:month="Apr";
				break;
		case 5:month="May";
				break;
		case 6:month="Jun";
				break;
		case 7:month="Jul";
				break;
		case 8:month="Aug";
				break;
		case 9:month="Sep";
				break;
		case 10:month="Oct";
				break;
		case 11:month="Nov";
				break;
		case 12:month="Dec";
			
				
	
	}
	date=atoi(day.c_str());
	date2=atoi(day2.c_str());
	yearInt =atoi(year2.c_str());
	diff= date2-date;
	
	for(int i=0 ; i<=diff ; i++)//this is to loop exactly how many days
	{
		token=toString(date,month,yearInt);
		for(int j=0; j<tv.size();j++) //to check the vector every iteration for each date
		{
			if(strcmp(token.c_str(),tv[j].getTransactedDate().c_str())==0)
			{
				
					 
					 t.setStockID(tv[j].getStockID());
					 if(t.getStockID()==tv[j+1].getStockID())
					 {
					 	/* cout << token << '\t' << token<<'\t'
					 << tv[j].getStockID()<<'\t'
					 <<tv[j].getStockDescription()
					 <<endl;*/
					 	 t.setStockDescription(tv[j].getStockDescription());
						 t.setStockCategory(tv[j].getStockCategory());
						 t.setStockSubCategory(tv[j].getStockSubCategory());
						 t.setAmountPerUnit(tv[j].getAmountPerUnit());
						 t.setTransactedDate(tv[j].getTransactedDate());
						if(tv[j].getQty()>0)
						{
							incoming +=tv[j].getQty();
							
						}
						else if(tv[j].getQty()<0)
							outgoing +=tv[j].getQty();
						t.setIncoming(incoming);
						t.setOutgoing(outgoing);	 
					 
					 }
					 else
					 {
					 	if(tv[j].getQty()>0)
						{
							incoming +=tv[j].getQty();
							
						}
						else if(tv[j].getQty()<0)
						
							outgoing +=tv[j].getQty();
						t.setIncoming(incoming);
						t.setOutgoing(outgoing);	 
					 	positiveIncome=t.calculateTotalAmount(incoming,tv[j].getAmountPerUnit());
						negativeIncome=t.calculateTotalAmount(outgoing,tv[j].getAmountPerUnit());
					
						t.setTotalStockAmount((negativeIncome+positiveIncome));
					 	dailyReport.push_back(t);
						incoming =0 ;
						outgoing=0;
						positiveIncome=0;
						negativeIncome=0;
					 }
					 
					 	 
				
			
			}
		
			
			
		
		
		
		}
		
			date++;
	}
	cout 	<<left << setw(10)<<setfill(' ') <<"Day"
			<<left << setw(15)<<setfill(' ') <<"From"
			<<left << setw(15)<<setfill(' ') <<"To"
			<<left << setw(10)<<setfill(' ') <<"stockID"
			<<left << setw(25)<<setfill(' ') <<"description"
		     <<left << setw(25)<<setfill(' ') <<"Category"
			 <<left << setw(25)<<setfill(' ') <<"Sub Category"
			 <<left << setw(15)<<setfill(' ')  << "Amount P.U"
			 <<left << setw(15)<<setfill(' ') << "In"
			 <<left << setw(15)<<setfill(' ') <<"Out"
			 <<left << setw(20)<<setfill(' ') <<"Total amount $"<<endl;
	cout << setw(160)<< setfill('=') << "="<<endl;
    cout << setw(5)<< setfill(' ')<< ""<<endl;
	

	 for(int m=0;m<dailyReport.size();m++)
	 {
	 	if(strcmp(tv[m].getTransactedDate().c_str(),tv[m+1].getTransactedDate().c_str())!=0)
		{
			++n;
		
		}
		
		cout 	<<left << setw(10)<<setfill(' ') <<n
			<<left << setw(15)<<setfill(' ') << dailyReport[m].getTransactedDate() 
			<<left << setw(15)<<setfill(' ') << dailyReport[m].getTransactedDate()
			 <<left << setw(10)<<setfill(' ') << dailyReport[m].getStockID() 
			<<left << setw(25)<<setfill(' ') <<dailyReport[m].getStockDescription()
		     <<left << setw(25)<<setfill(' ') <<dailyReport[m].getStockCategory()
			 <<left << setw(25)<<setfill(' ') <<dailyReport[m].getStockSubCategory()
			 <<left << setw(15)<<setfill(' ')  << dailyReport[m].getAmountPerUnit()
			 <<left << setw(15)<<setfill(' ') << dailyReport[m].getIncoming()
			 <<left << setw(15)<<setfill(' ') <<dailyReport[m].getOutgoing()
			 <<left << setw(20)<<setfill(' ') <<dailyReport[m].getTotalStockAmount()<<endl;
	 }
	 dailyReport.clear();
	
}
string TransactionList::toString(int day,string month ,int year)
{
	string temp;
	stringstream a;
	
	a<<day
	 <<"-"
	 <<month
	 <<"-"
	 <<year;
	temp = a.str();

	return temp;
	

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
/*	  	  string day ,monthInInt ,year;
	string day2,month2,year2;
	string month;
	int date=0,date2=0,x=0,position=0;
	int yearInt=0;
	int incoming =0,outgoing=0;
	double positiveIncome =0 , negativeIncome=0;
	string delimiter2 ="-";
	int i =0, diff=0;
	 int n=1;
	size_t pos = 0;
	string token;
	bool isUnique =true;
	Transaction t;
	
	day=splitDay(fromDay).c_str();
	monthInInt =splitMonth(fromDay).c_str();
	year= splitYear(fromDay.c_str());
	x=atoi(monthInInt.c_str());
	day2=splitDay(toDay).c_str();
	month2=splitMonth(toDay).c_str();
	year2= splitYear(toDay.c_str());
	switch(x)
	{
		case 1: month="Jan";
				break;
		case 2:month="Feb";
				break;
		case 3:month="Mar";
				break;
		case 4:month="Apr";
				break;
		case 5:month="May";
				break;
		case 6:month="Jun";
				break;
		case 7:month="Jul";
				break;
		case 8:month="Aug";
				break;
		case 9:month="Sep";
				break;
		case 10:month="Oct";
				break;
		case 11:month="Nov";
				break;
		case 12:month="Dec";
			
				
	
	}*/
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
	



