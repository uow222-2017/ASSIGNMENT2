#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "stock.h"

using namespace std;




class StockList
{
	public:
		StockList();
		
		StockList(int);
		
		~StockList();
		
		void LoadSample(const char[]);
		void LoadStock(const char[]);
		void vectorToFile(const char[]);
		
		void editStock(const char[]);
		void addStock(const char[]);
		int searchStock(StockList&); // enter StockList class
		void removeStock(const char[], TransactionList);
		
		//////// Compare functions ///////////
		bool compIDAsc(Stock&, Stock&);
		bool compIDDsc(Stock&, Stock&);
		
		bool compDescriptAsc(Stock&, Stock&);
		bool compDescriptDsc(Stock&, Stock&);
		
		bool compCatAsc(Stock&, Stock&);
		bool compCatDsc(Stock&, Stock&);
		
		bool compSubCatAsc(Stock&, Stock&);
		bool compSubCatDsc(Stock&, Stock&);
		
		bool compAmountAsc(Stock&, Stock&);
		bool compAmountDsc(Stock&, Stock&);
		
		bool compQtyAsc(Stock&, Stock&);
		bool compQtyDsc(Stock&, Stock&);
		
		///////// Other methods ////////////
		
		void printVector();
		
		void sortInAscending(int);
		void sortInDescending(int);
		void displayByCategory(); // Display in ascending
		void displayBySubCat(); // Display in ascending
		void displayByPrice(); // Display in ascending
	
		
		vector<Stock> stockList;
};


//////////////////////// Constructor & Destructor ///////////////////////////
StockList::StockList()
{
	
}

StockList::StockList(int size)
{
	vector<Stock> stockList(size);
}
		
StockList::~StockList()
{
	
}
/////////////////////////// Bool Functions /////////////////////////////////////

bool StockList::compIDAsc(Stock &lhs, Stock &rhs)   // Compare StockID
{
	if ( lhs.getStockID() < rhs.getStockID() )
		return true;
	return false;
}

bool StockList::compIDDsc(Stock &lhs, Stock &rhs)
{
	if ( lhs.getStockID() > rhs.getStockID() )
		return true;
	return false;
}
//----------------------------------------
bool StockList::compDescriptAsc(Stock &lhs, Stock &rhs)       // Compare Stock Descript
{
	if ( lhs.getStockDescript().compare(rhs.getStockDescript()) < 0 )
		return true;
	return false;
}

bool StockList::compDescriptDsc(Stock &lhs, Stock &rhs)
{
	if ( lhs.getStockDescript().compare(rhs.getStockDescript()) > 0 )
		return true;
	return false;
}
//----------------------------------------
bool StockList::compCatAsc(Stock &lhs, Stock &rhs)  			// Compare Stock Category
{
	if ( lhs.getStockCat().compare(rhs.getStockCat()) < 0 )
		return true;
	return false;
}


bool StockList::compCatDsc(Stock &lhs, Stock &rhs)
{
	if ( lhs.getStockCat().compare(rhs.getStockCat()) > 0)
		return true;
	return false;
	
}
//----------------------------------------
bool StockList::compSubCatAsc(Stock &lhs, Stock &rhs)			// Compare Stock SubCategory
{
	if ( lhs.getStockSubCat().compare(rhs.getStockSubCat()) < 0 )
		return true;
	return false;
}


bool StockList::compSubCatDsc(Stock &lhs, Stock &rhs)
{
	if ( lhs.getStockSubCat().compare(rhs.getStockSubCat()) > 0 )
		return true;
	return false;
}
//----------------------------------------
bool StockList::compAmountAsc(Stock &lhs, Stock &rhs)			// Compare Stock Amount Per Unit
{
	if ( lhs.getAmountPerUnit() < rhs.getAmountPerUnit() )
		return true;
	return false;
}

bool StockList::compAmountDsc( Stock &lhs, Stock &rhs)
{
	if ( lhs.getAmountPerUnit() > rhs.getAmountPerUnit() )
		return true;
	return false;
}
//----------------------------------------
bool StockList::compQtyAsc(Stock &lhs, Stock &rhs)				// Compare Stock Quantity
{
	if ( lhs.getQty() < rhs.getQty() )
		return true;
	return false;
}


