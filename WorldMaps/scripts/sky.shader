// q3map_sun <red> <green> <blue> <intensity> <degrees> <elevation>
// color will be normalized, so it doesn't matter what range you use
// intensity falls off with angle but not distance 100 is a fairly bright sun
// degree of 0 = from the east, 90 = north, etc.  altitude of 0 = sunrise/set, 90 = noon

// skyparms work like this: 

textures/skies/blacksky
{
	qer_editorimage textures/skies/blacksky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	//skyparms env/q3sky_red1 - -
	//skyparms env/kmnight - -
	//skyparms env/black - -
	q3map_surfacelight 25
	q3map_lightsubdivide 512
	q3map_sun	1 1 1 32	90 90
	{
		map	gfx/colors/black.tga
	}
}

textures/skies/xblacksky
{
	qer_editorimage textures/skies/blacksky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	//skyparms env/q3sky_red1 - -
	//skyparms env/kmnight - -
	//skyparms env/black - -
	q3map_surfacelight 300
	q3map_lightsubdivide 512
	q3map_sun	1 1 1 32	45 90
	{
		map	gfx/colors/black.tga
	}
}

textures/skies/xblacksky_dm7
{
	qer_editorimage textures/skies/blacksky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	//skyparms env/q3sky_red1 - -
	//skyparms env/kmnight - -
	//skyparms env/black - -
//	q3map_surfacelight 300
//	q3map_lightsubdivide 512
//	q3map_sun	1 1 1 32	45 90
	{
		map	gfx/colors/black.tga
	}
}

textures/skies/stars_arena7
{
	qer_editorimage textures/skies/stars.tga

	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_surfacelight 10
	q3map_sun .6 .6 .6 30 35 78

	skyparms env/black - -
}

textures/skies/killsky
{
	qer_editorimage textures/skies/stars.tga
	surfaceparm noimpact
	surfaceparm nomarks
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 3 2 2 70 315 65
	q3map_surfacelight 75
	skyparms env/black 512 -

	//cloudparms 512 full
	//lightning

	{
		map textures/skies/killsky_1.tga
		tcMod scroll 0.05 .1
		tcMod scale 2 2
		depthWrite
	}
	{
		map textures/skies/killsky_2.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.06
		tcMod scale 3 2
	}
}

textures/skies/tim_km2
{
	qer_editorimage textures/skies/stars.tga
	surfaceparm noimpact
	surfaceparm nomarks
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 3 2 2 70 315 40
	q3map_surfacelight 75
	skyparms env/black 512 -

	//cloudparms 512 full
	//lightning

	{
		map textures/skies/killsky_1.tga
		tcMod scroll 0.05 .1
		tcMod scale 2 2
		depthWrite
	}
	{
		map textures/skies/killsky_2.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.06
		tcMod scale 3 2
	}
}

textures/skies/tim_dm14
{
	qer_editorimage textures/skies/stars.tga
	surfaceparm noimpact
	surfaceparm nomarks
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 3 2 2 90 314 60
	q3map_surfacelight  80 
	skyparms env/black 512 -

	//cloudparms 512 full
	//lightning

	{
		map textures/skies/killsky_1.tga
		tcMod scroll 0.05 .1
		tcMod scale 2 2
		depthWrite
	}
	{
		map textures/skies/killsky_2.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.06
		tcMod scale 3 2
	}
}


textures/skies/hellsky
{
	surfaceparm noimpact
	surfaceparm nomarks
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 4 3 3 65 290 75
	q3map_surfacelight 50
	skyparms env/black - -

	cloudparms 512 full
	lightning

	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.05 0
		tcMod scale 2 2
		depthWrite
	}

	//{
	//	map textures/skies/dimclouds.tga
	//	blendfunc GL_ONE GL_ONE
	//	tcMod scroll 0.05 0.06
	//	tcMod scale 1 1
	//}
}

textures/skies/toxicsky
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	skyparms 512 full -

	q3map_surfacelight 80
	q3map_sun	1 1 0.5 100	30 60

//	cloudparms 512 full

	skyparms - 512 -

	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}

textures/skies/xtoxicsky_dm3
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	qer_editorimage textures/skies/toxicsky.tga

	q3map_surfacelight 400
	q3map_sun	1 1 0.5 150	30 60
//	q3map_sun	1 1 0.5 150	200 85
	skyparms 512 full -
//	cloudparms 512 full

	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}



textures/skies/xtoxicsky_dm9
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	qer_editorimage textures/skies/toxicsky.tga

	q3map_surfacelight 400
	q3map_sun	1 1 0.5 150	30 60
	skyparms 512 full -
//	cloudparms 512 full

	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}

textures/skies/xtoxicsky_ctf
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	qer_editorimage textures/skies/toxicsky.tga

	q3map_surfacelight 500
	q3map_sun	1 1 0.5 150	30 60
	skyparms 512 full -
//	cloudparms 512 full

	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}

textures/skies/xtoxicsky_tourney
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	qer_editorimage textures/skies/toxicsky.tga

	q3map_surfacelight 495
//	q3map_sun	1 1 0.5 150	55 60
	q3map_sun	1 1 0.5 150	75 60
	skyparms 512 full -
//	cloudparms 512 full

	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}

textures/skies/nightsky_xian_dm1
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_surfacelight 300
	q3map_sun 1 1 1 100 -41 58

	qer_editorimage textures/skies/nightsky_nocloud.tga

	skyparms env/xnight2 - -
}

textures/skies/nightsky_xian_dm2
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_surfacelight 200
	q3map_sun 1 1 1 100 -41 58

	qer_editorimage textures/skies/nightsky_nocloud.tga

	sky	env/xnight2
}

textures/skies/nightsky_xian_dm3
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_surfacelight 500
	q3map_sun 1 1 1 100 -41 58

	qer_editorimage textures/skies/nightsky_nocloud.tga

	sky	env/xnight2
}

textures/skies/nightsky_xian_dm15
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm nolightmap
	surfaceparm sky
	surfaceparm noimpact

	q3map_surfacelight 900
	q3map_sun 1 1 1 100 -58 58
	skyparms env/xnight2 - -

//	q3map_sun 1 1 1 100 -41 58
//	q3map_sun 1 1 1 100 -49 58

}



textures/skies/xblacksky
{
	qer_editorimage textures/skies/blacksky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_surfacelight 2
	q3map_sun	0.2 0.2 0.3 80 -55 75

}

textures/skies/xtoxicsky_dm4
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_surfacelight 80
	q3map_sun	1 1 0.95 50 40 90

	qer_editorimage textures/skies/toxicsky.tga

	//sky env/hell2
	cloudparms 512 full
	//lightning
	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}


textures/skies/xtoxicsky_dm14
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_surfacelight 800
//	q3map_sun	1 1 0.5 100	75 45
//	q3map_sun	1 1 0.85 100	140 85
	q3map_sun	1 1 0.85 100	90 90


	qer_editorimage textures/skies/toxicsky.tga

	//sky env/hell2
	//cloudparms 512 full
	skyparms 512 full -
	//lightning
	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}


textures/skies/xtoxicsky_90_60
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_surfacelight 80
//	q3map_sun	1 1 0.5 100	75 45
	q3map_sun	1 1 0.5 200	160 70
	qer_editorimage textures/skies/toxicsky.tga

	//sky env/hell2
	cloudparms 512 full
	//lightning
	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}

