#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class TimeHMS
{
	int hour, min, sec;
public:
	TimeHMS(int h, int m, int s) : hour(h), min(m), sec(s) { }
	TimeHMS(int d = 0) { convert(d); }

	void convert(int total) {
		hour = total / (60 * 60);
		total %= (60 * 60);
		min = total / 60;
		sec = total % 60;
	}
	int totalsec() { return hour * (60 * 60) + min * 60 + sec; }

	TimeHMS operator+(TimeHMS t) {
		return TimeHMS((hour + t.hour) * 3600 + (min + t.min) * 60 + (sec + t.sec));
	}
	TimeHMS operator-(TimeHMS t) {
		return TimeHMS((hour - t.hour) * 3600 + (min - t.min) * 60 + (sec - t.sec));
	}
	bool operator==(TimeHMS t) { return totalsec() == t.totalsec(); }
	bool operator!=(TimeHMS t) { return totalsec() != t.totalsec(); }


	TimeHMS& operator++() {
		hour++;
		return *this;
	}
	TimeHMS& operator--() {
		hour--;
		return *this;
	}
	TimeHMS& operator++(int) {
		sec++;
		return *this;
	}
	TimeHMS& operator--(int) {
		sec--;
		return *this;
	}

	int operator[](int id) {
		if (id == 0) return hour;
		else if (id == 1) return min;
		else if (id == 2) return sec;
		else return -1;
	}

	operator int() { return totalsec(); }
	operator double() { return totalsec() / 3600.; }

	friend TimeHMS operator*(int times, TimeHMS t) {
		return TimeHMS(times * t.totalsec());
	}
	friend ostream& operator<<(ostream& os, const TimeHMS& t) {
		os << fixed << setfill('0') <<
			setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec
			<< endl;
		return os;
	}
	friend istream& operator>>(istream& is, TimeHMS& t) {
		int total;
		is >> total;
		t.convert(total);
		return is;
	}

	void main()
	{
		TimeHMS t1, t2, t3;

		cout << "t1 : ";
		cin >> t1;
		cout << "t2 : ";
		cin >> t2;
		cout << "\n";
		cout << "t1 = " << t1;
		cout << "t2 = " << t2;
		cout << "t3 = t1 + t2, t3 = " << t1 + t2;
		cout << "t3 = t1 - t2, t3 = " << t1 - t2;
		cout << "++t1 = " << ++t1;
		cout << "--t1 = " << --t1;
		cout << "t1++ = " << t1++;
		cout << "t1-- = " << t1--;
		cout << "\n";
		cout << "t1[0], t1[1], t1[2] = " << t1[0] << ", " << t1[1] << ", " << t1[2] << endl;
		cout << "\n";
		cout << "t1[sec] = " << (int)t1 << endl;
		cout << "t1[hour] = " << (double)t1 << endl;
		cout << "\n";
		cout << "2*t1 = " << 2 * t1;
	}
};