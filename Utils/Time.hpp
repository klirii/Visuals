#pragma once
#include <chrono>

namespace Utils {
	using namespace std;

	class TimeNow {
	public:
		static __int64 UnixNano() {
			chrono::steady_clock::time_point timestamp = chrono::steady_clock::now();
			return chrono::duration_cast<chrono::nanoseconds>(timestamp.time_since_epoch()).count();
		}
	};

	class Time {
	public:
		static TimeNow now;
	};

	TimeNow Time::now;
}