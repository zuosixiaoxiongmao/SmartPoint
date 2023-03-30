#pragma once

#include <stdio.h>
#include <string>
#include <vector>

//#include <map>

//#include "Object.h"

using namespace std;

template<int id = -1>
void out(int ittd) {
	printf("%d\n", id);
}



template<int id>
class Function {
public:
	template<typename Func>
	class Define {
	public:
		typedef Func Func;
	};
	template<typename Func>
	class Caller {
	public:
		typedef Func Func;

		template<typename Owner, typename...  Parameters>
		auto operator ()(Owner owner, Func _pFunc, Parameters ... parameters) -> decltype((owner->*_pFunc)(parameters...)) {
			return (owner->*_pFunc)(parameters...);
		}
	};
public:
	
};

class Object {

};

class MemoryStream {

};

template<typename Owner, typename Func>
class Method;

class MethodBase {
public:
	virtual Object call(MemoryStream params) = 0;
};

template<typename Owner, typename Func>
class Method : public Caller{
public:
	Method(Owner * owner, Func func) {
		_pOwner = owner;
		_pFunc = func;
	}

	virtual Object call(MemoryStream ms) {
		vector<Object> params;
		Object param = call(params)
	}

	template<typename...  Parameters>
	auto operator()(Parameters ... parameters) -> decltype((_pOwner->*_pFunc)(parameters...)) {
		return (_pOwner->*_pFunc)(parameters...);
	}

private:
	virtual Object call(vector<Object> params) {
		switch (params.size())
		{
		case 0:return _call();
		case 1:return _call(params[0]);
		case 2:return _call(params[0], params[1]);
		case 3:return _call(params[0], params[1], params[2]);
		case 4:_call(params[0]); break;
		case 5:_call(params[0]); break;
		case 6:_call(params[0]); break;
		case 7:_call(params[0]); break;
		case 8:_call(params[0]); break;
		case 9:_call(params[0]); break;
		case 10:_call(params[0]); break;
		case 11:_call(params[0]); break;
		case 12:_call(params[0]); break;
		case 13:_call(params[0]); break;
		case 14:_call(params[0]); break;
		case 15:_call(params[0]); break;
		case 16:_call(params[0]); break;
		case 17:_call(params[0]); break;
		case 18:_call(params[0]); break;
		case 19:_call(params[0]); break;
		case 20:_call(params[0]); break;
		case 21:_call(params[0]); break;
		case 22:_call(params[0]); break;
		case 23:_call(params[0]); break;
		case 24:_call(params[0]); break;
		case 25:_call(params[0]); break;
		default:
			break;
		}
	}

private:
	template<typename...  Parameters>
	virtual Object _call( Parameters ... parameters) {
		return (_pOwner->*_pFunc)(parameters...);
	}

private:
	Owner * _pOwner;
	Func  _pFunc;
};



class Eventor {
	template<typename id,class Owner, typename Func>
	int registor(Func func) {
		Function<id, Func> tFunc
		return 0
	}

	template<int a, class Owner, typename Func>
	int call(int id) {

	}
};

class Event {

};

/*class Eventer {
public:
	virtual int notify(Event event, ArrayRef<> params) {

	}
};

class EventDispacth {
public:
	template<typename EventOwer, typename CallBack>
	int addListenner(Ref<int> event, EventOwer ower, CallBack callBack) {
		Ref<> eOwner = Ref<>::creaet(dynamic_cast<void*>(ower.raw()));
		_iEventMap[*even] = Eventer{ eventNo , Ref<CallBack>::create(callBack) };
	}

	template<typename ... Params>
	int dispacthEvent(Ref<int> event, Params ... params) {
		Eventer & eventer = _iEventMap[*event];
		eventer.eventNo
	}
private:
	map<int, Eventer> _iEventMap;
};*/
