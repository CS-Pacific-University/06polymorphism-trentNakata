#include "Overnight.h"

//***************************************************************************
// Constructor: Overnight
//
// Description: Initializes data members to default values
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************

Overnight::Overnight() : Parcel(), mVolume(0)
{
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

int Overnight::getDeliveryDay() const {
	int deliveryDay = 0;
	int distance = getDistance();
	if (distance <= 1000) {
		deliveryDay = 1;
	}
	else {
		deliveryDay = 2;
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

double Overnight::setInsured() {
	double insurancePrice = 0.25*getCost();
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

double Overnight::setRush() {
	double rushPrice = 0.75*getCost();
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

bool Overnight::read(istream& rcIn) {
	bool bCorrect = false;
	if (Parcel::read(rcIn)) {
		rcIn >> mVolume;
		if (mVolume > 100) {
			setCost(20);
		}
		else {
			setCost(12);
		}
		bCorrect = true;
	}
	return bCorrect;
}

//***************************************************************************
// Function:    print
//
// Description: prints overnight package
//
// Parameters:  rcOut - the location to print
//
// Returned:    none
//***************************************************************************

void Overnight::print(ostream& rcOut) const {
	Parcel::print(rcOut);
	rcOut << "	OVERNIGHT!";
}