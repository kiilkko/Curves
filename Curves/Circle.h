#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>
using namespace std;

class Circle :
	public Shape
{
public:
	Circle()
	{
		radius = (1 + rand() % 20);
		params.push_back(radius);
	}
	~Circle()
	{

	}

	const vector<int>& GetParameters() override;
	const string& GetType () override;
	void GetPointValue(double t, double& x, double& y, double& z) override;
	void GetDerivativeValue(double t, double& x, double& y, double& z) override;

protected:
	int radius;
	vector <int> params;
	const string type = "Circle";
	void Round(double& parametr) override;
};

