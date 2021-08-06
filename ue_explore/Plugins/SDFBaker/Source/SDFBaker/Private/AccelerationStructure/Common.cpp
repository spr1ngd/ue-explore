
#include "AccelerationStructure/Common.h"
#include "DrawDebugHelpers.h"
#pragma region box

bool S::FBox_2DSDF::IsValid()
{
	return this->extent.X > 0.0f && this->extent.Y > 0.0f;
}

void S::FBox_2DSDF::Split()
{
	//if (this->edges.Num() == 2) {
	//	FEdge_2DSDF* e0 = this->edges[0];
	//	FEdge_2DSDF* e1 = this->edges[1];

	//	if ((e0->xParallel && e1->xParallel) || (e0->yParallel && e1->yParallel)) {
	//		splitCenter = this->center;
	//	}
	//	else
	//	{
	//		if ((e0->xParallel || e0->yParallel) || (e1->xParallel || e1->yParallel)) {
	//			return;
	//		}
	//		splitCenter = this->edges[0]->end;
	//	}
	//}
	//else {
	//	splitCenter = this->center;
	//}
	FVector splitCenter = this->center;
	float xOffset = splitCenter.X - this->min.X;
	float yOffset = splitCenter.Y - this->min.Y;

	FBox_2DSDF* c00 = new FBox_2DSDF(this->min, splitCenter);
	FBox_2DSDF* c10 = new FBox_2DSDF(this->min + FVector(xOffset, 0, 0), FVector(this->max.X, splitCenter.Y, 0.0f));
	FBox_2DSDF* c01 = new FBox_2DSDF(this->min + FVector(0, yOffset, 0), FVector(splitCenter.X, this->max.Y, 0.0f));
	FBox_2DSDF* c11 = new FBox_2DSDF(splitCenter, this->max);

	c00->parent = this;
	c10->parent = this;
	c01->parent = this;
	c11->parent = this;

	this->children.Add(c00);
	this->children.Add(c10);
	this->children.Add(c01);
	this->children.Add(c11);
}

bool S::FBox_2DSDF::LineIntersection(FEdge_2DSDF* line)
{
	if (this->InsideBox(line->start))
		return true;
	if (this->InsideBox(line->end))
		return true;

	bool startOnEdge = this->OnBoxEdge(line->start);
	bool endOnEdge = this->OnBoxEdge(line->end);
	if (startOnEdge && endOnEdge)
		return true;

	FVector t0 = (min - line->start) / line->direction;
	FVector t1 = (max - line->start) / line->direction;
	FVector tmin = FVector(FMath::Min(t0.X, t1.X), FMath::Min(t0.Y, t1.Y), 0.0f);
	FVector tmax = FVector(FMath::Max(t0.X, t1.X), FMath::Max(t0.Y, t1.Y), 0.0f);
	float da = FMath::Max(tmin.X, tmin.Y);
	float db = FMath::Min(tmax.X, tmax.Y);
	bool intersection = da <= db && da >= 0.0f && db >= 0.0f;
	if (intersection) {
		/*if (startOnEdge && line->length >= db) {
			return true;
		}
		else if (endOnEdge && line->length >= da) {
			return true;
		}
		else{
			if (line->length >= da) {
				return true;
			}
		}*/
		return true;
	}
    // #因为交叉检测丢了一些边导致出现的情况
	return false;
}

bool S::FBox_2DSDF::InsideBox(FVector point)
{
	if (point.X > this->min.X && point.X < this->max.X && point.Y > this->min.Y && point.Y < this->max.Y)
		return true;
	return false;
}

bool S::FBox_2DSDF::OnBoxEdge(FVector point)
{
	if (
		((point.X == this->min.X || point.X == this->max.X) && (point.Y >= this->min.Y && point.Y <= this->max.Y)) ||
		((point.Y == this->min.Y || point.Y == this->max.Y) && (point.X >= this->min.X && point.X <= this->max.Y))
		)
		return true;
	return false;
}

float S::FBox_2DSDF::ShortestDistance(FVector sp)
{
	float minDist = FLT_MAX;
	for (FEdge_2DSDF* edge : this->edges) {
		float dist = edge->ShortestDistance(sp);
		minDist = FMath::Min(minDist, dist);
	}
	return minDist;
}

#pragma endregion box

S::FEdge_2DSDF::FEdge_2DSDF(FVector pStart, FVector pEnd)
{
	start = pStart;
	end = pEnd;
	edge = end - start;
	edge.ToDirectionAndLength(direction,length);

	/*xParallel = FVector::Parallel(direction, FVector::ForwardVector);
	yParallel = FVector::Parallel(direction, FVector::RightVector);*/
}

float S::FEdge_2DSDF::ShortestDistance(FVector sp)
{
	FVector ap = sp - start;
	FVector pab = ap - edge * FMath::Clamp(FVector::DotProduct(ap, edge) / FVector::DotProduct(edge, edge), 0.0f, 1.0f);
	float d = FMath::Sqrt(FVector::DotProduct(pab, pab));
	float sign = FVector::CrossProduct(direction, ap).Z >= 0.0f ? 1.0f : -1.0f;
	return d * sign;
}

float S::FEdge_2DSDF::ShortestDistance(FVector sp, FVector& intersection)
{
	FVector ap = sp - start;
	FVector pab = ap - edge * FMath::Clamp(FVector::DotProduct(ap, edge) / FVector::DotProduct(edge, edge), 0.0f, 1.0f);
	float d = FMath::Sqrt(FVector::DotProduct(pab, pab));
	float sign = FVector::CrossProduct(direction, ap).Z >= 0.0f ? 1.0f : -1.0f;
	intersection = sp - pab;
	return d * sign;
}
