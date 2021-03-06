#pragma once

#include "_Buffer.h"

#pragma message (__FILE__ "(" _CRT_STRINGIZE(__LINE__) ")" ": warning: 현재로서는 사용하지 않음")

/// <summary>
/// 스트림 버퍼
/// 21.11.16
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class StreamBuffer
{
	Microsoft::WRL::ComPtr<ID3D11Buffer> buffer;
	StreamBuffer(const ConstantBuffer<T>& rhs) = delete;
public:
	StreamBuffer() {}
	ID3D11Buffer* Get() const
	{
		return buffer.Get();
	}
	ID3D11Buffer* const* GetAddressOf() const
	{
		return buffer.GetAddressOf();
	}
	void initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
	{
		if (this->buffer.Get() != nullptr) this->buffer.Reset();

		int m_nBufferSize = 1000000;
		D3D11_BUFFER_DESC bufferDesc =
		{
			m_nBufferSize,
			D3D11_USAGE_DEFAULT,
			D3D11_BIND_VERTEX_BUFFER | D3D11_BIND_STREAM_OUTPUT,
			0,
			0,
			0
		};
		device->CreateBuffer(&bufferDesc, NULL, buffer.GetAddressOf());
	}
};