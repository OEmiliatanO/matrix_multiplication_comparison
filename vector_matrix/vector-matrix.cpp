#include <iostream>
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
	for (int x = 0; x < n; x += 4)
		for (int y = 0; y < m; y += 4)
		{
			__m128 r0 = _mm_setzero_ps();
			__m128 r1 = _mm_setzero_ps();
			__m128 r2 = _mm_setzero_ps();
			__m128 r3 = _mm_setzero_ps();

			for (int z = 0; z < k; z += 4)
			{
				// load A[x:x+3][k:k+3] and B[k:k+3][y:y+3]
				__m128 I0 = _mm_load_ps(&A[x+0][z]);
				__m128 I1 = _mm_load_ps(&A[x+1][z]);
				__m128 I2 = _mm_load_ps(&A[x+2][z]);
				__m128 I3 = _mm_load_ps(&A[x+3][z]);

				__m128 I4 = _mm_set_ps(B[z+3][y+0], B[z+2][y+0], B[z+1][y+0], B[z+0][y+0]);
				__m128 I5 = _mm_set_ps(B[z+3][y+1], B[z+2][y+1], B[z+1][y+1], B[z+0][y+1]);
				__m128 I6 = _mm_set_ps(B[z+3][y+2], B[z+2][y+2], B[z+1][y+2], B[z+0][y+2]);
				__m128 I7 = _mm_set_ps(B[z+3][y+3], B[z+2][y+3], B[z+1][y+3], B[z+0][y+3]);

				// calculate
				__m128 T0 = _mm_mul_ps(I0, I4);
				__m128 T1 = _mm_mul_ps(I0, I5);
				__m128 T2 = _mm_mul_ps(I0, I6);
				__m128 T3 = _mm_mul_ps(I0, I7);

				__m128 T4 = _mm_mul_ps(I1, I4);
				__m128 T5 = _mm_mul_ps(I1, I5);
				__m128 T6 = _mm_mul_ps(I1, I6);
				__m128 T7 = _mm_mul_ps(I1, I7);

				__m128 T8 = _mm_mul_ps(I2, I4);
				__m128 T9 = _mm_mul_ps(I2, I5);
				__m128 T10 = _mm_mul_ps(I2, I6);
				__m128 T11 = _mm_mul_ps(I2, I7);

				__m128 T12 = _mm_mul_ps(I3, I4);
				__m128 T13 = _mm_mul_ps(I3, I5);
				__m128 T14 = _mm_mul_ps(I3, I6);
				__m128 T15 = _mm_mul_ps(I3, I7);

				// transpose
				__m128 T16 = _mm_unpacklo_ps(T0, T1);
				__m128 T17 = _mm_unpacklo_ps(T2, T3);
				__m128 T18 = _mm_unpackhi_ps(T0, T1);
				__m128 T19 = _mm_unpackhi_ps(T2, T3);

				__m128 T20 = _mm_unpacklo_ps(T16, T17);
				__m128 T21 = _mm_unpacklo_ps(T16, T17);
				__m128 T22 = _mm_unpackhi_ps(T18, T19);
				__m128 T23 = _mm_unpackhi_ps(T18, T19);

				T20 = _mm_add_ps(T20, T21);
				T20 = _mm_add_ps(T20, T22);
				T20 = _mm_add_ps(T20, T23);

				r0 = _mm_add_ps(T20, r0);
				
				T16 = _mm_unpacklo_ps(T4, T5);
				T17 = _mm_unpacklo_ps(T6, T7);
				T18 = _mm_unpacklo_ps(T4, T5);
				T19 = _mm_unpacklo_ps(T6, T7);
				
				T20 = _mm_unpacklo_ps(T16, T17);
				T21 = _mm_unpacklo_ps(T16, T17);
				T22 = _mm_unpackhi_ps(T18, T19);
				T23 = _mm_unpackhi_ps(T18, T19);

				T20 = _mm_add_ps(T20, T21);
				T20 = _mm_add_ps(T20, T22);
				T20 = _mm_add_ps(T20, T23);

				r1 = _mm_add_ps(T20, r1);

				T16 = _mm_unpacklo_ps(T8, T9);
				T17 = _mm_unpacklo_ps(T10, T11);
				T18 = _mm_unpacklo_ps(T8, T9);
				T19 = _mm_unpacklo_ps(T10, T11);
				
				T20 = _mm_unpacklo_ps(T16, T17);
				T21 = _mm_unpacklo_ps(T16, T17);
				T22 = _mm_unpackhi_ps(T18, T19);
				T23 = _mm_unpackhi_ps(T18, T19);

				T20 = _mm_add_ps(T20, T21);
				T20 = _mm_add_ps(T20, T22);
				T20 = _mm_add_ps(T20, T23);

				r2 = _mm_add_ps(T20, r2);
				
				T16 = _mm_unpacklo_ps(T12, T13);
				T17 = _mm_unpacklo_ps(T14, T15);
				T18 = _mm_unpacklo_ps(T12, T13);
				T19 = _mm_unpacklo_ps(T14, T15);
				
				T20 = _mm_unpacklo_ps(T16, T17);
				T21 = _mm_unpacklo_ps(T16, T17);
				T22 = _mm_unpackhi_ps(T18, T19);
				T23 = _mm_unpackhi_ps(T18, T19);

				T20 = _mm_add_ps(T20, T21);
				T20 = _mm_add_ps(T20, T22);
				T20 = _mm_add_ps(T20, T23);

				r3 = _mm_add_ps(T20, r3);
			}

			_mm_store_ps(&C[x+0][y], r0);
			_mm_store_ps(&C[x+1][y], r1);
			_mm_store_ps(&C[x+2][y], r2);
			_mm_store_ps(&C[x+3][y], r3);
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
			std::cin >> B[j][i];
	
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
