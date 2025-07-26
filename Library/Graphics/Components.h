#pragma once
#include "Entity.h"
#include "../Math/Inc/DirectXMath.h"
#include <string>

using namespace DirectX;

namespace Helios
{
	

		enum class COMPONENT_TYPE
		{
			ID,
			TAG,
			TRANSFORM
		};

		struct Component
		{
			COMPONENT_TYPE type;

			explicit Component(COMPONENT_TYPE _type) : type{ _type } {}
		};

		struct IDComponent : public Component
		{
			uint64_t m_ID;

			IDComponent() = default;
			explicit IDComponent(uint64_t id) : Component{ COMPONENT_TYPE::ID }, m_ID{ id }{}
		};

		struct TagComponent : Component
		{
			std::string m_tag;

			TagComponent() = default;
			TagComponent(std::string tag) : Component{ COMPONENT_TYPE::TAG }, m_tag{ tag } {}
		};

		struct TransformComponent : public Component
		{
			XMVECTOR location;
			XMVECTOR rotation;
			XMVECTOR scale;

			TransformComponent() = default;

			TransformComponent(XMFLOAT3& l, XMFLOAT3& r, XMFLOAT3& s) : Component{ COMPONENT_TYPE::TRANSFORM }, location{ 0.0f, 0.0f, 0.0f }, rotation{ 0.0f,0.0f,0.0f }, scale{ 1.0f, 1.0f, 1.0f }{}
		};

		struct LightComponent : public Component
		{
			XMFLOAT3 location;

		};

}