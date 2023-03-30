#pragma once

#include <stdio.h>
#include <string>
#include <vector>

#include <map>
#include <string>

//#include "Object.h"

using namespace std;


class Object {

};

class MemoryStream {

};

void unserilize(MemoryStream & stream, string * obj) {

}

void unserilize(MemoryStream & stream, int * obj) {
	++(*obj);
}

void unserilize(MemoryStream & stream, Object * obj) {

}

void unserilize(MemoryStream & stream, const char * obj) {

}

template<typename T, typename...  Parameters>
void unserilize(MemoryStream & stream, T * t, Parameters ... parameters) {
	unserilize(stream, t);
	unserilize(stream, parameters...);
}

template<typename T, class=int>
struct ImpObj {
	static T Value;
};

template<int>
struct ImpObj {
	static int Value = 0;
};

class Method {
public:
	virtual void call(MemoryStream & stream) = 0;
};

template<typename T, typename...  Parameters>
class Caller : public Method {
public:
	virtual void call(MemoryStream & stream) {
	}

};

class NotifyCenter {
public:
	void regedit(string strName, Method* pMethod) {
		_methodMap[strName] = pMethod;
	}

	void call(MemoryStream stream, string name) {
		_methodMap[name]->call(stream);
	}
private:
	map<string, Method*> _methodMap;
};