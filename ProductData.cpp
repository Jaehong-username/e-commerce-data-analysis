#include "ProductData.h"

ProductData::ProductData(string uniqId, string productName, string brandName, string asin, string category,
	string upcEanCode, string listPrice, string sellingPrice, string quantity, string modelNumber,
	string aboutProduct, string productSpecification, string technicalDetails, string shippingWeight, string productDimensions,
	string image, string variants, string sku, string productUrl, string stock, string productDetails, string dimensions,
	string color, string ingredients, string directionToUse, string isAmazonSeller, string sizeQuantityVariant, string productDescription)
{
	this->uniqId = uniqId;
	this->productName = productName;
	this->brandName = brandName;
	this->asin = asin;
	this->category = category;
	this->upcEanCode = upcEanCode;
	this->listPrice = listPrice;
	this->sellingPrice = sellingPrice;
	this->quantity = quantity;
	this->modelNumber = modelNumber;
	this->aboutProduct = aboutProduct;
	this->productSpecification = productSpecification;
	this->technicalDetails = technicalDetails;
	this->shippingWeight = shippingWeight;
	this->productDimensions = productDimensions;
	this->image = image;
	this->variants = variants;
	this->sku = sku;
	this->productUrl = productUrl;
	this->stock = stock;
	this->productDetails = productDetails;
	this->dimensions = dimensions;
	this->color = color;
	this->ingredients = ingredients;
	this->directionToUse = directionToUse;
	this->isAmazonSeller = isAmazonSeller;
	this->sizeQuantityVariant = sizeQuantityVariant;
	this->productDescription = productDescription;
}


string& ProductData::getUniqId()
{
	return this->uniqId;
}

string& ProductData::getProductName()
{
	return this->productName;
}

string& ProductData::getBrandName()
{
	return this->brandName;
}

string& ProductData::getAsin()
{
	return this->asin;
}

string& ProductData::getCategory()
{
	return this->category;
}

string& ProductData::getUpcEanCode()
{
	return this->upcEanCode;
}

string& ProductData::getListPrice()
{
	return this->listPrice;
}

string& ProductData::getSellingPrice()
{
	return this->sellingPrice;
}

string& ProductData::getQuantity()
{
	return this->quantity;
}

string& ProductData::getModelNumber()
{
	return this->modelNumber;
}

string& ProductData::getAboutProduct()
{
	return this->aboutProduct;
}

string& ProductData::getProductSpecification()
{
	return this->productSpecification;
}

string& ProductData::getTechnicalDetails()
{
	return this->technicalDetails;
}

string& ProductData::getShippingWeight()
{
	return this->shippingWeight;
}

string& ProductData::getProductDimensions()
{
	return this->productDimensions;
}

string& ProductData::getImage()
{
	return this->image;
}

string& ProductData::getVariants()
{
	return this->variants;
}

string& ProductData::getSku()
{
	return this->sku;
}

string& ProductData::getProductUrl()
{
	return this->productUrl;
}

string& ProductData::getStock()
{
	return this->stock;
}

string& ProductData::getProductDetails()
{
	return this->productDetails;
}

string& ProductData::getDimensions()
{
	return this->dimensions;
}

string& ProductData::getColor()
{
	return this->color;
}

string& ProductData::getIngredients()
{
	return this->ingredients;
}

string& ProductData::getDirectionToUse()
{
	return this->directionToUse;
}

string& ProductData::getIsAmazonSeller()
{
	return this->isAmazonSeller;
}

string& ProductData::getSizeQuantityVariant()
{
	return this->sizeQuantityVariant;
}

string& ProductData::getProductDescription()
{
	return this->productDescription;
}