bool StockList::compQtyDsc(Stock &lhs, Stock &rhs)
{
	if ( lhs.getQty() > rhs.getQty() )
		return true;
	return false;
}

///////////////////////////////// Methods /////////////////////////////////



void StockList::addStock(const char fileName[])
{
	fstream outfile;
	int intBuffer;
	string stringBuffer;
	Stock stockObj;
	
	outfile.open(fileName, ios::out); // overwrite current stock file
	
	if(!outfile)
	{
		// throw exception
	}
	
	cout << "\nAdd Stock " << endl;
	cout << "---------" << endl;
	
	do
	{
		cout << "\nEnter Stock ID : ";
		if(cin.fail())	{	cout << "\nPlease enter an integer" << endl; cin.clear();	cin.ignore(20,'\n');	}
		cin >> intBuffer;
	}while(cin.fail() || (intBuffer < 0) );
	stockObj.setStockID(intBuffer);
	
	cout << "\nEnter Stock Description : ";
	cin >> stringBuffer;
	stockObj.setStockDescript(stringBuffer);
	
	cout << "\nEnter Stock Category : ";
	cin >> stringBuffer;
	stockObj.setStockCat(stringBuffer);
	
	cout << "\nEnter Stock Sub Category : ";
	cin >> stringBuffer;
	stockObj.setStockSubCat(stringBuffer);
	
	do
	{
		cout << "\nEnter Amount Per Unit : ";
		if(cin.fail())	{	cout << "\nPlease enter an integer" << endl; cin.clear();	cin.ignore(20,'\n');	}
		cin >> intBuffer;
	}while(cin.fail() || (intBuffer < 0));
	stockObj.setAmountPerUnit(intBuffer);
	
	do
	{
		cout << "\nEnter Quantity : ";
		if(cin.fail())	{	cout << "\nPlease enter an integer" << endl; cin.clear();	cin.ignore(20,'\n');	}
		cin >> intBuffer;
	}while(cin.fail() || (intBuffer < 0));
	stockObj.setQty(intBuffer);
	
	stockList.push_back(stockObj);
	cout << "\nStock Successfully Added." << endl;
	
	for(int i=0; i<stockList.size(); i++)
	{
		outfile << stockList[i].getStockID() << ":"
				<< stockList[i].getStockDescript() << ":"
				<< stockList[i].getStockCat() << ":"
				<< stockList[i].getStockSubCat() << ":"
				<< stockList[i].getAmountPerUnit() << ":"
				<< stockList[i].getQty() 
				<< endl;
	}
	
	outfile.close();
}

//------------------------------------------------

void StockList::removeStock(const char fileName[], TransactionList tL)
{
	int tempID, intBuffer;
	bool notFound = true;
	
	fstream outfile;
	
	outfile.open(fileName,ios::out); // vector to file overwrite
	
	if(!outfile)
	{
		// throw exception
	}
	
	cout << "\nRemove Stock" << endl;
	cout << "------------" << endl;
	
	do
	{
		cout << "\nEnter Stock ID to remove : ";
		if(cin.fail())	{	cout << "\nPlease enter an integer" << endl; cin.clear();	cin.ignore(20,'\n');	}
		cin >> tempID;
	}while(cin.fail() || (tempID < 0) );
	//Search through vector 
	for(int i=0; i<stockList.size(); i++)
	{
		if(tempID == stockList[i].getStockID() )
		{
			notFound = false;
			
			// remove from vector
			stockList.erase(stockList.begin() + i);
		}	
	}
	
	
	
	if(notFound)
	{
		cout << "\nStock ID not found." << endl;
	}
	else
	{
		for(int j=0; j<tL.tv.size(); j++)
		{
			if(tempID == tL.tv.getStockID())
			{
				tL.tv.setStockID(-1); // Set Stock ID in tranasctionlist to 
			}
		}
		cout << "\nStock successfully removed." << endl;
	}
	
	
	
	
	//output overwrite to file to update stock
	for(int i=0; i<stockList.size(); i++)
	{
		outfile << stockList[i].getStockID() << ":"
				<< stockList[i].getStockDescript() << ":"
				<< stockList[i].getStockCat() << ":"
				<< stockList[i].getStockSubCat() << ":"
				<< stockList[i].getAmountPerUnit() << ":"
				<< stockList[i].getQty() 
				<< endl;
	}
	
	
	outfile.close();
}

