#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CTKCore" for configuration "Release"
set_property(TARGET CTKCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CTKCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKCore.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "Qt5::Core;dbghelp"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS CTKCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_CTKCore "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKCore.lib" "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKCore.dll" )

# Import target "CTKWidgets" for configuration "Release"
set_property(TARGET CTKWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CTKWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKWidgets.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "CTKCore;Qt5::Widgets;Qt5::Xml;Qt5::OpenGL"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKWidgets.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS CTKWidgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_CTKWidgets "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKWidgets.lib" "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKWidgets.dll" )

# Import target "CTKDICOMCore" for configuration "Release"
set_property(TARGET CTKDICOMCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CTKDICOMCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMCore.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "CTKCore;ofstd;oflog;dcmdata;i2d;dcmimgle;dcmimage;dcmjpeg;ijg8;ijg12;ijg16;dcmjpls;charls;dcmtls;dcmnet;dcmsr;cmr;dcmdsig;dcmwlm;dcmqrdb;dcmpstat;dcmrt;dcmiod;dcmfg;dcmseg;dcmtract;dcmpmap;Qt5::Sql"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS CTKDICOMCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_CTKDICOMCore "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMCore.lib" "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMCore.dll" )

# Import target "CTKDICOMWidgets" for configuration "Release"
set_property(TARGET CTKDICOMWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CTKDICOMWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMWidgets.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "CTKDICOMCore;CTKWidgets"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMWidgets.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS CTKDICOMWidgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_CTKDICOMWidgets "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMWidgets.lib" "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKDICOMWidgets.dll" )

# Import target "CTKVisualizationVTKCore" for configuration "Release"
set_property(TARGET CTKVisualizationVTKCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CTKVisualizationVTKCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKCore.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "vtkViewsContext2D;vtkChartsCore;vtkCommonCore;vtkCommonDataModel;vtkCommonSystem;vtkFiltersStatistics;vtkIOImage;vtkInteractionStyle;vtkRenderingAnnotation;vtkRenderingCore;vtkRenderingOpenGL2;vtkRenderingFreeType;vtkRenderingContextOpenGL2;CTKCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS CTKVisualizationVTKCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_CTKVisualizationVTKCore "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKCore.lib" "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKCore.dll" )

# Import target "CTKVisualizationVTKWidgets" for configuration "Release"
set_property(TARGET CTKVisualizationVTKWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CTKVisualizationVTKWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "vtkChartsCore;vtkChartsCore;vtkCommonMath;vtkFiltersSources;vtkImagingGeneral;vtkImagingStatistics;vtkInteractionWidgets;vtkRenderingContext2D;vtkViewsContext2D;vtkGUISupportQt;vtkRenderingContextOpenGL2;vtkRenderingGL2PSOpenGL2;CTKWidgets;CTKVisualizationVTKCore;Qt5::Network"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKWidgets.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS CTKVisualizationVTKWidgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_CTKVisualizationVTKWidgets "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib" "${_IMPORT_PREFIX}/lib/ctk-0.1/CTKVisualizationVTKWidgets.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
