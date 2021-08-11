// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CPosition.h                                                               //
// ========================================================================= //

#pragma once

#include "Component.h"

class CPosition : public Component
{
	ADD_PROPERTY( float, x )
	ADD_PROPERTY( float, y )
};
