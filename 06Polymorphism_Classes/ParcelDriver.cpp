//****************************************************************************** 
// File name:    ParcelDriver.cpp
// Author:       Trent Nakata
// Date:         5/02/2021
// Class:        CS 250
// Assignment:   Parcel
// Purpose:      Demonstrate the use of Parcels
// Hours worked: 12
//******************************************************************************

#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "Overnight.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void openFileForRead(ifstream& inputFile, string fileName);
void closeFileForRead(ifstream& inputFile);
void createArray(ifstream& inputFile, char postcard, char overnight, 
  char letter, Parcel* array[]);
void printArray(Parcel* array[], ostream& rcOut);
void deleteArray(Parcel* array[]);
void printTitle(string title);
void printChoice(string print, string insurance, string rush, string deliver,
  string quit);
void getChoice();
void addInsurance(Parcel* array[], ostream&);
void addRush(Parcel* array[], ostream&);
void delivery(Parcel* array[], ostream&);
int parcelNum = 0;
string userInput = "0";
bool bChoiceSelect = true;

//******************************************************************************
// Function:    main
//
// Description: Takes user input to affect parcels
//              Print all Parcels
//              Add insurance to Parcel
//              Add rush to Parcel
//              Delivers Parcel with price
//
// Parameters:  none
//
// Returned:    exit status
//******************************************************************************

int main() {

  const char postcard = 'P';
  const char overnight = 'O';
  const char letter = 'L';

  const int MAX_PARCEL = 25;
  const string printAllSelect = "1";
  const string addInsuranceSelect = "2";
  const string addRushSelect = "3";
  const string deliverSelect = "4";
  const string quitSelect = "5";
  const string fileName = "Text.txt";
  const string title = "Mail Simulator!";
  const string print = "Print All";
  const string insurance = "Add Insurance";
  const string rush = "Add Rush";
  const string deliver = "Deliver";
  const string quit = "Quit";

  Parcel* apcParcel[MAX_PARCEL];

  ifstream inputFile;

  cout << fixed << setprecision(2);

  openFileForRead(inputFile, fileName);
  createArray(inputFile, postcard, overnight, letter, apcParcel);
  closeFileForRead(inputFile);

  printTitle(title);

  while (userInput != quitSelect || !bChoiceSelect) {
    printChoice(print, insurance, rush, deliver, quit);
    bChoiceSelect = false;
    getChoice();
    if (userInput == printAllSelect) {
      printArray(apcParcel, cout);
    }
    else if (userInput == addInsuranceSelect) {
      addInsurance(apcParcel, cout);
    }
    else if (userInput == addRushSelect) {
      addRush(apcParcel, cout);
    }
    else if (userInput == deliverSelect) {
      delivery(apcParcel, cout);
    }
    else {
      bChoiceSelect = true;
    }
  }

  
  deleteArray(apcParcel);

  return EXIT_SUCCESS;
}

//***************************************************************************
// Function:    openFileForRead
//
// Description: Opens the file that is asked for
//
// Parameters:  inputFile - open the input file
//              fileName  - the name of the input file
//
// Returned:    None
//***************************************************************************

void openFileForRead(ifstream& inputFile, string fileName) {
  inputFile.open(fileName);
}

//***************************************************************************
// Function:    closeFileForRead
//
// Description: Closes the read file
//
// Parameters:  inputFile - the input file to close
//
// Returned:    None
//***************************************************************************

void closeFileForRead(ifstream& inputFile) {
  inputFile.close();
}

//***************************************************************************
// Function:    createArray
//
// Description: Use the input file and puts all parcels in the array
//
// Parameters:  inputFile - the input file being read
//              postcard  - char to signify the parcel is a postcard
//              overnight - char to signify the parcel is a overnight package
//              letter    - char to signify the parcel is a letter
//              array     - the array to put the parcels in
//
// Returned:    none
//***************************************************************************

