#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int SOTD = 22;
//SIZE OF THE MAP MUST BE (X*2)+2.SO IF YOU WANT 9X9 SOTD = 20;MUST BE EVEN
//FORMULA FOR THE SIZE; X IS YOUR DESIRED SIZE; (X*2)+2 = SOTD;

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
pair<double,double> calcRightAngle(pair<int,int> x1,pair<double,double> Func)
{
	pair<double,double> RightFunc;
	
	double k = -1 *(1/Func.first);
	double b = x1.second - (k * x1.first);
	
	RightFunc.first = k;
	RightFunc.second = b;

	return RightFunc;
}

pair<int,int> GetIntersectionPoint(pair<double,double> RightFunc,pair<double,double> Func)
{
	pair<int,int> Inter;

	Inter.first = (int)((RightFunc.second - Func.second)/(Func.first - RightFunc.first));
	Inter.second = (int)(RightFunc.first*Inter.first + RightFunc.second);
	
	return Inter;
}

double GetDistance(pair<int,int> x1,pair<int,int> x2)
{
	double distance = 
	sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));

	return distance;
}
double FindPoint(pair<int,int> x1,pair<double,double> Func)
{
	pair<double,double> RightFunc = calcRightAngle(x1,Func);
	cout<<RightFunc.first<<" "<<RightFunc.second<<endl;
	pair<int,int> Inter = GetIntersectionPoint(RightFunc,Func);
	cout<<Inter.first<<" "<<Inter.second<<endl;
	double distance = GetDistance(x1,Inter);
	cout<<distance<<endl;
	return distance;
}
int main()
{
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

	pair< pair<int,int>,int> MaxX;
	MaxX.first.first = -99999;
	MaxX.first.second = -99999;
	MaxX.second = -99999;
	
	pair< pair<int,int>,int> MinX;
	MinX.first.first = 99999;
	MinX.first.second = 99999;
	MinX.second = -99999;

	pair< pair<int,int>,int> MaxY;
	MaxY.first.first = -99999;
	MaxY.first.second = -99999;
	MaxY.second = -99999;
	
	pair< pair<int,int>,int> MinY;
	MinY.first.first = 99999;
	MinY.first.second = 99999;
	MinY.second = -99999;

	//GETTING CORDINATES
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		pair<int,int> x;
		cin>>x.first>>x.second;

		if(x.first > MaxX.first.first)
		{
			MaxX.first = x;
			MaxX.second = Map.size();
		}
		if(x.first < MinX.first.first)
		{
			MinX.first = x;
			MinX.second = Map.size();
		}
		if(x.second > MaxY.first.first)
		{
			MaxY.first = x;
			MaxY.second = Map.size();
		}
		if(x.second < MinY.first.first)
		{
			MinY.first = x;
			MinY.second = Map.size();
		}
		Map.push_back(x);
	}
	/*
	cout<<MaxX.first.first<<":"<<MaxX.first.second<<" "<<MaxX.second<<endl;
	cout<<MinX.first.first<<":"<<MinX.first.second<<" "<<MinX.second<<endl;
	cout<<MaxY.first.first<<":"<<MaxY.first.second<<" "<<MaxY.second<<endl;
	cout<<MinY.first.first<<":"<<MinY.first.second<<" "<<MinY.second<<endl;
	*/

	//STOP GETTING CORDINATES

	//DRAW LINE
	pair<double,double> Func = calcFunc(Map[MaxX.second],Map[MinX.second]);
	for(int x = MinX.first.first ;x <= MaxX.first.first;x++)
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
	//END DRAW LINE
	
	//CALCULATE
	double max = 0;
	pair<int,int> Point;
	for(int i=0;i<Map.size();i++)
	{
		if(i != MaxX.second && i != MinX.second)
		{
			double distance = FindPoint(Map[i],Func);
			if(max < distance)
			{
				max = distance;	
				Point = Map[i];
			}
		}
	}
	cout<<"Dist:"<<max<<"||"<<Point.first<<":"<<Point.second<<endl;
	//END CALCULATE

	//DRAW ALL POINTS
	for(int i=0;i<n;i++)
	{
		Display[SOTD/2 - Map[i].second][SOTD/2 + Map[i].first] = '*';	
	}
	//END DRAW ALL POINTS

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
}