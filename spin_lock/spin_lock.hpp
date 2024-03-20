#ifndef SPIN_LOCK_HPP
#define SPIN_LOCK_HPP

#include <atomic>

class alignas(std::hardware_destructive_interference_size) spin_lock final
{
public:
	spin_lock() = default;
	spin_lock(const spin_lock&) = delete;
	spin_lock(spin_lock&&) = delete;
	spin_lock& operator=(const spin_lock&) = delete;
	spin_lock& operator=(spin_lock&&) = delete;
	~spin_lock() = default;

	/**
   * @brief Locks the locker.
   */
	void lock() noexcept;

	/**
   * @brief Unlocks the locker.
   * 
   */
	void unlock() noexcept;

private:
	std::atomic_flag flag_{ATOMIC_FLAG_INIT};
};

#endif // SPIN_LOCK_HPP
