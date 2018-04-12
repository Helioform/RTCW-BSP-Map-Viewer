
cin_logo
{
	nopicmip
	nomipmaps
	
	{
		map ui/assets/cin_logo.tga
		blendfunc blend
	}
}




warning
{
	nopicmip
	nomipmaps
	
	{
		map ui/assets/warning.tga
		blendfunc blend
		tcmod scale 8 8 
	}
}


screenwipe
{
	nopicmip
	nomipmaps
	
	{
		map ui/assets/screen_wipe1.tga
		tcmod scroll .1 .1
		blendfunc filter
	}
}





popback
{

	nopicmip
	nomipmaps
        
        {
		clampmap ui/assets/popback.tga          
		blendfunc blend
	}
	{
		clampmap ui/assets/popback.tga
		tcmod rotate 10 
		rgbgen wave sin .5 0 0 0          
		blendfunc add
	}
        
}
centerconsole
{

	nopicmip
	nomipmaps
        
        {
		clampmap textures/sfx/console01.tga          
		tcMod rotate 20
	}
        {
		clampmap textures/sfx/console02.tga
		rgbgen wave sin .5 0 0 0             
		tcMod rotate -60
		blendFunc filter
	}
}


menuback_a
{	
	nopicmip
	nomipmaps	

	{
		map ui/assets/menuback_a.tga
	}
	

	{
		map ui/assets/console02.tga
		blendfunc filter
		tcmod rotate -60
	}
}

menuback_b
{
	
	nopicmip
	nomipmaps
	{
		map ui/assets/menuback_b.tga
		blendfunc add
		rgbgen wave sin .75 0 0 0
		tcmod scroll 0 .2
	}
	{
			map textures/effects2/console01.tga
                	blendFunc Add
                	tcMod scroll -.01  -.02 
                	tcmod scale .02 .01
                	tcmod rotate 3
	}
	
}


menuback_e
{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/radial.tga
		blendfunc add
		tcmod rotate 100
	}
	{
		clampmap ui/assets/radial.tga
		blendfunc add
		tcmod rotate -100
	}
}
menuback_e3
{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/radial2.tga
		blendfunc add
		tcmod rotate 200
		tcmod scale .5 .5
		rgbgen wave sin .5 .5 0 10
	}
	{
		clampmap ui/assets/radial2.tga
		blendfunc add
		tcmod rotate -200
		tcmod scale .5 .5
		rgbgen wave sin .5 .5 0 10
	}
	
}
menuback_e4
{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/radial2.tga
		blendfunc add
		tcmod rotate 200
		rgbgen wave sin .5 .5 0 10
	}
	{
		clampmap ui/assets/radial2.tga
		blendfunc add
		tcmod rotate -200
		rgbgen wave sin .5 .5 0 10
	}
	
}




menuback_c
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menuback_c.tga
		blendfunc blend
	}


	{
		clampmap ui/assets/menuback_c_light.tga
		blendfunc add
		tcmod rotate -60
	}
	
}


menuback_d
{
	nopicmip
	nomipmaps
	{
		map ui/assets/teamarena.tga
		blendfunc filter
	}
	{
		map ui/assets/teamarena.tga
		blendfunc add
		rgbgen wave sin .25 .25 0 5
	}
	
}
menuback_f
{	
	
	nopicmip
	nomipmaps
	{
		map ui/assets/menuback_f.tga
		blendfunc blend
	}
	
}
menuback_g
{	
	

	nopicmip
	nomipmaps
	{
		map ui/assets/singleplayer1.tga
		blendfunc blend
	}
	
	
	}


	

lightningkc
	{
	nopicmip
	nomipmaps
	{
		animMap 10 ui/assets/blu01.tga ui/assets/blu02.tga ui/assets/blu03.tga ui/assets/blu04.tga ui/assets/blu05.tga ui/assets/blu06.tga ui/assets/blu07.tga ui/assets/blu08.tga 
		blendFunc add	
		rgbGen wave inverseSawtooth 0 1 0 10	
	}	
	}

