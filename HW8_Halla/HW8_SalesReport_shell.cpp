// HW8_SalesReport_shell.cpp (shell code. need ADD CODE #1 ~ #3)
// by Bin "Crystal" Peng, CS225
// generate sales report using monthly sales data
// fixed # of sales people; unknown # of sales record


#include <iostream>
#include <fstream> // std::ifstream
#include <string>  // std::string
#include <iomanip> // std::setw(), std::fixed, std::setprecision()

//----------------------------------------------
// global declarations
//----------------------------------------------

const int MAX = 10;   // max # of sales person

struct salesPersonRec
{
  std::string ID;     // salesperson's ID
  double totalSales;  // salesperson's yearly sales amount
};


//----------------------------------------------
// function declarations
//----------------------------------------------

// read id data into array and set totalSales of each record to 0
bool loadID(salesPersonRec list[]/*OUT*/, int listSize/*IN*/);
// Pre: listSize specified
// Post: listSize # of ids read in from file and saved in the ID column in the first listSize records of list. totalSales of those records set to 0

// read in sales data and calculate total sales per person
bool loadData(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains valid ids and totalSales set to 0 for the first listSize records
// Post: sales data read from file
//       totalSales of the first listSize records are set to accumulated sales of the salesperson with the given id

// display menu on screen
void showMenu();
// Pre: none
// Post: menu choices printed on screen

// display id and yearly sales amout of all salespersons by id order
void showReportByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of the id column
//       id and totalSales column of the first listSize records in list are printed on screen

// display id and yearly sales amout of all salespersons by total sales order
void showReportBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of the total sales column
//       id and totalSales column of the first listSize records in list are printed on screen

// sort sales person records by total sales amount
void sortBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of the totalSales column


// ADD CODE #1: two function declarations

void sortByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
void showReport(salesPersonRec list[]/*IN*/, int listSize/*IN*/);
// END ADD CODE #1



//----------------------------------------------

int main()
{
  salesPersonRec salesPersonList[MAX]; // array to hold the salesperson's data
  int numOfSalesPerson = 6;

  if (!loadID(salesPersonList, numOfSalesPerson)) // load id data
    return 1;

  if (!loadData(salesPersonList, numOfSalesPerson)) // load sales data
    return 1;

  // user interaction via menu
  int option = 0; // user option
  do
  {
    // display menu
    showMenu();

    // user option
    std::cin >> option;

    switch (option)
    {
    case 1: // sort and display report by id
      showReportByID(salesPersonList, numOfSalesPerson);
      break;
    case 2: // sort and display report by sales
      showReportBySales(salesPersonList, numOfSalesPerson);
      break;
    case 0: // exit
      std::cout << "\nThank you for using our reporting system!\n";
      break;
    default: // invalid input
      std::cout << "invalid choice. Please try again.\n";
      break;
    }
  } while (option != 0);

} // end main


//----------------------------------------------
// Function Implementation
//----------------------------------------------

// read id data into array and set totalSales of each record to 0
bool loadID(salesPersonRec list[]/*OUT*/, int listSize/*IN*/)
{
  std::ifstream inFile;  // input file
  std::string idfilename = "salesID.txt";

  // open id file
  inFile.open(idfilename);
  if (inFile.fail())
  {
    std::cerr << "Error: can't open input file \"" << idfilename << "\". Abort. \n"; // report to cerr
    return false;                                           // and end now
  }

  // read in id data
  for (int index = 0; index < listSize; index++)
  {
    if (!(inFile >> list[index].ID)) // get salesperson's ID
      return false;  // reading failed

    list[index].totalSales = 0.0;
  }
  inFile.close(); // close file

  return true;
} //end loadID

//----------------------------------------------

// read in sales data and calculate total sales of each person
bool loadData(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  std::ifstream inFile;  // input file
  std::string datafilename = "salesData.txt";

  // open sales data
  inFile.open(datafilename);
  if (inFile.fail())
  {
    std::cerr << "Error: can't open input file \"" << datafilename << "\". Abort. \n"; // report to cerr
    return false;                                           // and end now
  }

  // read in data and process
  std::string id;
  int month;
  double amount;

  // ADD CODE #2:
  // read sales data from file,
  while (inFile >> id >> month >> amount) {
    for (int i = 0; i < listSize; i++)
    {
      if (list[i].ID == id)
      {
        // calculate and update totalSales of each record
        list[i].totalSales += amount;
        break;
      }
    }
  }

  // END ADD CODE #2


  inFile.close(); // close data file

  return true;
} //end loadData

//----------------------------------------------

// display menu on screen
void showMenu()
{
  const std::string menuOptions[] = { "Options:",
    "1. Display sales report by sales id.",
    "2. Display sales report by annual sales amount.",
    "0. Exit",
    "Choose (0 ~ 2): "
  };
  int menuLen = sizeof(menuOptions) / sizeof(std::string);

  std::cout << std::endl;
  for (int i = 0; i < menuLen - 1; i++)
    std::cout << menuOptions[i] << std::endl;
  std::cout << menuOptions[menuLen - 1]; // last item
} // end getUserOption

//----------------------------------------------

void showReportByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  sortByID(list, listSize);
  showReport(list, listSize);
} // end showReportByID

//----------------------------------------------

void showReportBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  sortBySales(list, listSize);
  showReport(list, listSize);
} // end showReportBySales

//----------------------------------------------

void sortBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  // insertion sort
  for (int i = 1; i < listSize; i++)
  {
    // find spot to insert [i]
    salesPersonRec hold = list[i];
    double amount = list[i].totalSales;
    int indexToInsert = i - 1;
    while (indexToInsert >= 0 && amount < list[indexToInsert].totalSales)
    {
      // shift
      list[indexToInsert + 1] = list[indexToInsert];
      indexToInsert--;
    }
    // insert
    list[indexToInsert + 1] = hold;
  }
} // end sortBySales

//----------------------------------------------

// ADD CODE #3: implementation of two functions

void sortByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  for (int i = 0; i < listSize; i++)
  {
    for (int j = 0; j < listSize; j++)
    {
      if (list[i].ID < list[j].ID)
      {
        std::swap(list[i], list[j]);
      }
    }
  }
}

void showReport(salesPersonRec list[]/*IN*/, int listSize/*IN*/) 
{
  std::cout << "---- Annual Sales Report ----" << std::endl << "ID      TotalSales" << std::endl;
  for (int i = 0; i < listSize; i++)
  {
    std::cout << std::left << std::setw(5) << list[i].ID << std::setw(12) << std::right << std::fixed << std::setprecision(2) << list[i].totalSales << std::endl;
  }
  std::cout << "------------------------------" << std::endl;
}

// END ADD CODE #3
