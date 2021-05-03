#include "Postcard.h"

//***************************************************************************
// Constructor: Postcard
//
// Description: Initializes data members to default values
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************

Postcard::Postcard() : Parcel(), mMessage("Null")
{
	setCost(0.15);
}

//***************************************************************************
// Function:    getDeliveryDay
//
// Description: calculates the delivery day
//
// Parameters:  None
//
// Returned:    The delivery day
//***************************************************************************

int Postcard::getDeliveryDay() const {
	int deliveryDay = 0;
	int distance = getDistance();
	if (distance <= 10) {
		deliveryDay = 1;
	}
	else if (distance % 10 == 0) {
		deliveryDay = distance / 10;
	}
	else {
		deliveryDay = int(distance / 10) + 1;
	}
	return deliveryDay;
}

//***************************************************************************
// Function:    setInsured
//
// Description: Adds the amount of insurance to cost
//
// Parameters:  None
//
// Returned:    The cost of insurance
//***************************************************************************

double Postcard::setInsured() {
	double insurancePrice = 0.15;
	if (!getInsured()) {
		addInsurance();
		setCost(getCost() + insurancePrice);
		return insurancePrice;
	}
	return 0;
}

//***************************************************************************
// Function:    setRush
//
// Description: Adds the amount of rush to cost
//
// Parameters:  None
//
// Returned:    The cost of rush
//***************************************************************************

double Postcard::setRush() {
	double rushPrice = 0.25;
	if (!getRush()) {
		addRush();
		setCost(getCost() + rushPrice);
		return rushPrice;
	}
	return 0;
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

bool Postcard::read(istream& rcIn) {
	bool bCorrect = false;
	if (Parcel::read(rcIn)) {
		rcIn >> mMessage;
		bCorrect = true;
	}
	return bCorrect;
}

//***************************************************************************
// Function:    print
//
// Description: prints postcard
//
// Parameters:  rcOut - the location to print
//
// Returned:    none
//***************************************************************************

void Postcard::print(ostream& rcOut) const {
	Parcel::print(rcOut);
	rcOut << "	" << mMessage;
}