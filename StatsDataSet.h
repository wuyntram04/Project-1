#pragma once

#include "Dataset.h"
#include <cmath>
#include <algorithm>
#include <fstream>
#include <memory>

using namespace std;

class StatsDataSet : public Dataset
{
	using Dataset::Dataset;  // inherit constructors from Dataset

public:
	int Minimum() const
	{	
		return data()[0];
	}

	int Maximum() const
	{
		return data()[getSize()-1];
	}

	int Range() const
	{
		return Maximum() - Minimum();
	}

	int Sum() const
	{
		int sum = 0;
		for (int i = 0; i < getSize(); i++)
		{
			sum += data()[i];
		}
		return sum;
	}

	int Mean() const
	{
		return Sum() / getSize();
	}

	double Median() const
{
	int n = getSize();

	if (n % 2 == 1)
	{
		int p = (n + 1) / 2.0;
		return data()[p - 1];
	}
	else
	{
		int p = n / 2;
		int left = data()[p - 1];
		int right = data()[p];
		return (left + right) / 2.0;
	}
}
};


