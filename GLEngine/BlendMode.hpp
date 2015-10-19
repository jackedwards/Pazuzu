#ifndef BLENDMODE_HPP
#define BLENDMODE_HPP

struct BlendMode
{
	enum Factor
	{
		Zero,
		One,
		SrcColor,
		OneMinusSrcColor,
		DstColor,
		OneMinusDstColor,
		SrcAlpha,
		OneMinusSrcAlpha,
		DstAlpha,
		OneMinusDstAlpha
	};

	enum Equation
	{
		Add,
		Subtract
	};

	Factor m_colorSrcFactor;
    Factor m_colorDstFactor;
    Equation m_colorEquation;
    Factor m_alphaSrcFactor;
    Factor m_alphaDstFactor;
    Equation m_alphaEquation;

    static const BlendMode BlendAlpha;
    static const BlendMode BlendAdd;
    static const BlendMode BlendMultiply;
    static const BlendMode BlendNone;

	BlendMode();
	BlendMode(Factor sourceFactor, Factor destinationFactor, Equation blendEquation = Add);
	BlendMode(Factor colorSourceFactor, Factor colorDestinationFactor,
  			  Equation colorBlendEquation, Factor alphaSourceFactor,
  			  Factor alphaDestinationFactor, Equation alphaBlendEquation);
};

bool operator ==(const BlendMode& left, const BlendMode& right);
bool operator !=(const BlendMode& left, const BlendMode& right);

#endif
