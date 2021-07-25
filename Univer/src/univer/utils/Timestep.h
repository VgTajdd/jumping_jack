// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Timestep.h                                                                //
// ========================================================================= //

#ifndef TIMESTEP_H_
#define TIMESTEP_H_

namespace univer
{
class Timestep
{
public:
	Timestep( float time = 0.0f ) : m_time( time ) {}

	operator float() const { return m_time; }

	float seconds() const { return m_time; }
	float milliseconds() const { return m_time * 1000.0f; }

private:
	float m_time;
};
}

#endif // !TIMESTEP_H_