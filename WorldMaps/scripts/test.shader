textures/test/flag_l_01a
{
        qer_editorimage textures/test/flag_l_01.tga

	tessSize 64
	deformVertexes wave 100 sin 4 3 0 0.3
        //deformVertexes wave 194 sin 0 3 0 .4
        //deformVertexes wave 30 sin 0 3 0 .8
        //deformVertexes wave 194 sin 0 3 0 .4
        //deformVertexes wave 300 sin 0 4 0 .1
        surfaceparm nomarks
        cull none
        
	{
		map textures/test/flag_l_01.tga
		blendFunc GL_ONE GL_ZERO
		//alphaFunc GE128
		//depthWrite
		rgbGen identity
	}
        {
		map $lightmap
                blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	

}

textures/test/flag_l_01malytest
{
        qer_editorimage textures/test/flag_l_01.tga

	tessSize 64
	//deformVertexes wave 100 sin 4 3 0 0.3
        //deformVertexes wave 194 sin 0 3 0 .4
        deformVertexes wave 10 sin 0 2 0 .2
        //deformVertexes wave 194 sin 0 3 0 .4
        //deformVertexes wave 300 sin 0 4 0 .1
        surfaceparm nomarks
        cull none
        
	{
		map textures/test/flag_l_01.tga
		blendFunc GL_ONE GL_ZERO
		//alphaFunc GE128
		//depthWrite
		rgbGen identity
	}
        {
		map $lightmap
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	

}

textures/test/flag_l_01clairetest
{
        qer_editorimage textures/test/flag_l_01.tga

	tessSize 64
	//deformVertexes wave 100 sin 4 3 0 0.3
        //deformVertexes wave 194 sin 0 3 0 .4
        deformVertexes wave 10 sin 0 2 0 .2
        //deformVertexes wave 194 sin 0 3 0 .4
        //deformVertexes wave 300 sin 0 4 0 .1
        surfaceparm nomarks
        cull none
        
	{ 
		map textures/test/flag_l_01.tga
		blendFunc GL_ONE GL_ZERO
		//alphaFunc GE128
		//depthWrite
		rgbGen identity
	}
        {
		map $lightmap
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	

}

textures/ctf/ctf_blueflag
{
        tessSize 64
	//deformVertexes wave 100 sin 4 3 0 0.3
       deformVertexes wave 194 sin 0 3 0 .4
        //deformVertexes wave 30 sin 0 3 0 .8
        //deformVertexes wave 194 sin 0 3 0 .4
        //deformVertexes wave 300 sin 0 4 0 .1
        surfaceparm nomarks
        cull none
        
        {
		map textures/ctf/ctf_blueflag.tga
		rgbGen identity
	}
        {
		map textures/effects/redflagmap.tga
                tcGen environment
                tcmod scale 9 3
                tcmod scroll .1 .7
                
                blendFunc GL_ONE GL_ONE
                rgbGen identity
	}
        {
		map textures/ctf/ctf_blueflag.tga
                blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen identity
	}
        {
		map $lightmap
                blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}
textures/ctf/ctf_redflag
{
        tessSize 64
	//deformVertexes wave 100 sin 4 3 0 0.3
        deformVertexes wave 194 sin 0 3 0 .4
       // deformVertexes wave 30 sin 0 3 0 .8
        //deformVertexes wave 194 sin 0 3 0 .4
       // deformVertexes wave 300 sin 0 4 0 .1
        surfaceparm nomarks
        cull none
        {
		map textures/ctf/ctf_redflag.tga
		rgbGen identity
	}
        {
		map textures/effects/blueflagmap.tga
                 tcGen environment
                tcmod scale 9 3
                tcmod scroll .1 .7
                
                blendFunc GL_ONE GL_ONE
                rgbGen identity
	}
        {
		map textures/ctf/ctf_redflag.tga
                blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen identity
	}
        {
		map $lightmap
                blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}
powerups/redflag
{
	deformVertexes wave 100 sin 3 0 0 0
	{
		map textures/effects/redflagmap.tga
		blendfunc GL_ONE GL_ONE
		tcGen environment
		tcMod turb 0 0.2 0 1
	}
}

powerups/blueflag
{
	deformVertexes wave 100 sin 3 0 0 0
	{
		map textures/effects/blueflagmap.tga
		blendfunc GL_ONE GL_ONE
		tcGen environment
		tcMod turb 0 0.2 0 1
	}
}

sprites/friend
{
	nomipmaps
	nopicmip
	{
		map sprites/friend1.tga
		blendfunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
}

sprites/foe
{
	nomipmaps
	nopicmip
	{
		map sprites/foe2.tga
		blendfunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
}

textures/test/pjgrate1
{
	surfaceparm	metalsteps		
	cull none

	// A GRATE OR GRILL THAT CAN BE SEEN FROM BOTH SIDES
	{
		map textures/test/pjgrate1.tga
		tcMod scale 2 2
		blendFunc GL_ONE GL_ZERO
		alphaFunc GE128
		depthWrite
		rgbGen identity
	}
	{
		map $lightmap
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO
		depthFunc equal
	}
}




///////// 
////////
///////
//
// Sherman testing
//


textures/test/soloflare1
{
	qer_editorimage textures/test/soloflare1.tga
	q3map_surfacelight 5000
//	q3map_flare flareShader
	surfaceparm nomarks
	{
		map $lightmap
		rgbGen identity
	}
    {
		map textures/sfx/firegorre.tga
			blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
			tcmod scale  -1.3 -1
			tcMod scroll 2 0
	}
}


textures/test/shermflare
{
	deformVertexes autoSprite
//	deformVertexes move 0 0 3   sin 0 5 0 0.1
//	deformVertexes move 2 2 0   sin 0 9 0 0.05
	surfaceparm	trans
	surfaceparm nomarks
	surfaceparm nolightmap
	cull none
	{
		clampmap gfx/misc/flare.tga
		blendFunc GL_ONE GL_ONE
		tcMod rotate 20
	}
}


textures/test/solo_group1
{
	q3map_smoothinggroup 1		// set the group

//	qer_editorimage textures/test/shermtest1.tga
	qer_editorimage textures/test/grnwall_m01a.tga

	{
		map textures/test/grnwall_m01a.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/test/solo_group2
{
	q3map_smoothinggroup 2		// set the group

	qer_editorimage textures/test/grnwall_m01a.tga

	{
		map textures/test/grnwall_m01a.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/test/solo_shiny1
{
	{
		map textures/base_wall/chrome_env.tga
		tcgen environment
		tcmod scale .25 .25 
		rgbgen identity      
	}

	{
		map textures/base_wall/shinybluemetal1.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
		//alphaGen lightingSpecular
	}
	
	{	
		map $lightmap
		blendfunc gl_dst_color gl_zero
		rgbgen identity      
	}


				
}


models/weapons2/lightning/f_lightning
{
	sort additive
	cull disable
	{
		map models/weapons2/flamethrower/flash.tga
		blendfunc GL_ONE GL_ONE
	}
}

models/weapons2/lightning/crackle1
{
	sort additive
	cull disable
	
	{
		clampmap models/weapons2/flamethrower/pilot.tga
		tcMod rotate 16
		blendFunc GL_ONE GL_ONE
	}
		
}

textures/skies/solosky1
{
	qer_editorimage textures/skies/toxicsky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 256
	q3map_surfacelight 400
	surfaceparm sky
	q3map_sun	1 1 0.5 150 30 60
	skyparms full 512 -
	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}

//\\
//\\ end Sherman testing
//\\
//\\\\\\\
//\\\\\\\\
//\\\\\\\\\ 
