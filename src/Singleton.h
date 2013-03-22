#ifndef SINGLETON_H
#define SINGLETON_H

/**
 * Guarantees that only a single instance of an object will exist
 * throughout the lifetime of the program.
 */
template <class Derived>
class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Derived& instance()
	{
		if (instance_ == nullptr)
			instance_ = new Derived();
		return *instance_;
	}
protected:
	Singleton() {}
	static Derived* instance_;
};

template <class Derived>
Derived* Singleton<Derived>::instance_ = nullptr;

#endif
