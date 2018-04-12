ntextures/town_wall/church_c01_shadow
{
	qer_editorimage town_wall/church_c01.tga
	{
		map textures/town_wall/church_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map $lightmap
		rgbGen identity
		tcMod scale 1 1
		tcMod turb 0 .1 0 .1
	}

}

///assualtmachine///
textures/assault/machine_cl01
{
	{
		map textures/assault/elec1.tga
//		blendFunc GL_ONE GL_ZERO
//		rgbGen lightingdiffuse
//		tcGen environment 
		tcMod scale 2 2
		tcMod scroll 2 2
	}
	{
		map textures/assault/machine_cl01.tga
		blendfunc blend
		rgbGen identity
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}


}

textures/castle_wood/cwood_mo2_bak
{
	qer_editorimage castle_wood/cwood_mo2.tga
	{
		map textures/effects/wdfx.tga
		blendfunc GL_ONE GL_ZERO
		tcMod turb 0 0.015 0 0.025
		rgbGen diffuse
		tcGen environment
	}



	{
		map textures/castle_wood/cwood_mo2.tga
//		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA 
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA 
		rgbGen identity
		alphaGen lightingSpecular
	}


//	{
//		map $lightmap
//		rgbGen identity
//	}
        {
		map $lightmap
                blendFunc GL_ONE_MINUS_DST_ALPHA GL_DST_COLOR 
		rgbGen identity
	}
}


