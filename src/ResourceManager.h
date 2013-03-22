#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceLimit.h"
#include "ResourceUsage.h"

#include "Singleton.h"

#include "sys/resource.h"
#include "sys/time.h"

#include <set>

class ResourceManager : public Singleton<ResourceManager>
{
public:
	// mutators
	bool set_resource_limit(const ResourceLimit&);

	// accessors
	ResourceLimit get_resource_limit(int) const;
	ResourceUsage get_resource_usage(int) const;

	// operational functions
	void apply_limits();
private:
	std::set<ResourceLimit> resource_limits_;
};

#endif
