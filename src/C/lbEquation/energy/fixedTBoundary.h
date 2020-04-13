#ifndef FIXEDTBOUNDARY_H
#define FIXEDTBOUNDARY_H

#include <basicMesh.h>

void fixedTBoundary( basicMesh* mesh, scalar* field, scalar* T, scalar* U, char* bdname, scalar bdval );

#endif // FIXEDTBOUNDARY_H
