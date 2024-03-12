// PSByCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;


string ToUpper(string stringList)
{
	for(int i=0; i< stringList.size();++i)
	{
		if('a'<= stringList[i] && stringList[i]<='z')
		{
			stringList[i] += 'A' - 'a';
		}
	}

	return stringList;
}
vector<string> Solution(vector<vector<string>> input)
{
	vector<string> result;

	for(size_t i=0; i<input.size();++i)
	{
		
		std::sort(input[i].begin(), input[i].end(),[&](auto& left, auto& right)
		{
				string converLeft = ToUpper(left);
				string converRight = ToUpper(right);

				if (converLeft < converRight)
					return true;

				return false;
			
		});
		result.push_back(input[i][0]);
	}


	return result;
	
}

void input()
{

	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	vector<string> input;

	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		input.push_back(temp);
	}


	//Solution(input);


}
int main()
{
	//
	//input();

	int n=-1;
	vector<vector<string>> realInput;

	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		vector<string> input;

		for (int i = 0; i < n; ++i)
		{
			string temp;
			cin >> temp;
			input.push_back(temp);
		}

		realInput.push_back(input);

	}
	

	
	vector<string> result;
	result = Solution(realInput);

	for(int i=0; i<result.size();++i)
	{
		cout << result[i] << endl;
	}

	return 0;


}
