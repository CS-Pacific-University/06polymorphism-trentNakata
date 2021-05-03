#pragma once

#include "Parcel.h"

class Overnight : public Parcel {
	public:
		Overnight();

		int getDeliveryDay() const;

		virtual double setInsured() override;
		virtual double setRush() override;

		virtual bool read(istream&) override;
		virtual void print(ostream&) const override;

	private:
		int mVolume;
};