#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


//

class Stock
{
	public:
		
		Stock();
		
		Stock(int, int, int, int, string, string, string);
		
		~Stock();
		
		
		void setStockID(int);
		void setAmountPerUnit(int);
		void setTotalStockQty(int);
		void setQty(int);
		void setStockDescript(string);
		void setStockCat(string);
		void setStockSubCat(string);
		
		
		int getStockID();
		int getAmountPerUnit();
		int getTotalStockQty();
		int getQty();
		string getStockDescript();
		string getStockCat();
		string getStockSubCat(); 
		
	private:
		int stockID;
		double amountPerUnit;
		int qty;
		string stockDescript;
		string stockCat;
		string stockSubCat;
};

/////////////////// Constructors and Descructors /////////////////////
Stock::Stock()
{
	stockID = 0;
	amountPerUnit = 0;
	qty = 0;
	stockDescript = "";
	stockCat = "";
	stockSubCat = "";
}
		
Stock::Stock(int stockID, int amountPerUnit, int totalStockQty, int qty, string stockDescript, string stockCat, string stockSubCat)
{
	this->stockID = stockID;
	this->amountPerUnit = amountPerUnit;
	this->qty = qty;
	this->stockDescript = stockDescript;
	this->stockCat = stockCat;
	this->stockSubCat = stockSubCat;
}
		
Stock::~Stock()
{
	
}



//////////////// Mutators ///////////////////

void Stock::setStockID(int stockID)
{
	this->stockID = stockID;
}

void Stock::setAmountPerUnit(int amountPerUnit)
{
	this->amountPerUnit = amountPerUnit;
}


void Stock::setQty(int qty)
{
	this->qty = qty;
}

void Stock::setStockDescript(string stockDescript)
{
	this-> stockDescript = stockDescript;
}

void Stock::setStockCat(string stockCat)
{
	this->stockCat = stockCat;
}

void Stock::setStockSubCat(string stockSubCat)
{
	this->stockSubCat = stockSubCat;
}
////////////////////// Accessors ////////////////////////

int Stock::getStockID()
{
	return stockID;
}

int Stock::getAmountPerUnit()
{
	return amountPerUnit;
}


int Stock::getQty()
{
	return qty;
}

string Stock::getStockDescript()
{
	return stockDescript;
}

string Stock::getStockCat()
{
	return stockCat;
}
		
string Stock::getStockSubCat()
{
	return stockSubCat;
}