lightningkca
	{
	nopicmip
	nomipmaps
	{
		animMap 10 ui/assets/blu01.tga ui/assets/blu02.tga ui/assets/blu03.tga ui/assets/blu04.tga ui/assets/blu05.tga ui/assets/blu06.tga ui/assets/blu07.tga ui/assets/blu08.tga 
		blendFunc add	
		rgbGen wave inverseSawtooth 0 1 0 10
		tcmod swap	
	}	
	}

menu2back
{
	nopicmip
	nomipmaps
	{
		map ui/assets/background.tga
		rgbgen identity
	}
}

blur
	{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/blur.tga
		blendfunc add
		rgbgen wave sin .8 .02 0 1
		tcmod stretch sin .9 .05 0 1
		tcmod turb 1 .005 0 5
	}
	}


vs
	{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/vs.tga
		blendfunc add
		rgbgen wave sin .25 .15 .25 1.5
		tcmod turb 1 .005 0 4.5	
	}
	{
		clampmap ui/assets/vs_alt.tga
		rgbgen wave square .75 .15 0 1 
		tcmod turb 1 .005 .5 4.5	
		blendfunc add
	}
	}



ui/assets/the_fallen_name
	{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/the_fallen_name.tga
		blendfunc add
		rgbgen wave sin .75 .25 0 2
		tcmod turb 1 .005 0 5	
	}
	{
		map ui/assets/the_fallen_name_alt.tga
		blendfunc add
	}
	}

ui/assets/stroggs_name
	{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/stroggs_name.tga
		blendfunc add
		rgbgen wave sin .75 .25 0 2
		tcmod turb 1 .005 0 5
	}

	{
		map ui/assets/stroggs_name_alt.tga
		blendfunc add
	}

}


ui/assets/pagans_name
	{

	nopicmip
	nomipmaps
	{
		map ui/assets/pagans_name.tga
		blendfunc add
		rgbgen wave sin .75 .25 0 2
		tcmod turb 1 .005 0 5
	}

	{
		map ui/assets/pagans_name_alt.tga
		blendfunc add
	}
 
}
	
ui/assets/intruders_name
	{

	nopicmip
	nomipmaps
	{
		map ui/assets/intruders_name.tga
		blendfunc add
		rgbgen wave sin .75 .25 0 2
		tcmod turb 1 .005 0 5
	}

	{
		map ui/assets/intruders_name_alt.tga
		blendfunc add
	}
 
}

ui/assets/crusaders_name
	{

	nopicmip
	nomipmaps
	{
		map ui/assets/crusaders_name.tga
		blendfunc add
		rgbgen wave sin .75 .25 0 2
		tcmod turb 1 .005 0 5
	}

	{
		map ui/assets/crusaders_name_alt.tga
		blendfunc add
	}
 
}


		

uibackground4
{
	nopicmip
	nomipmaps
    
       		{	
			map ui/assets/screen02.tga
                	blendFunc GL_ONE GL_ZERO
                	tcMod scroll 7.1  0.2
               		tcmod scale .8 1
			rgbgen wave square .5 .05 0 5
		}
		{
			map ui/assets/background3.tga
			blendfunc add
			//tcmod turb 1 .002 0 5	
		}
				
}
uibackground8
{
	nopicmip
	nomipmaps
    
       		{	
			map ui/assets/background8.tga
                	blendFunc GL_ONE GL_ZERO 
			rgbgen wave sin .5 0 0 0 
		}

				
}



uibackgroundid
{
	nopicmip
	nomipmaps
    
       	
		{
			map ui/assets/backgroundid.tga
		}
		{	
			map ui/assets/screen02.tga
                	blendFunc add
                	tcMod scroll 7.1  0.2
               		tcmod scale .8 1
			rgbgen wave square .25 .05 0 5
		}
						
		}

hudalert
{
	nopicmip
	nomipmaps
    
       		{	map ui/assets/red_box.tga
                	blendFunc GL_ONE GL_ZERO
                	tcMod scroll 7.1  0.2
               		tcmod scale .8 1
			rgbgen wave sin .25 .25 0 1
		}   
	}

