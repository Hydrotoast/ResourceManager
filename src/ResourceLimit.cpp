#include "ResourceLimit.h"

ResourceLimit::ResourceLimit(int resource_id) :
	resource_id_(resource_id), applied_(false)
{
	getrlimit(resource_id, &limit_);
}

ResourceLimit::ResourceLimit(int resource_id, rlim_t soft_limit, rlim_t hard_limit) :
	resource_id_(resource_id), applied_(false)
{
	limit_.rlim_cur = soft_limit;
	limit_.rlim_max = hard_limit;
}

ResourceLimit::ResourceLimit(int resource_id, rlimit& limit) :
	resource_id_(resource_id), limit_(limit), applied_(false) {}

rlim_t ResourceLimit::soft_limit() const
{
	return limit_.rlim_cur;
}

rlim_t ResourceLimit::hard_limit() const
{
	return limit_.rlim_max;
}

void ResourceLimit::get_limit()
{
	getrlimit(resource_id_, &limit_);
}

void ResourceLimit::apply()
{
	setrlimit(resource_id_, &limit_);
	applied_ = true;
}

bool ResourceLimit::operator==(const ResourceLimit& other) const
{
	return resource_id_ == other.resource_id_;
}

bool ResourceLimit::operator<(const ResourceLimit& other) const
{
	return resource_id_ < other.resource_id_;
}
