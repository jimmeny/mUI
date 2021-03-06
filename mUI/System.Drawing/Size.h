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

#ifndef __SIZE_H__
#define __SIZE_H__

#include "Export.h"

namespace mUI{ namespace System{ namespace Drawing{

class DRAWING_ENTRY Size
{
public:
	Size() : Width(0), Height(0) {}
	Size(int w, int h) : Width(w), Height(h) {}

	int Width;
	int Height;

	bool operator==(const Size& rhs) const
	{
		return Width == rhs.Width && Height == rhs.Height;
	}
	bool operator!=(const Size& rhs) const
	{
		return !(*this == rhs);
	}
	friend Size operator+(const Size& lhs, const Size& rhs)
	{
		return Size(lhs.Width + rhs.Width, lhs.Height + rhs.Height);
	}
	friend Size operator*(const Size& lhs, const Size& rhs)
	{
		return Size(lhs.Width * rhs.Width, lhs.Height * rhs.Height);
	}
	friend Size operator/(const Size& lhs, const Size& rhs)
	{
		return Size(lhs.Width / rhs.Width, lhs.Height / rhs.Height);
	}

	static const Size Empty;
};

}}}

#endif // __SIZE_H__
