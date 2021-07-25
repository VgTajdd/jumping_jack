// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// EmitterSettings.h                                                         //
// ========================================================================= //

#pragma once

#include "univer/core/UTypes.h"

namespace univer
{
struct UVR_API EmitterSettings
{
	float finalScaleFactor = 0.0f;
	float initialScaleFactor = 1.0f;
	UVec2 particleSize = { 10.0f, 10.0f };
	float emissionFrequency = 30.f;
	float emissionAngleMin = -75.f;
	float emissionAngleMax = -45.f;
	float lifeTime = 4000.f;
	float minSpeed = 0.05f;
	float maxSpeed = 0.2f;
	float acceleration = 0.f;
	bool useRotation = true;
	float minAngularSpeed = 0.1f;
	float maxAngularSpeed = 0.2f;
	float angularAcceleration = 0.f;
	UVec4 initialColor = { 1.0f, 0.0f, 0.0f, 1.0f };
	UVec4 finalColor = { 0.0f, 0.0f, 1.0f, 1.0f };
	float gravity = 0.0001f;
	const char* texture = "";
};
}