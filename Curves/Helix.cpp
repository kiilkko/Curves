#include "stdafx.h"
#include "Helix.h"

const string& Helix::GetType()
{
	return type;
}

void Helix::GetPointValue(double t, double & x, double & y, double & z)
{
	x = radius*cos(t);
	Round(x);
	y = radius*sin(t);
	Round(y);
	z = (step/6.28)*t;
	Round(z);
}

void Helix::GetDerivativeValue(double t, double & x, double & y, double & z)
{
	x = -radius*sin(t);
	Round(x);
	y = radius*cos(t);
	Round(y);
	z = step / 6.28;
	Round(z);
}

const vector<int>& Helix::GetParameters()
{
	return params;
}

void Helix::Round(double& parametr)
{
	parametr = round(parametr * 1000) / 1000;
}