#include "spin_lock.hpp"

void spin_lock::lock() noexcept
{
	while (flag_.test_and_set(std::memory_order_acquire))
	{
		flag_.wait(true, std::memory_order_relaxed);
	}
}

void spin_lock::unlock() noexcept
{
	flag_.clear(std::memory_order_release);
	flag_.notify_all();
}
