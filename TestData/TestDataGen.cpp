#include <iostream>
#include <unistd.h>
#include <random>

constexpr int MAXSIZE = 960;

int n, k, m;

void init()
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<float> unif(-1000, 1000);
	
	n = k = m = 192 * CNT;
	//n = k = m = 2;
	std::cout << n << ' ' << k << ' ' << m << '\n';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
			std::cout << unif(eng) << ' ';
		std::cout << '\n';
	}
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < m; ++j)
			std::cout << unif(eng) << ' ';
		std::cout << '\n';
	}
}

int main()
{
	init();

	return 0;
}
