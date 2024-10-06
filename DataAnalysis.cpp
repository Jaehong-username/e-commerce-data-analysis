#include "DataAnalysis.h"

string DataAnalysis::dataWithDoubleQuotes(std::stringstream& ss)
{
	string tempFullData;
	string partialData;
    string placeHolder;
    // if the sentence starts with "
    if (ss.peek() == '\"')
	{
		do
		{
			std::getline(ss, partialData, '\"');
			tempFullData += partialData;
		} while (ss.peek() != ',');
        //once out of the do while loop! needs this dummy placeholder for the next data!
        std::getline(ss, placeHolder, ',');
    }
    else
		std::getline(ss, tempFullData, ',');

	if (tempFullData == "")
	{
		tempFullData = "NA";
	}

	return tempFullData;
}

//will return the Product DataNode after parsing each line
ProductData* DataAnalysis::parseCSVDataLine(ifstream& fileStream, std::stringstream& tempLineStream, string tempUniqId)
{
	if (fileStream.is_open()) //if the fileStream is open
	{
		string tempProductName;
		string tempBrandName;
		string tempAsin;
		string tempCategory;
		string tempUpcEanCode;
		string tempListPrice;
		string tempSellingPrice;
		string tempQuantity;
		string tempModelNumber;
		string tempAboutProduct;
		string tempProductSpecification;
		string tempTechnicalDetails;
		string tempShippingWeight;
		string tempProductDimensions;
		string tempImage;
		string tempVariants;
		string tempSku;
		string tempProductUrl;
		string tempStock;
		string tempProductDetails;
		string tempDimensions;
		string tempColor;
		string tempIngredients;
		string tempDirectionToUse;
		string tempIsAmazonSeller;
		string tempSizeQuantityVariant;
		string tempProductDescription;


			
			tempProductName = dataWithDoubleQuotes(tempLineStream);
			tempBrandName = dataWithDoubleQuotes(tempLineStream);
			tempAsin = dataWithDoubleQuotes(tempLineStream);
			tempCategory = dataWithDoubleQuotes(tempLineStream);
			tempUpcEanCode = dataWithDoubleQuotes(tempLineStream);
			tempListPrice = dataWithDoubleQuotes(tempLineStream);
			tempSellingPrice = dataWithDoubleQuotes(tempLineStream);
			tempQuantity = dataWithDoubleQuotes(tempLineStream);
			tempModelNumber = dataWithDoubleQuotes(tempLineStream);
			tempAboutProduct = dataWithDoubleQuotes(tempLineStream);
			tempProductSpecification = dataWithDoubleQuotes(tempLineStream);
			tempTechnicalDetails = dataWithDoubleQuotes(tempLineStream);
			tempShippingWeight = dataWithDoubleQuotes(tempLineStream);
			tempProductDimensions = dataWithDoubleQuotes(tempLineStream);
			tempImage = dataWithDoubleQuotes(tempLineStream);
			tempVariants = dataWithDoubleQuotes(tempLineStream);
			tempSku = dataWithDoubleQuotes(tempLineStream);
			tempProductUrl = dataWithDoubleQuotes(tempLineStream);
			tempStock = dataWithDoubleQuotes(tempLineStream);
			tempProductDetails = dataWithDoubleQuotes(tempLineStream);
			tempDimensions = dataWithDoubleQuotes(tempLineStream);
			tempColor = dataWithDoubleQuotes(tempLineStream);
			tempIngredients = dataWithDoubleQuotes(tempLineStream);
			tempDirectionToUse = dataWithDoubleQuotes(tempLineStream);
			tempIsAmazonSeller = dataWithDoubleQuotes(tempLineStream);
			tempSizeQuantityVariant = dataWithDoubleQuotes(tempLineStream);
			tempProductDescription = dataWithDoubleQuotes(tempLineStream);
			

			ProductData* pMem = new ProductData(tempUniqId,
												tempProductName,
												tempBrandName,
												tempAsin,
												tempCategory,
												tempUpcEanCode,
												tempListPrice,
												tempSellingPrice,
												tempQuantity,
												tempModelNumber,
												tempAboutProduct,
												tempProductSpecification,
												tempTechnicalDetails,
												tempShippingWeight,
												tempProductDimensions,
												tempImage,
												tempVariants,
												tempSku,
												tempProductUrl,
												tempStock,
												tempProductDetails,
												tempDimensions,
												tempColor,
												tempIngredients,
												tempDirectionToUse,
												tempIsAmazonSeller,
												tempSizeQuantityVariant,
												tempProductDescription);

			return pMem;
	}

	else
	{
		cout << "The csv file is not open! Can't implement this function. Please Doublecheck!" << endl;
		return nullptr;
	}
		
}


//This is more of customized function
//for the first function
void DataAnalysis::loadHashTable()
{
	if (!fileStream.is_open()) //if the fileStream is open
	{
		fileStream.open("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");


		string tempLine;
		string tempUniqId; //since it will be used as the key

		string tempBrandName;

		string tempRawCategory;
		
		std::getline(fileStream, tempLine); //to skip the first line

		while (std::getline(fileStream, tempLine))
		{
			
			std::stringstream tempLineStream(tempLine);

			std::getline(tempLineStream, tempUniqId, ','); //uniq Id product
			//HashNode<string, ProductData>* pMem = new HashNode<string, ProductData>(tempUniqId, parseCSVDataLine(fileStream, tempLineStream));
			ProductData* pMem = parseCSVDataLine(fileStream, tempLineStream, tempUniqId);
			
			
			this->idHashTable.insertItem(tempUniqId, pMem);


			tempRawCategory = pMem->getCategory();
			parseCategory(tempRawCategory, pMem);

			
		}
		
		fileStream.close();
	}

}

