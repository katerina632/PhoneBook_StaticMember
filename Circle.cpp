#include "Circle.h"

int Circle::count = 0;
float Circle::square = 0;
const float pi = 3.14;

Circle::Circle()
{
	radius = 0;
	++count;
	square += GetArea();
}

Circle::Circle(float _radius):Circle()
{
	radius = (IsCorrectRadius(_radius) ? _radius : 1);	
	square += GetArea();
}

int Circle::GetCountOfCircles () 
{
	return count;
}

float Circle::GetAmountOfAreas ()
{
	return square;
}

void Circle::SetRadius(float _radius)
{
	radius = (IsCorrectRadius(_radius) ? _radius : 1);
}

void Circle::Print() const {
	
	cout << "Radius of the circle - " << radius << endl;
	cout << "Square of the circle - " << GetArea() << endl;
	cout << "Perimeter of the circle - " << GetPerimeter() << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
}

float Circle::GetArea() const
{	
	return  2 * pi * radius * radius;
}

float Circle::GetPerimeter() const
{
	return 2 * pi * radius;
}

float Circle::GetRadius() const
{
	return radius;
}
