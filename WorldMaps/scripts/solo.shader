textures/castle_wall/escape1_entry
{
	{
//		map $lightmap
		map textures/castle_wall/escape1_entry.tga
//		map $whiteimage
		blendFunc GL_SRC_COLOR GL_ZERO
//		tcmod rotate 90
		tcMod scale .02343 .02343
		rgbGen identity
	}

	{
		map textures/castle_wall/castle_c46_a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		tcMod scale .046 .046
		rgbGen identity
	}
}

sunflare1
{
	cull none
	{
		map gfx/misc/sunflare1.tga
		blendFunc GL_ONE GL_ONE
		rgbGen vertex
	}
}


targetEffectExplode
{
	nofog
	cull disable
	{
		animmap 8 models/weaphits/rlboom/rlboom_1.tga  models/weaphits/rlboom/rlboom_2.tga models/weaphits/rlboom/rlboom_3.tga models/weaphits/rlboom/rlboom_4.tga models/weaphits/rlboom/rlboom_5.tga models/weaphits/rlboom/rlboom_6.tga models/weaphits/rlboom/rlboom_7.tga models/weaphits/rlboom/rlboom_8.tga
		rgbGen wave inversesawtooth 0 1 0 8
		blendfunc add
	}
	{
		animmap 8 models/weaphits/rlboom/rlboom_2.tga models/weaphits/rlboom/rlboom_3.tga models/weaphits/rlboom/rlboom_4.tga models/weaphits/rlboom/rlboom_5.tga models/weaphits/rlboom/rlboom_6.tga models/weaphits/rlboom/rlboom_7.tga models/weaphits/rlboom/rlboom_8.tga gfx/colors/black.tga
		rgbGen wave sawtooth 0 1 0 8
		blendfunc add
	}
}





textures/skies/falling_bgsky
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
	q3map_surfacelight 90
	fogvars ( .1 .1 .1 ) 3000

	skyparms full 200 -
	{
		map textures/skies/sky_falling.tga
//		tcMod scroll 0.0005 0.0005
//		tcMod scale 12.0 12.0
		depthWrite
	}
}

textures/skies/falling_stopped
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	{
		map textures/skies/sky_falling.tga
	}
}

textures/skies/falling_fast
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	{
		map textures/skies/sky_falling.tga
		tcMod scroll 0 0.1
	}
	{
		map textures/skies/sky_falling.tga
//		tcMod scroll 0 3.3
		tcMod scroll 0 1.3
		tcmod scale .5 1
		blendFunc blend
	}
}

textures/skies/falling_fast_turn
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	{
		map textures/skies/sky_falling.tga
		tcMod scroll 0.1 0.1
	}
	{
		map textures/skies/sky_falling.tga
		tcMod scroll 0 3.3
		tcmod scale .5 1
		blendFunc blend
	}
}

textures/skies/falling_slow
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	{
		map textures/skies/sky_falling.tga
		tcMod scroll 0 0.03
	}
}



textures/skies/falling_horizcloud
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	deformVertexes move 0 0 1400 sawtooth -400 2 0 .5
	{
		map textures/skies/sky_falling.tga
//		blendFunc blend
		blendFunc GL_SRC_ALPHA GL_ONE
	}
}


textures/skies/falling_horiz
{
	qer_editorimage textures/skies/sky_falling
	surfaceparm noimpact
	surfaceparm nolightmap
	{
		map textures/skies/sky_falling.tga
		tcMod scroll -0.1 0
	}
	{
		map textures/skies/sky_falling.tga
		tcMod scroll -1.3 0
		tcmod scale 1 .5
		blendFunc blend
	}
}


models/weapons2/tesla/base_tesla4_L
{
	cull none
	{
		// play this one out of sync with the other, so you don't see any cycling

		animmap 4 models/weapons2/tesla/base_tesla4_L3.tga models/weapons2/tesla/base_tesla4_L2.tga models/weapons2/tesla/base_tesla4_L.tga
		alphaGen	wave inversesawtooth 0 1 0 4
		blendFunc blend
//		rgbGen lightingdiffuse
		rgbgen	identity
	}

	{
		animmap 3 models/weapons2/tesla/base_tesla4_L.tga models/weapons2/tesla/base_tesla4_L2.tga models/weapons2/tesla/base_tesla4_L3.tga
		alphaGen	wave inversesawtooth 0 1 0.25 3
		blendFunc blend
//		rgbGen lightingdiffuse
		rgbgen	identity
	}
}









