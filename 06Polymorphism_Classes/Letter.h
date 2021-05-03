#pragma once

#include "Parcel.h"

class Letter : public Parcel {
	public:
		Letter();
		
		virtual int getDeliveryDay() const override;

		virtual double setInsured() override;
		virtual double setRush() override;

		virtual bool read(istream &rcIn) override;
};