hudalert_red
{
	nopicmip
	nomipmaps
    
       		{	map ui/assets/red_box.tga
                	blendFunc GL_ONE GL_ZERO
                	tcMod scroll 7.1  0.2
               		tcmod scale .8 1
			rgbgen wave sin .25 .25 0 1
		}   
	}
hudalert_good
{
	nopicmip
	nomipmaps
    
       		{	map ui/assets/green_box.tga
                	blendFunc GL_ONE GL_ZERO
                	tcMod scroll 7.1  0.2
               		tcmod scale .8 1
			rgbgen wave sin .25 .25 0 1
		}   
	}

cinematicscreen
{
	nopicmip
	nomipmaps
    
       		{	map ui/assets/green_box.tga
                	blendFunc filter
                	
		}   
	}

hudalert_blue
{
	nopicmip
	nomipmaps
    
       		{	map ui/assets/blue_box.tga
                	blendFunc GL_ONE GL_ZERO
                	tcMod scroll 7.1  0.2
               		tcmod scale .8 1
			rgbgen wave sin .25 .25 0 1
		}   
	}

menuscreen
{
	nopicmip
	nomipmaps
    
       	{	
			map textures/sfx2/screen01.tga
                	blendFunc add
                	tcMod scroll 7.1  0.2
               	tcmod scale .8 1
			rgbgen wave square .75 .05 0 5
		}
	{
			map textures/effects2/console01.tga
                	blendFunc Add
                	tcMod scroll -.01  -.02 
                	tcmod scale .02 .01
                	tcmod rotate 3
	}

}

menuscreen2
{
	nopicmip
	nomipmaps
    
       	{	
			map textures/sfx2/screen01.tga
                	blendFunc add
                	tcMod scroll 7  0.2
               	tcmod scale .4 .5
			rgbgen wave square .75 .05 0 5
		}


}

clanlogo
{
	nopicmip
	nomipmaps
    
	{
			animMap 5 ui/assets/pagans.tga ui/assets/stroggs.tga ui/assets/crusaders.tga ui/assets/thefallen.tga ui/assets/intruders.tga 
			blendfunc add
			rgbGen wave inverseSawtooth 0 .25 0 5
			
	}
	{
			animMap 5 ui/assets/intruders.tga ui/assets/pagans.tga ui/assets/stroggs.tga ui/assets/crusaders.tga ui/assets/thefallen.tga  
			blendfunc add
			rgbGen wave Sawtooth 0 .25 0 5
			
	}


}		


playerheads
{
	nopicmip
	nomipmaps
    
	{
			animMap 5 ui/assets/head1.tga ui/assets/head2.tga ui/assets/head3.tga ui/assets/head4.tga ui/assets/head5.tga ui/assets/head6.tga ui/assets/head7.tga ui/assets/head8.tga
			blendfunc add
			rgbGen wave inverseSawtooth 0 .5 0 5
			
	}
	{
			animMap 5 ui/assets/head2.tga ui/assets/head3.tga ui/assets/head4.tga ui/assets/head5.tga ui/assets/head6.tga ui/assets/head7.tga ui/assets/head8.tga ui/assets/head1.tga

			blendfunc add
			rgbGen wave Sawtooth 0 .5 0 5
			
	}


}


ui/assets/pagans_shader1
{
	nopicmip
	nomipmaps
	{
		clampmap ui/assets/pagans.tga
		blendfunc add
		rgbgen wave sin .25 0 0 0
	}
}

ui/assets/mainbanner_shader1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/mainmenubanner.tga
		blendfunc add
		rgbgen wave sin .05 0 0 0 
		tcmod scroll .02 0
	}
}


ui/assets/clan_shader1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/chooseclan.tga
		blendfunc add
		rgbgen wave sin .05 0 0 0
		tcmod scroll .02 0
	}
}

ui/assets/player_shader1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/selectplayer.tga
		blendfunc add
		rgbgen wave sin .05 0 0 0
		tcmod scroll .04 0
	}
}

