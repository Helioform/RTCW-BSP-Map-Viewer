models/players/infantry/legs_heat
{
	deformVertexes wave 100 sin .2 0 0 0
	{
		map models/players/infantry/legs_heat.tga
//		blendfunc GL_ONE_MINUS_SRC_ALPHA gl_src_alpha
		blendfunc GL_ONE GL_ONE_MINUS_SRC_COLOR
//		blendfunc GL_ONE GL_ONE
		rgbGen lightingdiffuse
	}
	
	
}

models/players/infantry/torso_heat
{
	deformVertexes wave 100 sin .2 0 0 0
	{
		map models/players/infantry/body_heat.tga
//		blendfunc GL_ONE_MINUS_SRC_ALPHA gl_src_alpha
		blendfunc GL_ONE GL_SRC_COLOR
//		blendfunc GL_ONE GL_ONE
		rgbGen lightingdiffuse
	}
	
	
}

models/players/infantry/head_heat
{
	deformVertexes wave 100 sin .2 0 0 0
	{
		map models/players/infantry/head_heat.tga
//		blendfunc GL_ONE_MINUS_SRC_ALPHA gl_src_alpha
		blendfunc GL_ONE GL_SRC_COLOR
//		blendfunc GL_ONE GL_ONE
		rgbGen lightingdiffuse
	}
	
	
}
