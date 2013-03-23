#include "ResourceLimit.h"
#include "errno.h"
#include <system_error>

using namespace std;

ResourceLimit::ResourceLimit(int resource_id) :
	resource_id_(resource_id), applied_(false)
{
	if (getrlimit(resource_id, &limit_) == -1)
		throw system_error(errno, system_category());
}

ResourceLimit::ResourceLimit(int resource_id, rlim_t soft_limit, rlim_t hard_limit) :
	resource_id_(resource_id), applied_(false)
{
	limit_.rlim_cur = soft_limit;
	limit_.rlim_max = hard_limit;
}

ResourceLimit::ResourceLimit(int resource_id, rlimit& limit) :
	resource_id_(resource_id), limit_(limit), applied_(false) {}

rlim_t ResourceLimit::soft_limit() const noexcept
{
	return limit_.rlim_cur;
}

rlim_t ResourceLimit::hard_limit() const noexcept
{
	return limit_.rlim_max;
}

void ResourceLimit::get_limit()
{
	if (getrlimit(resource_id_, &limit_) == -1)
		throw system_error(errno, system_category());
}

void ResourceLimit::apply()
{
	if (setrlimit(resource_id_, &limit_) == -1)
		throw system_error(errno, system_category());
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
