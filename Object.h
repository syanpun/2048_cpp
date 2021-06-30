#pragma once

#include<string>

using std::string;

class Object {
private:
	static int count;
	static string objs[10];
public:
	static int getCount();
	static string* getObjs();
	Object(string info);
	virtual ~Object();
};