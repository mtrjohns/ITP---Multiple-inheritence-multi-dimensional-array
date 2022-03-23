#pragma once
/********************************
**** Pattern Object Header File *
********************************/

class Pattern
{
protected:
	float t = 0.0f;
	int debug = 0;

public:
	Pattern();
	Pattern(float);
	virtual ~Pattern();

	void setT(float);
	float getT();
	void setDebug(int);
	int getDebug();

	virtual void print(int) = 0;
};