//------------------------------------------------

void StockList::editStock(const char fileName[])
{
	string stringBuffer;
	int choice, intBuffer;
	int tempID, index;
	fstream outfile;
	bool notFound = true;
	
	outfile.open(fileName,ios::out);
	
	if(!outfile)
	{
		// throw exception
	}
	
	
	cout << "\nEdit Stock" << endl;
	cout << "----------" << endl;
	
	cout << "\nEnter Stock ID : ";
	cin >> tempID;
	
	for(int i=0; i<stockList.size(); i++)
	{
		if ( tempID == stockList[i].getStockID() )
		{
			notFound == false;
			index = i;
			do
			{
				cout << "Edit Stock Info : " << endl;
				cout << "			1) Stock ID" << endl;
				cout << "			2) Stock Description" << endl;
				cout << "			3) Stock Category" << endl;
				cout << "			4) Stock SubCategory" << endl;
				cout << "			5) Stock Price" << endl;
				cout << "			6) Exit to Main Menu" << endl;
				
				cin >> choice;
				
				switch(choice)
				{
					case 1:	cout << "Stock ID is currently	: '" << stockList[i].getStockID() << "'" << endl;
							cout << "Enter new Stock ID		: ";
							cin >> intBuffer;
							
							stockList[i].setStockID(intBuffer);
							break;
							
					case 2:	cout << "Stock Description is currently	: '" << stockList[i].getStockDescript() << "'" << endl;
							cout << "Enter new Stock Description	: ";
							cin >> stringBuffer;
							
							stockList[i].setStockDescript(stringBuffer);
							break;
							
					case 3: cout << "Stock Category is currently	: '" << stockList[i].getStockCat() << "'" << endl;
							cout << "Enter new Stock Category		: ";
							cin >> stringBuffer;
							
							stockList[i].setStockCat(stringBuffer);
							break;
							
					case 4:	cout << "Stock SubCategory is currently	: '" << stockList[i].getStockSubCat() << "'" << endl;
							cout << "Enter new Stock SubCategory	: ";
							cin >> stringBuffer;
							
							stockList[i].setStockSubCat(stringBuffer);
							break;
							
					case 5: cout << "Stock Price is currently	: '" << stockList[i].getAmountPerUnit() << "'" << endl;
							cout << "Enter new Stock Price		: ";
							cin >> intBuffer;
							
							stockList[i].setAmountPerUnit(intBuffer);
							break;
							
					default: break;
				}
				
			}while(choice != 6);
			
		}
		
	}
	
	if(notFound)
	{
		cout << "\nStock ID not found." << endl;
	}
	else
	{
		for(int j=0; j<tL.tv.size(); j++)
		{
			if(tempID == tL.tv.getStockID())
			{											// Set edited Stock info to transaction info
				tL.tv.setStockID(stockList[index].getStockID()); // Set Stock ID in tranasctionlist 
				tL.tv.setStockDescript(stockList[index].getStockDescript());
				tL.tv.setStockCat(stockList[index].getStockCat());
				tL.tv.setStockSubCat(stockList[index].getStockSubCat());
				tL.tv.setAmountPerUnit(stockList[index].getAmountPerUnit());
				tL.tv.setQty(stockList[index].getQty());
			}
		}
	}
	
	// Stock details changed in Vector
	
	// Print vector to overwrite file
	
	for(int i=0; i<stockList.size(); i++)
	{
		outfile << stockList[i].getStockID() << ":"
				<< stockList[i].getStockDescript() << ":"
				<< stockList[i].getStockCat() << ":"
				<< stockList[i].getStockSubCat() << ":"
				<< stockList[i].getAmountPerUnit() << ":"
				<< stockList[i].getQty() 
				<< endl;
	}
	
	outfile.close();
}