void createArray(ifstream& inputFile, char postcard, char overnight, 
  char letter, Parcel* array[]) {
  char packageType;
  while (!inputFile.eof()) {
    inputFile >> packageType;
    if (packageType == postcard) {
      array[parcelNum] = new Postcard;
      array[parcelNum]->read(inputFile);
      parcelNum++;
    }
    else if (packageType == overnight) {
      array[parcelNum] = new Overnight;
      array[parcelNum]->read(inputFile);
      parcelNum++;
    }
    else if (packageType == letter) {
      array[parcelNum] = new Letter;
      array[parcelNum]->read(inputFile);
      parcelNum++;
    }
  }
}

//***************************************************************************
// Function:    printArray
//
// Description: Prints the Parcels 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void printArray(Parcel* array[], ostream& rcOut) {
  rcOut << endl;
  for (int i = 0; i < parcelNum; i++) {
    if (array[i] != NULL) {
      array[i]->print(rcOut);
      rcOut << endl;
    }
  }

}

//***************************************************************************
// Function:    deleteArray
//
// Description: Gets rid of all the pointer in the array
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void deleteArray(Parcel* array[]) {
  for (int i = 0; i < parcelNum; i++) {
    delete array[i];
  }
}

//***************************************************************************
// Function:    printTitle
//
// Description: Prints the title
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void printTitle(string title) {
  cout << title << endl;
}

//***************************************************************************
// Function:    printChoice
//
// Description: Prints the choices that the user can use
//
// Parameters:  print     - print all string
//              insurance - insurance string
//              rush:     - rush string
//              deliver:  - deliver string
//              quit:     - quit string
//
// Returned:    none
//***************************************************************************

void printChoice(string print, string insurance, string rush, 
  string deliver, string quit) {
  cout << endl << "1. " << print << endl;
  cout << "2. " << insurance << endl;
  cout << "3. " << rush << endl;
  cout << "4. " << deliver << endl;
  cout << "5. " << quit << endl << endl;
}

//***************************************************************************
// Function:    getChoice
//
// Description: Gets users input
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void getChoice() {
  cout << "Choice> ";
  cin >> userInput;
}

//***************************************************************************
// Function:    addInsurance
//
// Description: Adds insurance to the parcel with the user inputed TID
//
// Parameters:  array - the array of parcels
//              rcOut - the ostream to print out the insurance
//
// Returned:    none
//***************************************************************************

void addInsurance(Parcel* array[], ostream& rcOut) {
  cout << endl << "TID> ";
  cin >> userInput;
  for (int i = 0; i < parcelNum; i++) {
    if (array[i] != NULL) {
      if (stoi(userInput) == array[i]->getTId()) {
        cout << "Added Insurance for $" << array[i]->setInsured();
        cout << endl;
        array[i]->print(rcOut);
      }
    }
  }
  cout << endl;
}

//***************************************************************************
// Function:    addRush
//
// Description: Adds rush to the parcel with the user inputed TID
//
// Parameters:  array - the array of parcels
//              rcOut - the ostream to print out the rush
//
// Returned:    none
//***************************************************************************

void addRush(Parcel* array[], ostream& rcOut){
  cout << endl << "TID> ";
  cin >> userInput;
  for (int i = 0; i < parcelNum; i++) {
    if (array[i] != NULL) {
      if (stoi(userInput) == array[i]->getTId()) {
        cout << "Added Rush for $" << array[i]->setRush();
        cout << endl;
        array[i]->print(rcOut);
      }
    }
  }
  cout << endl;
}

//***************************************************************************
// Function:    delivery
//
// Description: Adds insurance to the parcel with the user inputed TID
//
// Parameters:  array - the array of parcels
//              rcOut - the ostream to print out the delivery
//
// Returned:    none
//***************************************************************************

void delivery(Parcel* array[], ostream& rcOut) {
  cout << endl << "TID> ";
  cin >> userInput;
  for (int i = 0; i < parcelNum; i++) {
    if (array[i] != NULL) {
      if (stoi(userInput) == array[i]->getTId()) {
        cout << "Delivered!" << endl;
        cout << array[i]->getDeliveryDay() << " Day, $" << array[i]->getCost();
        cout << endl;
        array[i]->print(rcOut);
        delete array[i];
        array[i] = NULL;
      }
    }
  }
  cout << endl;
}