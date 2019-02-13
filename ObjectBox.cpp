#include "ObjectBox.h"



ObjectBox::ObjectBox()
{
}

ObjectBox::ObjectBox(Vector3 Position, float width, float height, float depth)
{
	Pos = Position;
	Width = width;
	Height = height;
	Depth = depth;
	xAxis = (1, 0, 0);
	yAxis = (0, 1, 0);
	zAxis = (0, 0, 1);
}

ObjectBox::~ObjectBox()
{
}

void ObjectBox::setOBB(Vector3 Position) //sets OBB when object moves
{
	Pos = Position;
}

bool ObjectBox::checkCollision(const ObjectBox A, const ObjectBox B)
{
	Vector3 T = B.Pos - A.Pos;

	return !(
		fabs(T.Dot(A.xAxis)) > (A.Width + fabs(B.Width * (A.xAxis.Dot(B.xAxis))) + fabs(B.Height * (A.xAxis.Dot(B.yAxis))) + fabs(B.Depth * (A.xAxis.Dot(B.zAxis)))) || //Case 1
		fabs(T.Dot(A.yAxis)) > (A.Height + fabs(B.Width * (A.yAxis.Dot(B.xAxis))) + fabs(B.Height * (A.yAxis.Dot(B.yAxis))) + fabs(B.Depth * (A.yAxis.Dot(B.zAxis))))||	//Case 2
		fabs(T.Dot(A.zAxis)) > (A.Depth + fabs(B.Width * (A.zAxis.Dot(B.xAxis))) + fabs(B.Height * (A.zAxis.Dot(B.yAxis))) + fabs(B.Depth * (A.zAxis.Dot(B.zAxis)))) ||	//Case 3
		fabs(T.Dot(B.xAxis)) > (B.Width + fabs(A.Width * (A.xAxis.Dot(B.xAxis))) + fabs(A.Height * (A.yAxis.Dot(B.xAxis))) + fabs(A.Depth * (A.zAxis.Dot(B.xAxis)))) ||	//Case 4
		fabs(T.Dot(B.yAxis)) > (B.Height + fabs(A.Width * (A.xAxis.Dot(B.yAxis))) + fabs(A.Height * (A.yAxis.Dot(B.yAxis))) + fabs(A.Depth * (A.zAxis.Dot(B.yAxis))))||	//Case 5
		fabs(T.Dot(B.zAxis)) > (B.Depth + fabs(A.Width * (A.xAxis.Dot(B.zAxis))) + fabs(A.Height * (A.yAxis.Dot(B.zAxis))) + fabs(A.Depth * (A.zAxis.Dot(B.zAxis)))) ||	//Case 6
		fabs(T.Dot(A.xAxis.Cross(B.xAxis))) > ( fabs(A.Height * (A.zAxis.Dot(B.xAxis))) + fabs(A.Depth * (A.yAxis.Dot(B.zAxis))) + fabs(B.Height * (A.xAxis.Dot(B.zAxis))) +  fabs(B.Depth * (A.xAxis.Dot(B.yAxis))) )||	//Case 7

		);
}