// PSByCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

struct Bridge
{
	int left;
	int right;

};

int used[2][1000] = { { 0,} };

vector<Bridge> debug;
int result = 0;


void Run(int lev ,int selectedRight, int endLeft, int endRight)
{

	if(lev >= endLeft)
	{
		++result;
		//for(int i=0; i<debug.size();++i)
		//{
		//	//cout << "Debug(" << debug[i].left << "," << debug[i].right << ")" << endl;

		//}
		//debug.clear();

		return;
	}

	used[0][lev] = 1;

	for(int i=0; i<endRight;++i)
	{
		if (used[1][i] == 0 && selectedRight <=i)
		{
			if(lev==0 && i == endRight)
			{
				return;
			}
			used[1][i] = 1;
		/*	debug.push_back({ lev,i });*/
			Run(lev + 1, i, endLeft, endRight);
			used[1][i] = 0; 

		}
		else
		{
			continue;
		}
	}
	used[0][lev] = 0;


}
void Outer(int left, int right)
{
	Run(0, 0, left, right);
}
int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	vector<Bridge> inputVec;

	cin >> n;

	for(int i=0 ;i<n;++i)
	{
		int left, right = 0;

		cin >> left >> right;

		inputVec.push_back({ left,right });
	}

	

	for(auto node : inputVec)
	{

		Outer(node.left, node.right);
		cout << result << endl;
		result = 0;

	}

}
