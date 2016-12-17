#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int nVertices, mRatings;

class Cycle
{
public:
	Cycle();
	Cycle(int k, int n);
	~Cycle();
	int *cycle;
	void nextCycle();
	bool isTheLast();
	bool isNonIncreasing();
	int getSum()
	{
		return accumulate(cycle, cycle + k, 0);
	}

	void fillWithOnes();
private:
	int depth, k;
	int n;
};

Cycle::Cycle()
{

}

Cycle::Cycle(int k, int n)
{
	cycle = new int[k];
	this->k = k;
	this->n = n;
}

Cycle::~Cycle()
{
	delete cycle;
}

bool Cycle::isTheLast()
{
	for (int i = 0; i < k; i++)
		if (cycle[i] != n)
			return false;
	return true;
}

class Composition
{
public:
	Composition();
	Composition(int n, int k);
	~Composition();

	bool isSumCorrect()
	{
		int realSum = cycle->getSum();
		return sum == realSum;
	}
	bool isSumGreater()
	{
		int realSum = cycle->getSum();
		return sum < realSum;
	}
	void nextCycle();

	int count();

private:
	int sum;
	int k;
	Cycle *cycle;
};

Composition::Composition()
{
	sum = 0;
	cycle = NULL;
}

Composition::Composition(int n, int k)
{
	sum = n;
	cycle = new Cycle(k, n);
	this->k = k;
	cycle->fillWithOnes();
}

void Cycle::fillWithOnes()
{
	for (int i = 0; i < k; i++)
		cycle[i] = 1;
}

Composition::~Composition()
{
	delete cycle;
}

bool Cycle::isNonIncreasing()
{
	for (int i = 1; i < k; i++)
		if (cycle[i - 1] < cycle[i])
			return false;
	return true;
}

void Cycle::nextCycle()
{
	depth = 0;
	int prevDepth = depth;
	do
	{
		prevDepth = depth;
		cycle[depth]++;
		if (cycle[depth] > n)
		{
			cycle[depth] = 1;
			depth++;
			if (depth >= k)
				throw new exception();
		}
	} while (cycle[prevDepth] == 1);
}

int Composition::count()
{
	int c = 0;

	while (!(cycle->isTheLast()))
	{
		if (isSumCorrect() && cycle->isNonIncreasing())
			c++;

		try
		{
			cycle->nextCycle();
		}
		catch (exception &e)
		{
			cout << "cos nie tak" << endl;
		}
	};
	if (isSumCorrect() && cycle->isNonIncreasing())
		c++;
	
	return c;
}

int iPow(int x, int p)
{
	if (p == 0) return 1;
	if (p == 1) return x;

	int tmp = iPow(x, p / 2);
	if (p % 2 == 0) return tmp * tmp;
	else return x * tmp * tmp;
}

int calcComposition(int k, int n)
{
	//x_1 + x_2 + ... + x_k = n
	//x_i \in \mathrm{N}, x_i \ge 1
	Composition *composition = new Composition(n, k);
	return composition->count();
}

int giveResult() {
	vector<int> compositions;
	for (int k = 1; k <= nVertices; k++)
		compositions.push_back(calcComposition(k, nVertices));
	int sumOfCompositions = accumulate(compositions.begin(), compositions.end(), 0);
	return iPow(mRatings, sumOfCompositions);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	//ifstream cin;

	//cin.open("in.txt");
	
	cin >> nVertices;
	cin >> mRatings;

	int result = giveResult();
	cout << result << endl;

	//system("pause");
	return 0;
}
