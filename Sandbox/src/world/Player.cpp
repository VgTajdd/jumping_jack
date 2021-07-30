#include "Player.h"

#include <univer/core/Log.h>
#include <univer/events/KeyEvent.h>

void Player::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	UVR_INFO( "code pressed: {0}", (int)e.GetKeyCode() );
}

void Player::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	UVR_INFO( "code released: {0}", (int)e.GetKeyCode() );
}
