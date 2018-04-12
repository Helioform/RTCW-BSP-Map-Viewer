textures/liquids/water_ripple1

//	*********************************************************
//	*      Large clear ripple water. Created September 9	  *
//	*      		Comment all changes                   *
//	*********************************************************
	
	{
		qer_editorimage textures/liquids/pool3d_3.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water

		cull disable
		deformVertexes wave 64 sin .5 .5 0 .5	
	
		
		{ 
			map textures/liquids/pool3d_5.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 1.5 0 1.5 1 1 2
			tcmod scroll -.05 .001
		}
	
		{ 
			map textures/liquids/pool3d_6.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 0 1.5 1 1.5 2 1
			tcmod scroll .025 -.001
		}

		{ 
			map textures/liquids/pool3d_3.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .25 .5
			tcmod scroll .001 .025
		}	

		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
//	END
	}
///// maxx water /////

textures/liquids/water_m1

//	*********************************************************
//	*      Large clear ripple water. Created September 9	  *
//	*      		Comment all changes                   *
//	*********************************************************
	
	{
		qer_editorimage textures/liquids/water_m1.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water

		cull disable
		deformVertexes wave 32 sin 1 .4 0 .5	
	
		
		{ 
			map textures/liquids/water_m1.tga
		//	blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale 1 1
			tcmod stretch scale 2 .2 0 .1
		//	tcmod rotate 3
		//	tcmod stretch scroll 2 .2 0 .1
		//	tcmod transform 1.5 0 1.5 1 1 2
		//	tcmod scroll -.05 .001
		
		}

		{
			map textures/effects/wdfx2.tga
			blendFunc GL_ONE_MINUS_DST_ALPHA GL_ONE
			tcGen environment
			tcmod scale 1 1
			rgbGen vertex
		}




	
	//	{ 
	//		map textures/liquids/pool3d_6.tga
	//		blendFunc GL_dst_color GL_one
	//		rgbgen identity
	//		tcmod scale .5 .5
	//		tcmod transform 0 1.5 1 1.5 2 1
	//		tcmod scroll .025 -.001
	//	}

	//	{ 
	//		map textures/liquids/pool3d_3.tga
	//		blendFunc GL_dst_color GL_one
	//		rgbgen identity
	//		tcmod scale .25 .5
	//		tcmod scroll .001 .025
	//	}	

		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
//	END
	}

textures/liquids/water_ripple3_10

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/water_m1.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
	//	deformVertexes wave 64 sin 3 .7 .8 .25
		deformVertexes wave 64 sin 0 1 .75 .2
		deformVertexes wave 64 sin 0 1 .25 .15	
		{ 
			map textures/liquids/water_m5.tga
		//	blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .85 .45
		//	tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll .005 -.005
		}	

	
		{ 
		//	map textures/liquids/water_m1.tga
			map textures/liquids/water_m4.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity		
			tcmod scale -.85 .45
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod rotate 5 
			tcmod scroll -.01 .0051
		}

		{ 
		//	map textures/liquids/water_m1.tga
		//	map textures/liquids/water_m4.tga
		//	blendFunc GL_dst_color GL_one
		//	rgbgen identity
		//	tcmod scale .4 .5
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod scroll -.005 -.0055
		}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}

textures/liquids/water_ripple3_10

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/water_m1.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
	//	deformVertexes wave 64 sin 3 .7 .8 .25
		deformVertexes wave 64 sin 0 1 .75 .2
		deformVertexes wave 64 sin 0 1 .25 .15	
		{ 
			map textures/liquids/water_m5.tga
		//	blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .85 .45
		//	tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll .005 -.005
		}	

	
		{ 
		//	map textures/liquids/water_m1.tga
			map textures/liquids/water_m4.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity		
			tcmod scale -.85 .45
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod rotate 5 
			tcmod scroll -.01 .0051
		}

		//{ 
		//	map textures/liquids/water_m1.tga
		//	map textures/liquids/water_m4.tga
		//	blendFunc GL_dst_color GL_one
		//	rgbgen identity
		//	tcmod scale .4 .5
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod scroll -.005 -.0055
		//}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}

textures/liquids/water_beach3


//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
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



