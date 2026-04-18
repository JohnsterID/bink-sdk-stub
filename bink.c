/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Stub library containing subset of functions from binkw32.dll as used by the W3D engine.
 *
 * @copyright This is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            3 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "bink.h"
#include <stddef.h>
#include <string.h>

/*
 * All of these function definitions are empty, they are just hear to generate a dummy dll that
 * exports the same symbols as the real binkw32.dll so we can link against it without the commercial
 * SDK.
 */

BINK *__stdcall BinkOpen(const char *name, unsigned int flags)
{
    return NULL;
}

void __stdcall BinkSetSoundTrack(unsigned int total_tracks, unsigned int *tracks)
{
    
}

int __stdcall BinkSetSoundSystem(SndOpenCallback open, unsigned long param)
{
    return 0;
}

void *__stdcall BinkOpenDirectSound(unsigned long param)
{
    return NULL;
}

void __stdcall BinkClose(BINK *handle)
{
    
}

int __stdcall BinkWait(BINK *handle)
{
    return 0;
}

int __stdcall BinkDoFrame(BINK *handle)
{
    return 0;
}

int __stdcall BinkCopyToBuffer(
    BINK *handle, void *dest, int destpitch, unsigned int destheight, unsigned int destx, unsigned int desty, unsigned int flags)
{
    return 0;
}

void __stdcall BinkSetVolume(BINK *handle, unsigned int trackid, int volume)
{
    
}

void __stdcall BinkNextFrame(BINK *handle)
{
    
}

void __stdcall BinkGoto(BINK *handle, unsigned int frame, int flags)
{
    
}

/*
 * Civ5XP additional exports (52 functions).
 * Signatures derived from:
 * - Civ5XP ELF exported C-linkage symbols (62/62: full function names)
 * - IDA Pro decompilation of statically-linked Bink code (62/62: exact param counts/types)
 * - Bink SDK naming conventions and existing bink.h patterns
 */

/* Open/options */
BINK *__stdcall BinkOpenWithOptions(const char *name, unsigned int flags, int options)
{
    return NULL;
}

/* Frame control */
int __stdcall BinkDoFramePlane(BINK *handle, int plane)
{
    return 0;
}

int __stdcall BinkDoFrameAsync(BINK *handle, int thread_id, int flags)
{
    return 0;
}

int __stdcall BinkDoFrameAsyncMulti(BINK *handle, unsigned int *thread_ids, int count)
{
    return 0;
}

int __stdcall BinkDoFrameAsyncWait(BINK *handle, int timeout_ms)
{
    return 0;
}

int __stdcall BinkPause(BINK *handle, int onoff)
{
    return 0;
}

int __stdcall BinkService(BINK *handle)
{
    return 0;
}

int __stdcall BinkShouldSkip(BINK *handle)
{
    return 0;
}

int __stdcall BinkSetWillLoop(BINK *handle, int onoff)
{
    return 0;
}

int __stdcall BinkSetFrameRate(unsigned int frame_rate, unsigned int frame_rate_div)
{
    return 0;
}

int __stdcall BinkSetSimulate(unsigned int sim_speed)
{
    return 0;
}

int __stdcall BinkSetFileOffset(unsigned int offset, unsigned int type)
{
    return 0;
}

/* Frame buffers */
int __stdcall BinkAllocateFrameBuffers(BINK *handle, BINKFRAMEBUFFERS *fbset)
{
    return 0;
}

int __stdcall BinkRegisterFrameBuffers(BINK *handle, BINKFRAMEBUFFERS *fbset)
{
    return 0;
}

void __stdcall BinkGetFrameBuffersInfo(BINK *handle, BINKFRAMEBUFFERS *fbset)
{

}

int __stdcall BinkCopyToBufferRect(
    BINK *handle, void *dest, int destpitch, unsigned int destheight,
    unsigned int destx, unsigned int desty, unsigned int srcx, unsigned int srcy,
    unsigned int srcw, unsigned int srch, unsigned int flags)
{
    return 0;
}

int __stdcall BinkGetRects(BINK *handle, unsigned int flags)
{
    return 0;
}

unsigned int __stdcall BinkGetKeyFrame(BINK *handle, unsigned int frame, int flags)
{
    return 0;
}

