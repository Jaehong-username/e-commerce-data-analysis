#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;


class ProductData
{
public:
	

	ProductData(string uniqId, string productName, string brandName, string asin, string category,
		string upcEanCode, string listPrice, string sellingPrice, string quantity, string modelNumber,
		string aboutProduct, string productSpecification, string technicalDetails, string shippingWeight, string productDimensions,
		string image, string variants, string sku, string productUrl, string stock, string productDetails, string dimensions,
		string color, string ingredients, string directionToUse, string isAmazonSeller, string sizeQuantityVariant, string productDescription);
		

	~ProductData()
	{
		cout << "Product Data destructor invoked!" << endl;
	}

	//Uniq Id, Product Name, Brand Name, Asin, Category, Upc Ean Code, List Price, Selling Price, Quantity, 
	// Model Number, About Product, Product Specification, Technical Details, Shipping Weight, 
	// Product Dimensions, Image, Variants, Sku, Product Url, Stock, Product Details, Dimensions, Color, 
		//Ingredients, Direction To Use, Is Amazon Seller, Size Quantity Variant, Product Description

	//Getter  no need for unique Id since that will be used for the key
	string& getUniqId();
	string& getProductName();
	string& getBrandName();
	string& getAsin();
	string& getCategory();
	string& getUpcEanCode();
	string& getListPrice();
	string& getSellingPrice();
	string& getQuantity();
	string& getModelNumber();
	string& getAboutProduct();
	string& getProductSpecification();
	string& getTechnicalDetails();
	string& getShippingWeight();
	string& getProductDimensions();
	string& getImage();
	string& getVariants();
	string& getSku();
	string& getProductUrl();
	string& getStock();
	string& getProductDetails();
	string& getDimensions();
	string& getColor();
	string& getIngredients();
	string& getDirectionToUse();
	string& getIsAmazonSeller();
	string& getSizeQuantityVariant();
	string& getProductDescription();

	
private:
	string uniqId;
	string productName;
	string brandName;
	string asin;
	string category;
	string upcEanCode;
	string listPrice;
	string sellingPrice;
	string quantity;
	string modelNumber;
	string aboutProduct;
	string productSpecification;
	string technicalDetails;
	string shippingWeight;
	string productDimensions;
	string image;
	string variants;
	string sku;
	string productUrl;
	string stock;
	string productDetails;
	string dimensions;
	string color;
	string ingredients;
	string directionToUse;
	string isAmazonSeller;
	string sizeQuantityVariant;
	string productDescription;
	
};