#include<string>
#include <Windows.h>

#include "Object.h"
#include "Event.h"

using namespace std;

class A {
public:
	int a;
};

class B {
public:
	int b;
	B(int b) {
		this->b = b;
	}
};

class Action {
public:
	void onMove(Ref<int> x, Ref<int> y) {

	}
};

int main(int argc, char * argv []) {
	Ref<B> objB = Ref<B>::create(1);
	Ref<A> objA0 = Ref<A>::create();
	Ref<A> objA = new A();
	(Ref<A>)(objA.ref());
	objA->a = 0;
	
	Ref<A> objA1 = objA.ref();
	Ref<A>(objA.ref())->a;

	auto action = Ref<Action>::create();

	EventDispacth dispacher;
	dispacher.addListenner(Ref<int>::create(1), action, &Action::onMove);

	dispacher.dispacthEvent(Ref<int>::create(1), Ref<int>::create(100), Ref<int>::create(200));

	
	return 0;
}