setup
{
	nopicmip
	nomipmaps
	{
		map ui/assets/setup.tga
		blendfunc add
		rgbgen wave sin .05 0 0 0
		tcmod scroll .04 0
	}
}


join_server
{
	nopicmip
	nomipmaps
	{
		map ui/assets/join_server.tga
		blendfunc add
		rgbgen wave sin .05 0 0 0
		tcmod scroll .04 0
	}
}

fight
{
	nopicmip
	nomipmaps
	{
		map ui/assets/fight.tga
		blendfunc add
		rgbgen wave sin .05 0 0 0
		tcmod scroll .04 0
	}
}



start_server
{
	nopicmip
	nomipmaps
{
		map ui/assets/start_server.tga
		blendfunc add
		rgbgen wave sin .15 0 0 0
		tcmod scroll .04 0
	}
}


ui/assets/controls_shader1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/controls.tga
		blendfunc add
		rgbgen wave sin .15 0 0 0
		tcmod scroll .02 0
	}
}

playertitle
{	nopicmip
	nomipmaps
	{
		clampmap ui/assets/playertitle.tga
		blendfunc add
		tcmod stretch sin .9 .001 0 10
		rgbgen wave triangle .5 .05 0 1
	}

	
}

/////////////////////////////////// wolf ///////////////////////


menuback_cw
{	
	nopicmip
	nomipmaps	

	{
		map ui/assets/menuback_cw.tga
		tcmod scroll 0.025 0 
	}
	

//	{
//		map ui/assets/console02.tga
//		blendfunc filter
//		tcmod rotate -60
//	}
}

sidebar
{
	nopicmip
	nomipmaps
	{
		map ui/assets/sidebar.tga
		blendfunc blend
	}


//	{
//		clampmap ui/assets/menuback_c_light.tga
//		blendfunc add
//		tcmod rotate -60
//	}
	
}

sidebar2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/sidebar2.tga
		blendfunc blend
	}


//	{
//		clampmap ui/assets/menuback_c_light.tga
//		blendfunc add
//		tcmod rotate -60
//	}
	
}

bj1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/bj1.tga
		blendfunc blend
	}


//	{
//		clampmap ui/assets/menuback_c_light.tga
//		blendfunc add
//		tcmod rotate -60
//	}
	
}

red_bar
{
	nopicmip
	nomipmaps
	{
		map ui/assets/red_bar.tga
		blendfunc blend
	}
}

WOLFLOGO
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFLOGO.tga
		blendfunc blend
	}
}

WOLFLOGO2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFLOGO2.tga
		blendfunc blend
	}
}

WOLFLOGO3
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFLOGO3.tga
		blendfunc blend
	}
}

WOLFLOGO4
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFLOGO4.tga
		blendfunc blend
	}
}

WOLFLOGO4a
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFLOGO4a.tga
		blendfunc blend
	}
}

backimage2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/backimage2.tga
		blendfunc blend
	}
}

backimage3
{
	nopicmip
	nomipmaps
	{
		map ui/assets/backimage3.tga
		blendfunc blend
	}
}

backimage4
{
	nopicmip
	nomipmaps
	{
		map ui/assets/backimage4.tga
		blendfunc blend
	}
}



bands
{
	nopicmip
	nomipmaps
	{
		map ui/assets/bands.tga
		blendfunc blend
	//	tcmod stretch sin 1 .2 0 1
		tcmod scroll -0.03 0 
		rgbgen wave sawtooth 2 .7 0 .5
	}

	{
		map ui/assets/bandsa.tga
		blendfunc blend
	//	tcmod stretch sin 1 .1 0 1 
	//	tcmod turb  1 .01 0 .1
		tcmod scroll 0.05 0

	}
}

band_logo
{
	nopicmip
	nomipmaps
	{
		map ui/assets/band_logo.tga
		blendfunc blend
	//	tcmod stretch sin 1 .2 0 1
		tcmod scroll -0.03 0 
		rgbgen wave sawtooth 2 .7 0 .5
	}

	{
		map ui/assets/band_logo.tga
		blendfunc blend
	//	tcmod stretch sin 1 .1 0 1 
	//	tcmod turb  1 .01 0 .1
		tcmod scroll 0.03 0

	}
}

