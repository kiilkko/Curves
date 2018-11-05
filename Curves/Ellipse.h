#pragma once
#include "Shape.h"
class Ellipse :
	public Shape
{
public:
	Ellipse()
	{
		radiusA = (1 + rand() % 20);
		radiusB = (1 + rand() % 20)-1;
		params.push_back(radiusA);
		params.push_back(radiusB);
	}
	~Ellipse()
	{

	}

	const vector<int>& GetParameters() override;
	const string& GetType () override;
	void GetPointValue(double t, double& x, double& y, double& z) override;
	void GetDerivativeValue(double t, double& x, double& y, double& z) override;

protected:
	int radiusA;
	int radiusB;
	vector <int> params;
	const string type = "Ellipse";
	void Round(double& parametr) override;
};

