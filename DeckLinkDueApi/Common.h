#pragma once
#include <stdint.h>

typedef void(__stdcall * FrameCallback)(uint8_t *buffer, int width, int height);