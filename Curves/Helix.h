#pragma once
#include "Shape.h"
class Helix :
	public Shape
{
public:
	Helix()
	{
		radius = (1 + rand() % 20);
		step = (1 + rand() % 20);
		params.push_back(radius);
		params.push_back(step);
	}
	~Helix()
	{

	}

	const vector<int>& GetParameters() override;
	const string& GetType() override;
	void GetPointValue(double t, double& x, double& y, double& z) override;
	void GetDerivativeValue(double t, double& x, double& y, double& z) override;

protected:
	int radius;
	int step;
	vector <int> params;
	const string type = "Helix";
	void Round(double& parametr) override;
};
