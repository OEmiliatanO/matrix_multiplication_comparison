#include <iostream>
#include <limits>
#include <chrono>
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>
#include <smmintrin.h>
#include <nmmintrin.h>
#include <immintrin.h>

constexpr int MAXSIZE = 960;

float A[MAXSIZE][MAXSIZE] __attribute__((aligned(16)));
float B[MAXSIZE][MAXSIZE] __attribute__((aligned(16)));
float C[MAXSIZE][MAXSIZE] __attribute__((aligned(16)));

int n, k, m;

inline void MMUL() noexcept
{
	//float (*A)[MAXSIZE][MAXSIZE] = A;
	//float (*B)[MAXSIZE][MAXSIZE] = B;
	//float (*C)[MAXSIZE][MAXSIZE] = C;

	for (int x = 0; x < n; x += 4)
		for (int y = 0; y < m; y += 4)
		{
			__m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8;

			__m128 xmm9  = _mm_setzero_ps();
			__m128 xmm10 = _mm_setzero_ps();
			__m128 xmm11 = _mm_setzero_ps();
			__m128 xmm12 = _mm_setzero_ps();

			for (int z = 0; z < k; z += 4)
			{
				xmm0 = _mm_load_ps(&B[z+0][y]);
				xmm1 = _mm_load_ps(&B[z+1][y]);
				xmm2 = _mm_load_ps(&B[z+2][y]);
				xmm3 = _mm_load_ps(&B[z+3][y]);
				
				// load A[x][z:z+3]
				xmm4 = _mm_load_ps(&A[x+0][z]);
				xmm5 = _mm_shuffle_ps(xmm4, xmm4, 0x00);
				xmm6 = _mm_shuffle_ps(xmm4, xmm4, 0x55);
				xmm7 = _mm_shuffle_ps(xmm4, xmm4, 0xAA);
				xmm8 = _mm_shuffle_ps(xmm4, xmm4, 0xFF);
				
				xmm5 = _mm_mul_ps(xmm5, xmm0);
				xmm6 = _mm_mul_ps(xmm6, xmm1);
				xmm5 = _mm_add_ps(xmm5, xmm6);
				
				xmm7 = _mm_mul_ps(xmm7, xmm2);
				xmm8 = _mm_mul_ps(xmm8, xmm3);
				xmm7 = _mm_add_ps(xmm7, xmm8);
				
				xmm5 = _mm_add_ps(xmm5, xmm7);
				xmm9 = _mm_add_ps(xmm9, xmm5);
				
				// load A[x+1][z:z+3]
				xmm4 = _mm_load_ps(&A[x+1][z]);
				xmm5 = _mm_shuffle_ps(xmm4, xmm4, 0x00);
				xmm6 = _mm_shuffle_ps(xmm4, xmm4, 0x55);
				xmm7 = _mm_shuffle_ps(xmm4, xmm4, 0xAA);
				xmm8 = _mm_shuffle_ps(xmm4, xmm4, 0xFF);
				
				xmm5 = _mm_mul_ps(xmm5, xmm0);
				xmm6 = _mm_mul_ps(xmm6, xmm1);
				xmm5 = _mm_add_ps(xmm5, xmm6);
				
				xmm7 = _mm_mul_ps(xmm7, xmm2);
				xmm8 = _mm_mul_ps(xmm8, xmm3);
				xmm7 = _mm_add_ps(xmm7, xmm8);
				
				xmm5 = _mm_add_ps(xmm5, xmm7);
				xmm10 = _mm_add_ps(xmm10, xmm5);
				
				// load A[x+2][z:z+3]
				xmm4 = _mm_load_ps(&A[x+2][z]);
				xmm5 = _mm_shuffle_ps(xmm4, xmm4, 0x00);
				xmm6 = _mm_shuffle_ps(xmm4, xmm4, 0x55);
				xmm7 = _mm_shuffle_ps(xmm4, xmm4, 0xAA);
				xmm8 = _mm_shuffle_ps(xmm4, xmm4, 0xFF);
				
				xmm5 = _mm_mul_ps(xmm5, xmm0);
				xmm6 = _mm_mul_ps(xmm6, xmm1);
				xmm5 = _mm_add_ps(xmm5, xmm6);
				
				xmm7 = _mm_mul_ps(xmm7, xmm2);
				xmm8 = _mm_mul_ps(xmm8, xmm3);
				xmm7 = _mm_add_ps(xmm7, xmm8);
				
				xmm5 = _mm_add_ps(xmm5, xmm7);
				xmm11 = _mm_add_ps(xmm11, xmm5);
				
				// load A[x+3][z:z+3]
				xmm4 = _mm_load_ps(&A[x+3][z]);
				xmm5 = _mm_shuffle_ps(xmm4, xmm4, 0x00);
				xmm6 = _mm_shuffle_ps(xmm4, xmm4, 0x55);
				xmm7 = _mm_shuffle_ps(xmm4, xmm4, 0xAA);
				xmm8 = _mm_shuffle_ps(xmm4, xmm4, 0xFF);
				
				xmm5 = _mm_mul_ps(xmm5, xmm0);
				xmm6 = _mm_mul_ps(xmm6, xmm1);
				xmm5 = _mm_add_ps(xmm5, xmm6);
				
				xmm7 = _mm_mul_ps(xmm7, xmm2);
				xmm8 = _mm_mul_ps(xmm8, xmm3);
				xmm7 = _mm_add_ps(xmm7, xmm8);
				
				xmm5 = _mm_add_ps(xmm5, xmm7);
				xmm12 = _mm_add_ps(xmm12, xmm5);
			}
			_mm_store_ps(&C[x+0][y], xmm9);
			_mm_store_ps(&C[x+1][y], xmm10);
			_mm_store_ps(&C[x+2][y], xmm11);
			_mm_store_ps(&C[x+3][y], xmm12);
		}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			std::cin >> A[i][j];
	
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> B[i][j];
	
	auto begin = std::chrono::high_resolution_clock::now();
	MMUL();
	auto end = std::chrono::high_resolution_clock::now();
	auto T = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	std::cerr << T.count() << '\n';
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			std::cout << C[i][j] << ' ';
		std::cout << '\n';
	}
	return 0;
}
