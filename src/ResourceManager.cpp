#include "ResourceManager.h"

using namespace std;

bool ResourceManager::set_resource_limit(const ResourceLimit& limit)
{
	return resource_limits_.insert(limit).second;
}

ResourceLimit ResourceManager::get_resource_limit(int resource_id) const
{
	return *resource_limits_.find(ResourceLimit(resource_id));
}

ResourceUsage ResourceManager::get_resource_usage(int who) const
{
	return ResourceUsage(who);
}

void ResourceManager::apply_limits()
{
	for (ResourceLimit limit : resource_limits_)
		limit.apply();
}
