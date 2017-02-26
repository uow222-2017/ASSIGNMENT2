#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "stock_list.h"

using namespace std;

const char MAX = 100;
const char MAXCHAR = 30;

char trash;
const char delim = ':';
const char FILE_NAME[] = "SampleData.txt";
const char FILE_STOCK[] = "StockList.txt";

/////////// Function ProtoTypes ////////////////



int main()
{
	
	fstream afile;
	StockList sL;
	
	// Begin read from text file to vetor
	sL.LoadSample(FILE_NAME);
	
	sL.vectorToFile(FILE_STOCK);
	
	// sL.printVector();
	
	sL.LoadStock(FILE_STOCK);
	
	
}



void StockList::LoadSample(const char fileName[])
{
	fstream afile;
	
	afile.open(fileName,ios::in);
	

	string stringBuffer;
	int intBuffer;
	Stock stockObj;
	bool isUnique;
	
	if(!afile)
	{
		afile.close();
		// throw exception
	}
	
	
	// trash gets the delimiter and throws it away
	// Begin reading from file
	// someVector[0].setValue("someName",1);
	int i = 0;
	while( afile >> intBuffer ) // stock id
	{
		//cout << "Start reading\n";
		isUnique = true;
		
		stockObj.setStockID(intBuffer); // if there are transactions going on
		
		afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock description
		stockObj.setStockDescript(stringBuffer);
		
		//afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock category
		stockObj.setStockCat(stringBuffer);
		
		//afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock sub category
		stockObj.setStockSubCat(stringBuffer);
		
		//afile >> trash; // throw delim
		afile >> intBuffer;   				// stock amount per unit
		stockObj.setAmountPerUnit(intBuffer);
		
		afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock qty in out
		intBuffer = atoi(stringBuffer.c_str());
		stockObj.setQty(intBuffer);
		
		//afile >> trash; // throw delim
		getline(afile,stringBuffer,'\n'); // throw away transaction date
		//afile >> trash; // throw away '\n'
		
		// Checking for data with same stockID
		
		for(int j = 0; j < stockList.size(); j++)
		{
			
			
			if(stockObj.getStockID() == stockList[j].getStockID()) // if same stockID
			{
					// Update Qty
				
				intBuffer = stockList[j].getQty() + stockObj.getQty();
				stockList[j].setQty(intBuffer);
					
				isUnique = false;
					
			}
			
		
		}
		
		if(isUnique)
		{
				
			stockList.push_back(stockObj);
			
			/*
			cout << "Stock " << i+1 << " : " << stockList[i].getStockID() << " "
			<< stockList[i].getStockDescript() << " "
			<< stockList[i].getStockCat() << " "
			<< stockList[i].getStockSubCat() << " "
			<< stockList[i].getAmountPerUnit() << " "
			<< stockList[i].getQty() << " " 
			<< endl;
			*/
			
			
			++i;
		}
		
		
		
		// Start reading from new line again
		
	}
	
	
	afile.close();
	cout << "Reading from text file to vector done." << endl;
	
}

//------------------------------------------------

void StockList::vectorToFile(const char fileName[])
{
	ofstream outfile;
	
	outfile.open(fileName);
	
	if(!outfile)
	{
		outfile.close();
		// throw exception
	}
	
	for (int i=0; i<stockList.size(); ++i)
	{
		outfile << stockList[i].getStockID() << ":"
				<< stockList[i].getStockDescript() << ":"
				<< stockList[i].getStockCat() << ":"
				<< stockList[i].getStockSubCat() << ":"
				<< stockList[i].getAmountPerUnit() << ":"
				<< stockList[i].getQty() << endl;
	}
	
	outfile.close();
	cout << fileName << " generated." << endl;
	
	
	
}

//----------------------------------------------

void StockList::LoadStock(const char fileName[])
{
	fstream afile;

	
	afile.open(fileName,ios::in);
	

	string stringBuffer;
	int intBuffer;
	Stock stockObj;
	bool isUnique;
	
	if(!afile)
	{
		afile.close();
		// throw exception
	}
	
	stockList.clear(); // Clear Vector to enter in data again
	
	
	
	// trash gets the delimiter and throws it away
	// Begin reading from file
	// someVector[0].setValue("someName",1);
	int i = 0;
	while( afile >> intBuffer ) // stock id
	{
		//cout << "Start reading\n";
		isUnique = true;
		
		stockObj.setStockID(intBuffer); // if there are transactions going on
		
		afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock description
		stockObj.setStockDescript(stringBuffer);
		
		//afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock category
		stockObj.setStockCat(stringBuffer);
		
		//afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock sub category
		stockObj.setStockSubCat(stringBuffer);
		
		//afile >> trash; // throw delim
		afile >> intBuffer;   				// stock amount per unit
		stockObj.setAmountPerUnit(intBuffer);
		
		afile >> trash; // throw delim
		getline(afile,stringBuffer,delim); // stock qty in out
		intBuffer = atoi(stringBuffer.c_str());
		stockObj.setQty(intBuffer);
		
		
		// Checking for data with same stockID
		
		for(int j = 0; j < stockList.size(); j++)
		{
			
			
			if(stockObj.getStockID() == stockList[j].getStockID()) // if same stockID
			{
					// Update Qty
				
				intBuffer = stockList[j].getQty() + stockObj.getQty();
				stockList[j].setQty(intBuffer);
					
				isUnique = false;
					
			}
			
		
		}
		
		if(isUnique)
		{
				
			stockList.push_back(stockObj);
			
			/*
			cout << "Stock " << i+1 << " : " << stockList[i].getStockID() << " "
			<< stockList[i].getStockDescript() << " "
			<< stockList[i].getStockCat() << " "
			<< stockList[i].getStockSubCat() << " "
			<< stockList[i].getAmountPerUnit() << " "
			<< stockList[i].getQty() << " " 
			<< endl;
			*/
			
			
			++i;
		}
		
		
		
		
		
	}
	
	
	afile.close();
	cout << "Reading from text file to vector done." << endl;
	
	
	
}










