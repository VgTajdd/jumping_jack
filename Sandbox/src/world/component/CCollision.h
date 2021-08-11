// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CCollision.h                                                              //
// ========================================================================= //

#pragma once

#include "Component.h"

#include <univer/core/URectangle.h>

class CCollision : public Component
{
	ADD_PROPERTY( univer::URectangle, bounds )
};
