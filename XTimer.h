#pragma once
#include <windows.h>

class XTimer
{
protected:
	double		m_freq, m_elapsedTime;
	__int64		m_counterStart;
	bool		m_paused;
public:
	XTimer() : m_freq(0.0), m_elapsedTime(0.0), m_counterStart(0), m_paused(false) { }
	~XTimer();
	
	double GetElapsedTime() const {
		return m_elapsedTime;
	}

	bool StartCounter()
	{
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li))
			return false;

		m_freq = double(li.QuadPart) / 1000.0;

		QueryPerformanceCounter(&li);
		m_counterStart = li.QuadPart;

		return true;
	}

	void CalculateElapsedTIme()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		m_elapsedTime = double(li.QuadPart - m_counterStart) / m_freq;
	}

	void Pause(void) { m_paused = true; m_elapsedTime = 0.0; }
};

