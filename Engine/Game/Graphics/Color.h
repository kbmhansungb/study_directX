#pragma once
typedef unsigned char BYTE;

/// <summary>
/// 칼라 클래스, BTYPE rgba, unsigned int color, float dds가 union으로 통합되어 있음.
/// 21.11.16
/// </summary>
class Color
{
public:
	union
	{
		BYTE rgba[4];
		unsigned int color;
		float dds;
	};

public:
	Color();
	Color(unsigned int val);
	Color(BYTE r, BYTE g, BYTE b);
	Color(BYTE r, BYTE g, BYTE b, BYTE a);
	// 복사생성자
	Color(const Color& src);
	// 대입연사자. 이름 오지게 복잡하다.
	Color& operator= (const Color& src);
	bool operator== (const Color& rhs) const;
	bool operator!= (const Color& rhs) const;

	constexpr BYTE GetR() const;
	void SetR(BYTE r);

	constexpr BYTE GetG() const;
	void SetG(BYTE g);

	constexpr BYTE GetB() const;
	void SetB(BYTE b);

	constexpr BYTE GetA() const;
	void SetA(BYTE a);
};

namespace texColors
{
	const Color UnloadedTextureColor(100, 100, 100);
	const Color UnhandledTextureColor(250, 0, 0);
}
