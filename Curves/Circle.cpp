#include "stdafx.h"
#include "Circle.h"


const string& Circle::GetType()
{
	return type;
}

void Circle::GetPointValue(double t, double& x, double& y, double& z) 
{
	x = radius*cos(t);
	Round(x);
	y = radius*sin(t);
	Round(y);
	z = 0.0;

}

void Circle::GetDerivativeValue(double t, double& x, double& y, double& z)
{
	x = -radius*sin(t);
	Round(x);
	y = radius*cos(t);
	Round(y);
	z = 0.0;
}

const vector<int>& Circle::GetParameters()
{
	return params;
}

void Circle::Round(double& parametr)
{
	parametr= round(parametr * 1000) / 1000;
}