textures/skies/space_holder
{
	qer_editorimage textures/skies/space_holder.tga
	//surfaceparm sky
	surfaceparm noimpact
	//q3map_surfacelight 300
	surfaceparm nolightmap
	sky	env/space1
}
textures/skies/nightsky_nocloud_600
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	q3map_surfacelight 600
	surfaceparm nolightmap
	sky	env/xnight2
}
textures/skies/nightsky_nocloud_100
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	//q3map_surfacelight 100
	q3map_sun 1 1 1 100 -41 58
	q3map_surfacelight 300
	surfaceparm nolightmap
	sky	env/xnight2
}
textures/skies/nightsky_nocloud_200
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	q3map_surfacelight 200
	surfaceparm nolightmap
	sky	env/xnight2
}

textures/skies/nightsky_nocloud_1000
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	q3map_surfacelight 1000
	surfaceparm nolightmap
	sky	env/xnight2
}

textures/skies/nightsky_nocloud_500
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	q3map_surfacelight 500
	surfaceparm nolightmap
	sky	env/xnight2
}
textures/skies/nightsky_nocloud_400
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	q3map_surfacelight 400
	surfaceparm nolightmap
	sky	env/xnight2
}
textures/skies/nightsky_nocloud
{
	surfaceparm sky
	surfaceparm noimpact
	q3map_surfacelight 350
	surfaceparm nolightmap
	sky	env/xnight2
}
textures/skies/hellredclouds
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 

	q3map_sun 5 2 2 60 135 90
	q3map_surfacelight 80

	skyparms - 512 -
	//lightning

	{
		map textures/skies/redclouds.tga
		tcMod scroll 0.02 0
		tcMod scale 2 2
	}
	{
		map textures/skies/lightningsky8_kc.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 10 10
		tcMod scroll .2 .2
	}	
	{
		map textures/skies/redcloudsa.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.02 0.01
	}


}
textures/skies/hellskybright
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 4 3 3 80 45 75
	q3map_surfacelight 60

	skyparms - 512 -
	//sky env/hell2
	//cloudparms 512 full
	//lightning

	{
		map textures/skies/dimclouds.tga
		//blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0
		//tcMod scroll 0 0
		tcMod scale 2 2
		depthWrite
	}
	{
		map textures/skies/redclouds.tga
		//blendFunc GL_DST_COLOR GL_ZERO
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.06
		tcMod scale 1 1
	}
}

textures/skies/hellsky2bright
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun	1 1 1 100 220 50
	q3map_surfacelight 120

	qer_editorimage textures/skies/toxicsky.tga

	skyparms - 512 -
	//cloudparms 512 full
	{
		map textures/skies/inteldimclouds.tga
		tcMod scale 3 2
		tcMod scroll 0.15 0.15
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.05 0.05
	}
}

textures/skies/hellsky
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 5 3 3 60 290 75
	q3map_surfacelight 90

	cloudparms 512 full
	lightning

	{
		map textures/skies/redclouds.tga
		tcMod scroll 0.05 0
		tcMod scale 2 2
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.06
		tcMod scale 1 1
	}
}
textures/hell/newhell
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_surfacelight 200

	sky env/hell2
	cloudparms 512 full
	lightning

	{
		map env/redcloudsa.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0
		tcMod scale 2 2
	}
	{
		map env/redclouds.tga
		blendFunc GL_DST_COLOR GL_ZERO
		tcMod scroll 0.05 0.06
		tcMod scale 1 1
	}
}

//*******************************************************
//*              Paul Jaquays' pj_dm10 sky
//*******************************************************
textures/skies/pj_dm10sky
{
	qer_editorimage textures/skies/pjbasesky.tga
	q3map_lightsubdivide 512 
	q3map_globaltexture
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_sun	.5 .6 .8 90 225 55
	q3map_surfacelight 150

	qer_editorimage textures/skies/toxicbluesky.tga

	skyparms - 512 -

	{
		map textures/skies/bluedimclouds.tga
		tcMod scale 3 2
		tcMod scroll 0.15 0.15
		depthWrite
	}
	{
		map textures/skies/topclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.05 0.05
	}

}

//*******************************************************
//*              Kevin Cloud's kc_dm10 sky
//*******************************************************
textures/skies/kc_dm10sky
{
	qer_editorimage textures/skies/pjbasesky.tga
	q3map_lightsubdivide 512 
	q3map_globaltexture
	surfaceparm noimpact
	surfaceparm nolightmap
	
	q3map_sun	.5 .6 .8 90 225 55
	q3map_surfacelight 150

	qer_editorimage textures/skies/toxicbluesky.tga

	skyparms - 512 -

	{
		map textures/skies/bluedimclouds.tga
		tcMod scale 3 2
		tcMod scroll 0.15 0.15
	}
	{
		map textures/skies/topclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.05 0.05
	}

	//{
	//	map textures/liquids/electric_fog.tga
	//	blendfunc gl_dst_color gl_one
	//	rgbgen wave triangle .8 .2 0 5
	//	tcmod scale -.02 -.02
	//	tcmod rotate 10
	//	tcmod scroll .5 -.5
	//}



}

//*******************************************************
//*              Paul Jaquays' pj_arena1 sky
//*******************************************************
textures/skies/pjbasesky_arena1_sky
{
	qer_editorimage textures/skies/pjbasesky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 256 
	q3map_sun	0.266383 0.274632 0.358662 150 60 85
	q3map_surfacelight 100

	skyparms full 256 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.01 0.01
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/pjbasesky.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.01 -0.01
		tcMod scale 5 5
	}
}

//*******************************************************
//*              Paul Jaquays' pj_ctf2 sky
//*******************************************************
textures/skies/pj_ctf2_sky
{
	qer_editorimage textures/skies/pjbasesky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0000 0.9410 0.6823 100 150 45
	q3map_surfacelight 150

	skyparms full 128 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.015 0.016
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/pjbasesky.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.01 -0.012
		tcMod scale 5 5
	}
}

//*******************************************************
//*              Paul Jaquays' pj_arena4 sky
//*******************************************************
textures/skies/pj_arena4_sky
{
	qer_editorimage textures/skies/pjbasesky.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0000 0.9410 0.6823 90 165 45
	q3map_surfacelight 140

	skyparms full 128 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.015 0.016
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/pjbasesky.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.01 -0.012
		tcMod scale 5 5
	}
}
//*******************************************************
//*              Paul Jaquays' pj_ctf1 sky /june 30, 199
//*******************************************************
textures/skies/pj_ctf1sky
{
	qer_editorimage textures/skies/pjbasesky

	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.266383 0.274632 0.358662 100 350 75
	q3map_surfacelight 150

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.015 0.016
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/pjbasesky.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.01 -0.012
		tcMod scale 5 5
	}
}
//*******************************************************
//*              Paul Jaquays' pj_arena2 sky
//*******************************************************
textures/skies/pj_arena2sky
{
	qer_editorimage textures/skies/pjbasesky

	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.000000 0.941176 0.682353 40 10 70
	q3map_surfacelight 80

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.015 0.016
		tcMod scale 3 3
		depthWrite
	}
	{
		map textures/skies/pjbasesky.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.01 -0.012
		tcMod scale 5 5
	}
}
//*******************************************************
//*              Paul Jaquays' pj_dm9 sky
//*******************************************************
textures/skies/pj_dm9sky
{
	qer_editorimage textures/skies/toxicbluesky.tga
	q3map_lightimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nomarks
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	//q3map_sun	0.266383 0.274632 0.358662 140 165 60
	//q3map_surfacelight 80

	//skyparms full 128 -
	//
	//{
	//	map textures/skies/dimclouds.tga
	//	tcMod scroll 0.015 0.016
	//	tcMod scale 3 3
	//	depthWrite
	//}
	//{
	//	map textures/skies/pjbasesky.tga
	//	blendfunc GL_ONE GL_ONE
	//	tcMod scroll -0.01 -0.012
	//	tcMod scale 5 5
	//}
//}
//
	q3map_sun	.5 .6 .8 140 165 60
	q3map_surfacelight 80

	///qer_editorimage textures/skies/toxicbluesky.tga

	skyparms - 512 -
	//cloudparms 512 full
	{
		map textures/skies/bluedimclouds.tga
		tcMod scale 3 2
		tcMod scroll 0.15 0.15
		depthWrite
	}
	{
		map textures/skies/topclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.05 0.05
	}
}

