#include "Parcel.h"

//***************************************************************************
// Constructor: Parcel
//
// Description: Initializes data members to default values
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************

Parcel::Parcel() {
	mTrackingId = 0;
	mTo = "null";
	mFrom = "null";
	mWeight = 0;
	mDistance = 0;
	mCost = 0;
	mbInsured = false;
	mbRush = false;
	mbDelivered = false;
}

//***************************************************************************
// Function:    getWeight
//
// Description: Allows weight to be accessed
//
// Parameters:  None
//
// Returned:    The weight of the Parcel
//***************************************************************************

int Parcel::getWeight() const{
	return mWeight;
}

//***************************************************************************
// Function:    getDistance
//
// Description: Allows Distance to be accessed
//
// Parameters:  None
//
// Returned:    The Distance of the Parcel away from destination
//***************************************************************************

int Parcel::getDistance() const {
	return mDistance;
}

//***************************************************************************
// Function:    getInsured
//
// Description: Allows insurance to be accessed
//
// Parameters:  None
//
// Returned:    True - When theres insurance
//***************************************************************************

bool Parcel::getInsured() const {
	return mbInsured;
}

//***************************************************************************
// Function:    getRush
//
// Description: Allows rush to be accessed
//
// Parameters:  None
//
// Returned:    True - When theres rush
//***************************************************************************

bool Parcel::getRush() const {
	return mbRush;
}

//***************************************************************************
// Function:    getTId
//
// Description: Allows tracking id to be accessed
//
// Parameters:  None
//
// Returned:    The tracking id of the Parcel
//***************************************************************************

int Parcel::getTId() const {
	return mTrackingId;
}

//***************************************************************************
// Function:    setCost
//
// Description: Changes the cost
//
// Parameters:  newCost - the new cost of the parcel
//
// Returned:    none
//***************************************************************************

void Parcel::setCost(double newCost) {
	mCost = newCost;
}

//***************************************************************************
// Function:    addInsurance
//
// Description: Set insurance to true
//
// Parameters:  None
//
// Returned:		None
//***************************************************************************

void Parcel::addInsurance() {
	mbInsured = true;
}

//***************************************************************************
// Function:    addRush
//
// Description: Set rush to true
//
// Parameters:  None
//
// Returned:		None
//***************************************************************************

void Parcel::addRush() {
	mbRush = true;
}

//***************************************************************************
// Function:    read
//
// Description: reads the input file
//
// Parameters:  rcIn - the input file to read it
//
// Returned:    true - if read properly
//***************************************************************************

bool Parcel::read(istream& rcIn) {
	rcIn >> mTrackingId >> mTo >> mFrom >> mWeight >> mDistance;
	return true;
}

//***************************************************************************
// Function:    print
//
// Description: prints Parcel
//
// Parameters:  rcOut - the location to print
//
// Returned:    none
//***************************************************************************

void Parcel::print(ostream& rcOut) const{
	rcOut << "TID: " << mTrackingId << "	From: " << mFrom << "	To: " << mTo;
	if (mbInsured) {
		rcOut << "	INSURED";
	}
	if (mbRush) {
		rcOut << "	RUSH";
	}
}

//***************************************************************************
// Function:    getCost
//
// Description: Allows cost to be accessed
//
// Parameters:  None
//
// Returned:    The cost of the Parcel
//***************************************************************************

double Parcel::getCost() const {
	return mCost;
}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: Used as the base function 
//
// Parameters:  None
//
// Returned:    Distance need to travel
//***************************************************************************

int Parcel::getDeliveryDay() const {
	return mDistance;
}

//***************************************************************************
// Function:    setInsured
//
// Description: Used as the base function
//
// Parameters:  None
//
// Returned:    0 - not called
//***************************************************************************

double Parcel::setInsured() {
	return 0;
}

//***************************************************************************
// Function:    setRush
//
// Description: Used as the base function
//
// Parameters:  None
//
// Returned:    0 - not called
//***************************************************************************

double Parcel::setRush() {
	return 0;
}