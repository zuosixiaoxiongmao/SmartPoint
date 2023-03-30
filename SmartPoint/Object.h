#pragma once

class ObjectRef {
public:
	inline ObjectRef() :pointer(0) {
		refCount = new int;
		*refCount = 0;
		retain();
	}

	inline ObjectRef(void * p) : pointer(p) {
		refCount = new int;
		*refCount = 0;
		retain();
	}

	inline ObjectRef(const ObjectRef & objRef){
		retain();
		refCount = objRef.refCount;
		pointer = pointer;
	}

	inline ~ObjectRef() {
		release();
	}

	inline const ObjectRef& operator =(const ObjectRef & objRef) const {
		objRef.retain();
		refCount = objRef.refCount;
		pointer = objRef.pointer;
		return *this;
	}

	inline void retain() const {
		++(*refCount);
	}

	inline void release() {
		if (0 == --(*refCount)) {
			delete pointer;
			delete refCount;
			pointer = 0;
			refCount = 0;
		}
	}

	inline void * ref(){
		return pointer;
	}

	inline const void * ref() const {
		return pointer;
	}

private:
	mutable	int * refCount;
	mutable void * pointer;
};

template <class Obj = void>
class Ref {
public:
	typedef Ref Ref;
	inline Object() {
		raw = new Obj();
		objRef = raw;
	}

	inline Ref(Obj * obj) {
		objRef = obj;
		raw = obj;
	}

	inline Ref(const ObjectRef & ref) {
		objRef = ref;
		raw = (Obj*)ref.ref();
	}

	inline Ref(const ObjectRef && ref) {
		objRef = ref;
		raw = ref.ref();
	}

	inline  Obj* operator raw() {
		return (Obj*) (objRef.ref());
	}

	inline const Obj* operator raw() const  {
		return (Obj*) (objRef.ref());
	}

	inline Obj* operator ->() {
		return (Obj*) (objRef.ref());
	}

	inline const Obj* operator ->() const {
		return (Obj*) (objRef.ref());
	}


	inline const Obj & *() const {
		return *((Obj*) (objRef.ref()))
	}

	inline ObjectRef & ref() {
		return objRef;
	}

	inline const ObjectRef & ref() const {
		return objRef;
	}

	inline static ObjectRef create() {
		return ObjectRef(new Obj);
	}

	template<typename...  Parameters>
	inline static ObjectRef create(Parameters ... parameters) {
		return ObjectRef(new Obj(parameters...));
	}

private:
	ObjectRef objRef;
	Obj * raw;
};


template <class Obj = void, int num = 0>
class ArrayRef {
public:

private:
	Obj * obj;
	int len;
};

template <class Obj = void>
class RefLock {
};

template <class Obj = void, int num = 0>
class ArrayRefLock {
public:

private:
	Obj * obj;
	int len;
};

