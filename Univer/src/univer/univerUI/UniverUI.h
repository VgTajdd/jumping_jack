// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// UniverUI.h                                                                //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"
#include "univer/core/UTypes.h"

namespace univer::ui
{
class UVR_API Control
{
public:
enum class TYPE
{
	LIST_BOX,
	TEXT,
	SLIDER_INT,
	SLIDER_FLOAT,
	COLOR_EDIT
};
public:
	TYPE type() const { return m_type; }
protected:
	Control( TYPE t ) : m_type( t ) {}
private:
	TYPE m_type;
};

class UVR_API ListBox : public Control
{
protected:
	ListBox() : Control( Control::TYPE::LIST_BOX ) {}
public:
	virtual void addItem( const char* item ) = 0;
	virtual void setSelectedIndex( const int index ) = 0;
	virtual int selectedIndex() const = 0;
};

class UVR_API Text : public Control
{
protected:
	Text() : Control( Control::TYPE::TEXT ) {}
public:
	virtual void setText( const char* text ) = 0;
};

class UVR_API SliderInt : public Control
{
protected:
	SliderInt() : Control( Control::TYPE::SLIDER_INT ) {}
public:
	virtual void setup( const char* label, int* value, int min, int max ) = 0;
	virtual const int currentValue() const = 0;
};

class UVR_API SliderFloat : public Control
{
protected:
	SliderFloat() : Control( Control::TYPE::SLIDER_FLOAT ) {}
public:
	virtual void setup( const char* label, float* value, float min, float max ) = 0;
	virtual void setLogarithmicScaleEnabled( bool enable ) = 0;
	virtual void setFormat( const char* format ) = 0;
	virtual const float currentValue() const = 0;
};

class UVR_API ColorEdit : public Control
{
protected:
	ColorEdit() : Control( Control::TYPE::COLOR_EDIT ) {}
public:
	virtual void setValue( UColor32* value ) = 0;
	virtual const UColor32& currentValue() const = 0;
};

class UVR_API Panel
{
public:
	virtual ListBox* createListBox( const char* name ) = 0;
	virtual Text* createText( const char* name ) = 0;
	virtual SliderInt* createSliderInt( const char* name ) = 0;
	virtual SliderFloat* createSliderFloat( const char* name ) = 0;
	virtual ColorEdit* createColorEdit( const char* name ) = 0;
	virtual void setAutoResizeEnabled( bool enable ) = 0;
	virtual bool autoResizeEnabled() const = 0;
};

class UVR_API UIManager
{
public:
	virtual Panel* createPanel( const char* name ) = 0;
};
}