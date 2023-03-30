#include "Event.h"
#include <stdarg.h>
#include <tuple>
using namespace std;



/*class A {
public:
	int add(int a, int b) {
		return a + b;
	}

	Ref<int> add(Ref<int> a, Ref<int> b) {
		return Ref<int>::create();
	}

	void out() {

	}
};

int* addT(int * a, int * b) {
	int * p = new int(*a + *b);
	return p;
}

typedef void *(*VoidFunc)(...);
void * remoteCall(void * func, void * owner, ...) {
	VoidFunc ft = (VoidFunc)func;
	void * pResutl = 0;
	va_list args;
	va_start(args, owner);
	int * dd1 = va_arg(args, int*);
	int * dd2 = va_arg(args, int*);
	pResutl = ft(dd1, dd2);
	va_end(args);

	return pResutl;
}*/

int main(int argc, char * argv []) {
	int ttta = TImpObj::t;
	ImpObj<char> obj;
	typedef std::tuple <int, double, long &, const char *> test_tuple;
	long lengthy = 12;
	test_tuple proof(18, 6.5, lengthy, "Ciao!");
	lengthy = std::get<0>(proof);

	MemoryStream stream;
	int a = 0;
	int b = 0;;
	int c = 0;
	int d = 0;
	int e = 0;
	unserilize(stream, &a, &b, &c, &d, &e);

	/*void * dd = (void*)(&addT);
	int * pDD = (int *)remoteCall(dd, 0, new int(1), new int(2));


	A a;
	MemoryStream ms;
	Method<A, decltype(&A::add)> method(&a, &A::add);
	method.call(ms);*/

//	int ddd = method(6, 2);
	
	return 0;
}