void DataAnalysis::parseCategory(string rawCategory, ProductData* pMem)
{
	int count = 0;
	std::stringstream newStringStream(rawCategory);
	string oneCategory = "";

	for (char delim : rawCategory)
	{
		if (delim == '|')
			count++;
	}

	while (count != 0)
	{

		std::getline(newStringStream, oneCategory, '|');
		if (oneCategory.at(0) == ' ')
		{
			oneCategory.erase(0, 1);
		}

		if (oneCategory.at(oneCategory.length() - 1) == ' ')
		{
			oneCategory.erase(oneCategory.length() - 1, 1);
		}

		categoryHashTable.insertItemChaining(oneCategory, pMem);

		count--;

	}

	if (count == 0)
	{
		categoryHashTable.insertItemChaining(oneCategory, pMem);
	}
	
	
}



//Uniq Id, Product Name, Brand Name, Asin, Category, Upc Ean Code, List Price, Selling Price, Quantity, 
//Model Number, About Product, Product Specification, Technical Details, Shipping Weight, Product Dimensions, 
//Image, Variants, Sku, Product Url, Stock, Product Details, Dimensions, Color, Ingredients, Direction To Use, 
//Is Amazon Seller, Size Quantity Variant, Product Description

void DataAnalysis::find(string inventoryId)
{
	HashNode<string, ProductData>* pFind = this->idHashTable.hashTableLookUp(inventoryId);

	if (pFind != nullptr)
	{
		cout << "The description of the product with ID: " << inventoryId << endl;
		cout << "Product Name: " << pFind->getDataPtr()->getProductName() << endl;
		cout << "Brand Name: " << pFind->getDataPtr()->getBrandName() << endl;
		cout << "Asin: " << pFind->getDataPtr()->getAsin() << endl;
		cout << "Category: " << pFind->getDataPtr()->getCategory() << endl;
		cout << "Upc Ean Code: " << pFind->getDataPtr()->getUpcEanCode() << endl;
		cout << "List Price: " << pFind->getDataPtr()->getListPrice() << endl;
		cout << "Selling Price: " << pFind->getDataPtr()->getSellingPrice() << endl;
		cout << "Quantity: " << pFind->getDataPtr()->getQuantity() << endl;
		cout << "Model Number: " << pFind->getDataPtr()->getModelNumber() << endl;
		cout << "About Product: " << pFind->getDataPtr()->getAboutProduct() << endl;
		cout << "Product Specification: " << pFind->getDataPtr()->getProductSpecification() << endl;
		cout << "Technical Details: " << pFind->getDataPtr()->getTechnicalDetails() << endl;
		cout << "Shipping Weight: " << pFind->getDataPtr()->getShippingWeight() << endl;
		cout << "Product Dimensions: " << pFind->getDataPtr()->getProductDimensions() << endl;
		cout << "Image: " << pFind->getDataPtr()->getImage() << endl;
		cout << "Variants: " << pFind->getDataPtr()->getVariants() << endl;
		cout << "Sku: " << pFind->getDataPtr()->getSku() << endl;
		cout << "Product Url: " << pFind->getDataPtr()->getProductUrl() << endl;
		cout << "Product Details: " << pFind->getDataPtr()->getProductDetails() << endl;
		cout << "Dimensions: " << pFind->getDataPtr()->getDimensions() << endl;
		cout << "Color: " << pFind->getDataPtr()->getColor() << endl;
		cout << "Ingredients: " << pFind->getDataPtr()->getIngredients() << endl;
		cout << "Direction To Use: " << pFind->getDataPtr()->getDirectionToUse() << endl;
		cout << "Is Amazon Seller: " << pFind->getDataPtr()->getIsAmazonSeller() << endl;
		cout << "Product Name: " << pFind->getDataPtr()->getProductName() << endl;
		cout << "Size Quantity Variant: " << pFind->getDataPtr()->getSizeQuantityVariant() << endl;
		cout << "Product Description: " << pFind->getDataPtr()->getProductDescription() << endl << endl << endl;
		
	}

	else
    {
        cout << "'Inventory/Product not found'" << endl;
        cout << "The product that matches with the following product uniq Id does not exist!: " << inventoryId << endl
             << endl;
    }
	
}

void DataAnalysis::listInventory(string inventoryCategory)
{
	HashNode<string, ProductData>* pFind = this->categoryHashTable.hashTableLookUp(inventoryCategory);

	if (pFind != nullptr)
	{
		cout << "The list that matches with " << inventoryCategory << "is as follows: " << endl << endl;

		while (pFind != nullptr)
		{
			cout << "Uniq Id: " << pFind->getDataPtr()->getUniqId() << endl;
			cout << "Product Name: " << pFind->getDataPtr()->getProductName() << endl << endl;

			pFind = pFind->getpNext();
		}

	}

	else
    {
        cout << "'Invalid Category'" << endl;
        cout << "The list that matches with the following inventory category does not exist!: " << inventoryCategory << endl
             << endl;
    }
		
}