//------------------------------------------------


void StockList::printVector()
{
	
	for(int i=0; i<stockList.size(); i++)
	{
		cout << stockList[i].getStockID() << " "
				<< stockList[i].getStockDescript() << " "
				<< stockList[i].getStockCat() << " "
				<< stockList[i].getStockSubCat() << " "
				<< stockList[i].getAmountPerUnit() << " "
				<< stockList[i].getQty() 
				<< endl; 
	}
}




//------------------------------------------------
 
// 1 	1) Stock ID" << endl;
//		2) Stock Description" << endl;
//		3) Stock Category" << endl;
//		4) Stock Sub Category" << endl;
//		5) Stock Price" << endl;
//		6) Stock Quantity" << endl;
//		7) Exit to Main Menu" << endl;
		
void StockList::sortInAscending(int num)
{
	StockList* sL;
	
	if(num == 1) // stock ID
	{
		sort(stockList.begin(),stockList.end(),sL->compIDAsc);
	}
	else if(num == 2) // stock Descript
	{
		sort(stockList.begin(),stockList.end(),sL->compDescriptAsc);
	}
	else if(num == 3) // stock Cat
	{
		sort(stockList.begin(),stockList.end(),sL->compCatAsc);
	}
	else if (num == 4) // stock sub cat
	{
		sort(stockList.begin(),stockList.end(),sL->compSubCatAsc);
	}
	else if (num == 5) // Amount Per Unit
	{
		sort(stockList.begin(),stockList.end(),sL->compAmountAsc);
	}
	else if(num == 6) // Qty
	{
		sort(stockList.begin(),stockList.end(),sL->compQtyAsc);
	}
}

//------------------------------------------------

void StockList::sortInDescending(int num)
{
	StockList* sL;
	
	if(num == 1) // stock ID
	{
		sort(stockList.begin(),stockList.end(),sL->compIDDsc);
	}
	else if(num == 2) // stock Descript
	{
		sort(stockList.begin(),stockList.end(),sL->compDescriptDsc);
	}
	else if(num == 3) // stock Cat
	{
		sort(stockList.begin(),stockList.end(),sL->compCatDsc);
	}
	else if (num == 4) // stock sub cat
	{
		sort(stockList.begin(),stockList.end(),sL->compSubCatDsc);
	}
	else if (num == 5)  // Amount
	{
		sort(stockList.begin(),stockList.end(),sL->compAmountDsc);
	}
	else if(num == 6) // Qty
	{
		sort(stockList.begin(),stockList.end(),sL->compQtyDsc);
	}
}

//------------------------------------------------

