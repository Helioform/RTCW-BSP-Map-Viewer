# RTCW-BSP-Map-Viewer
Loads and renders Return To Castle Wolfenstein maps.

Displays BSP maps with lightmaps as well as load and parse shaders.

Requires:

  * Visual Studio 2017
  
  * Graphics Card with Direct3D 10 GPU
  
  * Windows 7/10 (has not been tested on previous versions of Windows)
  
I have reorganized the code to use Singletons for the renderer and the texture manager. Added a simple test map for loading. Also used a hash map for a lot more efficient shader loading. 
  
![x3dengine 2017-11-18 16-22-02-63](https://user-images.githubusercontent.com/26845476/32984915-7b18070a-cc7d-11e7-89f8-f04fa4198ca7.png)
