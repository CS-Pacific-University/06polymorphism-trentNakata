#include "Letter.h"

//***************************************************************************
// Constructor: Letter
//
// Description: Initializes data members to default values
//
// Parameters:	None
//
// Returned:		None
//***************************************************************************

Letter::Letter() : Parcel() 
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

int Letter::getDeliveryDay() const {
	int deliveryDay = 0;
	int distance = getDistance();
	if (distance <= 100) {
		deliveryDay = 1;
	}
	else if (distance % 100 == 0){
		deliveryDay = distance / 100;
	}
	else {
		deliveryDay = int(distance / 100) + 1;
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

double Letter::setInsured() {
	double insurancePrice = 0.45;
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

double Letter::setRush() {
	double rushPrice = getCost() * 0.1;
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

bool Letter::read(istream& rcIn) {
	bool check = Parcel::read(rcIn);
	setCost(0.45 * getWeight());
	return check;
}