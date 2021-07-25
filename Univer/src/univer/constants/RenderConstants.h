// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// RenderConstants.h                                                         //
// ========================================================================= //

#pragma once

#include "univer/core/UTypes.h"

namespace univer
{
// Quad vertex positions.
struct QVP
{
	UVec4 v1 = { 0.0f, 0.0f, 0.0f, 1.0f };
	UVec4 v2 = { 1.0f, 0.0f, 0.0f, 1.0f };
	UVec4 v3 = { 1.0f, 1.0f, 0.0f, 1.0f };
	UVec4 v4 = { 0.0f, 1.0f, 0.0f, 1.0f };
};

// Quad vertex texture coordinates.
struct QVTC
{
	UVec2 v1 = { 0.0f,  0.0f };
	UVec2 v2 = { 1.0f,  0.0f };
	UVec2 v3 = { 1.0f,  1.0f };
	UVec2 v4 = { 0.0f,  1.0f };
};

static QVP qvp;
static QVTC qvtc;

}