textures/liquids/water_beach2a
{


	qer_editorimage textures/liquids/ocean01.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water

	deformVertexes wave 32 sin 0 10 .75 .1


	{
		animMap 8 textures/liquids/ocean01.tga textures/liquids/ocean02.tga textures/liquids/ocean03.tga textures/liquids/ocean04.tga textures/liquids/ocean05.tga textures/liquids/ocean06.tga textures/liquids/ocean07.tga textures/liquids/ocean08.tga textures/liquids/ocean09.tga textures/liquids/ocean10.tga textures/liquids/ocean11.tga textures/liquids/ocean12.tga textures/liquids/ocean13.tga

	//	blendfunc gl_one gl_one
	//	blendFunc GL_SRC_ALPHA GL_ONE
		rgbGen identity
		tcmod scroll .00 -.01
	}	
	{
		animMap 8 textures/liquids/ocean13.tga textures/liquids/ocean01.tga textures/liquids/ocean02.tga textures/liquids/ocean03.tga textures/liquids/ocean04.tga textures/liquids/ocean05.tga textures/liquids/ocean06.tga textures/liquids/ocean07.tga textures/liquids/ocean08.tga textures/liquids/ocean09.tga textures/liquids/ocean10.tga textures/liquids/ocean11.tga textures/liquids/ocean12.tga

		blendFunc GL_dst_color GL_one
		rgbGen identity
		tcmod scroll .01 .01
	}
	{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity
		
	}

	

}
textures/liquids/water_beach_old


//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/ocean_m1.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
	//	deformVertexes wave 64 sin 3 .7 .8 .25
		deformVertexes wave 32 sin 0 5 .75 .2
	//	deformVertexes wave 32 sin 0 20 .25 .1	
		{ 
			map textures/liquids/ocean_m1.tga
		//	blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .4 .2
		//	tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll .00 .01
		}	

	
		{ 
		//	map textures/liquids/water_m1.tga
			map textures/liquids/ocean_m2.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity		
			tcmod scale -.6 .5
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod rotate 5 
			tcmod scroll .01 .01
		}

	
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}

textures/liquids/ocean_m3


//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/ocean_m3.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
	//	deformVertexes wave 64 sin 3 .7 .8 .25
		deformVertexes wave 32 sin 0 5 .75 .2
	//	deformVertexes wave 32 sin 0 3 .25 .1	
		

	
		{ 
		//	map textures/liquids/water_m1.tga
			map textures/liquids/ocean_m3.tga
		//	blendFunc GL_dst_color GL_one
			blendFunc GL_ONE GL_ONE
		//	alphaFunc GE128
			rgbgen identity		
			tcmod scale -.6 .5
			tcmod stretch 0 1 .01 0 .25 1
		//	tcmod rotate 5 
		//	tcmod scroll .01 .01
		}
	//	{
		//	map $lightmap
		//	blendFunc GL_dst_color GL_zero
		//	rgbgen identity		
	//	}



//	END
	}

textures/liquids/xwater_waste

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/water_m7.tga
		qer_trans .5
		q3map_globaltexture
	//	surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
		surfaceparm lava
	
		cull disable
		deformVertexes wave 64 sin .5 .2 0 .5	
		{ 
			map textures/liquids/water_m7.tga
			blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		//	blendFunc GL_dst_color GL_one
			rgbgen vertex
			tcmod scale .3 .5
			tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll .005 .005
		}	

	
		{ 
		//	map textures/liquids/water_m1.tga
		//	map textures/liquids/water_m4.tga
		//	blendFunc GL_dst_color GL_one
		//	rgbgen identity		
		//	tcmod scale -.4 .3
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod rotate 5 
	///		tcmod scroll -.005 .0051
		}

		{ 
		//	map textures/liquids/water_m1.tga
	//		map textures/liquids/water_m4.tga
	//		blendFunc GL_dst_color GL_one
	//		rgbgen identity
			tcmod scale .4 .5
		//	tcmod stretch 0 1 .01 0 .25 1
	//		tcmod scroll -.005 -.0055
		}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}

textures/liquids/xwater_waste2

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************

//	q3map_globaltexture
//	surfaceparm trans
//	//surfaceparm nonsolid
//	surfaceparm noimpact
//	surfaceparm lava
//	surfaceparm nolightmap
//	q3map_surfacelight 600
//	cull disable
	
