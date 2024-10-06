#pragma once

#include "HashTable.h"

class DataAnalysis
{
public:
	DataAnalysis()
	{
		//Don't forget to initialize the hash table with the nullptr!!!!
		this->idHashTable.initEmptyArray();
		this->categoryHashTable.initEmptyArray();
	}

	~DataAnalysis()
	{
	}
	
	string dataWithDoubleQuotes(std::stringstream& ss);
	ProductData* parseCSVDataLine(ifstream& fileStream, std::stringstream& tempLineStream, string tempUniqId);
	


	void loadHashTable();

	void parseCategory(string rawCategory, ProductData* pMem);

	



	

	void find(string inventoryId);
	void listInventory(string inventoryCategory); //list inventory of products that matches with category

private:
	//Need two hash tables
	HashTable<string, ProductData> idHashTable;
	HashTable<string, ProductData> categoryHashTable;
	ifstream fileStream;
};