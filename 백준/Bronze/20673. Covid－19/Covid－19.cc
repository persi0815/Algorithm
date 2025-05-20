#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

int main()
{
	std::cin.tie(NULL); 
	std::ios::sync_with_stdio(false);

	int32_t avgNumNewCasesPerDay;
	std::cin >> avgNumNewCasesPerDay;

	int32_t avgNumNewHospitalizationsPerDay;
	std::cin >> avgNumNewHospitalizationsPerDay;

	std::string colorResult = "";


	if ((avgNumNewCasesPerDay <= 50) && (avgNumNewHospitalizationsPerDay <= 10))
	{
		colorResult = "White";
	}

	else if (avgNumNewHospitalizationsPerDay > 30)
	{
		colorResult = "Red";
	}

	else
	{
		colorResult = "Yellow";
	}

	std::cout << colorResult;

}
