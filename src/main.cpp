#include <iostream>

#include "ResourceManager.h"

using namespace std;

int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(int argc, char* argv[])
{
	ResourceManager& manager = ResourceManager::instance();
	manager.set_resource_limit(ResourceLimit(RLIMIT_CPU, 3, 3));
	manager.set_resource_limit(ResourceLimit(RLIMIT_RTTIME, 3, 3));
	manager.apply_limits();

	fib(31);

	ResourceUsage usage = manager.get_resource_usage(RUSAGE_SELF);

	cout << "User Time (sec): " << usage.utime().seconds << endl;
	cout << "User Time (usec): " << usage.utime().microseconds << endl;
	cout << "System Time (sec): " << usage.stime().seconds << endl;
	cout << "System Time (usec): " << usage.stime().microseconds << endl;

	return 0;
}
