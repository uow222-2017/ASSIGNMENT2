#ifndef Transaction_H
#define Transaction_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>



using namespace std;
const int MAX=100;


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
		
		void setIncoming(int);
		int getIncoming();
		
		void setOutgoing(int);
		int getOutgoing();
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
		int incoming;
		int outgoing;

};
#endif