textures/skies/nightsky_xian_dm4
{
	qer_editorimage textures/skies/nightsky_nocloud.tga
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_sun 1 1 1 80 -41 58
	q3map_surfacelight 50
	skyparms env/xnight2 - -
}

textures/skies/xnightsky
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 1 1 1 100 -41 58
	q3map_surfacelight 300

	sky env/xnight2
	cloudparms 512 half

	{
		map env/xnightsky4.tga
		tcMod scroll 0.005 0.002
		tcMod scale 12 18
		blendfunc GL_ONE GL_ONE
	}

	{
		map env/xnightsky3.tga
		tcMod scroll 0.001 0.003
		tcMod scale 6 10
		blendfunc GL_DST_COLOR GL_ZERO
	}
}
textures/skies/xnightsky_600
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_surfacelight 600

	qer_editorimage textures/skies/xnightsky.tga

	sky env/xnight2
	cloudparms 256 half

	{
		map env/xnightsky.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.010 0.010
		tcMod scale 10 10
	}

	{
		map env/xnightsky1.tga
		blendfunc GL_DST_COLOR GL_ZERO
		tcMod scroll 0.010 0.007
		tcMod scale 10 10
	}
}
textures/skies/hellskyteam
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun 5 3 6 40 80 70
	q3map_surfacelight 45

	skyparms - 512 -
	//sky env/hell2
	//cloudparms 512 full
	//lightning
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/redcloudsa.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}
	//{
		//map env/redcloudsa.tga
		//blendfunc GL_ONE GL_ONE
		//tcMod scroll 0.05 0
		//tcMod scale 2 2
		//
	//}
//
	//{
		//map env/redclouds.tga
		//blendfunc GL_ONE GL_SRC_COLOR
		//tcMod scroll 0.05 0.05
		//tcMod scale 1 1
	//}
//}

textures/skies/toxicskydim
//used in tim_dm1
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_surfacelight 100
	q3map_sun	1 1 0.5 80 30 70

	qer_editorimage textures/skies/toxicsky.tga
	skyparms - 512 -
	//cloudparms 512 full
	{
		map textures/skies/inteldimclouds.tga
		tcMod scroll 0.1 0.1
		tcMod scale 3 2
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.05 0.05
		tcMod scale 3 3
	}
}
textures/skies/toxicskytim_dm4
//used in tim_dm4
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun	1 1 0.5 90 120 75
	q3map_surfacelight 80

	qer_editorimage textures/skies/toxicsky.tga

	skyparms - 512 -
	//cloudparms 512 full
	{
		map textures/skies/inteldimclouds.tga
		tcMod scale 3 2
		tcMod scroll 0.15 0.15
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.05 0.05
	}
}


textures/skies/toxicskytim_ctf1
//used in tim_ctf1
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky

	q3map_sun	1 1 0.5 90 70 40
	q3map_surfacelight 120

	qer_editorimage textures/skies/toxicsky.tga

	skyparms - 512 -
	//cloudparms 512 full
	{
		map textures/skies/inteldimclouds.tga
		tcMod scale 3 2
		tcMod scroll 0.15 0.15
		depthWrite
	}
	{
		map textures/skies/intelredclouds.tga
		blendFunc GL_ONE GL_ONE
		tcMod scale 3 3
		tcMod scroll 0.05 0.05
	}
}
	
textures/hell/hellsky2goo
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	q3map_surfacelight 300

	sky env/hell2
	cloudparms 256

	{
		map env/redcloudsa.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0
		tcMod scale 2 2
	}

	{
		map env/redclouds.tga
		blendfunc GL_ONE GL_SRC_COLOR
		tcMod scroll 0.05 0.05
		tcMod scale 1 1
	}
}

textures/castle/sky_castle1
{
	surfaceparm sky
	surfaceparm noimpact
	surfaceparm nolightmap

	sky env/castle1
	cloudparms 256

	{
		map env/redcloudsa.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll 0.05 0
		tcMod scale 2 2
	}

	{
		map env/redclouds.tga
		blendfunc GL_DST_COLOR GL_ZERO
		tcMod scroll 0.05 0.05
		tcMod scale 1 1
	}
}

textures/skies/dk_castlesky
{
	qer_editorimage textures/skies/dkclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512
	q3map_sun	1.0 0.63 0.4 65 220 18
	q3map_surfacelight 45
//	q3map_sun	1.0000 0.6900 0.4400 70 150 40
//	q3map_surfacelight 150
	fogvars ( .15 .15 .155 ) .000475
	skyfogvars ( .23 .23 .24 ) .5
//	fogvars ( .13 .13 .14 ) .0005
//	skyfogvars (1 0 0) 3000

	skyparms - 128 textures/env/night	
	
	{
		map textures/skies/dkclouds.tga
		tcMod scroll 0.0015 0.0015
		tcMod scale 12 12
		depthWrite
	}
}

textures/skies/dk_boxsky
{
	qer_editorimage textures/skies/dkclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0000 0.6900 0.4400 70 150 40
	q3map_surfacelight 150
//	fogvars ( .13 .13 .14 ) .0005
//	skyfogvars (1 0 0) 3000

	skyparms - 128 textures/env/night	

	{
		map textures/skies/bluesky.tga
		blendfunc GL_ONE GL_SRC_COLOR
		tcMod scroll 0.001 0.001
		tcMod scale 10 10
	}

}

textures/skies/dk_castleskylowamb
{
	qer_editorimage textures/skies/dkclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0000 0.5900 0.3400 20 150 40
//	q3map_sun	1.0000 0.9220 0.5880 70 150 40
//	q3map_sun	1.0000 0.6300 0.4000 70 150 40
	q3map_surfacelight 40
//	fogvars ( .13 .13 .14 ) .0005

	skyparms - 128 textures/env/night	
	
	{
		map textures/skies/dkclouds.tga
		tcMod scroll 0.0015 0.0015
		tcMod scale 12 12
		depthWrite
	}

	// single cloud layer maxx
	//{
	//	map textures/skies/dimclouds_m.tga
	//	blendfunc GL_ONE GL_ONE
	//	tcMod scroll 0.002 0.002
	///	tcMod scale 8 8
	//}

}

textures/skies/proto_sky
{
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	skyparms 512 full -

	q3map_surfacelight 30
	q3map_sun .473 .243 .314 30 35 78

//	cloudparms 512 full

	skyparms - 512 -

	{
		map textures/skies/proto_sky.tga
		tcMod scroll .02 .04
		tcMod scale 3 4
		depthWrite
	}
	{
		map textures/skies/proto_sky2.tga
		blendFunc GL_ONE GL_ONE
		tcMod scroll 0.005 0.005
                //rgbgen wave triangle 1 2 0 7
		tcMod scale 3 3
	}
        
     
}

