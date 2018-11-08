#include "stdafx.h"
#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"


//Factory method
		shared_ptr<Shape> Shape::make_shape(int rand)
		{
			switch (rand)
			{
				case 1:
				{
					return make_shared<Circle>();
					break;
				}
				case 2:
				{
					return make_shared<Ellipse>();
					break;
				}
				case 3:
				{
					return make_shared<Helix>();
					break;
				}
			}
		}