watersplash_test1
{
	cull disable
	{
		animmap 5 models/weaphits/splash1.tga  models/weaphits/splash2.tga  models/weaphits/splash3.tga gfx/colors/ablack.tga
		rgbGen wave inversesawtooth 0 1 0 5
//		blendfunc add
		blendfunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	}
	{
		animmap 5 models/weaphits/splash2.tga  models/weaphits/splash3.tga  gfx/colors/ablack.tga gfx/colors/ablack.tga
		rgbGen wave sawtooth 0 1 0 5
//		blendfunc add
		blendfunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	}
}


watersplash_almost
{
	cull disable
	{
		animmap 12 models/weaphits/splash2_1.tga  models/weaphits/splash2_2.tga  models/weaphits/splash2_3.tga models/weaphits/splash2_4.tga gfx/colors/ablack.tga
		alphaGen wave inversesawtooth 0 1 0 12
		blendfunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
	{
		animmap 12 models/weaphits/splash2_2.tga  models/weaphits/splash2_3.tga  models/weaphits/splash2_4.tga  gfx/colors/ablack.tga gfx/colors/ablack.tga
		rgbGen wave sawtooth 0 1 0 12
		blendfunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
}

watersplash
{
	cull disable
	{
		animmap 20 models/weaphits/splash2_1.tga  models/weaphits/splash2_2.tga  models/weaphits/splash2_3.tga models/weaphits/splash2_4.tga gfx/colors/ablack.tga
		alphaGen wave inversesawtooth 0 1 0 4
		blendfunc blend
	}
}


//----(SA)	
// applied to the water splash model when bullets go into the water

waterSplash_test3
{
	cull disable
	{
		animmap 10 models/weaphits/splash1.tga  models/weaphits/splash2.tga  models/weaphits/splash3.tga models/weaphits/splash4.tga
//		rgbGen identity
//		alphagen wave inversesawtooth 0 1 0 10
///		blendfunc blend
		blendfunc GL_ONE GL_SRC_ALPHA
	}
//	{
//		animmap 10  models/weaphits/splash2.tga  models/weaphits/splash3.tga  models/weaphits/splash4.tga  gfx/colors/ablack.tga
///		rgbGen identity
///		alphaGen wave sawtooth 0 1 0 10
////		blendfunc blend
//		blendfunc GL_ONE GL_SRC_ALPHA
//	}
}


waterSplash_test2
{
	cull disable
	{
		animmap 10 models/weaphits/splash2_1.tga  models/weaphits/splash2_2.tga  models/weaphits/splash2_3.tga models/weaphits/splash2_4.tga
		blendfunc GL_SRC_ALPHA GL_ZERO
	}
}



waterSplash_straight
{
	cull disable
	{
		animmap 4 models/weaphits/splash1.tga  models/weaphits/splash2.tga  models/weaphits/splash3.tga models/weaphits/splash4.tga
		blendfunc blend
	}
}








bulletExplosion
{
	cull disable
	{
		animmap 5 models/weaphits/bullet1.tga  models/weaphits/bullet2.tga  models/weaphits/bullet3.tga gfx/colors/black.tga
		rgbGen wave inversesawtooth 0 1 0 5
		blendfunc add
	}
	{
		animmap 5 models/weaphits/bullet2.tga  models/weaphits/bullet3.tga  gfx/colors/black.tga gfx/colors/black.tga
		rgbGen wave sawtooth 0 1 0 5
		blendfunc add
	}
}




// original version	(three pass with additive pass)

textures/liquids/water_beach_original
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
//	tesssize 128
	
	cull disable
	nofog
//	deformVertexes wave 160 sin 0 10 0 .3	// the chop

	waterfogvars ( 0.1 0.1 0.1 ) 300
//	waterfogvars ( 0.1 0.1 0.1 ) .005
	{
		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		fog on
		map textures/liquids/ocean_m1.tga
		rgbgen identity
		tcmod scale .4 .2
		tcmod scroll .00 -.01
	}	

	
	{ 
		map textures/liquids/ocean_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale -.6 .5
		tcmod scroll -.01 -.01
	}
}

textures/liquids/water_beach
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	tesssize 128

	waterfogvars ( 0.1 0.1 0.1 ) 300
//	waterfogvars ( 0.1 0.1 0.1 ) .005
	
	cull disable
//	nofog
	deformVertexes wave 160 sin 0 10 0 .3	// the chop

	{
//		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
//		fog on
		map textures/liquids/ocean_m1.tga
		rgbgen identity
		tcmod scale .4 .2
		tcmod scroll .00 -.01
	}	

	
	{ 
//		map textures/liquids/ocean_m2.tga
		map textures/liquids/ocean_m2d.tga	// made by SA has alpha channel
//		blendFunc GL_dst_color GL_one
		blendfunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
//		blendfunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbgen identity		
		tcmod scale -.6 .5
		tcmod scroll -.01 -.01
	}
}

