#pragma once

#include "HashNode.h"




template <class T, class U>
class HashTable
{
public:
	HashTable();
	~HashTable();
	

	void initEmptyArray();

	
	void insertItem(T key, U* dataPtr); // U = DataNode
	HashNode<T,U>*& hashTableLookUp(T key);

	//chaining!
	void insertItemChaining(T key, U* dataPtr);
	HashNode<T,U>*& hashTableChainLookup(T key);

	void rehash();
	

private:
	int hashTableSize;
	HashNode<T,U>** hashTablePtr; //* for indicating an array another *for it is an array of pointer to Data Node
	int howManyFilled;
};

template <class T, class U>
HashTable<T, U>::HashTable()
{
	this->hashTableSize = 5003; //prime number around 5003
	this->hashTablePtr = nullptr;
	this->howManyFilled = 0;
}

template <class T, class U>
HashTable<T,U>::~HashTable()
{
	
	delete[] this->hashTablePtr;
	this->hashTablePtr = nullptr;
	cout << "Hash Table destroyed!\n";
}



//initializing hash table
template <class T, class U>
void HashTable<T,U>::initEmptyArray()
{
	hashTablePtr = new HashNode<T,U> * [this->hashTableSize]; //it will be an array of pointer to DatanNode

	for (int i = 0; i < hashTableSize; i++)
	{
		hashTablePtr[i] = nullptr;
	}
}



template <class T, class U>
void HashTable<T,U>::insertItem(T key, U* dataPtr)
{

	std::size_t hashIndex = std::hash<T>{}(key) % this->hashTableSize;
	//int hashIndex = hashFunction(&key);
	bool inserted = false;

	while (!inserted)
	{
		if (hashTablePtr[hashIndex] == nullptr) //if the content at that index is empty
		{
			//dynamically allocate memory for a HashNode
			HashNode<T, U>* pMem = new HashNode<T, U>(key, dataPtr);
			hashTablePtr[hashIndex] = pMem; //after creating the node just relink the pointer!

			++howManyFilled;
			inserted = true;

			//if more than 50% is occupied! time to rehash the array
			if ((double)(this->howManyFilled) / (double)(this->hashTableSize) > 0.5)
			{
				rehash();
				cout << "Rehash complete!\n";
			}
		}

		else //hash collision occurs!!!  Let's do linear probing
		{
			//if it reaches to the end of table and have to increment again now it wraps around the hash table
			if (hashIndex == hashTableSize - 1)
			{
				hashIndex = 0;
			}
			else //linear probing due to hash collision
				++hashIndex;


			if (hashTablePtr[hashIndex] == nullptr)
			{
				//dynamically allocate memory for a HashNode
				HashNode<T, U>* pMem = new HashNode<T, U>(key, dataPtr);
				hashTablePtr[hashIndex] = pMem; //after creating the node just relink the pointer!

				++howManyFilled;
				inserted = true;

				//if more than 50% is occupied! time to rehash the function
				if ((double)(this->howManyFilled) / (double)(this->hashTableSize) > 0.5)
				{
					//Rehash the array!
					rehash();
					cout << "Rehash complete!\n";
				}
			}
		}
	}
}



template <class T, class U> //look up function if the hash collision is linear probing
HashNode<T,U>*& HashTable<T,U>::hashTableLookUp(T key)
{
	//unsigned int hashIndex = hashFunction(&key); //always returns the same index
	std::size_t hashIndex = std::hash<T>{}(key) % this->hashTableSize;
	bool found = false;

	while (!found)
	{
		//Case1: matched with the data. Already in the hash table
		if (hashTablePtr[hashIndex] != nullptr && hashTablePtr[hashIndex]->getKey() == key)
		{
			cout << "Found the data at HashTable[" << hashIndex << "]" << endl;
			found = true;
			return this->hashTablePtr[hashIndex];

		}

		//Case2: not empty but the data is different linear probing
		else if (hashTablePtr[hashIndex] != nullptr && hashTablePtr[hashIndex]->getKey() != key)
		{
			cout << "Hash Indec " <<hashIndex << ":" << hashTablePtr[hashIndex]->getDataPtr()->getCategory() << endl;
			//if its the last index
			if (hashIndex + 1 == this->hashTableSize)
			{
				hashIndex = 0;
			}
			else
			{
				++hashIndex;
			}
			
		}

		//case3
		else if (hashTablePtr[hashIndex] == nullptr)
		{
			cout << "'Data not found'" << endl;
			//return nullptr;
			return this->hashTablePtr[hashIndex];
		}
	}

}


