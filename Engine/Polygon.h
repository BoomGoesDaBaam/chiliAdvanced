#include <vector>
#include "Rect.h"
#include "Graphics.h"
#include <cassert>
#include <iostream>
class P0lygon
{
	std::vector<Vec2> points;
public:
	P0lygon(){points = { Vec2(-50, -50), Vec2(-50, 50), Vec2(50, 50), Vec2(50, -50) };};
	P0lygon(std::vector<Vec2> points):points(points) {};
	void Draw(Graphics& gfx, Color c,Vei2 pos)
	{
		assert(points.size() >= 2);
		for (int i = 0; i < points.size() - 1; i++)
		{
			gfx.DrawLine(points[i]+(Vec2)pos, points[(__int64)(i + 1)] + (Vec2)pos, c,1);
		}
		gfx.DrawLine(points[points.size() - 1] + (Vec2)pos, points[0] + (Vec2)pos, c);
	};
	static std::vector<Vec2> MakeStar(float outerRadius, float innerRadius, int nFlares = 5)
	{
		std::vector<Vec2> star;
		star.reserve(nFlares * 2);
		const float dTheta = 2.0f * 3.14159f / float(nFlares * 2);
		for (int i = 0; i < nFlares * 2; i++)
		{
			const float rad = (i % 2 == 0) ? outerRadius : innerRadius;
			star.emplace_back(
				rad * cos(float(i) * dTheta),
				rad * sin(float(i) * dTheta)
			);
		}
		return star;
	}
};