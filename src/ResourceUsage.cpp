#include "ResourceUsage.h"

ResourceUsage::ResourceUsage(int who) : who_(who)
{
	getrusage(who, &usage_);
}

TimeParts ResourceUsage::utime() const { return TimeParts(usage_.ru_utime); }
TimeParts ResourceUsage::stime() const { return TimeParts(usage_.ru_stime); }

long ResourceUsage::maxrss() const { return usage_.ru_maxrss; }
long ResourceUsage::ixrss() const { return usage_.ru_ixrss; }
long ResourceUsage::idrss() const { return usage_.ru_idrss; }
long ResourceUsage::minflt() const { return usage_.ru_minflt; }
long ResourceUsage::majflt() const { return usage_.ru_majflt; }
long ResourceUsage::nswap() const { return usage_.ru_nswap; }
long ResourceUsage::inblock() const { return usage_.ru_inblock; }
long ResourceUsage::oublock() const { return usage_.ru_oublock; }
long ResourceUsage::msgsnd() const { return usage_.ru_msgsnd; }
long ResourceUsage::msgrcv() const { return usage_.ru_msgrcv; }
long ResourceUsage::nsignals() const { return usage_.ru_nsignals; }
long ResourceUsage::nvcsw() const { return usage_.ru_nvcsw; }
long ResourceUsage::nivcsw() const { return usage_.ru_nivcsw; }