//	tesssize 128

		
{

		surfaceparm trans
		qer_editorimage textures/liquids/water_m5.tga
	//	qer_trans .5
		q3map_globaltexture
	//	surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable

	
	tesssize 128
	deformVertexes wave 20 sin 3 2 .1 0.1
	
        {
		map textures/liquids/water_m7.tga
                tcmod scale .2 .2
                tcmod scroll .0004 .0003
                tcMod turb 0 .1 0 .01
                blendFunc GL_ONE GL_ZERO
                rgbGen identity
	}
	{
		map textures/liquids/water_m6.tga
	        tcmod scale .5 .5
                blendfunc blend
		tcMod turb 0 .02 0 .01
	}

}

textures/liquids/xwater_waste3


//	*********************************************************
//	*      Large clear ripple water. Created September 9	  *
//	*      		Comment all changes                   *
//	*********************************************************
	
	{
		qer_editorimage textures/liquids/pool3d_3.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water

		cull disable
		deformVertexes wave 64 sin .5 .5 0 .2	
	
		
		{ 
			map textures/liquids/pool3d_5m.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale 1 1
			tcmod transform 1.5 0 1.5 1 1 2
			tcmod scroll -.01 .0005
		}
	
		{ 
			map textures/liquids/pool3d_6m.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale 1 1
			tcmod transform 0 1.5 1 1.5 2 1
			tcmod scroll .005 -.001
		}

		{ 
			map textures/liquids/pool3d_3m.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod scroll .0005 .005
		}	

		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
//	END
	}


textures/liquids/water_shore

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************		
{

		surfaceparm trans
		qer_editorimage textures/assault_rock/ground_m07wet.tga
	//	qer_trans .5
	//	q3map_globaltexture
	//	surfaceparm trans
	//	surfaceparm nonsolid
	//	surfaceparm water
	
		cull disable

	//	{ 
		//	map textures/liquids/water_m1.tga
		//	map textures/liquids/ocean_m3.tga
		//	blendFunc GL_dst_color GL_one
	//		blendFunc GL_ONE GL_ZERO
		//	alphaFunc GE128
	//		rgbgen identity		
	//		tcmod scale -.6 .5
	//		tcmod stretch 0 -1 .01 0 .25 1
		//	tcmod rotate 5 
		//	tcmod scroll .01 .01
	//	}
	{
		map textures/liquids/ocean_m1b.tga
	//        tcmod scale 1 1
		blendFunc GL_ONE GL_ZERO
        //	blendfunc blend
	//	tcMod turb 0 .02 0 .01
		tcmod scale .4 .2
		tcmod scroll .00 .01
	 	rgbGen identity
	}
	{ 
//		map textures/liquids/water_m1.tga
		map textures/liquids/ocean_m1b.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale -.6 .5
//		tcmod stretch 0 1 .01 0 .25 1
//		tcmod rotate 5 
		tcmod scroll .01 .01
	}

        {
		map textures/assault_rock/ground_m07wet.tga
                blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen identity
	}
        {
		map $lightmap
                blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}



}

textures/assault_rock/ground_m07wet

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************		
{

		surfaceparm trans
		qer_editorimage textures/assault_rock/ground_m07wet.tga
	//	qer_trans .5
	//	q3map_globaltexture
	//	surfaceparm trans
	//	surfaceparm nonsolid
	//	surfaceparm water
	
		cull disable


	{
		map textures/liquids/ocean_m1aa.tga
	//        tcmod scale 1 1
		blendFunc GL_ONE GL_ZERO
        //	blendfunc blend
	//	tcMod turb 0 .02 0 .01
		tcmod scale 1 1
		tcmod scroll .00 .0051
	//	tcmod stretch 0 1 .01 0 .25 1
	 	rgbGen identity
	}
//	{ 
//		map textures/liquids/water_m1.tga
//		map textures/liquids/ocean_m1b.tga
//		blendFunc GL_dst_color GL_one
//		rgbgen identity		
//		tcmod scale -.6 .5
//		tcmod stretch 0 1 1 0 .1 1
//		tcmod rotate 5 
//		tcmod scroll .01 .01
//	}

        {
		map textures/assault_rock/ground_m07wet.tga
                blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen identity
	}
        {
		map $lightmap
                blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}



}

