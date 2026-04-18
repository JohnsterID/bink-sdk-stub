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
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#if !defined _MSC_VER
#if !defined(__stdcall)
#if defined __has_attribute && __has_attribute(stdcall)
#define __stdcall __attribute__((stdcall))
#else
#define __stdcall
#endif
#endif /* !defined __stdcall */
#endif /* !defined COMPILER_MSVC */

#ifdef BINKDLL
#define BINKEXPORT __declspec(dllexport)
#else
#define BINKEXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C" {
#endif

#define BINKSURFACE24 1
#define BINKSURFACE32 3
#define BINKSURFACE555 9
#define BINKSURFACE565 10
#define BINKPRELOADALL 0x00002000
#define BINKCOPYNOSCALING 0x70000000

typedef struct BINK
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Frames;
    unsigned int FrameNum;
    unsigned int LastFrameNum;
    unsigned int FrameRate;
    unsigned int FrameRateDiv;
    /* Original struct has more members, but we only need these to match the ABI*/
} BINK, *HBINK;

typedef void *(__stdcall *SndOpenCallback)(unsigned long param);
typedef unsigned int u32;

/*
 * Opaque struct types for frame buffer and summary queries.
 * The real Bink SDK defines these; we only access them through pointers.
 */
typedef struct BINKFRAMEBUFFERS BINKFRAMEBUFFERS;
typedef struct BINKRECT BINKRECT;
typedef struct BINKSUMMARY BINKSUMMARY;
typedef struct BINKREALTIME BINKREALTIME;

BINKEXPORT HBINK __stdcall BinkOpen(const char *name, unsigned int flags);
BINKEXPORT void __stdcall BinkSetSoundTrack(unsigned int total_tracks, unsigned int *tracks);
BINKEXPORT int __stdcall BinkSetSoundSystem(SndOpenCallback open, unsigned long param);
BINKEXPORT void *__stdcall BinkOpenDirectSound(unsigned long param);
BINKEXPORT void __stdcall BinkClose(HBINK handle);
BINKEXPORT int __stdcall BinkWait(HBINK handle);
BINKEXPORT int __stdcall BinkDoFrame(HBINK handle);
BINKEXPORT int __stdcall BinkCopyToBuffer(
    HBINK handle, void *dest, int destpitch, unsigned int destheight, unsigned int destx, unsigned int desty, unsigned int flags);
BINKEXPORT void __stdcall BinkSetVolume(HBINK handle, unsigned int trackid, int volume);
BINKEXPORT void __stdcall BinkNextFrame(HBINK handle);
BINKEXPORT void __stdcall BinkGoto(HBINK handle, unsigned int frame, int flags);

/*
 * Civ5XP additional exports (52 functions).
 * Bink is statically linked in both Windows and Linux Civ5XP builds (no DLL).
 * Signatures derived from:
 * - Civ5XP ELF exported C-linkage symbols (62/62: full function names)
 * - IDA Pro decompilation of statically-linked Bink code (62/62: exact param counts/types)
 * - Bink SDK naming conventions and existing bink.h patterns
 */

/* Open/options */
BINKEXPORT HBINK __stdcall BinkOpenWithOptions(const char *name, unsigned int flags, int options);

/* Frame control */
BINKEXPORT int __stdcall BinkDoFramePlane(HBINK handle, int plane);
BINKEXPORT int __stdcall BinkDoFrameAsync(HBINK handle, int thread_id, int flags);
BINKEXPORT int __stdcall BinkDoFrameAsyncMulti(HBINK handle, unsigned int *thread_ids, int count);
BINKEXPORT int __stdcall BinkDoFrameAsyncWait(HBINK handle, int timeout_ms);
BINKEXPORT int __stdcall BinkPause(HBINK handle, int onoff);
BINKEXPORT int __stdcall BinkService(HBINK handle);
BINKEXPORT int __stdcall BinkShouldSkip(HBINK handle);
BINKEXPORT int __stdcall BinkSetWillLoop(HBINK handle, int onoff);
BINKEXPORT int __stdcall BinkSetFrameRate(unsigned int frame_rate, unsigned int frame_rate_div);
BINKEXPORT int __stdcall BinkSetSimulate(unsigned int sim_speed);
BINKEXPORT int __stdcall BinkSetFileOffset(unsigned int offset, unsigned int type);

