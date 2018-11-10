#include<iostream>
#include<vector>
using namespace std;

int SOTD = 102;

double Null = -99999999999.0;

pair<double,double> calcFunc(pair<int,int> x1,pair<int,int> x2)
{
	pair<double,double> Func;
	double k,b;
	if(x1.first - x2.first != 0)
	{
		k = (double)(x1.second - x2.second) / (double)(x1.first - x2.first);
		b = x1.second - k * x1.first;
	}else
	{
		k = Null;
		b = Null;
	}
	Func.first = k;
	Func.second = b;
	return Func;
}
int main()
{
	//TEMPLATE
	vector< pair<int,int> > Map;
	char Display[SOTD][SOTD];
	//SETTING UP THE BOARD

	for(int i=0;i<SOTD;i++)
	{
		Display[i][SOTD/2] = '|';
	}
	for(int i=0;i<SOTD;i++)
	{
		Display[SOTD/2][i] = '-';
	}
	Display[SOTD/2][SOTD/2] = '#';

	//END SETTING UP THE BOARD

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		pair<int,int> x;
		cin>>x.first>>x.second;

		Map.push_back(x);
	}
	//END TEMPLATE

	pair<double,double> Func = calcFunc(Map[0],Map[1]);
	//pair<int,int> Func;
	//Func.first = 1;
	//Func.second = -2;
	for(int x = -1*(SOTD/2)+1;x < SOTD/2;x++)
	{
		if(Func.first != Null && Func.second != Null)
		{
			double y = Func.first * x + Func.second;
			if(y > -1*(SOTD/2) && y < SOTD/2)
			{
				Display[SOTD/2 - (int)y][SOTD/2 + x] = '*';
			}
		}else
		{
			Display[SOTD/2-x][SOTD/2+Map[0].first] = '*';
		}
	}   
	//TEMPLATE
	//DISPLAY
	for(int i=0;i<SOTD;i++)
	{
		for(int j=0;j<SOTD;j++)
		{
			if(Display[i][j] == '*' || Display[i][j] == '#' || Display[i][j] == '-' || Display[i][j] == '|')
			{
				cout<<Display[i][j];
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	//STOP DISPLAY
	//END TEMPLATE
}