textures/assault_rock/ground_m08wet

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************		
{

		surfaceparm trans
		qer_editorimage textures/assault_rock/ground_m08wet.tga
	//	qer_trans .5
	//	q3map_globaltexture
	//	surfaceparm trans
	//	surfaceparm nonsolid
	//	surfaceparm water
	
		cull disable


	{
		map textures/liquids/ocean_m1aa.tga
	//        tcmod scale 1 1
		blendFunc GL_ONE GL_ZERO
        //	blendfunc blend
	//	tcMod turb 0 .02 0 .01
		tcmod scale 1 1
	//	tcmod stretch 0 1 .01 0 .25 1
	//	tcmod turb 0 1 .01 0 .25 1
		tcmod scroll .00 .0051
	 	rgbGen identity
	}
//	{ 
//		map textures/liquids/water_m1.tga
///		map textures/liquids/ocean_m1b.tga
//		blendFunc GL_dst_color GL_one
//		rgbgen identity		
//		tcmod scale -.6 .5
//		tcmod stretch 0 1 .01 0 .25 1
//		tcmod rotate 5 
//		tcmod scroll .01 .01
//	}

        {
		map textures/assault_rock/ground_m08wet.tga
                blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbGen identity
	}
        {
		map $lightmap
                blendFunc GL_DST_COLOR GL_ONE_MINUS_DST_ALPHA
		rgbGen identity
	}



}

textures/liquids/water_shore2
{

	qer_editorimage textures/assault_rock/ground_m07.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	qer_nocarve
	tesssize 128
	
	cull disable
///	deformVertexes wave 64 sin 3 .7 .8 .25
//	deformVertexes wave 32 sin 0 5 .75 .2
///	deformVertexes wave 32 sin 0 20 .25 .1	

	nofog
//	deformVertexes wave 135 sin 0 10 0 .07	// the swell
///	deformVertexes wave 383 sin 0 15 0 .1	// the chop
	deformVertexes wave 160 sin 0 10 0 .3	// the chop
	
	{
		
		map textures/liquids/ocean_m1c.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		tcmod scale .4 .2
		tcmod scroll .00 .01
	 	rgbGen identity
	}

}

textures/liquids/water_ripple3


//	*********************************************************
//	*      Medium clear ripple water. Created September 9	  *
//	*      		Comment all changes                   *
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/pool3d_3c.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .5 .5 0 .5	
		
		{ 
			map textures/liquids/pool3d_5c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 1.5 0 1.5 1 1 2
			tcmod scroll -.05 .001
		}
	
		{ 
			map textures/liquids/pool3d_6c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 0 1.5 1 1.5 2 1
			tcmod scroll .025 -.001
		}

		{ 
			map textures/liquids/pool3d_3c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .25 .5
			tcmod scroll .001 .025
		}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}

textures/liquids/water_calm1

//	*********************************************************
//	*      Medium clear calm water. Created September 9	  *
//	*      		Comment all changes                   *
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/pool3d_3e.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .25 .25 0 .5	
		{ 
			map textures/liquids/pool3d_5e.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod scroll .025 .01
		}
	
		{ 
			map textures/liquids/pool3d_3e.tga
			blendFunc GL_dst_color GL_one
			tcmod scale -.5 -.5
			tcmod scroll .025 .025
		}

	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	
	

//	END
	}

textures/liquids/water_calm2

//	*********************************************************
//	*      Medium clear ripple water. Created September 9	  *
//	*      		Comment all changes                   *
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/pool3d_3c.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
	nofog
		cull disable
		
		{ 
		fog on
			map textures/liquids/pool3d_5c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 1.5 0 1.5 1 1 2
			tcmod scroll -.05 .001
		}
	
		{ 
		fog on
			map textures/liquids/pool3d_6c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 0 1.5 1 1.5 2 1
			tcmod scroll .025 -.001
		}

		{ 
			map textures/liquids/pool3d_3c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .25 .5
			tcmod scroll .001 .025
		}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}
	
	

textures/liquids/water_xlab1

//Sippy's Test Water
		
	{
		qer_editorimage textures/liquids/pool3d_3f.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .25 .25 0 .5	
		{ 
			map textures/liquids/pool3d_5e.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod scroll .025 .01
		}
	
		{ 
			map textures/liquids/pool3d_3f.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale -1 -1
			tcmod scroll .025 .025
		}

	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	
	
	}

textures/liquids/water_xlab2

		
	{
		qer_editorimage textures/liquids/water_m6.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .25 .25 0 .5	
		{ 
			map textures/liquids/water_m6.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod scroll .025 .01
		}
	
		{ 
			map textures/liquids/water_m7.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale -1 -1
			tcmod scroll .025 .025
		}

	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	
	
	}

