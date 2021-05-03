#pragma once

#include "Parcel.h"

class Postcard : public Parcel {
	public:
		Postcard();

		virtual int getDeliveryDay() const override;

		virtual double setInsured() override;
		virtual double setRush() override;

		virtual bool read(istream&) override;
		virtual void print(ostream&) const override;

	private:
		string mMessage;
};