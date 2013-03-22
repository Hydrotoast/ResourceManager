#ifndef RESOURCEUSAGE_H
#define RESOURCEUSAGE_H

#include "sys/resource.h"
#include "sys/time.h"

/**
 * An alternative representation of timevals
 */
class TimeParts
{
public:
	long seconds;
	long microseconds;

	// constructors
	TimeParts(long seconds, long microseconds) :
		seconds(seconds), microseconds(microseconds) {}

	TimeParts(timeval tv) :
		seconds(tv.tv_sec), microseconds(tv.tv_usec) {}
};

/**
 * A descriptor of the resource usage of the
 * current process. This object is immutable
 * after construction.
 */
class ResourceUsage
{
public:
	// constructors
	ResourceUsage(int);
	
	// time accessors
	TimeParts utime() const;
	TimeParts stime() const;

	// accessors
	long maxrss() const;
	long ixrss() const;
	long idrss() const;
	long isrss() const;
	long minflt() const;
	long majflt() const;
	long nswap() const;
	long inblock() const;
	long oublock() const;
	long msgsnd() const;
	long msgrcv() const;
	long nsignals() const;
	long nvcsw() const;
	long nivcsw() const;
private:
	int who_;

	rusage usage_;
};

#endif
