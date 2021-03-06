#pragma once
#include <vector>
#include <map>
#include "d3dUtil.h"

#define MAX_BONE_COUNT 64

class AnimationController;

__declspec(align(16)) struct Bone {
	XMFLOAT4X4									offset;
	XMFLOAT4X4									localTransform;
	std::vector<Bone*>	children;
	int											idx;
	int											parentIdx;
	std::string									name;
};

class Skeleton {
public:
	Skeleton();
	~Skeleton();
	void SetRootTransform( XMFLOAT4X4& transform );
	void SetAnimationController( AnimationController* animController );
	XMFLOAT4X4* GetBoneTransforms();
	Bone* GetBoneByIndex( int index );
	Bone* GetBoneByName( std::string name );
	void AddBone( Bone* newBone );
	int BoneCount();
private:
	void UpdateTransforms( Bone* bone );
	XMFLOAT4X4*							rootTransform;
	XMFLOAT4X4							rootCorrection;
	int									numBones;
	std::map<int, Bone*>				idxBones;
	std::map<std::string, Bone*>		nameBones;
	XMFLOAT4X4							toRoot[MAX_BONE_COUNT];
	XMFLOAT4X4							finalTransformData[MAX_BONE_COUNT];
	AnimationController*				animationController;
};
