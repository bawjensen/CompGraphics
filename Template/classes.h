#ifndef _CLASSES
#define _CLASSES

#ifdef __APPLE__
	#include <GLUT/glut.h>
#elif __linux
	#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES // Needed to get MATH_PI from cmath
#include <cmath>
#include <iostream>

using namespace std;

class Vec3f;
class Matrix44f; // Forward definition to allow use in Vec3f

class Vec3f {
private:
public:
	float x, y, z, origX, origY, origZ; // Maybe these should be private, but we have global variables, why not public data members
	float xzAngle;

	Vec3f();
	Vec3f(float nX, float nY, float nZ);

	void set(float, float, float);

	Vec3f rotateZ(float);
	// Vec3f rotateXZ(float);
	Vec3f rotateY(float);

	Vec3f& operator*=(Matrix44f);
	Vec3f& operator=(const Vec3f&);
	float operator[](int);

	friend ostream& operator<<(ostream&, Vec3f&);
};

class Matrix44f {
private:
public:
	float matrix[4][4];

	Matrix44f();
	Matrix44f(float array[4][4]);

	Matrix44f& operator*=(Matrix44f);
	Matrix44f& operator=(const Matrix44f&);

	friend ostream& operator<<(ostream&, Matrix44f&);
};

class Camera {
private:
public:
	Vec3f pos, origPos, focus, viewDir, pOrigin, xzAxis;
	bool isFocusing, panActive;
	float horizAngle, vertAngle, deltaHorizAngle, deltaVertAngle, angularScrollSpeed;

	Camera();

	void setPos(float, float, float);
	void setViewDir(float, float, float);
	void setFocus(float, float, float);

	void rotateTo(float, float);
	void rotate(float, float);
	void handleClick(int, int, int, int);
	void handleMovement(int, int);
};

#endif