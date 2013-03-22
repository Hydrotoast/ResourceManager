#ifndef RESOURCELIMIT_H
#define RESOURCELIMIT_H

#include "sys/resource.h"

class ResourceLimit
{
public:
	// constructors
	ResourceLimit(int);
	ResourceLimit(int, rlim_t, rlim_t);
	ResourceLimit(int, rlimit&);

	// accessors
	rlim_t soft_limit() const;
	rlim_t hard_limit() const;

	// native accessors
	const rlimit& to_rlimit() const;

	// operational functions
	void get_limit();
	void apply();

	// comparisons
	bool operator==(const ResourceLimit&) const;
	bool operator<(const ResourceLimit&) const;
private:
	int resource_id_;
	rlimit limit_;

	bool applied_;
};


#endif
