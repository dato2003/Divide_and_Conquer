#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

const int SOTD = 22;

vector< pair<int,int> > Map;


char Display[SOTD][SOTD];
priority_queue< pair<double,pair<int,int> > > Archive;
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
void DrawLine(pair<double,double> Func,int MinX,int MaxX)
{
	for(int x = MinX+1 ;x < MaxX;x++)
	{
		if(Func.first != Null && Func.second != Null)
		{
			double y = Func.first * x + Func.second;
			if(y > -1*(SOTD/2) && y < SOTD/2)
			{
				Display[SOTD/2 - (int)y][SOTD/2 + x] = '$';
			}
		}else
		{
			Display[SOTD/2-x][SOTD/2+Map[0].first] = '$';
		}
	}
}
double FindPoint(pair<int,int> x1,pair<double,double> Func)
{
	pair<double,double> RightFunc = calcRightAngle(x1,Func);
	//cout<<RightFunc.first<<" "<<RightFunc.second<<endl;
	pair<int,int> Inter = GetIntersectionPoint(RightFunc,Func);
	//cout<<Inter.first<<" "<<Inter.second<<endl;
	double distance = GetDistance(x1,Inter);
	//cout<<distance<<endl;
	return distance;
}

double area(pair<int,int> Point1, pair<int,int> Point2, pair<int,int> Point3) 
{ 
   return abs((Point1.first*(Point2.second-Point3.second) + 
   			Point2.first*(Point3.second-Point1.second) + 
			Point3.first*(Point1.second-Point2.second))/2.0); 
}
bool isInside(pair<int,int> Point1,pair<int,int> Point2, pair<int,int> Point3, pair<int,int> Point4) 
{    
   double A = area (Point1, Point2, Point3); 

   double A1 = area (Point4, Point2, Point3);   
   double A2 = area (Point1, Point4, Point3);    
   double A3 = area (Point1, Point2, Point4); 

   if(A1+A2+A3 == A)
   {
	return true;
   }
   return false;
} 
  
int main()
{
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
	vector< pair<int,int> > Result = Map;
	/*
	cout<<MaxX.first.first<<":"<<MaxX.first.second<<" "<<MaxX.second<<endl;
	cout<<MinX.first.first<<":"<<MinX.first.second<<" "<<MinX.second<<endl;
	cout<<MaxY.first.first<<":"<<MaxY.first.second<<" "<<MaxY.second<<endl;
	cout<<MinY.first.first<<":"<<MinY.first.second<<" "<<MinY.second<<endl;
	*/

	//STOP GETTING CORDINATES

	//DRAW ALL POINTS
	for(int i=0;i<n;i++)
	{
		Display[SOTD/2 - Map[i].second][SOTD/2 + Map[i].first] = '*';	
	}
	//END DRAW ALL POINTS

	//DRAW LINE
	pair<double,double> Func = calcFunc(Map[MaxX.second],Map[MinX.second]);
	DrawLine(Func,MinX.first.first,MaxX.first.first);
	//END DRAW LINE
	
	//CALCULATE
	double max = 0;
	pair<int,int> Point;
	for(int i=0;i<Map.size();i++)
	{
		if(i != MaxX.second && i != MinX.second)
		{
			double distance = FindPoint(Map[i],Func);
			Archive.push(make_pair(distance,Map[i]));
			if(max < distance)
			{
				max = distance;	
				Point = Map[i];
			}
		}
	}
	cout<<"Dist:"<<max<<"||"<<Point.first<<":"<<Point.second<<endl;
	//cout<<isInside(MinX.first,MaxX.first,Point,Map[1])<<endl;
	
	while(!Archive.empty())
	{
		Point = Archive.top().second;
		cout<<"POINT:"<<Point.first<<":"<<Point.second<<endl;
		for(int i=0;i<Map.size();i++)
		{
			if(i != MinX.second && i != MaxX.second && Map[i] != Point)
			{	
				if(isInside(MinX.first,MaxX.first,Point,Map[i]))
				{
					cout<<"		TARGET:"<<Map[i].first<<":"<<Map[i].second<<endl;
					Result.erase(remove(Result.begin(), Result.end(), Map[i]), Result.end());
				}
			}
		}
		Archive.pop();
	}
	for(int i=0;i<Result.size();i++)
	{
		cout<<Result[i].first<<":"<<Result[i].second<<endl;
	}
	//END CALCULATE

	//DISPLAY
	for(int i=0;i<SOTD;i++)
	{
		for(int j=0;j<SOTD;j++)
		{
			if(Display[i][j] == NULL)
			{
				cout<<" ";
			}else
			{
				cout<<Display[i][j];
			}
		}
		cout<<endl;
	}
	//STOP DISPLAY
}