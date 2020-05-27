#pragma once
#include<iostream>
using namespace std;


class Circle
{
private:

	float radius;
	
	static int count;
	static float square;

	inline bool IsCorrectRadius(float _radius) const
	{
		return _radius >= 0;
	}

public:

	Circle();	

	Circle(float _radius);	

	static int GetCountOfCircles();

	static float GetAmountOfAreas();

	void SetRadius(float _radius);	

	void Print() const;	

	float GetArea() const;
	
	float GetPerimeter() const;

	float GetRadius() const;
	
};

