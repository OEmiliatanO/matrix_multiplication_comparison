#include <iostream>
#include <fstream>

using namespace std;

// n = (192, 384, 576, 768, 960)
constexpr int n = 192;

int main()
{
	fstream stdfile, copfile;
	stdfile.open("naive_matrix/matrix_out_n576", ios::in);
	//copfile.open("blocked_matrix/blocked_matrix_out_n576", ios::in);
	//copfile.open("vector_matrix/vector_matrix_out_n960", ios::in);
	copfile.open("vector_matrixV2/vector_matrix_out_n576", ios::in);
	//copfile.open("blocked_cache_matrix/blocked_cache_matrix_out_n192", ios::in);
	//copfile.open("blocked_cache_matrixV2/blocked_cache_matrix_out_n960", ios::in);

	double avgerr = 0, maxerr = 0, stdans = 0, ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			stdfile >> stdans;
			copfile >> ans;
			maxerr = max(maxerr, abs(stdans - ans));
			avgerr += abs(stdans - ans);
		}
	
	avgerr /= n*n;
	
	cout << "maxerr: " << maxerr << '\n';
	cout << "avgerr: " << avgerr << '\n';

	return 0;
}
