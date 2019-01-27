#include "pch.h"
#include <iostream>
#include <iomanip>


class Time {
	int sec_ = 0;
public:
	enum {
		MINUTE = 60,
		HOUR = 60 * MINUTE,
		DAY = 24 * HOUR
	};

	Time() {}

	Time(int sec) :
		sec_(sec)
	{}

	Time(int hours, int mins, int secs) :
		sec_(hours * HOUR + mins * MINUTE + secs)
	{}

	Time(double mins) :
		sec_(mins * MINUTE)
	{}

	Time(double mins, int secs) :
		sec_(mins * MINUTE + secs)
	{}

	Time(double hours, double mins) :
		sec_(hours * HOUR)
	{}

	Time(const Time& time) :
		sec_(time.sec_)
	{}

	Time(Time&& time) :
		sec_(std::move(time.sec_))
	{}

	Time& operator=(const Time& time) {
		sec_ = time.sec_;
		return *this;
	}
	Time& operator=(Time&& time) {
		sec_ = std::move(time.sec_);
		return *this;
	}
	Time& operator++() {
		++sec_;
		return *this;
	}
	Time& operator--() {
		--sec_;
		return *this;
	}
	Time operator++(int) {
		Time tmp = *this;
		++sec_;
		return tmp;
	}
	Time operator--(int) {
		Time tmp = *this;
		--sec_;
		return tmp;
	}
	Time& operator+=(const Time& time) {
		sec_ += time.sec_;
		return *this;
	}
	Time& operator-=(const Time& time) {
		sec_ -= time.sec_;
		return *this;
	}

	int getSec() const {
		return sec_ % MINUTE;
	}
	int getMin() const {
		return sec_ % HOUR / MINUTE;
	}
	int getHour() const {
		return sec_ / HOUR;
	}

	void setSec(int hours, int mins, int secs) {
		sec_ = hours * HOUR + mins * MINUTE + secs;
	}
};

std::ostream& operator<<(std::ostream& os, const Time& obj) {
	bool am = obj.getHour() <= 12 ? true : false;
	os << std::setfill('0') << std::setw(2) << obj.getHour() % 12 << ':' 
		<< std::setfill('0') << std::setw(2) << obj.getMin() << ':' 
		<< std::setfill('0') << std::setw(2) << obj.getSec() << ' '
		<< ((am == true) ? "AM" : "PM");
	return os;
}

std::istream& operator>>(std::istream& is, Time& obj) {
	int hours;
	int mins;
	int secs;
	std::cin >> hours >> mins >> secs;
	obj.setSec(hours, mins, secs);
	return is;
}

int main() {
	Time t1(23); 
	std::cout << t1 << std::endl; // 00:00:23 AM
	Time t2((double)23);
	std::cout << t2 << std::endl; // 00:23:00 AM

	t1 = t2;
	std::cout << t1 << std::endl; // 00:23:00 AM
	
	Time t3 = t2++;
	std::cout << t3 << std::endl; // 00:23:00 AM
	std::cout << t2 << std::endl; // 00:23:01 AM

	t3 += t2;
	std::cout << t3 << std::endl; // 00:46:01 AM

	Time t4(23, 23, 23);
	std::cout << t4 << std::endl; // 11:23:23 PM

	Time t5;
	std::cin >> t5; // 12 -> enter, 12 -> enter, 12 -> enter
	std::cout << t5 << std::endl; // 00:12:12 AM
}
