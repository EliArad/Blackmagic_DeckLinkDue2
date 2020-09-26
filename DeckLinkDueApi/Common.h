#pragma once
#include <stdint.h>
#include "DeckLinkAPI_h.h"

typedef void(__stdcall * FrameCallback)(uint8_t *buffer, int width, int height, BMDPixelFormat pif);

typedef enum SURFACE_ENGINE
{

	OPENGL,
	DX9
} SURFACE_ENGINE;