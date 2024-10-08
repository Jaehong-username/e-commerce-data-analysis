# e-commerce-data-analysis

I decided to use hash table as the main data structure to analyze the Amazon Inventory product csv data to take advantage of a constant run time complexity of insert and search functions with more than 10k rows of data. So, there will be two hash tables loaded with data from the Amazon inventory product csv file. Also, I wrote template code for hash table that can accept any data types as specified by the instruction. One hash table will be mapped to based on uniq Id data of each product from the csv file. The other one will be mapped to based on category data of each product from the csv file. One thing to note is that if category contains '|', this indicates that the following product belongs to multiple categories. Therefore, the following product will be stored in multiple index of the category hash table.

Then, in order to handle hash collision, I used linear probing for find prdouct function and chaining (linked list) for listInventory function. listInventory is only interested in printing out product Id and product name that matches with the following category from the user input. When hash collision occurs, data should be inserted into the linked list from the same index, so that if an user inputs category, the program will find the hashindex that contains the following category and simply print the linked list. 
Moreover, if hash table slots are more than 50% filled, rehash function will be implemented to reduce the frequency of hash collision by resizing the hash table.

What makes the Amazon inventory csv data complicated is that it often contains a data column that contains a single comma as part of data itself, it's indicated by double quotes. So, when parsing the data, it's important to when to ignore a single comma from stringstream or not.

The way I made an algorithm for this is that if it runs into a double quote, it will run into an iteration loop to keep concatenating the data with a double quote until it finds the next string buffer is a single comma which comes right after the end of double quote. That's when the data column including double quotes ends.

Also, notice that there are quite a bit of data columns that have missing data indicated by solely ,, In this case, I wrote codes that will make the program perceive the data as NA.

If there is no data that matches with the user input of uniq Id or category, the program will print 'Inventory/Product not found’ or 'Invalid Category'
