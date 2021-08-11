// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// JJWorld.h                                                                 //
// ========================================================================= //

#pragma once

#include "world/World.h"

namespace univer
{
class Text2D;
} // namespace univer

class JJWorld : public World
{
	static std::shared_ptr<JJWorld>& GetPrivate();

public:
	static const std::shared_ptr<JJWorld>& Get();

public:
	void setLifes( int lifes );
	void setScore( int score );

private:
	void init() override;
	void clear() override;
	void initializeTexts();

private:
	univer::Text2D* m_lifes;
	univer::Text2D* m_score;
};
