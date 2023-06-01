/*
    Christian Chacon | 5/18/23

    CIS - 230 - 01
*/
#include <iostream>
#include <limits>
#include <cstring>

const int Max_Count = 20;

class Retail_Item{
private://class data as private
    std::string description;
    short int unitsOnHand;
    double price;
    short int reorderQuantity;

public://class data as public
    Retail_Item(){
        description = "";
        unitsOnHand = 0;
        price = 0.00;
        reorderQuantity = 0;
    }

    Retail_Item(std::string description, short int unitsOnHand, double price, short int reorderQuantity){
        this->description = description;
        this->unitsOnHand = unitsOnHand;
        this->price = price;
        this->reorderQuantity = reorderQuantity;
    }

    //change the data
    void setDescription(std::string description){this->description = description;}
    void setUnitsOnHand(short int unitsOnHand){this->unitsOnHand = unitsOnHand;}
    void setPrice(double price){this->price = price;}
    void setReorderQuantity(short int reorderQuantity){this->reorderQuantity = reorderQuantity;}

    //access the data
    std::string getDescription(){return description;}
    short int getUnitsOnHand(){return unitsOnHand;}
    double getPrice(){return price;}
    short int getReorderQuantity(){return reorderQuantity;}
};// - - - - - - - End Retail_Item Class - - - - - - -

char displayChoices();
int addItem(Retail_Item item[]);
void displayAllInventory(short int countItem, Retail_Item item[]);
void checkForSimilarItem(short int countItem, Retail_Item item[]);
void displayLowStock(short int countItem, Retail_Item item[]);
void editCurrentItems(short int countItem, Retail_Item item[]);
void printAllInventory(short int countItem, Retail_Item item[]);


int main(){
    Retail_Item item[Max_Count];
    char input, printInventory;
    short int countItem = 0, fillArray = 0;

    std::cout<<"Would you like to manage the inventory? (Y/N) ";
        std::cin>>input;
        input = toupper(input);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail() || (input != 'Y' && input != 'N')){
                std::cout << "\n  Invalid"<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Would you like to manage the inventory? (Y/N) ";
                    std::cin>>input;
                    input = toupper(input);
            }

    if(input == 'Y'){
        std::cout<<"\nPlease log some inventory first.\nHow many items would you like to enter? (1-"<<Max_Count<<") ";
            std::cin>>fillArray;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            while(std::cin.fail() || ((fillArray > Max_Count) || fillArray <= 0)){
                std::cout << "\n  Invalid"<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"\nPlease log some inventory first.\nHow many items would you like to enter? (1-"<<Max_Count<<") ";
                    std::cin>>fillArray;
            }

        for(int x = 0; x < fillArray; x++){//mandate user fill the array so no bugs come out further down the line
            countItem = addItem(item);
        }

        do{
            input = displayChoices();
            switch(input){
                case 'A':
                    if(countItem < Max_Count){
                        countItem = addItem(item);
                    }
                    else{
                        std::cout<<"Max amount of items in inventory: "<<Max_Count<<" items"<<std::endl;
                    }
                        break;
                case 'B':
                    displayAllInventory(countItem, item);
                        break;
                case 'C':
                    checkForSimilarItem(countItem, item);
                        break;
                case 'D':
                    displayLowStock(countItem, item);
                        break;
                case 'E':
                    editCurrentItems(countItem, item);
                        break;
                case 'Q':
                    std::cout<<"Exiting Terminal.... Done! "<<std::endl;
                        break;
                default:
                    std::cout<<"Error..."<<std::endl;
                        break;
            }
        }while(input != 'Q');
    }

    std::cout<<"Would you like all inventory to be printed? (Y/N): ";
        std::cin>>printInventory;
        printInventory = toupper(printInventory);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(std::cin.fail() || (printInventory != 'Y' && printInventory != 'N')) {
        std::cout<<"\nInvalid";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"\nWould you like another receipt? (Y/N) ";
            std::cin>>printInventory;
            printInventory = toupper(printInventory);
    }

    if(printInventory == 'Y') {
        printAllInventory(countItem, item);
    }

    return 0;
}

char displayChoices(){
    char input;

    std::cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<std::endl;

    std::cout<<"Please choose what operation to complete: "<<std::endl;
    std::cout<<"   A) Add an item to inventory"<<std::endl;
    std::cout<<"   B) Display all items in inventory"<<std::endl;
    std::cout<<"   C) Check to see if an item is in inventory"<<std::endl;
    std::cout<<"   D) Display only those items that need to be re-ordered"<<std::endl;
    std::cout<<"   E) Update an item in inventory"<<std::endl;
    std::cout<<"\n   Q) Quit"<<std::endl<<"->";
        std::cin>>input;
        input = toupper(input);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        while(std::cin.fail() || (input != 'A' && input != 'B' && input != 'C' && input != 'D' && input != 'E' && input != 'Q')){
                std::cout << "\n  Invalid"<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Please choose what operation to complete: "<<std::endl;
                std::cout<<"   A) Add an item to inventory"<<std::endl;
                std::cout<<"   B) Display all items in inventory"<<std::endl;
                std::cout<<"   C) Check to see if an item is in inventory"<<std::endl;
                std::cout<<"   D) Display only those items that need to be re-ordered"<<std::endl;
                std::cout<<"   E) Update an item in inventory"<<std::endl;
                std::cout<<"\n   Q) Quit"<<std::endl<<"->";
                    std::cin>>input;
                    input = toupper(input);
        }

    std::cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<std::endl;

    return input;
}

