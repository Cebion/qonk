// Copyright 2005 by Anthony Liekens anthony@liekens.net

#include "coordinate.h"
#include "stars.h"
#include "canvas.h"

// ##### STAR METHODS #####

Star::Star() {
	c.setX( (double)rand() / RAND_MAX );
	c.setY( (double)rand() / RAND_MAX );
	brightness = rand() % ( 255 - 70 );
}

void
Star::render( ) const {
    Canvas::drawStar(c.getXMapped(), c.getYMapped(), brightness);
}

// ##### STARS METHODS #####

Stars::Stars() {
}

Stars::Stars( int n ) {
	addStars( n );
}

void
Stars::addStars( int n ) {
	for( int i = 0; i < n; i++ )
		push_back( Star() );
}

void 
Stars::render( ) const {
	for( const_iterator i = begin(); i != end(); i++ )
		i->render( );
}

