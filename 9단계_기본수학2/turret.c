#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1, y1, r1, x2, y2, r2, t, res;
	double dis, rc;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d %d %d %d %d",&x1, &y1, &r1, &x2, &y2, &r2);
		dis = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		rc = r1 > r2 ? r1 - r2 : r2 - r1;
		if (dis == 0 && rc == 0)
			res = -1;
		else if (dis < r1 + r2 && rc < dis)
			res = 2;
		else if (dis == r1 + r2 || rc == dis)
			res = 1;
		else
			res = 0;
		printf("%d\n", res);
	}
	return (0);
}