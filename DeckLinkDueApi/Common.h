#pragma once
#include <stdint.h>
#include "DeckLinkAPI_h.h"


typedef void(__stdcall * FrameCallback)(uint8_t *buffer, int width, int height, BMDPixelFormat pif);

typedef enum SURFACE_ENGINE
{

	OPENGL,
	DX9
} SURFACE_ENGINE;


typedef enum DECKLINK2_DEVICES
{
	DEVICE1,
	DEVICE2,
	DEVICE3,
	DEVICE4,

} DECKLINK2_DEVICES;

#define RGBA_HD_SIZE (1920 * 1080 * 4)