int addItem(Retail_Item item[]){
    static int countItem = 0;
    std::string description;
    short int units = 0;
    double price;
    short int reorder;

    std::cout<<"\nEnter the name or description of item: ";
        getline(std::cin, description);

        item[countItem].setDescription(description);

    std::cout<<"\nHow many units are in stock?: ";
        std::cin>>units;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail() || units <= 0){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nHow many units are in stock?: ";
                std::cin>>units;
        }

        item[countItem].setUnitsOnHand(units);

    std::cout<<"\nWhat is the retail price?: ";
        std::cin>>price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail() || price <= 0){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat is the retail price?: ";
                std::cin>>price;
        }
        
        item[countItem].setPrice(price);

    std::cout<<"\nWhat is the lowest number you want to have in stock before re-stock?: ";
        std::cin>>reorder;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail()){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat is the lowest number you want to have in stock before re-stock?: ";
                std::cin>>reorder;
        }
        
        item[countItem].setReorderQuantity(reorder);

    countItem++;
    return countItem;
}

void displayAllInventory(short int countItem, Retail_Item item[]){
    std::cout<<"All current inventory: "<<std::endl;
    std::cout<<"Description\t\tUnits\t\tCost Per Unit"<<std::endl;

    for(int x = 0; x < countItem; x++){
        std::cout<<"  "<<(x + 1)<<" - "<<item[x].getDescription()<<"\t  "<< item[x].getUnitsOnHand()<<"\t "<< item[x].getPrice()<<std::endl;
    }
}

void checkForSimilarItem(short int countItem, Retail_Item item[]){
    std::string input;
    short int foundItem = -1;//set to -1 because array starts with 0 and can collide with array[0]

    std::cout<<"What are you looking for: ";
        std::cin>>input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        while(std::cin.fail()){//passes numbers/string of numbers through
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"What are you looking for: ";
                std::cin>>input;
        }

    for(int x = 0; x < countItem; x++){
        if(item[x].getDescription() == input){
            std::cout<<"Found it"<<std::endl<<std::endl;
            std::cout<<"Description\tUnits\tCost Per Unit"<<std::endl;
            std::cout<<"  "<<(x + 1)<<" - "<<item[x].getDescription()<<"\t  "<< item[x].getUnitsOnHand()<<"\t "<< item[x].getPrice()<<std::endl;
            foundItem = x;
            break;
        }
    }
    if(foundItem == -1){
        std::cout<<"We could not find that item. Going back to menu."<<std::endl;
    }
}

void displayLowStock(short int countItem, Retail_Item item[]){
    int loop = 0;
    
    for(int x = 0; x < countItem; x++){
        if(item[x].getUnitsOnHand() <= item[x].getReorderQuantity()){
            loop++;
        }
    }

    if(loop > 0){
        std::cout<<"These items need re-stocking: "<<std::endl;
        std::cout<<"  Current Amt    -    Description"<<std::endl;

        for(int x = 0; x < countItem; x++){
            if(item[x].getUnitsOnHand() <= item[x].getReorderQuantity()){
                std::cout<<"       "<<item[x].getUnitsOnHand()<<"         -       "<< item[x].getDescription()<<std::endl;
            }
        }
    }
    else{
        std::cout<<"No items need restocking."<<std::endl;
    }
}

void editCurrentItems(short int countItem, Retail_Item item[]){
    short int editedItem;
    std::string description;
    short int units = 0;
    double price;
    short int reorder;

    std::cout<<"Select the number you want to edit: "<<std::endl;
    for(int x = 0; x < countItem; x++){
        std::cout<<"  "<<(x + 1)<<" - "<<item[x].getDescription()<<std::endl;
    }
    std::cout<<"->";
        std::cin>>editedItem;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //validate - make sure the number <= countItem
        while(std::cin.fail() || (editedItem > countItem)){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"Select the number you want to edit: "<<std::endl;
            for(int x = 0; x < countItem; x++){        
                std::cout<<"  "<<(x+1)<<" - "<<item[x].getDescription()<<std::endl;
                break;
            }
            std::cout<<"->";
                std::cin>>editedItem;
        }

        editedItem = (editedItem - 1);

    std::cout<<"You are currently editing: "<<item[editedItem].getDescription()<<std::endl;

    std::cout<<"\nHow many units are in stock?: ";
        std::cin>>units;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail() || (price <= 0)){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nHow many units are in stock?: ";
                std::cin>>units;
        }

        item[editedItem].setUnitsOnHand(units);

    std::cout<<"\nWhat is the retail price?: ";
        std::cin>>price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail() || (price <= 0)){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat is the retail price?: ";
                std::cin>>price;
        }
        
        item[editedItem].setPrice(price);

    std::cout<<"\nWhat is the lowest number you want to have in stock before re-stock?: ";
        std::cin>>reorder;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while(std::cin.fail() || (price <= 0)){
            std::cout << "\n  Invalid"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat is the lowest number you want to have in stock before re-stock?: ";
                std::cin>>reorder;
        }

        item[editedItem].setReorderQuantity(reorder);
}

void printAllInventory(short int countItem, Retail_Item item[]){
    std::cout<<std::endl<<std::endl;

    for (int x = 0; x < countItem; x++) {
        std::cout<<" - - - - - - - - - - - - - - - - - - "<<std::endl;

        std::cout<<"Item "<<(x + 1)<<":"<<std::endl;
        std::cout<<"Description: "<<item[x].getDescription()<<std::endl;
        std::cout<<"Units on Hand: "<<item[x].getUnitsOnHand()<<std::endl;
        std::cout<<"Price: "<<item[x].getPrice()<<std::endl;
        std::cout<<"Reorder Quantity: "<<item[x].getReorderQuantity()<<std::endl;
    }
    std::cout<<" - - - - - - - - - - - - - - - - - - "<<std::endl;
}