//*******************************************************
//*              Richard's crypt sky /9/14/99
//*******************************************************
textures/skies/rf_nightsky
{
	qer_editorimage textures/skies/topclouds
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.266383 0.274632 0.358662 40 350 75
	q3map_surfacelight 70

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

//*******************************************************
//*              Drew's Scale Model Sky 
//*******************************************************
textures/skies/dm_modelsky
{
	qer_editorimage textures/skies/topclouds
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.366383 0.274632 0.258662 20 310 75
	q3map_surfacelight 40

	skyparms full 200 -

//	fogvars ( .1 .1 .1 ) .001
	
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

//*******************************************************
//*              Mike Denny Test Sky
//*******************************************************
textures/skies/md_testsky
{
	qer_editorimage textures/skies/topclouds
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
//	q3map_sun	0.366383 0.274632 0.258662 20 310 75
//	q3map_surfacelight 40

	skyparms full 200 -

	fogvars ( .17 .17 .17 ) .00025
	
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

textures/skies/solosky1
{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
	q3map_surfacelight 90
	skyparms - 128 textures/env/night
//	fogvars ( .07 .06 .09 ) .0008
	fogvars ( .1 .1 .1 ) 2000
	
	{
		map textures/skies/dimclouds_m.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/uboat_sky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .2 .2 .2 ) .0001

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

textures/skies/town_sky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
//	fogvars ( .13 .13 .14 ) .001
//	fogvars ( .16 .16 .16 ) .0003
	fogvars ( .11 .11 .11 ) .0002

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

textures/skies/sky_rocket
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .13 .13 .13 ) .0005

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


textures/skies/sky_swf
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .2 .2 .2 ) .0002
	nopicmip
	nocompress
	skyparms full 200 -
	

	{
		map textures/skies/dimclouds2.tga
		rgbGen const ( 0.3 0.3 0.3 )
		blendfunc GL_ONE GL_ZERO
		tcMod scroll 0.002 0.002
		tcMod scale 8.0 8.0
	}
	
	{
		map textures/skies/dimclouds2.tga
		blendfunc GL_ONE GL_ONE
		rgbGen const ( 0.2 0.2 0.2 )
		tcMod scroll -0.001 -0.004
		tcMod scale 10 10


	}

}

textures/skies/sky_fac
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 25 200 50
	q3map_surfacelight 55
	fogvars ( .096 .09 .09 ) .0005
//	skyfogvars ( .23 .23 .24 ) .15
	nopicmip
	nocompress
	skyparms full 200 -
	
	{
		map textures/skies/dimclouds2.tga
		rgbGen const ( 0.3 0.3 0.3 )
		blendfunc GL_ONE GL_ZERO
		tcMod scroll 0.002 0.002
		tcMod scale 8.0 8.0
	}
	
	{
		map textures/skies/dimclouds2.tga
		blendfunc GL_ONE GL_ONE
		rgbGen const ( 0.2 0.2 0.2 )
		tcMod scroll -0.001 -0.004
		tcMod scale 10 10


	}
}

textures/skies/sky_trainyard
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 25 200 50
	q3map_surfacelight 55
	fogvars ( .096 .09 .09 ) .0004
//	skyfogvars ( .23 .23 .24 ) .15
	nopicmip
	nocompress
	skyparms full 200 -
	
	{
		map textures/skies/dimclouds2.tga
		rgbGen const ( 0.3 0.3 0.3 )
		blendfunc GL_ONE GL_ZERO
		tcMod scroll 0.002 0.002
		tcMod scale 8.0 8.0
	}
	
	{
		map textures/skies/dimclouds2.tga
		blendfunc GL_ONE GL_ONE
		rgbGen const ( 0.2 0.2 0.2 )
		tcMod scroll -0.001 -0.004
		tcMod scale 10 10
	}
}

textures/skies/sky_xlabs
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .2 .2 .2 ) .00002

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 5 5
	}
}

textures/skies/gt_sky
{
	qer_editorimage textures/skies/topclouds.tga
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
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/sky_b25
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 65 220 18
	q3map_surfacelight 30
	fogvars ( .13 .13 .14 ) .003
	skyfogvars ( .23 .23 .24 ) .7

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.02 0.02
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll  0.01 0.01
		tcMod scale 10 10
	}
}

textures/skies/sky_newcrypt
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 65 220 18
	q3map_surfacelight 0
	fogvars ( .135 .13 .13 ) .0002
//	fogvars ( .135 .13 .13 ) .0006
//	skyfogvars ( .23 .23 .24 ) .5

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/gt2_sky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 0 220 18
	q3map_surfacelight 50
	fogvars ( .15 .15 .19 ) .003
	skyfogvars ( .23 .23 .27 ) .75

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/town_sky_nofog
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
//	fogvars ( .13 .13 .14 ) .001

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

textures/skies/town_skynew
{
	qer_editorimage textures/skies/topclouds
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.68 0.4 50 200 50
	q3map_surfacelight 100
	fogvars ( .25 .2 .2 ) .00065
	

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

textures/skies/town_sky_side
{
	qer_editorimage textures/skies/topclouds
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.68 0.4 120 200 50
	q3map_surfacelight 1

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

textures/skies/town_sky2
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .2 .2 .25 ) .0004

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

//textures/skies/town_sky2
//{
//	qer_editorimage textures/skies/topclouds
//	surfaceparm noimpact
//	surfaceparm nolightmap
//	q3map_globaltexture
//	q3map_lightsubdivide 512 
//	q3map_sun	1.0 0.68 0.4 120 350 50
//	q3map_surfacelight 100
//	fogvars ( .2 .2 .25 ) .0004
//
//	skyparms full 200 -
//	
//	{
//		map textures/skies/dimclouds.tga
//		tcMod scroll 0.002 0.002
//		tcMod scale 3 3
//		depthWrite
//	}
//	{
//		map textures/skies/dimclouds.tga
//		blendfunc GL_ONE GL_ONE
//		tcMod scroll -0.001 -0.005
//		tcMod scale 5 5
//	}
//}


textures/skies/town_skydak
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm nodlight
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	//q3map_lightsubdivide 512  changed by Rich to decrease lighting time
	q3map_lightsubdivide 1024
	q3map_sun	1.0 0.63 0.4 60 0 45
	q3map_surfacelight 125
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




//*******************************************************
//*              Rich's Outdoor sky 
//*******************************************************
textures/skies/mk_nightsky
{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
	q3map_surfacelight 90
	fogvars ( .02 .02 .03 ) .00035
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	
	{
		map textures/skies/dimclouds_m.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
	
	
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
		tcMod scale 12.0 12.0
	}

	
}




textures/skies/solo_superfog
{
	qer_editorimage textures/skies/sky_m01dm
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 1 135 45
	q3map_surfacelight 140
	//q3map_lightrgb 0.1 0.1 0.5
	skyparms full 200 -
//	fogvars ( .11 .11 .13 ) .1
	fogvars ( 0 0 0 ) .01

	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.001 0.001
		tcMod scale 12.0 12.0
		depthWrite
	}
}

textures/skies/mk_wrecksky2
{
	qer_editorimage textures/skies/sky_m01dm
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.534632 0.474632 0.474662 60 135 60
	q3map_surfacelight 100
	//q3map_lightrgb 0.1 0.1 0.5
	skyparms full 200 -
	fogvars ( .11 .11 .13 ) .001	



	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.001 0.001
		tcMod scale 12.0 12.0
		depthWrite
	}


	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite


/// maxx 2-alpha layer test ////	
//	{
//		map textures/skies/skysolid.tga
//	//	tcMod scroll 0.001 0.001
//		tcMod scale 12.0 12.0
//		depthWrite
//	}
	
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
		tcMod scale 12.0 12.0
	}

	
}

