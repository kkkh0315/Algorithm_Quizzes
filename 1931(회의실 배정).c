#include <stdio.h>
#include <algorithm>

typedef struct TIME
{
	int start;
	int end;

}TIME;

TIME meetingtime[100000];

bool compare(TIME a, TIME b)
{
	if (a.end == b.end)
	{
		return a.start < b.start;
	}
	else
		return a.end < b.end;
}

int main(void)
{
	int meeting;

	scanf("%d", &meeting);
	if (meeting < 1 || meeting > 100000)
		return 0;
	

	for (int i = 0; i < meeting; ++i)
	{
		scanf("%d%d", &meetingtime[i].start, &meetingtime[i].end);
	}

	std::sort(meetingtime, meetingtime + meeting, compare);

	int i = 0;
	int min = 0 ;
	int answer = 0;
	
	
	for (i = 0; i < meeting; ++i)
	{
		if (min <= meetingtime[i].start)
		{
			min = meetingtime[i].end;
			++answer;
		}
	}

	printf("%d", answer);


	return 0;
}