/* Query */
void __stdcall BinkGetRealtime(BINK *handle, BINKREALTIME *rtime, unsigned int frame)
{

}

void __stdcall BinkGetSummary(BINK *handle, BINKSUMMARY *summary)
{

}

int __stdcall BinkGetPalette(BINK *handle)
{
    return 0;
}

int __stdcall BinkGetPlatformInfo(int sel, int data)
{
    return 0;
}

/* Sound */
int __stdcall BinkSetSoundSystem2(SndOpenCallback open, unsigned long param, unsigned long param2)
{
    return 0;
}

int __stdcall BinkSetSoundOnOff(BINK *handle, int onoff)
{
    return 0;
}

void __stdcall BinkSetPan(BINK *handle, unsigned int trackid, int pan)
{

}

int __stdcall BinkSetVideoOnOff(BINK *handle, int onoff)
{
    return 0;
}

void __stdcall BinkSetSpeakerVolumes(BINK *handle, unsigned int trackid, unsigned int *vol_array, unsigned int vol_array_size, unsigned int total_speakers)
{

}

/* Tracks */
void *__stdcall BinkOpenTrack(BINK *handle, unsigned int track_index)
{
    return NULL;
}

void *__stdcall BinkCloseTrack(void *track_handle)
{
    return NULL;
}

int __stdcall BinkGetTrackData(void *track_handle, void *dest)
{
    return 0;
}

int __stdcall BinkGetTrackID(BINK *handle, unsigned int track_index)
{
    return 0;
}

int __stdcall BinkGetTrackMaxSize(BINK *handle, unsigned int track_index)
{
    return 0;
}

int __stdcall BinkGetTrackType(BINK *handle, unsigned int track_index)
{
    return 0;
}

/* Async threads */
int __stdcall BinkStartAsyncThread(int thread_index)
{
    return 0;
}

int __stdcall BinkRequestStopAsyncThread(int thread_index)
{
    return 0;
}

int __stdcall BinkWaitStopAsyncThread(int thread_index)
{
    return 0;
}

/* I/O */
int __stdcall BinkSetIO(void *io_system)
{
    return 0;
}

int __stdcall BinkSetIOSize(unsigned int io_buffer_size)
{
    return 0;
}

int __stdcall BinkControlBackgroundIO(BINK *handle, int control)
{
    return 0;
}

/* Memory */
int __stdcall BinkSetMemory(void *(*alloc)(unsigned int), void (*free)(void *))
{
    return 0;
}

/* Error */
static char last_bink_error[256];

char *__stdcall BinkSetError(const char *error_string)
{
    if (error_string) {
        strncpy(last_bink_error, error_string, sizeof(last_bink_error) - 1);
        last_bink_error[sizeof(last_bink_error) - 1] = '\0';
    }
    return last_bink_error;
}

char *__stdcall BinkGetError(void)
{
    return last_bink_error;
}

/* System */
int __stdcall BinkFreeGlobals(void)
{
    return 0;
}

int __stdcall BinkControlPlatformFeatures(int use, int features)
{
    return 0;
}

int __stdcall BinkUseTelemetry(void *context)
{
    return 0;
}

int __stdcall BinkUseTmLite(void *context)
{
    return 0;
}

/* Bink texture compression (Granny integration) */
unsigned int __stdcall BinkTC_check_sizes(unsigned int *width, unsigned int *height)
{
    return 0;
}

/* Audio decompression API */
void *__stdcall BinkAudioDecompressOpen(void *output_buffer, unsigned int sample_rate, int channels, int flags)
{
    return NULL;
}

unsigned int __stdcall BinkAudioDecompressMemory(unsigned int sample_rate, int channels)
{
    return 0;
}

int __stdcall BinkAudioDecompressResetStartFrame(void *state)
{
    return 0;
}

void *__stdcall BinkAudioDecompress(void *state, void *dest, unsigned int *dest_len,
    int src_data, unsigned int *src_used, int src_len, int src_offset, unsigned int *skip_frames)
{
    return NULL;
}

int __stdcall BinkAudioDecompressOutputSize(void *state)
{
    return 0;
}

int __stdcall BinkAudioDecompressAllocatedSize(void *state)
{
    return 0;
}
