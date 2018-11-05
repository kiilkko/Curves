// Curves.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "stdafx.h"
#include "Helix.h"
#include <time.h>
using namespace std;

int main()
{
	double x = 0;
	double y = 0;
	double z = 0;
	double t = 0;
	string type = "";
	int sum = 0;
	int randomShape = 0;
	bool ContainerIsChecked = true;
	vector<shared_ptr<Shape>> FirstContainer = {};
	vector<shared_ptr<Shape>> SecondContainer = {};
	srand(time(0));	
	
	//Íàïîëíåíèå ïåðâîãî êîíòåéíåðà	
	for (int i=0;i<5;++i)
	{
		//ñëó÷àéíûì îáðàçîì âûáèðàåì òèï êðèâîé
		randomShape = 1 + rand() % 3;
		switch (randomShape)
		{
		case 1:
		{ //äåëàåì ïðîâåðêó ïîääåðæêè òèïà êðèâîé êîíòåéíåðîì ïðè çàïîëíåíèè
			try
			{
				FirstContainer.push_back(make_shared<Circle>());
			}
			catch (const std::exception&)
			{
				cout << "Invalid type: Circle!" << endl;
			}
			break;
		}
		case 2: 
		{
			try
			{
				FirstContainer.push_back(make_shared<Ellipse>());
			}
			catch (const std::exception&)
			{
				cout << "Invalid type: Ellipse!" << endl;
			}
			break;
		}
		case 3: 
		{
			try
			{
				FirstContainer.push_back(make_shared<Helix>());
			}
			catch (const std::exception&)
			{
				cout << "Invalid type: Helix!" << endl;
			}
			break;
		}
		}
	}
	
	//Âûâîä òî÷åê äëÿ t=PI/4, t ââîäèòñÿ â ðàäèàíàõ, t=0.785 ðàä
	for (auto n : FirstContainer)
	{
		t = 0.785;
		n->GetPointValue(t, x, y, z);
		type = n->GetType();
		cout << type << ":" << endl;
		cout <<  "Coordinates of point:" << endl;
		cout << "x= " << x << endl;
		cout << "y= " << y << endl;
		cout << "z= " << z << endl;

		n->GetDerivativeValue(0.785, x, y, z);
		cout << "Coordinates of tangent vector:" << endl;
		cout << "x= " << x << endl;
		cout << "y= " << y << endl;
		cout << "z= " << z << endl;
	}

	//íàïîëíåíèå âòîðîãî êîíòåéíåðà
	copy_if(FirstContainer.begin(), FirstContainer.end(), back_inserter(SecondContainer), [](auto n)
	{
		string st = n->GetType();
		return st == "Circle";
	});
	cout <<"Size of second container: " << SecondContainer.size()<<endl;

	//ïðîâåðèì àäðåñ, íà êîòîðûé óêàçûâàþò â ïàìÿòè óêàçàòåëè â ïåðâîì è âòîðîì êîíòåéíåðå (äîëæíû óêàçûâàòü íà îäèí îáúåêò)
	//åñëè äâà óêàçàòåëÿ óêàçûâàþò íà îäèí îáúåêò, âûâåäåì åãî òèï è àäðåñ
	for (auto i : SecondContainer)
	{
		for (auto n : FirstContainer)
		{
			if (!i.owner_before(n)==!n.owner_before(i))
			{
				cout << "type "<< (*i).GetType() << ", address = " << i << endl;
			};
		}
	}	
	
	//Ñîðòèðîâêà âòîðîãî êîíòåéíåðà ïî ðàäèóñó
	struct CompareSh
	{
		bool operator()(shared_ptr<Shape> A, shared_ptr<Shape> B)
		{
			int a = A->GetParameters()[0];
			int b = B->GetParameters()[0];
			return a < b;
		}
	};
	if (SecondContainer.size() > 0)
	{
		sort(SecondContainer.begin(), SecondContainer.end(), CompareSh());
		cout << "Sort result: circles radius in ascending order: " << endl;
		for (auto n : SecondContainer)
		{
			cout << n->GetParameters()[0] << " ";
		}
		cout<< endl;


		//Ïîäñ÷åò ðàäèóñîâ âî âòîðîì êîíòåéíåðå
		vector<shared_ptr<Shape>>::iterator iter = SecondContainer.begin();
		while (iter != SecondContainer.end())
		{
			sum += (*iter)->GetParameters()[0];
			iter++;
		}
		cout << "Sum of all radii in second container is " << sum << endl;

	}
	else
	{
		cout << "Container is empty (no circles in firstcontainer)" << endl;
	}
	
	system("pause");
    return 0;
}
