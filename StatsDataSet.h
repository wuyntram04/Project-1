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

	int Median() const
	{

	}
};

