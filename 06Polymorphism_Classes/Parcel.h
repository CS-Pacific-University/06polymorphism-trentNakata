#pragma once
#include <string>
#include <iostream>

using namespace std;

class Parcel {

	public:
		Parcel();

		int getWeight() const;
		int getDistance() const;
		bool getInsured() const;
		bool getRush() const;
		int getTId() const;

		void setCost(double);
		void addInsurance();
		void addRush();

		virtual double setInsured();
		virtual double setRush();

		virtual bool read(istream &rcIn);
		virtual void print(ostream &rcOut) const;

		double getCost() const;
		virtual int getDeliveryDay() const;

	private:
		int mTrackingId;
		string mTo;
		string mFrom;

		int mWeight;
		int mDistance;

		double mCost;

		bool mbInsured;
		bool mbRush;
		bool mbDelivered;
};