//*******************************************************
//*              Dan's Outdoor sky 
//*******************************************************
textures/skies/dk_nightsky
{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
//	fixing sun to blue again dan 12/1
//	q3map_sun	1.0000 0.9410 0.6823 100 150 45
	q3map_surfacelight 90

	fogvars ( .1 .1 .1 ) .0004

	skyparms - 128 textures/env/night
	
	{
		map textures/skies/dimclouds_m.tga
	//	blendfunc GL_ONE GL_ONE
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
		//tcMod scroll -0.01 -0.012
		tcMod scale 12.0 12.0
	}
}

////
textures/skies/dk_nightsky2
{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
	q3map_surfacelight 90
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -

	
	{
		map textures/skies/dimclouds_m.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
	
	
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
		tcMod scale 12.0 12.0
	}

	
}

//*******************************************************
//*       Rich's Castle sky. Added by rich Jan22/2k 
//*******************************************************

textures/skies/rf_castsky

{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
//	fixing sun to blue again dan 12/1
//	q3map_sun	1.0000 0.9410 0.6823 100 150 45
	q3map_surfacelight 90

	skyparms - 128 textures/env/night
	
	{
		map textures/skies/dimclouds_m.tga
	//	blendfunc GL_ONE GL_ONE
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
		//tcMod scroll -0.01 -0.012
		tcMod scale 12.0 12.0
	}
}

//*******************************************************
//*       Sippy's Cathedral sky. Added by the Sipsta Jan26/2k 
//*******************************************************

textures/skies/dak_cathsky

{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	//q3map_sun 0.274632 0.274632 0.358662 35 180 45
//	fixing sun to blue again dan 12/1
//	q3map_sun	1.0000 0.9410 0.6823 100 150 45
	q3map_surfacelight 90

	skyparms - 128 textures/env/night
	
	{
		map textures/skies/dimclouds_m.tga
	//	blendfunc GL_ONE GL_ONE
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
		//tcMod scroll -0.01 -0.012
		tcMod scale 12.0 12.0
	}
}

textures/skies/sky_baseout
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.39 18 35 35
	q3map_surfacelight 35
	skyparms full 200 -
	fogvars ( .1 .1 .1 ) .0002
	skyfogvars ( .23 .23 .24 ) .05

	
	{
		map textures/skies/newclouds2.tga
//		tcMod scroll 0.0005 0.0001
		tcMod scale 16.0 16.0
		depthWrite
	}

	{
		map textures/skies/vil_clouds1.tga
		blendfunc blend
		tcMod scroll 0.001 0.00
		tcMod scale 2 1
	}
}

textures/skies/rf_wildsky
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 25 135 35
	q3map_surfacelight 80
	//q3map_lightrgb 0.1 0.1 0.5
	skyparms full 200 -
	fogvars ( .11 .11 .13 ) .0008	



	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 6.0 6.0
		depthWrite
	}

	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
		tcMod scale 12.0 12.0
	}	
}

textures/skies/sky_tram
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 1024 
	//q3map_sun	0.274632 0.274632 0.358662 30 325 35
	q3map_surfacelight 35
	skyparms full 200 -
	fogvars ( .4 .4 .45 ) 2700	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/rf_trambsky
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	// changed to 1024 by rich q3map_lightsubdivide 512
	q3map_lightsubdivide 1024 
	q3map_sun	0.274632 0.274632 0.358662 25 325 35
	q3map_surfacelight 80
	skyparms full 200 -
	fogvars ( .26 .26 .31 ) 3400	

	//*********************************************
	// Removed as this is fastsky 1 so clouds are never seen.
	//
	//{
	//	map textures/skies/dimclouds.tga
	//	tcMod scroll 0.002 0.002
	//	tcMod scale 6.0 6.0
	//	depthWrite
	//}
	//*********************************************
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}

	
}

textures/skies/rf_chatsky
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 20 325 35
	q3map_surfacelight 150
	//q3map_lightrgb 0.1 0.1 0.5
	skyparms full 200 -
	fogvars ( .11 .11 .13 ) .0004	



	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 6.0 6.0
		depthWrite
	}
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}

	
}

textures/skies/xlabsky
//Sippy's Xlab sky - based on solosky1
{
	qer_editorimage textures/skies/sky_m01
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 90 45
	q3map_surfacelight 90
	skyparms - 128 textures/env/night
//	fogvars ( .07 .06 .09 ) .0008
	fogvars ( .1 .1 .1 ) 2000
	
	{
		map textures/skies/dimclouds_m.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}
	{
		map textures/skies/sky_m01.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

/// maxx test fog - awf //////

textures/skies/test_fog
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .2 .2 .25 ) .0003	skyparms full 200 -
	
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

textures/skies/dig_sky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 100 0 30
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

textures/skies/rf_asssky

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
	fogvars ( .26 .26 .31 ) 4200	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/maxx_test
{
	qer_editorimage textures/env/st_up
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
//	fixing sun to blue again dan 12/1
//	q3map_sun	1.0000 0.5410 0.6823 100 150 45
	q3map_surfacelight 90

	skyparms - 128 textures/env/st
	
	{
		map textures/skies/dimclouds_m.tga
	//	blendfunc GL_ONE GL_ONE
		tcMod scroll 0.002 0.0005
		tcMod scale 12.0 12.0
		depthWrite
	}
}

textures/skies/rf_beachsky

{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 1024 
//	q3map_sun	0.274632 0.274632 0.358662 45 325 35
	q3map_surfacelight 65
	skyparms full 200 -
	fogvars ( .26 .26 .31 ) 9200	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}

	
}

textures/skies/rf_beachsky2
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 1024 
//	q3map_sun	0.274632 0.274632 0.358662 30 325 35
	q3map_surfacelight 65
	skyparms full 200 -
// 	fogvars ( .26 .26 .31 ) 4200  Value from old Beach map	
	fogvars ( .26 .26 .31 ) 9200

	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}	
}

textures/skies/graveyard_sky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
//	q3map_sun	1.0 0.63 0.4 65 220 18
//	q3map_surfacelight 65
	q3map_sun	1.0 0.63 0.4 135 275 25
	q3map_surfacelight 120
	fogvars ( .13 .13 .14 ) .0007
	skyfogvars ( .23 .23 .24 ) .5

	surfaceparm nodlight	// (SA) added so dlights don't affect surface
	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08

		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/rf_beachsky3

{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 1024 
//	q3map_sun	0.274632 0.274632 0.358662 55 325 35
	q3map_surfacelight 70
	skyparms full 200 -
	fogvars ( .26 .26 .31 ) 4200	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}	
}

textures/skies/dimclouds_mb
{

	surfaceparm noimpact
	surfaceparm nolightmap

	{
		map textures/skies/dimclouds_mb.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		tcMod scale .5 .5
		tcMod scroll 0.02 0.05
		rgbGen vertex
	}	
}

textures/skies/a_box1
{
	surfaceparm noimpact
	surfaceparm nolightmap

	{
		map textures/skies/a_box1.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		tcMod scale 0.5 0.5
		tcMod scroll 0.02 0.05
		rgbGen vertex
	}	
}

textures/skies/a_box2

{
	surfaceparm noimpact
	surfaceparm nolightmap

	{
		map textures/skies/a_box2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}	
}

textures/skies/a_skybox


{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 75 0 30
	q3map_surfacelight 20
	// fogvars ( .13 .13 .14 ) .002

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

textures/skies/sky_escape1
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 65 220 18
	q3map_surfacelight 45
	fogvars ( .15 .15 .155 ) .000375
	//skyfogvars ( .23 .23 .24 ) .5

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08

		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/sky_forest
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

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}
}