textures/castle_wood/cwood_mo2
{
	{
		map textures/castle_wood/cwood_mo2s1.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/wdfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}


textures/castle_wall/castle_c35a
{
	{
		map textures/castle_wall/castle_c35a.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/wdfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}


textures/castle_wall/c_test_m46a
{
	{
		map textures/castle_wall/c_test_m46a.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/wdfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo2_mirror
{
	qer_editorimage textures/castle_wood/cwood_mo2s1.tga
	portal

	// mirror pass
	{
		map textures/common/mirror1.tga
		blendfunc GL_ONE GL_ONE
		depthWrite
	}

	// texture pass
	{
		map textures/castle_wood/cwood_mo2s1.tga
		blendFunc GL_ONE GL_ONE_MINUS_SRC_ALPHA 
		rgbGen identity
	}

	// lightmap pass
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/castle_floor/floor_m01
{
	qer_editorimage textures/castle_floor/floor_m01.tga
	portal

	// mirror pass
	{
		map textures/common/mirror1.tga
		blendfunc GL_ONE GL_ONE
		depthWrite
	}

	// texture pass
	{
		map textures/castle_floor/floor_m01.tga
		blendFunc GL_ONE GL_ONE_MINUS_SRC_ALPHA   
		rgbGen identity
	}

	// lightmap pass
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA 
		rgbGen identity
	}
}


///////////  flag maxx ///////


textures/props/flags_temp
{
	surfaceparm alphashadow
	// qer_trans 0.50
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flags_temp.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flag_c03dmtad
{
	surfaceparm alphashadow
	qer_trans 0.9

	cull twosided
	{
		map textures/props/flag_c03dmtad.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}
textures/props/flags_temptad
{
	surfaceparm alphashadow
	 qer_trans 0.90
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flags_temptad.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flags_m1
{
	surfaceparm alphashadow
	// qer_trans 0.50
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flags_m1.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flags_m1_snow

{
	surfaceparm nolightmap // added as test
	surfaceparm trans // added as test
	surfaceparm alphashadow 
	// qer_trans 0.50
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flags_m1_snow.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flags_m1_snowtad

{
	surfaceparm alphashadow
	 qer_trans 0.90
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flags_m1_snowtad.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flags_m1_fac

{
	surfaceparm alphashadow
	 qer_trans 0.90
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flags_m1_fac.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flag_l_m01

{

	// qer_trans 0.50
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/props/flag_l_m01.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flag_l_m01nomove

{
	qer_editorimage textures/props/flag_l_m01.tga

	// qer_trans 0.50
	cull twosided
	{
		map textures/props/flag_l_m01.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flag_l_m01_tad

{
	qer_editorimage textures/props/flag_l_m01_tad.tga

	// qer_trans 0.50
	cull twosided
	{
		map textures/props/flag_l_m01_tad.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}



//// maxx window /////

textures/castle_props/castle_m11b
{
	qer_editorimage textures/castle_props/castle_m11b.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/castle_props/castle_m11b.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_props/castle_m11b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/castle_props/castle_m11b.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

//// maxx window /////

textures/castle_props/castle_m11c
{
	qer_editorimage textures/castle_props/castle_m11c.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/castle_props/castle_m11c.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_props/castle_m11c.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/castle_props/castle_m11c.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

//// Claire window /////

textures/cathedrale_wall/cathedrale_c02
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c02.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c02.tga
	q3map_surfacelight 200
	light 1

	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c02.blend.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/cathedrale_wall/cathedrale_c16
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c16.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c16.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c16.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c16.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/cathedrale_wall/cathedrale_c17
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c17.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c17.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c17.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c17.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/cathedrale_wall/cathedrale_c35
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c35.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c35.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c35.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c35.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/cathedrale_wall/cathedrale_c36
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c36.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c36.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c36.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c36.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/cathedrale_wall/cathedrale_c37
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c37.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c37.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c37.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c37.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/cathedrale_wall/cathedrale_c44
{
	qer_editorimage textures/cathedrale_wall/cathedrale_c44.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/cathedrale_wall/cathedrale_c44.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c44.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/cathedrale_wall/cathedrale_c44.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}


textures/snow/s_ca_window_c01
{
	qer_editorimage textures/snow/s_ca_window_c01.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/snow/s_ca_window_c01.tga
	q3map_surfacelight 200
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_ca_window_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO	
		rgbGen identity
	}
	{
		map textures/snow/s_ca_window_c01.BLEND.tga
		blendfunc GL_ONE GL_ONE
	
	}
}

textures/castle_props/castle_c28
{
	qer_editorimage textures/castle_props/castle_c28.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/castle_props/castle_c28.tga
	q3map_surfacelight 100
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_props/castle_c28.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/castle_props/castle_c28.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/village/villwin_c12
{
	qer_editorimage textures/village/villwin_c12.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c12.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villwin_c12.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village/villwin_c12.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/village/villwin_c12a
{
	qer_editorimage textures/village/villwin_c12a.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c12.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villwin_c12a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village/villwin_c12a.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/village/villwin_c12m
{
	{
		map textures/village/villwin_c12m.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/vilfx2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/village/vill2_win_m1
{
	{
		map textures/village/vill2_win_m1.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/vilfx2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}


textures/village/vill2_inwin1
{
	qer_editorimage textures/village/villwin_c12m.tga
	{
		map textures/village/villwin_c12m.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/vilfx2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/chateau/window_c01
{
	qer_editorimage textures/chateau/window_c01.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/chateau/window_c01a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chateau/window_c02a
{
	qer_editorimage textures/chateau/window_c02a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue2.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c02a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c02.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}




////////////////            maxx new window shader ///////////////



textures/chateau/window_c03a
{
	qer_editorimage textures/chateau/window_c03a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue.tga       // color for window
	q3map_surfacelight 300
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chateau/window_director
{
	qer_editorimage textures/chateau/window_c03a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue.tga       // color for window
	q3map_surfacelight 3000
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chateau/window_c03a_750
{
	qer_editorimage textures/chateau/window_c03a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue.tga       // color for window
	q3map_surfacelight 750
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chateau/window_c03a_1250
{
	qer_editorimage textures/chateau/window_c03a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue.tga       // color for window
	q3map_surfacelight 1250
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}


textures/chateau/window_c03a_2500
{
	qer_editorimage textures/chateau/window_c03a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue.tga       // color for window
	q3map_surfacelight 2500
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}


textures/chateau/window_c03a_nolight
{
	qer_editorimage textures/chateau/window_c03a.tga
	// surfaceparm nomarks
	//q3map_lightimage textures/chateau/soft_blue.tga       // color for window
	//q3map_surfacelight 300
	//q3map_lightsubdivide 64
	//light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	
}


textures/chateau/window_c04a
{
	qer_editorimage textures/chateau/window_c04a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_blue2.tga
	q3map_surfacelight 300
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c04a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c02.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chateau/window_c05a
{
	qer_editorimage textures/chateau/window_c05a.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_warm.tga       // color for window
	q3map_surfacelight 300
	q3map_lightsubdivide 64
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c05a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c05.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chateau/window_c06
{
	qer_editorimage textures/chateau/window_c06.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/chateau/window_c06a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c06.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chateau/window_c07a
{
	qer_editorimage textures/chateau/window_c07a.tga
	surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_warm.tga //color for window
	q3map_surfacelight 80
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c07a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c05.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chateau/window_c10e
{
	qer_editorimage textures/chateau/window_c10e.tga
//	surfaceparm glass
//	q3map_lightimage textures/chateau/soft_warm.tga       // color for window
//	q3map_surfacelight 80
//	q3map_lightsubdivide 128
//	light 1

	{
		map textures/chateau/window_c10e.tga
		rgbGen identity
	}

}
textures/chateau/window_c11e
{
	qer_editorimage textures/chateau/window_c11e.tga
 	surfaceparm nomarks
//	q3map_lightimage textures/chateau/soft_warm.tga       // color for window
//	q3map_surfacelight 80
//	q3map_lightsubdivide 128
//	light 1

	{
		map textures/chateau/window_c11e.tga
		rgbGen identity
	}

}

textures/chateau/window_c08a

{
	qer_editorimage textures/chateau/window_c08a.tga
	surfaceparm nomarks
	q3map_lightimage textures/lightimage/soft_warm2.tga 
	q3map_surfacelight 300
	q3map_lightsubdivide 64
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c08a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c04.blend.tga
		blendfunc GL_ONE GL_ONE
	}

}




////////////////  maxx new window shader end  ///////////////



textures/chateau/window_c01a
{
	qer_editorimage textures/chateau/window_c01a.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/chateau/window_c01a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c01a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chateau/window_c02a
{
	qer_editorimage textures/chateau/window_c02a.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/chateau/window_c02a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c02a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c02.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chateau/window_c06a
{
	qer_editorimage textures/chateau/window_c06a.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/chateau/window_c06a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/window_c06a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_c05.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
//textures/chateau/window_c08a
//{
//	qer_editorimage textures/chateau/window_c08a.tga
//	// surfaceparm nomarks
//	// q3map_lightimage textures/chateau/window_c08a.tga
//	q3map_surfacelight 300
//	light 1
//
//
//	{
//		map $lightmap
//		rgbGen identity
//	}
//	{
//		map textures/chateau/window_c08a.tga
//		blendFunc GL_DST_COLOR GL_ZERO
//		rgbGen identity
//	}
//	{
//		map textures/chateau/window_c06.blend.tga
//		blendfunc GL_ONE GL_ONE
//	}
//}













textures/village_door/villdoor_c03
{
	qer_editorimage textures/village_door/villdoor_c03.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village_door/villdoor_c03.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village_door/villdoor_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village_door/villdoor_c03.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/village_door/villdoor_c04
{
	qer_editorimage textures/village_door/villdoor_c04.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village_door/villdoor_c04.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village_door/villdoor_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village_door/villdoor_c04.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/village_door/villdoor_c05
{
	qer_editorimage textures/village_door/villdoor_c05.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village_door/villdoor_c05.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village_door/villdoor_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village_door/villdoor_c05.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chat_door/door_c12
{
	qer_editorimage textures/chat_door/door_c12.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/chat_door/door_c12.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_door/door_c12.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_door/door_c12.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}


textures/village/villwin_c12
{
	qer_editorimage textures/village/villwin_c12.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c12.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villwin_c12.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village/villwin_c12.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}



textures/terrain/weed_m02
{
	// qer_trans 0.50
//	deformVertexes wave 194 sin 0 2 0 .1
//	deformVertexes wave 30 sin 0 1 0 .3
//	deformVertexes wave 194 sin 0 1 0 .4
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided
	{
		map textures/terrain/weed_m02.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/terrain/weed_m01
{

	cull twosided
	{
		map textures/terrain/weed_m01.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

///// xlab  door maxx  ////

textures/xlab_door/xdoor_m01
{
	{
		map textures/xlab_door/xdoor_m01.tga
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

textures/awf/adoor_m02
{
	{
		map textures/awf/adoor_m02.tga
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

textures/metal_misc/metal_m01ss
{
	{
		map textures/metal_misc/metal_m01ss.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx5.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1 1  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/miltary_door/mdoor_m09
{
	{
		map textures/miltary_door/mdoor_m09.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/chrome2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 2 2  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/miltary_door/mdoor_m10
{
	{
		map textures/miltary_door/mdoor_m10.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/chrome2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 2 2  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/miltary_door/mdoor_m11
{
	{
		map textures/miltary_door/mdoor_m11.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/chrome2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 2 2  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}
textures/metal_misc/metal_m03ss
{
	surfaceparm metalsteps
	{
		map textures/metal_misc/metal_m03ss.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx5.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

//textures/metal_misc/metal_m04ss
//{
//	{
//		map textures/metal_misc/metal_m04ss.tga
//		blendFunc GL_ONE GL_ZERO
//		rgbGen identity
//	}
//	{
//		map textures/effects/tinfx5.tga
//		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
//		tcMod Scale 1.5 1.5  
//		tcGen environment
//	}
//	{
//		map $lightmap
//		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
//		rgbGen identity
//	}
//}




textures/metal_misc/metal_m04ss_osa
{
	{
		map textures/metal_misc/metal_m04ss_osa.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx5.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/metal_misc/metal_m05ss
{
	
		
	{
		map textures/metal_misc/metal_m05ss.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx5.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}


textures/metal_misc/metal_m02ss
{
	
	surfaceparm roofsteps
	q3map_lightmapsamplesize 1

	{
		map textures/metal_misc/metal_m02ss.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 2 2  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR 				      GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}


textures/xlab_wall/xmetal_m01
{
	

	{
		map textures/effects/tinfx.tga
	        rgbGen identity
		tcGen environment
		tcmod scale .5 .5
	}
	
	{
		map textures/xlab_wall/xmetal_m01.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA	
		rgbGen identity
	}
	{
		map $lightmap
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/xlab_wall/xmetal_m02
{
	surfaceparm metalsteps

	{
		map textures/xlab_wall/xmetal_m02.tga
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

textures/xlab_wall/xmetal_m02a
{
	surfaceparm metalsteps
	{
		map textures/xlab_wall/xmetal_m02a.tga
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



textures/xlab_wall/xmetal_m02a_trim
{
	surfaceparm metalsteps
	{
		map textures/xlab_wall/xmetal_m02a_trim.tga
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

textures/xlab_wall/xmetal_m02f
{
	surfaceparm metalsteps
	qer_editorimage textures/xlab_wall/xmetal_m02.tga
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xmetal_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xmetal_m03
{
	{
		map textures/xlab_wall/xmetal_m03.tga
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

textures/metal_misc/ametal_m03_spec
{

	{
		map textures/metal_misc/ametal_m03_spec.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/wdfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 2 2  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}


textures/xlab_door/xdoor_m01f
{
	{
		map textures/xlab_door/xdoor_m01f.tga
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

textures/props/tram_s3_1

{
	qer_editorimage textures/props/tram_s3.tga
	surfaceparm alphashadow		
	cull none
	{
		map textures/props/tram_s3.tga
		alphaFunc GE128
		rgbGen vertex
		depthWrite
	}
}

textures/props/tram_s3_ns1

{
	qer_editorimage textures/props/tram_s3ns.tga
	surfaceparm alphashadow		
	cull none
	{
		map textures/props/tram_s3ns.tga
		alphaFunc GE128
		rgbGen vertex
		depthWrite
	}
}

textures/props/tram_s6_1

{
	qer_editorimage textures/props/tram_s6.tga
	surfaceparm alphashadow		
	cull none
	{
		map textures/props/tram_s6.tga
		alphaFunc GE128
		rgbGen vertex
		depthWrite
	}
}


textures/xlab_wall/xmetal_c01
{
	{
		map textures/xlab_wall/xmetal_c01.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx4.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 3 3 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}
textures/xlab_wall/xmetal_c01b
{
	{
		map textures/xlab_wall/xmetal_c01b.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx9.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 3 3 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}





textures/xlab_wall/xmetal_c02
{
	{
		map textures/xlab_wall/xmetal_c02.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx4.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 3 3 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/xlab_wall/xconcrete_c50
{
	{
		map textures/xlab_wall/xconcrete_c50.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1 1 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/atest/wood_c03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/atest/wood_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/atest/ametal_m01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/atest/ametal_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/atest/floor_l_02
{
	surfaceparm gravelsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/atest/floor_l_02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}




textures/castle_wood/cwood_c10
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_c10.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo2b
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_mo2b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo7_C
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_mo7_C.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo2bdm
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_mo2bdm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/diamond_c_01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/diamond_c_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/diamond_c_01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/diamond_c_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/metal_misc/diamond_m_02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/diamond_m_02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/miltary_floor/floor_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/miltary_floor/floor_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_grass_ml03a
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_grass_ml03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_grass_ml03a_s
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_grass_ml03a_s.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chat_wood/chwood_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_wood/chwood_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chat_wood/chwood_c04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_wood/chwood_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_floor_l_01
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_floor_l_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/floor_c06
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/floor_c06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/wood_c05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/door_c05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/door_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/chateau/desk_c05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/desk_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/desk_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/desk_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/desk_c03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/desk_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/desk_c04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/desk_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/doors/door_c08
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/doors/door_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/doors/door_c13
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/doors/door_c13.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/doors/door_c05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/doors/door_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/chateau/wood_c07
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_c07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/wood_c09
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_c09.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/wood_c06
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_c06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/wood_c20
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_c20.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/wood_c22
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_c22.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/wood_test
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/wood_test.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/trim_c10
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/trim_c10.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/trim_c14
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/trim_c14.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/trim_c03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/trim_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/trim_c09
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/trim_c09.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/trim_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/trim_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/trim_c08
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/trim_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/stair_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/stair_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/graveyard/gy_door_01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/graveyard/gy_door_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/graveyard/gy_door_04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/graveyard/gy_door_04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo5c
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_mo5c.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/chateau/furniture_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/furniture_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/fireplace_01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/fireplace_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/book_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/book_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chateau/floor_c04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chateau/floor_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/tabletop_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/tabletop_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/wine_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/wine_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/wine_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/wine_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/town_wood/wood_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wood/wood_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/snow/s_castle_m03_step_2a
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_castle_m03_step_2a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/rock/s_roc_c30c
{
	surfaceparm snowsteps
	q3map_lightmapsamplesize 32
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/rock/s_roc_c30c.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_castle_m03a_step
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_castle_m03a_step.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_t_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_t_m01a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m01a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_t_m04b
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m04b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/board_cl01m
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/board_cl01m.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/miltary_wall/miltary_m06
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/miltary_wall/miltary_m06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/miltary_wall/miltary_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/miltary_wall/miltary_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/props/box_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_m02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_m03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_m04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_m05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_m05a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m05a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault_rock/rock_c02asnow2
{
	surfaceparm rubble
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault_rock/rock_c02asnow2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


//	{"metal",	0,	SURF_METAL,0 },
//	{"metalsteps",	0,	SURF_METAL,0 },
//	{"flesh",	0,	SURF_FLESH,0 },
//	{"nosteps",	0,	SURF_NOSTEPS,0 },
//	{"woodsteps",	0,	SURF_WOOD,0 },
//	{"grasssteps",	0,	SURF_GRASS,0 },
//	{"gravelsteps",	0,	SURF_GRAVEL,0 },
//	{"snowsteps",	0,	SURF_SNOW,0 },
//	{"roofsteps",	0,	SURF_ROOF,0 },	// tile roof type sound




textures/castle_floor/floor_c10
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_floor/floor_c10.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo6
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_mo6.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_floor/floor_c10_a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_floor/floor_c10_a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chat_window/chwindow_c01
{
	qer_editorimage textures/chat_window/chwindow_c01.tga
	surfaceparm nomarks
	Q3map_lightimage textures/lightimage/ltblue_m1.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chat_window/chwindow_c02
{
	qer_editorimage textures/chat_window/chwindow_c02.tga
	surfaceparm nomarks
	q3map_lightimage textures/lightimage/ltblue_m1A.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c02.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chat_window/chwindow_c03
{
	qer_editorimage textures/chat_window/chwindow_c03.tga
	surfaceparm nomarks
	q3map_lightimage textures/lightimage/ltblue_m1A.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c03.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chat_window/chwindow_c04
{
	qer_editorimage textures/chat_window/chwindow_c04.tga
	surfaceparm nomarks
	Q3map_lightimage textures/lightimage/ltblue_m1a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c04.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chat_window/chwindow_c05
{
	qer_editorimage textures/chat_window/chwindow_c05.tga
	surfaceparm nomarks
	Q3map_lightimage textures/lightimage/ltblue_m1a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c05.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chat_window/chwindow_c06
{
	qer_editorimage textures/chat_window/chwindow_c06.tga
	surfaceparm nomarks
	Q3map_lightimage textures/lightimage/chwindow_c06.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c06.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/chat_window/chwindow_c07
{
	qer_editorimage textures/chat_window/chwindow_c07.tga
	surfaceparm nomarks
	Q3map_lightimage textures/lightimage/ltblue_m1a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c07.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/chat_window/chwindow_c08
{
	qer_editorimage textures/chat_window/chwindow_c08.tga
	surfaceparm nomarks
	Q3map_lightimage textures/lightimage/ltblue_m1a.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chat_window/chwindow_c08.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
 
textures/terrain/grass_ml03amx
{
	{
		qer_editorimage textures/terrain/grass_ml03mx.tga
		map $lightmap
		rgbGen identity
	}
	{
//		map textures/terrain/grass_ml03mx.tga
//		map textures/terrain/grassdetail.tga
		map textures/terrain/grassdetail2_crop.tga
//		map textures/terrain/grassdetail3_crop.tga

		// (my way)
		blendFunc GL_DST_COLOR GL_ONE

		// (id way)
//		blendFunc GL_DST_COLOR GL_SRC_COLOR
//		detail
		tcMod scale 9 9.1
	}
	{
		map textures/terrain/grass_ml03mx.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
//		tcMod scale .3 .3
	}
}

textures/terrain/grass_ml03mxaa
{
	qer_editorimage textures/terrain/grass_ml03mx.tga
	nomipmap
	surfaceparm grasssteps		
	cull none
	{
		map textures/terrain/grass_ml03mx.tga
		alphaFunc GE128
		rgbGen vertex
		depthWrite
	}
}


textures/assault_rock/ground_c07
{
	surfaceparm gravelsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault_rock/ground_c07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault_rock/ground_m0s7
{
	surfaceparm gravelsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault_rock/ground_m07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault_rock/ground_c07a
{
	surfaceparm gravelsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault_rock/ground_c07a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/diamond_m03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/diamond_m03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/town_wood/trenchwood
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wood/trenchwood.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/terrain/cliff_m05C
{
	surfaceparm grasssteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/terrain/cliff_m05C.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault_rock/ground_c09a
{
	surfaceparm grasssteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault_rock/ground_c09a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/terrain/cliff_m05D2
{
	surfaceparm grasssteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/terrain/cliff_m05D2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/metal_c02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/metal_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/ametal_m04a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/ametal_m04a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/ametal_m03a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/ametal_m03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/sho_box_c01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/sho_box_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/sho_box_c02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/sho_box_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/sho_box_c03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/sho_box_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_c03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/sub1
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/sub1.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}





textures/chat_window/chwindow_c08
{
    q3map_lightimage textures/lightimage/ltblue_m1a.tga
    qer_editorimage textures/chat_window/chwindow_c08.tga
    q3map_surfacelight 300
    light 1
    surfaceparm nomarks
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat_window/chwindow_c08.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
    {
        map textures/chat_window/chwindow_c08.blend.tga
        blendFunc GL_ONE GL_ONE
    }
}

textures/rock/dam_m01
{
    {
        map textures/rock/dam_m01.tga
        rgbGen identity
    }
}

textures/rock/dam_m01a
{
//    nofog
    {
        map textures/rock/dam_m01a.tga
	blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen identity
    }
}

textures/chat/carpet_c14trim
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c14trim.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}


textures/chateau/floor_c10
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chateau/floor_c10.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/chateau/floor_c10a
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chateau/floor_c10a.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}



textures/chat/carpet_c11
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c11.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/chat/carpet_c12
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c12.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}



textures/props/cable_m_m01
{
 
    surfaceparm metalsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/props/cable_m_m01.tga
        blendFunc GL_DST_COLOR GL_ZERO
	tcMod scroll 1 1	
        rgbGen identity
    }
}

textures/props/cable_m01
{
  
    surfaceparm metalsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/props/cable_m01.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}


textures/terrain/grass_ml03
{
  
    surfaceparm grasssteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/terrain/grass_ml03.tga
        blendFunc GL_DST_COLOR GL_ZERO	
        rgbGen identity
    }
}


textures/rock/s_roc_c30
{
  

    surfaceparm nolightmap
    surfaceparm snowsteps

	q3map_smoothinggroup 1

    {
        map textures/rock/s_roc_c30.tga
      //blendFunc GL_DST_COLOR GL_ZERO	
        rgbGen exactvertex
    }
}

// (SA) created (11/9/00)
textures/rock/s_roc_c30b
{
  

    surfaceparm nolightmap
    surfaceparm snowsteps

	q3map_smoothinggroup 1

    {
        map textures/rock/s_roc_c30b.tga
      //blendFunc GL_DST_COLOR GL_ZERO	
        rgbGen exactvertex
    }
}


textures/metal_misc/ametal_m03_vertex
{
    surfaceparm metalsteps
    {
        map textures/metal_misc/ametal_m03_vertex.tga	
        rgbGen vertex
    }
}

textures/graveyard/gy_ml03
{

    surfaceparm grasssteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/graveyard/gy_ml03.tga
        blendFunc GL_DST_COLOR GL_ZERO	
        rgbGen identity
    }
}
textures/castle_window/cwindow_m01
{
	{
		map textures/castle_window/cwindow_m01.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/tinfx.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.2 1.2  
		tcGen environment
	}
}

textures/wood/wood_c13
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_c13.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/terrain/dirt_m03_mung
{
  
    surfaceparm grasssteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/terrain/dirt_m03_mung.tga
        blendFunc GL_DST_COLOR GL_ZERO	
        rgbGen identity
    }
}

textures/props/gold_m01
{
	{
		map textures/props/gold_m01.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/chrome4.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 2 2 
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}

textures/wood/wood_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m01_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m01_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m04_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m04_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m05_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m05a_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05a_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m06
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m06a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m06a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m06b
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m06b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m06_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m06_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m07
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m07_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m07_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/wood/wood_m08
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/wood/wood_m08_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m08_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m09
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m09.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m09_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m09_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m10
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m10.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m11
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m11.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m12
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m12.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m12a
{
	qer_editorimage textures/wood/wood_m12.tga
	surfaceparm woodsteps

	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m12.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m12snow
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m12snow.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m12_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m12_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m12a_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m12a_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/wood/wood_m12s
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m12s.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m13
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m13.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m13_usat
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m13_usat.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/metal_m04dr2
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/metal_m04dr2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/tram_s5
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/tram_s5.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/tram_s3
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/tram_s3.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/tram_s3ns
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/tram_s3ns.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xgrid_c01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xgrid_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_c02dm
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c02dm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_c08
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_c08
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xtrim_c02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xtrim_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xtrim_c05
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xtrim_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/swf/xtrim_cm05
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/xtrim_cm05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xmetal_c03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xmetal_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xwall_c07
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xwall_c07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xmetal_c03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xmetal_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_diamond_c01a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_diamond_c01a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/props/flag_m02

{
	qer_editorimage textures/props/flag_m02.tga

	// qer_trans 0.50
	cull twosided
	{
		map textures/props/flag_m02.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flag_m03

{
	qer_editorimage textures/props/flag_m03.tga

	// qer_trans 0.50
	cull twosided
	{
		map textures/props/flag_m02.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}

textures/props/flag_m02b

{
	qer_editorimage textures/props/flag_m02b.tga

	// qer_trans 0.50
	cull twosided
	{
		map textures/props/flag_m02b.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen vertex
	}

}


textures/props/ember1

{


	// qer_trans 0.50
	cull twosided
	{
		map textures/props/ember1.tga
	//	tcMod stretch sin 1 0.02 0 .05
	//	blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		tcMod rotate 3
		rgbGen wave sin 1 1 .25 1.5

	}

}
textures/props/ember2
{
	qer_editorimage textures/props/ember2.tga
	{
		map textures/props/ember1a.tga
		rgbGen wave sin 1 0.5 0 0.5 
	}
	{
		map textures/props/ember2.tga
		blendfunc blend
		rgbGen lightingdiffuse
	}
}
textures/props/ember2a
{
	
	qer_editorimage textures/props/ember2.tga
	{
		map textures/props/ember1a.tga
	//	tcMod rotate 6
		tcmod stretch sin 1.2 .2 0 .5
 	        rgbGen wave sin 1 0.2 0.25 1.5
	//	tcGen environment
	//	tcMod rotate 3
	//	tcmod scale .5 .5
	}
	
	{
		map textures/props/ember2.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA	
		rgbGen identity
	}
	{
		map $lightmap
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}


textures/metal_misc/ametal_m03snow
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/ametal_m03snow.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/ametal_m03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/ametal_m03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/swf/ametal_m08
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/ametal_m08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/barrel_m01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/barrel_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/wood/wood_m05a_usata_dm
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05a_usata_dm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m02a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m02a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/miltary_wall/mroof_m01a
{
	surfaceparm roofsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/miltary_wall/mroof_m01a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m16
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m16.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/textures/wood/wood_m16dm
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m16dm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

wood/wood_m19a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m19a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m18
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m18.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/wood/wood_m16cm
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m16cm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/swood/wood_m05_usata_cm
{
	surfaceparm woodsteps
	surfaceparm clipmissile
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05_usata_cm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m05_usata
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05_usata.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_m05a_usat_snow
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05a_usat_snow.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_wood_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_wood_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_t_m04
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_t_m04a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m04a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_m04a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_m04a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/metal_m04dg2
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/metal_m04dg2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/miltary_door/mdoor_m01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/miltary_door/mdoor_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_castle_m03_step_2
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_castle_m03_step_2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_dirt_m03i_2
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_dirt_m03i_2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_grass_ml03b
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_grass_ml03b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_castle_m03_step
{
	surfaceparm snowsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_castle_m03_step.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_mo2s1
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_mo2s1.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}




textures/swf/door_m01aaaaswf
{
	nocompress
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/door_m01aaaaswf.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/swf/sdoor_m01aaaaswf
{
	nocompress
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/sdoor_m01aaaaswf.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/blimp/runway_m01_sm
{
	nocompress
	
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/blimp/runway_m01_sm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/stone/mxrock1aa
{
	surfaceparm grasssteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/stone/mxrock1aa.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}




//////////////////// marble test ///////////////////////////////////////////////////


textures/chateau/marble_c03
{
	{
		map textures/chateau/marble_c03.tga
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


textures/chateau/marblefloor_c01
{
	{
		map textures/chateau/marblefloor_c01.tga
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
textures/chateau/marble_c04
{
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
textures/chateau/marble_c07
{
	{
		map textures/chateau/marble_c07.tga
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
textures/chateau/marble_c10
{
	{
		map textures/chateau/marble_c10.tga
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
textures/chateau/marble_c11
{
	{
		map textures/chateau/marble_c11.tga
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
textures/chateau/marbletrim_c01
{
	{
		map textures/chateau/marbletrim_c01.tga
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
textures/chateau/marbletrim_c02
{
	{
		map textures/chateau/marbletrim_c02.tga
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

textures/chateau/marbletrim_c04
{
	{
		map textures/chateau/marbletrim_c04.tga
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


textures/chateau/marbletrim_c05
{
	{
		map textures/chateau/marbletrim_c05.tga
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
textures/chateau/marbletrim_c06
{	
	{
		map textures/chateau/marbletrim_c06.tga
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
textures/chateau/walltest_c07a_vertex
{
	qer_editorimage chateau/walltest_c07a.tga

	{
		map textures/chateau/walltest_c07a.tga
		tcMod Scale .25 .25
		rgbGen vertex
	}
}
textures/chateau/marblefloor_c04
{
	{
		map textures/chateau/marblefloor_c04.tga
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
textures/training/road_m03
{
	{
		map textures/training/road_m03.tga
		rgbGen vertex
	}
}

textures/castle_window/CASHUDDER_C01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_window/CASHUDDER_C01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_c15
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_c15.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/castle_wood/cwood_c18
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_wood/cwood_c18.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/ametal_m03dm
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/ametal_m03dm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/metal_misc/metal_m04dg
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/metal_m04dg.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/board_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/board_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/board_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/board_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/logend_m01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/logend_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/panel_d04
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/panel_d04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/panelside_d01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/panelside_d01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/panel_tram3
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/panel_tram3.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/props/lockers_c02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/lockers_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_cashudder_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_cashudder_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_cwood_mo5c
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_cwood_mo5c.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/snow/s_floor_c10_a2
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_floor_c10_a2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/wood/wood_c01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/town_window/shudder_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_window/shudder_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/wood/wood_m05a_usata
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/wood/wood_m05a_usata.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/snow/s_shudder_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/snow/s_shudder_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/town_wood/wood_c11
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wood/wood_c11.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_c05_light_half
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c05_light_half.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_c10_light
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c10_light.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_switch
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_switch.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/xmetal_m03l
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/xmetal_m03l.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/swf/metal_m03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/metal_m03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/metal_c06
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/metal_c06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/machine_c05b
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c05b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/assault/metal_c07a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/metal_c07a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/assault/trim_c01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/trim_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/assault/trim_c04
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/trim_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/awf_props/tool_m01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/awf_props/tool_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/awf_props/tool_m04
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/awf_props/tool_m04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/awf_props/tool_m06

{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/awf_props/tool_m06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/metal_misc/diamond_c_01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/metal_misc/diamond_c_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/mesure_c01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/mesure_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/assault/machine_c07
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c07.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/assault/machine_c04b
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c04b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/assault/machine_c03a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/atool_m02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/atool_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/kobra_03a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/kobra_03a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/kobra_02a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/kobra_02a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/kobra_01a
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/kobra_01a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/swf/metal_m02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/metal_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_wall/x_metalwall_m01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_wall/x_metalwall_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/xlab_props/xdrawers_c03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xdrawers_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/xlab_props/xpanel_c04dm
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c04dm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/xlab_props/xpanel_c03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/xpanel_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/train_m01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/train_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/train_m02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/train_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/train_m03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/train_m03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/train_m04
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/train_m04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/board_cl01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/board_cl01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/board_c03
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/board_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/miltary_wall/brick_l_01
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/miltary_wall/brick_l_01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/props/box_t_m02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/props/box_t_m02a
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/box_t_m02a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/props/sign_c05
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/sign_c05.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/machine_c06b
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c06b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/machine_c01b
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c01b.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/assault/machine_c03e
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c03e.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/assault/machine_cl01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_cl01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/assault/machine_c08
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/assault/machine_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/village/villwin_c15
{
	qer_editorimage textures/village/villwin_c15.tga
	surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c15.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villwin_c15.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village/villwin_c15.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}
textures/village/villwin_c16
{
	qer_editorimage textures/village/villwin_c16.tga
	surfaceparm nomarks
	q3map_lightimage textures/lightimage/villwin_c16.tga
	q3map_surfacelight 300
	light 1



	{
		map textures/village/vill2_win_m2.tga
		blendFunc GL_ONE GL_ZERO
		rgbGen identity
	}
	{
		map textures/effects/vilfx2.tga
		blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
		tcMod Scale 1.5 1.5  
		tcGen environment
	}
	{
		map $lightmap
		blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}
}



textures/village/villwin_c17
{
	qer_editorimage textures/village/villwin_c17.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c17.tga
	q3map_surfacelight 300
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villwin_c17.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village/villwin_c17.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/village/villwin_c18
{
	qer_editorimage textures/village/villwin_c18.tga
	surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c17.tga
	q3map_surfacelight 200
	light 1
	q3map_lightsubdivide 128

	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villwin_c18.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/village/villwin_c18.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/village/vilwin_frm1a
{
	qer_editorimage textures/village/vilwin_frm1a.tga
	// surfaceparm nomarks
	// q3map_lightimage textures/village/villwin_c12.tga
	q3map_surfacelight 300
	light 1

	{
		map textures/village/vilwin_frm1a.tga
//		blendFunc GL_DST_COLOR GL_ZERO
//		rgbGen wave sin .6 .2 0 .6
		rgbGen identity
	}
}

textures/terrain/grass_dm01
{
	surfaceparm grasssteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/terrain/grass_dm01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chat/carpet_c02
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c02.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/chateau/stair_c03
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chateau/stair_c03.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}


textures/chat/carpet_c03
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c03.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/chat/carpet_c08
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c08.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}



textures/chat/bedlinen_c04
{
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/bedlinen_c04.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}



textures/windows/window_c04
{
	qer_editorimage textures/windows/window_c04.tga
	q3map_lightimage textures/lightimage/window_c04.tga      // color for window
	q3map_surfacelight 300
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/windows/window_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/windows/window_c04.tga
		blendfunc GL_ONE GL_ONE
	}
}

textures/windows/window_c04_nolight
{
	qer_editorimage textures/windows/window_c04.tga
	// surfaceparm nomarks
	q3map_lightimage textures/lightimage/window_c04.tga      // color for window
//	q3map_surfacelight 300
	q3map_lightsubdivide 128
//	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/windows/window_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/windows/window_c04.tga
		blendfunc GL_ONE GL_ONE
	}
}














textures/chat/book_c02
{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat/book_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chat/book_c03

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat/book_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/chat/office_c03

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/chat/office_c03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/town_wall/store_c01

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wall/store_c01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_wall/store_c02

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wall/store_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_wall/store_c03_a

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wall/store_c03_a.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_window/shudder_c04

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_window/shudder_c04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_wood/wood_c02

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_wood/wood_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/village/villdoor_c06

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/village/villdoor_c06.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/swf/ametal_m01sm

{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/swf/ametal_m01sm.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/castle_door/door_m01

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/castle_door/door_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/town_props/number05_c02

{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/number05_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_props/number11_c02

{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/number11_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_props/number21_c02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/number21_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/town_props/number42_c02
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/number42_c02.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/town_props/streetname_C01
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/streetname_C01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/town_props/streetname_C03
{
	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/streetname_C03.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}

textures/town_props/store_c04_a2tga

{
	surfaceparm woodsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/town_props/store_c04_a2tga.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}



textures/props/wine_c08

{
	surfaceparm nomarks
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/props/wine_c08.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/blimp/a_block

{
	surfaceparm nomarks

	{
		map textures/blimp/a_block.tga
		rgbGen identity
	}
}

textures/windows/dam_window1
{
	qer_editorimage textures/windows/dam_window1.tga
	// surfaceparm nomarks
//	q3map_lightimage textures/chateau/soft_blue.tga       // color for window
	q3map_surfacelight 300
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/windows/dam_window1.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/windows/dam_window1.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}


textures/windows/dam_window1_nolight
{
	qer_editorimage textures/windows/dam_window1.tga
	// surfaceparm nomarks
//	q3map_lightimage textures/chateau/soft_blue.tga       // color for window
//	q3map_surfacelight 300
//	q3map_lightsubdivide 128
//	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/windows/dam_window1.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity

	}


}


textures/miltary_door/mdoor_m06a
{
	surfaceparm metalsteps
	{
		map textures/miltary_door/mdoor_m06a.tga
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

textures/xlab_props/panel_m01_light
{
	qer_editorimage textures/xlab_props/panel_m01.tga
	surfaceparm nomarks
	q3map_lightimage textures/xlab_props/softblue.tga       // color for window
	q3map_surfacelight 1000
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	//	rgbGen wave sin .6 .2 0 .6
	}
	{
		map textures/xlab_props/panel_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen wave sin 1 .1 0 7
	//	rgbGen identity

	}


}

textures/xlab_props/panel_m01
{

	surfaceparm metalsteps
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/xlab_props/panel_m01.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}


}


textures/assault/radar_01a
{      
	qer_editorimage textures/assault/radar_01
        
	{
		map textures/assault/radarsweep.tga
		rgbGen identity
		tcMod rotate 130
	//	rgbgen wave triangle 0 1 0 7
	//	tcMod scroll 1 0
	}


	{
		map textures/assault/radarbeeps.tga
		blendfunc blend
		tcMod scroll .01 .001
		rgbGen wave sin 1 .5 0 .25
	}
	{
		map textures/assault/radar_01.tga
		blendfunc blend
		rgbGen vertex
	}
}

textures/assault/radar_01b
{      

	qer_editorimage textures/assault/radar_01        
	{
		map textures/assault/radarsweep.tga
		rgbGen identity
		tcMod rotate -110
	//	rgbgen wave triangle 0 1 0 7
	//	tcMod scroll 1 0
	}


	{
		map textures/assault/radarbeeps.tga
		blendfunc blend
		tcMod scroll .01 .001
		rgbGen wave sin 1 .5 0 .25
	}
	{
		map textures/assault/radar_01.tga
		blendfunc blend
		rgbGen vertex
	}
}

textures/training/window_m04
{
	qer_editorimage textures/training/window_m04.tga
	// surfaceparm nomarks
	q3map_lightimage textures/chateau/soft_blue.tga       // color for window
	q3map_surfacelight 300
	q3map_lightsubdivide 128
	light 1


	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/training/window_m04.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
	{
		map textures/chateau/window_m01.blend.tga
		blendfunc GL_ONE GL_ONE
	}
}




textures/chat/carpet_c10
{
//   q3map_lightmapsamplesize 1
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c10.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}


textures/chat/carpet_c10trim
{
//    q3map_lightmapsamplesize 1
    surfaceparm carpetsteps
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chat/carpet_c10trim.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/chateau/floor_c05
{
//   q3map_lightmapsamplesize 1
    {
        map $lightmap
        rgbGen identity
    }
    {
        map textures/chateau/floor_c05.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
    }
}

textures/stone/riverrock_m01
{

	surfaceparm gravelsteps

	{
		map textures/stone/riverrock_m01.tga
		rgbGen identity
	}

}



