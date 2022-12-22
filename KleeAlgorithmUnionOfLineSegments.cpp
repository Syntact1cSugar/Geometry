#include <iostream>
#include <vector>
#include <algorithm>


bool compare(const std::pair<int, bool>& a, const std::pair<int, bool>& b)
{
	if(a.first == b.first)
	{
		return a.second == true;
	}
	else
	{
		return a.first < b.first;
	}
}
int SegmentsUnion(const std::vector<std::pair<int, int>>& segments)
{
	int n = (int)segments.size();
	int result = 0;
	
	//pair(x, y) = (point coordinate, isLeft)
	
	std::vector<std::pair<int, bool>> points;
	
	for(int i=0; i<n; ++i)
	{
		points.push_back({segments[i].first, true});
		points.push_back({segments[i].second, false});
	}
	std::sort(points.begin(), points.end(), compare);
	
	
	int segmentLength = 0;
	int count         = 0;
	
	for(int i=0; i<2 * n; ++i)
	{
		if(count > 0)
		{
			segmentLength += (points[i].first - points[i - 1].first);
		}
		
		//Set new count
		if(points[i].second)
		{
			++count;
		}
		else if(--count == 0)
		{
			std::cout << segmentLength << '\n';
			segmentLength = 0;
		}
	}
	
	return result;
	
}
int main()
{
	//pair(x, y) = (start, end) and start <= end
	std::vector<std::pair<int, int>> segments = {{2, 5}, {10, 23}, {10, 14}, {1, 5}, {6, 8}, {15, 20}};
	std::cout << SegmentsUnion(segments);
	return 0;
}
