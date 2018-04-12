textures/lights/light_m4_white
{
    //off white KP light
    q3map_lightimage textures/lightimage/light_m4.blend.tga
    qer_editorimage textures/lights/light_m4.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m4.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m4.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m4
{
    //off white KP light
    q3map_lightimage textures/lightimage/light_m4.blend.tga

    qer_editorimage textures/lights/light_m4.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m4.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m4.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m5_red
{
    qer_editorimage textures/lights/light_m5.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m5.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m5.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m6_bwhite
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m6.blend.tga
    qer_editorimage textures/lights/light_m6.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m6.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m6.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

/// maxx low light //
textures/lights/light_m6_100
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m6.blend.tga
    qer_editorimage textures/lights/light_m6.tga
    q3map_surfacelight 100
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m6.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m6.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m9_white
{
    //off white KP light
    q3map_lightimage textures/lightimage/light_m9.blend.tga
    qer_editorimage textures/lights/light_m9.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m9.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m9.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/window_m02
{
    //q3map_lightimage textures/miltary_wall/window_m02.blend.tga
    qer_editorimage textures/miltary_wall/window_m02.tga
    q3map_surfacelight 200
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/miltary_wall/window_m02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/miltary_wall/window_m02.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c01_8k
{
    //bright white KP light
 //   q3map_lightimage textures/lights/light_c01.blend.tga

	q3map_lightimage textures/lightimage/light_c01_color.tga
    qer_editorimage textures/lights/light_c01.tga
    q3map_surfacelight 8000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c01.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c01_4k
{
    //bright white KP light
 //   q3map_lightimage textures/lights/light_c01.blend.tga

	q3map_lightimage textures/lightimage/light_c01_color.tga
    qer_editorimage textures/lights/light_c01.tga
    q3map_surfacelight 4000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c01.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c01_10k
{
    //bright white KP light
    //q3map_lightimage textures/lights/light_c01.blend.tga

	q3map_lightimage textures/lightimage/light_c01_color.tga
    qer_editorimage textures/lights/light_c01.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c01.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c01_10k_noblock
{
    //bright white KP light
   // q3map_lightimage textures/lights/light_c01.blend.tga

	q3map_lightimage textures/lightimage/light_c01_color.tga
    qer_editorimage textures/lights/light_c01.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    surfaceparm nonsolid
	surfaceparm trans
    surfaceparm noimpact
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c01.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c01_2k
{
    //bright white KP light
   // q3map_lightimage textures/lights/light_c01.blend.tga

	q3map_lightimage textures/lightimage/light_c01_color.tga
    qer_editorimage textures/lights/light_c01.tga
    q3map_surfacelight 2000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c01.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c01
{
    //bright white KP light
 //   q3map_lightimage textures/lights/light_c01.blend.tga

	q3map_lightimage textures/lightimage/light_c01_color.tga
    qer_editorimage textures/lights/light_c01.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c01.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c02
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c02.blend.tga
    qer_editorimage textures/lights/light_c02.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c02.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c02_10000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c02.blend.tga
    qer_editorimage textures/lights/light_c02.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c02.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c02_20000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c02.blend.tga
    qer_editorimage textures/lights/light_c02.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c02.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c03
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c03.blend.tga
    qer_editorimage textures/lights/light_c03.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c03.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c03.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c04
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c04.blend.tga
    qer_editorimage textures/lights/light_c04.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c04.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c04_5k
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c04.blend.tga
    qer_editorimage textures/lights/light_c04.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c04.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c04_10k
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c04.blend.tga
    qer_editorimage textures/lights/light_c04.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c04.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}


textures/lights/light_c04_nolight
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c04.blend.tga
    qer_editorimage textures/lights/light_c04.tga
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c04.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c04_10000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c04.blend.tga
    qer_editorimage textures/lights/light_c04.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c04.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c04_20000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c04.blend.tga
    qer_editorimage textures/lights/light_c04.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c04.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c05
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c05.blend.tga
    qer_editorimage textures/lights/light_c05.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c05.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c05.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c05_10000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c05.blend.tga
    qer_editorimage textures/lights/light_c05.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c05.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c05.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c05_20000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c05.blend.tga
    qer_editorimage textures/lights/light_c05.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c05.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c05.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c06
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c06.blend.tga
    qer_editorimage textures/lights/light_c06.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c06.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c06.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c06_10000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c06.blend.tga
    qer_editorimage textures/lights/light_c06.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c06.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c06.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c06_20000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c06.blend.tga
    qer_editorimage textures/lights/light_c06.tga
    q3map_surfacelight 20000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c06.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c06.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_c06_25000
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c06.blend.tga
    qer_editorimage textures/lights/light_c06.tga
    q3map_surfacelight 25000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c06.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c06.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}


textures/lights/light_m10_bwhite
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m10.blend.tga
    qer_editorimage textures/lights/light_m10.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m10.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m10.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m25r
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m25r.tga
    qer_editorimage textures/lights/light_m25r.tga
    q3map_surfacelight 8000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m25r.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m25r.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m25b
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_msb1.tga
    qer_editorimage textures/lights/light_m25b.tga
    q3map_surfacelight 8000
    light 1
    surfaceparm nomarks
	q3map_lightsubdivide 128
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m25b.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m25b.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m25b_2k
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_msb1.tga
    qer_editorimage textures/lights/light_m25b.tga
    q3map_surfacelight 2000
    light 1
    surfaceparm nomarks
	q3map_lightsubdivide 128	
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m25b.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m25b.tga
        blendFunc GL_ONE GL_ONE
    }
}

/// maxx test /////
textures/lights/light_m11_max
{
    //red KP light
    q3map_lightimage textures/lightimage/test.tga
    qer_editorimage textures/lights/light_m11.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m11.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m11.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m11_red
{
    //q3map_lightimage textures/lights/light_m11.blend.tga
    //red KP light
    qer_editorimage textures/lights/light_m11.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m11.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m11.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m12_small
{
    //small white KP light
    qer_editorimage textures/lights/light_m12.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m12.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m12.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/mlight_10k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/mlight_9k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 9000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/mlight_8k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 8000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/mlight_7k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 7000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/mlight_6k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/mlight_5k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m15_small
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m16_small
{
    //small white KP light
    qer_editorimage textures/lights/light_m16.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m16.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m16.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m17_small
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m17.blend.tga
    qer_editorimage textures/lights/light_m17.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m17.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m17.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

/// maxx ///
textures/lights/light_m20_5000
{
    qer_editorimage textures/lights/light_m20.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
}

textures/lights/light_m21_5000
{
    qer_editorimage textures/lights/light_m21.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m21.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m21.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

///
textures/lights/light_m18_small
{
    //small white KP light
    qer_editorimage textures/lights/light_m18.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m18.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m18.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m11_red_2500
{

    qer_editorimage textures/lights/light_m11.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m11.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m11.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Texture lighting experiment by Dave 02.04.00
textures/lights/light_test_250
{
    //surfaceparm nodraw
    q3map_lightimage textures/lightimage/light_test_250.tga
    qer_editorimage textures/lights/light_test_250.tga
    q3map_surfacelight 50
    light 1
    qer_trans 0.3
    surfaceparm nomarks
    surfaceparm nonsolid
    surfaceparm trans
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_test_250.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_test_250.tga
        blendFunc GL_ONE GL_ONE
    }
}

//test
textures/lights/light_test_temp
{
    //surfaceparm nodraw
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m10.blend.tga
    qer_editorimage textures/lights/light_m10.tga
    q3map_surfacelight 5000
    light 1
    qer_trans 0.3
    surfaceparm nomarks
    surfaceparm nonsolid
    surfaceparm trans
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m10.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m10.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_test_350
{
    //surfaceparm metalsteps
    ///surfaceparm nodraw
    q3map_surfacelight 1000
    cull disable
    {
        map textures/lights/light_test_350.tga
        alphaFunc GE128
        depthWrite
        rgbGen vertex
    }
}

//modified by rich feb 28 2000
textures/lights/mlight_30k
{
    //small white KP light
    q3map_lightimage textures/lightimage/light_m15.blend.tga
    qer_editorimage textures/lights/light_m15.tga
    q3map_surfacelight 30000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m15.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m15.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
textures/lights/light_m16_5k
{
    //small white KP light
    qer_editorimage textures/lights/light_m16.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m16.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m16.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
textures/lights/light_m16_10k
{
    //small white KP light
    qer_editorimage textures/lights/light_m16.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m16.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m16.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
textures/lights/light_m16_15k
{
    //small white KP light
    qer_editorimage textures/lights/light_m16.tga
    q3map_surfacelight 15000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m16.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m16.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
textures/lights/light_m16_20k
{
    //small white KP light
    qer_editorimage textures/lights/light_m16.tga
    q3map_surfacelight 20000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m16.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m16.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
textures/lights/light_xlight_750
{
    //small white KP light
    qer_editorimage textures/lights/light_xlight_01.tga
    q3map_surfacelight 750
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_01.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
//Sippy!
textures/lights/light_m21_fb
{
    //small white KP light
    qer_editorimage textures/lights/light_m21.tga
    q3map_surfacelight 1
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m20.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m20.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Sippy!
textures/lights/light_m20_fb
{
    qer_editorimage textures/lights/light_m20.tga
    q3map_surfacelight 1
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m20.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m20.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m30
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m30.tga
    qer_editorimage textures/lights/light_m30.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m30.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m30.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m30r
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_m30r.tga
    qer_editorimage textures/lights/light_m30r.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m30r.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m30r.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m31
{
    //cull twosided
    q3map_lightimage textures/lightimage/light_m31.tga
    q3map_surfacelight 5000
    light 1
    surfaceparm nomarks
    {
        map textures/lights/light_m31.tga
        blendFunc GL_ONE GL_ZERO
        rgbGen identity
    }
}

//Modified by Richard June 29/00
textures/lights/light_xlight_2500
{
    qer_editorimage textures/lights/light_xlight_02.tga
    q3map_surfacelight 2500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Modified by Mal Nov 9/00
textures/lights/light_xlight_4000
{
    qer_editorimage textures/lights/light_xlight_02.tga
    q3map_surfacelight 4000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_xlight_1500
{
    qer_editorimage textures/lights/light_xlight_02.tga
    q3map_surfacelight 1500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_xlight_700
{
    qer_editorimage textures/lights/light_xlight_02.tga
    q3map_surfacelight 700
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Modified by Mal Nov 27/00
textures/lights/light_xlight3_4000
{
    qer_editorimage textures/lights/light_xlight_03.tga
    q3map_surfacelight 4000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Modified by Mal Nov 11/00
textures/lights/light_xlight_5500
{
    qer_editorimage textures/lights/light_xlight_02.tga
    q3map_surfacelight 5500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

//Modified by Mal Nov 27/00
textures/lights/light_xlight3_5500
{
    qer_editorimage textures/lights/light_xlight_03.tga
    q3map_surfacelight 5500
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_xlight_02.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m5_red20k
{

    qer_editorimage textures/lights/light_m5.tga
    q3map_surfacelight 20000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_m5.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_m5.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_m1r
{
    nofog
    qer_editorimage textures/lights/light_m1r.tga
    surfaceparm nomarks
    {
        //Animmap .3 animMap 3 textures/lights/light_m1r textures/lights/light_m2r
        //blendFunc GL_ONE GL_ONE
        //rgbgen wave triangle .8 2 0 7
        //blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        animMap 1 textures/lights/light_m1r.tga textures/lights/light_m2r.tga 
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen identity
    }
}

textures/lights/light_tp_m01
{

    qer_editorimage textures/lights/light_tp_m01.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m02
{
    qer_editorimage textures/lights/light_tp_m02.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m03
{

    qer_editorimage textures/lights/light_tp_m03.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m03.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m04
{

    qer_editorimage textures/lights/light_tp_m04.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m05
{

    qer_editorimage textures/lights/light_tp_m05.tga
//  q3map_surfacelight 6000
//  light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m05.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m2.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m06
{

    qer_editorimage textures/lights/light_tp_m06.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m06.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m2.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m07
{
    //q3map_lightimage textures/lights/light_m5.blend.tga
    qer_editorimage textures/lights/light_tp_m07.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m07.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m2.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/lights/light_tp_m08
{
    //q3map_lightimage textures/lights/light_m5.blend.tga
    qer_editorimage textures/lights/light_tp_m08.tga
    q3map_surfacelight 6000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m08.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_tp_m2.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}
//Modified by claire november 25/00
//textures/lights/light_xlight_2500
//{
//   qer_editorimage textures/lights/light_xlight_03.tga
//    q3map_surfacelight 2500
//    light 1
//    surfaceparm nomarks
//    {
//        map $lightmap
//        rgbGen identity
//    }
//    {
//        map textures/lights/light_xlight_03.tga
//       blendFunc GL_DST_COLOR GL_ZERO
//        rgbGen identity
//    }
//    {
//        map textures/lights/light_xlight_03.tga
//        blendFunc GL_ONE GL_ONE
//    }
//}


textures/props/refer_light
{
   q3map_lightimage textures/lightimage/lgreen.tga
    //red KP light
    qer_editorimage textures/props/refer.tga
    q3map_surfacelight 150
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/props/refer.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/props/refer.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/props/light
{
   q3map_lightimage textures/lights/lgreen.tga
    //red KP light
    qer_editorimage textures/props/light.tga
    q3map_surfacelight 1000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/props/light.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/props/light.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/nxlab/xlab_fan
{
    //bright white KP light
    q3map_lightimage textures/lightimage/light_c02.blend.tga
    qer_editorimage textures/lights/light_c02.tga
    q3map_surfacelight 10000
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/lights/light_c02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/lights/light_c02.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}