textures/liquids/water_mxwld

		
	{
		qer_editorimage textures/liquids/water_m6.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .25 .25 0 .5	
		{ 
			map textures/liquids/water_m6.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod scroll .025 .01
		}
	
	//	{ 
	//		map textures/liquids/water_m7.tga
	//		blendFunc GL_dst_color GL_one
	//		rgbgen identity
	//		tcmod scale -1 -1
	//		tcmod scroll .025 .025
	//	}

	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	
	
	}



//// maxx trans water

textures/liquids/water_ripple3_rc

//	*********************************************************
//	*     			 Maxx				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/water_m1.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .5 .2 0 .5	
		{ 
			map textures/liquids/water_m5.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .3 .5
			tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll .015 .005
		}	

	
		{ 
		//	map textures/liquids/water_m1.tga
			map textures/liquids/water_m4.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity		
			tcmod scale -.4 .3
		//	tcmod stretch 0 1 .01 0 .25 1
		//	tcmod rotate 5 
			tcmod scroll -.015 .0051
		}

		{ 
		//	map textures/liquids/water_m1.tga
			map textures/liquids/water_m4.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .4 .5
		//	tcmod stretch 0 1 .01 0 .25 1
			tcmod scroll -.005 -.0155
		}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}

textures/liquids/water_xlab_op

//Sippy test water, part 2
		
	{
		qer_editorimage textures/liquids/pool3d_3c.tga
		qer_trans .5
		q3map_globaltexture
		//surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		
		{ 
			map textures/liquids/pool3d_5c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 1.5 0 1.5 1 1 2
			tcmod scroll -.05 .001
		}
	
		{ 
			map textures/liquids/pool3d_6c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 0 1.5 1 1.5 2 1
			tcmod scroll .025 -.001
		}

		{ 
			map textures/liquids/pool3d_3c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .25 .5
			tcmod scroll .001 .025
		}
	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

//	END
	}


textures/liquids/lake_m01
{
	nocompress
	qer_editorimage textures/liquids/lake_m1.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	surfaceparm nomarks	// don't play ripple effects when shooting into water
//	tesssize 128
	cull disable
	nofog
//	deformVertexes wave 1024 sin 0 5 0 .3	// the chop

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
		tcmod scale .4 .3
	//	tcmod scroll .0075 -.0025
		tcmod scroll .0035 -.0012
	//	tcmod turd 10 1 0 5
	//	tcmod stretch sin 1 .005 0 .06
		tcmod stretch sin 1 .005 0 .03
	}
	
	{ 
		map textures/liquids/lake_m1.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale .4 .3
		tcmod scroll -.00075 .00025
	//	tcmod stretch sin 1 .005 0 .02
		tcmod transform 1.5 0 1.5 1 1 2
	}

	
	{ 
		map textures/liquids/lake_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale .18 .28
	//	tcmod scroll .001 .001
	}
}




