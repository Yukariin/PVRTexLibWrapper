#include "PVRTexLibWrapper.h"

#include <cstring>

#include <PVRTexture.h>
#include <PVRTextureUtilities.h>

using namespace pvrtexture;

extern bool DecompressPVR(const void* pTexture, void* out, size_t size)
{
    CPVRTexture cTexture(pTexture);
    PixelType PixelTypeBGRA('b','g','r','a',8,8,8,8);
    if (Transcode(cTexture, PixelTypeBGRA, ePVRTVarTypeUnsignedByteNorm, ePVRTCSpacelRGB))
    {
        void* data = cTexture.getDataPtr();
        memcpy(out, data, size);

        return true;
    }

    return false;
}
