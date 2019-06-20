# What is iBEX all about?

iBEX as free and open source project aimed to encapsulate all the required functionalities of a medical grade digital X-ray workstation
machine software. By opening the doors of the medical X-ray imaging device software to open source community and developing neatly documented 
software which are compatible with medical software standards, it is possible to have more stable, robust and flexible imaging device
with lower costs and ready for deploy in short time period.

# Pre-requisites
If you wish to make your own X-ray workstation, then you have to options download the iBEX source code (please check that you are on ## FastDev branch; it is the only one that is actively developed now) take a glance on the code and then try to build it for yourself from scratch. In the future the built versions would be prepared and uploaded too. The code is developed based on MVC design pattern. If you are not familiar with this design pattern then https://www.pluralsight.com/courses/introduction-qt-cplusplus-framework) is strongly suggested to get started from. Beside the Qt, stands up on the following list of packages:

| Package  |  version      | Discussion                                                        
| ---------|:-------------:| ------------------------------------------------------------------
| VTK      | 9             | visualization toolkit                                             
| CTK      | 0.1           | Qt widget toolkit. Specifically useful for DICOM communication    
| SQLite   | 3.28          | small size database management system                             
| DCMTK    | 3.64          | DICOM toolkit. Its free version is used for iBEX development  

Compiling the packages and integrating them into one project is time consuming process! specifically CTK. You may need to select the 
minimum configuration options then extend if your compilation faild. Please be patient!

## Prepration steps
The project is prepared to run on Windows 10 (x64) and Interl Core i7 CPU. In the following the steps to built the project is discussed.

### 1. Install Qt. 

    You do not needd commercial version. Just try to keep uptodate version (at the time of this writing its version 5+, 
    there are so many problems with version 4.x)

### 2. Compile and install VTK.

    Depends on your operating system, you may need to add the compiled parameters to the environment **PATH** variable
    (e.g. C:\VTK\bin).
        
    Snippet of VTK CMAKE configuration that were set to true (the remaining parameters are set to false):    
         BUILD_SHARED_LIBS :                  TRUE          
         EXODUSII_DISABLE_COMPILER_WARNINGS : TRUE         
         HDF5_USE_FOLDERS :                   TRUE         
         LIBPROJ_USE_THREAD :                 TRUE         
         Module_vtkGUISupportQtOpenGL  :      TRUE         
         NETCDF_DISABLE_COMPILER_WARNINGS :   TRUE         
         USE_COMPILER_HIDDEN_VISIBILITY  :    TRUE         
         VTK_BUILD_QT_DESIGNER_PLUGIN :       TRUE         
         VTK_DISPATCH_AOS_ARRAYS   :          TRUE         
         VTK_EXTERNAL_LIBHARU_IS_SHARED :     TRUE         
         VTK_Group_Qt :                       TRUE         
         VTK_Group_Rendering :                TRUE         
         VTK_Group_StandAlone :               TRUE         
         VTK_REPORT_OPENGL_ERRORS :           TRUE         
         VTK_REPORT_OPENGL_ERRORS :           OpenGL2         
         VTK_USE_64BIT_IDS :                  TRUE         
         VTK_USE_VIDEO_FOR_WINDOWS :          TRUE         
         CMAKE_INSTALL_PREFIX :               C:/VTK
         
     
    The VTK comes with plugin for Qt. You would be warned that these plugins are outdated. You need to put the dll in a specific  folder within the Qt (e.g. C:\Qt\qtcreator4.5.0\bin\plugins\designer QVTKWidgetPlugin.dll). Hope you would have no problem with    OpenGl2 problem otherwise you may need to compile for OpenGl next time because some legacy plugins are written for OpenGl and do not support OpenGl.
 
 ### 3. Compile and install DCMTK.
    
    This is the DICOM toolkit. There are versions that are not free. For iBEX, the free version is enough. But if you think about a commercial product you MAY require to pay and buy the complete package.
    
 ### 4. Compile and install CTK.
    
  This is the trickiest section. By now you should have Qt, VTK and DCMTK installed on your computer and the paths are 
  added to environment variables (e.g. C:\Qt\5.9.4\msvc2015_64\bin and C:\Qt\5.9.4\msvc2015_64\bin). The CTK make file requires
  Qt and VTK for compile. To get to this point
  
        CTK_BUILD_QTDESIGNER_PLUGINS      :TRUE
        CTK_BUILD_SHARED_LIBS             :TRUE
        CTK_ENABLE_DICOM                  :TRUE
        CTK_ENABLE_Widgets                :TRUE
        CTK_LIB_Core                      :TRUE
        CTK_LIB_DICOM/Core                :TRUE
        CTK_LIB_DICOM/Widgets             :TRUE
        CTK_LIB_Visualization/VTK/Core    :TRUE
        CTK_LIB_Visualization/VTK/Widgets :TRUE
        CTK_LIB_Widgets                   :TRUE
        CTK_SUPERBUILD                    :TRUE
        CTK_USE_GIT_PROTOCOL              :TRUE
        CTK_USE_GIT_PROTOCOL              :TRUE
        CTK_USE_SYSTEM_DCMTK              :TRUE
        CTK_USE_SYSTEM_VTK                :TRUE
        CTK_QT_VERSION                    :5
        
  ### 5. Compile and build iBEX
    
   Now you can build the iBEX and run it! Sample screenshots are shown in the following
   
   *Main screen*
   
   <img src="https://github.com/altaybrusan/ibex/blob/FastDev/docs/screen%20shots/main_dialog.JPG" width="700" height="450">

   
   *Patient registration dialog*
   
   <img src="https://github.com/altaybrusan/ibex/blob/FastDev/docs/screen%20shots/registration_dialog.JPG" width="500" height="400">
   
       
   *Examination dialog*
   
   <img src="https://github.com/altaybrusan/ibex/blob/FastDev/docs/screen%20shots/exposure_dialog.jpg" width="700" height="450">
   
  # Extend via plugins
  
  The other way to extend iBEX functionalities is through adding external plugins. Way we are planned to keep iBEX dynamic alive.  For developers how has no time to make iBEX from scratch, a set of pre-built projects are going to be prepared and they can write their own plugins and extend the iBEX functionalities based on the needs, instead of rebuilding everything from scratch.
  
  iBEX kernel supports two types of extension plugins. First type is for adding a device driver. An X-ray machine is actually  is an assembly of a couple of components (devices) such as digital detector, generator, collimator, etc. Usually, these components come with device drivers. In order to make the communication in between iBEX and these devices feasible, developers are required to develop a wrapper and then put them within plugin directory. iBEX automatically loads the plugins and then integrate them during the program start time. The engine that were used for plugin extension is based on Qt. Consequently, specific rules and regulations should be followed to make the connection successful. 
  
  <img src="https://github.com/altaybrusan/ibex/blob/FastDev/docs/images/plugin_mechanism.png" width="550" height="350">
   
  iBEX provide IDevice interface to make the communication with devices standard! Developers are required to implement
  this interface for their device-driver wrappers. IDEvice plugin interface provide the following list of services:
    
    - Read/Write to device
    - Execute a command
    - Update a setting and a parameter
    - Provide a graphical container (Widget) to display the user interface of the plugin (if any available)
    - Notify the plugin with an error, message or dialog show up.
   
       
   ## Example 
   
   Teledyne detector is a digital X-ray detector. The following snippet shows how the IDevice is implemented for this device (due to legal issues we cannot show the detector's API here, but one can take a glance over the source code to understand the mechanism better).
   
   <img src="https://github.com/altaybrusan/ibex/blob/FastDev/docs/screen%20shots/plugin_snippet.PNG" width="550" height="350">
  
  The other type of extension is algorithm. These extension plugins are required to implement IAlgorithm interface. This type of plugins is useful for adding new 
  image processing algorithms into the iBEX core.
  
  <img src="https://github.com/altaybrusan/ibex/blob/FastDev/docs/screen%20shots/IAlgorithm_implementation.PNG" width="550" height="350">
  
  Like IDevice interface, IAlgorithm interface also provide a set of standard mechanisms such as widget container, signaling and communication and command execution. The ButterworthLowPassFilter.cpp could be visited as a template for developing new algorithms. We must emphasize that in order to make the communication between plugins and kernel most efficient, all the data are carried over standard containers defined within vtk (such as vtkImageData)
  
  
  
     