textures/liquids/river_m01
{
	nocompress
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

//	{ 
//		fog on
//		map textures/liquids/lake_m1.tga
//		rgbgen identity
//		tcmod scale .2 .4
//		tcmod scroll .005 .005
//	}	
//

//   water effect used ///  
	{ 
		fog on
		map textures/liquids/lake_m1.tga
		rgbgen identity
		tcmod scale .4 .3
		tcmod scroll .0075 -.0025
	//	tcmod turd 10 1 0 5
		tcmod stretch sin 1 .005 0 .06
	}
	
	{ 
		map textures/liquids/river_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
		tcmod scale -.12 .2
	//	tcmod scroll .005 .005
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
	tesssize 256
	
	cull disable
	nofog
	deformVertexes wave 160 sin 0 10 0 .3	// the chop

	waterfogvars ( 0.1 0.1 0.1 ) 512
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

textures/liquids/water_dam		
{
	qer_editorimage textures/liquids/ocean_m1b.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	cull disable
     waterfogvars ( 0.1 0.115 0.1 ) 512

	{ 
		map textures/liquids/ocean_m1b.tga
		rgbgen identity
		tcmod scale .8 .7
		tcmod scroll .00 -.03
	}
	
	{
	   	map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}
	
}
textures/liquids/water_dam01.tga		
{
	qer_editorimage textures/liquids/water_dam01.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	cull disable
     waterfogvars ( 0.1 0.115 0.1 ) 512

	{ 
		map textures/liquids/water_dam01.tga
		rgbgen identity
		tcmod scale .8 .7
		tcmod scroll .00 -.03
	}
	
	{
	   	map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}
	
}
textures/liquids/water_dam02.tga		
{
	qer_editorimage textures/liquids/water_dam02.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	cull disable
     waterfogvars ( 0.1 0.115 0.1 ) 512

	{ 
		map textures/liquids/water_dam02.tga
		rgbgen identity
		tcmod scale .8 .7
		tcmod scroll .00 -.03
	}
	
	{
	   	map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}
	
}
textures/liquids/water_dam03.tga		
{
	qer_editorimage textures/liquids/water_dam03.tga
	qer_trans .5
	q3map_globaltexture
	surfaceparm trans
	surfaceparm nonsolid
	surfaceparm water
	cull disable
     waterfogvars ( 0.1 0.115 0.1 ) 512

	{ 
		map textures/liquids/water_dam03.tga
		rgbgen identity
		tcmod scale .8 .7
		tcmod scroll .00 -.03
	}
	
	{
	   	map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}
	
}



textures/liquids/pond_m2
{
	nocompress
	qer_editorimage textures/liquids/pond_m2.tga
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

	waterfogvars ( 0.25 0.15 0.1 ) 1024

	{
		fog on
		map $lightmap
		blendFunc GL_dst_color GL_zero
		rgbgen identity		
	}



//   water effect used ///  
	{ 
		fog on
		map textures/liquids/pond_m1.tga
		rgbgen identity
		tcmod scale 1 .5
		tcmod scroll .00075 -.00025
	//	tcmod turd 0 1 0 1
		tcmod stretch sin .5 .005 0 .015
	}
	
	{ 
		map textures/liquids/pond_m2.tga
		blendFunc GL_dst_color GL_one
		rgbgen identity		
	//	tcmod scale -.12 .2

	}
}

textures/liquids/water_endcastle

//Sippy's Test Water #2
		
	{
		qer_editorimage textures/liquids/pool3d_3f.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
	
		cull disable
		deformVertexes wave 64 sin .25 .25 0 .5	

	waterfogvars ( 0.25 0.15 0.1 ) 1024

		{ 
			map textures/liquids/pool3d_5e.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod scroll .025 .01
		}
	
		{ 
			map textures/liquids/pool3d_3f.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale -1 -1
			tcmod scroll .025 .025
		}

	
		{
			map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	
	
	}

textures/liquids/water_norway


//	*********************************************************
//	*     			Rich				*
//	*      		Comment all changes                   	*
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/ocean_m1b.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
		cull disable
		deformVertexes wave 32 sin 0 10 .75 .1
		waterfogvars ( 0.1 0.13 0.1 ) 600
		tesssize 512		
	
		{ 
			map textures/liquids/ocean_m1b.tga
			rgbgen identity
			tcmod scale .8 .7
			tcmod scroll .00 -.01
		}
	

		{
	   		map $lightmap
			blendFunc GL_dst_color GL_zero
			rgbgen identity		
		}
	

	}

textures/liquids/dig_water1

//	*********************************************************
//	*      digger water for the sipinator			  *
//	*      		Comment all changes                   *
//	*********************************************************
		
	{
		qer_editorimage textures/liquids/pool3d_3c.tga
		qer_trans .5
		q3map_globaltexture
		surfaceparm trans
		surfaceparm nonsolid
		surfaceparm water
		q3map_lightimage textures/liquids/bluewater.tga
		q3map_surfacelight 100
 	      light 1
		nofog
		cull disable
		
		{ 
		fog on
			map textures/liquids/pool3d_5c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 1.5 0 1.5 1 1 2
			tcmod scroll -.05 .001
		}
	
		{ 
		fog on
			map textures/liquids/pool3d_6c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .5 .5
			tcmod transform 0 1.5 1 1.5 2 1
			tcmod scroll .025 -.001
		}

		{ 
			map textures/liquids/pool3d_3c.tga
			blendFunc GL_dst_color GL_one
			rgbgen identity
			tcmod scale .25 .5
			tcmod scroll .001 .025
		}
	
	//	{
	//		map $lightmap
	//		blendFunc GL_dst_color GL_zero
	//		rgbgen identity		
	//	}
	

//	END
	}




