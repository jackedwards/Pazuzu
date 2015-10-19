#include "BlendMode.hpp"

const BlendMode BlendMode::BlendAlpha(BlendMode::SrcAlpha, BlendMode::OneMinusSrcAlpha, BlendMode::Add,
                           			  BlendMode::One, BlendMode::OneMinusSrcAlpha, BlendMode::Add);
const BlendMode BlendMode::BlendAdd(BlendMode::SrcAlpha, BlendMode::One, BlendMode::Add,
                         			BlendMode::One, BlendMode::One, BlendMode::Add);
const BlendMode BlendMode::BlendMultiply(BlendMode::DstColor, BlendMode::Zero);
const BlendMode BlendMode::BlendNone(BlendMode::One, BlendMode::Zero);

BlendMode::BlendMode()
	: m_colorSrcFactor(BlendMode::SrcAlpha),
	  m_colorDstFactor(BlendMode::OneMinusSrcAlpha),
	  m_colorEquation(BlendMode::Add),
	  m_alphaSrcFactor(BlendMode::One),
	  m_alphaDstFactor(BlendMode::OneMinusSrcAlpha),
	  m_alphaEquation(BlendMode::Add)
{
	
}

BlendMode::BlendMode(Factor sourceFactor, Factor destinationFactor, Equation blendEquation)
	: m_colorSrcFactor(sourceFactor),
	  m_colorDstFactor(destinationFactor),
	  m_colorEquation(blendEquation),
	  m_alphaSrcFactor(sourceFactor),
	  m_alphaDstFactor(destinationFactor),
	  m_alphaEquation(blendEquation)
{

}

BlendMode::BlendMode(Factor colorSourceFactor, Factor colorDestinationFactor,
					 Equation colorBlendEquation, Factor alphaSourceFactor,
					 Factor alphaDestinationFactor, Equation alphaBlendEquation)
	: m_colorSrcFactor(colorSourceFactor),
	  m_colorDstFactor(colorDestinationFactor),
	  m_colorEquation(colorBlendEquation),
	  m_alphaSrcFactor(alphaSourceFactor),
	  m_alphaDstFactor(alphaDestinationFactor),
	  m_alphaEquation(alphaBlendEquation)
{

}

bool operator ==(const BlendMode& left, const BlendMode& right)
{
    return (left.m_colorSrcFactor == right.m_colorSrcFactor) &&
           (left.m_colorDstFactor == right.m_colorDstFactor) &&
           (left.m_colorEquation  == right.m_colorEquation)  &&
           (left.m_alphaSrcFactor == right.m_alphaSrcFactor) &&
           (left.m_alphaDstFactor == right.m_alphaDstFactor) &&
           (left.m_alphaEquation  == right.m_alphaEquation);
}

bool operator !=(const BlendMode& left, const BlendMode& right)
{
    return !(left == right);
}
