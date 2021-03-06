#pragma once
#include "d3dUtil.h"

class Model {
public:
	Model();
	~Model();

	inline ID3D11Buffer* IB() {
		return ib;
	}
	inline void SetIB( ID3D11Buffer* ib, UINT indexCount ) {
		this->ib = ib;
		this->indexCount = indexCount;
	}

	inline ID3D11Buffer* VB() {
		return vb;
	}
	inline void SetVB( ID3D11Buffer* vb ) {
		this->vb = vb;
	}

	inline UINT IndexCount() {
		return indexCount;
	}

	inline DXGI_FORMAT IndexFormat() {
		return indexFormat;
	}

	inline UINT VertexStride() {
		return vertexStride;
	}
	inline void SetVertexStride(UINT stride) {
		vertexStride = stride;
	}
	
	
private:
	ID3D11Buffer*	vb;
	ID3D11Buffer*	ib;
	UINT			indexCount;
	DXGI_FORMAT		indexFormat;
	UINT			vertexStride;
};