textures/skies/sky_forest_block
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 512

			
	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}
}

textures/skies/sky_truckride
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 512
	q3map_sun	1.0 0.8 0.6 120 220 40
	q3map_surfacelight 35

	fogvars ( .3 .3 .305 ) .0001
	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}
}

textures/skies/sky_training
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

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}
}

textures/skies/mx_forestsky2
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

	fogvars ( .3 .3 .38 ) .000065
//	fogvars ( .3 .3 .305 ) .000095
//	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -


	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}

	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.0005 0.00
		tcMod scale 2 1
	}

	

}

textures/skies/mx_training
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	1.0 0.8 0.6 130 220 50
	q3map_surfacelight 25							

	fogvars ( .3 .3 .38 ) .000065
//	fogvars ( .3 .3 .305 ) .000095
//	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -

	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}	


//	{
//		map textures/skies/t_sky1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
///		tcMod scale 5 5
//	}

}

textures/skies/sky_osa
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
        lightgridmulamb .7
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	1.0 0.8 0.6 130 95 50
	q3map_surfacelight 25							

	fogvars ( .3 .3 .38 ) .000065
//	fogvars ( .3 .3 .305 ) .000095
//	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -

	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}	


//	{
//		map textures/skies/t_sky1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
///		tcMod scale 5 5
//	}

}

textures/skies/sky_osa_skybox
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	1.0 0.8 0.6 60 95 50
	q3map_surfacelight 25							

	fogvars ( .3 .3 .38 ) .000065
//	fogvars ( .3 .3 .305 ) .000095
//	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -

	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}	


//	{
//		map textures/skies/t_sky1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
///		tcMod scale 5 5
//	}

}

textures/skies/rf_castleskyboxsky
{
	qer_editorimage textures/skies/topclouds.tga
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
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}


// dan - cleaned up to look more like escape1
textures/skies/sky_escape2
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight	// (SA) added so dlights don't affect surface
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 70 220 18
	q3map_surfacelight 55
	fogvars ( .15 .15 .15 ) .000375
	//skyfogvars ( .23 .23 .24 ) .5
	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/sky_ice
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	0.60 0.55 0.55 70 220 60
	q3map_surfacelight 70
	fogvars ( .4 .4 .46 ) .0001
	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.003 -0.001
		tcMod scale 6 6
		depthWrite
	}
//	{
//		map textures/skies/newclouds.tga
//		blendfunc GL_ONE GL_ONE
//		tcMod scroll 0.002 0.002
///		tcMod scale 1 1
//	}
}

textures/skies/sky_spacetest
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 125 220 18
	q3map_surfacelight 45
//	fogvars ( .15 .15 .15 ) .0004
//	skyfogvars ( .23 .23 .24 ) .5

//	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
//		tcMod scroll 0.002 0.002
//		tcMod scale 1 1
//		tcMod turb 0 0.05 0 .08

	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
//		tcMod scroll -0.001 -0.005
//		tcMod scale 10 10
	}
}

textures/skies/terrain_haze
{
	qer_editorimage textures/liquids/mx_fogcloud3_alpha.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm alphashadow

//	{
//		map textures/assault_rock/hazz.tga
//		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
//		tcMod scroll -0.001 -0.005
//		tcMod scale 1 1
//		rgbGen identity
//	}
	{
		map textures/liquids/mx_fogcloud3_alpha.tga
	//	blendfunc gl_dst_color gl_zero
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	//	tcmod scale 1 1
	//	tcmod scroll .005 -.005
	//	tcmod stretch sin 1 .5 0 1
		rgbgen identity
	}

}

textures/skies/tram_skybox
{
	qer_editorimage textures/skies/topclouds.tga
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
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}


textures/skies/pink_sky

{
	qer_editorimage textures/skies/pink_skym1.tga
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
	
	//{
	//	map textures/skies/pink_skym1.tga
	//	tcMod scroll 0.002 0.002
	//	tcmod rotate -6
	//	tcMod scale .5 .5
	//	depthWrite
	//}

	{
		map textures/skies/pink_skym2.tga
	//	blendfunc GL_ONE GL_ONE
		tcMod scroll 0.001 -0.005
		tcMod scale 10 10
	}
	{
		map textures/skies/pink_skym2.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/rf_wrecked_castlesky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
        //q3map_sun	0.89 0.93 1 85 135 55
	q3map_surfacelight 85
	fogvars ( .15 .15 .155 ) .00035
	skyfogvars ( .23 .23 .24 ) .005

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08

		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/rf_newchurchsky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
        //q3map_sun	0.89 0.93 1 85 135 55
	q3map_surfacelight 45
	fogvars ( .1 .1 .1 ) .0002
	skyfogvars ( .2 .2 .2 ) .5

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08

		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}


textures/skies/rf_wrecked_castlesky_hiamb
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
        //q3map_sun	0.89 0.93 1 85 135 55
	q3map_surfacelight 95
	fogvars ( .15 .15 .155 ) .000475
	skyfogvars ( .23 .23 .24 ) .5

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08

		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}


textures/skies/rf_wrecked_castlesky_pink

