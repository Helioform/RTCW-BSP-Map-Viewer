#pragma once
#include "../Math/Inc/DirectXMath.h"
#include "Components.h"
#include "CommonHeaders.h"

namespace Helios
{
	
		class Entity
		{
		

		public:
			Entity();
			

			virtual ~Entity() = default;

			template <typename T, typename... Args>
			void AddComponent(COMPONENT_TYPE t, Args&&...args )
			{
				m_components.emplace(t, std::make_unique<Component>(T{ std::forward<Args>(args)... }));
			}
			
			template <typename T>
			T GetComponent() {
				return nullptr;
			}

			inline void SetPosition(const XMVECTOR& p)
			{
				XMStoreFloat3(&m_position, p);
			}

			inline XMFLOAT3 GetPosition3f() const {
				return m_position;
			}

			inline XMVECTOR GetPosition() const {
				return DirectX::XMLoadFloat3(&m_position);
			}

			inline XMFLOAT3 GetRight3f() const
			{
				return m_right;
			}

			inline XMVECTOR GetRight() const {
				return DirectX::XMLoadFloat3(&m_right);
			}
			inline XMFLOAT3 GetUp3f() const
			{
				return m_up;
			}

			inline XMVECTOR GetUp() const
			{
				return DirectX::XMLoadFloat3(&m_up);
			}

			inline XMVECTOR GetForward() const
			{
				return DirectX::XMLoadFloat3(&m_forward);
			}

			inline XMFLOAT3 GetForward3f() const
			{
				return m_forward;
			}

			inline void SetUp(const XMVECTOR& up)
			{
				DirectX::XMStoreFloat3(&m_up, up);
			}

			inline void SetRight(const XMVECTOR& right)
			{
				DirectX::XMStoreFloat3(&m_right, right);
			}

			inline void SetForward(const XMVECTOR& forward)
			{
				DirectX::XMStoreFloat3(&m_forward, forward);
			}

			std::string GetTAG() {
				return tag;
			}

			XMMATRIX CreateRotationMatrixFromForward(const XMVECTOR& forward);
		
		protected:
			XMFLOAT3	m_right{ 0.0f,1.0f,0.0f };
			XMFLOAT3	m_up{ 0.0f,1.0f,0.0f }; 
			XMFLOAT3	m_forward { 0.0f,0.0f,1.0f };
			XMFLOAT3	m_position{ 0.0f, 0.0f, 0.0f };
			std::unordered_map<COMPONENT_TYPE, std::unique_ptr<Component>> m_components;
			std::string tag;
		};
}

