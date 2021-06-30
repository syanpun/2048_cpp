#include"Object.h"
#include<iostream>
#include<windows.h>


int Object::count = 0;
string Object::objs[10];

int Object::getCount() {
	return count;
}

string* Object::getObjs() {
	return objs;
}

Object::Object(string info) {
	objs[count] = info;
	count++;
	std::cout << "创建了一个 " << info << " 对象, 目前共有 " << count  << " 个对象" << std::endl;
	Sleep(10);
}

Object::~Object() {
	count--;
	std::cout << "释放了一个" << objs[count] << "对象, 目前共有 " << count << " 个对象" << std::endl;
	Sleep(10);
}