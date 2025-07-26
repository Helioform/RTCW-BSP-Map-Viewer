#pragma once

#include <d3d11.h>


namespace Helios
{
	
		enum BUFFER_TYPE
		{
			VERTEX_BUFFER,
			INDEX_BUFFER,
			CONSTANT_BUFFER
		};

		enum RESOURCE_TYPE
		{
			CPU,
			GPU
		};

		enum CPU_ACCESS
		{
			NONE = 0,
			WRITE = D3D11_CPU_ACCESS_WRITE,
			READ = D3D11_CPU_ACCESS_READ
		};

		enum USAGE
		{
			DEFAULT = D3D11_USAGE_DEFAULT,
			IMMUTABLE = D3D11_USAGE_IMMUTABLE,
			DYNAMIC = D3D11_USAGE_DYNAMIC,
			STAGING = D3D11_USAGE_STAGING
		};

		struct BufferDesc
		{
			BUFFER_TYPE type;
			RESOURCE_TYPE resType;
			CPU_ACCESS cpuAccess;
			USAGE usage;
			UINT64 byteWidth;
		};

		struct BufferAccess
		{
			virtual void* GetData() = 0;

		};

	
		struct Buffer
		{
		
			virtual void* GetBuffer() = 0;
		};
}