textures/liquids/water_beach_fog
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	tesssize 128
//	waterfogvars ( .13 .13 .14 ) 6000	// put '0' here eventually to designate "no fog dist change, just color"
	waterfogvars ( 0.1 0.1 0.1 ) 300

	
	cull disable
//	nofog
	deformVertexes wave 160 sin 0 10 0 .3	// the chop

	{
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}
	{ 
		map textures/liquids/ocean_m1.tga
		rgbgen identity
		tcmod scale .4 .2
		tcmod scroll .00 -.01
	}	
	{ 
		map textures/liquids/ocean_m2d.tga	// made by SA has alpha channel
		blendfunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbgen identity		
		tcmod scale -.6 .5
		tcmod scroll -.01 -.01
	}
}

textures/liquids/water_beach_fast
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	qer_nocarve
	tesssize 128
	
	cull disable
	deformVertexes wave 160 sin 0 10 0 .3	// the chop

	{
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		map textures/liquids/ocean_m1.tga
		rgbgen identity
		tcmod scale .4 .2
		tcmod scroll .00 -.01
	}	
}

textures/liquids/water_beach_sa1
{
	qer_editorimage textures/liquids/ocean_m1.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	tesssize 128
	
	cull disable
///	deformVertexes wave 64 sin 3 .7 .8 .25
//	deformVertexes wave 32 sin 0 5 .75 .2
///	deformVertexes wave 32 sin 0 20 .25 .1	

	nofog
	deformVertexes wave 128 sin 0 15 0 .1
//	deformvertexes bulge 0 15 1


	{
		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		fog on
		map textures/liquids/ocean_m1.tga
//		blendFunc GL_dst_color GL_one
		rgbgen identity
		tcmod scale .4 .2
//		tcmod stretch 0 1 .01 0 .25 1
		tcmod scroll .00 -.01
	}	

	
	{ 
//		map textures/liquids/water_m1.tga
		map textures/liquids/ocean_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale -.6 .5
//		tcmod stretch 0 1 .01 0 .25 1
//		tcmod rotate 5 
		tcmod scroll -.01 -.01
	}

	
	
}


// wake is the mark on water surfaces for paddling players
splashRipple
{
	{
		clampmap sprites/splashalpha.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
		tcMod stretch sawtooth 0 1 0 0.9
//		tcMod stretch sin .9 0.05 0 0.5
//		rgbGen wave sin .7 .3 .25 .5
////		tcMod stretch sin .9 0.03 0 0.5
////		rgbGen wave sin .7 .07 .25 .5
	}	
}




textures/skies/rf_asssky_sa1

{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 1024 
	q3map_sun	0.274632 0.274632 0.358662 25 325 35
	q3map_surfacelight 120
	skyparms full 200 -
	fogvars ( .26 .26 .31 ) 2000	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}

	
}

textures/skies/rf_asssky_sa2_bak
{
	qer_editorimage textures/skies/topclouds.tga
//	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
//	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512
	q3map_sun	0.274632 0.274632 0.358662 25 325 35
	q3map_surfacelight 120
	skyparms full 200 -
//	fogvars ( 1 0 0 ) .0002
	fogvars ( .13 .13 .14 ) .001
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/rf_asssky_sa2
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 0 45
	q3map_surfacelight 115
	fogvars ( .13 .13 .14 ) .001

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 5 5
	}
}

textures/skies/rf_asssky_sa3_bak
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 1024 
	q3map_sun	0.274632 0.274632 0.358662 25 325 35
	q3map_surfacelight 120
	skyparms full 200 -
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}



textures/skies/rf_asssky_sa3
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 0 45
	q3map_surfacelight 115
//	fogvars ( .13 .13 .14 ) .001

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 3 3
		depthWrite
	}
//	{
//		map textures/skies/dimclouds.tga
//		blendfunc GL_ONE GL_ONE
//		tcMod scroll -0.001 -0.005
//		tcMod scale 5 5
//	}
}


