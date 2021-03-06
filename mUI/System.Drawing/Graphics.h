﻿/*
	Copyright 2011 hello.patz@gmail.com

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <System/System.h>
#include "SizeF.h"

namespace mUI{ namespace System{
	class String;
}}

namespace mUI{ namespace System{  namespace Drawing{

class Brush;
class Font;
class Image;
class Pen;
class Point;
class PointF;
class Rectangle;

class DRAWING_ENTRY Graphics
{
public:
	Graphics() {}
	virtual ~Graphics() {}

	virtual void DrawLine(const Pen& pen, const Point& pt1, const Point& pt2) = 0;
	virtual void DrawLine(const Pen& pen, int X1, int Y1, int X2, int Y2) = 0;

	virtual void FillRectangle(Brush& brush, const Rectangle& rect) = 0;
	virtual void FillRectangle(Brush& brush, int X, int Y, int Width, int Height) = 0;

	virtual void DrawRectangle(Pen& pen, const Rectangle& rect) = 0;
    virtual void DrawRectangle(Pen& pen, int X, int Y, int Width, int Height) = 0;

    virtual void DrawEllipse(Pen& pen, const Rectangle& rect) = 0;
    virtual void DrawEllipse(Pen& pen, int x, int y, int width, int height) = 0;

    virtual void FillEllipse(Brush& brush, const Rectangle& rect) = 0;
    virtual void FillEllipse(Brush& brush, int x, int y, int width, int height) = 0;

	virtual void DrawImage(const Image& image, Point pt) = 0;
	virtual void DrawImage(const Image& image, const Rectangle& rect) = 0;
	virtual void DrawImage(const Image& image, int X, int Y, int Width, int Height) = 0;

	virtual void SetClip(const Rectangle& rect) = 0;
	virtual void SetClip(int X, int Y, int Width, int Height) = 0;

	virtual void DrawString(const String& s, const Font& font, Brush& brush, const PointF& pt) = 0;

    virtual SizeF MeasureString(const String& text, const Font& font) = 0;

    // Non WinForm Graphics Interfaces.
    virtual void SetPixel(const Pen& pen, const Point& location) = 0;
    virtual void SetPixel(const Pen& pen, int x, int y) = 0;

private:
	Graphics(const Graphics&) {}
};

}}}

#endif // __GRAPHICS_H__