//bandsa
//{
//	nopicmip
//	nomipmaps
//	{
///		map ui/assets/bandsa.tga
//		blendfunc blend
//	//	tcmod stretch sin 1 .2 0 1
//		tcmod scroll 0.02 0 
//	}
//
//	{
//		map ui/assets/bandsa.tga
//		blendfunc blend
//	//	tcmod stretch sin 1 .1 0 1 
//		tcmod scroll 0.04 0
//	}
//}


band2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/band2.tga
		blendfunc blend
		rgbgen wave sawtooth 2 .5 0 .5
	}
}

video_over1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/video_over1.tga
		blendfunc blend
	}
}



//////////////// help menu ////////////////

back_help
{
	nopicmip
	nomipmaps
	{
		map ui/assets/back_help.tga
		blendfunc blend
	}
}


back_help2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/back_help2.tga
		blendfunc blend
	}
}

vid_frame
{
	nopicmip
	nomipmaps
	{
		map ui/assets/vid_frame.tga
		blendfunc blend
	}
}

////////////////////// maxx /////////////////////////

centerconsole2
{

	nopicmip
	nomipmaps
        
//        {
//		clampmap textures/sfx/console01.tga
//		blendfunc add   
//		rgbgen wave sin .15 0 0 0         
//		tcMod rotate 20
//	}
//        {
//		clampmap textures/sfx/console02.tga
//		rgbgen wave sin .5 0 0 0             
//		tcMod rotate -60
//		blendFunc add
//	}


        {
		clampmap ui/assets/menuback_c_light.tga
		rgbgen wave sin .5 0 0 0             
		tcMod rotate -30
		blendFunc add
	}

}


wolf_flag1
{
	
	nopicmip
	nomipmaps
	tesssize 16
//	deformVertexes wave 160 sin 0 10 0 .3	// the chop
	deformVertexes wave 10 sin 0 2 0 .2
	cull twosided

	{
		map ui/assets/wolf_flag1.tga
		blendfunc blend
	}
}

menu_controls
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menu_controls.tga
		blendfunc blend
	}
}

notebook1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/notebook1.tga
		blendfunc blend
	}
}

machine1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/machine1.tga
		blendfunc blend
	}
}

machine2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/machine2.tga
		blendfunc blend
	}
}

menu_start
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menu_start.tga
		blendfunc blend
	}
}

menu_load
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menu_load.tga
		blendfunc blend
	}
}

menu_select
{
	nopicmip
	nomipmaps
	{
		map ui/assets/menu_select.tga
		blendfunc blend
	}
}
machine_video
{
	nopicmip
	nomipmaps
	{
		map ui/assets/machine_video.tga
		blendfunc blend
	}
}


machine_video2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/machine_video2.tga
		blendfunc blend
	}
}

machine_videob
{
	nopicmip
	nomipmaps
	{
		map ui/assets/machine_videob.tga
		blendfunc blend
	}
}


cross
{
	nopicmip
	nomipmaps
	{
		map ui/assets/cross.tga
		blendfunc blend
	}
}

cross2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/cross2.tga
		blendfunc blend
	}
}

pageturn
{
	nopicmip
	nomipmaps
	{
		map ui/assets/pageturn.tga
		blendfunc blend
	}
}

pageturn2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/pageturn2.tga
		blendfunc blend
	}
}

bookmark_cover
{
	nopicmip
	nomipmaps
	{
		map ui/assets/bookmark_cover.tga
		blendfunc blend
	}
}

bookmark_back
{
	nopicmip
	nomipmaps
	{
		map ui/assets/bookmark_back.tga
		blendfunc blend
	}
}

gfx/clipboard/icon1
{
	nopicmip
	nomipmaps
	{
		map gfx/clipboard/icon1.tga
		blendfunc blend
	}
}

