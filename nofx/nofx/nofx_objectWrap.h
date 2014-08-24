#ifndef _NOFX_OBJECT_WRAP_H_
#define _NOFX_OBJECT_WRAP_H_

// Forward declaring node's original objectWrap
// At this point we don't need to know its implementation
// Derived classes will know it.

namespace node {
	class ObjectWrap;
}



// Forward declaring std shared_ptr
// At this point we don't need to know its implementation
// Derived classes will know it.

namespace std {
	template<class T> class shared_ptr;
}



// An interface for nofx wrapped objects
// Mostly will be used for OF internal data types

namespace nofx
{
	template<class T>
	class ObjectWrap : public node::ObjectWrap
	{
	public:
		virtual T* GetWrapped() const = 0;
		virtual void SetWrapped(T* n) = 0;
		virtual void SetWrapped(T& n) = 0;
	};
}



// A handy macro for declaration of common
// methods and members of nofx::ObjectWrap
// Note that this can't be implemented directly
// into nofx::ObjectWrap since it has private
// constructors and static methods which
// cannot be virtual.

#define DeclareObjectRoutinesLong(WrapperClassName, WrappedTypeName) \
public: \
	static void Initialize(v8::Handle<v8::Object> target); \
	static const v8::Persistent<v8::Function>& Factory() { return constructor; } \
	WrappedTypeName* GetWrapped() const { return internal_.get(); }; \
	void SetWrapped(WrappedTypeName* n)  { internal_.reset(n); }; \
	void SetWrapped(WrappedTypeName& n)  { internal_.reset(new WrappedTypeName(n)); }; \
	void SetWrapped(const WrappedTypeName& n)  { internal_.reset(new WrappedTypeName(n)); }; \
\
private: \
	~WrapperClassName() {}; \
	WrapperClassName() : internal_(new WrappedTypeName()) {}; \
	WrapperClassName(WrappedTypeName* aInternal) : internal_(aInternal) {}; \
	std::shared_ptr<WrappedTypeName> internal_; \
	static v8::Persistent<v8::Function> constructor; \
	static NAN_METHOD(New);


// Same as DeclareObjectRoutinesLong macro (but for lazy people)
// supply names by removing "of" from the beginning
// of your class name (and Wrap from the end), e.g:
// OfVec3fWrap --> Vec3f
// ofVec3f     --> Vec3f

#define DeclareObjectRoutines(name) \
	DeclareObjectRoutinesLong(Of##name##Wrap, of##name)

#endif