/* Frame buffers */
BINKEXPORT int __stdcall BinkAllocateFrameBuffers(HBINK handle, BINKFRAMEBUFFERS *fbset);
BINKEXPORT int __stdcall BinkRegisterFrameBuffers(HBINK handle, BINKFRAMEBUFFERS *fbset);
BINKEXPORT void __stdcall BinkGetFrameBuffersInfo(HBINK handle, BINKFRAMEBUFFERS *fbset);
BINKEXPORT int __stdcall BinkCopyToBufferRect(
    HBINK handle, void *dest, int destpitch, unsigned int destheight,
    unsigned int destx, unsigned int desty, unsigned int srcx, unsigned int srcy,
    unsigned int srcw, unsigned int srch, unsigned int flags);
BINKEXPORT int __stdcall BinkGetRects(HBINK handle, unsigned int flags);
BINKEXPORT unsigned int __stdcall BinkGetKeyFrame(HBINK handle, unsigned int frame, int flags);

/* Query */
BINKEXPORT void __stdcall BinkGetRealtime(HBINK handle, BINKREALTIME *rtime, unsigned int frame);
BINKEXPORT void __stdcall BinkGetSummary(HBINK handle, BINKSUMMARY *summary);
BINKEXPORT int __stdcall BinkGetPalette(HBINK handle);
BINKEXPORT int __stdcall BinkGetPlatformInfo(int sel, int data);

/* Sound */
BINKEXPORT int __stdcall BinkSetSoundSystem2(SndOpenCallback open, unsigned long param, unsigned long param2);
BINKEXPORT int __stdcall BinkSetSoundOnOff(HBINK handle, int onoff);
BINKEXPORT void __stdcall BinkSetPan(HBINK handle, unsigned int trackid, int pan);
BINKEXPORT int __stdcall BinkSetVideoOnOff(HBINK handle, int onoff);
BINKEXPORT void __stdcall BinkSetSpeakerVolumes(HBINK handle, unsigned int trackid, unsigned int *vol_array, unsigned int vol_array_size, unsigned int total_speakers);

/* Tracks */
BINKEXPORT void *__stdcall BinkOpenTrack(HBINK handle, unsigned int track_index);
BINKEXPORT void *__stdcall BinkCloseTrack(void *track_handle);
BINKEXPORT int __stdcall BinkGetTrackData(void *track_handle, void *dest);
BINKEXPORT int __stdcall BinkGetTrackID(HBINK handle, unsigned int track_index);
BINKEXPORT int __stdcall BinkGetTrackMaxSize(HBINK handle, unsigned int track_index);
BINKEXPORT int __stdcall BinkGetTrackType(HBINK handle, unsigned int track_index);

/* Async threads */
BINKEXPORT int __stdcall BinkStartAsyncThread(int thread_index);
BINKEXPORT int __stdcall BinkRequestStopAsyncThread(int thread_index);
BINKEXPORT int __stdcall BinkWaitStopAsyncThread(int thread_index);

/* I/O */
BINKEXPORT int __stdcall BinkSetIO(void *io_system);
BINKEXPORT int __stdcall BinkSetIOSize(unsigned int io_buffer_size);
BINKEXPORT int __stdcall BinkControlBackgroundIO(HBINK handle, int control);

/* Memory */
BINKEXPORT int __stdcall BinkSetMemory(void *(*alloc)(unsigned int), void (*free)(void *));

/* Error */
BINKEXPORT char *__stdcall BinkSetError(const char *error_string);
BINKEXPORT char *__stdcall BinkGetError(void);

/* System */
BINKEXPORT int __stdcall BinkFreeGlobals(void);
BINKEXPORT int __stdcall BinkControlPlatformFeatures(int use, int features);
BINKEXPORT int __stdcall BinkUseTelemetry(void *context);
BINKEXPORT int __stdcall BinkUseTmLite(void *context);

/* Bink texture compression (Granny integration) */
BINKEXPORT unsigned int __stdcall BinkTC_check_sizes(unsigned int *width, unsigned int *height);

/* Audio decompression API */
BINKEXPORT void *__stdcall BinkAudioDecompressOpen(void *output_buffer, unsigned int sample_rate, int channels, int flags);
BINKEXPORT unsigned int __stdcall BinkAudioDecompressMemory(unsigned int sample_rate, int channels);
BINKEXPORT int __stdcall BinkAudioDecompressResetStartFrame(void *state);
BINKEXPORT void *__stdcall BinkAudioDecompress(void *state, void *dest, unsigned int *dest_len,
    int src_data, unsigned int *src_used, int src_len, int src_offset, unsigned int *skip_frames);
BINKEXPORT int __stdcall BinkAudioDecompressOutputSize(void *state);
BINKEXPORT int __stdcall BinkAudioDecompressAllocatedSize(void *state);

#define BinkSoundUseDirectSound(x) BinkSetSoundSystem(BinkOpenDirectSound, (unsigned long)x)

#ifdef __cplusplus
} // extern "C"
#endif