gfx/clipboard/icon2
{
	nopicmip
	nomipmaps
	{
		map gfx/clipboard/icon2.tga
		blendfunc blend
	}
}

gfx/clipboard/icon3
{
	nopicmip
	nomipmaps
	{
		map gfx/clipboard/icon3.tga
		blendfunc blend
	}
}

ui/assets/ingame1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/ingame1.tga
		blendfunc blend
	}
}

ui/assets/about
{
	nopicmip
	nomipmaps
	{
		map ui/assets/about.tga
		blendfunc blend
	}
}

ui/assets/load_save
{
	nopicmip
	nomipmaps
	{
		map ui/assets/load_save.tga
		blendfunc blend
	}
}

ui/assets/controls
{
	nopicmip
	nomipmaps
	{
		map ui/assets/controls.tga
		blendfunc blend
	}
}
ui/assets/options
{
	nopicmip
	nomipmaps
	{
		map ui/assets/options.tga
		blendfunc blend
	}
}

ui/assets/top_left
{
	nopicmip
	nomipmaps
	{
		map ui/assets/top_left.tga
		blendfunc blend
	}
}
ui/assets/top_right
{
	nopicmip
	nomipmaps
	{
		map ui/assets/top_right.tga
		blendfunc blend
	}
}
ui/assets/bottom_left
{
	nopicmip
	nomipmaps
	{
		map ui/assets/bottom_left.tga
		blendfunc blend
	}
}
ui/assets/bottom_right
{
	nopicmip
	nomipmaps
	{
		map ui/assets/bottom_right.tga
		blendfunc blend
	}
}
ui/assets/middle
{
	nopicmip
	nomipmaps
	{
		map ui/assets/middle.tga
		blendfunc blend
	}
}
ui/assets/p_book1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/p_book1.tga
//		blendfunc blend
	}
}
p_book1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/p_book1.tga
//		blendfunc blend
	}
}

WOLFICON
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFICON.tga
		blendfunc blend
	}
}

WOLFFLAMELOGO
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFFLAMELOGO.tga
		blendfunc blend
	}
}

BLACKGRAD
{
	nopicmip
	nomipmaps
	{
		map ui/assets/BLACKGRAD.tga
		blendfunc blend
	}
}

gold_line
{
	nopicmip
	nomipmaps
	{
		map ui/assets/gold_line.tga
		blendfunc blend
	}
}

WOLFICONBACK
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFICONBACK.tga
		blendfunc blend
	}
}

FLAME
{
	nopicmip
	nomipmaps

	{
		map ui/assets/flame.tga
	//	blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA 
		blendfunc blend
		tcmod scale .75 .75
		tcmod scroll 0 .1 
		tcmod turb  .5 .1 0 .15
	}
	{
		map ui/assets/flame.tga
	//	blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA 
		blendfunc blend
		tcmod scale .5 .5
		tcmod scroll 0 .05 
	//	tcmod turb  .5 .1 0 .1
	}
}

SLIDER2

{
	nopicmip
	nomipmaps
	{
		map ui/assets/SLIDER2.tga
		blendfunc blend
	}
}

SLIDERBUTT_1

{
	nopicmip
	nomipmaps
	{
		map ui/assets/SLIDERBUTT_1.tga
		blendfunc blend
	}
}


BLACK
{
	nopicmip
	nomipmaps
	{
		map ui/assets/BLACK.tga
	}
}

WOLFICONBACK3
{
	nopicmip
	nomipmaps
	{
		map ui/assets/WOLFICONBACK3.tga
	}
}

forwardarrow

{
	nopicmip
	nomipmaps
	{
//		animMap 4 ui/assets/forwardarrow.tga ui/assets/forwardarrow.tga ui/assets/forwardarrow.tga ui/assets/forwardarrow.tga ui/assets/forwardarrow.tga ui/assets/forwardarrow_alt.tga ui/assets/forwardarrow_alt.tga ui/assets/forwardarrow_alt.tga
		animMap 4 ui/assets/forwardarrow_h1.tga ui/assets/forwardarrow_h1.tga ui/assets/forwardarrow_h1.tga ui/assets/forwardarrow_h1.tga ui/assets/forwardarrow_h1.tga ui/assets/forwardarrow_h2.tga ui/assets/forwardarrow_h2.tga ui/assets/forwardarrow_h2.tga
		blendfunc blend
	}
	
}

