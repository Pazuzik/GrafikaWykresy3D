//Extremely simple vector and matrix classes by Janusz Malinowski. 
#include <stdio.h>
#pragma once
class Vector4
{
public:
	double data[4];
	Vector4();
	void Print(void);
	void Set(double d1, double d2, double d3);
	double GetX();
	double GetY();
	double GetZ();
	Vector4 operator-(const Vector4&);
	friend Vector4 operator*(const Vector4&, double);
};

class Matrix4
{
public:
	double data[4][4];
	Matrix4();
	void Print(void);
	Matrix4 operator*(const Matrix4);
	friend Vector4 operator*(const Matrix4, const Vector4);
};

struct Point {
	float x, y, z;
	Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};


struct Segment {
	Point begin, end;
	Segment(Point _begin, Point _end) : begin(_begin), end(_end) {}
};


////////////////////////////////////////////////////////////////


class Vector
{
public:
	double data[3];
	Vector();
	void Print(void);
	void Set(double d1, double d2);
	double GetX();
	double GetY();
};

class Matrix
{
public:
	double data[3][3];
	Matrix();
	void Print(void);
	Matrix operator*(const Matrix);
	friend Vector operator*(const Matrix, const Vector);
};


