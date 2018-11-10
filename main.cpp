#include<iostream>
#include<vector>
using namespace std;
int SOTD = 22;
//SIZE OF THE MAP MUST BE (X*2)+2.SO IF YOU WANT 9X9 SOTD = 20;MUST BE EVEN
//FORMULA FOR THE SIZE; X IS YOUR DESIRED SIZE; (X*2)+2 = SOTD;
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
	cout<<MaxX.first.first<<":"<<MaxX.first.second<<" "<<MaxX.second<<endl;
	cout<<MinX.first.first<<":"<<MinX.first.second<<" "<<MinX.second<<endl;
	cout<<MaxY.first.first<<":"<<MaxY.first.second<<" "<<MaxY.second<<endl;
	cout<<MinY.first.first<<":"<<MinY.first.second<<" "<<MinY.second<<endl;

	//STOP GETTING CORDINATES

	//DRAW
	for(int i=0;i<n;i++)
	{
		Display[SOTD/2 - Map[i].second][SOTD/2 + Map[i].first] = '*';	
	}
	//END DRAWING

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