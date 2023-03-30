#pragma once
#include <string>
#include <map>

using namespace std;
typedef char byte;
typedef int Int;

class UIDGenerater {
public:
	static int getUid() {
		static int uid = 0;
		return uid++;
	}
};

class String{

};
class Postion {

};

enum PropertyScore
{
	NONE,
	BASE,
	CELL,
	CLIENT,
	BASE_AND_CELL,
	BASE_AND_CELL_AND_CLIENT,
	BASE_AND_CLIENT,
	CELL_AND_CLIENT
};

class Entity {
public:
	template <class TProperty>
	void syncProperty(PropertyScore score, int uid, TProperty property){
	//	property.serilize();
	}

	typedef void(*SetCall)(byte*, int);
	void onSetProterty(int uid, byte * data, int len) {
		 setMap[uid](data, len);
	}

private:
	map<int, SetCall> setMap;
};

template <int UID, class Prototype, PropertyScore SCORE = NONE >
class Property {
public:
	Property(Entity * pEntity, int score, Prototype ptype) {

	}

	Property(Entity * pEntity, int score) {

	}

	Property(Entity * pEntity) {

	}

	Prototype & operator ->() {
		return *this;
	}
	const Prototype & operator ->() const {
		return *this;
	}
	void operator =(Prototype v) {
		_value = v;
		_pEntity->syncProperty(_score, _uid, this);
	}
private:
	void _init() {
		_uid = _pEntity->getUid();
	}
private:
	int _uid = UID;
	PropertyScore _score;
	Prototype _value;
	const char * _name;
	Entity * _pEntity;
};

#define DEF_PROPERTY( name, type, proto, value) \
	

class Player : public Entity {
public:
	Player() :name(this),
		hp(this),
		pos(this) {

	}

	void serilize(byte * data, int len) {

	}

	Property<0, String, BASE_AND_CELL_AND_CLIENT>		name	=	{ this };
	Property<1, Int, BASE_AND_CELL_AND_CLIENT>			hp		=	{ this };
	Property<3, Postion, BASE_AND_CELL_AND_CLIENT>		pos;
	Property<4,	String> desc = { this,  BASE_AND_CELL_AND_CLIENT };

};

void test() {

	Player player;
	player.hp = 1;
}