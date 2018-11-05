#pragma once
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	Shape()
	{
		
	}
	~Shape()
	{

	}

	virtual const vector<int>& GetParameters() = 0;
	virtual const string& GetType() = 0;	
	virtual void GetPointValue(double t, double& x, double& y, double& z) = 0;
	virtual void GetDerivativeValue(double t, double& x, double& y, double& z) = 0;
protected:
	virtual void Round(double& parametr) = 0;
};