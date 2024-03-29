#include "RectF.h"

RectF::RectF( float left_in,float right_in,float top_in,float bottom_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottom( bottom_in )
{
}

RectF::RectF( const Vec2& topLeft,const Vec2 & bottomRight )
	:
	RectF( topLeft.x,bottomRight.x,topLeft.y,bottomRight.y )
{
}

RectF::RectF( const Vec2& topLeft,float width,float height )
	:
	RectF( topLeft,topLeft + Vec2( width,height ) )
{
}

bool RectF::IsOverlappingWith( const RectF& other ) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

bool RectF::IsContainedBy( const RectF & other ) const
{
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

RectF RectF::FromCenter( const Vec2 & center,float halfWidth,float halfHeight )
{
	const Vec2 half( halfWidth,halfHeight );
	return RectF( center - half,center + half );
}

RectF RectF::GetExpanded( float offset ) const
{
	return RectF( left - offset,right + offset,top - offset,bottom + offset );
}

Vec2 RectF::GetCenter() const
{
	return Vec2( (left + right) / 2.0f,(top + bottom) / 2.0f );
}
