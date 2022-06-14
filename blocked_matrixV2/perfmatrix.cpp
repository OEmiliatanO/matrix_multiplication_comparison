#include <iostream>
#include <chrono>
#include <fstream>
#define min(a, b) ((a)>(b)?(b):(a))

constexpr int MAXSIZE = 960;

float A[MAXSIZE][MAXSIZE]{}, B[MAXSIZE][MAXSIZE]{}, C[MAXSIZE][MAXSIZE]{};

int n, k, m;

inline void MMUL() noexcept
{
	int x, y, z, xx, yy, zz, maxx, maxy, maxz;
	for (x = 0; x < n; x += BLOCK)
		for (y = 0; y < m; y += BLOCK)
			for (z = 0; z < k; z += BLOCK)
			{
				maxx = min(n, x + BLOCK);
				maxy = min(m, y + BLOCK);
				maxz = min(k, z + BLOCK);
				for (xx = x; xx < maxx; ++xx)
					for (yy = y; yy < maxy; ++yy)
						for (zz = z; zz < maxz; ++zz)
							C[xx][yy] += A[xx][zz] * B[zz][yy];
			}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::fstream fin;
	fin.open("../TestData/n960");
	
	fin >> n >> k >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			fin >> A[i][j];
	
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < m; ++j)
			fin >> B[i][j];
	
	auto begin = std::chrono::high_resolution_clock::now();
	MMUL();
	auto end = std::chrono::high_resolution_clock::now();
	auto T = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	std::cerr << T.count() << '\n';

	return 0;
}
