q3view_terrain
{
//	cull front
	{
//		map textures/terrain/mountain_m03a.tga
//		map textures/terrain/rock_c05.tga
///		map textures/terrain/rock_c02.tga
//		map textures/terrain/rock_c04.tga
//		map textures/q3view/hf_s1.tga
		map textures/q3view/hf_s3_tex.tga
		blendFunc GL_ONE GL_ZERO
	}
}

q3view_ground
{
	{
		map $checkimage
//		blendfunc GL_ONE GL_ZERO
	}
}


q3view_markShadow
{
	polygonOffset
	{
		map gfx/damage/shadow.tga
		blendFunc GL_ZERO GL_ONE_MINUS_SRC_COLOR
		rgbGen exactVertex
	}	
}


q3view_chars
{
	nopicmip
	nomipmaps
	{
		map gfx/2d/bigchars.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbgen vertex
	}
}

q3view_pointer
{
	nopicmip
	nomipmaps
	{
		map menu/art/3_cursor2.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbgen vertex
	}
}

q3view_hudHighlight
{
	nomipmaps
	{
		map textures/q3view/hud_window.tga
		blendFunc blend
	}
}

q3view_hudHotspot
{
	nomipmaps
	{
		map textures/q3view/hud_but_plain.tga
		blendFunc blend
	}
}

q3view_silhouette
{
	nomipmaps
//	{
//		map textures/q3view/hud_bgright.tga
//		blendFunc blend
//	}
	{
//		map textures/q3view/silhouette3.tga
		map textures/q3view/silhouette4.tga
//		blendfunc GL_ZERO GL_SRC_COLOR
		blendfunc blend
	}
}


// button font is
// Bookman Old Style
// 48
// Bold
// Antialiased
//
// and webdings
// 64

//////////// buttons
////////

q3view_but_flip
{
	nomipmaps
	{
		map textures/q3view/hud_but_flip.tga
		blendFunc blend
	}
}


q3view_but_tick
{
	nomipmaps
	{
		map textures/q3view/hud_but_tick.tga
		blendFunc blend
	}
}
q3view_but_norms
{
	nomipmaps
	{
		map textures/q3view/hud_but_norms.tga
		blendFunc blend
	}
}
q3view_but_fnorms
{
	nomipmaps
	{
		map textures/q3view/hud_but_fnorms.tga
		blendFunc blend
	}
}
q3view_but_bbox
{
	nomipmaps
	{
		map textures/q3view/hud_but_bbox.tga
		blendFunc blend
	}
}
q3view_but_q3bbox
{
	nomipmaps
	{
		map textures/q3view/hud_but_q3bbox.tga
		blendFunc blend
	}
}
q3view_but_tags
{
	nomipmaps
	{
		map textures/q3view/hud_but_tags.tga
		blendFunc blend
	}
}
q3view_but_antialias
{
	nomipmaps
	{
		map textures/q3view/hud_but_antialias.tga
		blendFunc blend
	}
}
q3view_but_origin
{
	nomipmaps
	{
		map textures/q3view/hud_but_origin.tga
		blendFunc blend
	}
}

q3view_but_mousemode
{
	nomipmaps
	{
		map textures/q3view/hud_but_mousemode.tga
		blendFunc blend
	}
}
q3view_but_interpolate
{
	nomipmaps
	{
		map textures/q3view/hud_but_interpolate.tga
		blendFunc blend
	}
}
q3view_but_animate
{
	nomipmaps
	{
		map textures/q3view/hud_but_animate.tga
		blendFunc blend
	}
}

q3view_but_tex
{
	nomipmaps
	{
		map textures/q3view/hud_but_tex.tga
		blendFunc blend
	}
}
q3view_but_wire
{
	nomipmaps
	{
		map textures/q3view/hud_but_wire.tga
		blendFunc blend
	}
}
q3view_but_facet
{
	nomipmaps
	{
		map textures/q3view/hud_but_facet.tga
		blendFunc blend
	}
}
q3view_but_smooth
{
	nomipmaps
	{
		map textures/q3view/hud_but_smooth.tga
		blendFunc blend
	}
}





q3view_but_editmode
{
	nomipmaps
	{
		map textures/q3view/hud_edit_mode.tga
		blendFunc blend
	}
}

q3view_but_scr_skins
{
	nomipmaps
	{
		map textures/q3view/hud_edit_skins.tga
		blendFunc blend
	}
}

q3view_but_scr_models
{
	nomipmaps
	{
		map textures/q3view/hud_edit_models.tga
		blendFunc blend
	}
}

q3view_but_scr_textures
{
	nomipmaps
	{
		map textures/q3view/hud_edit_textures.tga
		blendFunc blend
	}
}

q3view_but_lock
{
	nomipmaps
	{
		map textures/q3view/hud_lock.tga
		blendFunc blend
	}
}


q3view_but_info
{
	nomipmaps
	{
		map textures/q3view/hud_info.tga
		blendFunc blend
	}
}

q3view_but_larrow
{
	nomipmaps
	{
		map textures/q3view/hud_larrow.tga
		blendFunc blend
	}
}

q3view_but_rarrow
{
	nomipmaps
	{
		map textures/q3view/hud_rarrow.tga
		blendFunc blend
	}
}

q3view_tab_right
{
	nopicmip
	nomipmaps
	{
		map textures/q3view/hud_rtab.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		rgbgen vertex
	}
}
