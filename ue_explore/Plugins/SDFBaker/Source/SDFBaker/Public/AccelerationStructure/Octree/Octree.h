
// author : spr1ngd 
// desc   : acceleration structure for signed distance field baker

#pragma once

namespace S
{
	class Octree 
	{

	};

	class OctreeNode 
	{
	public:
		bool bLeaf = false;
		OctreeNode* children;
	};
}