textures/liquids/water_dig
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	tesssize 128
	
	cull disable
	nofog
	deformVertexes wave 160 sin 0 2 0 .3	// the chop

	{
		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		fog on
		map textures/liquids/ocean_m1.tga
		rgbgen identity
		tcmod scale .4 .2
		tcmod scroll .00 -.01
	}	

	
	{ 
		map textures/liquids/ocean_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale -.6 .5
		tcmod scroll -.01 -.01
	}
}


textures/skies/town_sky_sacopy
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .13 .13 .14 ) .001
//	skyfogvars ( .2 0 0 ) .1
	skyfogvars ( .13 .13 .14 ) .5

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 5 5
	}
}

textures/skies/town_sky_sacopyb
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .13 .13 .14 ) .001
	skyfogvars ( .2 0 0 ) .1

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 5 5
	}
}



entitySteam
{
	allowCompress

	deformVertexes wave 50 sin 1 0 0 0
	deformVertexes wave 45 sin 0 20 0 -.6	// a negative frequency is for Z deformation based on normal
	cull none
	{
//		animmap 20 sprites/clnfire/spr000.tga sprites/clnfire/spr001.tga sprites/clnfire/spr002.tga sprites/clnfire/spr003.tga sprites/clnfire/spr004.tga sprites/clnfire/spr005.tga sprites/clnfire/spr006.tga sprites/clnfire/spr007.tga sprites/clnfire/spr008.tga sprites/clnfire/spr009.tga sprites/clnfire/spr010.tga sprites/clnfire/spr011.tga sprites/clnfire/spr012.tga sprites/clnfire/spr013.tga sprites/clnfire/spr014.tga sprites/clnfire/spr015.tga
		animmap 8 textures/sfx/smoke1.tga textures/sfx/smoke2.tga textures/sfx/smoke3.tga textures/sfx/smoke4.tga textures/sfx/smoke5.tga textures/sfx/smoke6.tga textures/sfx/smoke7.tga textures/sfx/smoke8.tga
//		blendFunc GL_SRC_ALPHA GL_ONE
		blendFunc GL_SRC_COLOR GL_ONE
//		alphaGen normalzfade 1.0 -0.7 0.5
		alphaGen normalzfade 1.0 -2.0 0.0

// blue
//	deformVertexes wave 100 sin 1 0 0 0
//	deformVertexes wave 94 sin 0 1 0 1.2
//		alphaGen normalzfade 1.0 -2.0 0.0

        //tcmod scroll 1 .1
	}
}




textures/chat/clock_m
{

	{
		map $lightmap
	}

	{
		map textures/chat/clock_m.tga
		blendfunc GL_DST_COLOR GL_ZERO
	}	

	{
		map textures/chat/clock_m_second.tga
		blendfunc blend
		tcmod rotate .1
	}

}


textures/liquids/slag1
{
	qer_editorimage textures/sfx/qsand_m01.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm slag
	tesssize 128
	
	cull disable
	nofog

	waterfogvars ( 0.1 0.1 0.1 ) 300
//	waterfogvars ( 0.05 0.05 0.02 ) .1

	{
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		map textures/sfx/qsand_m01.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity
		tcmod scale .5 .5
		tcmod scroll .025 .01
	}
}


textures/rock/satestrock
{
	qer_editorimage	textures/rock/s_roc_c30b.tga

    surfaceparm nolightmap
    surfaceparm snowsteps

	q3map_smoothinggroup 1

    {
        map textures/rock/s_roc_c30b.tga
      //blendFunc GL_DST_COLOR GL_ZERO	
        rgbGen exactvertex
    }
}

//
// vert lit/smoothed version
//
textures/rock/satestb
{
	qer_editorimage textures/colors/darkblue.tga

    surfaceparm nolightmap
	surfaceparm snowsteps

	q3map_smoothinggroup 1

    {
		map textures/colors/darkblue.tga
        rgbGen exactvertex
    }
}