//     Stock Search function with Search option Menu, Sort option Menu
int StockList::searchStock(StockList& sL)
{
	int choice1 = 0, choice2 = 0;
	
	do
	{
		do
		{
		
		cout << "\nSearch Stock" << endl;
		cout << "------------" << endl;
		cout << "\nSearch by : " << endl << endl;
		cout << "			1) Stock ID" << endl;
		cout << "			2) Stock Description" << endl;
		cout << "			3) Stock Category" << endl;
		cout << "			4) Stock Sub Category" << endl;
		cout << "			5) Stock Price" << endl;
		cout << "			6) Stock Quantity" << endl;
		cout << "			7) Exit to Main Menu" << endl;
		
		cout << "Enter Search Choice : ";
		if(cin.fail())	{	cout << "\nPlease enter an integer" << endl; cin.clear();	cin.ignore(20,'\n');	}
		cin >> choice1;
		}while(cin.fail());

		switch(choice1)
		{
			case 1: do
					{
					
						cout << "Sort by : " << endl;
						cout << "			1) View Stock" << endl;
						cout << "			2) Ascending Order" << endl;
						cout << "			3) Descending Order" << endl;
						cout << "			4) Exit to Search Menu" << endl;
					
						cout << "Enter Sort Choice : ";
						cin >> choice2;
						
						if(choice2 == 1)
						{
							sL.printVector();
						}
						else if(choice2 == 2)
						{
							sL.sortInAscending(choice1);
						}
						else if (choice2 == 3)
						{
							sL.sortInDescending(choice1);
						}
					}while(choice2 != 4);
					break;
					
			case 2: do
					{
					
						cout << "Sort by : " << endl;
						cout << "			1) View Stock" << endl;
						cout << "			2) Ascending Order" << endl;
						cout << "			3) Descending Order" << endl;
						cout << "			4) Exit to Search Menu" << endl;
					
						cout << "Enter Sort Choice : ";
						cin >> choice2;
						
						if(choice2 == 1)
						{
							sL.printVector();
						}
						else if(choice2 == 2)
						{
							sL.sortInAscending(choice1);
						}
						else if (choice2 == 3)
						{
							sL.sortInDescending(choice1);
						}
					}while(choice2 != 4);
					break;
					
			case 3: do
					{
					
						cout << "Sort by : " << endl;
						cout << "			1) View Stock" << endl;
						cout << "			2) Ascending Order" << endl;
						cout << "			3) Descending Order" << endl;
						cout << "			4) Exit to Search Menu" << endl;
					
						cout << "Enter Sort Choice : ";
						cin >> choice2;
						
						if(choice2 == 1)
						{
							sL.printVector();
						}
						else if(choice2 == 2)
						{
							sL.sortInAscending(choice1);
						}
						else if (choice2 == 3)
						{
							sL.sortInDescending(choice1);
						}
					}while(choice2 != 4);
					break;
					
			case 4: do
					{
					
						cout << "Sort by : " << endl;
						cout << "			1) View Stock" << endl;
						cout << "			2) Ascending Order" << endl;
						cout << "			3) Descending Order" << endl;
						cout << "			4) Exit to Search Menu" << endl;
					
						cout << "Enter Sort Choice : ";
						cin >> choice2;
						if(choice2 == 1)
						{
							sL.printVector();
						}
						else if(choice2 == 2)
						{
							sL.sortInAscending(choice1);
						}
						else if (choice2 == 3)
						{
							sL.sortInDescending(choice1);
						}
					}while(choice2 != 4);
					break;
					
			case 5: do
					{
					
						cout << "Sort by : " << endl;
						cout << "			1) View Stock" << endl;
						cout << "			2) Ascending Order" << endl;
						cout << "			3) Descending Order" << endl;
						cout << "			4) Exit to Search Menu" << endl;
					
						cout << "Enter Sort Choice : ";
						cin >> choice2;
						
						if(choice2 == 1)
						{
							sL.printVector();
						}
						else if(choice2 == 2)
						{
							sL.sortInAscending(choice1);
						}
						else if (choice2 == 3)
						{
							sL.sortInDescending(choice1);
						}
					}while(choice2 != 4);
					break;
					
			case 6: do
					{
					
						cout << "Sort by : " << endl;
						cout << "			1) View Stock" << endl;
						cout << "			2) Ascending Order" << endl;
						cout << "			3) Descending Order" << endl;
						cout << "			4) Exit to Search Menu" << endl;
					
						cout << "Enter Sort Choice : ";
						cin >> choice2;
						
						if(choice2 == 1)
						{
							sL.printVector();
						}
						else if(choice2 == 2)
						{
							sL.sortInAscending(choice1);
						}
						else if (choice2 == 3)
						{
							sL.sortInDescending(choice1);
						}
					}while(choice2 != 4);
					break;
				
				default: break;
			}
	
	}while (choice1 != 7);
}

//------------------------------------------------

void StockList::displayByCategory() // enter stockCat display
{
	StockList sL;
	
	sL.sortInAscending(3); // sort Vector to Stock Category
	
	// display vector
	sL.printVector();
}

void StockList::displayBySubCat() // enter subCat to display
{
	StockList sL;
	
	sL.sortInAscending(4); // sort Vector to subCat
	
	// display vector
	sL.printVector();
}

void StockList::displayByPrice() // enter amountPerUnit to display
{
	StockList sL;
	
	sL.sortInAscending(5); // sort Vector to Price
	
	// display vector
	sL.printVector();
}





