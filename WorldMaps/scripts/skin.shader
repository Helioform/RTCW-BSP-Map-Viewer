textures/organics/dirt_trans
{
	qer_editorimage textures/organics/dirt.tga
	surfaceparm nonsolid
	{
		map $lightmap
		rgbGen identity
	
	}
	{
		map textures/organics/dirt.tga
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO

	
	}
}


textures/skin/skin6_trans
{
	qer_editorimage textures/skin/skin6.tga
	surfaceparm nonsolid
	{
		map $lightmap
		rgbGen identity
	
	}
	{
		map textures/skin/skin6.tga
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO

	
	}
}
textures/skin/skin6_trans_decal
{
	polygonOffset
	qer_editorimage textures/skin/skin6.tga
	surfaceparm nonsolid
	{
		map $lightmap
		rgbGen identity
	
	}
	{
		map textures/skin/skin6.tga
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO

	
	}
}

textures/skin/nibbles
{
	// tessSize 64
	deformVertexes wave 10 sin 4 3 0 0.3
	{
		rgbGen identity
		map $lightmap
	}
	{
		map textures/skin/nibbles.tga
		blendFunc GL_DST_COLOR GL_SRC_ALPHA
		rgbGen identity
		alphaGen lightingSpecular
	}
}
textures/skin/soylent
{
	tessSize 64
	deformVertexes wave 100 sin 4 3 0 0.3
	{
		rgbGen identity
		map $lightmap
	}
        {
		map textures/skin/soylent.tga
		blendFunc GL_DST_COLOR GL_SRC_ALPHA
		rgbGen identity
		alphaGen lightingSpecular
	}

}
textures/skin/snake
{
	tessSize 128
	deformVertexes wave 100 sin 0 2 0 .3
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/snake.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/skin/proto_skin2
{
	tessSize 128
	deformVertexes wave 100 sin 4 3 0 0.3
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/proto_skin2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/skin/skin6move
{
	tessSize 128
	deformVertexes wave 100 sin 4 3 0 0.3
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/skin6move.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}


textures/skin/proto_skin
{
	tessSize 256
	deformVertexes wave 100 sin 2 2 0 0.3
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/proto_skin.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/skin/skin1move
{
	tessSize 128
	deformVertexes wave 100 sin 3 2 0 0.3
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/skin1move.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/skin/spikemove
{
	tessSize 128
	deformVertexes wave 100 sin 0 .5 0 0.1
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/spikemove.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
textures/skin/pjwal2f
{
	tessSize 128
	deformVertexes wave 100 sin 0 2 0 .3
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/skin/pjwal2f.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}
}
