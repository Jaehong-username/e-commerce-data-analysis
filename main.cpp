#include "DataAnalysis.h"

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
        << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||             //if line starts equals with ":help"
        (line.rfind("find", 0) == 0) ||     // if line starts with "find"
        (line.rfind("listInventory") == 0); // if line starts with the substring "listInventory"
    //rfind("") function: searches for the position with the string argument at the last occurence.
}

void evalCommand(string line, DataAnalysis& dataAnalysis)
{
    

    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        //cout << "YET TO IMPLEMENT!" << endl;
        
        string userInputId;
        cout << "Please enter an unique Inventory ID: ";
        //std::getline(std::cin, userInputId); //to discard the a newline character
        
        cin >> userInputId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //Implement the menu option 1
        dataAnalysis.find(userInputId);

    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        //cout << "YET TO IMPLEMENT!" << endl;
        string userInputCategory;
        cout << "Please enter an specific category: " << endl;
        //std::getline(std::cin, userInputCategory); //to discard the a newline character
        cin >> userInputCategory; //cin doesn't get a whitespace from the user
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //Implement the menu option 2
        dataAnalysis.listInventory(userInputCategory);
    }
}

void bootStrap(DataAnalysis& dataAnalysis)
{
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
    dataAnalysis.loadHashTable();
    
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    
    cout << "Before entering uniq Id or category, please enter the following commands first!: find, listInventory " << endl;
    cout << "After entering either one of the two commands, it will ask you to input Id or category!" << endl;

    
}

int main(int argc, char const* argv[])
{
    DataAnalysis dataAnalysis;
    
    /*ifstream fileStream;
    if (!fileStream.is_open())
    {
        fileStream.open("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");
        string tempLine;
        int num;
        int lineNum = 1;
        
        while (std::getline(fileStream, tempLine))
        {
            num = 0;
            for (char c : tempLine)
            {
                if (c == '|')
                {
                    ++num;
                }
            }
            cout << lineNum << "number of | s in this line: " << num << endl;
            ++lineNum;
            
        }

        fileStream.close();

    }*/

    string line;

    bootStrap(dataAnalysis); //print out a welcoming message
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, dataAnalysis);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
