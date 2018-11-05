#include "stdafx.h"
#include "Ellipse.h"


const string& Ellipse::GetType() 
{
	return type;
}

void Ellipse::GetPointValue(double t, double & x, double & y, double & z)
{
	x = radiusA*cos(t);
	Round(x);
	y = radiusB*sin(t);
	Round(y);
	z = 0.0;
}

void Ellipse::GetDerivativeValue(double t, double & x, double & y, double & z)
{
	x = -radiusA*sin(t);
	Round(x);
	y = radiusB*cos(t);
	Round(y);
	z = 0.0;
}

const vector<int>& Ellipse::GetParameters()
{
	return params;
}

void Ellipse::Round(double& parametr)
{
	parametr = round(parametr * 1000) / 1000;
}