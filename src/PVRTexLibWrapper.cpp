#include "PVRTexLibWrapper.h"

#include <cstring>

#include <PVRTexture.h>
#include <PVRTextureUtilities.h>

using namespace pvrtexture;

extern bool DecompressPVR(const void* pTexture, void* out)
{
    CPVRTexture cTexture(pTexture);
    PixelType PixelTypeBGRA('b','g','r','a',8,8,8,8);
    if (Transcode(cTexture, PixelTypeBGRA, ePVRTVarTypeUnsignedByteNorm, ePVRTCSpacelRGB))
    {
        void* data = cTexture.getDataPtr();
        int h = cTexture.getHeader().getHeight();
        int w = cTexture.getHeader().getWidth();
        memcpy(out, data, h*w*4);

        return true;
    }

    return false;
}