{
	qer_editorimage textures/skies/pink_skym1.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
	//q3map_sun 0.89 0.93 1 85 135 55
	q3map_surfacelight 85
	fogvars ( .15 .15 .155 ) .000475
	skyfogvars ( .23 .23 .24 ) .5

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	//{
	//	map textures/skies/pink_skym1.tga
	//	tcMod scroll 0.002 0.002
	//	tcmod rotate -6
	//	tcMod scale .5 .5
	//	depthWrite
	//}

	{
		map textures/skies/pink_skym2.tga
	//	blendfunc GL_ONE GL_ONE
		tcMod scroll 0.001 -0.005
		tcMod scale 10 10
	}
	{
		map textures/skies/pink_skym2.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/cl_layer
{
	qer_editorimage textures/liquids/mx_fogcloud3_alpha.tga
	surfaceparm noimpact
	surfaceparm nolightmap

	{
		map textures/skies/dimclouds1a.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		tcmod scroll 0 -.02
//		rgbgen identity
	}

}

textures/space/neb1
{		
//	surfaceparm alphashadow
	cull none
	{
		map textures/space/neb1.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

//textures/space/star1
//{
//
//	{
//		map textures/space/star1.tga
//		rgbGen vertex
//	}
//}

textures/space/star1
{


	{
		map textures/space/star1.tga
	//	blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/skies/pink_skym2

{
	surfaceparm noimpact
	surfaceparm nolightmap


	{
		map textures/skies/pink_skym2.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		//tcMod scroll 0.001 -0.005
       		tcMod rotate 12
	//	tcMod scale 10 10
	}

}

textures/skies/mx_snowsky
{
	qer_editorimage textures/skies/topclouds.tga
//	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	0.60 0.55 0.55 70 220 60
	q3map_surfacelight 70
//	q3map_sun	1.0 0.63 0.4 90 220 50
//	q3map_surfacelight 100

//	fogvars ( .35 .35 .35 ) .0001
//	skyfogvars ( .25 .25 .255 ) .1

	fogvars ( .4 .4 .46 ) .0001
	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.003 -0.001
		tcMod scale 6 6
		depthWrite
	}
//	{
//		map textures/skies/newclouds.tga
//		blendfunc GL_ONE GL_ONE
//		tcMod scroll 0.002 0.002
///		tcMod scale 1 1
//	}
}

textures/skies/sky_beach
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 100 120 45
	q3map_surfacelight 60
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog

	fogvars ( .1 .1 .18 ) .00005
//	skyfogvars ( .23 .23 .24 ) .1

	
	{
		map textures/skies/newclouds2.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
}

textures/skies/mx_beachsky
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	0.274632 0.274632 0.38 40 120 45
	q3map_surfacelight 30
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -

	fogvars ( .1 .1 .1 ) .0005
//	skyfogvars ( .23 .23 .24 ) .1

	
	{
	//	map textures/skies/beachsky_m01.tga
		map textures/skies/newclouds2.tga
		tcMod scroll 0.005 0.0005
		tcMod scale 4.0 4.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
	
	
//	{
//		map textures/skies/beachsky_m01.tga
//		blendfunc GL_ONE GL_ONE
//	///	tcMod scroll 0.0025 0.0025
//		tcMod scale 12.0 12.0
//	}
	
//	{
//		map textures/skies/newclouds2.tga
//		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	///	tcMod scroll 0.0025 0.0025
//		tcMod scale 12.0 12.0
//	}

}

textures/skies/mx_icesky
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	0.274632 0.274632 0.38 40 120 45
	q3map_surfacelight 30
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -

	fogvars ( .1 .1 .2 ) .00005
//	skyfogvars ( .23 .23 .24 ) .1

	
	{
	//	map textures/skies/beachsky_m01.tga
		map textures/skies/newclouds2.tga
//		tcMod scroll 0.005 0.0005
		tcMod scale 4.0 4.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
	
	
//	{
//		map textures/skies/beachsky_m01.tga
//		blendfunc GL_ONE GL_ONE
//	///	tcMod scroll 0.0025 0.0025
//		tcMod scale 12.0 12.0
//	}
	
//	{
//		map textures/skies/newclouds2.tga
//		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	///	tcMod scroll 0.0025 0.0025
//		tcMod scale 12.0 12.0
//	}

}

textures/skies/rf_assaultsky
{
	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	1.0 0.63 0.4 120 220 50
	q3map_surfacelight 125
//	q3map_sun	1.0 0.63 0.4 90 220 50
//	q3map_surfacelight 100

//	fogvars ( .35 .35 .35 ) .0001
//	skyfogvars ( .25 .25 .255 ) .1

	fogvars ( .25 .25 .255 ) .0001
	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.001 -0.003
		tcMod scale 6 6
		depthWrite
	}
//	{
//		map textures/skies/newclouds.tga
//		blendfunc GL_ONE GL_ONE
//		tcMod scroll 0.002 0.002
///		tcMod scale 1 1
//	}
}


textures/skies/mx_assaultsky

{
//	qer_editorimage textures/skies/topclouds.tga
//	q3map_lightimage textures/skies/n_blue.tga


	qer_editorimage textures/skies/topclouds.tga
	q3map_lightimage textures/skies/n_blue.tga

	nocompress
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	1.0 0.8 0.8 160 295 15
	q3map_surfacelight 40

//	fogvars ( .35 .35 .35 ) .0001
//	skyfogvars ( .25 .25 .255 ) .1
	fogvars ( .25 .25 .255 ) .00002
//	skyfogvars ( .23 .23 .24 ) .25

	skyparms full 200 -
	
	{
		map textures/skies/sunset1.tga
	//	tcMod scroll -0.001 -0.003
		tcMod scale 1 1
		depthWrite
	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.0005 0.00
		tcMod scale 2 1
	}
}


//*******************************************************
//*              Rich's Bigtram sky 
//*
//* Note: Original qer_editorimage is sky_m01, m01dm
//*
//*******************************************************
textures/skies/rf_bigtramsky
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nodlight
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_surfacelight 35
	skyparms full 200 -
	fogvars ( .4 .4 .45 ) 5632	

	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/rf_damsky
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 100 120 45
	q3map_surfacelight 25
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog

	fogvars ( .1 .1 .18 ) .00005
//	skyfogvars ( .23 .23 .24 ) .1

	
	{
	//	map textures/skies/beachsky_m01.tga
		map textures/skies/newclouds2.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
	
	
//	{
//		map textures/skies/beachsky_m01.tga
//		blendfunc GL_ONE GL_ONE
//	///	tcMod scroll 0.0025 0.0025
//		tcMod scale 12.0 12.0
//	}
	
//	{
//		map textures/skies/newclouds2.tga
//		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	///	tcMod scroll 0.0025 0.0025
//		tcMod scale 12.0 12.0
//	}

}
textures/skies/sky_chateau_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 20 35 45
	q3map_surfacelight 20
	//q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog

//	fogvars ( .1 .1 .18 ) .0005
//	skyfogvars ( .23 .23 .24 ) .1

	
	{
		map textures/skies/newclouds2.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	/////// moon test ////////////////////////
	//	map textures/skies/sky_m01_moon.tga
	//	blendfunc GL_ONE GL_ONE
	///	tcMod scroll 0.0025 0.0025
	//	tcMod scale 1.0 1.0
	//	depthWrite
}

textures/skies/sky_chateau_night2
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.39 30 35 45
	q3map_surfacelight 27
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun
	fogvars ( .15 .15 .15 ) .0001
	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky1.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	{
		map textures/skies/vil_clouds1.tga
		blendfunc blend
		tcMod scroll 0.001 0.00
		tcMod scale 2 1
	}


}


textures/skies/sky_dam_sunrise
{
	qer_editorimage textures/skies/topclouds.tga
	
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	
	q3map_lightimage textures/skies/n_blue.tga
	q3map_globaltexture
	q3map_lightsubdivide 4096
	q3map_sun	1.0 0.8 0.8 80 295 35
	q3map_surfacelight 10
	

	fogvars ( .25 .25 .255 ) .000035
	skyparms full 200 -
	
	{
		map textures/skies/sunset1.tga
		tcMod scale 1 1
		depthWrite
	}
}

textures/skies/sky_village2_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.39 30 35 45
	q3map_surfacelight 27
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun
//	fogvars ( .15 .15 .15 ) .0001
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky1.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	{
		map textures/skies/vil_clouds1.tga
		blendfunc blend
		tcMod scroll 0.001 0.00
		tcMod scale 2 1
	}


}


textures/skies/sky_END_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	lightgridmulamb 2
	lightgridmuldir 3
	q3map_globaltexture
//	q3map_lightsubdivide 512 
	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 30 35 45
	q3map_surfacelight 27
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun
	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

//	{
//		map textures/skies/vil_clouds1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
//		tcMod scale 2 1
//	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}

}

textures/skies/sky_dam_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
//	lightgridmulamb 2
//	lightgridmuldir 3
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 30 315 45
	q3map_surfacelight 11
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun

	fogvars ( .15 .15 .15 ) .0001
	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky1.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	{
		map textures/skies/vil_clouds1.tga
		blendfunc blend
		tcMod scroll 0.001 0.00
		tcMod scale 2 1
	}


}

textures/skies/sky_dam_night_skybox
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
//	lightgridmulamb 2
//	lightgridmuldir 3
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.39 10 315 45
	q3map_surfacelight 1
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun

	fogvars ( .0015 .0015 .0015 ) .0001
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky1.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	{
		map textures/skies/vil_clouds1.tga
		blendfunc blend
		tcMod scroll 0.001 0.00
		tcMod scale 2 1
	}


}


textures/skies/sky_boss2
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	1.0 0.63 0.4 50 200 50
	q3map_surfacelight 115
	fogvars ( .2 .2 .2 ) .00002

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 5 5
	}
}