//if collision occurs just insert it into the pHead
template <class T, class U>
void HashTable<T,U>::insertItemChaining(T key, U* dataPtr)
{
	//unsigned int hashIndex = hashFunction(&key);
	std::size_t hashIndex = std::hash<T>{}(key) % this->hashTableSize;
	bool inserted = false;

	//if the list is empty
	if (hashTablePtr[hashIndex] == nullptr)
	{
		//dynamically allocate memory for a HashNode
		HashNode<T, U>* pMem = new HashNode<T, U>(key, dataPtr);
		hashTablePtr[hashIndex] = pMem; //after creating the node just relink the pointer!

		++howManyFilled;
		if ((double)(howManyFilled) / (double)(hashTableSize) > 0.5)
		{
			rehash();
		}

	}

	//Data collision so we will insert the node into the linked list.
	else
	{
		//dynamically allocate memory for a HashNode
		HashNode<T, U>* pMem = new HashNode<T, U>(key, dataPtr);
		//hashTablePtr[hashIndex] = pMem; //after creating the node just relink the pointer! Caution!!!! In this way we lose the ptr to the old lsit!!!

		//temporal pointer
		HashNode<T,U>* pTemp = hashTablePtr[hashIndex];
		hashTablePtr[hashIndex] = pMem;
		pMem->setpNext(pTemp);

		if ((double)(howManyFilled) / (double)(hashTableSize) > 0.5)
		{
			rehash();
		}
	}
}

template <class T, class U>
HashNode<T,U>*& HashTable<T,U>::hashTableChainLookup(T key)
{
	//unsigned int hashIndex = hashFunction(&key); //always returns the same index
	std::size_t hashIndex = std::hash<T>{}(key) % this->hashTableSize;

	if (hashTablePtr[hashIndex] == nullptr)
	{
		cout << "'Invalid Category'" << endl;
		return nullptr;
	}

	//found the category that matches with the user input
	/*else
	{
		HashNode<T,U>* pCur = hashTablePtr[hashIndex];
		cout << "Here is the list of " << key << ":" << endl;
		while (pCur != nullptr)
		{
			cout << pCur->getUniqId() << endl;
			cout << pCur->getProductName() << endl << endl;

			pCur = pCur->getpNext();
		}
	}*/
	else
		return hashTablePtr[hashIndex];
}


template <class T, class U>
void HashTable<T,U>::rehash()
{
	cout << "More than half of the hash table is filled, It needs to be rehashed to double the size of the table!" << endl;
	int prevSize = this->hashTableSize;
	this->hashTableSize = this->hashTableSize * 2 + 1; //rehashing the size

	HashNode<T,U>** oldHashTablePtr = this->hashTablePtr;


	//the original pointer now points to enlongated size of the arrahy.
	this->hashTablePtr = new HashNode<T,U> * [this->hashTableSize];//now have the pointer to the enlarged hash table
	this->initEmptyArray(); //make sure to init the new Empty Array

	//traversing through the old array   prevSize equals to the size of the array
	for (int i = 0; i < prevSize; i++)
	{
		if (oldHashTablePtr[i] != nullptr)
		{
			//reinsert the data into the new hash table by getting the new hashIndex
			//int newHashIndex = hashFunction( &(oldHashTablePtr[i]->getKey() ) ); // will get a new index based on the updated size
			std::size_t newHashIndex = std::hash<T>{}(oldHashTablePtr[i]->getKey()) % this->hashTableSize;
			hashTablePtr[newHashIndex] = oldHashTablePtr[i]; //just reassign the pointer that's it
		}

	}

	//To prevent the memory leak!
	//oldHashTablePtr
	delete[] oldHashTablePtr; //delete the old one after relinking it with an new pointer.
	oldHashTablePtr = nullptr;
	//cout << "Test\n";

}



