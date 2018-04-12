textures/skies/pink_sky

{
	qer_editorimage textures/skies/pink_skym01.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 65 220 18
	q3map_surfacelight 30
	fogvars ( .13 .13 .14 ) .001
	skyfogvars ( .23 .23 .24 ) .5

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/pink_skym1.tga.tga
	//	tcMod scroll 0.002 0.002
		tcmod rotate 10
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/pink_skym2.tga.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}
