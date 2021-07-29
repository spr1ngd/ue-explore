
#include "MathLibrary.h"

void S::FMathLibrary::Convex(TArray<FVector> points, FVector pn)
{
	// 将所有点从法线为pn的平面旋转至xy平面FVector(0,0,1)
	// 求出y的最大值和最小值
	// 采用分治算法求出

	FVector stdN = FVector(0, 0, 1);
	
}
