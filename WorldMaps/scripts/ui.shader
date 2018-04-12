ui/assets/menumodel/bj_head1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menumodel/bj_head1.tga
		rgbgen identity
	}
}

ui/assets/menumodel/bj_body1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menumodel/bj_body1.tga
		rgbgen identity
	}
}


ps_back2
{
  nopicmip
  nomipmaps
  {
    map ui/assets/ps_back03a.tga
    rgbgen identity
  }
}

ps_back1
{
  nopicmip
  nomipmaps
  {
    map ui/assets/ps_back1.tga
    rgbgen identity
  }
}

uiBackground
{
  nopicmip
  nomipmaps
  {
    map ui/assets/background2.tga
    rgbgen identity
  }
}

uibackground5
{
  nopicmip
  nomipmaps
  {
    map ui/assets/background3.tga
    rgbgen identity
  }
	



}


uiBackgroundMulti
{
  {
    map ui/assets/background.tga
    rgbGen identity
  }
  {
    map ui/assets/multi_alpha.tga
    blendfunc gl_zero gl_src_alpha
    rgbGen identity
    tcMod scroll 0.05 0.05
    tcMod scale 1.5 3
  }
  {
    map $lightmap
    rgbGen identity
    blendfunc filter
  }
}


textures/base_wall2/icon_stroggs
{
  	
	surfaceparm trans
	surfaceparm nomarks
	surfaceparm nolightmap


	{
		map textures/base_wall2/icon_stroggs.tga
		blendfunc gl_src_alpha gl_one_minus_src_alpha
		rgbGen identity

	}
}



textures/redteam1
{      
  qer_editorimage textures/base_wall2/redteam1.tga
  {
    map textures/base_wall2/redteam1.tga
    rgbgen identity
  }
}

textures/blueteam1
{      
  qer_editorimage textures/base_wall2/blueteam1.tga
  {
    map textures/base_wall2/blueteam1.tga
    rgbgen identity
  }
}



textures/screenswitch
{
  qer_editorimage textures/base_wall2/blankscreen.tga
  {
    map textures/base_wall2/blankscreen.tga
    rgbgen identity
  }
}

ui/assets/pagans_shader1_2
{
	{
		clampmap ui/assets/pagans.tga
		rgbgen identity
		blendfunc add
		//rgbgen wave sin .25 0 0 0
	}
}

menuflare
{
	{
		clampmap ui/assets/menuflare.tga
		blendfunc add
		tcmod rotate 30
		rgbgen wave triangle 1 .05 0 .1
	}
}


