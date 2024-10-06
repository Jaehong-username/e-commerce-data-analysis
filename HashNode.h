#pragma once

#include "ProductData.h"

template <class T, class U>
class HashNode
{
public:

	HashNode(T newKey, U* newDataPtr) : key{ newKey }, dataPtr{ newDataPtr }, pNext{nullptr}
	{
	}

	~HashNode()
	{
		cout << "Destructor for Hash Node!" << endl;
	}

	//Getter
	T& getKey();
	U*& getDataPtr();
	HashNode<T,U>*& getpNext();  //make sure to define <T,U>

	//Setter
	void setpNext(HashNode* newpNext);

private:
	T key;
	U* dataPtr;
	HashNode* pNext;

};

template<class T, class U>
T& HashNode<T, U>::getKey()
{
	return this->key;
}

template<class T, class U>
U*& HashNode<T, U>::getDataPtr()
{
	return this->dataPtr;
}

template<class T, class U>
HashNode<T,U>*& HashNode<T, U>::getpNext()
{
	return this->pNext;
}

template<class T, class U>
void HashNode<T, U>::setpNext(HashNode* newpNext)
{
	this->pNext = newpNext;
}
