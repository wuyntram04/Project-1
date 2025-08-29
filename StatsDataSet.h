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

	double Mean() const
	{
		return (Sum() / getSize()) * 1.0;
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

double StandDeviation() const
{
	double ssdevia = 0.00;
	const  int* a = data();
	for (int i = 0; i < getSize(); i++)
	{
		double devia = a[i] - Mean();

		ssdevia += devia * devia;
	}

	bool sample = (getType() == "Sample");

	double denominator;
	if (sample)
	{
		if (getSize() < 2) return 0.0;
		else 
		denominator = getSize() - 1;
	}
	else
	{
		denominator = getSize()*1.0;
	}

	double variable = sqrt(double(ssdevia / denominator));

	return variable;

}
double Variance() const
{
	return StandDeviation()*StandDeviation();
}

double MidRange() const
{
	return (Maximum() - Minimum()) / 2;
}
double medianInRange(int lo, int hi) const
	{
		int len = hi - lo;
		if (len <= 0) return 0.0;

		const int* a = data(); 

		if (len % 2 == 1)
		{
			int mid = lo + (len / 2);
			return a[mid];
		}
		else
		{
			int right = lo + (len / 2);
			int left = right - 1;
			return (a[left] + a[right]) / 2.0;
		}
	}
	double Q1() const
	{
		int n = getSize();

		if (n == 0) return 0;

		int mid = n / 2;

		if (n % 2 == 1)
		{
			// odd: lower = [0, mid)
			return medianInRange(0, mid);
		}
		else
		{
			// even: lower = [0, mid)
			return medianInRange(0, mid);
		}
	}

	double Q3() const
	{
		int n = getSize();
		if (n == 0) return 0.0;

		int mid = n / 2;

		if (n % 2 == 1)
		{
			// odd: upper = (mid, n) => [mid+1, n)
			return medianInRange(mid + 1, n);
		}
		else
		{
			// even: upper = [mid, n)
			return medianInRange(mid, n);
		}
	}

	double IQR() const
	{
		return Q3() - Q1();
	}

	void Outliners( int *&outArr, int &outCount , double & lower, double &upper) 
	{
		outArr = nullptr;
		outCount = 0;
		lower = 0.0;
		upper = 0.0;

		int n = getSize();

		if (n == 0) return;

		lower = Q1() - 1.5 * IQR();
		upper = Q3() + 1.5 * IQR();

		const int* a = data();

		int cntSmall = 0, cntLarge = 0;
		for (int i = 0; i < n; ++i) 
		{
			int x = a[i];
			if (x < lower) 
			{
				cntSmall++;
			}
			else
			{
				if (x > upper) 
				{
					cntLarge++; 
				}
			}
		}

		int total = cntSmall + cntLarge;
		if (total == 0) return;

		outArr = new int[total];
		outCount = total;

		int k = 0;
		for (int i = 0; i < n; ++i)
		{
			int x = a[i];
			if (x < lower)
			{
				outArr[k++] = x;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			int x = a[i];
			if (x > upper)
			{
				outArr[k++] = x;
			}
		}
	}
void Mode() const
{
	int n = getSize();
	const int* arr = data();

	int maxCount = 1;
	int currentCount = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i < n && arr[i] == arr[i - 1])
		{
			currentCount++;
		}
		else if(currentCount > maxCount)
		{
			maxCount = currentCount;
			currentCount = 1;
		}
	}

	cout << "\n\tMode(s) = \t";
	currentCount = 1;
	for (int i = 1; i <= n; i++) 
	{
		if (i < n && arr[i] == arr[i - 1]) 
		{
			currentCount++;
		}
		else 
		{
			if (currentCount == maxCount) 
			{
				
				cout << arr[i - 1]<<" ";
			}
			currentCount = 1;
		}
	}
}

double SumOfSquare() const
{
	const int* arr = data();

	double ss = 0;
	double m = Mean();
	for (int i = 0; i < getSize(); i++)
	{
		double square = pow((arr[i] - m), 2) * 1.0;
		ss += square *1.0;
	}
	return ss;
}

double MeanAbsoluteDeviation() const
{
	const int* arr = data();
	double m = Mean();
	int n = getSize();
	double numerator = 0;

	for (int i = 0; i < n; i++)
	{
		numerator += abs(arr[i] - m);
	}
	return numerator / (n*1.0);
}

double RootMeanSquare() const
{
	const int* arr = data();
	int n = getSize();
	double sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += pow(arr[i], 2);
		
	}
	return sqrt(sum / (n * 1.0));
}

double StandardError() const
{
	int n = getSize();

	return StandDeviation() / sqrt((n * 1.0));
}




double Skewness() const
{
	int n = getSize();
	if (n == 0) return 0.0;

	const int* arr = data();
	double mean = Mean();
	double stdev = StandDeviation();
	//if (stdev == 0.0) return 0.0;

	double sumCubed = 0.0;
	for (int i = 0; i < n; i++)
	{
		double cubed = pow((arr[i] - mean)/stdev, 3);
		sumCubed += cubed;
	}

	if (sample())
	{
		if (n < 3) return 0.0;
		double factor = (n * 1.0) / ((n - 1.0) * (n - 2.0));
		return factor * sumCubed;
	}
	else
	{
		return sumCubed / (n * pow(stdev, 3));
	}
}

double Kurtosis() const
{
	int n = getSize();
	if (n < 4) return 0.0; // need at least 4 values for sample formula

	const int* arr = data();
	double mean = Mean();
	double stdev = StandDeviation();
	if (stdev == 0.0) return 0.0;

	double sumFourth = 0.0;
	for (int i = 0; i < n; i++)
	{
		double diff = arr[i] - mean;
		sumFourth += pow(diff, 4);
	}

	if (sample())
	{
		// Sample kurtosis using your exact formula
		double factor = (n * (n + 1.0)) / ((n - 1.0) * (n - 2.0) * (n - 3.0));
		return factor * (sumFourth / pow(stdev, 4));
	}
	else
	{
		// Population kurtosis
		return sumFourth / (n * pow(stdev, 4));
	}

	
}

double KurtosisExcess() const
{
	int n = getSize();
	if (n < 4) return 0.0;

	const int* arr = data();
	double mean = Mean();
	double stdev = StandDeviation();
	if (stdev == 0.0) return 0.0;

	double sumFourth = 0.0;
	for (int i = 0; i < n; i++)
	{
		double diff = arr[i] - mean;
		sumFourth += pow(diff, 4);
	}

	
	if (sample())
	{
		double term1 = (n * (n + 1.0)) / ((n - 1.0) * (n - 2.0) * (n - 3.0)) * (sumFourth / pow(stdev, 4));
		double term2 = (3.0 * (n - 1.0) * (n - 1.0)) / ((n - 2.0) * (n - 3.0));
		return (term1 - term2);
	}
	else
	{
		return (sumFourth / (n * pow(stdev, 4))) - 3.0;
	}

}

double CoefficientOfVariation() const
{
	return StandDeviation() / Mean();
}

double RelativeSD() const
{
	return CoefficientOfVariation() * 100.0;
}

void FrequencyTable() const
{
	int n = getSize();
	const int* arr = data();

	cout << left << setw(10) << "Value"
		<< setw(12) << "Frequency"
		<< setw(12) << "Frequency %" << endl;

	int i = 0;
	while (i < n)
	{
		int value = arr[i];
		int count = 1;

		while (i + count < n && arr[i + count] == value)
		{
			count++;
		}

		double percent = (count * 100.0) / n;


		cout << left << setw(10) << value
			<< setw(12) << count
			<< setw(12) << percent << endl;

		i += count;

	}


}
};