green

{
	nopicmip
	nomipmaps
	{
		map ui/assets/green.tga
		blendfunc blend
	}
}

green

{
	nopicmip
	nomipmaps
	{
		map ui/assets/green.tga
		blendfunc blend
	}
}

document1
{
	nopicmip
	nomipmaps
	{
		map gfx/clipboard/document1.tga
		blendfunc blend
	}
}

map_e1
{
	nopicmip
	nomipmaps
	{
		map ui/assets/map_e1.tga
		blendfunc blend
	}
}

kessler
{
	nopicmip
	nomipmaps
	{
		map ui/assets/kessler.tga
		blendfunc blend
	}
} 

m_village
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_village.tga
		blendfunc blend
	}
} 

m_escape2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_escape2.tga
		blendfunc blend
	}
} 

m_tram
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_tram.tga
		blendfunc blend
	}
} 

m_church
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_church.tga
		blendfunc blend
	}
} 

m_crypt
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_crypt.tga
		blendfunc blend
	}
}

partisan_house
{
	nopicmip
	nomipmaps
	{
		map ui/assets/partisan_house.tga
		blendfunc blend
	}
} 

mid_station
{
	nopicmip
	nomipmaps
	{
		map ui/assets/mid_station.tga
		blendfunc blend
	}
} 

dagger
{
	nopicmip
	nomipmaps
	{
		map ui/assets/dagger.tga
		blendfunc blend
	}
} 

helga
{
	nopicmip
	nomipmaps
	{
		map ui/assets/helga.tga
		blendfunc blend
	}
} 

m_forest
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_forest.tga
		blendfunc blend
	}
} 

forest_route
{
	nopicmip
	nomipmaps
	{
		map ui/assets/forest_route.tga
		blendfunc blend
	}
} 


m_rocket
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_rocket.tga
		blendfunc blend
	}
}

m_assault
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_assault.tga
		blendfunc blend
	}
}

m_sfm
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_sfm.tga
		blendfunc blend
	}
}


rocket
{
	nopicmip
	nomipmaps
	{
		map ui/assets/rocket.tga
		blendfunc blend
	}
}

natter
{
	nopicmip
	nomipmaps
	{
		map ui/assets/natter.tga
		blendfunc blend
	}
}

radar
{
	nopicmip
	nomipmaps
	{
		map ui/assets/radar.tga
		blendfunc blend
	}
}


tank
{
	nopicmip
	nomipmaps
	{
		map ui/assets/tank.tga
		blendfunc blend
	}
}

venom
{
	nopicmip
	nomipmaps
	{
		map ui/assets/venom.tga
		blendfunc blend
	}
}

m_factory
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_factory.tga
		blendfunc blend
	}
}


m_trainyard
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_trainyard.tga
		blendfunc blend
	}
}

m_dam
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_dam.tga
		blendfunc blend
	}
}

m_village2
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_village2.tga
		blendfunc blend
	}
}

m_chateau
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_chateau.tga
		blendfunc blend
	}
}

m_dig
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_dig.tga
		blendfunc blend
	}
}

m_castle
{
	nopicmip
	nomipmaps
	{
		map ui/assets/m_castle.tga
		blendfunc blend
	}
}

dark
{
	nopicmip
	nomipmaps
	{
		map ui/assets/dark.tga
		blendfunc blend
	}
}

norway
{
	nopicmip
	nomipmaps
	{
		map ui/assets/norway.tga
		blendfunc blend
	}
}

trainyard
{
	nopicmip
	nomipmaps
	{
		map ui/assets/trainyard.tga
		blendfunc blend
	}
}


generals
{
	nopicmip
	nomipmaps
	{
		map ui/assets/generals.tga
		blendfunc blend
	}
}

}
}
