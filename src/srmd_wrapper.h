//
// Created by archiemeng on 12/4/21.
//

#ifndef SRMD_NCNN_VULKAN_SRMD_WRAPPED_H
#define SRMD_NCNN_VULKAN_SRMD_WRAPPED_H
#include "srmd.h"

// wrapper class of ncnn::Mat
typedef struct Image{
    unsigned char *data;
    int w;
    int h;
    int elempack;
    Image(unsigned char *d, int w, int h, int channels) {
        this->data = d;
        this->w = w;
        this->h = h;
        this->elempack = channels;
    }
} Image;

union StringType {
    std::string *str;
    std::wstring *wstr;
};

class SRMDWrapper : public SRMD {
public:
    SRMDWrapper(int gpuid, bool tta_mode = false);
    int load(const StringType &parampath, const StringType &modelpath);
    int process(const Image &inimage, Image &outimage) const;
};

int get_gpu_count();
uint32_t  get_heap_budget(int gpuid);
#endif //SRMD_NCNN_VULKAN_SRMD_WRAPPED_H