textures/skies/sky_snow
{
	qer_editorimage textures/skies/topclouds.tga
//	q3map_lightimage textures/skies/n_blue.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	q3map_globaltexture
	q3map_lightsubdivide 2048
	q3map_sun	0.60 0.55 0.55 70 220 60
	q3map_surfacelight 70
//	q3map_sun	1.0 0.63 0.4 90 220 50
//	q3map_surfacelight 100

//	fogvars ( .35 .35 .35 ) .0001
//	skyfogvars ( .25 .25 .255 ) .1

	fogvars ( .4 .4 .46 ) .0001
	skyfogvars ( .23 .23 .24 ) .1

	skyparms full 200 -
	
	{
		map textures/skies/newclouds.tga
		tcMod scroll -0.003 -0.001
		tcMod scale 6 6
		depthWrite
	}
//	{
//		map textures/skies/newclouds.tga
//		blendfunc GL_ONE GL_ONE
//		tcMod scroll 0.002 0.002
///		tcMod scale 1 1
//	}
}


// Dark Road Sky
textures/skies/sky_dark
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	lightgridmulamb 2
	lightgridmuldir 4
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun 0.274632 0.274632 0.358662 22 325 28
	q3map_surfacelight 12
	skyparms full 200 -
	fogvars ( 0.09 .09 .13 ) 2400	

	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/sky_norway
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	//q3map_sun	0.274632 0.274632 0.358662 30 325 35
	q3map_surfacelight 55
	skyparms full 200 -
	fogvars ( .4 .4 .45 ) 2700	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/dak_endsky
{
	qer_editorimage textures/skies/topclouds.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	q3map_globaltexture
	q3map_lightsubdivide 512 
        q3map_sun	0.89 0.93 1 85 85 75
	q3map_surfacelight 85
	fogvars ( .15 .15 .155 ) .00035
	skyfogvars ( .23 .23 .24 ) .005

	surfaceparm nodlight	// (SA) added so dlights don't affect surface

	skyparms full 200 -
	
	{
		map textures/skies/dimclouds.tga
		tcMod scroll 0.002 0.002
		tcMod scale 1 1
		tcMod turb 0 0.05 0 .08

		depthWrite
	}
	{
		map textures/skies/dimclouds.tga
		blendfunc GL_ONE GL_ONE
		tcMod scroll -0.001 -0.005
		tcMod scale 10 10
	}
}

textures/skies/sky_dak_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512
	q3map_sun	0.89 0.93 1 85 85 75
	q3map_surfacelight 85
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun
	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

//	{
//		map textures/skies/vil_clouds1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
//		tcMod scale 2 1
//	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}

}

textures/skies/sky_boss1_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_sun	1.0 0.63 0.4 110 275 25
	q3map_surfacelight 110
	fogvars ( .15 .15 .16 ) .0003
	skyfogvars ( .23 .23 .24 ) .5
	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog
	sunshader sun
//	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}

}

textures/skies/sky_boss1_b25
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_sun	1.0 0.63 0.4 45 275 25
	q3map_surfacelight 45
	fogvars ( .15 .15 .16 ) .0003
	skyfogvars ( .23 .23 .24 ) .5
	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog
	sunshader sun
//	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}
}


textures/skies/sky_boss1_skybox
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_sun	1.0 0.63 0.4 30 275 25
	q3map_surfacelight 17
	fogvars ( .15 .15 .16 ) .0003
	skyfogvars ( .23 .23 .24 ) .75
	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog
	sunshader sun
//	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}
}

textures/skies/sky_boss2_2
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
//	q3map_sun	0.274632 0.274632 0.358662 30 325 35
	q3map_surfacelight 35
	skyparms full 200 -
	fogvars ( .2 .2 .2 ) .00002	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/sky_baseout_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 25 315 45
	q3map_surfacelight 15
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun

	fogvars ( .15 .15 .15 ) .0001
	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky1.tga
	//	tcMod scroll 0.005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

	{
		map textures/skies/vil_clouds1.tga
		blendfunc blend
		tcMod scroll 0.001 0.00
		tcMod scale 2 1
	}


}

textures/skies/sky_briefingroom
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	//q3map_sun	0.274632 0.274632 0.358662 30 325 35
	//q3map_surfacelight 35
	skyparms full 200 -
	fogvars ( .4 .4 .45 ) .005	
	
	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/sky_castle_night
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
//	lightgridmulamb 2
//	lightgridmuldir 3
	q3map_globaltexture
	q3map_lightsubdivide 512
 //	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 30 225 45
	q3map_surfacelight 27
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun
	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

//	{
//		map textures/skies/vil_clouds1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
//		tcMod scale 2 1
//	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}

}

textures/skies/sky_castle_night_skybox
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
//	lightgridmulamb 2
//	lightgridmuldir 3
	q3map_globaltexture
	q3map_lightsubdivide 512
 //	q3map_lightsubdivide 2048 
	q3map_sun	0.274632 0.274632 0.39 30 225 45
	q3map_surfacelight 8
//	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
//	nofog
	sunshader sun
	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}

//	{
//		map textures/skies/vil_clouds1.tga
//		blendfunc blend
//		tcMod scroll 0.001 0.00
//		tcMod scale 2 1
//	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}

}

// Dig Sky
textures/skies/sky_dig
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 2048 
	q3map_sun 0.274632 0.274632 0.358662 22 325 28
	q3map_surfacelight 12
	skyparms full 200 -
	fogvars ( 0.09 .09 .13 ) 2400	

	{
		map textures/skies/sky_m01dmcmp.tga
		blendfunc GL_ONE GL_ONE
		tcMod scale 12.0 12.0
	}
}

textures/skies/sky_wreck
{
	qer_editorimage textures/skies/sky_m01dmcmp
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm nodlight
	surfaceparm sky
	q3map_globaltexture
	q3map_lightsubdivide 512 
	q3map_sun	0.274632 0.274632 0.358662 35 135 45
	q3map_surfacelight 75
	fogvars ( .096 .09 .09 ) .0004	
//	skyfogvars ( .23 .23 .24 ) .15
	nopicmip
	nocompress
	skyparms full 200 -
	{
		map textures/skies/dimclouds2.tga
		rgbGen const ( 0.3 0.3 0.3 )
		blendfunc GL_ONE GL_ZERO
		tcMod scroll 0.002 0.002
		tcMod scale 8.0 8.0
	}
	
	{
		map textures/skies/dimclouds2.tga
		blendfunc GL_ONE GL_ONE
		rgbGen const ( 0.2 0.2 0.2 )
		tcMod scroll -0.001 -0.004
		tcMod scale 10 10
	}
}

textures/skies/sky_xlabdm
{
	nocompress
	qer_editorimage textures/skies/beachsky_m01
	q3map_lightimage textures/skies/n_blue2.tga
	surfaceparm noimpact
	surfaceparm nolightmap
	surfaceparm sky
	q3map_globaltexture
	q3map_sun	1.0 0.63 0.4 110 270 80
	q3map_surfacelight 110
	fogvars ( .15 .15 .16 ) .0003
	skyfogvars ( .23 .23 .24 ) .5
	q3map_lightrgb .1 0.1 0.5
	skyparms full 200 -
	nofog
	sunshader sun
//	fogvars ( .07 .07 .09 ) .0002
//	skyfogvars ( .23 .23 .24 ) .01

	
	{
		map textures/skies/nightsky2.tga
		tcMod scroll 0.0005 0.0005
		tcMod scale 16.0 16.0
		depthWrite
	}
	{
		map textures/skies/assa_clouds1.tga
		blendfunc blend
		tcMod scroll 0.005 0.00
		tcMod scale 2 1
	}

}
