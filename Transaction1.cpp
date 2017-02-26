#include "Transaction.h"


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
double Transaction::calculateTotalAmount( int quantity,double amountPerUnit)
{
	int x=0;
	x= quantity*amountPerUnit;
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

void Transaction::setIncoming(int incoming)
{
	this->incoming=incoming;
}
int Transaction::getIncoming()
{

	return incoming;
}
		
void Transaction::setOutgoing(int outgoing)
{
	this->outgoing=outgoing;
}
int Transaction::getOutgoing()
{
	return outgoing;

}

