#ifndef Transaction_List_H
#define Transaction_List_H

#include "Transaction.h"

#include <iostream>

class TransactionList
{
	public:
		TransactionList();
		~TransactionList();
		void retrieveFromTextFile(fstream&, char[]);
		void storeToTextFile();
		void displayAllTransaction();
		void displayDaily(string ,string );
		void displayMonthly(string ,string);
		void displayWeekly();
		void displayYearly();
		void push();
		void pop();
		
		string toString(int,string,int);
		string splitDay(string);
		string splitMonth(string);
		string splitYear(string);
	
	private:
		vector <Transaction> tv;
		vector<Transaction> dailyReport;
	
	    
};
#endif

