#pragma once

class oiContext;
class oiVolume;

struct oiConfig
{
    float scale_factor = 1.0f;
};

struct oiVolumeSummary
{
    int voxel_count = 0;
    int width = 0;
    int height = 0;
    int depth = 0;
    int format = 0;
    float min_value = 0;
    float max_value = 0;


    oiVolumeSummary() {}
    oiVolumeSummary(int c, int w, int h, int d, int f, float min, float max)
            : voxel_count(c),
              width(w),
              height(h),
              depth(d),
              format(f),
              min_value(min),
              max_value(max) {}
};

struct oiVolumeData
{
    void *voxels = nullptr;
};

openvdbiAPI void oiInitialize();
openvdbiAPI void oiUninitialize();

openvdbiAPI oiContext* oiContextCreate(int uid);
openvdbiAPI void oiContextSetConfig(oiContext* ctx, const oiConfig* config);
openvdbiAPI void oiContextDestroy(oiContext* ctx);
openvdbiAPI bool oiContextLoad(oiContext* ctx, const char *path);
openvdbiAPI oiVolume* oiContextGetVolume(oiContext* ctx);

openvdbiAPI void oiVolumeGetSummary(oiVolume* volume, oiVolumeSummary* dst);
openvdbiAPI void oiVolumeFillData(oiVolume* volume, oiVolumeData* dst);