//
// regular with-lightmap version
//
textures/rock/satest
{
	qer_editorimage textures/colors/darkblue.tga

	surfaceparm snowsteps

	q3map_smoothinggroup 1
	{
		map $lightmap
		blendFunc GL_one GL_zero
		rgbgen identity		
	}

    {
		map textures/colors/darkblue.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

//
// vert lit version
//
textures/rock/satesta
{
	qer_editorimage textures/colors/darkblue.tga

//    surfaceparm nolightmap
	surfaceparm snowsteps

    {
		map textures/colors/darkblue.tga
        rgbGen exactvertex
    }
}



textures/liquids/lake_m01_bak
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	tesssize 128
	
	cull disable
	nofog
	deformVertexes wave 1024 sin 0 5 0 .3	// the chop

	waterfogvars ( 0.1 0.1 0.1 ) 300
//	waterfogvars ( 0.1 0.1 0.1 ) .005
	{
		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		fog on
		map textures/liquids/lake_m1.tga
		rgbgen identity
		tcmod scale .2 .2
		tcmod scroll .005 .005
	}	

	
	{ 
		map textures/liquids/lake_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale .25 .25
	//	tcmod scroll .001 .001
	}
}

textures/liquids/river_m01_bak
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
	tesssize 128
	
	cull disable
	nofog
//	deformVertexes wave 160 sin 0 10 0 .3	// the chop

	waterfogvars ( 0.1 0.1 0.1 ) 300
//	waterfogvars ( 0.1 0.1 0.1 ) .005
	{
		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}

	{ 
		fog on
		map textures/liquids/ocean_m1.tga
		rgbgen identity
		tcmod scale .4 .2
		tcmod scroll .00 -.01
	}	

	
	{ 
		map textures/liquids/ocean_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale -.6 .5
		tcmod scroll -.01 -.01
	}
}



textures/chateau/marble_c04b
{
	surfaceparm ceramic
	qer_editorimage textures/chateau/marble_c04.tga
	{
		map textures/chateau/marble_c04.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.2 1.2  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}




// nailgun business

nailtrail
{
	sort nearest
	cull none
	{
		clampmap models/weaphits/nailtrail.tga 
		blendFunc Add
		rgbGen vertex
		tcMod rotate -30
	}

}

models/weaphits/nail
{

	cull disable

	{
		map models/weaphits/nail.tga
		alphaFunc GE128
		depthWrite
		rgbGen identity
	}
}

models/weaphits/nail2
{
     cull disable
	{
		map models/weaphits/nail2.tga
		alphaFunc GE128
		depthWrite
		rgbGen identity
	}
}




sun2
{
	nofog
	nocompress
	{
		map gfx/misc/sun_old.tga
//		blendFunc GL_ONE GL_ONE
		blendFunc GL_ONE_MINUS_DST_COLOR GL_ONE
		rgbGen vertex
	}
}


textures/skies/sky_saforest
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 512
	q3map_sun	1.0 0.8 0.6 130 220 50
	q3map_surfacelight 25							

	fogvars ( .3 .3 .305 ) .000095
	skyfogvars ( .23 .23 .24 ) .1

	sunshader sun2
	skyparms - 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}
}


textures/common/leakwater
{
    qer_trans 0.5
	surfaceparm nodraw
	surfaceparm trans
	surfaceparm markparticles
//	emittertype water
}

textures/common/leakoil
{
    qer_trans 0.5
	surfaceparm nodraw
	surfaceparm trans
	surfaceparm markparticles
//	emittertype oil
}

textures/common/leaksteam
{
    qer_trans 0.5
	surfaceparm nodraw
	surfaceparm trans
	surfaceparm markparticles
//	emittertype steam
}


liquids/water_beach_sa1
	{

    surfaceparm areaportal

		qer_editorimage textures/liquids/ocean_m1.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
	//	deformVertexes wave 64 sin 3 .7 .8 .25
		deformVertexes wave 32 sin 0 10 .75 .1
	//	deformVertexes wave 32 sin 0 20 .25 .1	
		{ 
			map textures/liquids/ocean_m1.tga
		//	blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .8 .7
		//	tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll .00 -.01
		}
	{
		animMap 9 textures/liquids/ocean13.tga textures/liquids/ocean01.tga textures/liquids/ocean02.tga textures/liquids/ocean03.tga textures/liquids/ocean04.tga textures/liquids/ocean05.tga textures/liquids/ocean06.tga textures/liquids/ocean07.tga textures/liquids/ocean08.tga textures/liquids/ocean09.tga textures/liquids/ocean10.tga textures/liquids/ocean11.tga textures/liquids/ocean12.tga

		blendFunc GL_dst_color GL_one
		rgbGen identity
		tcmod scroll .01 .01
	}	

	{
	   	map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}	

//	END
	}

